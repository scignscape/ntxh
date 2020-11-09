/* axlTorusReader.cpp ---
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

#include "axlTorusReader.h"

#include <axlCore/axlTorus.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlFieldReadersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlTorusReader
// /////////////////////////////////////////////////////////////////

axlTorusReader::axlTorusReader(void) {
    this->setObjectName(this->description());
}

axlTorusReader::~axlTorusReader(void) {
}

QString axlTorusReader::identifier(void) const {
    return "axlTorusReader";
}

QString axlTorusReader::description(void) const {
    return "axlTorusReader";
}

QStringList axlTorusReader::handled(void) const {
    return QStringList() << "axlTorus";
}

bool axlTorusReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlTorusReader", QStringList(), createaxlTorusReader);
}

bool axlTorusReader::accept(const QDomNode& node) {
    QDomElement element = node.toElement();

    if (element.tagName() != "torus")
        return false;

    if (!hasChildNode(element, "center"))
        return false;

    if (!hasChildNode(element, "ringRadius"))
        return false;

    if (!hasChildNode(element, "crossSectionRadius"))
        return false;

    return true;
}

bool axlTorusReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlTorusReader::read(const QDomNode& node) {
    QDomElement element = node.toElement();

    axlTorus* currentTorus = new axlTorus();

    QString name = element.attribute("name");
    if (!name.isEmpty()) {
        currentTorus->setObjectName(name);
    }

    QString color = element.attribute("color");
    if (!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if (colorList.size() > 2) // rgb components
            currentTorus->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if (colorList.size() == 4)
            currentTorus->setOpacity(colorList.at(3).toFloat());
    }

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
        currentTorus->setShader(dirShader);
    }

    QString size = element.attribute("size");
    if (!size.isEmpty())
        currentTorus->setSize(size.toFloat());

    // Center
    QDomNodeList nodeListCenter = element.elementsByTagName("center");
    QDomElement elementCenter = nodeListCenter.item(0).toElement();
    QStringList coordCenter = elementCenter.text().simplified().split(QRegExp("\\s+"));
    if (coordCenter.size() == 3)
        currentTorus->setCenter(new axlPoint(coordCenter[0].toDouble(), coordCenter[1].toDouble(), coordCenter[2].toDouble()));
    else
        qDebug() << "Torus data cannot be read correctly: radius coordinates";

    // Direction
    QDomNodeList nodeListDirection = element.elementsByTagName("direction");
    QDomElement elementDirection = nodeListDirection.item(0).toElement();
    QStringList coordDirection = elementDirection.text().simplified().split(QRegExp("\\s+"));
    if (coordDirection.size() == 3)
        currentTorus->setDirection(new axlPoint(coordDirection[0].toDouble(), coordDirection[1].toDouble(), coordDirection[2].toDouble()));
    else
        qDebug() << "Torus data cannot be read correctly: direction coordinates";

    //  Ring Radius
    QDomNodeList nodeListRingRadius = element.elementsByTagName("ringRadius");
    QDomElement elementRingRadius = nodeListRingRadius.item(0).toElement();
    QStringList ringRadius = elementRingRadius.text().simplified().split(QRegExp("\\s+"));
    if (ringRadius.size() == 1)
        currentTorus->setRingRadius(ringRadius[0].toDouble());
    else
        qDebug() << "Torus data cannot be read correctly : ring radius";

    //  Cross Section Radius
    QDomNodeList nodeListCrossSectionRadius = element.elementsByTagName("crossSectionRadius");
    QDomElement elementCrossSectionRadius = nodeListCrossSectionRadius.item(0).toElement();
    QStringList crossSectionRadius = elementCrossSectionRadius.text().simplified().split(QRegExp("\\s+"));
    if (crossSectionRadius.size() == 1)
        currentTorus->setCrossSectionRadius(crossSectionRadius[0].toDouble());
    else
        qDebug() << "Torus data cannot be read correctly : cross section radius";

    //if there are some field, read them thanks to the factory.
    QDomNodeList nodeListField = element.elementsByTagName("field");
    if(!nodeListField.isEmpty()){
        for(int i = 0; i < nodeListField.size(); i++){
            QDomElement fieldElement = nodeListField.at(i).toElement();
            QString fieldType = fieldElement.attribute("type");
            if(!fieldType.isEmpty()){
                axlAbstractDataReader *field_reader = dynamic_cast<axlAbstractDataReader *>(axlFieldReadersFactory::instance()->create(fieldType));
                axlAbstractField * fieldToAdd = dynamic_cast<axlAbstractField *>(field_reader->read(fieldElement));
                if(fieldToAdd){
                    QString newName = currentTorus->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentTorus->addField(fieldToAdd);
                }
            }
        }
    }

    return currentTorus;
}

dtkAbstractDataReader *createaxlTorusReader(void) {
    return new axlTorusReader;
}
