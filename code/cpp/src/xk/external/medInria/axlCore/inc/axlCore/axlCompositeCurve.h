/* axlCompositeCurve
 * author: Hung NGUYEN Sep, 2014
 *
 */

#ifndef AXL_CURVE_COMPOSITE_H
#define AXL_CURVE_COMPOSITE_H


#include "axlCoreExport.h"
#include "axlPoint.h"
#include "axlAbstractCurveParametric.h"
#include <QtCore>

/*
 * This class is implemented for the composite curve. The curve type is created by many "basic" curve (segment, arc, BSpline curve,...) inside. These "inside" curve
 * should be connected by the end point. These curve should belongs to the group of parametric curves???? 
 */

class axlCompositeCurvePrivate;
class AXLCORE_EXPORT axlCompositeCurve : public axlAbstractCurveParametric
{
	Q_OBJECT
public:
	axlCompositeCurve(QObject *parent = 0);
	axlCompositeCurve(bool Case,QObject *parent = 0);
	~axlCompositeCurve();

	//There are two cases for Composite curve: 
	// 1st: List of basic curves --- Case = True
	// 2nd: Just two points      --- Case = False 
	// More details: see Composite curve type 102, IGES.
	void setCase(bool Case);
	bool getCase();

	axlAbstractCurve  get_curve_at_id(int id) const;
	axlAbstractCurve *get_pt_curve_at_id(int id) const;
	const axlAbstractCurve& get_ref_curve_at_id(int id) const;

	int count_curve(void) const;

	void insert_list_curves(const QList<axlAbstractCurve>& data_curves);
	void insert_list_curves(const QList<axlAbstractCurve *>& data_curve);
	void insert_curve(axlAbstractCurve *curve, int id_want_inserted);
	void insert_curve(axlAbstractCurve curve, int id_want_inserted);
	void append_curve(const axlAbstractCurve& curve);
	void append_curve(axlAbstractCurve* curve);
	void append_point(const axlPoint& startPoint,const axlPoint& endPoint);
	void append_point(axlPoint *startPoint, axlPoint *endPoint);
	axlPoint *get_start_point();
	axlPoint *get_end_point();

	void remove_last_curve();
	void remove_curve_at_id(int id_want_remove);

	virtual QString description(void) const;
    virtual QString identifier(void)  const;

	axlCompositeCurve& operator =(const axlCompositeCurve& other);

private:
	axlCompositeCurvePrivate *d;
};

dtkAbstractData *createaxlCompositeCurve(void);

#endif
