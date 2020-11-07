/* dtkContainerVector.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Wed May 23 11:19:32 2012 (+0200)
 * Version: $Id: 766af74c48e147afce07593112133082768502da $
 * Last-Updated: mer. sept. 17 15:06:03 2014 (+0200)
 *           By: Thibaud Kloczko
 *     Update #: 84
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCONTAINERVECTOR_H
#define DTKCONTAINERVECTOR_H

#include "dtkAbstractContainerOrdered.h"
#include <dtkContainerSupportExport.h>

//#include <dtkCoreSupport/dtkArray.h>
#include <dtkCore/dtkArray>

#include <QtCore>

// /////////////////////////////////////////////////////////////////
// dtkContainerVector interface
// /////////////////////////////////////////////////////////////////

template <typename T> class dtkContainerVector : public dtkAbstractContainerOrdered<T>
{
public:
    typedef typename dtkArray<T>::iterator iterator;
    typedef typename dtkArray<T>::const_iterator const_iterator;

public:
    dtkContainerVector(void);
    dtkContainerVector(qlonglong size);
    dtkContainerVector(qlonglong size, const T& value);
    dtkContainerVector(const dtkContainerVector<T>& other);
    virtual ~dtkContainerVector(void);

public:
    QString  identifier(void) const;
    QString description(void) const;

public:
    void clear(void);

    void append(const T& value);
    void append(const dtkAbstractContainer<T>& values);
    void append(const   dtkContainerVector<T>& values);

    void prepend(const T& value);
    void prepend(const dtkAbstractContainer<T>& values);
    void prepend(const   dtkContainerVector<T>& values);

    void remove(const T& value);
    void remove(const dtkAbstractContainer<T>& values);
    void remove(const   dtkContainerVector<T>& values);

    void insert(qlonglong index, const T& value);
    void insert(qlonglong from, const dtkAbstractContainer<T>& values);
    void insert(qlonglong from, qlonglong step, const dtkAbstractContainer<T>& values);
    void insert(qlonglong *indices, const dtkAbstractContainer<T>& values);
    void insert(qlonglong from, const dtkContainerVector<T>& values);
    void insert(qlonglong from, qlonglong step, const dtkContainerVector<T>& values);
    void insert(qlonglong *indices, const dtkContainerVector<T>& values);

    void replace(qlonglong index, const T& value);
    void replace(qlonglong from, const dtkAbstractContainer<T>& values);
    void replace(qlonglong from, qlonglong step, const dtkAbstractContainer<T>& values);
    void replace(qlonglong *indices, const dtkAbstractContainer<T>& values);
    void replace(qlonglong from, const dtkContainerVector<T>& values);
    void replace(qlonglong from, qlonglong step, const dtkContainerVector<T>& values);
    void replace(qlonglong *indices, const dtkContainerVector<T>& values);

    void removeAt(qlonglong index);
    void removeAt(qlonglong from, qlonglong to, qlonglong step = 1);

    void reserve(qlonglong value);
    void resize(qlonglong size);

    void  squeeze(void);

public:
    bool  isEmpty(void) const;

    bool contains(const T& value) const;
    bool contains(const dtkAbstractContainer<T>& values) const;
    bool contains(const   dtkContainerVector<T>& values) const;

    qlonglong capacity(void) const;
    qlonglong    count(void) const;

    qlonglong     indexOf(const T& value, qlonglong from = 0)  const;
    qlonglong lastIndexOf(const T& value, qlonglong from = -1) const;

    qlonglong *indicesOf(const T& value, qlonglong from = 0) const;

    const T& at(qlonglong index) const;

    const T& first(void) const;
    const T&  last(void) const;

    dtkContainerVector<T> *subContainer(const dtkAbstractContainerOrdered<qlonglong>& indices)  const;
    dtkContainerVector<T> *subContainer(qlonglong from, qlonglong to, qlonglong step = 1) const;

    T *toArray(qlonglong& count);
    const T *toArray(qlonglong& count) const;

    T *array(void);
    const T *array(void) const;

    const T *constArray(void) const;

public:
    const T& operator [] (qlonglong index) const;
    T& operator [] (qlonglong index)      ;

public:
    dtkContainerVector& operator = (const dtkContainerVector<T>& other);

    dtkContainerVector<T> *clone(void) const;

public:
    dtkContainerVector& operator << (const T& value);
    dtkContainerVector& operator << (const dtkContainerVector<T>& values);

public:
    bool operator == (const dtkContainerVector<T>& other) const;
    bool operator != (const dtkContainerVector<T>& other) const;

    bool isEqual(const dtkAbstractContainer<T>& other) const;

public:
    dtkContainerVector<T>  operator +  (const dtkContainerVector<T>& other);

    dtkContainerVector<T>& operator += (const dtkContainerVector<T>& other);
    dtkContainerVector<T>& operator += (const T& value);

public:
    template <typename U> friend dtkContainerVector<U> dtkContainerVectorFromQVector(const QVector<U>& vector);
    template <typename U> friend QVector<U> dtkContainerVectorToQVector(const dtkContainerVector<U>& vector);
    template <typename U> friend dtkContainerVector<T> dtkContainerVectorFromDtkArray(const dtkArray<U>& vector);
    template <typename U> friend dtkArray<U> dtkContainerVectorToDtkArray(const dtkContainerVector<U>& vector);


public:
    iterator begin(iterator = iterator())                    {
        return m_vector.begin();
    }
    const_iterator begin(const_iterator = const_iterator()) const  {
        return m_vector.constBegin();
    }
    const_iterator cbegin(const_iterator = const_iterator()) const {
        return m_vector.constBegin();
    }

    iterator end(iterator = iterator())                        {
        return m_vector.end();
    }
    const_iterator end(const_iterator = const_iterator()) const      {
        return m_vector.constEnd();
    }
    const_iterator cend(const_iterator = const_iterator()) const     {
        return m_vector.constEnd();
    }

private:
    dtkArray<T> m_vector;
};

// // /////////////////////////////////////////////////////////////////
// // Helper functions
// // /////////////////////////////////////////////////////////////////

template <typename T> dtkContainerVector<T> dtkContainerVectorFromQVector(const QVector<T>& vector);
template <typename T> QVector<T> dtkContainerVectorToQVector(const dtkContainerVector<T>& vector);
template <typename T> dtkContainerVector<T> dtkContainerVectorFromDtkArray(const dtkArray<T>& vector);
template <typename T> dtkArray<T> dtkContainerVectorToDtkArray(const dtkContainerVector<T>& vector);

// /////////////////////////////////////////////////////////////////
// dtkContainerVector implementation
// /////////////////////////////////////////////////////////////////

#include "dtkContainerVector.tpp"

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

typedef dtkContainerVector<qreal> dtkContainerVectorReal;

Q_DECLARE_METATYPE(dtkContainerVectorReal  );
Q_DECLARE_METATYPE(dtkContainerVectorReal *);

typedef dtkContainerVector<qlonglong> dtkContainerVectorInteger;

Q_DECLARE_METATYPE(dtkContainerVectorInteger  );
Q_DECLARE_METATYPE(dtkContainerVectorInteger *);

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

#include <dtkMathSupport/dtkVector3D.h>

typedef dtkContainerVector<dtkVector3DReal *> dtkContainerVectorVector3DReal;

Q_DECLARE_METATYPE(dtkContainerVectorVector3DReal  );
Q_DECLARE_METATYPE(dtkContainerVectorVector3DReal *);

#endif
