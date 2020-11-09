/* axlFieldParametricVolumeTangentVectorWriter.cpp ---
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

#include "axlFieldParametricVolumeTangentVectorWriter.h"

#include <axlCore/axlFieldParametricVolumeTangentVector.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricVolumeTangentVectorWriter
// /////////////////////////////////////////////////////////////////

axlFieldParametricVolumeTangentVectorWriter::axlFieldParametricVolumeTangentVectorWriter(void):axlAbstractDataWriter()
{
    this->setObjectName(this->description());
}

axlFieldParametricVolumeTangentVectorWriter::~axlFieldParametricVolumeTangentVectorWriter(void)
{

}

QString axlFieldParametricVolumeTangentVectorWriter::identifier(void) const
{
    return "axlFieldParametricVolumeTangentVectorWriter";
}

QString axlFieldParametricVolumeTangentVectorWriter::description(void) const
{
    return "axlFieldParametricVolumeTangentVectorWriter";
}

QStringList axlFieldParametricVolumeTangentVectorWriter::handled(void) const
{
    return QStringList() << "axlFieldParametricVolumeTangentVector";
}

bool axlFieldParametricVolumeTangentVectorWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldParametricVolumeTangentVectorWriter", QStringList(), createaxlFieldParametricVolumeTangentVectorWriter);
}

bool axlFieldParametricVolumeTangentVectorWriter::accept(dtkAbstractData *data)
{
    axlFieldParametricVolumeTangentVector *spatialField = dynamic_cast<axlFieldParametricVolumeTangentVector *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldParametricVolumeTangentVectorWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldParametricVolumeTangentVectorWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlFieldParametricVolumeTangentVector *field = dynamic_cast<axlFieldParametricVolumeTangentVector *>(data);

    QDomElement fieldElement = doc->createElement("field");

    /////Type
    fieldElement.setAttribute("type", field->identifier());

    //// Parameters direction Values
    for(int i = 0; i < 3;i++){

        QDomElement parameter = doc->createElement("parameter");
        parameter.setAttribute("value", QString::number(field->parameter(i)));
        parameter.setAttribute("channel", QString::number(i));
        parameter.setAttribute("type", "double");
        fieldElement.appendChild(parameter);

    }

    return fieldElement;
}



QDomElement axlFieldParametricVolumeTangentVectorWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldParametricVolumeTangentVectorWriter(void)
{
    return new axlFieldParametricVolumeTangentVectorWriter;
}

