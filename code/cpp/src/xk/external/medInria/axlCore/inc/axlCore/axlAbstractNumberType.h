/* axlAbstractNumberType.h ---
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

#ifndef AXLABSTRACTNUMBERTYPE_H
#define AXLABSTRACTNUMBERTYPE_H

#include "axlCoreExport.h"

#include "axlAbstractData.h"

#include <QtCore>

class axlPoint;

class axlAbstractNumberTypePrivate;

class AXLCORE_EXPORT axlAbstractNumberType : public axlAbstractData
{
    Q_OBJECT
public:
    enum Type {Int,Float,Double};


public:
    axlAbstractNumberType(QObject *parent = 0);
    ~axlAbstractNumberType(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    double value(void) const;

public slots :
    void setValue(double newValue);

public :
    axlAbstractNumberType& operator =(const axlAbstractNumberType& other);


    friend QDebug operator<<(QDebug dbg, axlAbstractNumberType  line);
    friend QDebug operator<<(QDebug dbg, axlAbstractNumberType& line);
    friend QDebug operator<<(QDebug dbg, axlAbstractNumberType *line);

    QString objectType(void) const;

private:
    axlAbstractNumberTypePrivate *d;
};

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlAbstractNumberType  point);
QDebug operator<<(QDebug dbg, axlAbstractNumberType& point);
QDebug operator<<(QDebug dbg, axlAbstractNumberType *point);

#endif// AXLABSTRACTNUMBERTYPE_H
