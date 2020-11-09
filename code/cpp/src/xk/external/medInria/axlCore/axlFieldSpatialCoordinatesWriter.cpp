/* axlFieldSpatialCoordinatesWriter.cpp ---
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

#include "axlFieldSpatialCoordinatesWriter.h"

#include <axlCore/axlFieldSpatialCoordinates.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldSpatialCoordinatesWriter
// /////////////////////////////////////////////////////////////////

axlFieldSpatialCoordinatesWriter::axlFieldSpatialCoordinatesWriter(void):axlAbstractDataWriter()
{
    this->setObjectName(this->description());
}

axlFieldSpatialCoordinatesWriter::~axlFieldSpatialCoordinatesWriter(void)
{

}

QString axlFieldSpatialCoordinatesWriter::identifier(void) const
{
    return "axlFieldSpatialCoordinatesWriter";
}

QString axlFieldSpatialCoordinatesWriter::description(void) const
{
    return "axlFieldSpatialCoordinatesWriter";
}

QStringList axlFieldSpatialCoordinatesWriter::handled(void) const
{
    return QStringList() << "axlAbstractField" << "axlAbstractFieldSpatial" << "axlFieldSpatialCoordinates";
}

bool axlFieldSpatialCoordinatesWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldSpatialCoordinatesWriter", QStringList(), createaxlFieldSpatialCoordinatesWriter);
}

bool axlFieldSpatialCoordinatesWriter::accept(dtkAbstractData *data)
{
    axlFieldSpatialCoordinates *spatialField = dynamic_cast<axlFieldSpatialCoordinates *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldSpatialCoordinatesWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldSpatialCoordinatesWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlFieldSpatialCoordinates *field = dynamic_cast<axlFieldSpatialCoordinates *>(data);

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



QDomElement axlFieldSpatialCoordinatesWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldSpatialCoordinatesWriter(void)
{
    return new axlFieldSpatialCoordinatesWriter;
}


