/** =========================================================================================================
   @class: axlCurveOnParamSurface
   @author: Hung NGUYEN , INRIA 2013 - 2014. 
   
   @definition: 
      From IGES - page 191 (this number is in pdf file, NOT the page in book): 
		- The Curve on a Parametric Surface Entity associates a given curve with a surface and identifies 
		  the curve as lying on the surface. If S is a regular parameterized surface whose domain is a 
		  rectangle defined by 
				D = {( u,v )| u1 <= u <= u2 and v1 <= v <= v2 )}
		  Let B = B(t) be a curve defined by B(t) = (u(t), v(t)) for a <= t <= b, taking its values in D.
		  A curve Cc(t) on the surface S(u, v) is the composition of two mappings, S and B, defined as: 
		              Cc(t) = S o B(t) = (x(u(t),v(t)),y(u(t),v(t)),z(u(t),v(t)))
   @Describe: 
		  A curve on a surface may have been created in one of a number of various ways: 
		  " 1. as the projection on the surface of a given curve in model space in a prescribed way, for
			   example, parallel to a given fixed vector
            2. as the intersection of two given surfaces
            3. by a prescribed functional relation between the surface parameters u and v
            4. by a special curve, such as a geodesic, emanating from a given point in a certain direction,
			   a principal curve (line of curvature) emanating from a certain point, an asymptotic curve
			   emanating from a certain point, an isoparametric curve for a given value, or any other kind of
			   special curve. " (IGES - page 191).
==============================================================================================================

==============================================================================================================
   There are an important variable in this class, way_create_curve. So, be careful when use the methods 
   set_way_create_curve(). Because it will decide what data will be used. See this information below: 

   value of way_create_curve  |                Methods                         |        Variable will be used
              0               |              Unspecified                       |           None of them                  
			  1               |  Projection of a givencurve on the surface     |        sup_dir, sup_curve
			  2               |         Intersection of two surfaces           |           sup_surface
			  3               |           Isoparametric curve                  |         value_u,value_v
==============================================================================================================
Note: 
   - in the column 3, others var will be set NULL.
   - sup_dir = support direction, sup_curve = support curve, sup_surface = support surface.

==============================================================================================================
NOTE: 
   - Read carefully about the definition to understand well.
   - When you want to change the way to describe the curve, I recommend to create the new object. 
   - At the moment (when I write this line), there are no way to exchange between the way of describing the 
     curve. 
==============================================================================================================
*/

#ifndef AXLCURVEONPARAMSURFACE_H
#define AXLCURVEONPARAMSURFACE_H

#include "axlCoreExport.h"
#include "axlAbstractCurveParametric.h"
#include "axlAbstractSurfaceParametric.h"
#include "axlAbstractCurveBSpline.h"

class axlCurveOnParamSurfacePrivate;
class AXLCORE_EXPORT axlCurveOnParamSurface : public axlAbstractCurveParametric
{
	Q_OBJECT
public:
	axlCurveOnParamSurface(QObject *parent = 0);
	~axlCurveOnParamSurface();

	//get the flag to indicate how the curve was created  
	int get_way_create_curve() const;

	//set the flag to indicate how the curve was created
	void set_way_create_curve(int way);

	int get_way_present_curve() const;

	void set_way_present_curve(int way);

	//get the main surface
	axlAbstractSurfaceParametric&  get_main_surface() const;

	//set the main surface 
	void set_main_surface(axlAbstractSurfaceParametric* surface);
	/*void set_main_surface(const axlAbstractSurfaceParametric& surface);*/


	//get the "support" surface 
	axlAbstractSurfaceParametric *get_support_surface() const; // if you are confuse what is support surface, see the top of this file. 
	void set_support_surface(axlAbstractSurfaceParametric *surface);

	//get the "support" curve
	axlAbstractCurve& get_support_curve() const;
	axlAbstractCurve* get_support_curve();
	void set_support_curve(axlAbstractCurve *curve);

	//the direction
	axlPoint& get_direction() const;
	axlPoint* get_direction();
	void set_direction(axlPoint* point);
	void set_direction(const axlPoint& point);

	//curve on parameter domain
	axlAbstractCurve& get_support_curve_param_domain() const;
	axlAbstractCurve* get_support_curve_param_domain();
	void set_support_curve_param_domain(axlAbstractCurve *curve);

	//create curve object by the informations we have in this class. This function HAVE TO  be used AFTER you set all the necessary informations to create the curve.
	//and BEFORE you want to get the "result" curve - the curve you want describe by this class.  
	void CreateCurveObject();


	virtual QString description(void) const;
    virtual QString identifier(void)  const;

	axlCurveOnParamSurface& operator =(const axlCurveOnParamSurface& other);

private:
	axlCurveOnParamSurfacePrivate *d;
};

dtkAbstractData *createaxlCurveOnParamSurface(void);

#endif //AXLCURVEONPARAMSURFACE_H