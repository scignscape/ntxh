/* axlFieldParametricSurfaceTangentVectorWriter.cpp ---
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

#include "axlFieldParametricSurfaceTangentVectorWriter.h"

#include <axlCore/axlFieldParametricSurfaceTangentVector.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricSurfaceTangentVectorWriter
// /////////////////////////////////////////////////////////////////

axlFieldParametricSurfaceTangentVectorWriter::axlFieldParametricSurfaceTangentVectorWriter(void):axlAbstractDataWriter()
{
    this->setObjectName(this->description());
}

axlFieldParametricSurfaceTangentVectorWriter::~axlFieldParametricSurfaceTangentVectorWriter(void)
{

}

QString axlFieldParametricSurfaceTangentVectorWriter::identifier(void) const
{
    return "axlFieldParametricSurfaceTangentVectorWriter";
}

QString axlFieldParametricSurfaceTangentVectorWriter::description(void) const
{
    return "axlFieldParametricSurfaceTangentVectorWriter";
}

QStringList axlFieldParametricSurfaceTangentVectorWriter::handled(void) const
{
    return QStringList() << "axlFieldParametricSurfaceTangentVector";
}

bool axlFieldParametricSurfaceTangentVectorWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldParametricSurfaceTangentVectorWriter", QStringList(), createaxlFieldParametricSurfaceTangentVectorWriter);
}

bool axlFieldParametricSurfaceTangentVectorWriter::accept(dtkAbstractData *data)
{
    axlFieldParametricSurfaceTangentVector *spatialField = dynamic_cast<axlFieldParametricSurfaceTangentVector *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldParametricSurfaceTangentVectorWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldParametricSurfaceTangentVectorWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlFieldParametricSurfaceTangentVector *field = dynamic_cast<axlFieldParametricSurfaceTangentVector *>(data);

    QDomElement fieldElement = doc->createElement("field");

    /////Type
    fieldElement.setAttribute("type", field->identifier());

    //// Parameters direction Values
    for(int i = 0; i < 2;i++){

        QDomElement parameter = doc->createElement("parameter");
        parameter.setAttribute("value", QString::number(field->parameter(i)));
        parameter.setAttribute("channel", QString::number(i));
        parameter.setAttribute("type", "double");
        fieldElement.appendChild(parameter);

    }

    return fieldElement;
}



QDomElement axlFieldParametricSurfaceTangentVectorWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldParametricSurfaceTangentVectorWriter(void)
{
    return new axlFieldParametricSurfaceTangentVectorWriter;
}


