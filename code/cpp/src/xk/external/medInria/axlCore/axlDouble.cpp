/* axlDouble.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlDouble.h"

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlDoublePrivate
// /////////////////////////////////////////////////////////////////

class axlDoublePrivate
{
public:
    double value;
};

// /////////////////////////////////////////////////////////////////
// axlDouble implementation
// /////////////////////////////////////////////////////////////////

axlDouble::axlDouble(QObject *parent) : axlAbstractData(), d(new axlDoublePrivate)
{
    d->value = 0.0;
}


axlDouble::axlDouble(double value, QObject *parent) : axlAbstractData(), d(new axlDoublePrivate)
{
    d->value = value;
}



//! Constructs a copy of \a other with same value.
/*!
 *
 */
axlDouble::axlDouble(const axlDouble& other) : axlAbstractData(), d(new axlDoublePrivate)
{
    this->setParent(other.parent());
    d->value = other.value();
}

//! Destroys the axel double.
/*!
 *
 */
axlDouble::~axlDouble(void)
{
    delete d;
    d = NULL;
}

//! Assigns other to this double and returns a reference to this double.
/*!
 *
 */
axlDouble& axlDouble::operator=(const axlDouble& other)
{
    d->value= other.value();
    return (*this);
}


double axlDouble::value(void) const{
    return d->value;
}

void axlDouble::setValue(double newValue)
{
    d->value = newValue;
    this->touchGeometry();
}


// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlDouble value)
{
    dbg.nospace() << value.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlDouble& value)
{
    dbg.nospace() << value.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlDouble *value)
{
    dbg.nospace() << value->description();

    return dbg.space();
}

QString axlDouble::description(void) const
{
    QString result = "axlDouble";
    result.append("\n value : "+QString::number(d->value) );
    return result;
}

QString axlDouble::identifier(void) const
{
    return "axlDouble";
}


QVariantList axlDouble::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    list.append(id);
    QVariant value = QVariant::fromValue(d->value);
    list.append(value);
    return list;

}

int axlDouble::convertQVariantToData(const QVariantList &data){
    d->value = data.last().toDouble();
    return 1;
}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlDouble(void)
{
    return new axlDouble();

}


// /////////////////////////////////////////////////////////////////
// axlDouble documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlDouble
 *
 *  \brief Class axlDouble defines a double.
 *
 *  This class enables to represent and manipulate double number.
 *
 *  Example:
 *  \code
 *  axlDouble *doubleValue = new axlDouble(0.6);
 *  \endcode
 */
