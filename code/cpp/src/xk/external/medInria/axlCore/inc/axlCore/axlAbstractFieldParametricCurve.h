/* axlAbstractFieldParametricCurve.h ---
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
#include "axlCoreExport.h"
#ifndef AXLABSTRACTFIELDPARAMETRICCURVE_H
#define AXLABSTRACTFIELDPARAMETRICCURVE_H

#include <axlCore/axlAbstractFieldParametric.h>

class axlAbstractFieldParametricCurvePrivate;
class axlAbstractData;

class AXLCORE_EXPORT axlAbstractFieldParametricCurve : public axlAbstractFieldParametric
{
    Q_OBJECT

public:
    axlAbstractFieldParametricCurve();
    virtual ~axlAbstractFieldParametricCurve(void);

    virtual void setCurve(axlAbstractData *Curve);

    virtual int size(void);

    virtual double  scalar(double u, double v = 0, double w = 0);
    virtual double *vector(double u, double v = 0, double w = 0);
    virtual double *tensor(double u, double v = 0, double w = 0);

    virtual double start_u(void);

    virtual double end_u(void);

    virtual double numbersample_u(void);

    virtual void setFunction(axlAbstractData *data);
    virtual axlAbstractData *getFunction(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;


signals :
    void updated(void);


public slots:
    virtual void update(void);


private:
    axlAbstractFieldParametricCurvePrivate *d;
};

dtkAbstractData *createaxlAbstractFieldParametricCurve(void);


#endif  // AXLABSTRACTFIELDPARAMETRICCURVE_H
