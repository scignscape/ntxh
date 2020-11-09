/* axlPointWriter.cpp ---
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

#include "axlPointWriter.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlPointWriter
// /////////////////////////////////////////////////////////////////

axlPointWriter::axlPointWriter(void)
{
    this->setObjectName(this->description());
}

axlPointWriter::~axlPointWriter(void)
{

}

QString axlPointWriter::identifier(void) const
{
    return "axlPointWriter";
}

QString axlPointWriter::description(void) const
{
    return "axlPointWriter";
}

QStringList axlPointWriter::handled(void) const
{
    return QStringList() << "axlPoint";
}

bool axlPointWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlPointWriter", QStringList(), createaxlPointWriter);
}

bool axlPointWriter::accept(dtkAbstractData *data)
{
    axlPoint *point = dynamic_cast<axlPoint *>(data);
    if(point)
        return true;

    return false;
}

bool axlPointWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlPointWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlPoint *point = dynamic_cast<axlPoint *>(data);

    /////Name
    QDomElement pointElement = doc->createElement("point");
    pointElement.setAttribute("name",point->name());


    /////Size
    pointElement.setAttribute("size", QString::number(point->size()));



    ////Color
    QColor qcolor = point->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue());
    if(point->opacity()!=1.)
        QTextStream(&color) << " " << QString::number(point->opacity());
    pointElement.setAttribute("color", color);

    ////Shader
    QString shader = point->shader();
    QFileInfo shaderFileInfo(shader);
    pointElement.setAttribute("shader", shaderFileInfo.fileName());

    //Write point
    QString pointValue;
    QTextStream(&pointValue) << QString::number(point->x()) << " "<< QString::number(point->y()) << " "<< QString::number(point->z());

    QDomText pointDomText = doc->createTextNode(pointValue);

    pointElement.appendChild(pointDomText);

    //Write fields if exist.
    if(!point->fields().isEmpty()){
        foreach(axlAbstractField *field, point->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            pointElement.appendChild(fieldElement);
        }
    }

    return pointElement;
}


QDomElement axlPointWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlPointWriter(void)
{
    return new axlPointWriter;
}
