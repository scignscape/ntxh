/* axlAbstractSurfaceBSpline.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Mar 29 11:36:56 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 46
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTSURFACEBSPLINE_H
#define AXLABSTRACTSURFACEBSPLINE_H

#include "axlAbstractSurfaceParametric.h"
#include "axlCoreExport.h"

#include <dtkMathSupport/dtkVector3D.h>

class axlMesh;

class axlAbstractSurfaceBSplinePrivate;

class AXLCORE_EXPORT axlAbstractSurfaceBSpline : public axlAbstractSurfaceParametric
{
    Q_OBJECT

public:
    axlAbstractSurfaceBSpline(void);
    virtual ~axlAbstractSurfaceBSpline(void);

    using   axlAbstractSurfaceParametric::copy;
    virtual axlAbstractSurfaceBSpline* copy (void) const;

    virtual int countControlPoints(void) const;
    virtual int countControlPoints_u(void) const;
    virtual int countControlPoints_v(void) const;

    virtual int knotVectorSize_u(void) const;
    virtual int knotVectorSize_v(void) const;

    virtual int order_u(void) const;
    virtual int order_v(void) const;

    virtual double   getCoord(int n, int m, int v) const;
    virtual axlPoint getCoef(int n, int m) const;
    virtual axlPoint getCoef(int n ) const;

    //---Added
    virtual double getWeight(int n, int m) const;

    virtual bool setCoef(int n, int m, int v, double c);
    virtual bool setCoef(int n, int m, double *controlPoint);
    virtual bool setCoef(int n, double *controlPoint);

    virtual double getKnot_u(int n) const;
    virtual double getKnot_v(int n) const;

    virtual void setSurface(int pointsCount_u, int pointsCount_v, int order_u, int order_v, int dimension, double *knots_u, double *knots_v, double *points, bool rational);

    //---Added
    virtual void updateRcoeff();

    virtual void insertKnot_u(double k);
    virtual void removeKnot_u(double k);

    virtual void insertKnot_v(double k);
    virtual void removeKnot_v(double k);

    virtual bool rational(void) const;

    virtual QVector<axlPoint *> sampling();

    virtual void gridEvaluator(int num_u, int num_v, std::vector<double>& points, std::vector<double>& param_u, std::vector<double>& param_v);

    virtual QString printCoeffs(bool print) const;
    virtual QString printKnotsVector(bool print) const;

    virtual QString description(void) const;

    //converter method for qjson-rpc communication.
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);


    // Scalar values proof of concept
    double scalarValue(double u, double v);
    void setScalarValue(double u, double v, double value);

    //control points ' connections definition
    virtual bool connectionsAreDefined(void);

    virtual QList<int> getControlPointConnection(int i); // give all the connections that are still to be made for the ith coefficient.
    virtual void defineControlPointConnection(int i, int j);// i and j represents coefficient numbers.

    virtual void resetControlPointConnections(void);

    virtual void selectIndex(int i) { emit indexSelected(i); }

signals:
    void updated(void);
    void samplingChanged(void);
    void edgeSelected(int numEdge, int previous, int n);
    void indexSelected(int i);
    void modifiedControlPoints(void);

private:
    axlAbstractSurfaceBSplinePrivate *d;
};

#endif
