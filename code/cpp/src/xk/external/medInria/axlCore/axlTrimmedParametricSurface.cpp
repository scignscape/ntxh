#include "axlTrimmedParametricSurface.h"

class axlTrimmedParametricSurfacePrivate
{
public:
	axlAbstractSurface *surface;
	axlCurveOnParamSurface *outer;
	bool OuterIsBoundary;
	QList<axlCurveOnParamSurface *> inner;
};

axlTrimmedParametricSurface::axlTrimmedParametricSurface(QObject *parent) : axlAbstractSurface(), d(new axlTrimmedParametricSurfacePrivate)
{

}

//axlTrimmedParametricSurface::axlTrimmedParametricSurface() : axlAbstractSurface(), d(new axlTrimmedParametricSurfacePrivate)
//{
//
//}

axlTrimmedParametricSurface::axlTrimmedParametricSurface(axlCurveOnParamSurface *outer, QList<axlCurveOnParamSurface *> inner) : axlAbstractSurface(), d(new axlTrimmedParametricSurfacePrivate)
{
	d->outer = outer;
	d->inner = inner;
}

axlTrimmedParametricSurface::~axlTrimmedParametricSurface()
{
	delete d;
	d = NULL;
}

QString axlTrimmedParametricSurface::description(void) const
{
	QString s = "axlTrimmedParametricSurface "; //update
	return s;
}

QString axlTrimmedParametricSurface::identifier(void)  const
{
	return "axlTrimmedParametricSurface";
}
void axlTrimmedParametricSurface::setSurfaceBeTrimmed(axlAbstractSurface *surf)
{
	d->surface = surf;
}

void axlTrimmedParametricSurface::setOuter(axlCurveOnParamSurface *outer)
{
	d->outer = outer;
}

void axlTrimmedParametricSurface::setOuterIsBoundary(bool outerIsBoundaryOrNot)
{
	d->OuterIsBoundary = outerIsBoundaryOrNot;
}

void axlTrimmedParametricSurface::setInner(QList<axlCurveOnParamSurface *> list_inner)
{
	if(!d->inner.isEmpty())
	{
		qDeleteAll(d->inner);
	}
	d->inner.append(list_inner);
}

void axlTrimmedParametricSurface::addInner(axlCurveOnParamSurface *inner)
{
	d->inner.append(inner);
}

void axlTrimmedParametricSurface::addListInner(QList<axlCurveOnParamSurface *> list_inner)
{
	d->inner.append(list_inner);
}

axlCurveOnParamSurface& axlTrimmedParametricSurface::getOuter() const
{
	return *(d->outer);
}

axlCurveOnParamSurface* axlTrimmedParametricSurface::getOuter()
{
	return d->outer;
}

axlAbstractSurfaceParametric& axlTrimmedParametricSurface::getSurface() const
{
	return d->outer->get_main_surface();
}

axlAbstractSurface* axlTrimmedParametricSurface::getSurface()
{
	return d->surface;
}

QList<axlCurveOnParamSurface *>& axlTrimmedParametricSurface::getInner() const
{
	return d->inner;
}

bool axlTrimmedParametricSurface::getouterIsBoundaryOrNot()
{
	return d->OuterIsBoundary;
}
axlCurveOnParamSurface *axlTrimmedParametricSurface::getInner(int id)
{
	return d->inner.value(id);
}

axlTrimmedParametricSurface& axlTrimmedParametricSurface::operator =(const axlTrimmedParametricSurface& other)
{
	d->inner = other.d->inner;
	d->outer = other.d->outer;

	return *this;
}

dtkAbstractData *createaxlTrimmedParametricSurface(void)
{
	return new axlTrimmedParametricSurface();
}

