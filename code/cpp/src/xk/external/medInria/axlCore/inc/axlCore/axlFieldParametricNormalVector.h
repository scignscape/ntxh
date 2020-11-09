/* axlFieldParametricNormalVector.h ---
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
#ifndef AXLFIELDPARAMETRICNORMALVECTOR_H
#define AXLFIELDPARAMETRICNORMALVECTOR_H

#include <axlCore/axlAbstractFieldParametricSurface.h>

class axlFieldParametricNormalVectorPrivate;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldParametricNormalVector : public axlAbstractFieldParametricSurface
{
    Q_OBJECT

public:
    axlFieldParametricNormalVector();
    virtual ~axlFieldParametricNormalVector(void);

    void setSurface(axlAbstractData *data);

    double start_u(void);
    double start_v(void);

    double end_u(void);
    double end_v(void);

    double numbersample_u(void);
    double numbersample_v(void);

    int size(void);


    double *vector(double u, double v,double w=0.);

    QString description(void) const;
    QString identifier(void) const;



public slots:
    virtual void update(void);


private:
    axlFieldParametricNormalVectorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractData *createaxlFieldParametricNormalVector(void);


#endif // AXLFIELDPARAMETRICNORMALVECTOR_H
