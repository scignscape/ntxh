/* axlSurfaceParametricOffset.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Mar 29 09:43:31 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 36
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlSurfaceParametricOffset.h"

#include <dtkCoreSupport/dtkGlobal.h>


class axlSurfaceParametricOffsetPrivate
{
public:
    double offset;
    axlAbstractSurfaceParametric *surface;
};

//! Constructs a axlSurfaceParametricOffset with an axlAbstractSurfaceParametric and a distance offset.
/*!
 */
axlSurfaceParametricOffset::axlSurfaceParametricOffset(axlAbstractSurfaceParametric *surfaceParam, double offset) : axlAbstractSurfaceParametric(), d(new axlSurfaceParametricOffsetPrivate)
{
    this->setObjectName(this->identifier());
    if(surfaceParam)
        this->setParent(surfaceParam->parent());
    d->offset = offset;
    d->surface = surfaceParam;
}

//! Constructs a copy of \a other.
/*!
 *
 */
axlSurfaceParametricOffset::axlSurfaceParametricOffset(const axlSurfaceParametricOffset& other) : axlAbstractSurfaceParametric(), d(new axlSurfaceParametricOffsetPrivate)
{
    this->setObjectName(this->identifier());
    this->setParent(other.parent());
    d->offset = other.d->offset;
    d->surface = other.d->surface;

}

axlSurfaceParametricOffset::~axlSurfaceParametricOffset(void)
{
    delete d;

    d = NULL;
}

//! Assigns other to this axlSurfaceParametricOffset and returns a reference to this axlSurfaceParametricOffset.
/*!
 *
 */
axlSurfaceParametricOffset& axlSurfaceParametricOffset::operator=(const axlSurfaceParametricOffset& other)
{
    this->setObjectName(this->identifier());
    this->setParent(other.parent());
    d->offset = other.d->offset;
    d->surface = other.d->surface;

    return (*this);
}

//! Return offset of this axlSurfaceParametricOffset.
/*!
 *
 */
double axlSurfaceParametricOffset::offset(void)
{
    return d->offset;
}

//! Set the offset of this axlSurfaceParametricOffset.
/*!
 *
 */
void axlSurfaceParametricOffset::setOffset(double offset)
{
    d->offset = offset;
}

//! Return the pointer on the axlAbstractSurfaceParametric of this axlSurfaceParametricOffset.
/*!
 *
 */
axlAbstractSurfaceParametric *axlSurfaceParametricOffset::surfaceParam(void)
{
    return d->surface;
}


// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlSurfaceParametricOffset sphere)
{
    dbg.nospace() << sphere.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlSurfaceParametricOffset& sphere)
{
    dbg.nospace() << sphere.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlSurfaceParametricOffset *sphere)
{
    dbg.nospace() << sphere->description();

    return dbg.space();
}

QString axlSurfaceParametricOffset::description(void) const
{
    QString result = "axlSurfaceParametricOffset";
    result.append("\noffset : "+QString::number(d->offset)+ "n" + d->surface->description());
    return result;
}

QString axlSurfaceParametricOffset::identifier(void) const
{
    return "axlSurfaceParametricOffset";
}

// /////////////////////////////////////////////////////////////////
// axlSphere documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlSurfaceParametricOffset
 *
 *  \brief Class axlSurfaceParametricOffset defines offset of axlAbstractSurfaceParametric.
 *
 *  This class enables to represent and manipulate axlSurfaceParametricOffset.
 *
 *  Example:
 *  \code
 *  axlAbstractSurfaceParametric *surfaceParam = dtkAsbtractFactory::instance(...);// the axlAbstractSurfaceParametric need to be instanciated
 *  double offset = 1.0;
 *  axlSurfaceParametricOffset *A = new axlSurfaceParametricOffset(surfaceParam, offset);
 *  \endcode
 */
