/* axlFieldSpatialCoordinatesCreator.h ---
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

#ifndef axlFieldSpatialCoordinatesCreator_H
#define axlFieldSpatialCoordinatesCreator_H

#include "axlCoreExport.h"

#include <axlCore/axlAbstractFieldGenerator.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <QtGui>

class axlFieldSpatialCoordinatesCreatorPrivate;
class axlAbstractField;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldSpatialCoordinatesCreator : public axlAbstractFieldGenerator
{
    Q_OBJECT

public:
    axlFieldSpatialCoordinatesCreator(void);
    virtual ~axlFieldSpatialCoordinatesCreator(void);

public:
    virtual QString description(void) const;
    virtual QString identifier(void) const;


public slots:
    void setInput(dtkAbstractData *data, int channel);
    void setParameter(double value, int channel);
    int update(void);



public:
    static bool registered(void);


public:
    QString form(void) const
    {
        return QString(
                    " INPUT:0 data supportData \n"
                    " PARAMETER:0 double x-directionCoordinate 1.0 \n"
                    " PARAMETER:1 double y-directionCoordinate 0.0 \n"
                    " PARAMETER:2 double z-directionCoordinate 0.0");
    }

private:
    axlFieldSpatialCoordinatesCreatorPrivate *d;


};

AXLCORE_EXPORT dtkAbstractProcess *createaxlFieldSpatialCoordinatesCreator(void);
#endif // axlFieldSpatialCoordinatesCreator_H
