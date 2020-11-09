/* axlEllipsoid.h ---
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

#ifndef AXLELLIPSOID_H
#define AXLELLIPSOID_H

#include "axlCoreExport.h"
#include "axlAbstractData.h"

//? added ...
#include "axlPoint.h"


#include "dtkMathSupport/dtkQuaternion.h"

#include <QtCore>

class axlPoint;

class axlEllipsoidPrivate;

class AXLCORE_EXPORT axlEllipsoid : public axlAbstractData
{
    Q_OBJECT
    Q_PROPERTY(axlPoint center READ center WRITE touchCenter);
    Q_PROPERTY(axlPoint semiX READ semiX WRITE touchSemiX);
    Q_PROPERTY(axlPoint semiY READ semiY WRITE touchSemiY);
    Q_PROPERTY(axlPoint semiZ READ semiZ WRITE touchSemiZ);

public:
    axlEllipsoid(QObject *parent = 0);
    axlEllipsoid(axlPoint *center, axlPoint *semiX, axlPoint *semiY, axlPoint *semiZ, QObject *parent = 0);
    axlEllipsoid(const axlPoint& center, const axlPoint& semiX, const axlPoint& semiY, const axlPoint& semiZ, QObject *parent = 0);
    axlEllipsoid(const axlEllipsoid& other);
    ~axlEllipsoid(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    axlPoint *center(void) const;
    axlPoint *semiX(void) const;
    axlPoint *semiY(void) const;
    axlPoint *semiZ(void) const;

    void setValues(axlPoint *center, axlPoint *semiX, axlPoint *semiY, axlPoint *semiZ);
    void setCenter(axlPoint *center);
    void setSemiX(axlPoint *semiX);
    void setSemiY(axlPoint *semiY);
    void setSemiZ(axlPoint *semiZ);

    void touchCenter(axlPoint center);
    void touchSemiX(axlPoint semiX);
    void touchSemiY(axlPoint semiY);
    void touchSemiZ(axlPoint semiZ);

    void modifyCenter(double *center);
    void modifyCenterX(double x);
    void modifyCenterY(double y);
    void modifyCenterZ(double z);

    void modifySemiX(double *semiX);
    void modifySemiXX(double x);
    void modifySemiXY(double y);
    void modifySemiXZ(double z);

    void modifySemiY(double *semiY);
    void modifySemiYX(double x);
    void modifySemiYY(double y);
    void modifySemiYZ(double z);

    void modifySemiZ(double *semiZ);
    void modifySemiZX(double x);
    void modifySemiZY(double y);
    void modifySemiZZ(double z);

    axlEllipsoid& operator =(const axlEllipsoid& other);

    friend QDebug operator<<(QDebug dbg, axlEllipsoid  line);
    friend QDebug operator<<(QDebug dbg, axlEllipsoid& line);
    friend QDebug operator<<(QDebug dbg, axlEllipsoid *line);

    //IPC
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

public slots:
    void onCenterChanged(axlPoint *center);
    void onSemiXChanged(axlPoint *semiX);
    void onSemiYChanged(axlPoint *semiY);
    void onSemiZChanged(axlPoint *semiZ);
    void calculateYZ(void);
    void calculateXZ(void);
    void calculateXY(void);

private:
    axlEllipsoidPrivate *d;
};
Q_DECLARE_METATYPE(axlEllipsoid)

dtkAbstractData *createaxlEllipsoid(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlEllipsoid  point);
QDebug operator<<(QDebug dbg, axlEllipsoid& point);
QDebug operator<<(QDebug dbg, axlEllipsoid *point);

#endif // AXLELLIPSOID_H
