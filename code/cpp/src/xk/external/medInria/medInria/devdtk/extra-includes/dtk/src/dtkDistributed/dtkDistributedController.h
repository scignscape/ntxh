/* dtkDistributedController.h ---
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

#pragma once

#include <dtkDistributedExport.h>

#include <QtCore>
#include <QtNetwork>

class dtkDistributedMessage;
class dtkDistributedControllerPrivate;

class DTKDISTRIBUTED_EXPORT dtkDistributedController : public QObject
{
    Q_OBJECT

public:
    dtkDistributedController(QObject *parent = 0);
    ~dtkDistributedController(void);

public:
    static dtkDistributedController *instance(void);

public:
    Q_INVOKABLE static quint16 defaultPort(void);

public:
    bool    isConnected(const QUrl& server);
    bool isDisconnected(const QUrl& server);

public:
    QTcpSocket *socket(const QString& jobid);

signals:
    void    connected(const QUrl& server);
    void disconnected(const QUrl& server);

signals:
    void updated(void);
    void updated(const QUrl& server);

signals:
    void dataPosted(QVariant data);
    void jobEnded(QString jobid);
    void jobStarted(QString jobid);
    void jobQueued(QString jobid, QString submit_id);

public slots:
    bool    connectSrv(const QUrl& server, bool ssh_rank = false, bool emit_connected = true);
    void disconnectSrv(const QUrl& server);
    void       stop(const QUrl& server);
    void    refresh(const QUrl& server);
    void    killjob(const QUrl& server, QString jobid);
    void       send(dtkDistributedMessage *msg);
    void       send(QVariant v, QString jobid, qint16 destrank);
    bool     deploy(const QUrl& server, QString type = "local", bool ssh_tunnel = false, QString path = "./dtkDistributedServer", QString loglevel = "info");
    bool     submit(const QUrl& server, const QByteArray& resources, const QString& submit_id = "");

public:
    bool is_running(const QString& jobid);

protected slots:
    void read(void);
    void error(QAbstractSocket::SocketError error);
    void cleanup(void);

protected slots:
    void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    static dtkDistributedController *s_instance;

private:
    dtkDistributedControllerPrivate *d;
};
