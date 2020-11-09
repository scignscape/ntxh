/* axlFieldSpatialCoordinatesReader.cpp ---
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

#include "axlFieldSpatialCoordinatesReader.h"
#include "axlReader.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldSpatialCoordinates.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlDouble.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//#include <axlGui/axlInspectorToolFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldSpatialCoordinatesReader
// /////////////////////////////////////////////////////////////////

axlFieldSpatialCoordinatesReader::axlFieldSpatialCoordinatesReader(void)
{
    this->setObjectName(this->description());
}

axlFieldSpatialCoordinatesReader::~axlFieldSpatialCoordinatesReader(void)
{

}

QString axlFieldSpatialCoordinatesReader::identifier(void) const
{
    return "axlFieldSpatialCoordinatesReader";
}

QString axlFieldSpatialCoordinatesReader::description(void) const
{
    return "axlFieldSpatialCoordinatesReader";
}

QStringList axlFieldSpatialCoordinatesReader::handled(void) const
{
    return QStringList() << "axlAbstractField" << "axlFieldSpatialCoordinates";
}

bool axlFieldSpatialCoordinatesReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldSpatialCoordinatesReader", QStringList(), createaxlFieldSpatialCoordinatesReader);
}

bool axlFieldSpatialCoordinatesReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldSpatialCoordinatesReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldSpatialPointDistance.
axlAbstractData *axlFieldSpatialCoordinatesReader::read(const QDomNode& node)
{

    QDomElement element = node.toElement();
    axlAbstractField *field = NULL;

    // field type : the type corresponds to the identifier, use factory to initialize field.
    QString type = element.attribute("type");
    if(!type.isEmpty())
    {
        field = dynamic_cast<axlAbstractField *>(dtkAbstractDataFactory::instance()->create(type));
    }

    ////name
    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        field->setObjectName(name);
    }

    //Parameters
    int number = node.childNodes().size();
    for(int i = 0;i < number; i++){
        QDomNode child = node.childNodes().at(i);
        if(child.isElement() ){
            double channel =0;
            double value = 0;

            if(!child.toElement().attribute("channel").isEmpty())
                channel = child.toElement().attribute("channel").toInt();

            if(!child.toElement().attribute("value").isEmpty())
                value = child.toElement().attribute("value").toDouble();

            field->setParameter(value, channel);
        }

    }

    field->update();
    return field;


}

dtkAbstractData *axlFieldSpatialCoordinatesReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
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



dtkAbstractDataReader *createaxlFieldSpatialCoordinatesReader(void)
{
    return new axlFieldSpatialCoordinatesReader;
}


