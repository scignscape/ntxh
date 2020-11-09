/* axlFieldSpatialPointDistanceWriter.cpp ---
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

#include "axlFieldSpatialPointDistanceWriter.h"

#include <axlCore/axlFieldSpatialPointDistance.h>
#include <axlCore/axlPoint.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldSpatialPointDistanceWriter
// /////////////////////////////////////////////////////////////////

axlFieldSpatialPointDistanceWriter::axlFieldSpatialPointDistanceWriter(void):axlAbstractDataWriter()
{
    this->setObjectName(this->description());
}

axlFieldSpatialPointDistanceWriter::~axlFieldSpatialPointDistanceWriter(void)
{

}

QString axlFieldSpatialPointDistanceWriter::identifier(void) const
{
    return "axlFieldSpatialPointDistanceWriter";
}

QString axlFieldSpatialPointDistanceWriter::description(void) const
{
    return "axlFieldSpatialPointDistanceWriter";
}

QStringList axlFieldSpatialPointDistanceWriter::handled(void) const
{
    return QStringList() << "axlAbstractField" << "axlAbstractFieldSpatial" << "axlFieldSpatialCoordinates";
}

bool axlFieldSpatialPointDistanceWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldSpatialPointDistanceWriter", QStringList(), createaxlFieldSpatialPointDistanceWriter);
}

bool axlFieldSpatialPointDistanceWriter::accept(dtkAbstractData *data)
{
    axlFieldSpatialPointDistance *spatialField = dynamic_cast<axlFieldSpatialPointDistance *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldSpatialPointDistanceWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldSpatialPointDistanceWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlFieldSpatialPointDistance *field = dynamic_cast<axlFieldSpatialPointDistance *>(data);

    QDomElement fieldElement = doc->createElement("field");

    /////Type
    fieldElement.setAttribute("type", field->identifier());

    //// Inputs : reference point to compute distance function.

        QDomElement parameter = doc->createElement("input");
        parameter.setAttribute("xcoordinate", field->getPoint()->x());
        parameter.setAttribute("ycoordinate", field->getPoint()->y());
        parameter.setAttribute("zcoordinate", field->getPoint()->z());
        parameter.setAttribute("type", "data");
        fieldElement.appendChild(parameter);

    return fieldElement;
}



QDomElement axlFieldSpatialPointDistanceWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldSpatialPointDistanceWriter(void)
{
    return new axlFieldSpatialPointDistanceWriter;
}

