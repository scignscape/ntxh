/* axlCylinderCreator.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlCylinderCreator.h"
#include <axlCore/axlPoint.h>
#include <axlCore/axlCylinder.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlAbstractData.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//////////////////////////////////////////////////////////
////axlCylinderCreatorPrivate
//////////////////////////////////////////////////////////

class axlCylinderCreatorPrivate{

public :
    axlPoint *point1;
    axlPoint *point2;
    double radius;
    axlCylinder *output;


};

//////////////////////////////////////////////////////////
//// axlCylinderCreator
//////////////////////////////////////////////////////////
axlCylinderCreator::axlCylinderCreator(QObject *parent) : axlAbstractCreatorProcess(), d(new axlCylinderCreatorPrivate){
    d->point1 = NULL;
    d->point2 = NULL;
    d->radius = 1;
    d->output = NULL;

}

axlCylinderCreator::~axlCylinderCreator(void){

    delete d;
    d = NULL;
}


axlAbstractData * axlCylinderCreator::getInput(int channel) const{
    if(channel == 0){
        return d->point1;
    }else {
        return d->point2;
    }
}

void axlCylinderCreator::copyProcess(axlAbstractProcess *process){
    if(process->output()){
        d->output = dynamic_cast<axlCylinder *>(process->output());
    }
}

bool axlCylinderCreator::hasParameters(void){
    return true;
}


dtkAbstractData *axlCylinderCreator::output(void){
    return d->output;
}


void axlCylinderCreator::setInput(dtkAbstractData *newData, int channel){
    if(dynamic_cast<axlPoint *>(newData)){
        axlPoint *point = dynamic_cast<axlPoint *>(newData);
        if(channel == 0){
            d->point1 = point;
        }else if(channel == 1){
            d->point2 = point;
        }
    }
}


void axlCylinderCreator::setParameter(double data){
    d->radius = data;

}

int axlCylinderCreator::update(void){

    if(d->output == NULL){
        if(d->point1 && d->point2 && (d->radius >= 0.0)){
            axlCylinder *newCylinder =  new axlCylinder(d->point1, d->point2, d->radius);
            d->output = newCylinder;
            return 1;
        }else{
            return 0;
        }
    }else{
        if(d->point1 && d->point2 && (d->radius >= 0.0)){
            d->output->setValues(d->point1, d->point2, d->radius);
            return 1;
        }else{
            return 0;
        }

    }

}

QString axlCylinderCreator::description(void) const{
    return "create a cylinder with two points for its axe \n and its radius value";
}


QString axlCylinderCreator::identifier(void) const{
    return "axlCylinderCreator";
}

bool axlCylinderCreator::registered(void){
    return dtkAbstractProcessFactory::instance()->registerProcessType("axlCylinderCreator", createaxlCylinderCreator);
}


dtkAbstractProcess *createaxlCylinderCreator(void){

    return new axlCylinderCreator;
}
