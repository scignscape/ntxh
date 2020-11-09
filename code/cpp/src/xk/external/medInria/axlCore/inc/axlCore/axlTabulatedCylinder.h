/* axlTabulatedCylinder.h
 * author: Hung NGUYEN Sep, 2014
 *
 */

#ifndef AXL_TABULATED_CYLINDER_H
#define AXL_TABULATED_CYLINDER_H


#include "axlCoreExport.h"
#include "axlPoint.h"
#include "axlAbstractCurve.h"
#include "axlAbstractSurface.h"
#include <QtCore>

/*
 * This class is implemented for the Tabulated Cylinder. A tabulated cylinder is a surface formed by moving a line segment called the generatrix parallel to
 * itself along a curve called the directrix. This curve may be a line, circular arc, conic arc, parametric
 * spline curve, rational B-spline curve, composite curve, or any parametric curve
 */

class axlTabulatedCylinderPrivate;
class AXLCORE_EXPORT axlTabulatedCylinder : public axlAbstractSurface
{
	Q_OBJECT
public:
	axlTabulatedCylinder(QObject *parent = 0);
	~axlTabulatedCylinder();

	axlAbstractCurve  get_directrix() const;
	axlAbstractCurve *get_pt_directrix() const;
	axlPoint& get_ref_generatrix() const;
	axlPoint* get_pt_generatrix();

	void set_generatrix(const axlPoint& vector);
	void set_generatrix(axlPoint *vector);
	void set_directrix(axlAbstractCurve *curve);
	void set_directrix(const axlAbstractCurve& curve);

	virtual QString description(void) const;
    virtual QString identifier(void)  const;

	axlTabulatedCylinder& operator =(const axlTabulatedCylinder& other);

private:
	axlTabulatedCylinderPrivate *d;
};

dtkAbstractData *createaxlTabulatedCylinder(void);

#endif
