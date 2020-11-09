/* axlAbstractVolumeDiscrete.h ---
 *
 * Author:Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 * Created:
 * Version: $Id$
 * Last-Updated:
 *           By:
 *     Update #:
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTVOLUMEDISCRETE_H
#define AXLABSTRACTVOLUMEDISCRETE_H

#include "axlAbstractVolume.h"
#include "axlCoreExport.h"
#include "axlPoint.h"

#include <dtkMathSupport/dtkVector3D.h>

class axlMesh;
class axlAbstractVolumeDiscretePrivate;
//class axlAbstractVisitorParametric;

class AXLCORE_EXPORT axlAbstractVolumeDiscrete : public axlAbstractVolume
{
    Q_OBJECT

public:
    axlAbstractVolumeDiscrete(void);
    axlAbstractVolumeDiscrete(unsigned int x,unsigned int y,unsigned int z);
    axlAbstractVolumeDiscrete(const axlAbstractVolumeDiscrete& other);
    virtual ~axlAbstractVolumeDiscrete(void);


public :
    virtual int xDimension(void) const ;
    virtual int yDimension(void) const;
    virtual int zDimension(void) const ;
    virtual void setDimensions(unsigned int x,unsigned int y,unsigned int z);

    virtual double getValue(int indiceGlobal) const;
    virtual double getValue(int i, int j, int k) const;
//    virtual double *getValues(void) const;
    virtual void setValue(double value, int indiceGlobal);
    virtual void setValue(double value, int i, int j, int k);
//    virtual void setValues(double *values);

    virtual double minValue(void) const;
    virtual double midValue(void) const;
    virtual double maxValue(void) const;


private:
    axlAbstractVolumeDiscretePrivate *d;
};
#endif // AXLABSTRACTVOLUMEDISCRETE_H
