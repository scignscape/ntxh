#ifndef AXL_COMPOSITE_CURVE_H
#define AXL_COMPOSITE_CURVE_H

#include "axlLine.h"
#include "axlPoint.h"
#include "axlCircleArc.h"
#include "axlAbstractCurveBSpline.h"
#include "axlCompositeCurve.h"
#include <axlCore/axlAbstractDataConverter.h> 

class axlCompositeCurveConverterPrivate;

class AXLCORE_EXPORT axlCompositeCurveConverter : public axlAbstractDataConverter
{
    Q_OBJECT
public:
	 axlCompositeCurveConverter(void);
	 ~axlCompositeCurveConverter(void);

	 QString  description (void) const;
     QString  identifier  (void) const;

     QStringList fromTypes(void) const;
     QString       toType (void) const;

	 static bool registered(void);
	 void setData(dtkAbstractData *data);
public slots:
    axlMesh *toMesh(void);

private:
    axlCompositeCurveConverterPrivate *d;
	static void addMesh2Mesh(axlMesh& mother_mesh, axlMesh *child_mesh);

};

//===========================================================================================================================

/*
   The functions support to create Mesh
*/
void normalize(axlPoint& point);
double angle(axlPoint vCompute, axlPoint vRef, axlPoint normal);
double angleOfArc(const axlCircleArc *arc);
axlPoint normalCCWArc(const axlCircleArc& arc);
axlPoint *rotatePoint(double a, double b, double c, double x, double y,
	                  double z, double u, double v, double w, double alpha);
axlPoint* RotatePoint(axlPoint a,axlPoint x,axlPoint u, double alpha);
axlPoint* RotatePoint(axlLine *line,axlPoint *x, double alpha);
QList<axlPoint *> Sampling(axlAbstractCurve *curve);

//============================================================================================================================

dtkAbstractDataConverter *createaxlCompositeCurveConverter(void);

#endif