/* axlAbstractVolumeDiscrete.cpp ---
 *
 * Author:Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 * Created:
 * Version: $Id$
 * Last-Updated:
 *           By:
 *     Update #:
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractVolumeDiscrete.h"

#include "axlMesh.h"
#include <dtkCoreSupport/dtkGlobal.h>


class axlAbstractVolumeDiscretePrivate
{
public:
    //    //values in each cell.
    //    double *values;

};


//!
/*!
 *
 */
axlAbstractVolumeDiscrete::axlAbstractVolumeDiscrete(void) : axlAbstractVolume(), d(new axlAbstractVolumeDiscretePrivate)
{
    //    d->values = NULL;
}


//!
/*!
 *
 */
axlAbstractVolumeDiscrete::axlAbstractVolumeDiscrete(unsigned int x,unsigned int y,unsigned int z ) : axlAbstractVolume(), d(new axlAbstractVolumeDiscretePrivate)
{
    //    d->values = new double[x*y*z];
}


//!
/*!
 *
 */
axlAbstractVolumeDiscrete::axlAbstractVolumeDiscrete(const axlAbstractVolumeDiscrete& other) : axlAbstractVolume(), d(new axlAbstractVolumeDiscretePrivate)
{
    //    d->values = other.getValues();
}


//!
/*!
 *
 */
axlAbstractVolumeDiscrete::~axlAbstractVolumeDiscrete(void)
{
    delete d;

    d = NULL;
}


//!
/*!
 *
 */
int axlAbstractVolumeDiscrete::xDimension(void) const{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;

}


//!
/*!
 *
 */
int axlAbstractVolumeDiscrete::yDimension(void) const {
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}



//!
/*!
 *
 */
int axlAbstractVolumeDiscrete::zDimension(void) const{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//!
/*!
 *
 */
void axlAbstractVolumeDiscrete::setDimensions(unsigned int x,unsigned int y,unsigned int z){
    DTK_DEFAULT_IMPLEMENTATION;
}


//!
/*!
 *
 */
double axlAbstractVolumeDiscrete::getValue(int indiceGlobal) const{
    //    return d->values[indiceGlobal];
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//!
/*!
 *
 */
double axlAbstractVolumeDiscrete::getValue(int i, int j, int k) const{
    //    int n_x = xDimension();
    //    int n_y = yDimension();
    //    int indiceGlobal = k* n_x *n_y + j * n_x + i;
    //    return d->values[indiceGlobal];
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

////!
///*!
// *
// */
//double *axlAbstractVolumeDiscrete::getValues(void) const {
//    return d->values;
//}


//!
/*!
 *
 */
void axlAbstractVolumeDiscrete::setValue(double value, int indiceGlobal){

//    if(indiceGlobal < (xDimension() * yDimension() * zDimension())){
//        d->values[indiceGlobal] = value;
//    }

    DTK_DEFAULT_IMPLEMENTATION;
}


//!
/*!
 *
 */
void axlAbstractVolumeDiscrete::setValue(double value,int i, int j, int k){
//    int n_x = xDimension();
//    int n_y = yDimension();
//    int indiceGlobal = k* n_x *n_y + j * n_x + i;
//    if(indiceGlobal < (xDimension() * yDimension() * zDimension())){
//        d->values[indiceGlobal] = value;
//    }

    DTK_DEFAULT_IMPLEMENTATION;
}


////!
///*!
// *
// */
//void axlAbstractVolumeDiscrete::setValues(double *values){
//    d->values = values;
//}


//!
/*!
 *
 */
double axlAbstractVolumeDiscrete::minValue(void) const{

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//!
/*!
 *
 */
double axlAbstractVolumeDiscrete::midValue(void) const{

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;

}


//!
/*!
 *
 */
double axlAbstractVolumeDiscrete::maxValue(void) const{

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;

}



