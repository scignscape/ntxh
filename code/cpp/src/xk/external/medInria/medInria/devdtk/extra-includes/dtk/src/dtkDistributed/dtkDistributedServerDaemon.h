// Version: $Id: 1a158912279fb285f1697dc7db820753224e2c16 $
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
#include <QtNetwork>

class dtkDistributedResourceManager;

class DTKDISTRIBUTED_EXPORT dtkDistributedServerDaemonPrivate;

class DTKDISTRIBUTED_EXPORT dtkDistributedServerDaemon : public QTcpServer
{
    Q_OBJECT

public:
    dtkDistributedServerDaemon(quint16 port, QObject *parent = 0);
    ~dtkDistributedServerDaemon(void);

    void setManager(QString type);

    dtkDistributedResourceManager *manager(void);

    void waitForConnection(int rank, QString jobid);
    QByteArray waitForData(int rank, QString jobid);

protected:
    void incomingConnection(qintptr descriptor);

private slots:
    virtual void read(void);
    void discard(void);

private:
    dtkDistributedServerDaemonPrivate *d;
};

//
// dtkDistributedServerDaemon.h ends here
