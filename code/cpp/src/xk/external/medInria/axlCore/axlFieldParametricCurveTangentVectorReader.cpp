/* axlFieldParametricCurveTangentVectorReader.cpp ---
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

#include "axlFieldParametricCurveTangentVectorReader.h"
#include "axlReader.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricCurveTangentVector.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlDouble.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricCurveTangentVectorReader
// /////////////////////////////////////////////////////////////////

axlFieldParametricCurveTangentVectorReader::axlFieldParametricCurveTangentVectorReader(void)
{
    this->setObjectName(this->description());
}

axlFieldParametricCurveTangentVectorReader::~axlFieldParametricCurveTangentVectorReader(void)
{

}

QString axlFieldParametricCurveTangentVectorReader::identifier(void) const
{
    return "axlFieldParametricCurveTangentVectorReader";
}

QString axlFieldParametricCurveTangentVectorReader::description(void) const
{
    return "axlFieldParametricCurveTangentVectorReader";
}

QStringList axlFieldParametricCurveTangentVectorReader::handled(void) const
{
    return QStringList() << "axlFieldParametricCurveTangentVector";
}

bool axlFieldParametricCurveTangentVectorReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldParametricCurveTangentVectorReader", QStringList(), createaxlFieldParametricCurveTangentVectorReader);
}

bool axlFieldParametricCurveTangentVectorReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldParametricCurveTangentVectorReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldParametricCurveTangentVector.
axlAbstractData *axlFieldParametricCurveTangentVectorReader::read(const QDomNode& node)
{

    QDomElement element = node.toElement();
    axlFieldParametricCurveTangentVector *field = NULL;

    // field type : the type corresponds to the identifier, use factory to initialize field.
    QString type = element.attribute("type");
    if(!type.isEmpty())
    {
        field = dynamic_cast<axlFieldParametricCurveTangentVector *>(dtkAbstractDataFactory::instance()->create(type));
    }

    ////name
    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        field->setObjectName(name);
    }

    field->update();
    return field;


}

dtkAbstractData *axlFieldParametricCurveTangentVectorReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
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



dtkAbstractDataReader *createaxlFieldParametricCurveTangentVectorReader(void)
{
    return new axlFieldParametricCurveTangentVectorReader;
}


