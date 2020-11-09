/* axlFieldParametricVolume.h ---
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
#ifndef AXLFIELDPARAMETRICVOLUME_H
#define AXLFIELDPARAMETRICVOLUME_H

#include <axlCore/axlAbstractFieldParametricVolume.h>

class axlFieldParametricVolumePrivate;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldParametricVolume : public axlAbstractFieldParametricVolume
{
    Q_OBJECT

public:
    axlFieldParametricVolume();
    virtual ~axlFieldParametricVolume(void);

//    void setType(Type type);
//    void setKind(Kind kind);
//    void setSupport(Support support);

    void setFunction(axlAbstractData *data);
    axlAbstractData *getFunction(void);
    void setVolume(axlAbstractData *data);

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

//    Type type(void);
//    Kind kind(void);
//    Support support(void);

    virtual double  scalar(double u, double v  , double w );
    virtual double *vector(double u, double v  , double w );
    virtual double *tensor(double u, double v  , double w );

    virtual QString description(void) const;
    virtual QString identifier(void) const;
//    virtual QString name(void);
//    virtual void setName(QString name);

signals :
    void updated(void);


public slots:
    virtual void update(void);


private:
    axlFieldParametricVolumePrivate *d;
};

AXLCORE_EXPORT dtkAbstractData *createaxlFieldParametricVolume(void);


#endif  // AXLFIELDPARAMETRICVOLUME_H
