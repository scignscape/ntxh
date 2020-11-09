/* axlCylinderParametricWriter.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2011 - Valentin Michelet, Inria.
 * Created: Tue Aug 06 11:13:23 2013 (+0200)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlCylinderParametricWriter.h"

#include <axlCore/axlCylinder.h>
#include <axlCore/axlCylinderParametric.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlCylinderParametricWriter
// /////////////////////////////////////////////////////////////////

axlCylinderParametricWriter::axlCylinderParametricWriter(void) {
    this->setObjectName(this->description());
}

axlCylinderParametricWriter::~axlCylinderParametricWriter(void) {
}

QString axlCylinderParametricWriter::identifier(void) const {
    return "axlCylinderParametricWriter";
}

QString axlCylinderParametricWriter::description(void) const {
    return "axlCylinderParametricWriter";
}

QStringList axlCylinderParametricWriter::handled(void) const {
    return QStringList() << "axlCylinderParametric";
}

bool axlCylinderParametricWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlCylinderParametricWriter", QStringList(), createaxlCylinderParametricWriter);
}

bool axlCylinderParametricWriter::accept(dtkAbstractData *data) {
    axlCylinderParametric *cylinderParam = dynamic_cast<axlCylinderParametric *>(data);
    return cylinderParam != NULL;
}

bool axlCylinderParametricWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlCylinderParametricWriter::write(QDomDocument *doc, dtkAbstractData *data) {
    // Get cylinder parametric
    axlCylinderParametric *cylinderParam = dynamic_cast<axlCylinderParametric *>(data);
    // Get cylinder
    axlCylinder* cylinder = cylinderParam->getCylinder();

    // Create name
    QDomElement cylinderParamElement = doc->createElement("cylinderParam");
    cylinderParamElement.setAttribute("name",cylinder->name());

    // Create size
    cylinderParamElement.setAttribute("size", QString::number(cylinder->size()));

    // Create color
    QColor qcolor = cylinder->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(cylinder->opacity());
    cylinderParamElement.setAttribute("color", color);

    // Create shader
    QString shader = cylinder->shader();
    QFileInfo shaderFileInfo(shader);
    cylinderParamElement.setAttribute("shader", shaderFileInfo.fileName());

    // Write cylinder
    // Create first point
    QDomElement firstPoint = doc->createElement("point");
    QString firstPointStr;
    QTextStream(&firstPointStr) << QString::number(cylinder->firstPoint()->x()) << " "<< QString::number(cylinder->firstPoint()->y()) << " "<< QString::number(cylinder->firstPoint()->z());
    QDomText firstPointDomText = doc->createTextNode(firstPointStr);
    firstPoint.appendChild(firstPointDomText);

    cylinderParamElement.appendChild(firstPoint);

    // Create second point
    QDomElement secondPoint = doc->createElement("point");
    QString secondPointStr;
    QTextStream(&secondPointStr) << QString::number(cylinder->secondPoint()->x()) << " "<< QString::number(cylinder->secondPoint()->y()) << " "<< QString::number(cylinder->secondPoint()->z());
    QDomText secondPointDomText = doc->createTextNode(secondPointStr);
    secondPoint.appendChild(secondPointDomText);

    cylinderParamElement.appendChild(secondPoint);

    // Create radius
    QDomElement radius = doc->createElement("radius");
    QString radiusStr;
    QTextStream(&radiusStr) << QString::number(cylinder->radius());
    QDomText radiusDomText = doc->createTextNode(radiusStr);
    radius.appendChild(radiusDomText);

    cylinderParamElement.appendChild(radius);

    // Create refdir
    QDomElement refdir = doc->createElement("refdir");
    QString refdirStr;
    QTextStream(&refdirStr) << QString::number(cylinderParam->getR()->x()) << " "<< QString::number(cylinderParam->getR()->y()) << " "<< QString::number(cylinderParam->getR()->z());
    QDomText refdirDomText = doc->createTextNode(refdirStr);
    refdir.appendChild(refdirDomText);

    cylinderParamElement.appendChild(refdir);

    // Write fields if exist.
    if(!cylinder->fields().isEmpty()){
        foreach(axlAbstractField *field, cylinder->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            cylinderParamElement.appendChild(fieldElement);
        }
    }

    return cylinderParamElement;
}


QDomElement axlCylinderParametricWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlCylinderParametricWriter(void) {
    return new axlCylinderParametricWriter;
}
