/* axlAbstractCreatorProcess.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlAbstractCreatorProcess.h"
#include <axlCore/axlAbstractData.h>

//////////////////////////////////////////////////////////
////axlAbstractCreatorProcessPrivate
//////////////////////////////////////////////////////////

class axlAbstractCreatorProcessPrivate{

};

//////////////////////////////////////////////////////////
//// axlAbstractCreatorProcess
//////////////////////////////////////////////////////////
axlAbstractCreatorProcess::axlAbstractCreatorProcess(QObject *parent) : axlAbstractProcess(), d(new axlAbstractCreatorProcessPrivate){


}


axlAbstractCreatorProcess::~axlAbstractCreatorProcess(void){

    delete d;
    d = NULL;
}


axlAbstractData * axlAbstractCreatorProcess::getInput(int channel) const{
    Q_UNUSED(channel);
    return NULL;
}

int axlAbstractCreatorProcess::channelCount(void){
    return 1;
}

dtkAbstractData *axlAbstractCreatorProcess::output(void){
    DTK_DEFAULT_IMPLEMENTATION;
    return NULL;
}

dtkAbstractData *axlAbstractCreatorProcess::output(int channel){
    Q_UNUSED(channel);
    return NULL;
}


void axlAbstractCreatorProcess::setInput(dtkAbstractData *newData, int channel){
    Q_UNUSED(newData);
    Q_UNUSED(channel);


}


int axlAbstractCreatorProcess::update(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


QString axlAbstractCreatorProcess::description(void) const{
    DTK_DEFAULT_IMPLEMENTATION;
    return QString();
}


QString axlAbstractCreatorProcess::identifier(void) const{
    DTK_DEFAULT_IMPLEMENTATION;
    return QString();
}
