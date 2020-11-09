/* axlFieldSpatialPointDistanceReader.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlFieldSpatialPointDistanceReader.h"
#include "axlReader.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldSpatialPointDistance.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlPoint.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>


// /////////////////////////////////////////////////////////////////
// axlFieldSpatialPointDistanceReader
// /////////////////////////////////////////////////////////////////

axlFieldSpatialPointDistanceReader::axlFieldSpatialPointDistanceReader(void)
{
    this->setObjectName(this->description());
}

axlFieldSpatialPointDistanceReader::~axlFieldSpatialPointDistanceReader(void)
{

}

QString axlFieldSpatialPointDistanceReader::identifier(void) const
{
    return "axlFieldSpatialPointDistanceReader";
}

QString axlFieldSpatialPointDistanceReader::description(void) const
{
    return "axlFieldSpatialPointDistanceReader";
}

QStringList axlFieldSpatialPointDistanceReader::handled(void) const
{
    return QStringList() << "axlAbstractField" << "axlFieldSpatialPointDistance";
}

bool axlFieldSpatialPointDistanceReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldSpatialPointDistanceReader", QStringList(), createaxlFieldSpatialPointDistanceReader);
}

bool axlFieldSpatialPointDistanceReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldSpatialPointDistanceReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldSpatialPointDistance.
axlAbstractData *axlFieldSpatialPointDistanceReader::read(const QDomNode& node)
{

    QDomElement element = node.toElement();
    axlFieldSpatialPointDistance *field = NULL;

    // field type : the type corresponds to the identifier, use factory to initialize field.
    QString type = element.attribute("type");
    if(!type.isEmpty())
    {
        field = dynamic_cast<axlFieldSpatialPointDistance *>(dtkAbstractDataFactory::instance()->create(type));
    }

    ////name
    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        field->setObjectName(name);
    }


    //Parameters
    QDomNode child = element.elementsByTagName("input").at(0);
    if(child.isElement() ){
        double x = 0;
        double y = 0;
        double z = 0;

        QString xcoordinate = child.toElement().attribute("xcoordinate");
        if(!xcoordinate.isEmpty()){
            x = xcoordinate.toDouble();
        }

        QString ycoordinate = child.toElement().attribute("ycoordinate");
        if(!ycoordinate.isEmpty()){
            y = ycoordinate.toDouble();
        }

        QString zcoordinate = child.toElement().attribute("zcoordinate");
        if(!zcoordinate.isEmpty()){
            z = zcoordinate.toDouble();
        }

        field->setParameter(x,0);
        field->setParameter(y,1);
        field->setParameter(z,2);
    }

    field->update();
    return field;


}

dtkAbstractData *axlFieldSpatialPointDistanceReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
{
    if(!axl_reader)
        return NULL;

    if(!axl_reader->accept(node))
        return NULL;

    axl_reader->dtkAbstractDataReader::read(this->file());

    if(dtkAbstractData *data = axl_reader->read(node))
        return data;


    return NULL;
}



dtkAbstractDataReader *createaxlFieldSpatialPointDistanceReader(void)
{
    return new axlFieldSpatialPointDistanceReader;
}


