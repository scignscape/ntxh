/* axlAbstractSurfaceParametric.cpp ---
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

#include "axlAbstractSurfaceParametric.h"

#include "axlMesh.h"

#include <dtkCoreSupport/dtkGlobal.h>

//#include <axlCore/axlAbstractVisitor.h>


class axlAbstractSurfaceParametricPrivate
{
public:
    int samples_u;
    int samples_v;
    QVector<axlPoint> samples;

    //public :
    //    axlAbstractVisitorParametric *visitor;
};

axlAbstractSurfaceParametric::axlAbstractSurfaceParametric(void) :
    axlAbstractSurface(),
    d(new axlAbstractSurfaceParametricPrivate) {

    d->samples_u = 0;
    d->samples_v = 0;
    //d->visitor = NULL;
}

axlAbstractSurfaceParametric::~axlAbstractSurfaceParametric(void)
{
    delete d;

    d = NULL;
}

axlPoint axlAbstractSurfaceParametric::eval(double u, double v)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(u);
    DTK_UNUSED(v);

    return axlPoint();
}


//axlAbstractVisitorParametric *axlAbstractSurfaceParametric::getVisitor(void){
//    return d->visitor;
//}

//void axlAbstractSurfaceParametric::setVisistor(axlAbstractVisitorParametric *visitor){
//    d->visitor = visitor;

//}

void axlAbstractSurfaceParametric::eval(axlPoint *point, double u,double v)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(point);
    DTK_UNUSED(u);
    DTK_UNUSED(v);

}


void axlAbstractSurfaceParametric::eval(axlPoint *point, double u,double v, int numCell)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(point);
    DTK_UNUSED(u);
    DTK_UNUSED(v);
    DTK_UNUSED(numCell);

}

void axlAbstractSurfaceParametric::eval(double& x, double& y, double& z, double u,double v)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(x);DTK_UNUSED(y);DTK_UNUSED(z);
    DTK_UNUSED(u);DTK_UNUSED(v);
}

dtkDeprecated::dtkVector3D<double> axlAbstractSurfaceParametric::eval2(double u, double v)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(u);
    DTK_UNUSED(v);

    return dtkDeprecated::dtkVector3D<double>();
}

axlMesh axlAbstractSurfaceParametric::eval(double u, double v, int derivs, bool u_from_right, bool v_from_right, double resolution)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(u);
    DTK_UNUSED(v);

    DTK_UNUSED(derivs);
    DTK_UNUSED(u_from_right);
    DTK_UNUSED(v_from_right);
    DTK_UNUSED(resolution);

    return axlMesh();
}


void axlAbstractSurfaceParametric::parameterOf(const axlPoint& point, double& um, double& vm) {

    unsigned N = 200;

    double x, y, z;

    if (d->samples.size() == 0) {

        double u = this->startParam_u();
        double du = (this->endParam_u() - this->startParam_u())/N;

        double v = this->startParam_v();
        double dv = (this->endParam_v() - this->startParam_v())/N;

        for (unsigned i = 0; i <= N; i++, u += du) {
            v = this->startParam_v();
            for (unsigned j = 0; j <= N; j++, v += dv) {
                this->eval(x,y,z, u, v);
                d->samples << axlPoint(x,y,z);
            }
        }
    }

    int m = 0;
    double dm = axlPoint::distance(d->samples.at(0), point);
    double dd = dm;
    for (int k = 0; k < d->samples.size(); k++) {
        if ((dd = axlPoint::distance(d->samples.at(k), point)) < dm) {
            dm = dd;
            m  = k;
        }
    }

    um = this->startParam_u() + (this->endParam_u() - this->startParam_u())/N * (m/(N+1));
    vm = this->startParam_v() + (this->endParam_v() - this->startParam_v())/N * (m%(N+1));

    dtkWarn() << "Closest parameter point:" << um << vm << "for" << point.x() << point.y() << point.z();
}


dtkDeprecated::dtkVector3D<double> axlAbstractSurfaceParametric::normal(double u, double v)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(u);
    DTK_UNUSED(v);

    return dtkDeprecated::dtkVector3D<double>();
}

void axlAbstractSurfaceParametric::normal(axlPoint *normal, double u,double v)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(normal);
    DTK_UNUSED(u);
    DTK_UNUSED(v);

}

void axlAbstractSurfaceParametric::normal(axlPoint *normal, double u,double v, int numCell)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(normal);
    DTK_UNUSED(u);
    DTK_UNUSED(v);
    DTK_UNUSED(numCell);

}

void axlAbstractSurfaceParametric::normal(dtkDeprecated::dtkVector3D<double> *normal, double u,double v)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(normal);
    DTK_UNUSED(u);
    DTK_UNUSED(v);

}


double axlAbstractSurfaceParametric::area(double tol)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(tol);

    return 0;
}

double axlAbstractSurfaceParametric::startParam_u(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.;
}

double axlAbstractSurfaceParametric::endParam_u(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 1.;
}

double axlAbstractSurfaceParametric::startParam_v(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.;
}

double axlAbstractSurfaceParametric::endParam_v(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 1.;
}


double axlAbstractSurfaceParametric::startParam_u(int numCell)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.;
}

double axlAbstractSurfaceParametric::endParam_u(int numCell)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 1.;
}

double axlAbstractSurfaceParametric::startParam_v(int numCell)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.;
}

double axlAbstractSurfaceParametric::endParam_v(int numCell)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 1.;
}

bool axlAbstractSurfaceParametric::hasCells(void){
    DTK_DEFAULT_IMPLEMENTATION;
    return false;
}

int axlAbstractSurfaceParametric::countCells(void){
    DTK_DEFAULT_IMPLEMENTATION;
    return 1;
}



int axlAbstractSurfaceParametric::numSamples_u(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

int axlAbstractSurfaceParametric::numSamples_u(int numCell)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(numCell);

    return 0;
}

int axlAbstractSurfaceParametric::numSamples_v()
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

int axlAbstractSurfaceParametric::numSamples_v(int numCell)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(numCell);

    return 0;
}



void axlAbstractSurfaceParametric::setNumSamples_u(int numSamples)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(numSamples);
}

int axlAbstractSurfaceParametric::stripes(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

void axlAbstractSurfaceParametric::setStripes(int stripes)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(stripes);
}


void axlAbstractSurfaceParametric::setNumSamples_v(int numSamples)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(numSamples);
}

const int& axlAbstractSurfaceParametric::samples_u(void) const
{
    return d->samples_u;
}


void axlAbstractSurfaceParametric::setSamples_u(const int& samples)
{
    d->samples_u = samples;
}

const int& axlAbstractSurfaceParametric::samples_v(void) const
{
    return d->samples_v;
}


void axlAbstractSurfaceParametric::setSamples_v(const int& samples)
{
    d->samples_v = samples;
}
