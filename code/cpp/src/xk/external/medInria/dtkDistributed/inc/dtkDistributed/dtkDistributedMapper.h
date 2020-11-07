// Version: $Id: 0b2de3c651d708594f0250cc3190278c01cd0832 $
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

class dtkDistributedMapperPrivate;

// /////////////////////////////////////////////////////////////////
// dtkDistributedMapper interface
// /////////////////////////////////////////////////////////////////

class DTKDISTRIBUTED_EXPORT dtkDistributedMapper : public QObject
{
    Q_OBJECT

public:
    dtkDistributedMapper(void);
    dtkDistributedMapper(const dtkDistributedMapper& o);
    ~dtkDistributedMapper(void);

public:
    dtkDistributedMapper *scaledClone(qlonglong factor) const;

public:
    bool deref(void);
    bool   ref(void);

public:
    void clear(void);
    bool check(void);

public:
    void setMapping(const qlonglong& id_count, const qlonglong& pu_count);

    void initMap(const qlonglong& map_size, const qlonglong& pu_size);
    void setMap(const qlonglong& offset, const qlonglong& pu_id);

public:
    qlonglong localToGlobal(const qlonglong& local_id, const qlonglong& pu_id) const;

    qlonglong globalToLocal(const qlonglong& global_id) const;
    qlonglong globalToLocal(const qlonglong& global_id, const qlonglong& owner) const;

    qlonglong count(void) const;
    qlonglong count(const qlonglong& pu_id) const;
    qlonglong countMax(void) const;

    qlonglong firstIndex(const qlonglong& pu_id) const;
    qlonglong  lastIndex(const qlonglong& pu_id) const;

    qlonglong owner(const qlonglong& global_id);

public:
    friend DTKDISTRIBUTED_EXPORT QDebug operator<<(QDebug dbg, dtkDistributedMapper& mapper);
    friend DTKDISTRIBUTED_EXPORT QDebug operator<<(QDebug dbg, dtkDistributedMapper *mapper);

private:
    dtkDistributedMapperPrivate *d;
};

//
// dtkDistributedMapper.h ends here
