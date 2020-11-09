/* axlAbstractCurveBSpline.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 16:07:03 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 42
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTCURVEBSPLINE_H
#define AXLABSTRACTCURVEBSPLINE_H

#include "axlAbstractCurveParametric.h"
#include "axlPoint.h"

#include "axlCoreExport.h"

class axlAbstractCurveBSplinePrivate;

class AXLCORE_EXPORT axlAbstractCurveBSpline : public axlAbstractCurveParametric
{
    Q_OBJECT

public:

    typedef QMap<double, axlPoint> Sample;

public:
    axlAbstractCurveBSpline(void);
    virtual ~axlAbstractCurveBSpline(void);

    virtual int countControlPoints(void) const;
    virtual int knotVectorSize(void) const;
    virtual int order(void) const;
    virtual int numCoefs() const;

    virtual bool rational(void) const;

    virtual double startParam(void);
    virtual double endParam(void);

    virtual void setCurve(int pointsCount, int order, int dimension, double *knots, double *points, bool rational);

    virtual axlPoint closestPoint(const axlPoint& pt);
    virtual double closestParameter(const axlPoint& pt);

    virtual Sample sampling(int n);

    virtual void insertKnot(double k);
    virtual void removeKnot(double k);

    virtual axlPoint getCoef(int n) const ;
    virtual bool setCoef(int n, double *controlPoint);
    virtual double getKnot(int n) const;

    virtual QString printCoeffs(bool print) const;
    virtual QString printKnotsVector(bool print) const;

    //Added
    virtual double getWeight(int n) const;

    //Added
    virtual void updateRcoeff();


    virtual QString description(void) const;

    virtual bool connectionsAreDefined(void);
    virtual QList<int> getControlPointConnection(int i);
    virtual void defineControlPointConnection(int i, int j);// i and j represents coefficient numbers.
    virtual void resetControlPointConnections(void);

    //converter method for qjson-rpc communication.
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

    virtual void selectIndex(int i) { emit indexSelected(i); }

signals:
    void updated(void);
    void samplingChanged();
    void indexSelected(int);

private:
    axlAbstractCurveBSplinePrivate *d;
};

#endif
