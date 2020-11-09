/* axlTorusParametricReader.cpp ---
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

#include "axlTorusParametricReader.h"

#include <axlCore/axlTorus.h>
#include <axlCore/axlTorusParametric.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlFieldReadersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlTorusParametricReader
// /////////////////////////////////////////////////////////////////

axlTorusParametricReader::axlTorusParametricReader(void) {
    this->setObjectName(this->description());
}

axlTorusParametricReader::~axlTorusParametricReader(void) {
}

QString axlTorusParametricReader::identifier(void) const {
    return "axlTorusParametricReader";
}

QString axlTorusParametricReader::description(void) const {
    return "axlTorusParametricReader";
}

QStringList axlTorusParametricReader::handled(void) const {
    return QStringList() << "axlTorusParametric";
}

bool axlTorusParametricReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlTorusParametricReader", QStringList(), createaxlTorusParametricReader);
}

bool axlTorusParametricReader::accept(const QDomNode& node)  {
    QDomElement element = node.toElement();

    if(element.tagName() != "torusParam")
        return false;

    if(!hasChildNode(element, "center"))
        return false;

    if(!hasChildNode(element, "direction"))
        return false;

    if(!hasChildNode(element, "ringRadius"))
        return false;

    if(!hasChildNode(element, "crossSectionRadius"))
        return false;

    if(!hasChildNode(element, "refdir"))
        return false;

    return true;
}

bool axlTorusParametricReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlTorusParametricReader::read(const QDomNode& node) {
    QDomElement element = node.toElement();

    // Create torus parametric to fill and return
    axlTorusParametric *currentTorusParametric = new axlTorusParametric();

    // Get name
    QString name = element.attribute("name");
    if(!name.isEmpty()) {
        currentTorusParametric->setObjectName(name);
    }

    // Get color
    QString color = element.attribute("color");
    if(!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if(colorList.size() > 2) // rgb components
            currentTorusParametric->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if(colorList.size() == 4)
            currentTorusParametric->setOpacity(colorList.at(3).toFloat());
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
        currentTorusParametric->setShader(dirShader);
    }

    QString size = element.attribute("size");
    if(!size.isEmpty())
        currentTorusParametric->setSize(size.toFloat());


    axlTorus torus;

    // Get Center
    QDomNodeList centerNodeList = element.elementsByTagName("center") ;

    QDomElement centerElement = centerNodeList.item(0).toElement() ;

    QStringList centerCoords = centerElement.text().simplified().split(QRegExp("\\s+"));
    if(centerCoords.size() == 3)
        torus.setCenter(new axlPoint(centerCoords[0].toDouble(), centerCoords[1].toDouble(), centerCoords[2].toDouble()));
    else
        dtkWarn() << "TorusParametric data cannot be read correctly : center coordinates";

    // Get Direction
    QDomNodeList directionNodeList = element.elementsByTagName("direction") ;

    QDomElement directionElement = directionNodeList.item(0).toElement() ;

    QStringList directionCoords = directionElement.text().simplified().split(QRegExp("\\s+"));
    if(directionCoords.size() == 3)
        torus.setDirection(new axlPoint(directionCoords[0].toDouble(), directionCoords[1].toDouble(), directionCoords[2].toDouble()));
    else
        dtkWarn() << "TorusParametric data cannot be read correctly : direction coordinates";

    // Get Ring Radius
    QDomNodeList ringRadiusNodeList = element.elementsByTagName("ringRadius") ;

    QDomElement ringRadiusElement = ringRadiusNodeList.item(0).toElement() ;

    QStringList ringRadiusCoords = ringRadiusElement.text().simplified().split(QRegExp("\\s+"));
    if(ringRadiusCoords.size() == 1)
        torus.setRingRadius(ringRadiusCoords[0].toDouble());
    else
        dtkWarn() << "TorusParametric data cannot be read correctly : ring radius";

    // Get Cross Section Radius
    QDomNodeList crossSectionRadiusNodeList = element.elementsByTagName("crossSectionRadius") ;

    QDomElement crossSectionRadiusElement = crossSectionRadiusNodeList.item(0).toElement() ;

    QStringList crossSectionRadiusCoords = crossSectionRadiusElement.text().simplified().split(QRegExp("\\s+"));
    if(crossSectionRadiusCoords.size() == 1)
        torus.setCrossSectionRadius(crossSectionRadiusCoords[0].toDouble());
    else
        dtkWarn() << "TorusParametric data cannot be read correctly : refdir coordinates";

    currentTorusParametric->setTorus(torus);

    // Get Refdir
    QDomNodeList refdirNodeList = element.elementsByTagName("refdir") ;

    QDomElement refdirElement = refdirNodeList.item(0).toElement() ;

    QStringList refdirCoords = refdirElement.text().simplified().split(QRegExp("\\s+"));
    if(refdirCoords.size() == 3)
        currentTorusParametric->setR(new axlPoint(refdirCoords[0].toDouble(), refdirCoords[1].toDouble(), refdirCoords[2].toDouble()));
    else
        dtkWarn() << "TorusParametric data cannot be read correctly : refdir coordinates";

    //if there are some field, read them thanks to the factory.
    QDomNodeList nodeListField = element.elementsByTagName("field");
    if(!nodeListField.isEmpty()){
        for(int i =0; i < nodeListField.size(); i++){
            QDomElement fieldElement = nodeListField.at(i).toElement();
            QString fieldType = fieldElement.attribute("type");
            if(!fieldType.isEmpty()){
                axlAbstractDataReader *field_reader = dynamic_cast<axlAbstractDataReader *>(axlFieldReadersFactory::instance()->create(fieldType));
                axlAbstractField * fieldToAdd = dynamic_cast<axlAbstractField *>(field_reader->read(fieldElement));
                if(fieldToAdd){
                    QString newName = currentTorusParametric->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentTorusParametric->addField(fieldToAdd);
                }
            }
        }
    }

    return currentTorusParametric;
}

dtkAbstractDataReader *createaxlTorusParametricReader(void) {
    return new axlTorusParametricReader;
}
