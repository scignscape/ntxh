/* axlPlaneCreator.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlPlaneCreator.h"
#include <axlCore/axlPoint.h>
#include <axlCore/axlPlane.h>
#include <axlCore/axlAbstractData.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//////////////////////////////////////////////////////////
////axlPlaneCreatorPrivate
//////////////////////////////////////////////////////////

class axlPlaneCreatorPrivate{

public :
    QPair <axlPoint *, axlPoint *> inputs;
    axlPlane *output;


};

//////////////////////////////////////////////////////////
//// axlPlaneCreatorPrivate
//////////////////////////////////////////////////////////
axlPlaneCreator::axlPlaneCreator(QObject *parent) : axlAbstractCreatorProcess(), d(new axlPlaneCreatorPrivate){
    d->output = NULL;

    dtkAbstractProcessFactory::instance()->registerProcessType("axlPlaneCreator", createaxlPlaneCreator);

}

axlPlaneCreator::~axlPlaneCreator(void){
    delete d;
    d = NULL;
}


axlAbstractData *axlPlaneCreator::getInput(int channel) const{
    if(channel == 0){
        return d->inputs.first;
    }else{
        return d->inputs.second;
    }
}


void axlPlaneCreator::copyProcess(axlAbstractProcess *process){
    if(process->output()){
        d->output = dynamic_cast<axlPlane *>(process->output());
    }
}

bool axlPlaneCreator::hasParameters(void){
    return false;
}


dtkAbstractData *axlPlaneCreator::output(void){
    return d->output;
}


void axlPlaneCreator::setInput(dtkAbstractData *newData, int channel){
    if(dynamic_cast<axlPoint *>(newData)){
        axlPoint *point = dynamic_cast<axlPoint *>(newData);
        if(channel == 0){
            d->inputs.first = point;
        }else{
            d->inputs.second = point;
        }
    }
}


int axlPlaneCreator::update(void){

    if(d->output == NULL){
        if(d->inputs.first && d->inputs.second){
            d->output = new axlPlane(d->inputs.first, d->inputs.second);
            return 1;
        }else{
            return 0;
        }
    }else{
        if(d->inputs.first && d->inputs.second){
            d->output->setValues(d->inputs.first, d->inputs.second);
            return 1;
        }else{
            return 0;
        }

    }

}

QString axlPlaneCreator::description(void) const{
    return "create a plane with two points : \n one on the plane and the other one to determine its normal";
}


QString axlPlaneCreator::identifier(void) const{
    return "axlPlaneCreator";
}


bool axlPlaneCreator::registered(void) {
    return dtkAbstractProcessFactory::instance()->registerProcessType("axlPlaneCreator", createaxlPlaneCreator);
}

dtkAbstractProcess *createaxlPlaneCreator(void){

    return new axlPlaneCreator;
}


