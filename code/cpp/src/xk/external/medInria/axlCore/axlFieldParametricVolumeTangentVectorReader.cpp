/* axlFieldParametricVolumeTangentVectorReader.cpp ---
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

#include "axlFieldParametricVolumeTangentVectorReader.h"
#include "axlReader.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricVolumeTangentVector.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricVolumeTangentVectorReader
// /////////////////////////////////////////////////////////////////

axlFieldParametricVolumeTangentVectorReader::axlFieldParametricVolumeTangentVectorReader(void)
{
    this->setObjectName(this->description());
}

axlFieldParametricVolumeTangentVectorReader::~axlFieldParametricVolumeTangentVectorReader(void)
{

}

QString axlFieldParametricVolumeTangentVectorReader::identifier(void) const
{
    return "axlFieldParametricVolumeTangentVectorReader";
}

QString axlFieldParametricVolumeTangentVectorReader::description(void) const
{
    return "axlFieldParametricVolumeTangentVectorReader";
}

QStringList axlFieldParametricVolumeTangentVectorReader::handled(void) const
{
    return QStringList() << "axlFieldParametricVolumeTangentVector";
}

bool axlFieldParametricVolumeTangentVectorReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldParametricVolumeTangentVectorReader", QStringList(), createaxlFieldParametricVolumeTangentVectorReader);
}

bool axlFieldParametricVolumeTangentVectorReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldParametricVolumeTangentVectorReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldSpatialPointDistance.
axlAbstractData *axlFieldParametricVolumeTangentVectorReader::read(const QDomNode& node)
{

    QDomElement element = node.toElement();
    axlFieldParametricVolumeTangentVector *field = NULL;

    // field type : the type corresponds to the identifier, use factory to initialize field.
    QString type = element.attribute("type");
    if(!type.isEmpty())
    {
        field = dynamic_cast<axlFieldParametricVolumeTangentVector *>(dtkAbstractDataFactory::instance()->create(type));
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

dtkAbstractData *axlFieldParametricVolumeTangentVectorReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
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



dtkAbstractDataReader *createaxlFieldParametricVolumeTangentVectorReader(void)
{
    return new axlFieldParametricVolumeTangentVectorReader;
}

