/*
==================================================================================================================
   axlTrimmedParametricSurface.h
   @author: Hung NGUYEN, INRIA, 2013 - 2014
   
   @definition (from USPRO - IGES): 
		"A simple closed curve in the Euclidean plane divides the plane into two disjoint open connected
		components, one bounded and one unbounded. The bounded component is called the interior region
		to the curve (herein called “interior” and the unbounded component is called the exterior region to
		the curve (herein called “exterior”).
		The domain of the trimmed surface is defined as the common region of the interior of the outer
		boundary and the exterior of each of the inner boundaries and includes the boundary curves. Note
		that the trimmed surface has the same mapping S(u, v) as the original (untrimmed surface) but a
		different domain. The curves that delineate either the outer or the inner boundary of the trimmed
		surface are curves on the surface S, and are to be exchanged by means of the Curve on a Parametric
		Surface."

		So, a trimmed surface is defined by the outer boundary (only one) and the inner boundaries on the surface
		S. 
===================================================================================================================
*/

#ifndef AXLTRIMMEDPARAMETRICSURFACE_H
#define AXLTRIMMEDPARAMETRICSURFACE_H

#include "axlCoreExport.h"
#include "axlCurveOnParamSurface.h"
#include "axlAbstractSurfaceBSpline.h"

class axlTrimmedParametricSurfacePrivate;
class AXLCORE_EXPORT axlTrimmedParametricSurface : public axlAbstractSurface
{
    	Q_OBJECT
public:
	axlTrimmedParametricSurface(QObject *parent = 0);
	/*axlTrimmedParametricSurface();*/
	axlTrimmedParametricSurface(axlCurveOnParamSurface *outer, QList<axlCurveOnParamSurface *> inner);
	~axlTrimmedParametricSurface();

	void setSurfaceBeTrimmed(axlAbstractSurface *surf);
	void setOuterIsBoundary(bool outerIsBoundaryOrNot);
	void setOuter(axlCurveOnParamSurface *outer);
	void setInner(QList<axlCurveOnParamSurface *> list_inner);
	void addInner(axlCurveOnParamSurface *inner);
	void addListInner(QList<axlCurveOnParamSurface *> list_inner);

	axlCurveOnParamSurface& getOuter() const;
	axlCurveOnParamSurface* getOuter();
	axlAbstractSurfaceParametric& getSurface() const;
	axlAbstractSurface* getSurface();
	bool getouterIsBoundaryOrNot();

	QList<axlCurveOnParamSurface *>& getInner() const;
	axlCurveOnParamSurface *getInner(int id);

	virtual QString description(void) const;
    virtual QString identifier(void)  const;

	axlTrimmedParametricSurface& operator =(const axlTrimmedParametricSurface& other);
private:
	axlTrimmedParametricSurfacePrivate *d;
};

dtkAbstractData *createaxlTrimmedParametricSurface(void);
#endif //AXLTRIMMEDPARAMETRICSURFACE_H