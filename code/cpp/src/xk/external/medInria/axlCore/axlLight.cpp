/* axlLight.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlLight.h"

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtGui>

// /////////////////////////////////////////////////////////////////
// axlLightPrivate
// /////////////////////////////////////////////////////////////////

class axlLightPrivate
{
public:
    double position[3];
    double ambiant[3];
    double diffuse[3];
    double specular[3];
    double exponent;


public:
    QColor color;
    double opacity;
    QString shader;
};

// /////////////////////////////////////////////////////////////////
// axlLight implementation
// /////////////////////////////////////////////////////////////////

//! Constructs a axel light of zero position with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel light with no parent.
 */
axlLight::axlLight(QObject *parent) : dtkAbstractData(), d(new axlLightPrivate)
{
    this->setObjectName(this->description());
    d->position[0] = 0.0;
    d->position[1] = 0.0;
    d->position[2] = 0.0;

    d->ambiant[0] = 1.0;
    d->ambiant[1] = 1.0;
    d->ambiant[2] = 1.0;

    d->diffuse[0] = 1.0;
    d->diffuse[1] = 1.0;
    d->diffuse[2] = 1.0;

    d->specular[0] = 1.0;
    d->specular[1] = 1.0;
    d->specular[2] = 1.0;

    d->exponent = 50;

}

//! Constructs a axel light of position (\a x, \a y, \a z) with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel light with no parent.
 */
axlLight::axlLight(double x, double y, double z, QObject *parent) : dtkAbstractData(), d(new axlLightPrivate)
{
    this->setObjectName(this->description());
    d->position[0] = x;
    d->position[1] = y;
    d->position[2] = z;

    d->ambiant[0] = 1.0;
    d->ambiant[1] = 1.0;
    d->ambiant[2] = 1.0;

    d->diffuse[0] = 1.0;
    d->diffuse[1] = 1.0;
    d->diffuse[2] = 1.0;

    d->specular[0] = 1.0;
    d->specular[1] = 1.0;
    d->specular[2] = 1.0;

    d->exponent = 50;
}

axlLight::axlLight(double *position, double *ambiant, double *diffuse, double *specular, double exponent, QObject *parent)
{
    this->setObjectName(this->description());

    for(int i = 0; i < 3; i++)
    {
        d->position[i] = position[i];
        d->ambiant[i] = ambiant[i];
        d->diffuse[i] = diffuse[i];
        d->specular[i] = specular[i];
    }

    d->exponent = exponent;
}

//! Constructs a copy of \a other.
/*!
 *
 */
axlLight::axlLight(const axlLight& other) : dtkAbstractData(), d(new axlLightPrivate)
{
    this->setObjectName(this->description());
    this->setParent(other.parent());
    d->position[0] = other.d->position[0];
    d->position[1] = other.d->position[1];
    d->position[2] = other.d->position[2];

    d->ambiant[0] = other.d->ambiant[0];
    d->ambiant[1] = other.d->ambiant[1];
    d->ambiant[2] = other.d->ambiant[2];

    d->diffuse[0] = other.d->diffuse[0];
    d->diffuse[1] = other.d->diffuse[1];
    d->diffuse[2] = other.d->diffuse[2];

    d->specular[0] = other.d->specular[0];
    d->specular[1] = other.d->specular[1];
    d->specular[2] = other.d->specular[2];

    d->exponent = other.d->exponent;
}

//! Destroys the axel light.
/*!
 *
 */
axlLight::~axlLight(void)
{
    delete d;

    d = NULL;
}



//! Returns x-coordinate of this light.
/*!
 *
 */
double axlLight::x(void) const
{
    return d->position[0];
}

//! Returns y-coordinate of this light.
/*!
 *
 */
double axlLight::y(void) const
{
    return d->position[1];
}

//! Returns z-coordinate of this light.
/*!
 *
 */
double axlLight::z(void) const
{
    return d->position[2];
}

//! Returns position of this light.
/*!
 *
 */
double *axlLight::position(void) const
{
    return d->position ;
}

double *axlLight::ambiant(void) const
{
    return d->ambiant ;
}

double *axlLight::diffuse(void) const
{
    return d->diffuse ;
}

double *axlLight::specular(void) const
{
    return d->specular ;
}

double axlLight::exponent(void) const
{
    return d->exponent ;
}

void axlLight::setPosition(axlPoint *position)
{
    for (int i =0; i < 3 ; i ++)
        d->position[i] = position->coordinates()[i];
}

void axlLight::setAmbiant(axlPoint *ambiant)
{
    for (int i =0; i < 3 ; i ++)
        d->ambiant[i] = ambiant->coordinates()[i];
}

void axlLight::setDiffuse(axlPoint *diffuse)
{
    for (int i =0; i < 3 ; i ++)
        d->diffuse[i] = diffuse->coordinates()[i];
}

void axlLight::setSpecular(axlPoint *specular)
{
    for (int i =0; i < 3 ; i ++)
        d->specular[i] = specular->coordinates()[i];
}

void axlLight::setExponent(double position)
{
    d->exponent = position;
}

//SLOTS

void axlLight::onPositionChanged(axlPoint *position)
{
    this->setPosition(position);
}


//Property Method

const QColor& axlLight::color(void) const
{
    return d->color;
}

void axlLight::setColor(const QColor& color)
{
    d->color = color;
}

const double& axlLight::opacity(void) const
{
    return d->opacity;
}

void axlLight::setOpacity(const double& opacity)
{
    d->opacity = opacity;
}

const QString& axlLight::shader(void) const
{
    return d->shader;
}


void axlLight::setShader(const QString& shader)
{
    d->shader = shader;
}


// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlLight light)
{

    QString position(QString("position: (%1, %2, %3)\n").arg(light.position()[0]).arg(light.position()[1]).arg(light.position()[2]));
    QString ambiant(QString("ambiant: (%1, %2, %3)\n").arg(light.ambiant()[0]).arg(light.ambiant()[1]).arg(light.ambiant()[2]));
    QString diffuse(QString("diffuse: (%1, %2, %3)\n").arg(light.diffuse()[0]).arg(light.diffuse()[1]).arg(light.diffuse()[2]));
    QString specular(QString("specular: (%1, %2, %3)\n").arg(light.specular()[0]).arg(light.specular()[1]).arg(light.specular()[2]));
    QString exponent(QString("exponent: (%1)").arg(light.exponent()));

    dbg.nospace() << QString("axlLight:\n") << position << ambiant << diffuse << specular<<exponent;

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlLight& light)
{
    QString position(QString("position: (%1, %2, %3)\n").arg(light.position()[0]).arg(light.position()[1]).arg(light.position()[2]));
    QString ambiant(QString("ambiant: (%1, %2, %3)\n").arg(light.ambiant()[0]).arg(light.ambiant()[1]).arg(light.ambiant()[2]));
    QString diffuse(QString("diffuse: (%1, %2, %3)\n").arg(light.diffuse()[0]).arg(light.diffuse()[1]).arg(light.diffuse()[2]));
    QString specular(QString("specular: (%1, %2, %3)\n").arg(light.specular()[0]).arg(light.specular()[1]).arg(light.specular()[2]));
    QString exponent(QString("exponent: (%1)").arg(light.exponent()));

    dbg.nospace() << QString("axlLight:\n") << position << ambiant << diffuse << specular<<exponent;

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlLight *light)
{
    QString position(QString("position: (%1, %2, %3)\n").arg(light->position()[0]).arg(light->position()[1]).arg(light->position()[2]));
    QString ambiant(QString("ambiant: (%1, %2, %3)\n").arg(light->ambiant()[0]).arg(light->ambiant()[1]).arg(light->ambiant()[2]));
    QString diffuse(QString("diffuse: (%1, %2, %3)\n").arg(light->diffuse()[0]).arg(light->diffuse()[1]).arg(light->diffuse()[2]));
    QString specular(QString("specular: (%1, %2, %3)\n").arg(light->specular()[0]).arg(light->specular()[1]).arg(light->specular()[2]));
    QString exponent(QString("exponent: (%1)").arg(light->exponent()));

    dbg.nospace() << QString("axlLight:\n") << position << ambiant << diffuse << specular<<exponent;
    return dbg.space();
}

QString axlLight::description(void) const
{
    return "axlLight";
}

// /////////////////////////////////////////////////////////////////
// axlLight documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlLight
 *
 *  \brief Class axlLight defines 3D lights.
 *
 *  This class enables to represent and manipulate 3D lights.
 *
 *  Example:
 *  \code
 *  axlLight *A = new axlLight(0.0, 0.0, 0.0);
 *  axlLight *B = new axlLight(1.0, 0.0, 0.0);
 *  double length = axlLight::distance(A, B);
 *  axlLight middle = *(A);
 *  middle += *(B);
 *  middle /= 2.;
 *  \endcode
 */
