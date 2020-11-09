/* axlTorusParametric.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Tue Jul 30 16:58:59 2013 (+0100)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLTORUSPARAMETRIC_H
#define AXLTORUSPARAMETRIC_H

#include "axlCoreExport.h"
#include "axlAbstractSurfaceParametric.h"

#include <QtCore>

class axlPoint;
class axlTorus;
class axlTorusParametricPrivate;

class AXLCORE_EXPORT axlTorusParametric : public axlAbstractSurfaceParametric {
    Q_OBJECT

public:
    axlTorusParametric(axlAbstractSurfaceParametric* parent = 0);
    axlTorusParametric(axlTorus* torus, axlPoint* r);
    axlTorusParametric(const axlTorus& torus, const axlPoint& r);
    axlTorusParametric(const axlTorusParametric& other);
    virtual ~axlTorusParametric(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    axlPoint* getV(void) const;
    axlPoint* getR(void) const;
    void setR(axlPoint* r);
    axlPoint* getW(void) const;

    axlTorus* getTorus(void) const;
    void setTorus(const axlTorus& torus);

    axlTorusParametric& operator=(const axlTorusParametric& other);

    void modifyR(double* r);

    virtual axlPoint eval(double u, double v);
    virtual void eval(axlPoint *point, double u,double v);
    virtual void eval(double& x, double& y, double& z, double u,double v);

    virtual void parameterOf(const axlPoint& point, double& um, double& vm);

public slots:
    void onTorusChanged(axlTorus* torus);
    void onRChanged(axlPoint* r);

private:
    axlTorusParametricPrivate* d;
};

#endif // AXLTORUSPARAMETRIC_H
