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

#include "axlFieldSpatialCoordinatesCreator.h"

#include <axlCore/axlFieldSpatialCoordinates.h>
#include <axlCore/axlAbstractData.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkGlobal.h>
#include <QtGui>

class axlFieldSpatialCoordinatesCreatorPrivate
{
public:
    axlAbstractData * input;
    double a;
    double b;
    double c;
    axlFieldSpatialCoordinates *spatialField;
};

axlFieldSpatialCoordinatesCreator::axlFieldSpatialCoordinatesCreator(void) : axlAbstractFieldGenerator(),  d(new axlFieldSpatialCoordinatesCreatorPrivate)
{
    d->a = 0;
    d->b = 0;
    d->c = 1;
    d->input = NULL;
    d->spatialField = NULL;

}

axlFieldSpatialCoordinatesCreator::~axlFieldSpatialCoordinatesCreator(void)
{
    delete d;
    d = NULL;
}

void axlFieldSpatialCoordinatesCreator::setInput(dtkAbstractData *data, int channel)
{
    if(axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data))
    {
        d->input = axlData;
    }

}



void axlFieldSpatialCoordinatesCreator::setParameter(double value, int channel)
{
    if(channel ==0)
        d->a = value;
    else if (channel == 1)
        d->b = value;
    else if (channel ==2)
        d->c = value;
    else
        qDebug() << "channel has only three values possible : 0 to 2";

}


int axlFieldSpatialCoordinatesCreator::update(void)
{
    if(!d->input)
        return 0;


    //create field
        d->spatialField = new axlFieldSpatialCoordinates();
        QString newName = d->input->changeFieldName(d->spatialField->objectName());
        d->spatialField->setObjectName(newName);
        d->input->addField(d->spatialField);

        if(!d->spatialField) // field not found !!
            return 0;


        d->spatialField->setParameter(d->a,0);
        d->spatialField->setParameter(d->b,1);
        d->spatialField->setParameter(d->c,2);
        d->spatialField->update();

        //    }

        QList<axlAbstractData *>list;
        list << d->input;
        emit dataSetFieldsChanged(list, d->spatialField->objectName());


    return 1;

}

QString axlFieldSpatialCoordinatesCreator::description(void) const
{
    return "axlFieldSpatialCoordinatesCreator created fields for input dataset that evaluate ax+by+cz with (a,b,c) the direction chosen";
}

QString axlFieldSpatialCoordinatesCreator::identifier(void) const
{
    return "axlFieldSpatialCoordinateGenerator";
}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractProcess *createaxlFieldSpatialCoordinatesCreator(void)
{
    return new axlFieldSpatialCoordinatesCreator;
}


