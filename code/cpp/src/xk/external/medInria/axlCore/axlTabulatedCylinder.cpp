#include "axlTabulatedCylinder.h"
#include <axlCore/axlAbstractData.h>


#include <dtkCoreSupport/dtkGlobal.h>

class axlTabulatedCylinderPrivate
{
public:
	axlPoint *generatrix;
	axlAbstractCurve *directrix;
};
axlTabulatedCylinder::axlTabulatedCylinder(QObject *parent) : axlAbstractSurface(), d(new axlTabulatedCylinderPrivate)
{

};

axlTabulatedCylinder::~axlTabulatedCylinder()
{
	delete d;
	d = NULL;
};

axlAbstractCurve axlTabulatedCylinder::get_directrix() const
{
	return *(d->directrix);
}

axlAbstractCurve* axlTabulatedCylinder::get_pt_directrix() const
{
	return d->directrix;
}

axlPoint& axlTabulatedCylinder::get_ref_generatrix() const
{
	return *(d->generatrix);
}

axlPoint* axlTabulatedCylinder::get_pt_generatrix()
{
	return d->generatrix;
}

void axlTabulatedCylinder::set_generatrix(const axlPoint& vector)
{
	d->generatrix = new axlPoint(vector);
}

void axlTabulatedCylinder::set_generatrix(axlPoint *vector)
{
	d->generatrix = vector;
}

void axlTabulatedCylinder::set_directrix(axlAbstractCurve *curve)
{
	d->directrix = curve; // * = *
}

void axlTabulatedCylinder::set_directrix(const axlAbstractCurve& curve)
{
	d->directrix = new axlAbstractCurve(curve);
}

QString axlTabulatedCylinder::description(void) const
{
	QString s = "axlTabulatedCylinder \n Generatrix: \n" + d->generatrix->description() + "\n Directrix: " + d->directrix->description();
	return s;
}

QString axlTabulatedCylinder::identifier(void)  const
{
	return "axlTabulatedCylinder";
}

axlTabulatedCylinder& axlTabulatedCylinder::operator=(const axlTabulatedCylinder& other)
{
	d->directrix = other.d->directrix;
	d->generatrix = other.d->generatrix;
	return (*this);
}

dtkAbstractData *createaxlTabulatedCylinder(void)
{
	return new axlTabulatedCylinder;
}
