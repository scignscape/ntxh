/* axlConeCreator.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlConeCreator.h"
#include <axlCore/axlPoint.h>
#include <axlCore/axlCone.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlAbstractData.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//////////////////////////////////////////////////////////
////axlConeCreatorPrivate
//////////////////////////////////////////////////////////

class axlConeCreatorPrivate{

public :
    axlPoint *point1;
    axlPoint *point2;
    double radius;
    axlCone *output;


};

//////////////////////////////////////////////////////////
//// axlConeCreatorPrivate
//////////////////////////////////////////////////////////
axlConeCreator::axlConeCreator(QObject *parent) : axlAbstractCreatorProcess(), d(new axlConeCreatorPrivate){
    d->point1 = NULL;
    d->point2 = NULL;
    d->radius = 1;
    d->output = NULL;


}

axlConeCreator::~axlConeCreator(void){

    delete d;
    d = NULL;
}


axlAbstractData *axlConeCreator::getInput(int channel) const{
    if(channel == 0){
        return d->point1;
    }else {
        return d->point2;
    }
}


void axlConeCreator::copyProcess(axlAbstractProcess *process){
    if(process->output()){
        d->output = dynamic_cast<axlCone *>(process->output());
    }

}

bool axlConeCreator::hasParameters(void){
    return true;
}



dtkAbstractData *axlConeCreator::output(void){
    return d->output;
}

void axlConeCreator::setInput(dtkAbstractData *newData, int channel){
    if(dynamic_cast<axlPoint *>(newData)){
        axlPoint *point = dynamic_cast<axlPoint *>(newData);
        if(channel == 0){
            d->point1 = point;
        }else if(channel ==1){
            d->point2 = point;
        }
    }
}


void axlConeCreator::setParameter(double value){
    d->radius = value;

}

int axlConeCreator::update(void){
    if(d->output == NULL){
        if(d->point1 && d->point2 && (d->radius >=0.0)){
            axlCone *newCone = new axlCone(d->point1, d->point2, d->radius);
            d->output = newCone;
            return 1;
        }else{
            return 0;
        }
    }else{

        if(d->point1 && d->point2 && (d->radius >=0.0)){
            d->output->setValues(d->point1, d->point2, d->radius);
            return 1;
        }else{
            return 0;
        }

    }

}

QString axlConeCreator::description(void) const{
    return "create a cone with two points : \n its base point and its apex point \n and its radius value";
}


QString axlConeCreator::identifier(void) const{
    return "axlConeCreator";
}

bool axlConeCreator::registered(void){
    return dtkAbstractProcessFactory::instance()->registerProcessType("axlConeCreator", createaxlConeCreator);
}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractProcess *createaxlConeCreator(void)
{
    return new axlConeCreator;
}



