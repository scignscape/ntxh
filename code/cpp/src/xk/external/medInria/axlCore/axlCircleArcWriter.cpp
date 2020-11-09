/* axlCircleArcWriter.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008 - Valentin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Valentin Michelet
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlCircleArcWriter.h"

#include <axlCore/axlCircleArc.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlCircleArcWriter
// /////////////////////////////////////////////////////////////////

axlCircleArcWriter::axlCircleArcWriter(void) {
    this->setObjectName(this->description());
}

axlCircleArcWriter::~axlCircleArcWriter(void) {
}

QString axlCircleArcWriter::identifier(void) const {
    return "axlCircleArcWriter";
}

QString axlCircleArcWriter::description(void) const {
    return "axlCircleArcWriter";
}

QStringList axlCircleArcWriter::handled(void) const {
    return QStringList() << "axlCircleArc";
}

bool axlCircleArcWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlCircleArcWriter", QStringList(), createaxlCircleArcWriter);
}

bool axlCircleArcWriter::accept(dtkAbstractData *data) {
    axlCircleArc* arc = dynamic_cast<axlCircleArc*>(data);
    if (arc)
        return true;
    return false;
}

bool axlCircleArcWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlCircleArcWriter::write(QDomDocument *doc, dtkAbstractData *data) {

    // Get circle arc pointer
    axlCircleArc* arc = dynamic_cast<axlCircleArc*>(data);

    // Create name
    QDomElement arcElement = doc->createElement("arc");
    arcElement.setAttribute("name", arc->name());

    // Create size
    arcElement.setAttribute("size", QString::number(arc->size()));

    // Create color
    QColor qcolor = arc->color();
    QString color;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(arc->opacity());
    arcElement.setAttribute("color", color);

    // Create shader
    QString shader = arc->shader();
    QFileInfo shaderFileInfo(shader);
    arcElement.setAttribute("shader", shaderFileInfo.fileName());

    // Write arc
    // Create first point
    QDomElement point1Element = doc->createElement("point1");
    QString point1Str;
    QTextStream(&point1Str) << QString::number(arc->point1().x()) << " "
                            << QString::number(arc->point1().y()) << " "
                            << QString::number(arc->point1().z());
    QDomText point1DomText = doc->createTextNode(point1Str);
    point1Element.appendChild(point1DomText);

    arcElement.appendChild(point1Element);

    // Create second point
    QDomElement Point2Element = doc->createElement("point2");
    QString Point2Str;
    QTextStream(&Point2Str) << QString::number(arc->point2().x()) << " "
                            << QString::number(arc->point2().y()) << " "
                            << QString::number(arc->point2().z());
    QDomText Point2DomText = doc->createTextNode(Point2Str);
    Point2Element.appendChild(Point2DomText);

    arcElement.appendChild(Point2Element);

    // Create center
    QDomElement centerElement = doc->createElement("center");
    QString centerStr;
    QTextStream(&centerStr) << QString::number(arc->center().x()) << " "
                            << QString::number(arc->center().y()) << " "
                            << QString::number(arc->center().z());
    QDomText centerDomText = doc->createTextNode(centerStr);
    centerElement.appendChild(centerDomText);

    arcElement.appendChild(centerElement);

    // Create normal
    QDomElement normalElement = doc->createElement("normal");
    QString normalStr;
    QTextStream(&normalStr) << QString::number(arc->normal().x()) << " "
                            << QString::number(arc->normal().y()) << " "
                            << QString::number(arc->normal().z());
    QDomText normalDomText = doc->createTextNode(normalStr);
    normalElement.appendChild(normalDomText);

    arcElement.appendChild(normalElement);

    // Create counter clockwise bool
    QDomElement cCWElement = doc->createElement("ccw");
    QString cCWStr;
    QTextStream(&cCWStr) << arc->isDirect();
    QDomText cCWDomText = doc->createTextNode(cCWStr);
    cCWElement.appendChild(cCWDomText);

    arcElement.appendChild(cCWElement);


    // Write fields if exist.
    if(!arc->fields().isEmpty()){
        foreach(axlAbstractField *field, arc->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            arcElement.appendChild(fieldElement);
        }
    }

    return arcElement;
}

QDomElement axlCircleArcWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if (!axl_writer)
        return element;
    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlCircleArcWriter(void) {
    return new axlCircleArcWriter;
}
