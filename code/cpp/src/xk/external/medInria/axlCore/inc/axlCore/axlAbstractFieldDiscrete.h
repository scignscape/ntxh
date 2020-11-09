/* axlAbstractFieldDiscrete.h ---
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

#ifndef AXLABSTRACTFIELDDISCRETE_H
#define AXLABSTRACTFIELDDISCRETE_H

#include "axlCoreExport.h"
#include "axlAbstractField.h"
#include <QtCore>

class axlAbstractFieldDiscretePrivate;

class AXLCORE_EXPORT axlAbstractFieldDiscrete : public axlAbstractField
{
    Q_OBJECT

public:
    axlAbstractFieldDiscrete();
    axlAbstractFieldDiscrete(QString name, Type type, Kind kind, Support support, int size);
    axlAbstractFieldDiscrete(void *array);
    virtual ~axlAbstractFieldDiscrete(void);

    //    virtual void setType(Type type);
    //    virtual void setKind(Kind kind);
    //    virtual void setSupport(Support support);

    virtual void setScalar(int index, double v1);
    virtual void setVector(int index, double v1, double v2, double v3);
    virtual void setTensor(int index, double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9);


    //    virtual Type type(void);
    //    virtual Kind kind(void);
    //    virtual Support support(void);
    virtual int size(void);
    virtual void setSize(int size);

    virtual double  scalar(int index);
    virtual double *vector(int index);
    virtual double *tensor(int index);

    //    virtual QString name(void);
    //    virtual void setName(QString name);

signals:
    void updated(void);


public slots:
    virtual void update(void);

//public:
//    virtual void *array(void);

    //public :
    //    QString objectType(void);

private:
    axlAbstractFieldDiscretePrivate *d;
};



#endif // AXLABSTRACTFIELDDISCRETE_H
