/* axlAbstractCurveParametric.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:33:05 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 22
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTCURVEPARAMETRIC_H
#define AXLABSTRACTCURVEPARAMETRIC_H

#include "axlAbstractCurve.h"
#include "axlCoreExport.h"

class axlPoint;
class axlMesh;

class axlAbstractCurveParametricPrivate;
//class axlAbstractVisitorParametric;

/** \brief Generic interface for parametric curve.
 *  \li The parameter domain is defined by  starting parameter and end parameter.
 *  \li It provides an evaluation function which compute a point from a parameter.
**/
class AXLCORE_EXPORT axlAbstractCurveParametric : public axlAbstractCurve
{
    Q_OBJECT
    Q_PROPERTY(int samples READ samples WRITE setSamples)

public:
    axlAbstractCurveParametric(void);
    virtual ~axlAbstractCurveParametric(void);


    virtual double startParam(void);
    virtual double endParam(void);

    virtual axlPoint eval(double u);
    virtual void eval(axlPoint *point, double u);
    virtual axlMesh eval(double u, int derivs, bool from_right = true);

    double  parameterOf(const axlPoint& p);

    virtual double length(double tolerance);
    virtual int numSamples(void);
    virtual void setNumSamples(int numSamples);


//public :
//    virtual axlAbstractVisitorParametric *getVisitor(void);
//    virtual void setVisitor(axlAbstractVisitorParametric *visitor);





public:
    const int& samples(void) const;

public slots:
    virtual void onDirectChanged(bool direct);
    void setSamples(const int& color);

private:
    axlAbstractCurveParametricPrivate *d;
};
#endif
