/* axlCylinderParametric.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Fri Jul 26 16:58:59 2013 (+0100)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLCYLINDERPARAMETRIC_H
#define AXLCYLINDERPARAMETRIC_H

#include "axlCoreExport.h"
#include "axlAbstractSurfaceParametric.h"

#include <QtCore>

class axlPoint;
class axlCylinder;
class axlCylinderParametricPrivate;

class AXLCORE_EXPORT axlCylinderParametric : public axlAbstractSurfaceParametric {
    Q_OBJECT

public:
    axlCylinderParametric(axlAbstractSurfaceParametric* parent = 0);
    axlCylinderParametric(axlCylinder* cylinder, axlPoint* r);
    axlCylinderParametric(const axlCylinder& cylinder, const axlPoint& r);
    axlCylinderParametric(const axlCylinderParametric& other);
    virtual ~axlCylinderParametric(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    void setCylinder(axlCylinder* cylinder);
    axlPoint* getR(void) const;
    void setR(axlPoint* r);

    axlCylinderParametric& operator=(const axlCylinderParametric& other);

    void modifyR(double* r);

    axlCylinder* getCylinder(void) const;
    void setCylinder(const axlCylinder& cylinder);

    virtual axlPoint eval(double u, double v);
    virtual void eval(axlPoint *point, double u,double v);
    virtual void eval(double& x, double& y, double& z, double u,double v);

//    virtual void normal(axlPoint *normal, double, double);

    virtual void parameterOf(const axlPoint& point, double& um, double& vm);

public slots:
    void onCylinderChanged(axlCylinder* cylinder);
    void onRChanged(axlPoint* r);

private:
    axlCylinderParametricPrivate* d;
};

#endif // AXLCYLINDERPARAMETRIC_H
