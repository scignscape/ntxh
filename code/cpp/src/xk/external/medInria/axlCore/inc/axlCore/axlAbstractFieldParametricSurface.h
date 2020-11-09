/* axlAbstractFieldParametricSurface.h ---
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
#ifndef AXLABSTRACTFIELDPARAMETRICSURFACE_H
#define AXLABSTRACTFIELDPARAMETRICSURFACE_H

#include <axlCore/axlAbstractFieldParametric.h>

class axlAbstractFieldParametricSurfacePrivate;
class axlAbstractData;

class AXLCORE_EXPORT axlAbstractFieldParametricSurface : public axlAbstractFieldParametric
{
    Q_OBJECT

public:
    axlAbstractFieldParametricSurface();
    virtual ~axlAbstractFieldParametricSurface(void);

    //    void setType(Type type);
    //    void setKind(Kind kind);
    //    void setSupport(Support support);


    //    Type type(void);
    //    Kind kind(void);
    //    Support support(void);

    virtual void setSurface(axlAbstractData *surface);

    virtual int size(void);

    virtual double  scalar(double u, double v, double w = 0);
    virtual double *vector(double u, double v, double w = 0);
    virtual double *tensor(double u, double v, double w = 0);

    virtual double start_u(void);
    virtual double start_v(void);
    //    virtual double start_w(void);

    virtual double end_u(void);
    virtual double end_v(void);
    //    virtual double end_w(void);

    virtual double numbersample_u(void);
    virtual double numbersample_v(void);
    //    virtual double numbersample_w(void);

    virtual void setFunction(axlAbstractData *data);
    virtual axlAbstractData *getFunction(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;
    //    virtual QString name(void);
    //    virtual void setName(QString name);

signals :
    void updated(void);


public slots:
    virtual void update(void);


private:
    axlAbstractFieldParametricSurfacePrivate *d;
};

dtkAbstractData *createaxlAbstractFieldParametricSurface(void);


#endif  // AXLABSTRACTFIELDPARAMETRICSURFACE_H
