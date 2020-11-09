#include "axlSamplingCurve.h"
#include "axlAbstractCurveBSpline.h"

axlPoint *rotatePoint(double a, double b, double c, double x, double y,double z, double u, double v, double w, double alpha)
{
    axlPoint *res = new axlPoint();
    qreal a1 = (a*(qPow(v,2)+qPow(w,2))-u*(b*v+c*w-u*x-v*y-w*z))*(1-qCos(alpha))+x*qCos(alpha)+(-c*v+b*w-w*y+v*z)*qSin(alpha);
    qreal a2 = (b*(qPow(u,2)+qPow(w,2))-v*(a*u+c*w-u*x-v*y-w*z))*(1-qCos(alpha))+y*qCos(alpha)+(c*u-a*w+w*x-u*z)*qSin(alpha);
    qreal a3 = (c*(qPow(u,2)+qPow(v,2))-w*(a*u+b*v-u*x-v*y-w*z))*(1-qCos(alpha))+z*qCos(alpha)+(-b*u+a*v-v*x+u*y)*qSin(alpha);
    res->setValues(a1,a2,a3);
    return res;
};

axlPoint* RotatePoint(axlPoint a,axlPoint x,axlPoint u, double alpha)
{
    return rotatePoint(a.x(),a.y(),a.z(),x.x(),x.y(),x.z(),u.x(),u.y(),u.z(),alpha);
};

axlPoint* RotatePoint(axlLine *line,axlPoint *x, double alpha)
{
	axlPoint dir = line->secondPoint()->operator-(line->firstPoint());
	dir.normalize();//use better function
    return RotatePoint(*(line->firstPoint()),*x,dir,alpha);
}

void normalize(axlPoint& point)
{
	double n = point.norm();
	if(n>1e-5)
	{
		point.setValues(point.x()/n,point.y()/n,point.z()/n);
	}
}
//computing the angle of vector vCompute if you choose the vRef is origin (where the angle = 0) and the result will be between [-PI, PI].
//Vector normal here is very important, because, the angle is computing by the counter-clockwise with the direction of vector go out of plane. 
//For more details, see the atan2() of c++ references or google "c++ atan2". 
double angle(axlPoint vCompute, axlPoint vRef, axlPoint normal)
{
	normalize(vCompute);
	normalize(vRef);
	normalize(normal);
	axlPoint y = axlPoint::crossProduct(normal,vRef);
	return std::atan2(axlPoint::dotProduct(vCompute,y),axlPoint::dotProduct(vCompute,vRef));
}

//conputing the angle of arc with base on the function angle().
double angleOfArc(const axlCircleArc *arc)
{
	axlPoint p1 = arc->point1(), p2 = arc->point2();
	

	if(std::abs(axlPoint::crossProduct(arc->point1()-arc->center(),arc->point2()-arc->center()).norm())<1e-5)
	{
		if(arc->isDirect())
		    return M_PI;
		else
			return -M_PI;
	}
	if(!arc->isDirect())
		qSwap(p1,p2);

	double ang = angle(p2-arc->center(),p1-arc->center(),arc->normal());
	if(ang<0)
		return ang+ 2*M_PI;
	return ang;
}
axlPoint normalCCWArc(const axlCircleArc& arc)
{
	
	if(std::abs(axlPoint::crossProduct(arc.point1()-arc.center(),arc.point2()-arc.center()).norm())<1e-5)
	{
		if(arc.isDirect())
			return arc.normal();
		else
			return arc.normal()*(-1);
	}
	else
		return arc.calculateNormal();
		
}
QList<axlPoint *> Sampling(axlAbstractCurve *curve)
{
    QList<axlPoint *> result;

    if(axlLine *line = dynamic_cast<axlLine *>(curve))
    {
        result.append(line->firstPoint());
        result.append(line->secondPoint());
    }
    else if(axlCircleArc *ca = dynamic_cast<axlCircleArc *>(curve))
    {
        double step = angleOfArc(ca)/40;
		axlPoint nor = ca->normal()/*normalCCWArc(*ca)*/;
		nor.normalize();
		/*qDebug()<<"angle = "<<angleOfArc(ca);
		qDebug()<<"nor = "<< nor.description();*/
		axlPoint *inter;
		if(ca->isDirect())
			 inter = new axlPoint(ca->point1());
		else
			 inter = new axlPoint(ca->point2());
        for(int i = 0; i<=40;i++)
        {
            result.append(RotatePoint(new axlLine(ca->center(),ca->center()+nor),inter,i*step));
        }
    }
    else if(axlAbstractCurveBSpline *curvepara = dynamic_cast<axlAbstractCurveBSpline *>(curve))
    {
        double step = (curvepara->endParam()-curvepara->startParam())/40;
        for(int i = 0;i<41;i++)
        {
            result.append(new axlPoint(curvepara->eval(curvepara->startParam()+i*step)));
        }

    }
    return result;
}