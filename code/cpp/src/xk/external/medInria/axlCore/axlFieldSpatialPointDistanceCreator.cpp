/* axlFieldSpatialPointDistanceCreator.cpp---
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

#include "axlFieldSpatialPointDistanceCreator.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldSpatialPointDistance.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractData.h>
#include <axlCore/axlDataDynamic.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkGlobal.h>
#include <QtGui>

class axlFieldSpatialPointDistanceCreatorPrivate
{
public:
    axlAbstractData * input;
    double x;
    double y;
    double z;
};

axlFieldSpatialPointDistanceCreator::axlFieldSpatialPointDistanceCreator(void) : axlAbstractFieldGenerator(),  d(new axlFieldSpatialPointDistanceCreatorPrivate)
{
    d->input = NULL;
    d->x = 0;
    d->y = 0;
    d->z = 0;

}

axlFieldSpatialPointDistanceCreator::~axlFieldSpatialPointDistanceCreator(void)
{
    delete d;

    d = NULL;
}


void axlFieldSpatialPointDistanceCreator::setInput(dtkAbstractData *data, int channel)
{
    if(axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data))
    {
        if(channel == 0){

            d->input = axlData;
        }
    }

}

void axlFieldSpatialPointDistanceCreator::setParameter(double data, int channel)
{
    if(channel == 0){
        d->x = data;
    }else if(channel == 1){
        d->y = data;
    }else if(channel == 2){
        d->z = data;
    }
}



int axlFieldSpatialPointDistanceCreator::update(void)
{

    if(!d->input){
        return 0;
    }

    //create field.
    axlFieldSpatialPointDistance *spatialField = new axlFieldSpatialPointDistance();
    QString newName = d->input->changeFieldName(spatialField->objectName());
    spatialField->setObjectName(newName);
    d->input->addField(spatialField);



    if(spatialField == NULL) { // field not found !!
        return 0;
    }

    spatialField->setParameter(d->x,0);
    spatialField->setParameter(d->y,1);
    spatialField->setParameter(d->z,2);
    spatialField->update();



    QList<axlAbstractData *>list;
    list << d->input;
    emit dataSetFieldsChanged(list, spatialField->objectName());

    return 1;

}


int axlFieldSpatialPointDistanceCreator::channelCount(void)
{
    return 0;
}


QString axlFieldSpatialPointDistanceCreator::description(void) const
{
    return "axlFieldSpatialPointDistanceCreator created fields for input dataset that evaluate the distance from data to a point in the 3D space";
}

QString axlFieldSpatialPointDistanceCreator::identifier(void) const
{
    return "axlFieldSpatialPointDistanceCreator";
}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractProcess *createaxlFieldSpatialPointDistanceCreator(void)
{
    return new axlFieldSpatialPointDistanceCreator;
}

