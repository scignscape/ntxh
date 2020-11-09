/* axlBarycenterProcess.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlBarycenterProcess.h"
#include <axlCore/axlPoint.h>
#include <axlCore/axlLine.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlAbstractData.h>

//////////////////////////////////////////////////////////
////axlBarycenterProcessPrivate
//////////////////////////////////////////////////////////

class axlBarycenterProcessPrivate{

public :
    //inputs
    axlLine *input;
    axlDouble *lambda;
    //output
    axlPoint *output;

};

//////////////////////////////////////////////////////////
//// axlBarycenterProcess
//////////////////////////////////////////////////////////
axlBarycenterProcess::axlBarycenterProcess(QObject *parent) : axlAbstractProcess(), d(new axlBarycenterProcessPrivate){
    d->input = NULL;
    d->output = NULL;
    d->lambda = NULL;

}


axlBarycenterProcess::~axlBarycenterProcess(void){
    delete d;
    d= NULL;
}


axlAbstractData * axlBarycenterProcess::getInput(int channel) const{
    return d->input;
}

double axlBarycenterProcess::getCoeffValue(void) const{
    return d->lambda->value();
}



dtkAbstractData *axlBarycenterProcess::output(void){
    return d->output;
}


void axlBarycenterProcess::setInput(dtkAbstractData *newData, int channel){
    if(dynamic_cast<axlLine *>(newData)){
        axlLine *axlData = dynamic_cast<axlLine *>(newData);
        d->input = axlData;

    }
}

void axlBarycenterProcess::setParameter(double data, int channel){
    axlDouble *axlData = new axlDouble(data);
    d->lambda = axlData;
}

//! Returns the barycenter point of the line.
/*! By default the coefficient is equal to 0.5.
 *
 */
int axlBarycenterProcess::update(void){
    if (d->output==NULL) {
        if (d->input){
            if(d->lambda){
                d->output = d->input->getBarycenterPoint(d->lambda->value());
                return 1;
            } else {
                d->lambda = new axlDouble(0.5);
                d->output = d->input->getBarycenterPoint(d->lambda->value());
                return 1;
            }
        } else {
            return 0;
        }
    } else {
        if (d->input) {
            if(d->lambda) {
                axlPoint* tmp= d->input->getBarycenterPoint(d->lambda->value());
                d->output->setCoordinates( tmp->x(), tmp->y(), tmp->z()) ;
                delete tmp;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }

    } // return 0;
}

int axlBarycenterProcess::channelCount(void){
    return 1;
}

QString axlBarycenterProcess::description(void) const{
    return "give the barycenter point of the points defining the line";
}


QString axlBarycenterProcess::identifier(void) const{
    return "axlBarycenterProcess";
}

dtkAbstractProcess *createaxlBarycenterProcess(void){
    return new axlBarycenterProcess;
}
