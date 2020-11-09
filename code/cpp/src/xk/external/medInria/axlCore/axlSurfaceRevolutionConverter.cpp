//Author: Hung NGUYEN 9:17 AM 20/05/2014



#include <axlCore/axlMesh.h>
#include "axlSurfaceRevolution.h"
#include "axlSurfaceRevolutionConverter.h"

#include "axlAbstractCurveBSpline.h"
#include "axlCircleArc.h"
#include <dtkCoreSupport/dtkAbstractDataFactory.h>


class axlSurfaceRevolutionConverterPrivate
{
public:
    axlSurfaceRevolution *data;
};

axlSurfaceRevolutionConverter::axlSurfaceRevolutionConverter(void) : axlAbstractDataConverter(), d(new axlSurfaceRevolutionConverterPrivate)
{

    d->data = NULL;
}

axlSurfaceRevolutionConverter::~axlSurfaceRevolutionConverter(void)
{
    delete d;

    d = NULL;
}

QString axlSurfaceRevolutionConverter::description(void) const
{
    return "Converter from axlSurfaceRevolution to axlMesh";
}

QString axlSurfaceRevolutionConverter::identifier() const
{
    return "axlSurfaceRevolutionConverter";
}

QStringList axlSurfaceRevolutionConverter::fromTypes(void) const
{
    return QStringList() << "axlSurfaceRevolutionConverter" << "axlSurfaceRevolution";
}
QString axlSurfaceRevolutionConverter::toType (void) const
{
    return "axlMesh";
}

bool axlSurfaceRevolutionConverter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlSurfaceRevolutionConverter", QStringList(), "axlMesh", createaxlSurfaceRevolutionConverter);
}

axlPoint *axlSurfaceRevolutionConverter::rotatePoint(double a, double b, double c, double x, double y,double z, double u, double v, double w, double alpha)
{
    axlPoint *res = new axlPoint();
    qreal a1 = (a*(qPow(v,2)+qPow(w,2))-u*(b*v+c*w-u*x-v*y-w*z))*(1-qCos(alpha))+x*qCos(alpha)+(-c*v+b*w-w*y+v*z)*qSin(alpha);
    qreal a2 = (b*(qPow(u,2)+qPow(w,2))-v*(a*u+c*w-u*x-v*y-w*z))*(1-qCos(alpha))+y*qCos(alpha)+(c*u-a*w+w*x-u*z)*qSin(alpha);
    qreal a3 = (c*(qPow(u,2)+qPow(v,2))-w*(a*u+b*v-u*x-v*y-w*z))*(1-qCos(alpha))+z*qCos(alpha)+(-b*u+a*v-v*x+u*y)*qSin(alpha);
    res->setCoordinates(a1,a2,a3);
    return res;
};

axlPoint* axlSurfaceRevolutionConverter::RotatePoint(axlPoint a,axlPoint x,axlPoint u, double alpha)
{
    return rotatePoint(a.x(),a.y(),a.z(),x.x(),x.y(),x.z(),u.x(),u.y(),u.z(),alpha);
};

axlPoint* axlSurfaceRevolutionConverter::RotatePoint(axlLine *line,axlPoint *x, double alpha)
{
	axlPoint dir = line->secondPoint()->operator-(line->firstPoint());
	dir.normalize();//use better function
    return RotatePoint(*(line->firstPoint()),*x,dir,alpha);
}
//computing the angle of vector vCompute if you choose the vRef is origin (where the angle = 0) and the result will be between [-PI, PI].
//Vector normal here is very important, because, the angle is computing by the counter-clockwise with the direction of vector go out of plane.
//For more details, see the atan2() of c++ references or google "c++ atan2".
double axlSurfaceRevolutionConverter::angle(axlPoint vCompute, axlPoint vRef, axlPoint normal)
{
	axlPoint y = axlPoint::crossProduct(normal,vRef);
	return std::atan2(axlPoint::dotProduct(vCompute,y),axlPoint::dotProduct(vCompute,vRef));
}

//conputing the angle of arc with base on the function angle().
double axlSurfaceRevolutionConverter::angleOfArc(const axlCircleArc *arc)
{
	if(std::abs(axlPoint::crossProduct(arc->point1()-arc->center(),arc->point2()-arc->center()).norm())<1e-5)
	{
		if(arc->isDirect())
		    return M_PI;
		else
			return -M_PI;
	}

	double ang = angle(arc->point2()-arc->center(),arc->point1()-arc->center(),/*arc->normal()*/arc->calculateNormal());
	//
	//if(ang>0 && !arc->isDirect())
	//	ang = ang - 2*M_PI;
	//else if(ang<0&&!arc->isDirect())
	//	//ang = ang + 2*M_PI;
	if(ang<0)
		return ang+ 2*M_PI;
	/*if(axlPoint::dotProduct(axlPoint::crossProduct(arc->point1()-arc->center(),arc->point2()-arc->center()),arc->normal())<0&&arc->isDirect())
		return ang + 2*M_PI;
	if(axlPoint::dotProduct(axlPoint::crossProduct(arc->point1()-arc->center(),arc->point2()-arc->center()),arc->normal())>0&&!arc->isDirect())
		return ang - 2*M_PI;*/
	return ang;
}
axlPoint axlSurfaceRevolutionConverter::normalCCWArc(const axlCircleArc& arc)
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
QList<axlPoint *> axlSurfaceRevolutionConverter::Sampling(axlAbstractCurve *curve)
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
        /*if((axlPoint::dotProduct(ca->normal(),axlPoint::crossProduct(ca->point1()-ca->center(),ca->point2()-ca->center()))>0&&ca->isDirect())||(axlPoint::dotProduct(ca->normal(),axlPoint::crossProduct(ca->point1()-ca->center(),ca->point2()-ca->center()))<0&&!ca->isDirect()))
        {
            step = qAcos(axlPoint::dotProduct(ca->point1()-ca->center(),ca->point2()-ca->center())/(ca->point1()-ca->center()).norm()*(ca->point1()-ca->center()).norm())/40;
        }
        else
        {
            step = 2*M_PI - qAcos(axlPoint::dotProduct(ca->point1()-ca->center(),ca->point2()-ca->center())/(ca->point1()-ca->center()).norm()*(ca->point1()-ca->center()).norm())/40;
        }*/
        for(int i = 0; i<=40;i++)
        {
            axlPoint *inter = new axlPoint(ca->point1());
            result.append(RotatePoint(new axlLine(ca->center(),ca->center()+normalCCWArc(*ca)),inter,i*step));
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
axlMesh *axlSurfaceRevolutionConverter::toMesh(void)
{

    if(!d->data)
        return NULL;

    axlMesh *output = new axlMesh();
    int NoS = 40;
    double step = (d->data->getEndAngle()-d->data->getStartAngle())/NoS;
    QList<QList<axlPoint *> > samples;
	for(int i = 0; i<d->data->countCurve(); i++)
	{
		QList<axlPoint *> temp = Sampling(d->data->getCurve(i));
		samples.append(temp);
	}
	int lastID = 0;
	for(int k = 0; k<samples.size(); k++)
	{
		for(int i = 0;i<samples.at(k).size();i++)
		{
			for(int j = 0;j<NoS+1;j++)
			{
				output->push_back_vertex(RotatePoint(d->data->getAxe(),samples.at(k).value(i),d->data->getStartAngle()+j*step));
			}
		}
		int i1, i2;
		for(int i = 0; i < samples.at(k).size()-1; i++)
		{
			for(int j= 0; j <NoS; j++)
			{
				i1 = lastID + i * (NoS+1) + j;
				i2 = i1 + NoS+1;

				QVector<int> firstTriangle;
				QVector<int> secondTriamgle;

				firstTriangle.push_back(i1);
				firstTriangle.push_back(i1 + 1);
				firstTriangle.push_back(i2);

				secondTriamgle.push_back(i2);
				secondTriamgle.push_back(i1 + 1);
				secondTriamgle.push_back(i2 + 1);

				output->push_back_face(firstTriangle);
				output->push_back_face(secondTriamgle);

			}

		}

		axlMesh::Edge ed0,ed1,ed2,ed3;
		for(int i = 0; i < NoS+1 ; i++)
		{
			ed0<<lastID + i;
		}
		output->push_back_edge(ed0);

		for(int j = 0; j < samples.at(k).size() ; j++)
		{
			ed1<<lastID + (NoS+j*(NoS+1));
		}
		output->push_back_edge(ed1);


		for(int i = 0; i < NoS+1 ; i++)
		{
			ed2<<lastID + (samples.at(k).size()-2)*(NoS+1) + (NoS-i);
		}
		output->push_back_edge(ed2);

		for(int j = 0; j < samples.at(k).size() ; j++)
		{
			ed3<<lastID + (samples.at(k).size()-1-j)*(NoS+1);
		}
		output->push_back_edge(ed3);

		lastID+=samples.at(k).size()*(NoS+1);
	}

    output->vertex_show() = true;
    output->face_show() = true;
    output->vertex_show() = true;
    return output;
}

void axlSurfaceRevolutionConverter::setData(dtkAbstractData *data)
{
    if(axlSurfaceRevolution *Data = dynamic_cast<axlSurfaceRevolution *>(data))
        d->data = Data;
}

dtkAbstractDataConverter *createaxlSurfaceRevolutionConverter(void)
{
    return new axlSurfaceRevolutionConverter;
}
