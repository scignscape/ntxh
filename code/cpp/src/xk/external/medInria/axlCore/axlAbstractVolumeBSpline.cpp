/* axlAbstractVolumeBSpline.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012 - Anais Ducoffe, Inria.
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

#include "axlAbstractVolumeBSpline.h"

#include <dtkCoreSupport/dtkGlobal.h>
#include <QtCore/qmap.h>
#include <cmath>
#include <stdio.h>

class axlAbstractVolumeBSplinePrivate
{
public:
    QMap<axlPoint, double> scalar_values;// key axlPoint, value scalar
    QHash<int, QList<int> >connect;
};

axlAbstractVolumeBSpline::axlAbstractVolumeBSpline(void) : axlAbstractVolumeParametric(), d(new axlAbstractVolumeBSplinePrivate)
{

}

axlAbstractVolumeBSpline::~axlAbstractVolumeBSpline(void)
{
    delete d;
    d = NULL;
}

axlAbstractVolumeBSpline* axlAbstractVolumeBSpline::copy(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return NULL;
}

int axlAbstractVolumeBSpline::countControlPoints(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractVolumeBSpline::countControlPoints_u(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractVolumeBSpline::countControlPoints_v(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractVolumeBSpline::countControlPoints_w(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


int axlAbstractVolumeBSpline::knotVectorSize_u(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractVolumeBSpline::knotVectorSize_v(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractVolumeBSpline::knotVectorSize_w(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


int axlAbstractVolumeBSpline::order_u(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractVolumeBSpline::order_v(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractVolumeBSpline::order_w(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


bool axlAbstractVolumeBSpline::rational(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

void axlAbstractVolumeBSpline::updateRcoeff()
{
    DTK_DEFAULT_IMPLEMENTATION;
}

double axlAbstractVolumeBSpline::getCoord(int n, int m, int k, int v) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

axlPoint axlAbstractVolumeBSpline::getCoef(int n, int m,int k) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return axlPoint();
}

axlPoint axlAbstractVolumeBSpline::getCoef(int n) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(n);
    return axlPoint();
}

double axlAbstractVolumeBSpline::getWeight(int n, int m, int k) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 1.0;
}

bool axlAbstractVolumeBSpline::setCoef(int n, int m, int k, int v, double c)
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

bool axlAbstractVolumeBSpline::setCoef(int n, int m,int k, double *controlPoint)
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

bool axlAbstractVolumeBSpline::setCoef(int n, double *controlPoint)
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

double axlAbstractVolumeBSpline::getKnot_u(int n) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

double axlAbstractVolumeBSpline::getKnot_v(int n) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

double axlAbstractVolumeBSpline::getKnot_w(int n) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


QVector<axlPoint *> axlAbstractVolumeBSpline::sampling()
{
    DTK_DEFAULT_IMPLEMENTATION;
    QVector<axlPoint *> qVect;
    return qVect;
}

void axlAbstractVolumeBSpline::gridEvaluator(int num_u, int num_v, int num_w, std::vector<double>& points,std::vector<double>& param_u, std::vector<double> &param_v, std::vector<double> &param_w)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractVolumeBSpline::setVolume(int pointsCount_u, int pointsCount_v,int pointsCount_w, int order_u, int order_v,int order_w, int dimension, double *knots_u, double *knots_v, double *knots_w,double *points, bool rational)
{
    DTK_DEFAULT_IMPLEMENTATION;
}


void axlAbstractVolumeBSpline::insertKnot_u(double k)
{
    Q_UNUSED(k);
}

void axlAbstractVolumeBSpline::removeKnot_u(double k)
{
    Q_UNUSED(k);
}

void axlAbstractVolumeBSpline::insertKnot_v(double k)
{
    Q_UNUSED(k);
}

void axlAbstractVolumeBSpline::removeKnot_v(double k)
{
    Q_UNUSED(k);
}

void axlAbstractVolumeBSpline::insertKnot_w(double k)
{
    Q_UNUSED(k);
}

void axlAbstractVolumeBSpline::removeKnot_w(double k)
{
    Q_UNUSED(k);
}

QString axlAbstractVolumeBSpline::printCoeffs(bool print) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

QString axlAbstractVolumeBSpline::printKnotsVector(bool print) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

QString axlAbstractVolumeBSpline::description(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

double axlAbstractVolumeBSpline::scalarValue(double u, double v, double w)
{
    axlPoint point;
    point.setCoordinates(u,v,w);
    return d->scalar_values.value(point);
}


void axlAbstractVolumeBSpline::setScalarValue(double u, double v,double w, double value)
{
    axlPoint point;
    point.setCoordinates(u,v,w);
    d->scalar_values.insert(point, value);
}


//! Return true if control points connections were defined by developers. False if there are default connections visualization.
/*!
 *
 */
bool axlAbstractVolumeBSpline::connectionsAreDefined(void){
    return !d->connect.isEmpty();
}

//! Removes all control point connections.
/*!
 *
 */
void axlAbstractVolumeBSpline::resetControlPointConnections(void)
{
    d->connect.clear();
}


//! The list returned contains all indices of coefficients that are still to be connected to the ith coefficient.
/*!
 *
 */
QList<int> axlAbstractVolumeBSpline::getControlPointConnection(int i){
    return d->connect.value(i);
}


//! Define connection between the ith and the jth coefficient.
/*!
 *
 */
void axlAbstractVolumeBSpline::defineControlPointConnection(int i, int j){
    if(i==j){
        qDebug() << "The two indices must be different.";
    }else{
        int mini = std::min(i,j);
        int maxi = std::max(i,j);

        if(d->connect.keys().contains(mini)){
            QList<int> list = d->connect.value(mini);

            if(!list.contains(maxi) ){
                list << maxi;
                d->connect.insert(mini, list);
            }
        }else{
            QList<int> list;
            list << maxi;
            d->connect.insert(mini,list);
        }
    }
}


QVariantList axlAbstractVolumeBSpline::convertDataToQVariant(void) const{
    QVariantList list;
    list.append(identifier());
    QVariant nu = QVariant::fromValue(countControlPoints_u());
    list.append(nu);
    QVariant nv = QVariant::fromValue(countControlPoints_v());
    list.append(nv);
    QVariant nw = QVariant::fromValue(countControlPoints_w());
    list.append(nw);
    QVariant orderu = QVariant::fromValue(order_u());
    list.append(orderu);
    QVariant orderv = QVariant::fromValue(order_v());
    list.append(orderv);
    QVariant orderw = QVariant::fromValue(order_w());
    list.append(orderw);
    QVariant dimension = QVariant::fromValue(3);
    list.append(dimension);
    //append knots_u
    for(int i = 0; i < nu.toInt()+ order_u();i++){
        list.append(getKnot_u(i+1));
    }
    //append knots_v
    for(int i = 0; i < nv.toInt()+ order_v();i++){
        list.append(getKnot_v(i+1));
    }
    //append knots_w
    for(int i = 0; i < nw.toInt()+ order_w();i++){
        list.append(getKnot_w(i+1));
    }
    //append control points table
    for(int i = 0; i < nu.toInt()*nv.toInt()*nw.toInt();i++){
        list.append(getCoef(i+1).convertDataToQVariant());
    }
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;
}

int axlAbstractVolumeBSpline::convertQVariantToData(const QVariantList& data){
    int nu = data.at(1).toInt();
    int nv = data.at(2).toInt();
    int nw = data.at(3).toInt();
    int orderu = data.at(4).toInt();
    int orderv = data.at(5).toInt();
    int orderw = data.at(6).toInt();
    int dimension = data.at(7).toInt();
    //append knots_u
    double *knotsU = new double[nu+orderu];
    for(int i = 0; i < nu+orderu;i++){
        knotsU[i] = data.at(i+8).toDouble();
        //insertKnot_u(data.at(i+7).toDouble());
    }
    //append knots_v
    double *knotsV = new double[nv+orderv];
    for(int i = 0; i < nv+orderv;i++){
        knotsV[i] = data.at(i+8 +nu+orderu).toDouble();
        //insertKnot_v(data.at(i+8+nKu).toDouble());
    }
    //append knots_w
    double *knotsW = new double[nw+orderw];
    for(int i = 0; i < nw+orderw;i++){
        knotsW[i] = data.at(i+8 +nu+orderu +nv+orderv).toDouble();
        //insertKnot_v(data.at(i+8+nKu).toDouble());
    }
    //append control points table
    int indice = 8 +nu+orderu +nv+orderv +nw+orderw;
    double *CP = new double[3*nu*nv*nw];
    for(int i = 0; i < nu*nv*nw;i++){
        QVariantList list;
        list.append(data.at(indice));
        list.append(data.at(indice+1));
        list.append(data.at(indice+2));
        list.append(data.at(indice+3));
        list.append(data.at(indice+4));
        axlPoint* point = new axlPoint();
        point->convertQVariantToData(list);
        //double *controlPoint = point->coordinates();
        CP[3*i] = point->x();
        CP[3*i+1] = point->y();
        CP[3*i+2] = point->z();
        //setCoef(i,controlPoint);
        indice = indice+5;
    }
    setVolume(nu,nv,nw ,orderu,orderv,orderw,dimension,knotsU, knotsV,knotsW,CP, false);// rational=false B-spline volume
    setObjectName(data.last().toString());
    return 1;
}





