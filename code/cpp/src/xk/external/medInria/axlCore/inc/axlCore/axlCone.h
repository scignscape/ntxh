/* axlCone.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:46:18 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 21
 */

/* Commentary:
 * There is choice table for stock coordinate. But maybe that is nos the good solution if algorithm behin use a lot of point.
 * In this case, we have to create three double directly instead of table
 */

/* Change log:
 *
 */

#ifndef AXLCONE_H
#define AXLCONE_H

#include "axlCoreExport.h"

#include "axlAbstractData.h"

//? added ...
#include "axlPoint.h"

#include <QtCore>

class axlPoint;

class axlConePrivate;

class AXLCORE_EXPORT axlCone : public axlAbstractData
{
    Q_OBJECT
    Q_PROPERTY(axlPoint apex READ apex WRITE touchApex);
    Q_PROPERTY(axlPoint basePoint READ basePoint WRITE touchBasePoint);
    Q_PROPERTY(double radius READ radius WRITE touchRadius);

public:
    axlCone(QObject *parent = 0);
    axlCone(axlPoint *apex, axlPoint *basePoint, double radius, QObject *parent = 0);
    axlCone(const axlPoint& apex, const axlPoint& basePoint, double radius, QObject *parent = 0);
    axlCone(const axlCone& other);
    ~axlCone(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    axlPoint *apex(void) const;
    axlPoint *basePoint(void) const;
    double radius(void) const;
    double length(void) const;

    void setValues(axlPoint *apex, axlPoint *basePoint, double radius);
    void setApex(axlPoint *apex);
    void setApex(double *apex);
    void setBasePoint(axlPoint *basePoint);
    void setBasePoint(double *basePoint);

    void setRadius(double radius);
    void setLength(double length);

    void touchApex(axlPoint apex);
    void touchBasePoint(axlPoint basePoint);
    void touchRadius(double radius);

//    void modifyApex(double *apex);
//    void modifyBasePoint(double *basePoint);

    axlCone& operator =(const axlCone& other);

    friend QDebug operator<<(QDebug dbg, axlCone  line);
    friend QDebug operator<<(QDebug dbg, axlCone& line);
    friend QDebug operator<<(QDebug dbg, axlCone *line);

    //IPC
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

signals:
    void dataChanged(void);

public slots:
    void onApexChanged(axlPoint *apex);
    void onBasePointChanged(axlPoint *basePoint);
    void onRadiusChanged(double radius);

 private:
    axlConePrivate *d;
};
Q_DECLARE_METATYPE(axlCone);

//to be registered to the data factory.
dtkAbstractData *createaxlCone(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlCone  point);
QDebug operator<<(QDebug dbg, axlCone& point);
QDebug operator<<(QDebug dbg, axlCone *point);

#endif // AXLCONE_H
