/* axlAbstractFieldParametricVolume.h ---
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
#ifndef AXLABSTRACTFIELDPARAMETRICVOLUME_H
#define AXLABSTRACTFIELDPARAMETRICVOLUME_H

#include <axlCore/axlAbstractFieldParametric.h>

class axlAbstractFieldParametricVolumePrivate;
class axlAbstractData;

class AXLCORE_EXPORT axlAbstractFieldParametricVolume : public axlAbstractFieldParametric
{
    Q_OBJECT

public:
    axlAbstractFieldParametricVolume();
    virtual ~axlAbstractFieldParametricVolume(void);

    virtual void setVolume(axlAbstractData *Volume);

    virtual int size(void);

    virtual double  scalar(double u, double v, double w);
    virtual double *vector(double u, double v, double w);
    virtual double *tensor(double u, double v, double w);

    virtual double start_u(void);
    virtual double start_v(void);
    virtual double start_w(void);

    virtual double end_u(void);
    virtual double end_v(void);
    virtual double end_w(void);

    virtual double numbersample_u(void);
    virtual double numbersample_v(void);
    virtual double numbersample_w(void);

    virtual void setFunction(axlAbstractData *data);
    virtual axlAbstractData *getFunction(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

signals :
    void updated(void);


public slots:
    virtual void update(void);


private:
    axlAbstractFieldParametricVolumePrivate *d;
};

dtkAbstractData *createaxlAbstractFieldParametricVolume(void);


#endif // AXLABSTRACTFIELDPARAMETRICVOLUME_H
