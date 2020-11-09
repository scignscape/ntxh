/* axlTorusWriter.cpp ---
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

#include "axlTorusWriter.h"

#include <axlCore/axlTorus.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlTorusWriter
// /////////////////////////////////////////////////////////////////

axlTorusWriter::axlTorusWriter(void) {
    this->setObjectName(this->description());
}

axlTorusWriter::~axlTorusWriter(void) {
}

QString axlTorusWriter::identifier(void) const {
    return "axlTorusWriter";
}

QString axlTorusWriter::description(void) const {
    return "axlTorusWriter";
}

QStringList axlTorusWriter::handled(void) const {
    return QStringList() << "axlTorus";
}

bool axlTorusWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlTorusWriter", QStringList(), createaxlTorusWriter);
}

bool axlTorusWriter::accept(dtkAbstractData *data) {
    axlTorus* torus = dynamic_cast<axlTorus*>(data);
    if (torus)
        return true;
    return false;
}

bool axlTorusWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlTorusWriter::write(QDomDocument *doc, dtkAbstractData *data) {

    axlTorus* torus = dynamic_cast<axlTorus*>(data);

    /////Name
    QDomElement torusElement = doc->createElement("torus");
    torusElement.setAttribute("name", torus->name());

    /////Size
    torusElement.setAttribute("size", QString::number(torus->size()));

    ////Color
    QColor qcolor = torus->color();
    QString color;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(torus->opacity());
    torusElement.setAttribute("color", color);

    ////Shader
    QString shader = torus->shader();
    QFileInfo shaderFileInfo(shader);
    torusElement.setAttribute("shader", shaderFileInfo.fileName());

    //Write torus
    //Center
    QDomElement centerElement = doc->createElement("center");
    QString centerStr;
    QTextStream(&centerStr) << QString::number(torus->centerPoint()->x()) << " "
                            << QString::number(torus->centerPoint()->y()) << " "
                            << QString::number(torus->centerPoint()->z());
    QDomText centerDomText = doc->createTextNode(centerStr);
    centerElement.appendChild(centerDomText);

    torusElement.appendChild(centerElement);

    //Direction
    QDomElement directionElement = doc->createElement("direction");
    QString directionStr;
    QTextStream(&directionStr) << QString::number(torus->direction()->x()) << " "
                               << QString::number(torus->direction()->y()) << " "
                               << QString::number(torus->direction()->z());
    QDomText directionDomText = doc->createTextNode(directionStr);
    directionElement.appendChild(directionDomText);

    torusElement.appendChild(directionElement);

    //Ring Radius
    QDomElement ringRadiusElement = doc->createElement("ringRadius");
    QString ringRadiusStr;
    QTextStream(&ringRadiusStr) << QString::number(torus->ringRadius());
    QDomText ringRadiusDomText = doc->createTextNode(ringRadiusStr);
    ringRadiusElement.appendChild(ringRadiusDomText);

    torusElement.appendChild(ringRadiusElement);

    //Cross Section Radius
    QDomElement crossSectionRadiusElement = doc->createElement("crossSectionRadius");
    QString crossSectionRadiusStr;
    QTextStream(&crossSectionRadiusStr) << QString::number(torus->crossSectionRadius());
    QDomText crossSectionRadiusDomText = doc->createTextNode(crossSectionRadiusStr);
    crossSectionRadiusElement.appendChild(crossSectionRadiusDomText);

    torusElement.appendChild(crossSectionRadiusElement);

    //Write fields if exist.
    if(!torus->fields().isEmpty()){
        foreach(axlAbstractField *field, torus->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            torusElement.appendChild(fieldElement);
        }
    }

    return torusElement;
}

QDomElement axlTorusWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if (!axl_writer)
        return element;
    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlTorusWriter(void) {
    return new axlTorusWriter;
}
