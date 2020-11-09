/* axlFieldParametricSurfaceTangentVector.h ---
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
#ifndef AXLFIELDPARAMETRICSURFACETANGENTVECTOR_H
#define AXLFIELDPARAMETRICSURFACETANGENTVECTOR_H

#include <axlCore/axlAbstractFieldParametricSurface.h>

class axlFieldParametricSurfaceTangentVectorPrivate;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldParametricSurfaceTangentVector : public axlAbstractFieldParametricSurface
{
    Q_OBJECT

public:
    axlFieldParametricSurfaceTangentVector();
    virtual ~axlFieldParametricSurfaceTangentVector(void);

    void setSurface(axlAbstractData *data);
    void setParameter(double parameter, int channel);

    double parameter(int channel);

    double start_u(void);
    double start_v(void);

    double end_u(void);
    double end_v(void);

    double numbersample_u(void);
    double numbersample_v(void);

    int size(void);


    double* vector(double u, double v, double w=0.);

    QString description(void) const;
    QString identifier(void) const;

public slots:
    virtual void update(void);

private:
    axlFieldParametricSurfaceTangentVectorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractData *createaxlFieldParametricSurfaceTangentVector(void);


#endif // AXLFIELDPARAMETRICSURFACETANGENTVECTOR_H
