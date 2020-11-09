/* axlFieldDiscrete.h ---
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

#ifndef AXLFIELDDISCRETE_H
#define AXLFIELDDISCRETE_H

#include "axlCoreExport.h"



#include <axlCore/axlAbstractFieldDiscrete.h>

class axlFieldDiscretePrivate;

class AXLCORE_EXPORT axlFieldDiscrete : public axlAbstractFieldDiscrete
{
    Q_OBJECT

public:
    axlFieldDiscrete();
    axlFieldDiscrete(QString name, Type type, Kind kind, Support support, int size);
    //axlFieldDiscrete(void *array);
    virtual ~axlFieldDiscrete(void);

    static bool registered(void);

    //    virtual void setType(Type type);
    //    virtual void setKind(Kind kind);
    //    virtual void setSupport(Support support);

    virtual void setScalar(int index, double v1);
    virtual void setVector(int index, double v1, double v2, double v3);
    virtual void setTensor(int index, double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9);

    virtual int size(void);
    virtual void setSize(int size);

    virtual double  scalar(int index);
    virtual double *vector(int index);
    virtual double *tensor(int index);

    QString description(void) const;
    QString identifier(void) const;

signals :
    void updated(void);

public slots:
    virtual void update(void);

private:
    axlFieldDiscretePrivate *d;
};

dtkAbstractData *createaxlFieldDiscrete(void);


#endif // AXLFIELDDISCRETE_H
