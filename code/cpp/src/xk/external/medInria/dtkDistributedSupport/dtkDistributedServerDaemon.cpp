/* dtkDistributedServerDaemon.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Wed Jun  1 11:28:54 2011 (+0200)
 * Version: $Id: 026c6bf0e6c21f155995e2a5149398ed42c1d2eb $
 * Last-Updated: mar. févr.  4 15:18:53 2014 (+0100)
 *           By: Nicolas Niclausse
 *     Update #: 844
 */

/* Commentary:
 *
 * debug logging: use dtkLog() << "message" or qDebug() << "message"
 *   run logging: use dtkDistributedServiceBase::instance()->logMessage("message");
 */

/* Change log:
 *
 */

#include "dtkDistributedServerDaemon.h"
#include "dtkDistributedServerManager.h"
#include "dtkDistributedServerManagerOar.h"
#include "dtkDistributedServerManagerSsh.h"
#include "dtkDistributedServerManagerTorque.h"
#include "dtkDistributedService.h"
#include "dtkDistributedSocket.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkLog>

class dtkDistributedServerDaemonPrivate
{
public:
    dtkDistributedServerManager *manager;

public:
    QMap< QPair<int, QString>, dtkDistributedSocket *> sockets;
};

dtkDistributedServerDaemon::dtkDistributedServerDaemon(quint16 port, QObject *parent) : QTcpServer(parent), d(new dtkDistributedServerDaemonPrivate)
{
    d->manager = NULL;

    if (!this->listen(QHostAddress::Any, port)) {
        dtkError() << "Can't listen on port"  << port << ", aborting";
        exit(1);
    } else {
        dtkDebug() << "OK, server is waiting for incoming connection on port"  << port ;
    }

    dtkDistributedServiceBase::instance()->logMessage("Server daemon listening on port " + QString::number(port));
}

dtkDistributedServerDaemon::~dtkDistributedServerDaemon(void)
{
    delete d;

    d = NULL;
}

dtkDistributedServerManager *dtkDistributedServerDaemon::manager(void)
{
    return d->manager;
}

void dtkDistributedServerDaemon::setManager(dtkDistributedServerManager::Type type)
{
    switch (type) {
    case dtkDistributedServerManager::Oar:
        d->manager = new dtkDistributedServerManagerOar;
        break;

    case dtkDistributedServerManager::Torque:
        d->manager = new dtkDistributedServerManagerTorque;
        break;

    case dtkDistributedServerManager::Ssh:
        d->manager = new dtkDistributedServerManagerSsh;
        break;

    default:
        break;
    }
}

void dtkDistributedServerDaemon::incomingConnection(qintptr descriptor)
{
    dtkDebug() << DTK_PRETTY_FUNCTION << "-- Connection -- " << descriptor ;

    dtkDistributedSocket *socket = new dtkDistributedSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(discard()));
    socket->setSocketDescriptor(descriptor);

    dtkDistributedServiceBase::instance()->logMessage("New connection");
}

//! Wait for incomming connection
/*! Warning, in its current state, this method may never return if no
 *  connection is established.
 *
 * \param rank, the identifier of the slave on the cluster side.
 */
void dtkDistributedServerDaemon::waitForConnection(int rank, QString jobid)
{
    while (!d->sockets.keys().contains(qMakePair(rank, jobid)))
        qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
}

QByteArray dtkDistributedServerDaemon::waitForData(int rank, QString jobid)
{
    dtkDistributedSocket *socket = d->sockets.value(qMakePair(rank, jobid), NULL);

    if (!socket) {
        dtkWarn() << "No socket found for rank " << rank;
        return QByteArray();
    }

    socket->blockSignals(true);

    dtkDistributedMessage *data = NULL;

    if (socket->waitForReadyRead(30000))
        data = socket->parseRequest();
    else
        dtkWarn() << "Data not ready for rank " << rank;

    socket->blockSignals(false);

    if (data) {
        return data->content();
    } else {
        dtkWarn() << "Message not allocated - return void QByteArray";
        return QByteArray();
    }
}

void dtkDistributedServerDaemon::read(void)
{
    dtkDistributedSocket *socket = (dtkDistributedSocket *)sender();
    QScopedPointer<dtkDistributedMessage> msg(socket->parseRequest());

    QByteArray r;
    QString jobid;
    int      controller_rank = dtkDistributedMessage::CONTROLLER_RANK;
    QString controller_jobid = QString("");
    QPair<int, QString> controller = qMakePair(controller_rank, controller_jobid);
    QPair<int, QString> pair;

    dtkDebug() << DTK_PRETTY_FUNCTION << "read message of type" << msg->method();

    switch (msg->method()) {
    case dtkDistributedMessage::STATUS:
        r = d->manager->status();
        socket->sendRequest(new dtkDistributedMessage(dtkDistributedMessage::OKSTATUS, "", dtkDistributedMessage::SERVER_RANK, r.size(), "json", r));
        // GET status is from the controller, store the socket in sockets using rank=-1
        d->sockets.insert(controller, socket);
        break;

    case dtkDistributedMessage::STOP:
        qApp->quit();
        break;

    case dtkDistributedMessage::NEWJOB:
        jobid = d->manager->submit(msg->content());
        dtkDebug() << DTK_PRETTY_FUNCTION << jobid;
        msg.reset(new dtkDistributedMessage(dtkDistributedMessage::OKJOB, jobid));
        socket->sendRequest(msg.data());
        break;

    case dtkDistributedMessage::ENDJOB:
        dtkDebug() << DTK_PRETTY_FUNCTION << "Job ended " << msg->jobid();
        //TODO: check if exists
        d->sockets[controller]->sendRequest(msg.data());
        break;

    case dtkDistributedMessage::SETRANK:

        dtkDebug() << DTK_PRETTY_FUNCTION << "connected remote is of rank " << msg->rank() << msg->jobid();
        d->sockets.insert(qMakePair(msg->rank(), msg->jobid()), socket);

        // rank 0 is alive, warn the controller
        if (msg->rank() == dtkDistributedMessage::SLAVE_RANK && d->sockets.contains(controller))
            (d->sockets[controller])->sendRequest(msg.data());

        break;

    case dtkDistributedMessage::DELJOB:
        jobid = msg->jobid();

        if (d->manager->deljob(jobid).startsWith("OK")) {
            msg.reset(new dtkDistributedMessage(dtkDistributedMessage::OKDEL, jobid));
            socket->sendRequest(msg.data());
        } else {
            msg.reset(new dtkDistributedMessage(dtkDistributedMessage::ERRORDEL, jobid));
            socket->sendRequest(msg.data() );
        }

        break;

    case dtkDistributedMessage::DATA:
        pair = d->sockets.key(socket);
        msg->addHeader("x-forwarded-for", QString::number(pair.first));
        dtkDebug() << DTK_PRETTY_FUNCTION << "forwarding data of type" << msg->type() << "and size" << msg->content().size() << "from" << pair.first << "to" << msg->rank();
        pair = qMakePair(msg->rank(), msg->jobid());

        if (d->sockets.contains(pair )) {
            (d->sockets[pair])->sendRequest(msg.data());
        } else {
            dtkWarn() << "unknown socket for rank, store message" <<  msg->rank() << msg->jobid();
        }

        break;

    default:
        dtkWarn() << DTK_PRETTY_FUNCTION << "Unknown data";
    };

    if (socket->bytesAvailable() > 0)
        this->read();
}

void dtkDistributedServerDaemon::discard(void)
{
    dtkDebug() << DTK_PRETTY_FUNCTION << "-- Disconnection --";

    dtkDistributedSocket *socket = (dtkDistributedSocket *)sender();
    socket->deleteLater();

    dtkDistributedServiceBase::instance()->logMessage("Connection closed");
}
