/* axlConeWriter.cpp ---
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

#include "axlConeWriter.h"

#include <axlCore/axlCone.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlConeWriter
// /////////////////////////////////////////////////////////////////

axlConeWriter::axlConeWriter(void)
{
    this->setObjectName(this->description());
}

axlConeWriter::~axlConeWriter(void)
{

}

QString axlConeWriter::identifier(void) const
{
    return "axlConeWriter";
}

QString axlConeWriter::description(void) const
{
    return "axlConeWriter";
}

QStringList axlConeWriter::handled(void) const
{
    return QStringList() << "axlCone";
}

bool axlConeWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlConeWriter", QStringList(), createaxlConeWriter);
}

bool axlConeWriter::accept(dtkAbstractData *data)
{
    axlCone *cone = dynamic_cast<axlCone *>(data);
    if(cone)
        return true;

    return false;
}

bool axlConeWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlConeWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlCone *cone = dynamic_cast<axlCone *>(data);

    /////Name
    QDomElement coneElement = doc->createElement("cone");
    coneElement.setAttribute("name",cone->name());


    /////Size
    coneElement.setAttribute("size", QString::number(cone->size()));



    ////Color
    QColor qcolor = cone->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(cone->opacity());
    coneElement.setAttribute("color", color);

    ////Shader
    QString shader = cone->shader();
    QFileInfo shaderFileInfo(shader);
    coneElement.setAttribute("shader", shaderFileInfo.fileName());

    //Write cone
    //apex
    QDomElement apex = doc->createElement("point");
    QString apexStr;
    QTextStream(&apexStr) << QString::number(cone->apex()->x()) << " "<< QString::number(cone->apex()->y()) << " "<< QString::number(cone->apex()->z());
    QDomText apexDomText = doc->createTextNode(apexStr);
    apex.appendChild(apexDomText);

    coneElement.appendChild(apex);

    //apex
    QDomElement basePoint = doc->createElement("point");
    QString basePointStr;
    QTextStream(&basePointStr) << QString::number(cone->basePoint()->x()) << " "<< QString::number(cone->basePoint()->y()) << " "<< QString::number(cone->basePoint()->z());
    QDomText basePointDomText = doc->createTextNode(basePointStr);
    basePoint.appendChild(basePointDomText);

    coneElement.appendChild(basePoint);

    //radius
    QDomElement radius = doc->createElement("radius");
    QString radiusStr;
    QTextStream(&radiusStr) << QString::number(cone->radius());
    QDomText radiusDomText = doc->createTextNode(radiusStr);
    radius.appendChild(radiusDomText);

    coneElement.appendChild(radius);

    //Write fields if exist.
    if(!cone->fields().isEmpty()){
        foreach(axlAbstractField *field, cone->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            coneElement.appendChild(fieldElement);
        }
    }


    return coneElement;
}


QDomElement axlConeWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlConeWriter(void)
{
    return new axlConeWriter;
}
