/* axlCircleArcReader.cpp ---
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

#include "axlCircleArcReader.h"

#include <axlCore/axlCircleArc.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlFieldReadersFactory.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlCircleArcReader
// /////////////////////////////////////////////////////////////////

axlCircleArcReader::axlCircleArcReader(void) {
    this->setObjectName(this->description());
}

axlCircleArcReader::~axlCircleArcReader(void) {
}

QString axlCircleArcReader::identifier(void) const {
    return "axlCircleArcReader";
}

QString axlCircleArcReader::description(void) const {
    return "axlCircleArcReader";
}

QStringList axlCircleArcReader::handled(void) const {
    return QStringList() << "axlCircleArc";
}

bool axlCircleArcReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlCircleArcReader", QStringList(), createaxlCircleArcReader);
}

bool axlCircleArcReader::accept(const QDomNode& node) {
    QDomElement element = node.toElement();

    if (element.tagName() != "arc")
        return false;

    if (!hasChildNode(element, "point1"))
        return false;

    if (!hasChildNode(element, "point2"))
        return false;

    if (!hasChildNode(element, "center"))
        return false;

    if (!hasChildNode(element, "normal"))
        return false;

    if (!hasChildNode(element, "ccw"))
        return false;

    return true;
}

bool axlCircleArcReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData* axlCircleArcReader::read(const QDomNode& node) {
    QDomElement element = node.toElement();

    // Create circle arc pointer to fill and return
    axlCircleArc* currentArc = new axlCircleArc;

    // Get name
    QString name = element.attribute("name");
    if (!name.isEmpty()) {
        currentArc->setObjectName(name);
    }

    // Get color
    QString color = element.attribute("color");
    if (!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if (colorList.size() > 2) // rgb components
            currentArc->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if (colorList.size() == 4)
            currentArc->setOpacity(colorList.at(3).toFloat());
    }

    // Get shader
    QString shader = element.attribute("shader");
    QString dirShader;
    if (!shader.isEmpty()) {
        // try to read from axelShader.qrc
        dirShader = ":axlShader/shader/" + shader;
        if (!QFile::exists(dirShader)) {
            QSettings settings("inria", "dtk");
            QString defaultPath;
            settings.beginGroup("shader");
            dirShader = settings.value("path", defaultPath).toString();
            dirShader.append("/" + shader);
        }
        currentArc->setShader(dirShader);
    }

    // Get size
    QString size = element.attribute("size");
    if (!size.isEmpty())
        currentArc->setSize(size.toFloat());

    // Get first point
    QDomNodeList nodeListPoint1 = element.elementsByTagName("point1");
    QDomElement elementPoint1 = nodeListPoint1.item(0).toElement();
    QStringList coordPoint1 = elementPoint1.text().simplified().split(QRegExp("\\s+"));
    if (coordPoint1.size() == 3)
        currentArc->setPoint1(new axlPoint(coordPoint1[0].toDouble(), coordPoint1[1].toDouble(), coordPoint1[2].toDouble()));
    else
        dtkWarn() << "Error within axlCircleArcReader::read, arc data cannot be read correctly: point1 coordinates";

    // Get second point
    QDomNodeList nodeListPoint2 = element.elementsByTagName("point2");
    QDomElement elementPoint2 = nodeListPoint2.item(0).toElement();
    QStringList coordPoint2 = elementPoint2.text().simplified().split(QRegExp("\\s+"));
    if (coordPoint2.size() == 3)
        currentArc->setPoint2(new axlPoint(coordPoint2[0].toDouble(), coordPoint2[1].toDouble(), coordPoint2[2].toDouble()));
    else
        dtkWarn() << "Error within axlCircleArcReader::read, arc data cannot be read correctly: point2 coordinates";

    // Get center
    QDomNodeList nodeListCenter = element.elementsByTagName("center");
    QDomElement elementCenter = nodeListCenter.item(0).toElement();
    QStringList coordCenter = elementCenter.text().simplified().split(QRegExp("\\s+"));
    if (coordCenter.size() == 3)
        currentArc->setCenter(new axlPoint(coordCenter[0].toDouble(), coordCenter[1].toDouble(), coordCenter[2].toDouble()));
    else
        dtkWarn() << "Error within axlCircleArcReader::read, arc data cannot be read correctly: radius coordinates";

    // Get normal
    QDomNodeList nodeListNormal = element.elementsByTagName("normal");
    QDomElement elementNormal = nodeListNormal.item(0).toElement();
    QStringList coordNormal = elementNormal.text().simplified().split(QRegExp("\\s+"));
    if (coordNormal.size() == 3)
        currentArc->setNormal(new axlPoint(coordNormal[0].toDouble(), coordNormal[1].toDouble(), coordNormal[2].toDouble()));
    else
        dtkWarn() << "Error within axlCircleArcReader::read, arc data cannot be read correctly: normal coordinates";

    // Get counter clockwise bool
    QDomNodeList nodeListCCW = element.elementsByTagName("ccw");
    QDomElement elementCCW = nodeListCCW.item(0).toElement();
    QString coordCCW = elementCCW.text().simplified();
    bool ok;
    currentArc->setDirect(coordCCW.toInt(&ok));
    if (!ok) {
        dtkWarn() << "Error within axlCircleArcReader::read, arc data cannot be read correctly: ccw bool value";
    }

    // If there are some field, read them thanks to the factory.
    QDomNodeList nodeListField = element.elementsByTagName("field");
    if(!nodeListField.isEmpty()){
        for(int i =0; i < nodeListField.size(); i++){
            QDomElement fieldElement = nodeListField.at(i).toElement();
            QString fieldType = fieldElement.attribute("type");
            if(!fieldType.isEmpty()){
                axlAbstractDataReader *field_reader = dynamic_cast<axlAbstractDataReader *>(axlFieldReadersFactory::instance()->create(fieldType));
                axlAbstractField * fieldToAdd = dynamic_cast<axlAbstractField *>(field_reader->read(fieldElement));
                if(fieldToAdd){
                    QString newName = currentArc->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentArc->addField(fieldToAdd);
                }
            }
        }
    }

    return currentArc;
}

dtkAbstractDataReader *createaxlCircleArcReader(void) {
    return new axlCircleArcReader;
}
