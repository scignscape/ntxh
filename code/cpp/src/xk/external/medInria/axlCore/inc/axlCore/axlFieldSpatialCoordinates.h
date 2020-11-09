/* axlFieldSpatialCoordinates.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *1
 */
#include "axlCoreExport.h"
#ifndef AXLFIELDSPATIALCOORDINATES_H
#define AXLFIELDSPATIALCOORDINATES_H

#include <axlCore/axlAbstractFieldSpatial.h>

class axlFieldSpatialCoordinatesPrivate;

class AXLCORE_EXPORT axlFieldSpatialCoordinates : public axlAbstractFieldSpatial
{
    Q_OBJECT

public:
    axlFieldSpatialCoordinates();
    virtual ~axlFieldSpatialCoordinates(void);

    double  scalar(double x, double y  = 0, double z = 0);

    void setParameter(double parameter, int channel);
    double parameter(int channel);

    QString description(void) const;
    QString identifier(void) const;

signals :
    void updated(void);


public slots:
    virtual void update(void);


private:
    axlFieldSpatialCoordinatesPrivate *d;
};

AXLCORE_EXPORT dtkAbstractData *createaxlFieldSpatialCoordinates(void);


#endif // AXLFIELDSPATIALCOORDINATES_H
