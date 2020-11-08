/* dtkDistributedServerManager.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue May 31 23:00:53 2011 (+0200)
 * Version: $Id: ef27c4de1f83cb1282fad8d7abbfc1042626c728 $
 * Last-Updated: mar. avril 24 18:30:15 2012 (+0200)
 *           By: Nicolas Niclausse
 *     Update #: 35
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKDISTRIBUTEDSERVERMANAGER_H
#define DTKDISTRIBUTEDSERVERMANAGER_H

#include <dtkDistributedSupportExport.h>

#include <QtCore>

class dtkDistributedNode;
class dtkDistributedCpu;
class dtkDistributedGpu;
class dtkDistributedCore;
class dtkDistributedServerManagerPrivate;

class DTKDISTRIBUTEDSUPPORT_EXPORT dtkDistributedServerManager : public QObject
{
    Q_OBJECT

public:
    dtkDistributedServerManager(void);
    virtual ~dtkDistributedServerManager(void);

    enum Type {
        Oar,
        Torque,
        Ssh
    };

    static QString protocol(void) {
        return "1.0";
    };

public slots:
    virtual QByteArray status(void) = 0;
    virtual QString submit(QString input) = 0;
    virtual QString deljob(QString jobid) = 0;

protected:
    dtkDistributedServerManagerPrivate *d;
};

#endif
