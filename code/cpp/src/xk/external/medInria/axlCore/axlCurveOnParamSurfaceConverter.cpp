#include "axlCurveOnParamSurfaceConverter.h"
#include "axlCurveOnParamSurface.h"
#include "axlSamplingCurve.h"

#include <axlCore/axlMesh.h>

//? #include <dtkCore/dtkAbstractDataFactory.h>

 #include <dtkCoreSupport/dtkAbstractDataFactory.h>


class axlCurveOnParamSurfaceConverterPrivate
{
public:
    axlCurveOnParamSurface *data;
};

axlCurveOnParamSurfaceConverter::axlCurveOnParamSurfaceConverter() : axlAbstractDataConverter(), d(new axlCurveOnParamSurfaceConverterPrivate)
{
	 d->data = NULL;
};

axlCurveOnParamSurfaceConverter::~axlCurveOnParamSurfaceConverter()
{
	delete d; 
	d = NULL;
}

QString axlCurveOnParamSurfaceConverter::description(void) const
{
    return "Converter from axlCurveOnParamSurface to axlMesh";
}

QString axlCurveOnParamSurfaceConverter::identifier() const
{
    return "axlCurveOnParamSurfaceConverter";
}

QStringList axlCurveOnParamSurfaceConverter::fromTypes(void) const
{
    return QStringList() << "axlCurveOnParamSurfaceConverter" << "axlCurveOnParamSurface";
}

QString axlCurveOnParamSurfaceConverter::toType (void) const
{
    return "axlMesh";
}

bool axlCurveOnParamSurfaceConverter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlCurveOnParamSurfaceConverter", QStringList(), "axlMesh", createaxlCurveOnParamSurfaceConverter);
}

axlMesh *axlCurveOnParamSurfaceConverter::toMesh(void)
{
	if(!d->data)
        return NULL;
	axlMesh *mesh = new axlMesh();
	axlAbstractSurfaceParametric main = d->data->get_main_surface();
	if(d->data->get_way_create_curve()==1)
	{

	}
	else if(d->data->get_way_create_curve()==2)
	{

	}
	else if(d->data->get_way_create_curve()==3)
	{
		if(axlLine *line = dynamic_cast<axlLine *>(d->data->get_support_curve_param_domain()))
		{
			axlPoint *endPoint1 = line->firstPoint();
			axlPoint direct = *(line->secondPoint()) - *(line->firstPoint());

			for(int i = 0; i<41; i++)
			{
				axlPoint temp = *endPoint1 + direct*((double)i/40.0);
				mesh->push_back_vertex(main.eval(temp.x(),temp.y()));
		    }

			for(int i = 0; i<40; i++)
			{
				mesh->push_back_edge(i,i+1);
			}
		}
		else
		{
			QList<axlPoint *> list_point = Sampling(d->data->get_support_curve_param_domain());
            
			for(int i = 0; i<list_point.size(); i++)
			{
				mesh->push_back_vertex(main.eval(list_point.value(i)->x(),list_point.value(i)->y()));
			}

			for(int i = 0; i<list_point.size() - 1; i++)
			{
				mesh->push_back_edge(i,i+1);
			}
		}
	}

	//QList<axlPoint *> $list;
	//$list.append(Sampling(d->data->get_pt_directrix()));
	//axlPoint *$pt = d->data->get_pt_generatrix();
	//for(int i = 0; i<$list.size(); ++i)
	//{
	//	mesh->push_back_vertex($list.value(i));
	//	mesh->push_back_vertex(*$list.value(i)+ *$pt);
	//	if(i>0)
	//	{
	//		/*axlMesh::Face face(4);*/
	//		/*face<<2*i<<2*i+1<<2*i+3<<2*i+2;*/
	//		mesh->push_back_face(2*i-2, 2*i-1, 2*i);
	//		mesh->push_back_face(2*i-1, 2*i,2*i+1);
	//		/*mesh->push_back_face(face);*/
	//		mesh->push_back_edge(2*i-2, 2*i);
	//		mesh->push_back_edge(2*i-1, 2*i+1);
	//	}	
	//}

	//mesh->push_back_edge(0,1);
 //   mesh->push_back_edge(2*($list.size()-1),2*($list.size()-1)+1);

	mesh->vertex_show() = false;
    mesh->normal_used() = false;
    mesh->color_used() = false;
    mesh->edge_show() = true;
    mesh->face_show() = false;

	return mesh;
}

void axlCurveOnParamSurfaceConverter::setData(dtkAbstractData *data)
{
    if(axlCurveOnParamSurface *Data = dynamic_cast<axlCurveOnParamSurface *>(data))
        d->data = Data;
}

dtkAbstractDataConverter *createaxlCurveOnParamSurfaceConverter(void)
{
    return new axlCurveOnParamSurfaceConverter;
}
