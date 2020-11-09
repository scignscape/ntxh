/* axlFieldParametricCurveWriter.cpp ---
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

#include "axlFieldParametricCurveWriter.h"

#include <axlCore/axlFieldParametricCurve.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricCurveWriter
// /////////////////////////////////////////////////////////////////

axlFieldParametricCurveWriter::axlFieldParametricCurveWriter(void):axlAbstractDataWriter()
{
    this->setObjectName(this->description());
}

axlFieldParametricCurveWriter::~axlFieldParametricCurveWriter(void)
{

}

QString axlFieldParametricCurveWriter::identifier(void) const
{
    return "axlFieldParametricCurveWriter";
}

QString axlFieldParametricCurveWriter::description(void) const
{
    return "axlFieldParametricCurveWriter";
}

QStringList axlFieldParametricCurveWriter::handled(void) const
{
    return QStringList() <<  "axlFieldParametricCurve";
}

bool axlFieldParametricCurveWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldParametricCurveWriter", QStringList(), createaxlFieldParametricCurveWriter);
}

bool axlFieldParametricCurveWriter::accept(dtkAbstractData *data)
{
    axlFieldParametricCurve *spatialField = dynamic_cast<axlFieldParametricCurve *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldParametricCurveWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldParametricCurveWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlFieldParametricCurve *field = dynamic_cast<axlFieldParametricCurve *>(data);

    QDomElement fieldElement = doc->createElement("field");

    /////Type
    fieldElement.setAttribute("type", field->identifier());

    ////Parametric Function
    axlAbstractDataWriter *function_writer = dynamic_cast<axlAbstractDataWriter *>(dtkAbstractDataFactory::instance()->writer(field->getFunction()->identifier()+"Writer"));
    QDomElement functionElement = function_writer->write(doc, field->getFunction());
    fieldElement.appendChild(functionElement);


    return fieldElement;
}



QDomElement axlFieldParametricCurveWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldParametricCurveWriter(void)
{
    return new axlFieldParametricCurveWriter;
}

