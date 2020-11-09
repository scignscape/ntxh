/* axlFieldParametricSurfaceReader.cpp ---
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

#include "axlFieldParametricSurfaceReader.h"
#include "axlReader.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricSurface.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricSurfaceReader
// /////////////////////////////////////////////////////////////////

axlFieldParametricSurfaceReader::axlFieldParametricSurfaceReader(void)
{
    this->setObjectName(this->description());
}

axlFieldParametricSurfaceReader::~axlFieldParametricSurfaceReader(void)
{

}

QString axlFieldParametricSurfaceReader::identifier(void) const
{
    return "axlFieldParametricSurfaceReader";
}

QString axlFieldParametricSurfaceReader::description(void) const
{
    return "axlFieldParametricSurfaceReader";
}

QStringList axlFieldParametricSurfaceReader::handled(void) const
{
    return QStringList() << "axlFieldParametricSurface";
}

bool axlFieldParametricSurfaceReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldParametricSurfaceReader", QStringList(), createaxlFieldParametricSurfaceReader);
}

bool axlFieldParametricSurfaceReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldParametricSurfaceReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldParametricNormalVector.
axlAbstractData *axlFieldParametricSurfaceReader::read(const QDomNode& node)
{

    qDebug() << Q_FUNC_INFO << "enter";
    QDomElement element = node.toElement();
    axlFieldParametricSurface *field = NULL;

    // field type : the type corresponds to the identifier, use factory to initialize field.
    QString type = element.attribute("type");
    if(!type.isEmpty())
    {
        field = dynamic_cast<axlFieldParametricSurface *>(dtkAbstractDataFactory::instance()->create(type));
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
            field->setType(axlFieldParametricSurface::Int);
        }else if(typeField == "float"){
            field->setType(axlFieldParametricSurface::Float);
        }else{
            field->setType(axlFieldParametricSurface::Double);
        }
    }


    ////Field Support
    QString support = element.attribute("support");
    if(support == "point"){
        field->setSupport(axlFieldParametricSurface::Point);
    }else if(support == "cell"){
        field->setSupport(axlFieldParametricSurface::Cell);
    }else{
        field->setSupport(axlFieldParametricSurface::Custom);
    }

    ////Field Kind
    QString kind = element.attribute("kind");
    if(kind == "scalar"){
        field->setKind(axlFieldParametricSurface::Scalar);
    }else if(kind == "vector"){
        field->setKind(axlFieldParametricSurface::Vector);
    }else{
        field->setKind(axlFieldParametricSurface::Tensor);
    }


    ////Read the parametric function
    QDomNodeList listFunction = element.elementsByTagName("surface");
    QDomElement functionDescription = listFunction.at(0).toElement();
    qDebug() << Q_FUNC_INFO << "read function description";

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

dtkAbstractData *axlFieldParametricSurfaceReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
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



dtkAbstractDataReader *createaxlFieldParametricSurfaceReader(void)
{
    return new axlFieldParametricSurfaceReader;
}


