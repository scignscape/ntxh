/* axlLine.h ---
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

#ifndef AXLLINE_H
#define AXLLINE_H

#include "axlCoreExport.h"

#include "axlAbstractCurveParametric.h"
//#include "axlPoint.h"

#include <QtCore>

class axlPoint;

class axlLinePrivate;

class AXLCORE_EXPORT axlLine : public axlAbstractCurveParametric
{
    Q_OBJECT

    Q_PROPERTY(axlPoint point1 READ firstPoint WRITE touchFirstPoint);
    Q_PROPERTY(axlPoint point2 READ secondPoint WRITE touchSecondPoint);

public:
    axlLine(QObject *parent = 0);
    axlLine(axlPoint *p1, axlPoint *p2, QObject *parent = 0);
    axlLine(const axlPoint& p1, const axlPoint& p2, QObject* parent = 0);
    axlLine(const axlLine& other);
    ~axlLine(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    axlPoint *firstPoint(void) const;
    axlPoint *secondPoint(void) const;
    axlPoint *getBarycenterPoint(double coeff);
    axlPoint *getMiddlePoint(void);

    void setFirstPoint(axlPoint *p1);
    void setFirstPoint(double *p1);
    void touchFirstPoint(const axlPoint &point);
    void touchSecondPoint(const axlPoint &point);
    void setSecondPoint(axlPoint *p2);
    void setSecondPoint(double *p2);

    void setValues(axlPoint *p1, axlPoint *p2);

    void applyMatrix(double* matrix);

    double planeDirection(void);
    double planeOrigineOrdinate(void);

    axlLine& operator =(const axlLine& other);


    friend QDebug operator<<(QDebug dbg, axlLine  line);
    friend QDebug operator<<(QDebug dbg, axlLine& line);
    friend QDebug operator<<(QDebug dbg, axlLine *line);

    //IPC
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

//public slots:
    void onFirstPointChanged(axlPoint *p1);
    void onSecondPointChanged(axlPoint *p2);


private:
    axlLinePrivate *d;
};
Q_DECLARE_METATYPE(axlLine)

//to be registered to the data factory.
dtkAbstractData *createaxlLine(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlLine  point);
QDebug operator<<(QDebug dbg, axlLine& point);
QDebug operator<<(QDebug dbg, axlLine *point);

#endif // AXLLINE_H
