/* axlTorus.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2012 - Valentin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2012 (+0100)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLTORUS_H
#define AXLTORUS_H

#include "axlCoreExport.h"
#include "axlAbstractData.h"

#include <QtCore>

//? added ...
#include "axlPoint.h"


class axlPoint;
class axlTorusPrivate;

class AXLCORE_EXPORT axlTorus : public axlAbstractData {
    Q_OBJECT
    Q_PROPERTY(axlPoint centerPoint READ centerPoint WRITE touchCenterPoint);
    Q_PROPERTY(axlPoint direction READ direction WRITE touchDirection);
    Q_PROPERTY(double ringRadius READ ringRadius WRITE touchRingRadius);
    Q_PROPERTY(double crossSectionRadius READ crossSectionRadius WRITE touchCrossSectionRadius);

public:
    axlTorus(QObject* parent = 0);
    axlTorus(axlPoint* center, axlPoint* direction, double ringRadius, double crossSectionRadius);
    axlTorus(const axlPoint& center, const axlPoint& direction, double ringRadius, double crossSectionRadius);
    axlTorus(const axlTorus& other);
    virtual ~axlTorus(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    axlPoint* centerPoint(void) const;
    axlPoint* direction(void) const;
    double ringRadius(void) const;
    double crossSectionRadius(void) const;

    void setValues(axlPoint* center, axlPoint* direction, double ringRadius, double crossSectionRadius);

    void setCenter(axlPoint* center);
    void setCenter(double* center);

    void setDirection(axlPoint* direction);
    void setDirection(double* direction);

    void setRingRadius(double ringRadius);
    void setCrossSectionRadius(double crossSectionRadius);

    void touchCenterPoint(axlPoint center);
    void touchDirection(axlPoint direction);
    void touchRingRadius(double ringRadius);
    void touchCrossSectionRadius(double crossSectionRadius);

    axlTorus& operator=(const axlTorus& other);

    friend QDebug operator<<(QDebug dbg, axlTorus  torus);
    friend QDebug operator<<(QDebug dbg, axlTorus& torus);
    friend QDebug operator<<(QDebug dbg, axlTorus* torus);

    //IPC
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

public slots:
    void onCenterChanged(axlPoint* center);
    void onDirectionChanged(axlPoint* direction);
    void onRingRadiusChanged(double ringRadius);
    void onCrossSectionRadiusChanged(double crossSectionRadius);

private:
    axlTorusPrivate* d;
};
Q_DECLARE_METATYPE(axlTorus)

//to be registered to the data factory.
dtkAbstractData *createaxlTorus(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlTorus  point);
QDebug operator<<(QDebug dbg, axlTorus& point);
QDebug operator<<(QDebug dbg, axlTorus* point);

#endif // AXLTORUS_H
