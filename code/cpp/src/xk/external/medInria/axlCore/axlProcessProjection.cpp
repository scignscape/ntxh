/* axlProcessProjection.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */
#include "axlProcessProjection.h"
#include <axlCore/axlPoint.h>
#include <axlCore/axlLine.h>
#include <axlCore/axlAbstractData.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//////////////////////////////////////////////////////////
////axlProcessProjectionPrivate
//////////////////////////////////////////////////////////

class axlProcessProjectionPrivate{

public :
    QPair <axlPoint *, axlLine *> inputs;


};

//////////////////////////////////////////////////////////
//// axlProcessProjectionPrivate
//////////////////////////////////////////////////////////
axlProcessProjection::axlProcessProjection(QObject *parent) : axlAbstractProcess(), d(new axlProcessProjectionPrivate){

}

axlProcessProjection::~axlProcessProjection(void){
    delete d;
    d = NULL;
}


axlAbstractData *axlProcessProjection::getInput(int channel) const{
    if(channel == 0){
        return d->inputs.first;
    }else{
        return d->inputs.second;
    }
}


void axlProcessProjection::copyProcess(axlAbstractProcess *process){
    d->inputs.first = dynamic_cast<axlPoint *>(process->output());
}

bool axlProcessProjection::hasParameters(void){
    return false;
}


bool axlProcessProjection::isOnLine(void)
{

    if (d->inputs.first && d->inputs.second) {
        double xa = d->inputs.second->firstPoint()->x();
        double ya = d->inputs.second->firstPoint()->y();
        double za = d->inputs.second->firstPoint()->z();

        double a = d->inputs.second->secondPoint()->x() - xa;
        double b = d->inputs.second->secondPoint()->y() - ya;
        double c = d->inputs.second->secondPoint()->z() - za;

        double x = d->inputs.first->x();
        double y = d->inputs.first->y();
        double z = d->inputs.first->z();


        if ( d->inputs.first->isEqualTo(d->inputs.second->firstPoint()) ||
             d->inputs.first->isEqualTo(d->inputs.second->secondPoint()) ) {
            return true;
        }

        double signe = 0;
        if (d->inputs.second->planeDirection() < 0) {
            signe = -1;
        } else if(d->inputs.second->planeDirection() > 0) {
            signe = 1;
        }

        if (a==0 && b ==0 && c ==0) {
            return (x==xa && y ==ya && z==za);
        } else {
            double ta = 0;
            double tb = 0;
            double tc = 0;

            QList<double> hasBeenComputed;

            if (a !=0) {
                ta = (x-xa)/a;
                hasBeenComputed << ta;
            }
            if (b !=0) {
                tb = (y-ya)/b;
                hasBeenComputed << tb;
            }
            if (c !=0) {
                tc = (z-za)/c;
                hasBeenComputed << tc;
            }
            if (hasBeenComputed.size() ==1) {
                return (signe *hasBeenComputed.at(0)> 0 && signe*hasBeenComputed.at(0) < 1);
            } else {
                bool areEqual = true;
                for (int i = 0; i < hasBeenComputed.size()-1; i++) {
                    if (!(hasBeenComputed.at(i)== hasBeenComputed.at(i+1))) {
                        areEqual = false;
                    }
                }
                return areEqual;
            }
        }
    } else {
        dtkWarn() << "No inputs available";
        return false;
    }

}


dtkAbstractData *axlProcessProjection::output(void){
    return d->inputs.first;
}


void axlProcessProjection::setInput(dtkAbstractData *newData, int channel){
    if(channel == 0){
        if(dynamic_cast<axlPoint *>(newData)){
            axlPoint *point = dynamic_cast<axlPoint *>(newData);
            d->inputs.first = point;
        }else{
            qDebug() << "is not a point.";
        }
    }else if(channel == 1){
        if(dynamic_cast<axlLine *>(newData)){
            axlLine *line = dynamic_cast<axlLine *>(newData);
            d->inputs.second = line;
        }else{
            qDebug() << "is not a line.";
        }
    }else{
        qDebug() << "channel has only two possible values : 0 and 1.";
    }
}


int axlProcessProjection::update(void){


    if(isOnLine()){
        return 1;
    }


    double AB = axlPoint::distance(d->inputs.second->secondPoint(), d->inputs.second->firstPoint());
    double ABcarre = AB*AB;


    if(ABcarre == 0){
        d->inputs.first->setCoordinates(d->inputs.second->firstPoint()->x(),d->inputs.second->firstPoint()->y(),d->inputs.second->firstPoint()->z());
    }else{

        axlPoint point1;
        axlPoint point2;
        point1.setCoordinates(d->inputs.second->firstPoint()->x()-d->inputs.first->x(),d->inputs.second->firstPoint()->y()-d->inputs.first->y() ,d->inputs.second->firstPoint()->z()-d->inputs.first->z() );
        point2.setCoordinates(d->inputs.second->secondPoint()->x()-d->inputs.second->firstPoint()->x(),d->inputs.second->secondPoint()->y()-d->inputs.second->firstPoint()->y() ,d->inputs.second->secondPoint()->z()-d->inputs.second->firstPoint()->z() );
        double scalarProduct =axlPoint::dotProduct(point1,point2);
        scalarProduct = -1*scalarProduct;

        double t = scalarProduct/ABcarre;

        double x = d->inputs.second->firstPoint()->x() + t*(d->inputs.second->secondPoint()->x() - d->inputs.second->firstPoint()->x());
        double y = d->inputs.second->firstPoint()->y() + t*(d->inputs.second->secondPoint()->y() - d->inputs.second->firstPoint()->y());
        double z = d->inputs.second->firstPoint()->z() + t*(d->inputs.second->secondPoint()->z() - d->inputs.second->firstPoint()->z());
        d->inputs.first->setCoordinates(x,y,z);
    }

    return 1;

}

QString axlProcessProjection::description(void) const{
    return "if the point is not on the line, axlProcessProjection projects it on the line";
}


QString axlProcessProjection::identifier(void) const{
    return "axlProcessProjection";
}


bool axlProcessProjection::registered(void) {
    return dtkAbstractProcessFactory::instance()->registerProcessType("axlProcessProjection", createaxlProcessProjection, "axlAbstractProcess");
}

dtkAbstractProcess *createaxlProcessProjection(void){

    return new axlProcessProjection;
}
