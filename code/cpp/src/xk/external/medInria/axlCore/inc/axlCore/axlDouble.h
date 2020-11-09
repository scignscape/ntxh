/* axlDouble.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLDOUBLE_H
#define AXLDOUBLE_H

#include "axlCoreExport.h"

#include "axlAbstractData.h"
//#include "axlAbstractNumberType.h"

#include <QtCore>

class axlPoint;

class axlDoublePrivate;

class AXLCORE_EXPORT axlDouble : public axlAbstractData
{
    Q_OBJECT

public:
    axlDouble(QObject *parent = 0);
    axlDouble(double value, QObject *parent = 0);
    axlDouble(const axlDouble& other);
    ~axlDouble(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    double value(void) const;
    /*!
     * Convert an axlDouble into a QVariantList. Useful for RPC protocol.
     */
    QVariantList convertDataToQVariant(void) const;
    /*!
     * Convert a QVariantList into an axlDouble. Useful for RPC protocol.
     */
    int convertQVariantToData(const QVariantList &data);


public slots :
    void setValue(double newValue);

public :
    axlDouble& operator =(const axlDouble& other);


    friend QDebug operator<<(QDebug dbg, axlDouble  line);
    friend QDebug operator<<(QDebug dbg, axlDouble& line);
    friend QDebug operator<<(QDebug dbg, axlDouble *line);



private:
    axlDoublePrivate *d;
};

dtkAbstractData *createaxlDouble(void);
// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlDouble  point);
QDebug operator<<(QDebug dbg, axlDouble& point);
QDebug operator<<(QDebug dbg, axlDouble *point);

#endif // AXLDOUBLE_H
