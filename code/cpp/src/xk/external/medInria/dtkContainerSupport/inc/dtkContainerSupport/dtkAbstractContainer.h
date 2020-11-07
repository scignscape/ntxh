/* dtkAbstractContainer.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Tue May 22 13:07:11 2012 (+0200)
 * Version: $Id: cd49dd568374c1092fa607e5ee50abb3c31b9528 $
 * Last-Updated: Mon Sep 30 16:44:37 2013 (+0200)
 *           By: Julien Wintz
 *     Update #: 80
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKABSTRACTCONTAINER_H
#define DTKABSTRACTCONTAINER_H

#include <dtkContainerSupportExport.h>

#include <dtkCoreSupport/dtkGlobal>

#include <typeinfo>

enum dtkContainerType {
    dtkContainerTypeNone,
    dtkContainerTypeOrdered,
    dtkContainerTypeUnordered,
    dtkContainerTypeAssociated
};

// /////////////////////////////////////////////////////////////////
// dtkAbstractContainer interface
// /////////////////////////////////////////////////////////////////

template <typename T> class dtkAbstractContainer
{
public:
    dtkAbstractContainer(void);
    dtkAbstractContainer(const dtkAbstractContainer<T>& other);
    ~dtkAbstractContainer(void);

public:
    virtual QString  identifier(void) const = 0;
    virtual QString description(void) const = 0;

    virtual dtkContainerType type(void) const = 0;

public:
    virtual void clear(void) = 0;

    virtual void add(const T& value) = 0;
    virtual void add(const dtkAbstractContainer<T>& values) = 0;

    virtual void remove(const T& value) = 0;
    virtual void remove(const dtkAbstractContainer<T>& values) = 0;

public:
    virtual bool  isEmpty(void) const = 0;

    virtual bool contains(const T& value) const = 0;
    virtual bool contains(const dtkAbstractContainer<T>& values) const = 0;

    virtual qlonglong count(void) const = 0;

    virtual       T *toArray(qlonglong& count) = 0;
    virtual const T *toArray(qlonglong& count) const = 0;

public:
    dtkAbstractContainer& operator = (const dtkAbstractContainer<T>& other); // TO RE-IMPLEMENT !!!! SOURCE OF MEMORY LEAK !!!

    virtual dtkAbstractContainer<T> *clone(void) const = 0;

public:
    dtkAbstractContainer& operator << (const T& value);
    dtkAbstractContainer& operator << (const dtkAbstractContainer<T>& values);

public:
    bool operator == (const dtkAbstractContainer<T>& other) const;
    bool operator != (const dtkAbstractContainer<T>& other) const;

    virtual bool isEqual(const dtkAbstractContainer& other) const = 0;

public:
    dtkAbstractContainer<T>& operator +  (const dtkAbstractContainer<T>& other) const;

    dtkAbstractContainer<T>& operator += (const dtkAbstractContainer<T>& other);
    dtkAbstractContainer<T>& operator += (const T& value);
};

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

template <typename T> QDebug operator << (QDebug& dbg, const dtkAbstractContainer<T>& container);
template <typename T> QDebug operator << (QDebug& dbg,       dtkAbstractContainer<T> *container);

// /////////////////////////////////////////////////////////////////
// dtkAbstractContainer implementation
// /////////////////////////////////////////////////////////////////

#include "dtkAbstractContainer.tpp"

#endif
