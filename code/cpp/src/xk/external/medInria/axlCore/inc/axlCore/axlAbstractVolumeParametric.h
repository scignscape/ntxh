/* axlAbstractVolumeParametric.h ---
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

#ifndef AXLABSTRACTVOLUMEPARAMETRIC_H
#define AXLABSTRACTVOLUMEPARAMETRIC_H

#include "axlAbstractVolume.h"
#include "axlCoreExport.h"
#include "axlPoint.h"

#include <dtkMathSupport/dtkVector3D.h>

class axlMesh;
class axlAbstractVolumeParametricPrivate;
//class axlAbstractVisitorParametric;

class AXLCORE_EXPORT axlAbstractVolumeParametric : public axlAbstractVolume
{
    Q_OBJECT
    Q_PROPERTY(int samples_u READ samples_u WRITE setSamples_u)
    Q_PROPERTY(int samples_v READ samples_v WRITE setSamples_v)
    Q_PROPERTY(int samples_w READ samples_w WRITE setSamples_w)

public:
    axlAbstractVolumeParametric(void);
    virtual ~axlAbstractVolumeParametric(void);

    virtual axlPoint eval(double u, double v, double w);
    virtual void eval(axlPoint *point, double u,double v, double w);
    virtual void eval(double&, double&, double&, double u,double v, double w);
    virtual void normal(axlPoint *normal, double u,double v, double w);

    virtual axlMesh eval(double u, double v,double w, int derivs, bool u_from_right = true, bool v_from_right = true,bool w_from_right = true, double resolution = 1.0e-12);
    virtual dtkDeprecated::dtkVector3D<double> eval2(double u,double v, double w);


    virtual dtkDeprecated::dtkVector3D<double> normal(double u,double v, double w);
    virtual void normal(dtkDeprecated::dtkVector3D<double> *normal, double u,double v, double w);


//    virtual double volume(double tol);

    virtual int numSamples_u(void);
    virtual int numSamples_v(void);
    virtual int numSamples_w(void);

    virtual double startParam_u(void);
    virtual double endParam_u(void);
    virtual double startParam_v(void);
    virtual double endParam_v(void);
    virtual double startParam_w(void);
    virtual double endParam_w(void);


    virtual int stripes(void);
    virtual void setStripes(int stripes);

    virtual void setNumSamples_u(int numSamples);
    virtual void setNumSamples_v(int numSamples);
     virtual void setNumSamples_w(int numSamples);




public:
    const int& samples_u(void) const;
    const int& samples_v(void) const;
    const int& samples_w(void) const;

public slots:
    void setSamples_u(const int& color);
    void setSamples_v(const int& color);
    void setSamples_w(const int& color);


//public :
//    virtual axlAbstractVisitorParametric *getVisitor(void);
//    virtual void setVisitor(axlAbstractVisitorParametric *visitor);



private:
    axlAbstractVolumeParametricPrivate *d;
};
#endif
