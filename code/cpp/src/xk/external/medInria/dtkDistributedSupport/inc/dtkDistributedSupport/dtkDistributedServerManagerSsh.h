/* dtkDistributedServerManagerSsh.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: mar. avril 24 18:00:15 2012 (+0200)
 * Version: $Id: d2c1205135786d7861cbd7207c4a07a75daf63e9 $
 * Last-Updated: mer. avril 25 11:08:55 2012 (+0200)
 *           By: Nicolas Niclausse
 *     Update #: 7
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKDISTRIBUTEDSERVERMANAGERSSH_H
#define DTKDISTRIBUTEDSERVERMANAGERSSH_H

#include <dtkDistributedSupportExport.h>
#include "dtkDistributedServerManager.h"

class dtkDistributedServerManagerSshPrivate;

class DTKDISTRIBUTEDSUPPORT_EXPORT dtkDistributedServerManagerSsh : public dtkDistributedServerManager
{
    Q_OBJECT


public:
    dtkDistributedServerManagerSsh(void);
    virtual ~dtkDistributedServerManagerSsh(void);

public slots:
    QByteArray status(void);
    QString submit(QString input);
    QString deljob(QString jobid);

private:
    dtkDistributedServerManagerSshPrivate *d;
};

#endif
