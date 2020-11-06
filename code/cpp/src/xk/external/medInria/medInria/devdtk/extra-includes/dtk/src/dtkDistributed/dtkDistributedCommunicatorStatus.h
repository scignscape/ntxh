/* @(#)dtkDistributedCommunicatorStatus.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2013 - Nicolas Niclausse, Inria.
 * Created: 2013/04/30 09:24:57
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

class dtkDistributedCommunicatorStatusPrivate;

class DTKDISTRIBUTED_EXPORT dtkDistributedCommunicatorStatus
{

public:
    dtkDistributedCommunicatorStatus(void);
    virtual ~dtkDistributedCommunicatorStatus(void);

public:
    int       tag(void) const;
    qlonglong  count(void) const;
    qint32 source(void) const;
    int     error(void) const;

public:
    void    setTag(int tag);
    void  setCount(qlonglong count);
    void setSource(qint32 source);
    void  setError(int error);

private:
    dtkDistributedCommunicatorStatusPrivate *d;
};
