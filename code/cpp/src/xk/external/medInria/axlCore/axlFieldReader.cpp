/* axlFieldReader.cpp ---
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

#include "axlFieldReader.h"
#include "axlReader.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlDouble.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//#include <axlGui/axlInspectorToolFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldReader
// /////////////////////////////////////////////////////////////////

axlFieldReader::axlFieldReader(void)
{
    this->setObjectName(this->description());
}

axlFieldReader::~axlFieldReader(void)
{

}

QString axlFieldReader::identifier(void) const
{
    return "axlFieldReader";
}

QString axlFieldReader::description(void) const
{
    return "axlFieldReader";
}

QStringList axlFieldReader::handled(void) const
{
    return QStringList() << "axlAbstractField";
}

bool axlFieldReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldReader", QStringList(), createaxlFieldReader);
}

bool axlFieldReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldSpatialPointDistance.
axlAbstractData *axlFieldReader::read(const QDomNode& node)
{

    QDomElement element = node.toElement();
    axlAbstractField *field = NULL;

    //    //initialize the field with the factory
    //    QString status = element.attribute("status");
    //    if(!status.isEmpty())
    //        field = dynamic_cast<axlAbstractField *>(dtkAbstractDataFactory::instance()->create(status));
    //    qDebug() << Q_FUNC_INFO << status;


    // field name : the name corresponds to the identifier, use factory to initialize field.
    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        field = dynamic_cast<axlAbstractField *>(dtkAbstractDataFactory::instance()->create(name));
    }

    //field type
    QString type = element.attribute("type");
    if(type == "int"){
        field->setType(axlAbstractField::Int);
    }else if(type == "float"){
        field->setType(axlAbstractField::Float);
    }else if(type == "double"){
        field->setType(axlAbstractField::Double);
    }


    //field kind
    QString kind = element.attribute("kind");
    if(kind == "scalar"){
        field->setKind(axlAbstractField::Scalar);
    }else if(type == "vector"){
        field->setKind(axlAbstractField::Vector);
    }else if(type == "tensor"){
        field->setKind(axlAbstractField::Tensor);

    }

    //field support
    QString support = element.attribute("support");
    if(kind == "point"){
        field->setSupport(axlAbstractField::Point);
    }else if(type == "cell"){
        field->setSupport(axlAbstractField::Cell);
    }else if(type == "custom"){
        field->setSupport(axlAbstractField::Custom);

    }

    //    //find the parents name, ie the object on which the field is applied.
    //    QString dataSupportName = element.attribute("parent");
    //    //we search this data in the list (inserted before its fields !)
    //    foreach(dtkAbstractData *data, list){
    //        if(data->name() == dataSupportName)
    //            dynamic_cast<axlAbstractData *>(data)->addField(field);
    //    }



    field->update();
    return field;


}

dtkAbstractData *axlFieldReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
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

dtkAbstractDataReader *createaxlFieldReader(void)
{
    return new axlFieldReader;
}

