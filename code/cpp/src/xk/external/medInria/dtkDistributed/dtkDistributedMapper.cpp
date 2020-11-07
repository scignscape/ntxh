/* dtkDistributedMapper.cpp ---
 *
 * Author: Thibaud Kloczko
 * Created: 2013 Thu Feb  7 10:55:57 (+0100)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkDistributedMapper.h"

#include <dtkCore>
#include <QtCore>

// /////////////////////////////////////////////////////////////////
// dtkDistributedMapperPrivate interface
// /////////////////////////////////////////////////////////////////

class dtkDistributedMapperPrivate
{
public:
    dtkDistributedMapperPrivate(void) : ref(0), id_count(0) {
        clear();
    }
    ~dtkDistributedMapperPrivate(void) {
        clear();
    }

public:
    void clear(void);

public:
    void setMapping(const qlonglong& id_number, const qlonglong& pu_number);
    void initMap(const qlonglong& map_size, const qlonglong& pu_size);
    void setMap(const qlonglong& local_map_size, const qlonglong& pu_id);

public:
    qlonglong localToGlobal(const qlonglong&  local_id, const qlonglong& pu_id) const;

    qlonglong globalToLocal(const qlonglong& global_id) ;
    qlonglong globalToLocal(const qlonglong& global_id, const qlonglong& owner) ;

    qlonglong count(void) const;
    qlonglong count(const qlonglong& pu_id) const;
    qlonglong countMax(void) const;

    qlonglong owner(const qlonglong& global_id);

public:
    QAtomicInt ref;

public:
    qlonglong id_count;
    qlonglong pu_count;
    qlonglong last_pu_id;

    dtkArray<qlonglong> map;
};

// /////////////////////////////////////////////////////////////////
// dtkDistributedMapperPrivate implementation
// /////////////////////////////////////////////////////////////////

void dtkDistributedMapperPrivate::clear(void)
{
    id_count = 0;
    pu_count = 0;
    last_pu_id = 0;
    this->map.clear();
}

void dtkDistributedMapperPrivate::setMapping(const qlonglong& id_number, const qlonglong& pu_number)
{
    this->map.clear();
    this->id_count = id_number;
    this->pu_count = pu_number;
    this->map.reserve(this->pu_count + 1);

    if (this->pu_count == 1) {
        this->map << 0;

    } else if (this->id_count < this->pu_count  ) {

        qDebug() << "Number of ids less than process count: NOT YET IMPLEMENTED";
        return;

    } else {
        qlonglong step = this->id_count / this->pu_count + 1;

        qlonglong rest = this->id_count % this->pu_count;

        for (qlonglong i = 0; i < rest + 1; ++i) {
            this->map << i *step;
        }

        qlonglong last = rest * step;

        for (qlonglong i = 1; i < this->pu_count - rest; ++i) {
            this->map << last + i * (step - 1);
        }
    }

    this->map << this->id_count;
}

void dtkDistributedMapperPrivate::initMap(const qlonglong& map_size, const qlonglong& pu_size)
{
    this->id_count = map_size;
    this->pu_count = pu_size;

    this->map.resize(this->pu_count + 1);
    this->map[this->pu_count] = map_size;
}

void dtkDistributedMapperPrivate::setMap(const qlonglong& offset, const qlonglong& pu_id)
{
    this->map[pu_id] = offset;
    if (pu_id == this->pu_count) {
        this->id_count = offset;
    }
}

qlonglong dtkDistributedMapperPrivate::localToGlobal(const qlonglong& local_id, const qlonglong& pu_id) const
{
    return ( local_id + this->map.at(pu_id) );
}

qlonglong dtkDistributedMapperPrivate::globalToLocal(const qlonglong& global_id)
{
    qlonglong owner = this->owner(global_id);

    return ( global_id - this->map.at(owner) );
}

qlonglong dtkDistributedMapperPrivate::globalToLocal(const qlonglong& global_id, const qlonglong& owner)
{
    return ( global_id - this->map.at(owner) );
}

qlonglong dtkDistributedMapperPrivate::count() const
{
    return this->id_count ;
}

qlonglong dtkDistributedMapperPrivate::count(const qlonglong& pu_id) const
{
    return ( this->map.at(pu_id + 1) - this->map.at(pu_id) );
}

qlonglong dtkDistributedMapperPrivate::countMax(void) const
{
    qlonglong count_max = this->map.at(1) - this->map.at(0);

    for (int i = 1; i < this->map.count() - 1; ++i) {
        count_max = qMax(count_max, this->map.at(i + 1) - this->map.at(i));
    }

    return count_max;
}

qlonglong dtkDistributedMapperPrivate::owner(const qlonglong& global_id)
{
    if (global_id >= this->map.at(last_pu_id + 1)) {
        ++last_pu_id;

        while (global_id >= this->map.at(last_pu_id + 1))
            ++last_pu_id;
    } else if (global_id  < this->map.at(last_pu_id)) {
        --last_pu_id;

        while (global_id < this->map.at(last_pu_id))
            --last_pu_id;

    }

    return last_pu_id;
}

// /////////////////////////////////////////////////////////////////
// dtkDistributedMapper implementation
// /////////////////////////////////////////////////////////////////

dtkDistributedMapper::dtkDistributedMapper(void) : QObject(), d(new dtkDistributedMapperPrivate)
{
}

dtkDistributedMapper::dtkDistributedMapper(const dtkDistributedMapper& o) : QObject(), d(new dtkDistributedMapperPrivate)
{
    d->id_count = o.d->id_count;
    d->pu_count = o.d->pu_count;
    d->last_pu_id = o.d->last_pu_id;
    d->map = o.d->map;
}

dtkDistributedMapper::~dtkDistributedMapper(void)
{
    delete d;
    d = NULL;
}

dtkDistributedMapper *dtkDistributedMapper::scaledClone(qlonglong factor) const
{
    dtkDistributedMapper *mapper = new dtkDistributedMapper;

    mapper->initMap(d->id_count * factor, d->pu_count);

    for (qlonglong i = 0; i < d->pu_count; ++i) {
        mapper->setMap(d->map[i] * factor, i);
    }

    return mapper;
}

bool dtkDistributedMapper::deref(void)
{
    return d->ref.deref();
}

bool dtkDistributedMapper::ref(void)
{
    return d->ref.ref();
}

void dtkDistributedMapper::clear(void)
{
    d->clear();
}

void dtkDistributedMapper::setMapping(const qlonglong& id_count, const qlonglong& pu_count)
{
    d->setMapping(id_count, pu_count);
}

void dtkDistributedMapper::initMap(const qlonglong& map_size, const qlonglong& pu_size)
{
    d->initMap(map_size, pu_size);
}

void dtkDistributedMapper::setMap(const qlonglong& offset, const qlonglong& pu_id)
{
    d->setMap(offset, pu_id);
}

qlonglong dtkDistributedMapper::localToGlobal(const qlonglong& local_id, const qlonglong& pu_id) const
{
    return d->localToGlobal(local_id, pu_id);
}

qlonglong dtkDistributedMapper::globalToLocal(const qlonglong& global_id) const
{
    return d->globalToLocal(global_id);
}

qlonglong dtkDistributedMapper::globalToLocal(const qlonglong& global_id, const qlonglong& owner ) const
{
    return d->globalToLocal(global_id, owner);
}

qlonglong dtkDistributedMapper::count(void) const
{
    return d->count();
}

qlonglong dtkDistributedMapper::count(const qlonglong& pu_id) const
{
    Q_ASSERT(pu_id < d->pu_count);
    return d->count(pu_id);
}

qlonglong dtkDistributedMapper::countMax(void) const
{
    return d->countMax();
}

qlonglong dtkDistributedMapper::firstIndex(const qlonglong& pu_id) const
{
    Q_ASSERT(pu_id < d->pu_count);
    return d->map[pu_id];
}

qlonglong dtkDistributedMapper::lastIndex(const qlonglong& pu_id) const
{
    Q_ASSERT(pu_id < d->pu_count);
    return d->map[pu_id + 1] - 1;
}

qlonglong dtkDistributedMapper::owner(const qlonglong& global_id)
{
    Q_ASSERT(global_id < d->id_count);
    return d->owner(global_id);
}

// check validity of mapper: each pu_id should have at least one entry
bool dtkDistributedMapper::check(void)
{
    for (qlonglong i = 0; i < d->pu_count; ++i) {
        if (d->count(i) < 1) {
            dtkError() << "Bad mapper: wid" << i  << "has no values";
            return false;
        }
    }
    return true;
}


QDebug operator<<(QDebug dbg, dtkDistributedMapper  &mapper) {
    dbg << mapper.d->map;
    return dbg;
}

QDebug operator<<(QDebug dbg, dtkDistributedMapper  *mapper) {
    dbg << mapper->d->map;
    return dbg;
}
