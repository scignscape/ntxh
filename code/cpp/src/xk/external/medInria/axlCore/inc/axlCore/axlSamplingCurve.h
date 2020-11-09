/*
*  @author: Hung NGUYEN - INRIA 2013- 2014
*
*  Just store the function to sampling the curve. It's useful to some class converter in axlCore. 
*
*
*/
#ifndef AXL_SAMPLING_CURVE_CONVERTER_H
#define AXL_SAMPLING_CURVE_CONVERTER_H

#include "axlPoint.h"
#include "axlCircleArc.h"
#include "axlLine.h"
#include "axlAbstractCurve.h"

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

#endif