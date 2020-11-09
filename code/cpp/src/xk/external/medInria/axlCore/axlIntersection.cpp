/* axlIntersection.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlIntersection.h"
#include <axlCore/axlPoint.h>
#include <axlCore/axlLine.h>
#include <axlCore/axlAbstractData.h>

//////////////////////////////////////////////////////////
////axlIntersectionPrivate
//////////////////////////////////////////////////////////

class axlIntersectionPrivate{

public :
    //inputs
    axlAbstractData * data1;
    axlAbstractData * data2;
    //output
    axlPoint * output;

};

//////////////////////////////////////////////////////////
//// axlIntersectionPrivate
//////////////////////////////////////////////////////////
axlIntersection::axlIntersection(QObject *parent) : axlAbstractProcess(), d(new axlIntersectionPrivate){
    d->data1 = NULL;
    d->data2 = NULL;
    d->output = NULL;

}

axlIntersection::~axlIntersection(void){
    delete d;
    d= NULL;
}


axlAbstractData * axlIntersection::getInput(int channel) const{
    if(channel == 0)
        return d->data1;
    else
        return d->data2;
}



//dtkAbstractData *axlIntersection::output(int channel){
//    if(channel < d->output.size()){
//        return d->output.at(channel);
//    }
//}

dtkAbstractData *axlIntersection::output(void){
    return d->output;

}


void axlIntersection::setInput(dtkAbstractData *newData, int channel){
    if(dynamic_cast<axlAbstractData *>(newData)){
        axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(newData);
        if(channel == 0)
            d->data1 = axlData;
        else
            d->data2 = axlData;
    }
}

int axlIntersection::channelCount(void){
    //    return d->output.size();
    return 1;
}


int axlIntersection::update(void){

    //    if(!(d->output.empty())){
    //        d->output.clear();
    //    }

    if (dynamic_cast<axlLine *>(d->data1) && dynamic_cast<axlLine *>(d->data2)){

        axlLine *line2 = dynamic_cast<axlLine *>(d->data2);
        axlLine *line1 = dynamic_cast<axlLine *>(d->data1);

        double a1 = line1->secondPoint()->x() - line1->firstPoint()->x();
        double b1 = line1->secondPoint()->y() - line1->firstPoint()->y();
        double c1 = line1->secondPoint()->z() - line1->firstPoint()->z();

        double a2 = line2->secondPoint()->x() - line2->firstPoint()->x();
        double b2 = line2->secondPoint()->y() - line2->firstPoint()->y();
        double c2 = line2->secondPoint()->z() - line2->firstPoint()->z();


        double t1 = 0.0;
        double t2 = 0.0;

        //compute solution
        if(!(a2 == 0)){
            double B = b1 - (b2/a2)*a1;
            t1 = (1/B)* ((b2/a2)*(line1->firstPoint()->x() -line2->firstPoint()->x()) + (line2->firstPoint()->y() -line1->firstPoint()->y() ) );
            t2 = (a1/a2)*t1 + ((line1->firstPoint()->x() -line2->firstPoint()->x())/a2) ;
        }else if(!(a1 == 0)){
            t1 = (line1->firstPoint()->x() -line2->firstPoint()->x())/a1;
            t2 = (1/b2)*(b1*t1 + line1->firstPoint()->y() -line2->firstPoint()->y());
        }

        // double xSol1 = a1*t1 + line1->firstPoint()->x();
        // double ySol1 = b1*t1 + line1->firstPoint()->y();
        double zSol1 = c1*t1 + line1->firstPoint()->z();

        double xSol2 = a2*t2 + line2->firstPoint()->x();
        double ySol2 = b2*t2 + line2->firstPoint()->y();
        double zSol2 = c2*t2 + line2->firstPoint()->z();

        if(std::abs(zSol1 -zSol2) < 0.01){
            if(d->output == NULL){
                d->output = new axlPoint(xSol2, ySol2, zSol2);
            }else{
                d->output->setCoordinates(xSol2, ySol2, zSol2);
            }
            //emit dataInserted(d->output);
            return 1;
        }
    }
    return 0;
}

QString axlIntersection::description(void) const{
    return "give the intersection point(s) between two axlData";
}


QString axlIntersection::identifier(void) const{
    return "axlIntersection";
}

dtkAbstractProcess *createaxlIntersectionProcess(void){
    return new axlIntersection;
}
