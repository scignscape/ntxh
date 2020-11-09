#include "axlCurveOnParamSurface.h"

class axlCurveOnParamSurfacePrivate
{
public:
	int                           idWayCreateCurve; // id to show how to create the curve (more information in header file)
	int                           idWayPresentSendingSystem;//read more about this variable in header file if you're confused about it.    
	axlAbstractSurfaceParametric *mainSurf;//the surface the main curve lies on, usually is BSpline Surface.

	axlAbstractSurfaceParametric *supSurf; // the support surface to create the curve by finding intersection, usually is BSpline Surface.

	axlPoint                     *supDir;  // the support direction
	axlAbstractCurve             *supCurve;// the curve support to create the curve by finding intersection of line go through the point 
										   // in this curve with the supDir direction.
	axlAbstractCurve             *supCurveParamDomain; //the curve on the parameter domain to helping find the curve in the real space.

	double                        value_u; // isoparametric curve
	double                        value_v; // isoparametric curve

	//==============================================================================
	//Curve object you want to describe

	   // form 1: curve C
		axlAbstractCurveBSpline *curve;
	   
	   // form 2: S o B
	   // get information from the others methods. 
};

axlCurveOnParamSurface::axlCurveOnParamSurface(QObject *parent) : axlAbstractCurveParametric(), d(new axlCurveOnParamSurfacePrivate)
{
	d->idWayCreateCurve = 0;
	d->idWayPresentSendingSystem = 0;
	d->mainSurf = NULL;
	d->supCurve = NULL;
	d->supCurveParamDomain = NULL;
	d->supDir = NULL;
	d->supSurf = NULL;
	d->value_u = 0.0;
	d->value_v = 0.0;
	d->curve = NULL;
}

axlCurveOnParamSurface::~axlCurveOnParamSurface()
{
	delete d;
	d = NULL;
}

//get
int axlCurveOnParamSurface::get_way_create_curve() const
{
	return d->idWayCreateCurve;
}

int axlCurveOnParamSurface::get_way_present_curve() const
{
	return d->idWayPresentSendingSystem;
}

axlPoint& axlCurveOnParamSurface::get_direction() const
{
	return *(d->supDir);
}

axlAbstractSurfaceParametric& axlCurveOnParamSurface::get_main_surface() const
{
	return *(d->mainSurf);
}

axlAbstractCurve& axlCurveOnParamSurface::get_support_curve() const
{
	return *(d->supCurve);
}

axlAbstractCurve* axlCurveOnParamSurface::get_support_curve()
{
	return d->supCurve;
}

axlAbstractCurve* axlCurveOnParamSurface::get_support_curve_param_domain()
{
	return d->supCurveParamDomain;
}

axlAbstractCurve& axlCurveOnParamSurface::get_support_curve_param_domain() const
{
	return *(d->supCurveParamDomain);
}
//get curve result by this class
void axlCurveOnParamSurface::CreateCurveObject()
{
	//need interface. 

	/*if(d->idWayCreateCurve == 2)
	{
		if(d->mainSurf!=NULL&&d->supSurf!=NULL)
		{
			d->
		}
	}*/
}

//set
void axlCurveOnParamSurface::set_way_create_curve(int way)
{
	d->idWayCreateCurve = way;
}

void axlCurveOnParamSurface::set_way_present_curve(int way)
{
	d->idWayPresentSendingSystem = way;
}

void axlCurveOnParamSurface::set_main_surface(axlAbstractSurfaceParametric* surface)
{
	d->mainSurf = surface;
}

void axlCurveOnParamSurface::set_direction(axlPoint *point)
{
	d->supDir = point;
}

void axlCurveOnParamSurface::set_direction(const axlPoint& point)
{
	d->supDir = new axlPoint(point);
}

void axlCurveOnParamSurface::set_support_curve(axlAbstractCurve *curve)
{
	d->supCurve = curve;
}

void axlCurveOnParamSurface::set_support_curve_param_domain(axlAbstractCurve *curve)
{
	d->supCurveParamDomain = curve;
}

void axlCurveOnParamSurface::set_support_surface(axlAbstractSurfaceParametric *surface)
{
	d->supSurf = surface;
}

//operator = 
axlCurveOnParamSurface& axlCurveOnParamSurface::operator=(const axlCurveOnParamSurface& other)
{
	d->idWayCreateCurve          = other.d->idWayCreateCurve;
	d->idWayPresentSendingSystem = other.d->idWayPresentSendingSystem;
	d->mainSurf                  = other.d->mainSurf;
	d->supCurve                  = other.d->supCurve;
	d->supCurveParamDomain       = other.d->supCurveParamDomain;
	d->supDir                    = other.d->supDir;
	d->supSurf                   = other.d->supSurf;
	d->value_u                   = other.d->value_u;
	d->value_v                   = other.d->value_v;
	return *this;
}



QString axlCurveOnParamSurface::description(void) const
{
	QString s = "axlCurveOnParamSurface "; //update
	return s;
}

QString axlCurveOnParamSurface::identifier(void)  const
{
	return "axlCurveOnParamSurface";
}

dtkAbstractData *createaxlCurveOnParamSurface(void)
{
	return new axlCurveOnParamSurface;
}







