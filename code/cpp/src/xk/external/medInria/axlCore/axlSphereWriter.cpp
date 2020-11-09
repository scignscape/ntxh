/* axlSphereWriter.cpp ---
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

#include "axlSphereWriter.h"

#include <axlCore/axlSphere.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlSphereWriter
// /////////////////////////////////////////////////////////////////

axlSphereWriter::axlSphereWriter(void)
{
    this->setObjectName(this->description());
}

axlSphereWriter::~axlSphereWriter(void)
{

}

QString axlSphereWriter::identifier(void) const
{
    return "axlSphereWriter";
}

QString axlSphereWriter::description(void) const
{
    return "axlSphereWriter";
}

QStringList axlSphereWriter::handled(void) const
{
    return QStringList() << "axlSphere";
}

bool axlSphereWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlSphereWriter", QStringList(), createaxlSphereWriter);
}

bool axlSphereWriter::accept(dtkAbstractData *data)
{
    axlSphere *sphere = dynamic_cast<axlSphere *>(data);
    if(sphere)
        return true;

    return false;
}

bool axlSphereWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlSphereWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlSphere *sphere = dynamic_cast<axlSphere *>(data);

    /////Name
    QDomElement sphereElement = doc->createElement("sphere");
    sphereElement.setAttribute("name",sphere->name());


    /////Size
    sphereElement.setAttribute("size", QString::number(sphere->size()));



    ////Color
    QColor qcolor = sphere->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(sphere->opacity());
    sphereElement.setAttribute("color", color);

    ////Shader
    QString shader = sphere->shader();
    QFileInfo shaderFileInfo(shader);
    sphereElement.setAttribute("shader", shaderFileInfo.fileName());

    //Write sphere
    //center
    QDomElement center = doc->createElement("center");
    QString centerStr;
    QTextStream(&centerStr) << QString::number(sphere->x()) << " "<< QString::number(sphere->y()) << " "<< QString::number(sphere->z());
    QDomText centerDomText = doc->createTextNode(centerStr);
    center.appendChild(centerDomText);

    sphereElement.appendChild(center);

    QDomElement radius = doc->createElement("radius");
    QString radiusStr;
    QTextStream(&radiusStr) << QString::number(sphere->radius());
    QDomText radiusDomText = doc->createTextNode(radiusStr);
    radius.appendChild(radiusDomText);

    sphereElement.appendChild(radius);

    //Write fields if exist.
    if(!sphere->fields().isEmpty()){
        foreach(axlAbstractField *field, sphere->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            sphereElement.appendChild(fieldElement);
        }
    }


    return sphereElement;
}


QDomElement axlSphereWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlSphereWriter(void)
{
    return new axlSphereWriter;
}
