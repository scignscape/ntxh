/* axlCylinder.h ---
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

#ifndef AXLCYLINDER_H
#define AXLCYLINDER_H

#include "axlCoreExport.h"
#include "axlAbstractData.h"

//? added ...
#include "axlPoint.h"

#include <QtCore>

class axlPoint;

class axlCylinderPrivate;

class AXLCORE_EXPORT axlCylinder : public axlAbstractData
{
    Q_OBJECT
    Q_PROPERTY(axlPoint point1 READ firstPoint WRITE touchFirstPoint);
    Q_PROPERTY(axlPoint point2 READ secondPoint WRITE touchSecondPoint);
    Q_PROPERTY(double radius READ radius WRITE touchRadius);

public:
    axlCylinder(QObject *parent = 0);
    axlCylinder(axlPoint *p1, axlPoint *p2, double radius, QObject *parent = 0);
    axlCylinder(const axlPoint& p1, const axlPoint& p2, double radius, QObject *parent = 0);
    axlCylinder(const axlCylinder& other);
    ~axlCylinder(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    axlPoint *firstPoint(void) const;
    axlPoint *secondPoint(void) const;
    double    radius(void) const;
    double    length(void) const;

    void setValues(axlPoint *p1, axlPoint *p2, double radius);
    void setFirstPoint(axlPoint *p1);
    void setSecondPoint(axlPoint *p2);
    void setRadius(double radius);
    void setLength(double length);
    void setFirstPoint(double *p1);
    void setSecondPoint(double *p2);

    void touchFirstPoint(axlPoint p1);
    void touchSecondPoint(axlPoint p2);
    void touchRadius(double radius);

    axlCylinder& operator =(const axlCylinder& other);

    friend QDebug operator<<(QDebug dbg, axlCylinder  line);
    friend QDebug operator<<(QDebug dbg, axlCylinder& line);
    friend QDebug operator<<(QDebug dbg, axlCylinder *line);

    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

public slots:
    void onFirstPointChanged(axlPoint *p1);
    void onSecondPointChanged(axlPoint *p2);
    void onRadiusChanged(double radius);

private:
    axlCylinderPrivate *d;
};
Q_DECLARE_METATYPE(axlCylinder)

//to be registered to the data factory.
dtkAbstractData *createaxlCylinder(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlCylinder  point);
QDebug operator<<(QDebug dbg, axlCylinder& point);
QDebug operator<<(QDebug dbg, axlCylinder *point);


#endif // AXLCYLINDER_H
