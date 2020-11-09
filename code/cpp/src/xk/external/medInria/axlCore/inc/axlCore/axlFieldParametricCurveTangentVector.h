/* axlFieldParametricCurveTangentVector.h ---
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
#ifndef AXLFIELDPARAMETRICCURVETANGENTVECTOR_H
#define AXLFIELDPARAMETRICCURVETANGENTVECTOR_H

#include <axlCore/axlAbstractFieldParametricCurve.h>

class axlFieldParametricCurveTangentVectorPrivate;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldParametricCurveTangentVector : public axlAbstractFieldParametricCurve
{
    Q_OBJECT

public:
    axlFieldParametricCurveTangentVector();
    virtual ~axlFieldParametricCurveTangentVector(void);

    void setCurve(axlAbstractData *data);

    double start_u(void);

    double end_u(void);

    double numbersample_u(void);

    int size(void);

    double *vector(double u, double v=0., double w=0.);

    QString description(void) const;
    QString identifier(void) const;



public slots:
    virtual void update(void);


private:
    axlFieldParametricCurveTangentVectorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractData *createaxlFieldParametricCurveTangentVector(void);


#endif// AXLFIELDPARAMETRICCURVETANGENTVECTOR_H
