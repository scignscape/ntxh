/* axlFieldParametricSurfaceNormalVectorWriter.cpp ---
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

#include "axlFieldParametricSurfaceNormalVectorWriter.h"

#include <axlCore/axlFieldParametricNormalVector.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricSurfaceNormalVectorWriter
// /////////////////////////////////////////////////////////////////

axlFieldParametricSurfaceNormalVectorWriter::axlFieldParametricSurfaceNormalVectorWriter(void):axlAbstractDataWriter()
{
    this->setObjectName(this->description());
}

axlFieldParametricSurfaceNormalVectorWriter::~axlFieldParametricSurfaceNormalVectorWriter(void)
{

}

QString axlFieldParametricSurfaceNormalVectorWriter::identifier(void) const
{
    return "axlFieldParametricSurfaceNormalVectorWriter";
}

QString axlFieldParametricSurfaceNormalVectorWriter::description(void) const
{
    return "axlFieldParametricSurfaceNormalVectorWriter";
}

QStringList axlFieldParametricSurfaceNormalVectorWriter::handled(void) const
{
    return QStringList() <<  "axlFieldParametricNormalVector";
}

bool axlFieldParametricSurfaceNormalVectorWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldParametricSurfaceNormalVectorWriter", QStringList(), createaxlFieldParametricSurfaceNormalVectorWriter);
}

bool axlFieldParametricSurfaceNormalVectorWriter::accept(dtkAbstractData *data)
{
    axlFieldParametricNormalVector *spatialField = dynamic_cast<axlFieldParametricNormalVector *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldParametricSurfaceNormalVectorWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldParametricSurfaceNormalVectorWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlFieldParametricNormalVector *field = dynamic_cast<axlFieldParametricNormalVector *>(data);

    QDomElement fieldElement = doc->createElement("field");

    /////Type
    fieldElement.setAttribute("type", field->identifier());

    return fieldElement;
}



QDomElement axlFieldParametricSurfaceNormalVectorWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldParametricSurfaceNormalVectorWriter(void)
{
    return new axlFieldParametricSurfaceNormalVectorWriter;
}


