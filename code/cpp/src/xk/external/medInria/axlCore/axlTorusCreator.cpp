/* axlTorusCreator.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlTorusCreator.h"
#include <axlCore/axlPoint.h>
#include <axlCore/axlTorus.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlAbstractData.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//////////////////////////////////////////////////////////
////axlTorusCreatorPrivate
//////////////////////////////////////////////////////////

class axlTorusCreatorPrivate{

public :
    axlPoint *point1;
    axlPoint *point2;
    double ringRadius;
    double crossSectionRadius;
    axlTorus *output;


};

//////////////////////////////////////////////////////////
//// axlTorusCreator
//////////////////////////////////////////////////////////
axlTorusCreator::axlTorusCreator(QObject *parent) : axlAbstractCreatorProcess(), d(new axlTorusCreatorPrivate){
    d->point1 = NULL;
    d->point2 = NULL;
    d->ringRadius = 1;
    d->crossSectionRadius = 0.2;
    d->output = NULL;

    dtkAbstractProcessFactory::instance()->registerProcessType("axlTorusCreator", createaxlTorusCreator);

}

axlTorusCreator::~axlTorusCreator(void){

    delete d;
    d = NULL;
}


axlAbstractData *axlTorusCreator::getInput(int channel) const{
    if(channel == 0){
        return d->point1;
    }else {
        return d->point2;
    }
}

void axlTorusCreator::copyProcess(axlAbstractProcess *process){
    if(process->output()){
        d->output = dynamic_cast<axlTorus *>(process->output());
    }
}

bool axlTorusCreator::hasParameters(void){
    return true;
}

dtkAbstractData *axlTorusCreator::output(void){
    if(d->output){
        return d->output;
    } else {
        return nullptr;
    }
}


void axlTorusCreator::setInput(dtkAbstractData *newData, int channel){
    if(dynamic_cast<axlPoint *>(newData)){
        axlPoint *point = dynamic_cast<axlPoint *>(newData);
        if(channel == 0){
            d->point1 = point;
        }else if(channel == 1){
            d->point2 = point;
        }
    }
}

void axlTorusCreator::setParameter(double data, int channel){
    if(channel ==0){
        d->ringRadius = data;
    }else if (channel==1){
        d->crossSectionRadius = data;
    }
}

int axlTorusCreator::update(void){

    if(d->output == NULL){
        if(d->point1 && d->point2 &&  (d->ringRadius > d->crossSectionRadius) &&(d->ringRadius > 0.0)){
            d->output = new axlTorus(d->point1, d->point2, d->ringRadius, d->crossSectionRadius);
            return 1;
        }else{
            return 0;
        }
    }else{
        if(d->point1 && d->point2 && (d->ringRadius > d->crossSectionRadius)  &&(d->ringRadius > 0.0)){
            d->output->setValues(d->point1, d->point2, d->ringRadius, d->crossSectionRadius);
            return 1;
        }else{
            return 0;
        }

    }

}

QString axlTorusCreator::description(void) const{
    return "create a torus with two points : \n its center and  another one to determine its normal \n and two values :\n the ringRadius and the crossSectionRadius";
}


QString axlTorusCreator::identifier(void) const{
    return "axlTorusCreator";
}

dtkAbstractProcess *createaxlTorusCreator(void){

    return new axlTorusCreator;
}
