#include "axlCompositeCurve.h"
#include <axlCore/axlAbstractData.h>

#include <dtkCoreSupport/dtkGlobal.h>

class axlCompositeCurvePrivate
{
public:
	QList<axlAbstractCurve *> data; //data for curve
	QPair<axlPoint *, axlPoint *> ends;//data for two end points.
	bool tag;// tag : when tag == true -> just use "data", else use "ends". More details in headers file.
	//this tag wil help us do not mix between two ways of Composite curve.
};
axlCompositeCurve::axlCompositeCurve(QObject *parent) : axlAbstractCurveParametric(), d(new axlCompositeCurvePrivate)
{

};

axlCompositeCurve::axlCompositeCurve(bool Case,QObject *parent) : axlAbstractCurveParametric(), d(new axlCompositeCurvePrivate)
{
    d->tag = Case;
};

axlCompositeCurve::~axlCompositeCurve()
{
	delete d;
	d = NULL;
};

void axlCompositeCurve::setCase(bool Case)
{
	d->tag = Case;
}

bool axlCompositeCurve::getCase()
{
	return d->tag;
}
axlAbstractCurve* axlCompositeCurve::get_pt_curve_at_id(int id) const
{
	if(d->tag)
		return d->data.value(id);
	else
		return NULL;
}

int axlCompositeCurve::count_curve() const
{
	return d->data.size();
}

void axlCompositeCurve::insert_list_curves(const QList<axlAbstractCurve *>& data_curves)
{
	if(d->tag)
		d->data.append(data_curves);
}

void axlCompositeCurve::insert_list_curves(const QList<axlAbstractCurve>& data_curve)
{
	if(d->tag)
	{
		for(int i = 0; i<data_curve.size(); i++)
		{
			d->data.append(new axlAbstractCurve(data_curve.value(i)));
		}
	}
}

void axlCompositeCurve::insert_curve(axlAbstractCurve *curve, int id_want_inserted)
{
	if(d->tag)
	{
	    d->data.insert(id_want_inserted,curve);
	}
}

void axlCompositeCurve::insert_curve(axlAbstractCurve curve, int id_want_inserted)
{
	if(d->tag)
	{
	    d->data.insert(id_want_inserted,new axlAbstractCurve(curve));
	}
}

void axlCompositeCurve::append_curve(const axlAbstractCurve& curve)
{
	if(d->tag)
	{
	   d->data.append(new axlAbstractCurve(curve));
	}
}
void axlCompositeCurve::append_curve(axlAbstractCurve* curve)
{
	if(d->tag)
	{
	   d->data.append(curve);
	}
}

void axlCompositeCurve::append_point(const axlPoint& startPoint,const axlPoint& endPoint)
{
	if(!d->tag)
	{
		d->ends.first = new axlPoint(startPoint);
		d->ends.second = new axlPoint(endPoint);
    }
}
void axlCompositeCurve::append_point(axlPoint *startPoint, axlPoint *endPoint)
{
	if(!d->tag)
	{
		d->ends.first = startPoint;
		d->ends.second = endPoint;
    }
}

axlPoint *axlCompositeCurve::get_start_point()
{
	return d->ends.first;
}
axlPoint *axlCompositeCurve::get_end_point()
{
	return d->ends.second;
}
void axlCompositeCurve::remove_last_curve()
{
   if(d->tag)
	 d->data.removeLast();
}

void axlCompositeCurve::remove_curve_at_id(int id_want_remove)
{
  if(d->tag)
	  d->data.removeAt(id_want_remove);
}

QString axlCompositeCurve::description(void) const
{
	QString s = "axlCompositeCurve";
	if(d->tag)
	{
		for(int i = 0; i <d->data.size(); i++)
		{
			s.append(d->data.at(i)->description() + "\n");
		}
	}
	else
	{
		s.append(d->ends.first->description() + "\n");
		s.append(d->ends.second->description());
	}
	return s;
}

QString axlCompositeCurve::identifier(void)  const
{
	return "axlCompositeCurve";
}

axlCompositeCurve& axlCompositeCurve::operator=(const axlCompositeCurve& other)
{
    d->tag = other.d->tag;
	d->data.clear();
	if(d->tag)
	{
	   d->data.append(other.d->data);
	}
	else
	{
		d->ends = other.d->ends;
	}
	return (*this);
}

dtkAbstractData *createaxlCompositeCurve(void)
{
	return new axlCompositeCurve;
}
