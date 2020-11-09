/* axlFieldParametricSurfaceNormalVectorReader.cpp ---
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

#include "axlFieldParametricSurfaceNormalVectorReader.h"
#include "axlReader.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricNormalVector.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlDouble.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricSurfaceNormalVectorReader
// /////////////////////////////////////////////////////////////////

axlFieldParametricSurfaceNormalVectorReader::axlFieldParametricSurfaceNormalVectorReader(void)
{
    this->setObjectName(this->description());
}

axlFieldParametricSurfaceNormalVectorReader::~axlFieldParametricSurfaceNormalVectorReader(void)
{

}

QString axlFieldParametricSurfaceNormalVectorReader::identifier(void) const
{
    return "axlFieldParametricSurfaceNormalVectorReader";
}

QString axlFieldParametricSurfaceNormalVectorReader::description(void) const
{
    return "axlFieldParametricSurfaceNormalVectorReader";
}

QStringList axlFieldParametricSurfaceNormalVectorReader::handled(void) const
{
    return QStringList() << "axlFieldParametricNormalVector";
}

bool axlFieldParametricSurfaceNormalVectorReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldParametricSurfaceNormalVectorReader", QStringList(), createaxlFieldParametricSurfaceNormalVectorReader);
}

bool axlFieldParametricSurfaceNormalVectorReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldParametricSurfaceNormalVectorReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldParametricNormalVector.
axlAbstractData *axlFieldParametricSurfaceNormalVectorReader::read(const QDomNode& node)
{

    QDomElement element = node.toElement();
    axlFieldParametricNormalVector *field = NULL;

    // field type : the type corresponds to the identifier, use factory to initialize field.
    QString type = element.attribute("type");
    if(!type.isEmpty())
    {
        field = dynamic_cast<axlFieldParametricNormalVector *>(dtkAbstractDataFactory::instance()->create(type));
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

dtkAbstractData *axlFieldParametricSurfaceNormalVectorReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
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



dtkAbstractDataReader *createaxlFieldParametricSurfaceNormalVectorReader(void)
{
    return new axlFieldParametricSurfaceNormalVectorReader;
}


