/* axlInteger.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInteger.h"

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlIntegerPrivate
// /////////////////////////////////////////////////////////////////

class axlIntegerPrivate
{
public:
    int value;
};

// /////////////////////////////////////////////////////////////////
// axlInteger implementation
// /////////////////////////////////////////////////////////////////

axlInteger::axlInteger(QObject *parent) : axlAbstractData(), d(new axlIntegerPrivate)
{
    d->value = 0;
}


axlInteger::axlInteger(int value, QObject *parent) : axlAbstractData(), d(new axlIntegerPrivate)
{
    d->value = value;
}



//! Constructs a copy of \a other with same value.
/*!
 *
 */
axlInteger::axlInteger(const axlInteger& other) : axlAbstractData(), d(new axlIntegerPrivate)
{
    this->setParent(other.parent());
    d->value = other.value();
}

//! Destroys the axel integer.
/*!
 *
 */
axlInteger::~axlInteger(void)
{
    delete d;
    d = NULL;
}

//! Assigns other to this integer and returns a reference to this integer.
/*!
 *
 */
axlInteger& axlInteger::operator=(const axlInteger& other)
{
    d->value= other.value();
    return (*this);
}

//! Return the value of the axlInteger.
/*!
 *
 */
int axlInteger::value(void) const{
    return d->value;
}

//! Assigns a new value to the axlInteger.
/*!
 *
 */
void axlInteger::setValue(int newValue)
{
    d->value = newValue;
    this->touchGeometry();
}


// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlInteger value)
{
    dbg.nospace() << value.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlInteger& value)
{
    dbg.nospace() << value.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlInteger *value)
{
    dbg.nospace() << value->description();

    return dbg.space();
}

QString axlInteger::description(void) const
{
    QString result = "axlInteger";
    result.append("\n value : "+QString::number(d->value) );
    return result;
}

QString axlInteger::identifier(void) const
{
    return "axlInteger";
}

QVariantList axlInteger::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    list.append(id);
    QVariant value = QVariant::fromValue(d->value);
    list.append(value);
    return list;

}

int axlInteger::convertQVariantToData(const QVariantList &data){

    d->value = data.last().toInt();
    return 1;
}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlInteger(void)
{
    return new axlInteger();

}


// /////////////////////////////////////////////////////////////////
// axlInteger documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlInteger
 *
 *  \brief Class axlInteger defines an integer.
 *
 *  This class enables to represent and manipulate integer number.
 *
 *  Example:
 *  \code
 *  axlInteger *integerValue = new axlInteger(1);
 *  \endcode
 */
