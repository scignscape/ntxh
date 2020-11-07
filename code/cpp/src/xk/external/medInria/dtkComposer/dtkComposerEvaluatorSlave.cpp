/* @(#)dtkComposerEvaluatorSlave.cpp ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: 2012/04/06 14:25:39
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */


#include "dtkComposerEvaluatorSlave.h"

#include "dtkComposerEvaluator.h"
#include "dtkComposerNodeFactory.h"
#include "dtkComposerNodeGraph.h"
#include "dtkComposerGraph.h"
#include "dtkComposerReaderNoScene.h"
#include "dtkComposerNodeRemote.h"

#include <dtkDistributed/dtkDistributedCommunicator.h>
#include <dtkDistributed/dtkDistributedMessage.h>
#include <dtkDistributed/dtkDistributed.h>

#include <dtkLog/dtkLog.h>

#include <iostream>


// helper function

dtkComposerNodeRemote *get_first_node(dtkComposerNodeGraph * graph) {
    dtkComposerNode *root = graph->rootNodes().first();
    foreach (dtkComposerNode *node, graph->nodes()) {
        if (graph->scope(node) == root )
            if (dtkComposerNodeRemote * remote = dynamic_cast<dtkComposerNodeRemote *>(node) ) {
                return remote;
            }
    }
    return NULL;
}


// dtkComposerEvaluatorSlavePrivate class declaration

class dtkComposerEvaluatorSlavePrivate
{
public:
    dtkDistributedCommunicator *communicator_i;

public:
    QTcpSocket *composition_socket;

public:
    dtkComposerGraph        *eval_graph;
    dtkComposerNodeGraph    *node_graph;
    dtkComposerNodeFactory     *factory;
    dtkComposerReaderNoScene    *reader;
    dtkComposerEvaluator     *evaluator;

public:
    QUrl server;
    int  count;
    int  last_controller_rank;
    int  status;

public:
    QMap<int, QString> composition_cache;
};

dtkComposerEvaluatorSlave::dtkComposerEvaluatorSlave(void) : dtkDistributedSlave(), d(new dtkComposerEvaluatorSlavePrivate)
{
    d->evaluator = new dtkComposerEvaluator;
    d->reader    = new dtkComposerReaderNoScene;
    d->eval_graph = new dtkComposerGraph;

    d->node_graph = NULL;
    d->factory   = NULL;
    d->composition_socket = NULL;
    d->communicator_i = NULL;

    d->evaluator->setGraph(d->eval_graph);
    d->evaluator->setNotify(false);

    d->reader->setGraph(d->eval_graph);
    d->count  = 0;
    d->status = 0;
}

dtkComposerEvaluatorSlave::~dtkComposerEvaluatorSlave(void)
{
    delete d->communicator_i;
    delete d->eval_graph;
    delete d->reader;
    delete d->evaluator;

    if (d->composition_socket)
        delete d->composition_socket;

    delete d;

    d = NULL;
}

void dtkComposerEvaluatorSlave::setCount(int count)
{
    d->count = count;
}

void dtkComposerEvaluatorSlave::setFactory(dtkComposerNodeFactory *factory)
{
    d->factory = factory;
    d->reader->setFactory(d->factory);
}

void dtkComposerEvaluatorSlave::setServer(QUrl server)
{
    d->server = server;
}

int dtkComposerEvaluatorSlave::status(void)
{
    return d->status;
}

void dtkComposerEvaluatorSlave::run(void)
{
    d->status = 0;

    if ( !d->communicator_i) {
        d->communicator_i = dtkDistributed::communicator::instance();

        if (d->communicator_i->rank() == 0) {
            std::cout << QString("DTK_JOBID=" + this->jobId()).toStdString() << std::endl << std::flush;
        }
    }

    if (!d->factory) {
        dtkFatal() << "No factory set ! abort slave execution";
        d->status = 1;
        return;
    }

    int rank = d->communicator_i->rank();
    int size = d->communicator_i->size();
    dtkDebug() << "communicator size is" << size;
    dtkDebug() << "our rank is" << rank;

    if ( rank == 0) {

        QScopedPointer<dtkDistributedMessage> msg;
        bool new_composition;

        if (!this->isConnected()) {
            dtkDebug() << "connect to server" << d->server;
            this->connect(d->server);

            if (this->isConnected()) {
                if (!d->composition_socket) {
                    dtkDebug() << "open second socket to server" << d->server;
                    d->composition_socket = new QTcpSocket;
                    d->composition_socket->connectToHost(d->server.host(), d->server.port());

                    if (d->composition_socket->waitForConnected()) {
                        msg.reset(new dtkDistributedMessage(dtkDistributedMessage::SETRANK, this->jobId(), dtkDistributedMessage::SLAVE_RANK ));
                        msg->send(d->composition_socket);
                    } else {
                        dtkError() << "Can't connect to server";
                        d->status = 1;
                        return;
                    }
                }

                dtkDebug() << "connected, send our jobid to server" << this->jobId();
                msg.reset(new dtkDistributedMessage(dtkDistributedMessage::SETRANK, this->jobId(), 0));
                msg->send(this->socket());
                this->socket()->flush();
                this->socket()->setParent(0);
            } else  {
                dtkFatal() << "Can't connect to server" << d->server;
                d->status = 1;
                return;
            }
        }

        QString composition;

        dtkDebug() << "Wait for composition from controller " ;

        if (d->composition_socket->bytesAvailable() > 10) {
            dtkInfo() << "data already available, try to parse composition " << d->composition_socket->bytesAvailable();
        } else if (!d->composition_socket->waitForReadyRead(600000)) {
            dtkFatal() << "No data received from server after 10mn, abort " ;
            d->status = 1;
            return;
        } else {
            dtkDebug() << "Ok, data received on composition socket, parse" ;
        }

        msg.reset(new dtkDistributedMessage);
        msg->parse(d->composition_socket);

        if (msg->type() == "xml") {
            new_composition = true;
            composition = QString(msg->content());
            d->last_controller_rank = msg->header("x-forwarded-for").toInt();
            d->composition_cache.insert(d->last_controller_rank, composition);
        } else if (msg->type() == "not-modified") { // reuse the old composition
            if (msg->header("x-forwarded-for").toInt() == d->last_controller_rank) {
                new_composition = false;
            } else {
                d->last_controller_rank = msg->header("x-forwarded-for").toInt();
                dtkDebug() << "not modified, but from another controller" << d->last_controller_rank;
                new_composition = true;
                composition = d->composition_cache.value(d->last_controller_rank);
            }
        } else {
            dtkFatal() << "Bad composition type, abort" << msg->type() << msg->content();
            d->status = 1;
            return;
        }

        if (new_composition && composition.isEmpty()) {
            dtkFatal() << "Empty composition, abort" ;
            d->status = 1;
            return;
        }

        dtkDebug() << "got composition from controller:" << composition;

        if (new_composition) {
            dtkDebug() << "new composition";

            if  (size > 1) {
                dtkDebug() << "send composition to our slaves";

                for (int i = 1; i < size; i++) {
                    d->communicator_i->send(composition, i, 0);
                }
            }

            dtkDebug() << "parse composition" ;
            d->reader->readString(composition);
            d->node_graph = d->reader->nodeGraph();

        } else {
            dtkInfo() << "composition hasn't changed";

            for (int i = 1; i < size; i++)
                d->communicator_i->send(QString("rerun"), i, 0);
        }

        if (new_composition) {
            if (dtkComposerNodeRemote *remote = get_first_node(d->node_graph)) {
                //FIXME: can we remove this ?
                // this->communicator()->setProperty("jobid",this->jobId());
                remote->setSlave(this);
                remote->setJob(this->jobId());
                remote->setCommunicator(d->communicator_i);
            } else {
                dtkFatal() <<  "Can't find remote node in composition, abort";
                d->status = 1;
                return;
            }
        }

        dtkDebug() << "run composition" ;

        if (QThread::currentThread() == qApp->thread()) {
            dtkTrace() << "running on main thread, create a thread for the evaluator"  ;
            QThread *workerThread = new QThread(this);
            QObject::connect(workerThread, SIGNAL(started()),  d->evaluator, SLOT(run()), Qt::DirectConnection);
            QObject::connect(d->evaluator, SIGNAL(evaluationStopped()), workerThread, SLOT(quit()));

            QEventLoop loop;
            loop.connect(d->evaluator, SIGNAL(evaluationStopped()), &loop, SLOT(quit()));
            loop.connect(qApp, SIGNAL(aboutToQuit()), &loop, SLOT(quit()));

            this->socket()->moveToThread(workerThread);
            workerThread->start();

            loop.exec();

            workerThread->wait();
            workerThread->deleteLater();
        } else {
            dtkTrace() << "running on dedicated thread,run the evaluator" ;
            d->evaluator->run_static();
        }

        dtkDebug() << "finished" ;

    } else {
        QString composition;
        d->communicator_i->receive(composition, 0, 0);

        if (composition != "rerun") {
            dtkDebug() << "new/changed composition, read"  ;
            dtkDebug() << " composition is " << composition ;
            d->reader->readString(composition);
            d->node_graph = d->reader->nodeGraph();
            dtkDebug() << "read done" ;
        } else {
            dtkDebug() << "reuse composition" ;
        }

        if (dtkComposerNodeRemote *remote = get_first_node(d->node_graph)) {
            remote->setSlave(this);
            remote->setJob(this->jobId());
            remote->setCommunicator(d->communicator_i);
            dtkDebug() << "run composition" ;

            QThread *workerThread = new QThread(this);
            QObject::connect(workerThread, SIGNAL(started()),  d->evaluator, SLOT(run()), Qt::DirectConnection);
            QObject::connect(d->evaluator, SIGNAL(evaluationStopped()), workerThread, SLOT(quit()));
            QEventLoop loop;
            loop.connect(d->evaluator, SIGNAL(evaluationStopped()), &loop, SLOT(quit()));
            loop.connect(qApp, SIGNAL(aboutToQuit()), &loop, SLOT(quit()));

            workerThread->start();
            loop.exec();

            workerThread->wait();
            workerThread->deleteLater();
            // d->evaluator->run_static();
            dtkDebug() << "finished" ;
        } else {
            dtkFatal() <<  "Can't find remote node in composition, abort";
            d->status = 1;
            return;
        }
    }
}
