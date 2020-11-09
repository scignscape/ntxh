/* axlLight.h ---
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

#ifndef axlLight_H
#define axlLight_H

#include "axlCoreExport.h"

#include <QtCore>

#include <dtkCoreSupport/dtkAbstractData.h>

class axlLightPrivate;
class axlPoint;

class AXLCORE_EXPORT axlLight : public dtkAbstractData
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor )
    Q_PROPERTY(double opacity READ opacity WRITE setOpacity )
    Q_PROPERTY(QString shader READ shader WRITE setShader )

public:
     axlLight(QObject *parent = 0);
     axlLight(double x, double y, double z=0, QObject *parent = 0);
     axlLight(double *position, double *ambiant, double *diffuse, double *specular, double exponent, QObject *parent = 0);
     axlLight(const axlLight& other);
    ~axlLight(void);

    virtual QString description(void) const;

    double x(void) const;
    double y(void) const;
    double z(void) const;
    double *position(void) const;
    double *ambiant(void) const;
    double *diffuse(void) const;
    double *specular(void) const;
    double exponent(void) const;

    void setPosition(axlPoint *position);
    void setAmbiant(axlPoint *ambiant);
    void setDiffuse(axlPoint *diffuse);
    void setSpecular(axlPoint *specular);
    void setExponent(double position);



public slots:
    void onPositionChanged(axlPoint *position);


public:
    const QColor& color(void) const;
    const double& opacity(void) const;
    const QString& shader(void) const;

public slots:

    void setColor(const QColor& color);
    void setOpacity(const double& opacity);
    void setShader(const QString& shader);


private:
    axlLightPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlLight  point);
QDebug operator<<(QDebug dbg, axlLight& point);
QDebug operator<<(QDebug dbg, axlLight *point);

#endif // axlLight_H
