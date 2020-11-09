/* axlAbstractVolumeBSpline.h ---
 *
 * Author:Anais Ducoffe
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

#ifndef AXLABSTRACTVOLUMEBSPLINE_H
#define AXLABSTRACTVOLUMEBSPLINE_H

#include "axlAbstractVolumeParametric.h"
#include "axlCoreExport.h"

#include <dtkMathSupport/dtkVector3D.h>

class axlAbstractVolumeBSplinePrivate;

class AXLCORE_EXPORT axlAbstractVolumeBSpline : public axlAbstractVolumeParametric
{
    Q_OBJECT

public:
    axlAbstractVolumeBSpline(void);
    virtual ~axlAbstractVolumeBSpline(void);

    using   axlAbstractVolumeParametric::copy;
    virtual axlAbstractVolumeBSpline* copy (void) const;

    virtual int countControlPoints(void) const;
    virtual int countControlPoints_u(void) const;
    virtual int countControlPoints_v(void) const;
    virtual int countControlPoints_w(void) const;

    virtual int knotVectorSize_u(void) const;
    virtual int knotVectorSize_v(void) const;
    virtual int knotVectorSize_w(void) const;

    virtual int order_u(void) const;
    virtual int order_v(void) const;
    virtual int order_w(void) const;

    virtual double   getCoord(int n, int m,int k, int v) const;
    virtual axlPoint getCoef(int n, int m, int k) const;
    virtual axlPoint getCoef(int n) const;

    //Added
    virtual double getWeight(int n, int m, int k) const;

    virtual bool setCoef(int n, int m,int k, int v, double c);
    virtual bool setCoef(int n, int m, int k, double *controlPoint);
    virtual bool setCoef(int n, double *controlPoint);

    virtual double getKnot_u(int n) const;
    virtual double getKnot_v(int n) const;
    virtual double getKnot_w(int n) const;

    virtual void setVolume(int pointsCount_u, int pointsCount_v,int pointsCount_w, int order_u, int order_v,int order_w, int dimension, double *knots_u, double *knots_v, double *knots_w,double *points, bool rational);

    virtual void insertKnot_u(double k);
    virtual void removeKnot_u(double k);

    virtual void insertKnot_v(double k);
    virtual void removeKnot_v(double k);

    virtual void insertKnot_w(double k);
    virtual void removeKnot_w(double k);

    virtual bool rational(void) const;

    virtual QVector<axlPoint *> sampling();

    virtual void gridEvaluator(int num_u, int num_v,int num_w, std::vector<double>& points, std::vector<double>& param_u, std::vector<double>& param_v,std::vector<double>& param_w);

    virtual QString printCoeffs(bool print) const;
    virtual QString printKnotsVector(bool print) const;

    virtual QString description(void) const;

    virtual void updateRcoeff();

    // Scalar values proof of concept
    double scalarValue(double u, double v, double w);
    void setScalarValue(double u, double v, double w, double value);


    //control points' connections definition
    virtual bool connectionsAreDefined(void);
    virtual QList<int> getControlPointConnection(int i); // give all the connections that are still to be made for the ith coefficient.
    virtual void defineControlPointConnection(int i, int j);// i and j represents coefficient numbers.

    virtual void resetControlPointConnections(void);

    //converter method for qjson-rpc communication.
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

    virtual void selectIndex(int i) { emit indexSelected(i); }

signals:
    void updated(void);
    void samplingChanged(void);
    void indexSelected(int);

private:
    axlAbstractVolumeBSplinePrivate *d;
};

#endif
