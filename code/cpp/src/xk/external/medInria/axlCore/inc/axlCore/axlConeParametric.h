/* axlConeParametric.h ---
 *
 * Author: Hung NGUYEN.
 */

/* Commentary:
 *    This class is used for solidtools Plugin.
 */

/* Change log:
 *
 */

#ifndef AXLCONEPARAMETRIC_H
#define AXLCONEPARAMETRIC_H

#include "axlCoreExport.h"
#include "axlAbstractSurfaceParametric.h"

#include <QtCore>

class axlPoint;
class axlCone;
class axlConeParametricPrivate;

class AXLCORE_EXPORT axlConeParametric : public axlAbstractSurfaceParametric {
    Q_OBJECT

public:
    axlConeParametric(axlAbstractSurfaceParametric* parent = 0);
    axlConeParametric(axlCone* cone, axlPoint* r);
    axlConeParametric(const axlCone& cone, const axlPoint& r);
    axlConeParametric(const axlConeParametric& other);
    virtual ~axlConeParametric(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    void setCone(axlCone* cone);
    axlPoint* getR(void) const;
    void setR(axlPoint* r);

    axlConeParametric& operator=(const axlConeParametric& other);

    void modifyR(double* r);

    axlCone* getCone(void) const;
    void setCone(const axlCone& cone);

    virtual axlPoint eval(double u, double v);
    virtual void eval(axlPoint *point, double u,double v);
    virtual void eval(double& x, double& y, double& z, double u,double v);

//    virtual void normal(axlPoint *normal, double, double);

    virtual void parameterOf(const axlPoint& point, double& um, double& vm);

public slots:
    void onConeChanged(axlCone* cone);
    void onRChanged(axlPoint* r);

private:
    axlConeParametricPrivate* d;
};

#endif // AXLCONEPARAMETRIC_H
