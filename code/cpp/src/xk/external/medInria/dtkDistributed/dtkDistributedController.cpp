/* dtkDistributedController.cpp ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2014 - Nicolas Niclausse, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkDistributedController.h"
#include "dtkDistributedMessage.h"
#include "dtkDistributedResourceManager.h"

#include <dtkCore/dtkCore.h>

#include <dtkLog/dtkLog.h>

#include <QtNetwork>

#if !defined(Q_OS_MAC) && !defined(Q_OS_WIN)
#include <unistd.h>
#endif

#if defined(Q_OS_WIN) && !defined(__MINGW32__)
#include <windows.h>
#endif

// /////////////////////////////////////////////////////////////////
// dtkDistributedControllerPrivate declaration
// /////////////////////////////////////////////////////////////////

class dtkDistributedControllerPrivate
{
public:
    QHash<QString, QTcpSocket *> sockets;

    QHash<QString, QString > running_jobs; // all jobs started by the controller and running
    QHash<QString, QString > queued_jobs; // all jobs submitted by the controller (running or not)

    QHash<QString, QList<QProcess *> > servers;
    QHash<QString, bool > tunnel_option;

public:
    bool refreshing;
    QMutex mutex;
};


// /////////////////////////////////////////////////////////////////
// dtkDistributedController implementation
// /////////////////////////////////////////////////////////////////

/*!
  \class dtkDistributedController
  \inmodule dtkDistributed

  \brief The controller is used to interact with a remote
  dtkDistributedServer and get/view resources from this server using
  a dtkDistributedResourceManager. Differents managers are
  implemented: OAR, Torque, and Local resources on the server.

  \sa dtkDistributedServer, dtkDistributedMessage, dtkDistributedResourceManager

 */

dtkDistributedController::dtkDistributedController(QObject *parent) : QObject(parent), d(new dtkDistributedControllerPrivate)
{
    d->refreshing = false;
}

dtkDistributedController::~dtkDistributedController(void)
{
    delete d;

    d = NULL;
}

dtkDistributedController *dtkDistributedController::instance(void)
{
    if (!s_instance)
        s_instance = new dtkDistributedController;

    return s_instance;
}

//! define a default port that should be uniq among users: compute a CRC-16 hash using the username
quint16 dtkDistributedController::defaultPort(void)
{
    QProcessEnvironment pe = QProcessEnvironment::systemEnvironment();
    QString username = pe.value("USERNAME");

    if (username.isEmpty())
        username = pe.value("USER");

    if (username.isEmpty()) {
        return 9999;
    }

    QByteArray bin = username.toUtf8();
    quint16 p =  qChecksum(bin.data(), bin.length());

    if (p < 1024) // listen port should be higher than 1024
        p += 1024;

    dtkInfo() << "default port is" << p;
    return p;
}

bool dtkDistributedController::isConnected(const QUrl& server)
{
    if (d->sockets.keys().contains(server.toString())) {

        QTcpSocket *socket = d->sockets.value(server.toString());

        return (socket->state() == QAbstractSocket::ConnectedState);
    }

    return false;
}

bool dtkDistributedController::isDisconnected(const QUrl& server)
{
    if (d->sockets.keys().contains(server.toString())) {

        QTcpSocket *socket = d->sockets.value(server.toString());

        return (socket->state() == QAbstractSocket::UnconnectedState);
    }

    return true;
}

bool dtkDistributedController::submit(const QUrl& server, const QByteArray& resources, const QString& submit_id)
{
    dtkDebug() << "Want to submit jobs with resources:" << resources ;
    QScopedPointer<dtkDistributedMessage> msg (new dtkDistributedMessage(dtkDistributedMessage::NEWJOB, "", submit_id.toInt(), resources.size(), "json", resources));

    if (!d->servers.keys().contains(server.toString())) {
        dtkError() << "Can't submit job: unknown server " << server.toString();
        return false;
    }

    if (!d->sockets.contains(server.toString())) {
        dtkDebug() << "Needs to reconnect to server" << server.toString();
        this->connectSrv(server);
    }

    if (!isConnected(server)) {
        dtkWarn() << "Can't submit job:  server " << server.toString() << "is not connected";
        d->servers.remove(server.toString());
        d->tunnel_option.remove(server.toString());
        return false;
    }

    msg->send(d->sockets[server.toString()]);
    return true;
}

void dtkDistributedController::killjob(const QUrl& server, QString jobid)
{
    dtkDebug() << "Want to kill job" << jobid;

    if (!d->servers.keys().contains(server.toString())) {
        dtkError() << "Can't kill job: unknown server " << server.toString();
        return;
    }

    if (!d->sockets.contains(server.toString())) {
        dtkDebug() << "Needs to reconnect to server" << server.toString();
        this->connectSrv(server);
    }

    if (!isConnected(server)) {
        dtkWarn() << "Can't kill job: server " << server.toString() << "is not connected";
        d->servers.remove(server.toString());
        d->tunnel_option.remove(server.toString());
        return;
    }

    dtkDistributedMessage *msg  = new dtkDistributedMessage(dtkDistributedMessage::DELJOB, jobid, dtkDistributedMessage::SERVER_RANK);
    msg->send(d->sockets[server.toString()]);
    delete msg;
}

void dtkDistributedController::stop(const QUrl& server)
{
    dtkDebug() << "Want to stop server on " << server.toString();

    if (!d->sockets.contains(server.toString())) {
        dtkDebug() << "Needs to reconnect to server" << server.toString();
        this->connectSrv(server);
    }

    if (!isConnected(server)) {
        dtkWarn() << "Can't stop server " << server.toString() << "not connected";
        d->servers.remove(server.toString());
        d->tunnel_option.remove(server.toString());
        return;
    }

    dtkDebug() << "Send stop message to server" << server.toString();
    dtkDistributedMessage msg(dtkDistributedMessage::STOP, "", dtkDistributedMessage::SERVER_RANK);
    msg.send(d->sockets[server.toString()]);
    this->disconnectSrv(server);
    d->servers.remove(server.toString());
    d->tunnel_option.remove(server.toString());
}

void dtkDistributedController::refresh(const QUrl& server)
{
    dtkDebug() << server;

    if (!d->sockets.keys().contains(server.toString()))
        return;

    d->refreshing = true;

    QTcpSocket *socket = d->sockets.value(server.toString());
    dtkDistributedMessage *msg  = new dtkDistributedMessage(dtkDistributedMessage::STATUS);
    msg->send(socket);
    emit updated(server);
    delete msg;
}

// deploy a server instance on remote host (to be executed before connect)
bool dtkDistributedController::deploy(const QUrl& server, QString type, bool ssh_tunnel, QString path, QString loglevel)
{
    dtkDebug() << "deploy" << server << type << ssh_tunnel << path <<  QThread::currentThreadId();

    if (!d->servers.keys().contains(server.toString())) {

        // test if we can connect to server, if true, it means the server is deployed (by someone else ?), stop server first, and redeploy
        if (this->connectSrv(server, false, false)) {
            // can connect, server already deployed by someone else
            dtkInfo() << "server" << server << "is already deployed, restart server";
            stop(server);
        }

        int port = (server.port() == -1) ? dtkDistributedController::defaultPort() : server.port();
        QProcess *serverProc = new QProcess (this);

        QStringList args;
        args << "-t"; // that way, ssh will forward the SIGINT signal,
        // and the server will stop when the ssh process
        // is killed
        args << "-t"; // do it twice to force tty allocation
        args << "-x"; // disable X11 forwarding
        args << server.host();

        serverProc->setProcessChannelMode(QProcess::MergedChannels);

        if (ssh_tunnel) {
            dtkTrace() << "ssh port forwarding is set for server " << server.host();
            int port = (server.port() == -1) ? dtkDistributedController::defaultPort() : server.port();
            args << "-L" << QString::number(port) + ":localhost:" + QString::number(port);
        }

        args << path;
        args << "-nw";

        if (loglevel != "info") {
            args << "--loglevel";
            args << loglevel;
        }

        args << "-p";
        args << QString::number(port);
        args << "-type ";
        args << type;

        serverProc->start("ssh", args);

        // need to wait a bit for the server to open it's listening socket if we call connectSrv immediately after deploy.
        QThread::sleep(1);

        dtkDebug() << "ssh" << args;

        if (!serverProc->waitForStarted(5000)) {
            dtkError() << "server not started after 5 seconds, abort  " << args;
            serverProc->close();
            return false;
        }

        if (!serverProc->waitForReadyRead(5000)) {
            dtkError() << "no output from server after 5 seconds, abort  " << args;
            serverProc->close();
            return false;
        }

        QObject::connect(serverProc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onProcessFinished(int, QProcess::ExitStatus)));

        QObject::connect (qApp, SIGNAL(aboutToQuit()), this, SLOT(cleanup()));

        d->servers[server.toString()] << serverProc;
        d->tunnel_option[server.toString()] = ssh_tunnel;
        dtkDebug() << "A server is deployed on" << server.host();
        return true;

    }

    dtkInfo() << "dtkDistributedServer already deployed on " << server.host();
    return true;
}

void dtkDistributedController::send(dtkDistributedMessage *msg)
{
    if (d->queued_jobs.contains(msg->jobid())) {
        QString server = d->queued_jobs[msg->jobid()];
        QTcpSocket *socket = d->sockets[server];

        msg->send(socket);
    } else
        dtkWarn() << "unknown job, can't send message" << msg->jobid();

}

void dtkDistributedController::send(QVariant v, QString jobid, qint16 rank)
{
    if (d->queued_jobs.contains(jobid)) {
        QString server = d->queued_jobs[jobid];
        QTcpSocket *socket = d->sockets[server];

        QString type = "qvariant";

        //FIXME: what about the size ?
        dtkDistributedMessage *msg = new dtkDistributedMessage(dtkDistributedMessage::DATA, jobid, rank, -1, type);
        msg->send(socket);
        socket << v;
        delete msg;
    } else
        dtkWarn() << "unknown job, can't send message" << jobid;
}

QTcpSocket *dtkDistributedController::socket(const QString& jobid)
{
    if (d->queued_jobs.contains(jobid))
        if (d->sockets.contains(d->queued_jobs[jobid]))
            return d->sockets[d->queued_jobs[jobid]];

    return NULL;
}

bool dtkDistributedController::connectSrv(const QUrl& server,  bool set_rank, bool emit_connected)
{
    QString serverStr= server.toString();

    if (!d->sockets.keys().contains(serverStr)) {

        QTcpSocket *socket = new QTcpSocket(this);

        QString key;

        key = server.host();


        if (server.port() == -1) {
            const_cast<QUrl&>(server).setPort(dtkDistributedController::defaultPort());
        }

        int port = server.port();

        if (d->tunnel_option.keys().contains(serverStr) && d->tunnel_option[serverStr]) {
            dtkDebug() << "using ssh tunnel, connecting to localhost";
            socket->connectToHost("localhost", port);
        } else
            socket->connectToHost(server.host(), port);

        if (socket->waitForConnected()) {

            QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
            QObject::connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));

            d->sockets.insert(serverStr, socket);

            if (emit_connected)
                emit connected(server);

            if (set_rank) {
                dtkDebug() << "set rank for controller";
                dtkDistributedMessage msg(dtkDistributedMessage::SETRANK, "", dtkDistributedMessage::CONTROLLER_RANK);
                msg.send(socket);
            } else {
                dtkDebug() << "no need to set rank for controller";
            }

            return true;

        } else {

            dtkWarn() << "Unable to connect to" << serverStr;
            d->sockets.remove(serverStr);
            return false;
        }
    } else {
        dtkInfo() << "Already connected to server" << serverStr;
        return true;
    }
}

void dtkDistributedController::disconnectSrv(const QUrl& server)
{
    if (!d->sockets.keys().contains(server.toString())) {
        dtkDebug() << "disconnect: unknown server" << server;
        return;
    }

    QTcpSocket *socket = d->sockets.value(server.toString());
    socket->disconnectFromHost();

    d->sockets.remove(server.toString());

    emit disconnected(server);
}

bool dtkDistributedController::is_running(const QString& jobid)
{
    return d->running_jobs.contains(jobid);
}

void dtkDistributedController::read(void)
{
    QTcpSocket *socket = (QTcpSocket *)sender();

    QString server = d->sockets.key(socket);
    QScopedPointer< dtkDistributedMessage> msg(new dtkDistributedMessage);
    QVariant result;

    msg->parse(socket);

    dtkDistributedMessage::Method method = msg->method();
    int submit_id;

    switch (method) {
    case dtkDistributedMessage::OKSTATUS:
        emit updated();
        break;

    case dtkDistributedMessage::OKJOB:
        dtkDebug() << "New job queued: " << msg->jobid();
        submit_id = msg->rank(); // use rank to identify the submitter id
        d->queued_jobs[msg->jobid()] = server;
        emit jobQueued(msg->jobid(), QString::number(submit_id));
        break;

    case dtkDistributedMessage::SETRANK:
        dtkDebug() << "set rank received";

        if (msg->rank() ==  dtkDistributedMessage::SLAVE_RANK ||  msg->rank() ==  0 ) {
            dtkDebug() << "job started";
            d->running_jobs[msg->jobid()] = server;
            emit jobStarted(msg->jobid());
        }

        break;

    case dtkDistributedMessage::ENDJOB:
        dtkDebug() << "job finished: " << msg->jobid();
        d->queued_jobs.remove(msg->jobid());
        d->running_jobs.remove(msg->jobid());
        emit jobEnded(msg->jobid());
        break;

    case dtkDistributedMessage::DATA:
        if (msg->header("content-type") == "qvariant") {
            result = msg->variant();
        } else {
            dtkWarn() << "Data received, but not a variant: " << msg->header("content-type");
            result = QVariant::fromValue(msg->content());
        }

        emit dataPosted(result);
        break;

    default:
        dtkWarn() << "unknown response from server ";
    };

    if (socket->bytesAvailable() > 0)
        this->read();
}

void dtkDistributedController::cleanup()
{
    foreach (const QString& key, d->servers.keys()) {
        foreach (QProcess *server, d->servers[key]) {
            dtkDebug() << "terminating servers started on" << key;
            server->terminate();
        }
    }
}

void dtkDistributedController::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus )
{
    Q_UNUSED(exitCode);

    if (exitStatus != QProcess::NormalExit)
        dtkInfo() <<  "remote server deployment failure" << exitStatus ;
    else
        dtkInfo() <<  "remote server stopped";
}

void dtkDistributedController::error(QAbstractSocket::SocketError error)
{
    switch (error) {
    case QAbstractSocket::ConnectionRefusedError:
        dtkError() <<  "The connection was refused by the peer (or timed out).";
        break;

    case QAbstractSocket::RemoteHostClosedError:
        dtkError() <<  "The remote host closed the connection. Note that the slave socket (i.e., this socket) will be closed after the remote close notification has been sent.";
        break;

    case QAbstractSocket::HostNotFoundError:
        dtkError() <<  "The host address was not found.";
        break;

    case QAbstractSocket::SocketAccessError:
        dtkError() <<  "The socket operation failed because the application lacked the required privileges.";
        break;

    case QAbstractSocket::SocketResourceError:
        dtkError() <<  "The local system ran out of resources (e.g., too many sockets).";
        break;

    case QAbstractSocket::SocketTimeoutError:
        dtkError() <<  "The socket operation timed out.";
        break;

    case QAbstractSocket::DatagramTooLargeError:
        dtkError() <<  "The datagram was larger than the operating system's limit (which can be as low as 8192 bytes).";
        break;

    case QAbstractSocket::NetworkError:
        dtkError() <<  "An error occurred with the network (e.g., the network cable was accidentally plugged out).";
        break;

    case QAbstractSocket::AddressInUseError:
        dtkError() <<  "The address specified to QUdpSocket::bind() is already in use and was set to be exclusive.";
        break;

    case QAbstractSocket::SocketAddressNotAvailableError:
        dtkError() <<  "The address specified to QUdpSocket::bind() does not belong to the host.";
        break;

    case QAbstractSocket::UnsupportedSocketOperationError:
        dtkError() <<  "The requested socket operation is not supported by the local operating system (e.g., lack of IPv6 support).";
        break;

    case QAbstractSocket::ProxyAuthenticationRequiredError:
        dtkError() <<  "The socket is using a proxy, and the proxy requires authentication.";
        break;

    case QAbstractSocket::SslHandshakeFailedError:
        dtkError() <<  "The SSL/TLS handshake failed, so the connection was closed (only used in QSslSocket)";
        break;

    case QAbstractSocket::UnfinishedSocketOperationError:
        dtkError() <<  "Used by QAbstractSocketEngine only, The last operation attempted has not finished yet (still in progress in the background).";
        break;

    case QAbstractSocket::ProxyConnectionRefusedError:
        dtkError() <<  "Could not contact the proxy server because the connection to that server was denied";
        break;

    case QAbstractSocket::ProxyConnectionClosedError:
        dtkError() <<  "The connection to the proxy server was closed unexpectedly (before the connection to the final peer was established)";
        break;

    case QAbstractSocket::ProxyConnectionTimeoutError:
        dtkError() <<  "The connection to the proxy server timed out or the proxy server stopped responding in the authentication phase.";
        break;

    case QAbstractSocket::ProxyNotFoundError:
        dtkError() <<  "The proxy address set with setProxy() (or the application proxy) was not found.";
        break;

    case QAbstractSocket::ProxyProtocolError:
        dtkError() <<  "The connection negotiation with the proxy server because the response from the proxy server could not be understood.";
        break;

    case QAbstractSocket::UnknownSocketError:
        dtkError() <<  "An unidentified error occurred.";
        break;

    default:
        break;
    }
}

dtkDistributedController *dtkDistributedController::s_instance = NULL;
