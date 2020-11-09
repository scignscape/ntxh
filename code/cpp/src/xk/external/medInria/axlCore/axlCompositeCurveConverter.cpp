#include "axlCompositeCurveConverter.h"
#include "axlCompositeCurve.h"


#include <axlCore/axlMesh.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>


class axlCompositeCurveConverterPrivate
{
public:
    axlCompositeCurve *data;
};

axlCompositeCurveConverter::axlCompositeCurveConverter() : axlAbstractDataConverter(), d(new axlCompositeCurveConverterPrivate)
{
	 d->data = NULL;
};

axlCompositeCurveConverter::~axlCompositeCurveConverter()
{
	delete d;
	d = NULL;
}

QString axlCompositeCurveConverter::description(void) const
{
    return "Converter from axlCompositeCurve to axlMesh";
}

QString axlCompositeCurveConverter::identifier() const
{
    return "axlCompositeCurveConverter";
}

QStringList axlCompositeCurveConverter::fromTypes(void) const
{
    return QStringList() << "axlCompositeCurveConverter" << "axlCompositeCurve";
}
QString axlCompositeCurveConverter::toType (void) const
{
    return "axlMesh";
}

bool axlCompositeCurveConverter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlCompositeCurveConverter", QStringList(), "axlMesh", createaxlCompositeCurveConverter);
}

//this function just use whenthe meshes have no face.
void axlCompositeCurveConverter::addMesh2Mesh(axlMesh& mother_mesh, axlMesh *child_mesh)
{
	QVector<axlMesh::Edge> edge_of_child_mesh = child_mesh->edgeSet();
	int count_vertex = mother_mesh.vertex_count();
	qDebug()<<"count_vertex = "<<count_vertex;
	qDebug()<<"child_mesh = "<<child_mesh->vertex_count();
	//add vertex from child_mesh to mother_mesh
	for(int i = 0; i<child_mesh->vertex_count(); ++i)
	{
		mother_mesh.push_back_vertex(new axlPoint(child_mesh->vertexX(i),child_mesh->vertexY(i),child_mesh->vertexZ(i)));
	}

	//add edge to mother_mesh
	for(int i = 0; i<edge_of_child_mesh.size(); i++)
	{
		QVector<int> temp(edge_of_child_mesh.at(i).size());

		for(int j = 0; j < edge_of_child_mesh.at(i).size(); ++j)
		{
			temp.insert(j, edge_of_child_mesh.at(i).at(j) + count_vertex );
			if(j==1)
			{
				qDebug()<< edge_of_child_mesh.at(i).at(j)<<" ---> "<<edge_of_child_mesh.at(i).at(j) + count_vertex;
			}
		}

		mother_mesh.push_back_edge(temp);
	}
}

axlPoint *rotatePoint(double a, double b, double c, double x, double y,double z, double u, double v, double w, double alpha)
{
    axlPoint *res = new axlPoint();
    qreal a1 = (a*(qPow(v,2)+qPow(w,2))-u*(b*v+c*w-u*x-v*y-w*z))*(1-qCos(alpha))+x*qCos(alpha)+(-c*v+b*w-w*y+v*z)*qSin(alpha);
    qreal a2 = (b*(qPow(u,2)+qPow(w,2))-v*(a*u+c*w-u*x-v*y-w*z))*(1-qCos(alpha))+y*qCos(alpha)+(c*u-a*w+w*x-u*z)*qSin(alpha);
    qreal a3 = (c*(qPow(u,2)+qPow(v,2))-w*(a*u+b*v-u*x-v*y-w*z))*(1-qCos(alpha))+z*qCos(alpha)+(-b*u+a*v-v*x+u*y)*qSin(alpha);
    res->setCoordinates(a1,a2,a3);
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
        point.setCoordinates(point.x()/n,point.y()/n,point.z()/n);
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

axlMesh *axlCompositeCurveConverter::toMesh(void)
{
	if(!d->data)
        return NULL;


	axlMesh *mesh = new axlMesh();
	if(d->data->getCase())
	{
		QList<QList<axlPoint *> > $list;
		for(int i = 0; i<d->data->count_curve(); ++i)
		{
			$list.append(Sampling(d->data->get_pt_curve_at_id(i)));
		}

		for(int i = 0; i<$list.size(); ++i)
		{
			int count = mesh->vertex_count();
			for(int j = 0; j<$list.at(i).size(); ++j)
			{
				mesh->push_back_vertex($list.at(i).value(j));
				if(j!=0)
					mesh->push_back_edge( count + j - 1, count + j );
			}
		}

		mesh->vertex_show() = false;
		mesh->normal_used() = false;
		mesh->color_used() = false;
		mesh->edge_show() = true;
		mesh->face_show() = false;
	}
	else
	{
		mesh->push_back_vertex(d->data->get_start_point());
		mesh->push_back_vertex(d->data->get_end_point());

		mesh->vertex_show() = true;
		mesh->normal_used() = false;
		mesh->color_used() = false;
		mesh->edge_show() = false;
		mesh->face_show() = false;
	}

	return mesh;
}

void axlCompositeCurveConverter::setData(dtkAbstractData *data)
{
    if(axlCompositeCurve *Data = dynamic_cast<axlCompositeCurve *>(data))
        d->data = Data;
}

dtkAbstractDataConverter *createaxlCompositeCurveConverter(void)
{
    return new axlCompositeCurveConverter;
}



//===================================================================================

//@from toMesh()

/*

      axlAbstractCurve *curve = d->data->get_pt_curve_at_id(i);
		if(axlLine *line = dynamic_cast<axlLine *>(curve))
		{
			mesh->push_back_vertex(line->firstPoint());
			mesh->push_back_vertex(line->secondPoint());
			mesh->push_back_edge(mesh->vertex_count() -2,  mesh->vertex_count() -1);
		}
		else if(axlCircleArc *arc = dynamic_cast<axlCircleArc *>(curve))
		{
			int index = mesh->vertex_count();
			mesh->push_back_vertex(arc->point1());
			mesh->push_back_vertex(arc->point2());

			qDebug()<<"curve:"<< curve->description();
			QString converterName = curve->identifier()+"Converter";

			axlAbstractDataConverter* converter =
			         dynamic_cast<axlAbstractDataConverter*>(dtkAbstractDataFactory
					                           ::instance()->converter(converterName));

			if (converter) {
				converter->setData(curve);
				converter->setParams(0, mesh->vertex_count());
				converter->setParams(1, converter->ge);
				converter->setOutput(mesh);
				addMesh2Mesh(*mesh,converter->toMesh());
			}
		}





*/
