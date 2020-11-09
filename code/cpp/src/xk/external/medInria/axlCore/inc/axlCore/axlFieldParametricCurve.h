/* axlFieldParametricCurve.h ---
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
#ifndef AXLFIELDPARAMETRICCURVE_H
#define AXLFIELDPARAMETRICCURVE_H

#include <axlCore/axlAbstractFieldParametricCurve.h>

class axlFieldParametricCurvePrivate;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldParametricCurve : public axlAbstractFieldParametricCurve
{
    Q_OBJECT

public:
    axlFieldParametricCurve();
    virtual ~axlFieldParametricCurve(void);

//    void setType(Type type);
//    void setKind(Kind kind);
//    void setSupport(Support support);

    void setFunction(axlAbstractData *data);
    axlAbstractData *getFunction(void);
    void setCurve(axlAbstractData *data);

    double start_u(void);

    double end_u(void);

    double numbersample_u(void);

    int size(void);

//    Type type(void);
//    Kind kind(void);
//    Support support(void);

    virtual double  scalar(double u, double v = 0., double w = 0.);
    virtual double *vector(double u, double v = 0., double w = 0.);
    virtual double *tensor(double u, double v = 0., double w = 0.);

    virtual QString description(void) const;
    virtual QString identifier(void) const;
//    virtual QString name(void);
//    virtual void setName(QString name);


public slots:
    virtual void update(void);


private:
    axlFieldParametricCurvePrivate *d;
};

AXLCORE_EXPORT dtkAbstractData *createaxlFieldParametricCurve(void);


#endif // AXLFIELDPARAMETRICCURVE_H
