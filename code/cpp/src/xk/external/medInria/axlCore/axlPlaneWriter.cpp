/* axlPlaneWriter.cpp ---
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

#include "axlPlaneWriter.h"

#include <axlCore/axlPlane.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlPlaneWriter
// /////////////////////////////////////////////////////////////////

axlPlaneWriter::axlPlaneWriter(void)
{
    this->setObjectName(this->description());
}

axlPlaneWriter::~axlPlaneWriter(void)
{

}

QString axlPlaneWriter::identifier(void) const
{
    return "axlPlaneWriter";
}

QString axlPlaneWriter::description(void) const
{
    return "axlPlaneWriter";
}

QStringList axlPlaneWriter::handled(void) const
{
    return QStringList() << "axlPlane";
}

bool axlPlaneWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlPlaneWriter", QStringList(), createaxlPlaneWriter);
}

bool axlPlaneWriter::accept(dtkAbstractData *data)
{
    axlPlane *plane = dynamic_cast<axlPlane *>(data);
    if(plane)
        return true;

    return false;
}

bool axlPlaneWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlPlaneWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlPlane *plane = dynamic_cast<axlPlane *>(data);

    /////Name
    QDomElement planeElement = doc->createElement("plane");
    planeElement.setAttribute("name",plane->name());


    /////Size
    planeElement.setAttribute("size", QString::number(plane->size()));



    ////Color
    QColor qcolor = plane->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(plane->opacity());
    planeElement.setAttribute("color", color);

    ////Shader
    QString shader = plane->shader();
    QFileInfo shaderFileInfo(shader);
    planeElement.setAttribute("shader", shaderFileInfo.fileName());

    //Write plane
    //point
    QDomElement point = doc->createElement("point");
    QString pointStr;
    QTextStream(&pointStr) << QString::number(plane->point()->x()) << " "<< QString::number(plane->point()->y()) << " "<< QString::number(plane->point()->z());
    QDomText pointDomText = doc->createTextNode(pointStr);
    point.appendChild(pointDomText);

    planeElement.appendChild(point);

    //point
    QDomElement normal = doc->createElement("normal");
    QString normalStr;
    QTextStream(&normalStr) << QString::number(plane->normal()->x()) << " "<< QString::number(plane->normal()->y()) << " "<< QString::number(plane->normal()->z());
    QDomText normalDomText = doc->createTextNode(normalStr);
    normal.appendChild(normalDomText);

    planeElement.appendChild(normal);


    //Write fields if exist.
    if(!plane->fields().isEmpty()){
        foreach(axlAbstractField *field, plane->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            planeElement.appendChild(fieldElement);
        }
    }


    return planeElement;
}


QDomElement axlPlaneWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlPlaneWriter(void)
{
    return new axlPlaneWriter;
}
