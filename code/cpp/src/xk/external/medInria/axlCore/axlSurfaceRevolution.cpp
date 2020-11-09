//Author: Hung NGUYEN 9:17 AM 20/05/2014



#include "axlSurfaceRevolution.h"



#include <dtkCoreSupport/dtkGlobal.h>



class axlSurfaceRevolutionPrivate

{

public:

	axlLine *axe;

	QList<axlAbstractCurve *> curves;

	double theta1;

	double theta2;



};

axlSurfaceRevolution::axlSurfaceRevolution(QObject *parent) : axlAbstractSurface(), d(new axlSurfaceRevolutionPrivate)
{

	/*this->setObjectName(this->identifier());



	d->axe = new axlLine(new axlLine);

	d->p2 = new axlPoint(1.0, 0.0, 0.0);

	d->radius = 1.0;*/

};
axlSurfaceRevolution::axlSurfaceRevolution(axlLine *axe,QList<axlAbstractCurve *> curves,double theta1, double theta2, QObject *parent) : axlAbstractSurface(), d(new axlSurfaceRevolutionPrivate)
{
	/*qDebug()<<"create a object axlSurfacerevolution";*/
    this->setObjectName(this->identifier());

	d->axe = new axlLine(*axe);

	for(int i = 0; i<curves.size(); i++)
	{
		d->curves.append(curves.value(i));
	}

	d->theta1 = theta1;
	d->theta2 = theta2;
}

axlSurfaceRevolution::~axlSurfaceRevolution()

{

 delete d;

d = NULL;

}



axlSurfaceRevolution& axlSurfaceRevolution::operator=(const axlSurfaceRevolution& other)

{

this->setObjectName(this->identifier());

this->setParent(other.parent());

d->axe = other.d->axe;

d->curves = other.d->curves;


d->theta1 = other.d->theta1;

d->theta2 = other.d->theta2;

return (*this);

}



QString axlSurfaceRevolution::description(void) const

{

QString result = "axlSurfaceRevolution";

result.append("\nAxe : "+d->axe->description() + "\nCurves : ");
for(int i = 0; i<d->curves.size(); i++)
{
	result.append( "curve "+ QString::number(i) + " : " + d->curves.at(i)->identifier());
}

result.append( "\nStart Angle : "+ QString::number(d->theta1)+"\nEnd Angle : "+ QString::number(d->theta2) /*+ "\nReference Point : "+ d->referencePoint->description()*/);

return result;

}



QString axlSurfaceRevolution::identifier(void) const

{

return "axlSurfaceRevolution";

}



axlLine *axlSurfaceRevolution::getAxe()

{

return d->axe;

}



QList<axlAbstractCurve *> axlSurfaceRevolution::getCurves()

{

return d->curves;

}

double axlSurfaceRevolution::getStartAngle()

{

return d->theta1;

}

double axlSurfaceRevolution::getEndAngle()

{

return d->theta2;

}





void axlSurfaceRevolution::setAxe(axlLine *line)

{

    d->axe = new axlLine(*line);

}

void axlSurfaceRevolution::setAxe(axlPoint *point1, axlPoint *point2)
{
   d->axe = new axlLine(point1,point2);
}

int axlSurfaceRevolution::countCurve()
{
	return d->curves.size();
}

void axlSurfaceRevolution::setCurves(QList<axlAbstractCurve *> curves)

{
	for(int i = 0; i<curves.size() ; i++)
	{
		d->curves.append(curves.value(i));
	}
}

axlAbstractCurve *axlSurfaceRevolution::getCurve(int id)
{
	return d->curves.value(id);
}

void axlSurfaceRevolution::setStartAngle(double ang)

{

   d->theta1 = ang;

}



void axlSurfaceRevolution::setEndAngle(double ang)

{

   d->theta2 = ang;

}



void axlSurfaceRevolution::setAngle(double startAngle,double endAngle)

{

	d->theta1 = startAngle;

	d->theta2 = endAngle;

}


dtkAbstractData *createaxlSurfaceRevolution(void)

{

return new axlSurfaceRevolution;

}



