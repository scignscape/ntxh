/* axlCircleArc.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008 - Valentin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:46:18 2010 (+0100)
 *           By: Valentin Michelet
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLCIRCLEARC_H
#define AXLCIRCLEARC_H

#include "axlCoreExport.h"
#include "axlAbstractCurveParametric.h"

#include <QtCore>

class axlPoint;

class axlCircleArcPrivate;

class AXLCORE_EXPORT axlCircleArc : public axlAbstractCurveParametric {
    Q_OBJECT

public:
    axlCircleArc(QObject* parent = 0);
    axlCircleArc(const axlPoint& point1, const axlPoint& point2, const axlPoint& center, const axlPoint& normal, bool direct = true);
    axlCircleArc(const axlCircleArc& other);
    virtual ~axlCircleArc(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    double calculateRadius(void) const;
    axlPoint calculateNormal(void) const;

    axlPoint point1(void) const;
    axlPoint point2(void) const;
    axlPoint center(void) const;
    axlPoint normal(void) const;
    bool isDirect(void) const;

    void setValues(const axlPoint& point1, const axlPoint& point2, const axlPoint& center, const axlPoint &normal, bool direct = true);
    void setPoint1(const axlPoint& point1);
    void setPoint2(const axlPoint& point2);
    void setNormal(const axlPoint& normal);
    void setCenter(const axlPoint& center);
    void setDirect(bool direct);

    void modifyPoint1(double* point1);
    void modifyPoint2(double* point2);
    void modifyNormal(double* normal);
    void modifyCenter(double* center);

    axlCircleArc& operator=(const axlCircleArc& other);

    friend QDebug operator<<(QDebug dbg, axlCircleArc  arc);
    friend QDebug operator<<(QDebug dbg, axlCircleArc& arc);
    friend QDebug operator<<(QDebug dbg, axlCircleArc* arc);

    void applyMatrix(double* matrix);

    //IPC
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);



public slots:
    void onPoint1XChanged(double x);
    void onPoint1YChanged(double y);
    void onPoint1ZChanged(double z);
    void onPoint2XChanged(double x);
    void onPoint2YChanged(double y);
    void onPoint2ZChanged(double z);
    void onCenterXChanged(double x);
    void onCenterYChanged(double y);
    void onCenterZChanged(double z);
    void onNormalXChanged(double x);
    void onNormalYChanged(double y);
    void onNormalZChanged(double z);
    virtual void onDirectChanged(bool direct);

private:
    axlCircleArcPrivate* d;
};

//to be registered to the data factory.
dtkAbstractData *createaxlCircleArc(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlCircleArc  point);
QDebug operator<<(QDebug dbg, axlCircleArc& point);
QDebug operator<<(QDebug dbg, axlCircleArc* point);

#endif // AXLCIRCLEARC_H
