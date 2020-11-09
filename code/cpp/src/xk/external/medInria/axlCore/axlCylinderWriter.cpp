/* axlCylinderWriter.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008-2011 - Meriadeg Perrinel, Inria.
 * Created: Wed Sep 21 11:36:52 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Sep 21 12:11:29 2011 (+0200)
 *           By: Meriadeg Perrinel
 *     Update #: 88
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlCylinderWriter.h"

#include <axlCore/axlCylinder.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlCylinderWriter
// /////////////////////////////////////////////////////////////////

axlCylinderWriter::axlCylinderWriter(void)
{
    this->setObjectName(this->description());
}

axlCylinderWriter::~axlCylinderWriter(void)
{

}

QString axlCylinderWriter::identifier(void) const
{
    return "axlCylinderWriter";
}

QString axlCylinderWriter::description(void) const
{
    return "axlCylinderWriter";
}

QStringList axlCylinderWriter::handled(void) const
{
    return QStringList() << "axlCylinder";
}

bool axlCylinderWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlCylinderWriter", QStringList(), createaxlCylinderWriter);
}

bool axlCylinderWriter::accept(dtkAbstractData *data)
{
    axlCylinder *cylinder = dynamic_cast<axlCylinder *>(data);
    if(cylinder)
        return true;

    return false;
}

bool axlCylinderWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlCylinderWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlCylinder *cylinder = dynamic_cast<axlCylinder *>(data);

    /////Name
    QDomElement cylinderElement = doc->createElement("cylinder");
    cylinderElement.setAttribute("name",cylinder->name());


    /////Size
    cylinderElement.setAttribute("size", QString::number(cylinder->size()));



    ////Color
    QColor qcolor = cylinder->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(cylinder->opacity());
    cylinderElement.setAttribute("color", color);

    ////Shader
    QString shader = cylinder->shader();
    QFileInfo shaderFileInfo(shader);
    cylinderElement.setAttribute("shader", shaderFileInfo.fileName());

    //Write cylinder
    //firstPoint
    QDomElement firstPoint = doc->createElement("point");
    QString firstPointStr;
    QTextStream(&firstPointStr) << QString::number(cylinder->firstPoint()->x()) << " "<< QString::number(cylinder->firstPoint()->y()) << " "<< QString::number(cylinder->firstPoint()->z());
    QDomText firstPointDomText = doc->createTextNode(firstPointStr);
    firstPoint.appendChild(firstPointDomText);

    cylinderElement.appendChild(firstPoint);

    //secondPoint
    QDomElement secondPoint = doc->createElement("point");
    QString secondPointStr;
    QTextStream(&secondPointStr) << QString::number(cylinder->secondPoint()->x()) << " "<< QString::number(cylinder->secondPoint()->y()) << " "<< QString::number(cylinder->secondPoint()->z());
    QDomText secondPointDomText = doc->createTextNode(secondPointStr);
    secondPoint.appendChild(secondPointDomText);

    cylinderElement.appendChild(secondPoint);

    //radius
    QDomElement radius = doc->createElement("radius");
    QString radiusStr;
    QTextStream(&radiusStr) << QString::number(cylinder->radius());
    QDomText radiusDomText = doc->createTextNode(radiusStr);
    radius.appendChild(radiusDomText);

    cylinderElement.appendChild(radius);


    //Write fields if exist.
    if(!cylinder->fields().isEmpty()){
        foreach(axlAbstractField *field, cylinder->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            cylinderElement.appendChild(fieldElement);
        }
    }


    return cylinderElement;
}


QDomElement axlCylinderWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlCylinderWriter(void)
{
    return new axlCylinderWriter;
}
