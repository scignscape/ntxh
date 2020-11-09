/* axlAbstractVolumeParametric.cpp ---
 *
 * Author:Anais Ducoffe
 * Copyright (C) 2012 - Anais Ducoffe, Inria.
 * Created:
 * Version: $Id$
 * Last-Updated:
 *           By:
 *     Update #:
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractVolumeParametric.h"

#include "axlMesh.h"
#include <dtkCoreSupport/dtkGlobal.h>
//#include <axlCore/axlAbstractVisitorParametric.h>


class axlAbstractVolumeParametricPrivate
{
public:
    int samples_u;
    int samples_v;
    int samples_w;
//public :
//    axlAbstractVisitorParametric *visitor;
};

axlAbstractVolumeParametric::axlAbstractVolumeParametric(void) : axlAbstractVolume(), d(new axlAbstractVolumeParametricPrivate)
{
    //d->visitor = NULL;
}

axlAbstractVolumeParametric::~axlAbstractVolumeParametric(void)
{
    delete d;

    d = NULL;
}

axlPoint axlAbstractVolumeParametric::eval(double u, double v, double w)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(u);
    DTK_UNUSED(v);
    DTK_UNUSED(w);

    return axlPoint();
}


//axlAbstractVisitorParametric *axlAbstractVolumeParametric::getVisitor(void){
//    return d->visitor;
//}

//void axlAbstractVolumeParametric::setVisitor(axlAbstractVisitorParametric *visitor){
//    d->visitor = visitor;
//}

void axlAbstractVolumeParametric::eval(axlPoint *point, double u,double v, double w)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(point);
    DTK_UNUSED(u);
    DTK_UNUSED(v);
    DTK_UNUSED(w);

}

void axlAbstractVolumeParametric::eval(double& x, double& y, double& z, double u,double v, double w)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(x);DTK_UNUSED(y);DTK_UNUSED(z);
    DTK_UNUSED(u);DTK_UNUSED(v);DTK_UNUSED(w);
}

dtkDeprecated::dtkVector3D<double> axlAbstractVolumeParametric::eval2(double u, double v,double w)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(u);
    DTK_UNUSED(v);
    DTK_UNUSED(w);

    return dtkDeprecated::dtkVector3D<double>();
}

axlMesh axlAbstractVolumeParametric::eval(double u, double v,double w, int derivs, bool u_from_right, bool v_from_right,bool w_from_right, double resolution)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(u);
    DTK_UNUSED(v);
    DTK_UNUSED(w);

    DTK_UNUSED(derivs);
    DTK_UNUSED(u_from_right);
    DTK_UNUSED(v_from_right);
    DTK_UNUSED(w_from_right);
    DTK_UNUSED(resolution);

    return axlMesh();
}


dtkDeprecated::dtkVector3D<double> axlAbstractVolumeParametric::normal(double u, double v, double w)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(u);
    DTK_UNUSED(v);
    DTK_UNUSED(w);

    return dtkDeprecated::dtkVector3D<double>();
}

void axlAbstractVolumeParametric::normal(axlPoint *normal, double u,double v, double w)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(normal);
    DTK_UNUSED(u);
    DTK_UNUSED(v);
    DTK_UNUSED(w);

}

void axlAbstractVolumeParametric::normal(dtkDeprecated::dtkVector3D<double> *normal, double u,double v, double w)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(normal);
    DTK_UNUSED(u);
    DTK_UNUSED(v);
    DTK_UNUSED(w);

}


//double axlAbstractVolumeParametric::volume(double tol)
//{
//    DTK_DEFAULT_IMPLEMENTATION;
//    DTK_UNUSED(tol);

//    return 0;
//}

double axlAbstractVolumeParametric::startParam_u(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.;
}

double axlAbstractVolumeParametric::endParam_u(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 1.;
}

double axlAbstractVolumeParametric::startParam_v(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.;
}

double axlAbstractVolumeParametric::endParam_v(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 1.;
}

double axlAbstractVolumeParametric::startParam_w(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.;
}

double axlAbstractVolumeParametric::endParam_w(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 1.;
}

int axlAbstractVolumeParametric::numSamples_u(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

int axlAbstractVolumeParametric::numSamples_v(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

int axlAbstractVolumeParametric::numSamples_w(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

void axlAbstractVolumeParametric::setNumSamples_u(int numSamples)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(numSamples);
}

int axlAbstractVolumeParametric::stripes(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

void axlAbstractVolumeParametric::setStripes(int stripes)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(stripes);
}


void axlAbstractVolumeParametric::setNumSamples_v(int numSamples)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(numSamples);
}

void axlAbstractVolumeParametric::setNumSamples_w(int numSamples)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(numSamples);
}

const int& axlAbstractVolumeParametric::samples_u(void) const
{
    return d->samples_u;
}


void axlAbstractVolumeParametric::setSamples_u(const int& samples)
{
    d->samples_u = samples;
}

const int& axlAbstractVolumeParametric::samples_v(void) const
{
    return d->samples_v;
}


void axlAbstractVolumeParametric::setSamples_v(const int& samples)
{
    d->samples_v = samples;
}

const int& axlAbstractVolumeParametric::samples_w(void) const
{
    return d->samples_w;
}


void axlAbstractVolumeParametric::setSamples_w(const int& samples)
{
    d->samples_w = samples;
}
