/* axlFieldParametricSurfaceTangentVectorReader.cpp ---
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

#include "axlFieldParametricSurfaceTangentVectorReader.h"
#include "axlReader.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricSurfaceTangentVector.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricSurfaceTangentVectorReader
// /////////////////////////////////////////////////////////////////

axlFieldParametricSurfaceTangentVectorReader::axlFieldParametricSurfaceTangentVectorReader(void)
{
    this->setObjectName(this->description());
}

axlFieldParametricSurfaceTangentVectorReader::~axlFieldParametricSurfaceTangentVectorReader(void)
{

}

QString axlFieldParametricSurfaceTangentVectorReader::identifier(void) const
{
    return "axlFieldParametricSurfaceTangentVectorReader";
}

QString axlFieldParametricSurfaceTangentVectorReader::description(void) const
{
    return "axlFieldParametricSurfaceTangentVectorReader";
}

QStringList axlFieldParametricSurfaceTangentVectorReader::handled(void) const
{
    return QStringList() << "axlFieldParametricSurfaceTangentVector";
}

bool axlFieldParametricSurfaceTangentVectorReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldParametricSurfaceTangentVectorReader", QStringList(), createaxlFieldParametricSurfaceTangentVectorReader);
}

bool axlFieldParametricSurfaceTangentVectorReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldParametricSurfaceTangentVectorReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldSpatialPointDistance.
axlAbstractData *axlFieldParametricSurfaceTangentVectorReader::read(const QDomNode& node)
{

    QDomElement element = node.toElement();
    axlFieldParametricSurfaceTangentVector *field = NULL;

    // field type : the type corresponds to the identifier, use factory to initialize field.
    QString type = element.attribute("type");
    if(!type.isEmpty())
    {
        field = dynamic_cast<axlFieldParametricSurfaceTangentVector *>(dtkAbstractDataFactory::instance()->create(type));
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

            qDebug() << Q_FUNC_INFO << channel << value;
            field->setParameter(value, channel);
        }

    }

    field->update();
    return field;


}

dtkAbstractData *axlFieldParametricSurfaceTangentVectorReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
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



dtkAbstractDataReader *createaxlFieldParametricSurfaceTangentVectorReader(void)
{
    return new axlFieldParametricSurfaceTangentVectorReader;
}


