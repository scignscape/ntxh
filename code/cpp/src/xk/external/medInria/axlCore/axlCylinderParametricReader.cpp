/* axlCylinderParametricReader.cpp ---
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

#include "axlCylinderParametricReader.h"

#include <axlCore/axlCylinder.h>
#include <axlCore/axlCylinderParametric.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlFieldReadersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlCylinderParametricReader
// /////////////////////////////////////////////////////////////////

axlCylinderParametricReader::axlCylinderParametricReader(void) {
    this->setObjectName(this->description());
}

axlCylinderParametricReader::~axlCylinderParametricReader(void) {
}

QString axlCylinderParametricReader::identifier(void) const {
    return "axlCylinderParametricReader";
}

QString axlCylinderParametricReader::description(void) const {
    return "axlCylinderParametricReader";
}

QStringList axlCylinderParametricReader::handled(void) const {
    return QStringList() << "axlCylinderParametric";
}

bool axlCylinderParametricReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlCylinderParametricReader", QStringList(), createaxlCylinderParametricReader);
}

bool axlCylinderParametricReader::accept(const QDomNode& node)  {

    QDomElement element = node.toElement();

    if(element.tagName() != "cylinderParam")
        return false;

    if(!hasChildNode(element, "point"))
        return false;

    if(!hasChildNode(element, "radius"))
        return false;

    if(!hasChildNode(element, "refdir"))
        return false;

    qDebug() << "cylinderParam read.";

    return true;
}

bool axlCylinderParametricReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlCylinderParametricReader::read(const QDomNode& node) {
    QDomElement element = node.toElement();

    // Create parametric cylinder to fill and return
    axlCylinderParametric* currentCylinderParametric = new axlCylinderParametric;

    // Get name
    QString name = element.attribute("name");
    if(!name.isEmpty()) {
        currentCylinderParametric->setObjectName(name);
    }

    // Get color
    QString color = element.attribute("color");
    if(!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if(colorList.size() > 2) // rgb components
            currentCylinderParametric->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if(colorList.size() == 4)
            currentCylinderParametric->setOpacity(colorList.at(3).toFloat());
    }

    // Get shader
    QString shader = element.attribute("shader");
    QString dirShader;
    if(!shader.isEmpty()) {
        // try to read from axelShader.qrc
        dirShader = ":axlShader/shader/"+shader;
        if(!QFile::exists(dirShader)) {
            QSettings settings("inria", "dtk");
            QString defaultPath;
            settings.beginGroup("shader");
            dirShader = settings.value("path", defaultPath).toString();
//            dirShader = this->file().left(this->file().lastIndexOf("axel-data") + 9); // to Remove later
            dirShader.append("/"+shader);
        }
        currentCylinderParametric->setShader(dirShader);
    }

    // Get size
    QString size = element.attribute("size");
    if(!size.isEmpty())
        currentCylinderParametric->setSize(size.toFloat());

    QDomNodeList pointNodeList = element.elementsByTagName("point") ;
    axlCylinder cylinder;

    // Get Point 1
    QDomElement point1Element = pointNodeList.item(0).toElement() ;

    QStringList point1Coords = point1Element.text().simplified().split(QRegExp("\\s+"));
    if(point1Coords.size() == 3)
        cylinder.setFirstPoint(new axlPoint(point1Coords[0].toDouble(), point1Coords[1].toDouble(), point1Coords[2].toDouble()));
    else
        dtkWarn() << "CylinderParametric data cannot be read correctly : point 1 coordinates";

    // Get Point 2
    QDomElement point2Element = pointNodeList.item(1).toElement() ;

    QStringList point2Coords = point2Element.text().simplified().split(QRegExp("\\s+"));
    if(point2Coords.size() == 3)
        cylinder.setSecondPoint(new axlPoint(point2Coords[0].toDouble(), point2Coords[1].toDouble(), point2Coords[2].toDouble()));
    else
        dtkWarn() << "CylinderParametric data cannot be read correctly : point 2 coordinates";

    // Get Radius
    QDomNodeList radiusNodeList = element.elementsByTagName("radius") ;

    QDomElement radiusElement = radiusNodeList.item(0).toElement() ;

    QStringList radiusCoords = radiusElement.text().simplified().split(QRegExp("\\s+"));
    if(radiusCoords.size() == 1)
        cylinder.setRadius(radiusCoords[0].toDouble());
    else
        dtkWarn() << "CylinderParametric data cannot be read correctly : radius";

    currentCylinderParametric->setCylinder(cylinder);

    // Get Refdir
    QDomNodeList refdirNodeList = element.elementsByTagName("refdir") ;

    QDomElement refdirElement = refdirNodeList.item(0).toElement() ;

    QStringList refdirCoords = refdirElement.text().simplified().split(QRegExp("\\s+"));
    if(refdirCoords.size() == 3)
        currentCylinderParametric->setR(new axlPoint(refdirCoords[0].toDouble(), refdirCoords[1].toDouble(), refdirCoords[2].toDouble()));
    else
        dtkWarn() << "CylinderParametric data cannot be read correctly : refdir coordinates";


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
                    QString newName = currentCylinderParametric->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentCylinderParametric->addField(fieldToAdd);
                }
            }
        }
    }

    return currentCylinderParametric;
}

dtkAbstractDataReader *createaxlCylinderParametricReader(void) {
    return new axlCylinderParametricReader;
}
