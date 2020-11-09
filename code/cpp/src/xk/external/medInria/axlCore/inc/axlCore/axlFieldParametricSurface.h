/* axlFieldParametricSurface.h ---
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
#ifndef AXLFIELDPARAMETRICSURFACE_H
#define AXLFIELDPARAMETRICSURFACE_H

#include <axlCore/axlAbstractFieldParametricSurface.h>

class axlFieldParametricSurfacePrivate;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldParametricSurface : public axlAbstractFieldParametricSurface
{
    Q_OBJECT

public:
    axlFieldParametricSurface();
    virtual ~axlFieldParametricSurface(void);

    //    void setType(Type type);
    //    void setKind(Kind kind);
    //    void setSupport(Support support);

    void setFunction(axlAbstractData *data);
    axlAbstractData *getFunction(void);
    void setSurface(axlAbstractData *data);

    double start_u(void);
    double start_v(void);

    double end_u(void);
    double end_v(void);

    double numbersample_u(void);
    double numbersample_v(void);

    int size(void);

    //    Type type(void);
    //    Kind kind(void);
    //    Support support(void);

    virtual double  scalar(double u, double v, double w = 0);
    virtual double *vector(double u, double v, double w = 0);
    virtual double *tensor(double u, double v, double w = 0);

    virtual QString description(void) const;
    virtual QString identifier(void) const;
    //    virtual QString name(void);
    //    virtual void setName(QString name);


public slots:
    virtual void update(void);


private:
    axlFieldParametricSurfacePrivate *d;
};

AXLCORE_EXPORT dtkAbstractData *createaxlFieldParametricSurface(void);


#endif // AXLFIELDPARAMETRICSURFACE_H
