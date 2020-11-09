#include "axlTabulatedCylinderConverter.h"
#include "axlTabulatedCylinder.h"
#include "axlSamplingCurve.h"

#include <axlCore/axlMesh.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>


class axlTabulatedCylinderConverterPrivate
{
public:
    axlTabulatedCylinder *data;
};

axlTabulatedCylinderConverter::axlTabulatedCylinderConverter() : axlAbstractDataConverter(), d(new axlTabulatedCylinderConverterPrivate)
{
	 d->data = NULL;
};

axlTabulatedCylinderConverter::~axlTabulatedCylinderConverter()
{
	delete d;
	d = NULL;
}

QString axlTabulatedCylinderConverter::description(void) const
{
    return "Converter from axlTabulatedCylinder to axlMesh";
}

QString axlTabulatedCylinderConverter::identifier() const
{
    return "axlTabulatedCylinderConverter";
}

QStringList axlTabulatedCylinderConverter::fromTypes(void) const
{
    return QStringList() << "axlTabulatedCylinderConverter" << "axlTabulatedCylinder";
}
QString axlTabulatedCylinderConverter::toType (void) const
{
    return "axlMesh";
}

bool axlTabulatedCylinderConverter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlTabulatedCylinderConverter", QStringList(), "axlMesh", createaxlTabulatedCylinderConverter);
}

axlMesh *axlTabulatedCylinderConverter::toMesh(void)
{
	if(!d->data)
        return NULL;


	axlMesh *mesh = new axlMesh();
	QList<axlPoint *> $list;
	$list.append(Sampling(d->data->get_pt_directrix()));
	axlPoint *$pt = d->data->get_pt_generatrix();
	for(int i = 0; i<$list.size(); ++i)
	{
		mesh->push_back_vertex($list.value(i));
		mesh->push_back_vertex(*$list.value(i)+ *$pt);
		if(i>0)
		{
			/*axlMesh::Face face(4);*/
			/*face<<2*i<<2*i+1<<2*i+3<<2*i+2;*/
			mesh->push_back_face(2*i-2, 2*i-1, 2*i);
			mesh->push_back_face(2*i-1, 2*i,2*i+1);
			/*mesh->push_back_face(face);*/
			mesh->push_back_edge(2*i-2, 2*i);
			mesh->push_back_edge(2*i-1, 2*i+1);
		}
	}

	mesh->push_back_edge(0,1);
    mesh->push_back_edge(2*($list.size()-1),2*($list.size()-1)+1);

	mesh->vertex_show() = false;
    mesh->normal_used() = false;
    mesh->color_used() = false;
    mesh->edge_show() = true;
    mesh->face_show() = true;

	return mesh;
}

void axlTabulatedCylinderConverter::setData(dtkAbstractData *data)
{
    if(axlTabulatedCylinder *Data = dynamic_cast<axlTabulatedCylinder *>(data))
        d->data = Data;
}

dtkAbstractDataConverter *createaxlTabulatedCylinderConverter(void)
{
    return new axlTabulatedCylinderConverter;
}
