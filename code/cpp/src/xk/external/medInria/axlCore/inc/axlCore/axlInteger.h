/* axlInteger.h ---
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

#ifndef AXLINTEGER_H
#define AXLINTEGER_H

#include "axlCoreExport.h"

#include "axlAbstractData.h"

#include <QtCore>

class axlPoint;

class axlIntegerPrivate;

class AXLCORE_EXPORT axlInteger : public axlAbstractData
{
    Q_OBJECT

public:
    axlInteger(QObject *parent = 0);
    axlInteger(int value, QObject *parent = 0);
    axlInteger(const axlInteger& other);
    ~axlInteger(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    int value(void) const;

    /*!
     * Convert an axlInteger into a QVariantList. Useful for RPC protocol.
     */
    QVariantList convertDataToQVariant(void) const;
    /*!
     * Convert a QVariantList into an axlInteger. Useful for RPC protocol.
     */
    int convertQVariantToData(const QVariantList &data);

public slots :
    void setValue(int newValue);

public :
    axlInteger& operator =(const axlInteger& other);


    friend QDebug operator<<(QDebug dbg, axlInteger  line);
    friend QDebug operator<<(QDebug dbg, axlInteger& line);
    friend QDebug operator<<(QDebug dbg, axlInteger *line);



private:
    axlIntegerPrivate *d;
};

dtkAbstractData *createaxlInteger(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlInteger  point);
QDebug operator<<(QDebug dbg, axlInteger& point);
QDebug operator<<(QDebug dbg, axlInteger *point);

#endif // AXLINTEGER_H
