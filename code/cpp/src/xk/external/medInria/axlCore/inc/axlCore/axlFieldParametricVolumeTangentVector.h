/* axlFieldParametricVolumeTangentVector.h ---
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
#ifndef AXLFIELDPARAMETRICVOLUMETANGENTVECTOR_H
#define AXLFIELDPARAMETRICVOLUMETANGENTVECTOR_H

#include <axlCore/axlAbstractFieldParametricVolume.h>

class axlFieldParametricVolumeTangentVectorPrivate;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldParametricVolumeTangentVector : public axlAbstractFieldParametricVolume
{
    Q_OBJECT

public:
    axlFieldParametricVolumeTangentVector();
    virtual ~axlFieldParametricVolumeTangentVector(void);

    void setVolume(axlAbstractData *data);
    void setParameter(double parameter, int channel);

    double parameter(int channel);

    double start_u(void);
    double start_v(void);
    double start_w(void);

    double end_u(void);
    double end_v(void);
    double end_w(void);

    double numbersample_u(void);
    double numbersample_v(void);
    double numbersample_w(void);

    int size(void);


    double *vector(double u, double v, double w);

    QString description(void) const;
    QString identifier(void) const;



public slots:
    virtual void update(void);


private:
    axlFieldParametricVolumeTangentVectorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractData *createaxlFieldParametricVolumeTangentVector(void);


#endif // AXLFIELDPARAMETRICVOLUMETANGENTVECTOR_H
