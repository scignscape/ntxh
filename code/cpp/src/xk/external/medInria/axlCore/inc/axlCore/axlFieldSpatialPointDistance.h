/* axlFieldSpatialPointDistance.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */
#include "axlCoreExport.h"
#ifndef AXLFIELDSPATIALPOINTDISTANCE_H
#define AXLFIELDSPATIALPOINTDISTANCE_H

#include <axlCore/axlAbstractFieldSpatial.h>

class axlFieldSpatialPointDistancePrivate;
class axlPoint;

class AXLCORE_EXPORT axlFieldSpatialPointDistance : public axlAbstractFieldSpatial
{
    Q_OBJECT

public:
    axlFieldSpatialPointDistance();
    virtual ~axlFieldSpatialPointDistance(void);

    void setParameter(double data, int channel);
    axlPoint *getPoint(void);

    double  scalar(double x, double y  = 0, double z = 0);

    QString description(void) const;
    QString identifier(void) const;

signals :
    void updated(void);


public slots:
    virtual void update(void);


private:
    axlFieldSpatialPointDistancePrivate *d;
};

AXLCORE_EXPORT dtkAbstractData *createAxlFieldSpatialPointDistance(void);


#endif // AXLFIELDSPATIALPOINTDISTANCE_H
