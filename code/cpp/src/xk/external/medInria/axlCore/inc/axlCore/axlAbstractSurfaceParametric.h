/* axlAbstractSurfaceParametric.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Mar 29 09:43:43 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 24
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTSURFACEPARAMETRIC_H
#define AXLABSTRACTSURFACEPARAMETRIC_H

#include "axlAbstractSurface.h"
#include "axlCoreExport.h"
#include "axlPoint.h"

#include <dtkMathSupport/dtkVector3D.h>

class axlMesh;
class axlAbstractSurfaceParametricPrivate;
//class axlAbstractVisitorParametric;

class AXLCORE_EXPORT axlAbstractSurfaceParametric : public axlAbstractSurface
{
    Q_OBJECT
    Q_PROPERTY(int samples_u READ samples_u WRITE setSamples_u)
    Q_PROPERTY(int samples_v READ samples_v WRITE setSamples_v)

public:
    axlAbstractSurfaceParametric(void);
    virtual ~axlAbstractSurfaceParametric(void);

    virtual axlPoint eval(double u, double v);
    virtual void eval(axlPoint *point, double u,double v);
    virtual void eval(double&, double&, double&, double u,double v);
    virtual void normal(axlPoint *normal, double u,double v);

    virtual axlMesh eval(double u, double v, int derivs, bool u_from_right = true, bool v_from_right = true, double resolution = 1.0e-12);
    virtual dtkDeprecated::dtkVector3D<double> eval2(double u,double v);

    virtual void parameterOf(const axlPoint& point, double& um, double& vm);


    virtual dtkDeprecated::dtkVector3D<double> normal(double u,double v);
    virtual void normal(dtkDeprecated::dtkVector3D<double> *normal, double u,double v);


    virtual double area(double tol);

    virtual int numSamples_u(void);
    virtual int numSamples_v(void);

    virtual double startParam_u(void);
    virtual double endParam_u(void);
    virtual double startParam_v(void);
    virtual double endParam_v(void);


    virtual double startParam_u(int numCell);
    virtual double endParam_u(int numCell);
    virtual double startParam_v(int numCell);
    virtual double endParam_v(int numCell);
    virtual void eval(axlPoint *point, double u,double v, int numCell);
    virtual void normal(axlPoint *normal, double u,double v, int numCell);
    virtual bool hasCells(void);
    virtual int countCells(void);
    virtual int numSamples_u(int numCell);
    virtual int numSamples_v(int numCell);


    virtual int stripes(void);
    virtual void setStripes(int stripes);

    virtual void setNumSamples_u(int numSamples);
    virtual void setNumSamples_v(int numSamples);

public:
    const int& samples_u(void) const;
    const int& samples_v(void) const;

public slots:
    void setSamples_u(const int& color);
    void setSamples_v(const int& color);

//public :
//    virtual axlAbstractVisitorParametric *getVisitor(void);
//    virtual void setVisistor(axlAbstractVisitorParametric *visitor);



private:
    axlAbstractSurfaceParametricPrivate *d;
};
#endif
