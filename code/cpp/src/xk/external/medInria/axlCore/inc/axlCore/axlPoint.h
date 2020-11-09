/* axlPoint.h ---
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

#ifndef AXLPOINT_H
#define AXLPOINT_H

#include "axlCoreExport.h"

#include "axlAbstractData.h"

#include <QtCore>
#include <QObject>
#include <QMetaType>

class axlPointPrivate;

class AXLCORE_EXPORT axlPoint : public axlAbstractData
{
    Q_OBJECT
    Q_PROPERTY(double x READ x WRITE touchX);
    Q_PROPERTY(double y READ y WRITE touchY);
    Q_PROPERTY(double z READ z WRITE touchZ);

public:
    axlPoint(QObject *parent = 0);
    axlPoint(double x, double y, double z=0, QObject *parent = 0);
    axlPoint(const axlPoint& other);
    axlPoint(const axlPoint *other);
    axlPoint(double *p, QObject *parent = 0);

    ~axlPoint(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;


    double x(void) const;
    double y(void) const;
    double z(void) const;
    double operator [] (int i) const;

    double& x(void);
    double& y(void);
    double& z(void);
    double& operator [] (int i);

    double *coordinates(void) const;

    double norm(void) const;

    void setCoordinates(double x, double y, double z);
    //void updateCoordinates(double x, double y, double z);

    void touchX(double x);
    void touchY(double y);
    void touchZ(double z);

    void normalize(void);
    axlPoint& normalized(void);

    bool isEqualTo(axlPoint *point);

    axlPoint& operator =(const axlPoint& other);
    axlPoint& operator+=(const axlPoint& other);
    axlPoint& operator-=(const axlPoint& other);
    double    operator* (const axlPoint& other) const;
    axlPoint& operator*=(double scalar);
    axlPoint& operator/=(double scalar);

    axlPoint operator+(const axlPoint& other) const;
    axlPoint operator-(const axlPoint& other) const;
    axlPoint operator*(double scalar) const;
    axlPoint operator/(double scalar) const;

    void transformAsPoint(double matrix[12]);
    void transformAsVector(double matrix[12]);

    bool operator<(const axlPoint& other) const;

    bool operator==(const axlPoint& point2) const;
    bool operator!=(const axlPoint& point2) const;

    friend QDebug operator<<(QDebug dbg, axlPoint  point);
    friend QDebug operator<<(QDebug dbg, axlPoint& point);
    friend QDebug operator<<(QDebug dbg, axlPoint *point);

    //converter method for qjson-rpc communication.
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

//public slots:
//    void onXChanged(double x);
//    void onYChanged(double y);
//    void onZChanged(double z);

public:
    static double distance(const axlPoint& lhs, const axlPoint& rhs);
    static double distance(      axlPoint *lhs,       axlPoint *rhs);

    static axlPoint  crossProduct(const axlPoint& lhs, const axlPoint& rhs);
    static axlPoint* crossProduct(      axlPoint *lhs,       axlPoint *rhs);

    static double dotProduct(const axlPoint& lhs, const axlPoint& rhs);
    static double dotProduct(      axlPoint *lhs,       axlPoint *rhs);


private:
    axlPointPrivate *d;
};
Q_DECLARE_METATYPE(axlPoint);

dtkAbstractData *createaxlPoint(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlPoint  point);
QDebug operator<<(QDebug dbg, axlPoint& point);
QDebug operator<<(QDebug dbg, axlPoint *point);
#endif // AXLPOINT_H
