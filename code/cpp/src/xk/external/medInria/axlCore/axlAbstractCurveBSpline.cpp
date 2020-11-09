/* axlAbstractCurveBSpline.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:42:00 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 24
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractCurveBSpline.h"

#include <dtkCoreSupport/dtkGlobal.h>
#include <qhash.h>
#include <cmath>
#include <stdio.h>

typedef QMap<double, axlPoint> Sample;

class axlPoint;

class axlAbstractCurveBSplinePrivate
{
public:
    QHash<int, QList<int> > connect;
};

axlAbstractCurveBSpline::axlAbstractCurveBSpline(void) : axlAbstractCurveParametric(), d(new axlAbstractCurveBSplinePrivate)
{

}

axlAbstractCurveBSpline::~axlAbstractCurveBSpline(void)
{
    delete d;

    d = NULL;
}

int axlAbstractCurveBSpline::countControlPoints(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

int axlAbstractCurveBSpline::knotVectorSize(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

int axlAbstractCurveBSpline::order(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

int axlAbstractCurveBSpline::numCoefs() const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}


bool axlAbstractCurveBSpline::rational(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}
double axlAbstractCurveBSpline::startParam(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

double axlAbstractCurveBSpline::endParam(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 1;
}

void axlAbstractCurveBSpline::setCurve(int pointsCount, int order, int dimension, double *knots, double *points, bool rational)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

axlPoint axlAbstractCurveBSpline::closestPoint(const axlPoint& pt)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return axlPoint();
}

double axlAbstractCurveBSpline::closestParameter(const axlPoint& pt)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}


Sample axlAbstractCurveBSpline::sampling(int n)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return Sample();
}

axlPoint axlAbstractCurveBSpline::getCoef(int n) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return axlPoint();
}

bool axlAbstractCurveBSpline::setCoef(int n, double *controlPoint)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

//Added
double axlAbstractCurveBSpline::getWeight(int n) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 1.0;
}

//Added
void axlAbstractCurveBSpline::updateRcoeff()
{
    DTK_DEFAULT_IMPLEMENTATION;
}

double axlAbstractCurveBSpline::getKnot(int n) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

void axlAbstractCurveBSpline::insertKnot(double k)
{
    Q_UNUSED(k);
}

void axlAbstractCurveBSpline::removeKnot(double k)
{
    Q_UNUSED(k);
}

QString axlAbstractCurveBSpline::printCoeffs(bool print) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return "";
}

QString axlAbstractCurveBSpline::printKnotsVector(bool print) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return "";
}

QString axlAbstractCurveBSpline::description(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return "";
}

//! Return true if control points connections were defined by developers. False if there are default connections visualization.
/*!
 *
 */
bool axlAbstractCurveBSpline::connectionsAreDefined(void){
    return !d->connect.isEmpty();
}

//! Removes all control point connections.
/*!
 *
 */
void axlAbstractCurveBSpline::resetControlPointConnections(void)
{
    d->connect.clear();
}

//! The list returned contains all indices of coefficients that are still to be connected to the ith coefficient.
/*!
 *
 */
QList<int> axlAbstractCurveBSpline::getControlPointConnection(int i){
    return d->connect.value(i);
}


//! Define connection between the ith and the jth coefficient.
/*!
 *
 */
void axlAbstractCurveBSpline::defineControlPointConnection(int i, int j){
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

QVariantList axlAbstractCurveBSpline::convertDataToQVariant(void) const{
    QVariantList list;
    list.append(identifier());
    QVariant n = QVariant::fromValue(countControlPoints());
    list.append(n);
    QVariant ord = QVariant::fromValue(order());
    list.append(ord);
    QVariant dimension = QVariant::fromValue(3);
    list.append(dimension);
    //append knots
    for(int i = 0; i < n.toInt()+ order();i++){
        list.append(getKnot(i+1));
    }
    //append control points table
    for(int i = 0; i < n.toInt();i++){
        list.append(getCoef(i+1).convertDataToQVariant());
    }
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;
}

int axlAbstractCurveBSpline::convertQVariantToData(const QVariantList& data){
    int n = data.at(1).toInt();
    int order = data.at(2).toInt();
    int dimension = data.at(3).toInt();
    //append knots
    double *knots = new double[n+order];
    for(int i = 0; i < n+order;i++){
        knots[i] = data.at(i+4).toDouble();
        //insertKnot_u(data.at(i+7).toDouble());
    }
    //append control points table
    int indice = 4 +n+order;
    double *CP = new double[3*n];
    for(int i = 0; i < n;i++){
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
    setCurve(n ,order,dimension,knots,CP, false);// rational=false, this curve is a bspline curve (non-rational)
    QString name = data.last().toString();
    setObjectName(name);
    return 1;
}
