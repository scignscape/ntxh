/* axlEllipsoidCreator.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlEllipsoidCreator.h"
#include <axlCore/axlPoint.h>
#include <axlCore/axlEllipsoid.h>
#include <axlCore/axlAbstractData.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//////////////////////////////////////////////////////////
////axlEllipsoidCreatorPrivate
//////////////////////////////////////////////////////////

class axlEllipsoidCreatorPrivate{

public :
    axlPoint *point1;
    axlPoint *point2;
    axlPoint *point3;
    axlPoint *point4;
    axlEllipsoid *output;


};

//////////////////////////////////////////////////////////
//// axlEllipsoidCreatorPrivate
//////////////////////////////////////////////////////////
axlEllipsoidCreator::axlEllipsoidCreator(QObject *parent) : axlAbstractCreatorProcess(), d(new axlEllipsoidCreatorPrivate){
    d->point1 = NULL;
    d->point2 = NULL;
    d->point3 = NULL;
    d->point4 = NULL;
    d->output = NULL;

    dtkAbstractProcessFactory::instance()->registerProcessType("axlEllipsoidCreator", createaxlEllipsoidCreator);

}

axlEllipsoidCreator::~axlEllipsoidCreator(void){

    delete d;
    d = NULL;
}


axlAbstractData *axlEllipsoidCreator::getInput(int channel) const{
    if(channel == 0){
        return d->point1;
    }else if(channel == 1){
        return d->point2;
    }
    else if(channel == 2){
        return d->point3;
    }
    else{
        return d->point4;
    }
}


void axlEllipsoidCreator::copyProcess(axlAbstractProcess *process){
    if(d->output){
        d->output = dynamic_cast<axlEllipsoid *>(process->output());
    }
}

bool axlEllipsoidCreator::hasParameters(void){
    return false;
}


dtkAbstractData *axlEllipsoidCreator::output(void){
    return d->output;
}


void axlEllipsoidCreator::setInput(dtkAbstractData *newData, int channel){
    if(dynamic_cast<axlPoint *>(newData)){
        axlPoint *point = dynamic_cast<axlPoint *>(newData);
        if(channel == 0){
            d->point1 = point;
        }else if(channel == 1){
            d->point2 = point;
        }
        else if(channel == 2){
            d->point3 = point;
        }
        else{
            d->point4 = point;
        }

    }
}


int axlEllipsoidCreator::update(void){

    if(d->output == NULL){
        if(d->point1 && d->point2 && d->point3 && d->point4){
            axlEllipsoid *newEllipsoid =  new axlEllipsoid(d->point1, d->point2, d->point3, d->point4);
            d->output = newEllipsoid;
            return 1;
        }else{
            return 0;
        }
    }else{
        if(d->point1 && d->point2 && d->point3 && d->point4){
            d->output->setValues(d->point1, d->point2, d->point3, d->point4);
            return 1;
        }else{
            return 0;
        }

    }

}

QString axlEllipsoidCreator::description(void) const{
    return "create a ellipsoid with four points : \n the first one is the center, \n the three others determine its 3 axes";
}


QString axlEllipsoidCreator::identifier(void) const{
    return "axlEllipsoidCreator";
}


bool axlEllipsoidCreator::registered(void){
    return dtkAbstractProcessFactory::instance()->registerProcessType("axlEllipsoidCreator", createaxlEllipsoidCreator);
}

dtkAbstractProcess *createaxlEllipsoidCreator(void){
    return new axlEllipsoidCreator;
}
