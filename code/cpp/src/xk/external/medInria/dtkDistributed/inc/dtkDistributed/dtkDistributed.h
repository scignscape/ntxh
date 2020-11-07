// Version: $Id: c8f0dc80728b2fbffaec5b6b91c07f8de7498e74 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#pragma once

#include <dtkDistributedExport.h>

#include <QtCore>

class dtkDistributedApplication;
class dtkDistributedCommunicator;
class dtkDistributedController;
class dtkDistributedCoreApplication;
class dtkDistributedCommunicatorPlugin;
class dtkDistributedCommunicatorPluginFactory;
class dtkDistributedCommunicatorPluginManager;
class dtkDistributedPolicy;

// ///////////////////////////////////////////////////////////////////
// Distribution layer attributes
// ///////////////////////////////////////////////////////////////////

namespace dtkDistributed {
#pragma mark -
#pragma mark Distribution namespace flags

    enum Mode {
        Global,
        Local
    };

#pragma mark -
#pragma mark Setting distribution mode

    DTKDISTRIBUTED_EXPORT void setMode(dtkDistributed::Mode);

#pragma mark -
#pragma mark Querying distribution mode

    DTKDISTRIBUTED_EXPORT dtkDistributed::Mode mode(void);

#pragma mark -
#pragma mark retrieve dtkDistributedApplication global pointer

    DTKDISTRIBUTED_EXPORT dtkDistributedApplication *app(void);

#pragma mark -
#pragma mark create dtkDistributedApplication application

    DTKDISTRIBUTED_EXPORT dtkDistributedApplication *create(int& argc, char *argv[]);

#pragma mark -
#pragma mark retrieve current policy

    DTKDISTRIBUTED_EXPORT dtkDistributedPolicy *policy(void);

#pragma mark -
#pragma mark spawn application

    DTKDISTRIBUTED_EXPORT void spawn(void);

#pragma mark -
#pragma mark execute task

    DTKDISTRIBUTED_EXPORT void exec(QRunnable *task);

#pragma mark -
#pragma mark unspawn application

    DTKDISTRIBUTED_EXPORT void unspawn(void);

#pragma mark -
#pragma mark Modular concepts

    namespace communicator {
        DTKDISTRIBUTED_EXPORT dtkDistributedCommunicatorPluginFactory& pluginFactory(void);
        DTKDISTRIBUTED_EXPORT dtkDistributedCommunicatorPluginManager& pluginManager(void);
        DTKDISTRIBUTED_EXPORT dtkDistributedCommunicator *instance(void);
        DTKDISTRIBUTED_EXPORT void   initialize(const QString& path = QString());
        DTKDISTRIBUTED_EXPORT void setInstance(dtkDistributedCommunicator *comm);
        DTKDISTRIBUTED_EXPORT void setVerboseLoading(bool verbose);
    }

    namespace controller {
        DTKDISTRIBUTED_EXPORT dtkDistributedController *instance(void);

        // wrappers to force the execution of the  methods in the controller thread
        DTKDISTRIBUTED_EXPORT bool connectSrv(const QUrl& server, bool ssh_rank = false, bool emit_connected = true);
        DTKDISTRIBUTED_EXPORT bool     deploy(const QUrl& server, QString type = "local", bool ssh_tunnel = false, QString path = "./dtkDistributedServer", QString loglevel = "info");
        DTKDISTRIBUTED_EXPORT bool     submit(const QUrl& server, const QByteArray& resources, const QString& submit_id = "");

        /* DTKDISTRIBUTED_EXPORT void disconnect(const QUrl& server); */
        /* DTKDISTRIBUTED_EXPORT void       stop(const QUrl& server); */
        /* DTKDISTRIBUTED_EXPORT void    refresh(const QUrl& server); */
        /* DTKDISTRIBUTED_EXPORT void    killjob(const QUrl& server, QString jobid); */
        /* void       send(dtkDistributedMessage *msg); */
        /* void       send(QVariant v, QString jobid, qint16 destrank); */

    }
}

// ///////////////////////////////////////////////////////////////////
// Distribution macros
// ///////////////////////////////////////////////////////////////////

#define DTK_DISTRIBUTED_BEGIN_GLOBAL \
    dtkDistributed::app()->communicator()->barrier(); if (dtkDistributed::communicator::instance()->rank() == 0) {

#define DTK_DISTRIBUTED_END_GLOBAL \
    } ; dtkDistributed::app()->communicator()->barrier();

#define DTK_DISTRIBUTED_BEGIN_LOCAL \
    dtkDistributed::app()->communicator()->barrier();
#define DTK_DISTRIBUTED_END_LOCAL \
    ;

//
// dtkDistributed.h ends here
