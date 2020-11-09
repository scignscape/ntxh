/* axlFieldParametricCurveTangentVectorWriter.cpp ---
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

#include "axlFieldParametricCurveTangentVectorWriter.h"

#include <axlCore/axlFieldParametricCurveTangentVector.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricCurveTangentVectorWriter
// /////////////////////////////////////////////////////////////////

axlFieldParametricCurveTangentVectorWriter::axlFieldParametricCurveTangentVectorWriter(void):axlAbstractDataWriter()
{
    this->setObjectName(this->description());
}

axlFieldParametricCurveTangentVectorWriter::~axlFieldParametricCurveTangentVectorWriter(void)
{

}

QString axlFieldParametricCurveTangentVectorWriter::identifier(void) const
{
    return "axlFieldParametricCurveTangentVectorWriter";
}

QString axlFieldParametricCurveTangentVectorWriter::description(void) const
{
    return "axlFieldParametricCurveTangentVectorWriter";
}

QStringList axlFieldParametricCurveTangentVectorWriter::handled(void) const
{
    return QStringList() <<  "axlFieldParametricCurveTangentVector";
}

bool axlFieldParametricCurveTangentVectorWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldParametricCurveTangentVectorWriter", QStringList(), createaxlFieldParametricCurveTangentVectorWriter);
}

bool axlFieldParametricCurveTangentVectorWriter::accept(dtkAbstractData *data)
{
    axlFieldParametricCurveTangentVector *spatialField = dynamic_cast<axlFieldParametricCurveTangentVector *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldParametricCurveTangentVectorWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldParametricCurveTangentVectorWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlFieldParametricCurveTangentVector *field = dynamic_cast<axlFieldParametricCurveTangentVector *>(data);

    QDomElement fieldElement = doc->createElement("field");

    /////Type
    fieldElement.setAttribute("type", field->identifier());

    return fieldElement;
}



QDomElement axlFieldParametricCurveTangentVectorWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldParametricCurveTangentVectorWriter(void)
{
    return new axlFieldParametricCurveTangentVectorWriter;
}

