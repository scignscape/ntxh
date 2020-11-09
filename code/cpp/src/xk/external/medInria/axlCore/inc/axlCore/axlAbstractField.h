/* axlAbstractField.h ---
 *
 * Author: Thibaud Kloczko
 * Copyright (C) 2008 - Thibaud Kloczko, Inria.
 * Created: Wed Jul 28 11:21:06 2010 (+0200)
 * Version: $Id$
 * Last-Updated: Fri Feb  4 21:54:24 2011 (+0100)
 *           By: Regis Duvigneau
 *     Update #: 142
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTFIELD_H
#define AXLABSTRACTFIELD_H

#include "axlCoreExport.h"
#include "axlAbstractData.h"
#include <QtCore>

class axlAbstractFieldPrivate;

class AXLCORE_EXPORT axlAbstractField : public axlAbstractData
{
    Q_OBJECT

public:
    enum Type {
        Int = 0x001,
        Float = 0x002,
        Double = 0x004
    };

    enum Kind {
        Scalar = 0x001,
        Vector = 0x002,
        Tensor = 0x004
    };

    enum Support {
        Point = 0x001,
        Cell = 0x002,
        Custom = 0x004
    };

public:
    axlAbstractField();
    axlAbstractField(QString name, Type type, Kind kind, Support support);
    virtual ~axlAbstractField(void);

    virtual void setType(Type type);
    virtual void setKind(Kind kind);
    virtual void setSupport(Support support);

//    virtual void setScalar(int index, double v1);
//    virtual void setVector(int index, double v1, double v2, double v3);
//    virtual void setTensor(int index, double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9);


    virtual Type type(void);
    virtual Kind kind(void);
    virtual Support support(void);
//    virtual int size(void);
//    virtual void setSize(int size);

//    virtual double  scalar(int index);
//    virtual double *vector(int index);
//    virtual double *tensor(int index);

    virtual void setMin(double mini);
    virtual double minValue(void);
    virtual void setMax(double maxi);
    virtual double maxValue(void);

//    virtual QString name(void);
//    virtual void setName(QString name);
    virtual QString identifier(void) const;

signals:
    void updated(void);


public slots:
    virtual void update(void);

//public:
//    virtual void *array(void);

private:
    axlAbstractFieldPrivate *d;
};



#endif //axlAbstractField_H
