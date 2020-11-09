/* axlLineWriter.cpp ---
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

#include "axlLineWriter.h"

#include <axlCore/axlLine.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlLineWriter
// /////////////////////////////////////////////////////////////////

axlLineWriter::axlLineWriter(void) {
    this->setObjectName(this->description());
}

axlLineWriter::~axlLineWriter(void) {
}

QString axlLineWriter::identifier(void) const {
    return "axlLineWriter";
}

QString axlLineWriter::description(void) const {
    return "axlLineWriter";
}

QStringList axlLineWriter::handled(void) const {
    return QStringList() << "axlLine";
}

bool axlLineWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlLineWriter", QStringList(), createaxlLineWriter);
}

bool axlLineWriter::accept(dtkAbstractData *data) {
    axlLine *line = dynamic_cast<axlLine *>(data);
    if (line)
        return true;

    return false;
}

bool axlLineWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlLineWriter::write(QDomDocument *doc, dtkAbstractData *data) {
    // Get line
    axlLine *line = dynamic_cast<axlLine *>(data);

    // Create name
    QDomElement lineElement = doc->createElement("line");
    lineElement.setAttribute("name",line->name());

    // Create size
    lineElement.setAttribute("size", QString::number(line->size()));

    // Create color
    QColor qcolor = line->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(line->opacity());
    lineElement.setAttribute("color", color);

    // Create shader
    QString shader = line->shader();
    QFileInfo shaderFileInfo(shader);
    lineElement.setAttribute("shader", shaderFileInfo.fileName());

    // Write line
    // Create first point
    QDomElement firstPoint = doc->createElement("point");
    QString firstPointStr;
    QTextStream(&firstPointStr) << QString::number(line->firstPoint()->x()) << " "<< QString::number(line->firstPoint()->y()) << " "<< QString::number(line->firstPoint()->z());
    QDomText firstPointDomText = doc->createTextNode(firstPointStr);
    firstPoint.appendChild(firstPointDomText);

    lineElement.appendChild(firstPoint);

    // Create second point
    QDomElement secondPoint = doc->createElement("point");
    QString secondPointStr;
    QTextStream(&secondPointStr) << QString::number(line->secondPoint()->x()) << " "<< QString::number(line->secondPoint()->y()) << " "<< QString::number(line->secondPoint()->z());
    QDomText secondPointDomText = doc->createTextNode(secondPointStr);
    secondPoint.appendChild(secondPointDomText);

    lineElement.appendChild(secondPoint);

    // Write fields if any
    if(!line->fields().isEmpty()){
        foreach(axlAbstractField *field, line->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            lineElement.appendChild(fieldElement);
        }
    }

    return lineElement;
}


QDomElement axlLineWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlLineWriter(void) {
    return new axlLineWriter;
}
