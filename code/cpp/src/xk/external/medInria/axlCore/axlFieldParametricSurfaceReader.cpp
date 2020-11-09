/* axlFieldParametricCurveReader.cpp ---
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

#include "axlFieldParametricCurveReader.h"
#include "axlReader.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricCurve.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricCurveReader
// /////////////////////////////////////////////////////////////////

axlFieldParametricCurveReader::axlFieldParametricCurveReader(void)
{
    this->setObjectName(this->description());
}

axlFieldParametricCurveReader::~axlFieldParametricCurveReader(void)
{

}

QString axlFieldParametricCurveReader::identifier(void) const
{
    return "axlFieldParametricCurveReader";
}

QString axlFieldParametricCurveReader::description(void) const
{
    return "axlFieldParametricCurveReader";
}

QStringList axlFieldParametricCurveReader::handled(void) const
{
    return QStringList() << "axlFieldParametricCurve";
}

bool axlFieldParametricCurveReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldParametricCurveReader", QStringList(), createaxlFieldParametricCurveReader);
}

bool axlFieldParametricCurveReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldParametricCurveReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldParametricCurve.
axlAbstractData *axlFieldParametricCurveReader::read(const QDomNode& node)
{

    qDebug() << Q_FUNC_INFO << "enter";
    QDomElement element = node.toElement();
    axlFieldParametricCurve *field = NULL;

    // field type : the type corresponds to the identifier, use factory to initialize field.
    QString type = element.attribute("type");
    if(!type.isEmpty())
    {
        field = dynamic_cast<axlFieldParametricCurve *>(dtkAbstractDataFactory::instance()->create(type));
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
            field->setType(axlFieldParametricCurve::Int);
        }else if(typeField == "float"){
            field->setType(axlFieldParametricCurve::Float);
        }else{
            field->setType(axlFieldParametricCurve::Double);
        }
    }


    ////Field Support
    QString support = element.attribute("support");
    if(support == "point"){
        field->setSupport(axlFieldParametricCurve::Point);
    }else if(support == "cell"){
        field->setSupport(axlFieldParametricCurve::Cell);
    }else{
        field->setSupport(axlFieldParametricCurve::Custom);
    }

    ////Field Kind
    QString kind = element.attribute("kind");
    if(kind == "scalar"){
        field->setKind(axlFieldParametricCurve::Scalar);
    }else if(kind == "vector"){
        field->setKind(axlFieldParametricCurve::Vector);
    }else{
        field->setKind(axlFieldParametricCurve::Tensor);
    }


    ////Read the parametric function
    QDomNodeList listFunction = element.elementsByTagName("curve");
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

dtkAbstractData *axlFieldParametricCurveReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
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



dtkAbstractDataReader *createaxlFieldParametricCurveReader(void)
{
    return new axlFieldParametricCurveReader;
}

