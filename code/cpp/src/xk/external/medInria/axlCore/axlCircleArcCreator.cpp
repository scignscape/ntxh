/* axlCircleArcCreator.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlCircleArcCreator.h"
#include <axlCore/axlPoint.h>
#include <axlCore/axlCircleArc.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlAbstractData.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//////////////////////////////////////////////////////////
////axlCircleArcCreatorPrivate
//////////////////////////////////////////////////////////

class axlCircleArcCreatorPrivate{

public :
    axlPoint *point1;
    axlPoint *point2;
    axlPoint *point3;
    axlPoint *point4;
    bool direct;
    axlCircleArc *output;
};

//////////////////////////////////////////////////////////
//// axlCircleArcCreator
//////////////////////////////////////////////////////////
axlCircleArcCreator::axlCircleArcCreator(QObject *parent) : axlAbstractCreatorProcess(), d(new axlCircleArcCreatorPrivate) {
    d->point1 = NULL;
    d->point2 = NULL;
    d->point3 = NULL;
    d->point4 = NULL;
    d->direct = true;
    d->output = NULL;
}

axlCircleArcCreator::~axlCircleArcCreator(void){

    delete d;
    d = NULL;
}

//! Return the input points of the process
/*!
 *channel = 0, return the first extreme point .
 *channel = 1, return the second extreme point
 *channel = 2, return the center of the circle arc
 *channel = 3, return the normal of the plan that conatins the circle arc.
*/
axlAbstractData *axlCircleArcCreator::getInput(int channel) const{
    if(channel == 0) {
        return d->point1;
    } else if(channel == 1) {
        return d->point2;
    } else if (channel == 2) {
        return d->point3;
    } else if (channel == 3) {
        return d->point4;
    } else {
        return NULL;
    }
}

//! Return a copy of the process, useful for dynamic objects
/*!
*
*/
void axlCircleArcCreator::copyProcess(axlAbstractProcess *process){
    if(process->output()){
        d->output = dynamic_cast<axlCircleArc *>(process->output());
    }
}

//! Return true as the process needs one parameter.
/*!
*
*/
bool axlCircleArcCreator::hasParameters(void){
    return true;
}

//! Return the results of the process : NULL or the axlCircleArc
/*!
*
*/
dtkAbstractData *axlCircleArcCreator::output(void){
    return d->output;
}

//! Assigns points :
/*!
 *channel = 0, the first extreme point .
 *channel = 1, the second extreme point
 *channel = 2, the center of the circle arc
 *channel = 3, the normal of the plan that conatins the circle arc.
 */
void axlCircleArcCreator::setInput(dtkAbstractData *newData, int channel){
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
        else if(channel == 3){
            d->point4 = point;
        }
    }
}

//! Assigns the value of the boolean parameter which says whether it is direct .
/*!
 *
 */
void axlCircleArcCreator::setParameter(int data){
    if(data == 0 || data == 1){
        d->direct = data;
    }

}

//! Create an axlCircleArc.
/*!
 *
 */
int axlCircleArcCreator::update(void){

    if(d->output == NULL){
        if(d->point1 && d->point2 &&  d->point3 && d->point4){
            d->output = new axlCircleArc(d->point1, d->point2, d->point3, d->point4, d->direct);
            return 1;
        }else{
            return 0;
        }
    }else{
        if(d->point1 && d->point2 &&  d->point3 && d->point4){
            d->output->setValues(d->point1, d->point2, d->point3, d->point4, d->direct);
            return 1;
        }else{
            return 0;
        }

    }

}

QString axlCircleArcCreator::description(void) const{
    return "create a circle arc with four points : \n the two first ones are extremity, the third one is its center\n and the last one its normal \n and a boolean :\n the direction";
}


QString axlCircleArcCreator::identifier(void) const{
    return "axlCircleArcCreator";
}

dtkAbstractProcess *createaxlCircleArcCreator(void){

    return new axlCircleArcCreator;
}


// /////////////////////////////////////////////////////////////////
// axlCircleArcCreator documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlCircleArcCreator
 *
 *  \brief Class axlCircleArcCreator defines an process which creates an axlCircleArc.
 *
 *  Example:
 *  \code
 *  \endcode
 */

