/* axlPlaneParametric.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Tue Jul 23 16:58:59 2013 (+0100)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLPLANEPARAMETRIC_H
#define AXLPLANEPARAMETRIC_H

#include "axlCoreExport.h"
#include "axlAbstractSurfaceParametric.h"

#include <QtCore>

class axlPoint;
class axlPlane;
class axlPlaneParametricPrivate;

class AXLCORE_EXPORT axlPlaneParametric : public axlAbstractSurfaceParametric {
    Q_OBJECT

public:
    axlPlaneParametric(axlAbstractSurfaceParametric* parent = 0);
    axlPlaneParametric(axlPlane *plane, axlPoint* i);
    axlPlaneParametric(const axlPlane& plane, const axlPoint& i);
    axlPlaneParametric(const axlPlaneParametric& other);
    virtual ~axlPlaneParametric(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    void setPlane(const axlPlane& plane);
    void setI(axlPoint* i);
    void setJ(axlPoint* j);

    axlPlaneParametric& operator=(const axlPlaneParametric& other);

    void modifyI(double* i);
    void modifyJ(double* j);

    axlPlane* getPlane(void) const;
    axlPoint* getI(void) const;
    axlPoint* getJ(void) const;

    virtual axlPoint eval(double u, double v);
    virtual void eval(axlPoint* point, double u, double v);
    virtual void eval(double& x, double& y, double& z, double u, double v);

    virtual void normal(axlPoint *normal, double, double);

    virtual void parameterOf(const axlPoint& point, double& u, double& v);

public slots:
    void onPlaneChanged(axlPlane* plane);
    void onIChanged(axlPoint* i);
    void onJChanged(axlPoint* j);

private:
    axlPlaneParametricPrivate* d;
};

#endif // AXLPLANEPARAMETRIC_H
