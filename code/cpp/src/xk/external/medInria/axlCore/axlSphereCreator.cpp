/* axlSphereCreator.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlSphereCreator.h"
#include <axlCore/axlDouble.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlSphere.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//////////////////////////////////////////////////////////
////axlSphereCreatorPrivate
//////////////////////////////////////////////////////////

class axlSphereCreatorPrivate{

public :
    axlPoint *center;
    double radius;
    axlSphere *output;


};

//////////////////////////////////////////////////////////
//// axlSphereCreatorPrivate
//////////////////////////////////////////////////////////
axlSphereCreator::axlSphereCreator(QObject *parent) : axlAbstractCreatorProcess(), d(new axlSphereCreatorPrivate){
    d->center = NULL;
    d->radius = 1;
    d->output = NULL;

}

axlSphereCreator::~axlSphereCreator(void){
    delete d;
    d = NULL;
}


axlAbstractData *axlSphereCreator::getInput(int channel) const{
    return d->center;
}

void axlSphereCreator::copyProcess(axlAbstractProcess *process){
    if(process->output()){
        d->output = dynamic_cast<axlSphere *>(process->output());
    }
}

bool axlSphereCreator::hasParameters(void){
    return true;
}


dtkAbstractData *axlSphereCreator::output(void){
    return d->output;
}


void axlSphereCreator::setInput(dtkAbstractData *newData, int channel){
    if(dynamic_cast<axlPoint *>(newData)){
        axlPoint *value = dynamic_cast<axlPoint *>(newData);
        if(channel == 0){
            d->center = value;
        }

    }
}

void axlSphereCreator::setParameter(double data){
        d->radius = data;
}


int axlSphereCreator::update(void){

    if(d->output == NULL){
        if(d->center &&(d->radius > 0.0) ){
            axlSphere *newSphere =  new axlSphere(d->center->x(), d->center->y(), d->center->z(), d->radius);
            d->output = newSphere;
            return 1;
        }else{
            return 0;
        }
    }else{
        if(d->center && (d->radius > 0.0) ){
            d->output->setValues(d->center->x(), d->center->y(), d->center->z(), d->radius);
            return 1;
        }else{
            return 0;
        }

    }

}

QString axlSphereCreator::description(void) const{
    return "create a sphere with one center point \n  and the radius value";
}


QString axlSphereCreator::identifier(void) const{
    return "axlSphereCreator";
}

dtkAbstractProcess *createaxlSphereCreator(void){

    return new axlSphereCreator;
}

