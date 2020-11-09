//Author: Hung NGUYEN 9:17 AM 25/08/2014



#include "axlSurfaceRevolutionParametric.h"
#include "axlLine.h"
#include "axlCircleArc.h"
#include "axlAbstractCurveBSpline.h"


#include <dtkCoreSupport/dtkGlobal.h>



class axlSurfaceRevolutionParametricPrivate

{

public:

	axlLine *axe;

	axlAbstractCurve *curve;

	double theta1;

	double theta2;

/*axlPoint *referencePoint;*/

};

axlSurfaceRevolutionParametric::axlSurfaceRevolutionParametric(QObject *parent) : axlAbstractSurfaceParametric(), d(new axlSurfaceRevolutionParametricPrivate)
{

	/*this->setObjectName(this->identifier());



	d->axe = new axlLine(new axlLine);

	d->p2 = new axlPoint(1.0, 0.0, 0.0);

	d->radius = 1.0;*/

};
axlSurfaceRevolutionParametric::axlSurfaceRevolutionParametric(axlLine *axe,axlAbstractCurve *curve,double theta1, double theta2, QObject *parent) : axlAbstractSurfaceParametric(), d(new axlSurfaceRevolutionParametricPrivate)
{
	qDebug()<<curve->description();
    this->setObjectName(this->identifier());

	d->axe = new axlLine(*axe);
	if(curve)
		d->curve = curve;
	else
		qDebug()<<"No curve for axlSurfaceRevolution.";
	d->theta1 = theta1;
	d->theta2 = theta2;
	if(d->curve)
	{
	   qDebug()<<"STILL NULL";
	   qDebug()<<d->curve->description();
	}
}

axlSurfaceRevolutionParametric::~axlSurfaceRevolutionParametric()

{

 delete d;

d = NULL;

}



axlSurfaceRevolutionParametric& axlSurfaceRevolutionParametric::operator=(const axlSurfaceRevolutionParametric& other)

{

	this->setObjectName(this->identifier());

	this->setParent(other.parent());

	d->axe = other.d->axe;

	d->curve = other.d->curve;

	/*d->referencePoint = other.d->referencePoint;*/

	d->theta1 = other.d->theta1;

	d->theta2 = other.d->theta2;

	return (*this);

}



QString axlSurfaceRevolutionParametric::description(void) const

{

	QString result = "axlSurfaceRevolutionParametric";

	result.append("\nAxe : "+d->axe->description() + "\nCurve : "+d->curve->identifier() + "\nStart Angle : "+ QString::number(d->theta1)+"\nEnd Angle : "+ QString::number(d->theta2) /*+ "\nReference Point : "+ d->referencePoint->description()*/);

	return result;

}



QString axlSurfaceRevolutionParametric::identifier(void) const

{

   return "axlSurfaceRevolutionParametric";

}



axlLine *axlSurfaceRevolutionParametric::getAxe()

{

    return d->axe;

}



axlAbstractCurve *axlSurfaceRevolutionParametric::getCurve()

{

	return d->curve;

}

double axlSurfaceRevolutionParametric::getStartAngle()

{

	return d->theta1;

}

double axlSurfaceRevolutionParametric::getEndAngle()

{

	return d->theta2;

}





void axlSurfaceRevolutionParametric::setAxe(axlLine *line)

{

    d->axe = new axlLine(*line);

}

void axlSurfaceRevolutionParametric::setAxe(axlPoint *point1, axlPoint *point2)

{

   d->axe = new axlLine(point1,point2);

}



void axlSurfaceRevolutionParametric::setCurve(axlAbstractCurve *curve)

{

    d->curve = curve;

}



void axlSurfaceRevolutionParametric::setStartAngle(double ang)

{

   d->theta1 = ang;

}



void axlSurfaceRevolutionParametric::setEndAngle(double ang)

{

d->theta2 = ang;

}



void axlSurfaceRevolutionParametric::setAngle(double startAngle,double endAngle)

{

d->theta1 = startAngle;

d->theta2 = endAngle;

}



//void axlSurfaceRevolution::setReferencePoint(axlPoint *point)

//{

//  *(d->referencePoint)=*point;

//}

//

//void axlSurfaceRevolution::setReferencePoint(double x, double y, double z)

//{

//  d->referencePoint = new axlPoint(x,y,z);

//}



//QVariantList axlSurfaceRevolution::convertDataToQVariant(void) const

//{

//  QVariantList list;

// QVariant id = QVariant::fromValue(identifier());

//  /*QVariant axe = QVariant::fromValue(d->axe);*/

//  QVariantList axe = d->axe->convertDataToQVariant();

//  QVariantList curve = d->curve->convertDataToQVariant();

//  QVariantList referencePoint = d->referencePoint->convertDataToQVariant();

//  QVariant theta1 = QVariant::fromValue(d->theta1);

//  QVariant theta2 = QVariant::fromValue(d->theta2);

// list.append(id);

// list.append(radius);

// list.append(p1);

// list.append(p2);

// QVariant name = QVariant::fromValue(objectName());

// return list;

//}



//int axlSurfaceRevolution::convertQVariantToData(const QVariantList &data)

//{

//}



dtkAbstractData *createaxlSurfaceRevolutionParametric(void)

{

return new axlSurfaceRevolutionParametric;

}
