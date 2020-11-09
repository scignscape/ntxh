/* axlPlaneParametricWriter.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Mon Jul 29 11:13:23 2013 (+0200)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlPlaneParametricWriter.h"

#include <axlCore/axlPlane.h>
#include <axlCore/axlPlaneParametric.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlPlaneParametricWriter
// /////////////////////////////////////////////////////////////////

axlPlaneParametricWriter::axlPlaneParametricWriter(void) {
    this->setObjectName(this->description());
}

axlPlaneParametricWriter::~axlPlaneParametricWriter(void) {
}

QString axlPlaneParametricWriter::identifier(void) const {
    return "axlPlaneParametricWriter";
}

QString axlPlaneParametricWriter::description(void) const {
    return "axlPlaneParametricWriter";
}

QStringList axlPlaneParametricWriter::handled(void) const {
    return QStringList() << "axlPlaneParametric";
}

bool axlPlaneParametricWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlPlaneParametricWriter", QStringList(), createaxlPlaneParametricWriter);
}

bool axlPlaneParametricWriter::accept(dtkAbstractData *data)  {
    axlPlaneParametric *planeParam = dynamic_cast<axlPlaneParametric *>(data);
    return planeParam != NULL;
}

bool axlPlaneParametricWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlPlaneParametricWriter::write(QDomDocument *doc, dtkAbstractData *data) {
    // Get parametric plane
    axlPlaneParametric *planeParam = dynamic_cast<axlPlaneParametric *>(data);
    // Get plane
    axlPlane* plane = planeParam->getPlane();

    // Create name
    QDomElement planeParamElement = doc->createElement("planeParam");
    planeParamElement.setAttribute("name",plane->name());

    // Create size
    planeParamElement.setAttribute("size", QString::number(plane->size()));

    // Create color
    QColor qcolor = plane->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(plane->opacity());
    planeParamElement.setAttribute("color", color);

    // Create shader
    QString shader = plane->shader();
    QFileInfo shaderFileInfo(shader);
    planeParamElement.setAttribute("shader", shaderFileInfo.fileName());

    // Write plane param
    // Create point
    QDomElement point = doc->createElement("point");
    QString pointStr;
    QTextStream(&pointStr) << QString::number(plane->point()->x()) << " "<< QString::number(plane->point()->y()) << " "<< QString::number(plane->point()->z());
    QDomText pointDomText = doc->createTextNode(pointStr);
    point.appendChild(pointDomText);

    planeParamElement.appendChild(point);

    // Create normal
    QDomElement normal = doc->createElement("normal");
    QString normalStr;
    QTextStream(&normalStr) << QString::number(plane->normal()->x()) << " "<< QString::number(plane->normal()->y()) << " "<< QString::number(plane->normal()->z());
    QDomText normalDomText = doc->createTextNode(normalStr);
    normal.appendChild(normalDomText);

    planeParamElement.appendChild(normal);

    // Create refdir
    QDomElement refdir = doc->createElement("refdir");
    QString refdirStr;
    QTextStream(&refdirStr) << QString::number(planeParam->getI()->x()) << " "<< QString::number(planeParam->getI()->y()) << " "<< QString::number(planeParam->getI()->z());
    QDomText refdirDomText = doc->createTextNode(refdirStr);
    refdir.appendChild(refdirDomText);

    planeParamElement.appendChild(refdir);

    // Write fields if any
    if (!plane->fields().isEmpty()) {
        foreach(axlAbstractField *field, plane->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            planeParamElement.appendChild(fieldElement);
        }
    }

    return planeParamElement;
}


QDomElement axlPlaneParametricWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlPlaneParametricWriter(void) {
    return new axlPlaneParametricWriter;
}
