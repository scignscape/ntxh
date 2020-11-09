/* axlFieldParametricVolumeReader.cpp ---
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

#include "axlFieldParametricVolumeReader.h"
#include "axlReader.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricVolume.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricVolumeReader
// /////////////////////////////////////////////////////////////////

axlFieldParametricVolumeReader::axlFieldParametricVolumeReader(void)
{
    this->setObjectName(this->description());
}

axlFieldParametricVolumeReader::~axlFieldParametricVolumeReader(void)
{

}

QString axlFieldParametricVolumeReader::identifier(void) const
{
    return "axlFieldParametricVolumeReader";
}

QString axlFieldParametricVolumeReader::description(void) const
{
    return "axlFieldParametricVolumeReader";
}

QStringList axlFieldParametricVolumeReader::handled(void) const
{
    return QStringList() << "axlFieldParametricVolume";
}

bool axlFieldParametricVolumeReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldParametricVolumeReader", QStringList(), createaxlFieldParametricVolumeReader);
}

bool axlFieldParametricVolumeReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldParametricVolumeReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldParametricVolume.
axlAbstractData *axlFieldParametricVolumeReader::read(const QDomNode& node)
{

    dtkWarn() << Q_FUNC_INFO << "enter";
    QDomElement element = node.toElement();
    axlFieldParametricVolume *field = NULL;

    // field type : the type corresponds to the identifier, use factory to initialize field.
    QString type = element.attribute("type");
    if(!type.isEmpty())
    {
        field = dynamic_cast<axlFieldParametricVolume *>(dtkAbstractDataFactory::instance()->create(type));
    }

    ////name
    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        field->setObjectName(name);
    }

    ////Field Type
    QString typeField = element.attribute("valueType");
    if(!typeField.isEmpty()){
        if(typeField == "int"){
            field->setType(axlFieldParametricVolume::Int);
        }else if(typeField == "float"){
            field->setType(axlFieldParametricVolume::Float);
        }else{
            field->setType(axlFieldParametricVolume::Double);
        }
    }


    ////Field Support
    QString support = element.attribute("support");
    if(support == "point"){
        field->setSupport(axlFieldParametricVolume::Point);
    }else if(support == "cell"){
        field->setSupport(axlFieldParametricVolume::Cell);
    }else{
        field->setSupport(axlFieldParametricVolume::Custom);
    }

    ////Field Kind
    QString kind = element.attribute("kind");
    if(kind == "scalar"){
        field->setKind(axlFieldParametricVolume::Scalar);
    }else if(kind == "vector"){
        field->setKind(axlFieldParametricVolume::Vector);
    }else{
        field->setKind(axlFieldParametricVolume::Tensor);
    }


    ////Read the parametric function
    QDomNodeList listFunction = element.elementsByTagName("volume");
    QDomElement functionDescription = listFunction.at(0).toElement();

    dtkAbstractData *data = NULL;
    // test for all reader registered in the factory
    foreach(QString reader, dtkAbstractDataFactory::instance()->readers()) {
        axlAbstractDataReader *axl_reader = dynamic_cast<axlAbstractDataReader *>(dtkAbstractDataFactory::instance()->reader(reader));
        data = this->dataByReader(axl_reader, functionDescription);
        delete axl_reader;

        if(data){
            axlAbstractData *function = dynamic_cast<axlAbstractData *>(data);
            field->setFunction(function);
        }
    }


    field->update();
    return field;


}

dtkAbstractData *axlFieldParametricVolumeReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
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



dtkAbstractDataReader *createaxlFieldParametricVolumeReader(void)
{
    return new axlFieldParametricVolumeReader;
}


