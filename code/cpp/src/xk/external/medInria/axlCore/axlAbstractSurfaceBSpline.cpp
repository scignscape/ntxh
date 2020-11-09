/* axlAbstractSurfaceBSpline.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Apr  8 13:45:39 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 31
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractSurfaceBSpline.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <cmath>
#include <stdio.h>

class axlAbstractSurfaceBSplinePrivate
{
public:
    QMap<QPair<double, double>, double> scalar_values;
    QHash<int, QList<int> > connect;
};

axlAbstractSurfaceBSpline::axlAbstractSurfaceBSpline(void) : axlAbstractSurfaceParametric(), d(new axlAbstractSurfaceBSplinePrivate)
{

}

axlAbstractSurfaceBSpline::~axlAbstractSurfaceBSpline(void)
{
    delete d;
    d = NULL;
}

axlAbstractSurfaceBSpline* axlAbstractSurfaceBSpline::copy(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return NULL;
}

int axlAbstractSurfaceBSpline::countControlPoints(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractSurfaceBSpline::countControlPoints_u(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractSurfaceBSpline::countControlPoints_v(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


int axlAbstractSurfaceBSpline::knotVectorSize_u(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractSurfaceBSpline::knotVectorSize_v(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


int axlAbstractSurfaceBSpline::order_u(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlAbstractSurfaceBSpline::order_v(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


bool axlAbstractSurfaceBSpline::rational(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

double axlAbstractSurfaceBSpline::getCoord(int n, int m, int v) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

axlPoint axlAbstractSurfaceBSpline::getCoef(int n, int m) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return axlPoint();
}

axlPoint axlAbstractSurfaceBSpline::getCoef(int n) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(n);
    return axlPoint();
}

double axlAbstractSurfaceBSpline::getWeight(int n, int m) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 1.0;
}

bool axlAbstractSurfaceBSpline::setCoef(int n, int m, int v, double c)
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

bool axlAbstractSurfaceBSpline::setCoef(int n, int m, double *controlPoint)
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

bool axlAbstractSurfaceBSpline::setCoef(int n, double *controlPoint)
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

double axlAbstractSurfaceBSpline::getKnot_u(int n) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

double axlAbstractSurfaceBSpline::getKnot_v(int n) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


QVector<axlPoint *> axlAbstractSurfaceBSpline::sampling()
{
    DTK_DEFAULT_IMPLEMENTATION;
    QVector<axlPoint *> qVect;
    return qVect;
}

void axlAbstractSurfaceBSpline::gridEvaluator(int num_u, int num_v, std::vector<double>& points, std::vector<double>& param_u,std::vector<double>& param_v)
{
    DTK_DEFAULT_IMPLEMENTATION;
}
/**
 * @brief axlAbstractSurfaceBSpline::setSurface
 * @param n_u number of control points in the u direction
 * @param n_v number of control points in the v direction
 * @param order_u degree+1 for the u parameter
 * @param order_v degree+1 for the v parameter
 * @param dimension the number of coordinates of the control points (usually 3)
 * @param knots_u the sequence of knots in the u direction
 * @param knots_v the sequence of knots in the v direction
 * @param points the sequence of coordinates of the control points x0 y0 z0 x1 y1 z1 ....
 *  The control points are given row by row as
 * \f[ P_{0,0}, P_{1,0},  \ldots , P_{n_u, n_v}, \f]
 * where \f$ P_{i,j} \f$ is represented as @c dimension doubles.
 *  The points of index (0..n_u,0) correspond to the isoparametric curve v=v_min,
 *  the points of index (0..n_u,n_v) correspond to the isoparametric curve v=v_max,
 *  the points of index (0, 0..n_v) correspond to the isoparametric curve u=u_min,
 *  the points of index (n_u, 0..n_v) correspond to the isoparametric curve u=u_max,
 *  where u_min,u_max, v_min, v_max are respectively the min and max values of knot_u, knot_v.
 */
void axlAbstractSurfaceBSpline::setSurface(int n_u, int n_v, int order_u, int order_v, int dimension, double *knots_u, double *knots_v, double *points, bool rational)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

//Added
void axlAbstractSurfaceBSpline::updateRcoeff()
{
    DTK_DEFAULT_IMPLEMENTATION;
}


void axlAbstractSurfaceBSpline::insertKnot_u(double k)
{
    Q_UNUSED(k);
}

void axlAbstractSurfaceBSpline::removeKnot_u(double k)
{
    Q_UNUSED(k);
}

void axlAbstractSurfaceBSpline::insertKnot_v(double k)
{
    Q_UNUSED(k);
}

void axlAbstractSurfaceBSpline::removeKnot_v(double k)
{
    Q_UNUSED(k);
}

QString axlAbstractSurfaceBSpline::printCoeffs(bool print) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

QString axlAbstractSurfaceBSpline::printKnotsVector(bool print) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

QString axlAbstractSurfaceBSpline::description(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

double axlAbstractSurfaceBSpline::scalarValue(double u, double v)
{
    return d->scalar_values.value(qMakePair<double, double>(u, v));
}

void axlAbstractSurfaceBSpline::setScalarValue(double u, double v, double value)
{
    d->scalar_values.insert(qMakePair<double, double>(u, v), value);
}

//! Return true if control points connections were defined by developers. False if there are default connections visualization.
/*!
 *
 */
bool axlAbstractSurfaceBSpline::connectionsAreDefined(void){
    return !d->connect.isEmpty();
}

//! Removes all control point connections.
/*!
 *
 */
void axlAbstractSurfaceBSpline::resetControlPointConnections(void)
{
    d->connect.clear();
}

//! The list returned contains all indices of coefficients that are still to be connected to the ith coefficient.
/*!
 *
 */
QList<int> axlAbstractSurfaceBSpline::getControlPointConnection(int i){
    return d->connect.value(i);
}


//! Define connection between the ith and the jth coefficient.
/*!
 *
 */
void axlAbstractSurfaceBSpline::defineControlPointConnection(int i, int j){
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



// A BSpline surface is described with nu, nv,orderu,orderv,dimension,knotsu,knotsv and controlPoints.
QVariantList axlAbstractSurfaceBSpline::convertDataToQVariant(void) const{
    dtkWarn()<<"axlAbstractSurfaceBSpline::convertDataToQVariant not working for rational";
    QVariantList list;
    list.append(identifier());
    QVariant nu = QVariant::fromValue(countControlPoints_u());
    list.append(nu);
    QVariant nv = QVariant::fromValue(countControlPoints_v());
    list.append(nv);
    QVariant orderu = QVariant::fromValue(order_u());
    list.append(orderu);
    QVariant orderv = QVariant::fromValue(order_v());
    list.append(orderv);
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
    //append control points table
    for(int i = 0; i < nu.toInt()*nv.toInt();i++){
        list.append(getCoef(i+1).convertDataToQVariant());
    }
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;
}

int axlAbstractSurfaceBSpline::convertQVariantToData(const QVariantList& data){
    dtkWarn()<<"axlAbstractSurfaceBSpline::convertQVariantToData not working for rational";
    int nu = data.at(1).toInt();
    int nv = data.at(2).toInt();
    int orderu = data.at(3).toInt();
    int orderv = data.at(4).toInt();
    int dimension = data.at(5).toInt();

    //append knots_u
    double *knotsU = new double[nu+orderu];
    for(int i = 0; i < nu+orderu;i++){
        knotsU[i] = data.at(i+6).toDouble();
        //insertKnot_u(data.at(i+7).toDouble());
    }
    //append knots_v
    double *knotsV = new double[nv+orderv];
    for(int i = 0; i < nv+orderv;i++){
        knotsV[i] = data.at(i+6 +nu+orderu).toDouble();
        //insertKnot_v(data.at(i+8+nKu).toDouble());
    }
    //append control points table
    int indice = 6 +nu+orderu +nv+orderv;
    double *CP = new double[3*nu*nv];
    for(int i = 0; i < nu*nv;i++){
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
    setSurface(nu,nv ,orderu,orderv,dimension,knotsU, knotsV,CP,false);
    QString name = data.last().toString();
    setObjectName(name);
    return 1;
}
