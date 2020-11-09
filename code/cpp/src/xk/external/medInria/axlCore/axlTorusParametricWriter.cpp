/* axlTorusParametricWriter.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Tue Aug  6 11:13:23 2013 (+0200)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlTorusParametricWriter.h"

#include <axlCore/axlTorus.h>
#include <axlCore/axlTorusParametric.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlTorusParametricWriter
// /////////////////////////////////////////////////////////////////

axlTorusParametricWriter::axlTorusParametricWriter(void) {
    this->setObjectName(this->description());
}

axlTorusParametricWriter::~axlTorusParametricWriter(void) {
}

QString axlTorusParametricWriter::identifier(void) const {
    return "axlTorusParametricWriter";
}

QString axlTorusParametricWriter::description(void) const {
    return "axlTorusParametricWriter";
}

QStringList axlTorusParametricWriter::handled(void) const {
    return QStringList() << "axlTorusParametric";
}

bool axlTorusParametricWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlTorusParametricWriter", QStringList(), createaxlTorusParametricWriter);
}

bool axlTorusParametricWriter::accept(dtkAbstractData *data) {
    axlTorusParametric *torusParam = dynamic_cast<axlTorusParametric *>(data);
    return torusParam != NULL;
}

bool axlTorusParametricWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlTorusParametricWriter::write(QDomDocument *doc, dtkAbstractData *data) {
    // Get torus param
    axlTorusParametric *torusParam = dynamic_cast<axlTorusParametric *>(data);
    // Get torus
    axlTorus* torus = torusParam->getTorus();

    // Create name
    QDomElement torusParamElement = doc->createElement("torusParam");
    torusParamElement.setAttribute("name",torus->name());

    // Create size
    torusParamElement.setAttribute("size", QString::number(torus->size()));

    // Create color
    QColor qcolor = torus->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(torus->opacity());
    torusParamElement.setAttribute("color", color);

    // Create shader
    QString shader = torus->shader();
    QFileInfo shaderFileInfo(shader);
    torusParamElement.setAttribute("shader", shaderFileInfo.fileName());

    // Write torus
    // Create center
    QDomElement center = doc->createElement("center");
    QString centerStr;
    QTextStream(&centerStr) << QString::number(torus->centerPoint()->x()) << " "<< QString::number(torus->centerPoint()->y()) << " "<< QString::number(torus->centerPoint()->z());
    QDomText centerDomText = doc->createTextNode(centerStr);
    center.appendChild(centerDomText);

    torusParamElement.appendChild(center);

    // Create direction
    QDomElement direction = doc->createElement("direction");
    QString directionStr;
    QTextStream(&directionStr) << QString::number(torus->direction()->x()) << " "<< QString::number(torus->direction()->y()) << " "<< QString::number(torus->direction()->z());
    QDomText directionDomText = doc->createTextNode(directionStr);
    direction.appendChild(directionDomText);

    torusParamElement.appendChild(direction);

    // Create ring radius
    QDomElement ringRadius = doc->createElement("ringRadius");
    QString ringRadiusStr;
    QTextStream(&ringRadiusStr) << QString::number(torus->ringRadius());
    QDomText ringRadiusDomText = doc->createTextNode(ringRadiusStr);
    ringRadius.appendChild(ringRadiusDomText);

    torusParamElement.appendChild(ringRadius);

    // Create cross section radius
    QDomElement crossSectionRadius = doc->createElement("crossSectionRadius");
    QString crossSectionRadiusStr;
    QTextStream(&crossSectionRadiusStr) << QString::number(torus->crossSectionRadius());
    QDomText crossSectionRadiusDomText = doc->createTextNode(crossSectionRadiusStr);
    crossSectionRadius.appendChild(crossSectionRadiusDomText);

    torusParamElement.appendChild(crossSectionRadius);

    // Create refdir
    QDomElement refdir = doc->createElement("refdir");
    QString refdirStr;
    QTextStream(&refdirStr) << QString::number(torusParam->getR()->x()) << " "<< QString::number(torusParam->getR()->y()) << " "<< QString::number(torusParam->getR()->z());
    QDomText refdirDomText = doc->createTextNode(refdirStr);
    refdir.appendChild(refdirDomText);

    torusParamElement.appendChild(refdir);

    // Write fields if exist.
    if(!torus->fields().isEmpty()){
        foreach(axlAbstractField *field, torus->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            torusParamElement.appendChild(fieldElement);
        }
    }

    return torusParamElement;
}


QDomElement axlTorusParametricWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlTorusParametricWriter(void) {
    return new axlTorusParametricWriter;
}
