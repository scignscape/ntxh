/* axlPlane.h ---
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

#ifndef AXLPLANE_H
#define AXLPLANE_H

#include "axlCoreExport.h"

#include "axlAbstractData.h"

//? added ...
#include "axlPoint.h"


#include <QtCore>

class axlPoint;

class axlPlanePrivate;

class AXLCORE_EXPORT axlPlane : public axlAbstractData
{
    Q_OBJECT
    Q_PROPERTY(axlPoint point READ point WRITE touchPoint);
    Q_PROPERTY(axlPoint normal READ normal WRITE touchNormal);

public:
    axlPlane(QObject *parent = 0);
    axlPlane(axlPoint *point, axlPoint *normal, QObject *parent = 0);
    axlPlane(const axlPoint& point, const axlPoint& normal, QObject *parent = 0);
    axlPlane(const axlPlane& other);
    ~axlPlane(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    axlPoint *point(void) const;
    axlPoint *normal(void) const;

    void setValues(axlPoint *point, axlPoint *normal);

    void setPoint(axlPoint *point);
    void setPoint(double *p);

    void setNormal(axlPoint *normal);
    void setNormal(double *normal);

    void touchPoint(axlPoint point);
    void touchNormal(axlPoint normal);

    axlPlane& operator =(const axlPlane& other);

    friend QDebug operator<<(QDebug dbg, axlPlane  plane);
    friend QDebug operator<<(QDebug dbg, axlPlane& plane);
    friend QDebug operator<<(QDebug dbg, axlPlane *plane);

    //IPC
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

//public slots:
    //void onPointChanged(axlPoint *point);
    //void onNormalChanged(axlPoint *normal);

private:
    axlPlanePrivate *d;
};
Q_DECLARE_METATYPE(axlPlane)

//to be registered to the data factory.
dtkAbstractData *createaxlPlane(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlPlane  point);
QDebug operator<<(QDebug dbg, axlPlane& point);
QDebug operator<<(QDebug dbg, axlPlane *point);

#endif // AXLPLANE_H
