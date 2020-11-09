/* axlAbstractFieldSpatial.h ---
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
#ifndef AXLABSTRACTFIELDSPATIAL_H
#define AXLABSTRACTFIELDSPATIAL_H

#include <axlCore/axlAbstractField.h>

class axlAbstractFieldSpatialPrivate;

class AXLCORE_EXPORT axlAbstractFieldSpatial : public axlAbstractField
{
    Q_OBJECT

public:
    axlAbstractFieldSpatial();
    virtual ~axlAbstractFieldSpatial(void);

//    void setType(Type type);
//    void setKind(Kind kind);
//    void setSupport(Support support);

//    Type type(void);
//    Kind kind(void);
//    Support support(void);

    virtual double  scalar(double x, double y  = 0, double z = 0);
    virtual double *vector(double x, double y  = 0, double z = 0);
    virtual double *tensor(double x, double y  = 0, double z = 0);

    virtual QString description(void) const;
    virtual QString identifier(void) const;
//    virtual QString name(void);
//    virtual void setName(QString name);



signals :
    void updated(void);


public slots:
    virtual void update(void);


private:
    axlAbstractFieldSpatialPrivate *d;
};

dtkAbstractData *createaxlAbstractFieldSpatial(void);


#endif // AXLABSTRACTFIELDSPATIAL_H
