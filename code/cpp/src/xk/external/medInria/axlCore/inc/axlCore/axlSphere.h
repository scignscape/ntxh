/* axlSphere.h ---
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
 * There is choice table for stock coordinate. But maybe that is nos the good solution if algorithm behin use a lot of sphere.
 * In this case, we have to create three double directly instead of table
 */

/* Change log:
 *
 */

#ifndef AXLSPHERE_H
#define AXLSPHERE_H

#include "axlCoreExport.h"

#include "axlAbstractData.h"
#include "axlPoint.h"

#include <QtCore>

class axlSpherePrivate;

class AXLCORE_EXPORT axlSphere : public axlAbstractData
{
    Q_OBJECT
    Q_PROPERTY(double radius READ radius WRITE touchRadius);
    Q_PROPERTY(axlPoint center READ centerPoint WRITE touchCenter);

public:
     axlSphere(QObject *parent = 0);
     axlSphere(double x, double y, double z=0, double radius = 1.0, QObject *parent = 0);
     axlSphere(const axlSphere& other);
    ~axlSphere(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    double x(void) const;
    double y(void) const;
    double z(void) const;
    double *coordinates(void) const;
    double radius(void) const;
    void setRadius(double radius);
    void touchRadius(double radius);
    void touchCenter(axlPoint center);
    axlPoint centerPoint(void);

    void setValues(double x, double y, double z, double radius);
    void setCenter(double x, double y, double z);

    void normalize();

    axlSphere& operator =(const axlSphere& other);
    axlSphere& operator+=(const axlSphere& other);
    axlSphere& operator-=(const axlSphere& other);
    axlSphere& operator*=(double scalar);
    axlSphere& operator/=(double scalar);

    axlSphere operator+(const axlSphere& other) const;
    axlSphere operator-(const axlSphere& other) const;
    axlSphere operator*(double scalar) const;
    axlSphere operator/(double scalar) const;

    friend QDebug operator<<(QDebug dbg, axlSphere  sphere);
    friend QDebug operator<<(QDebug dbg, axlSphere& sphere);
    friend QDebug operator<<(QDebug dbg, axlSphere *sphere);

    //IPC
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

    //void emitDataChanged(void);

//signals :
//    void dataChanged(void);

public slots:
    void onXChanged(double x);
    void onYChanged(double y);
    void onZChanged(double z);
    void onRadiusChanged(double radius);

public:
    static double distance(const axlSphere& lhs, const axlSphere& rhs);
    static double distance(      axlSphere *lhs,       axlSphere *rhs);


private:
    axlSpherePrivate *d;
};
Q_DECLARE_METATYPE(axlSphere)

//to be registered to the data factory.
dtkAbstractData *createaxlSphere(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlSphere  sphere);
QDebug operator<<(QDebug dbg, axlSphere& sphere);
QDebug operator<<(QDebug dbg, axlSphere *sphere);

#endif // AXLSPHERE_H
