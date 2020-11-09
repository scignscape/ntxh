/* axlPlaneParametricReader.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Tue Aug 06 11:13:23 2013 (+0200)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlPlaneParametricReader.h"

#include <axlCore/axlPlane.h>
#include <axlCore/axlPlaneParametric.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlFieldReadersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlPlaneParametricReader
// /////////////////////////////////////////////////////////////////

axlPlaneParametricReader::axlPlaneParametricReader(void) {
    this->setObjectName(this->description());
}

axlPlaneParametricReader::~axlPlaneParametricReader(void) {
}

QString axlPlaneParametricReader::identifier(void) const {
    return "axlPlaneParametricReader";
}

QString axlPlaneParametricReader::description(void) const {
    return "axlPlaneParametricReader";
}

QStringList axlPlaneParametricReader::handled(void) const {
    return QStringList() << "axlPlaneParametric";
}

bool axlPlaneParametricReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlPlaneParametricReader", QStringList(), createaxlPlaneParametricReader);
}

bool axlPlaneParametricReader::accept(const QDomNode& node) {
    QDomElement element = node.toElement();

    if(element.tagName() != "planeParam")
        return false;

    if(!hasChildNode(element, "point"))
        return false;

    if(!hasChildNode(element, "normal"))
        return false;

    if(!hasChildNode(element, "refdir"))
        return false;

    return true;
}

bool axlPlaneParametricReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlPlaneParametricReader::read(const QDomNode& node) {
    QDomElement element = node.toElement();

    // Create new plane parametric to fill and return
    axlPlaneParametric *currentPlaneParametric = new axlPlaneParametric;

    // Get name
    QString name = element.attribute("name");
    if (!name.isEmpty()) {
        currentPlaneParametric->setObjectName(name);
    }

    // Get color
    QString color = element.attribute("color");
    if (!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if (colorList.size() > 2) // rgb components
            currentPlaneParametric->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if (colorList.size() == 4)
            currentPlaneParametric->setOpacity(colorList.at(3).toFloat());
    }

    // Get shader
    QString shader = element.attribute("shader");
    QString dirShader;
    if (!shader.isEmpty()) {
        // try to read from axelShader.qrc
        dirShader = ":axlShader/shader/"+shader;
        if (!QFile::exists(dirShader)) {
            QSettings settings("inria", "dtk");
            QString defaultPath;
            settings.beginGroup("shader");
            dirShader = settings.value("path", defaultPath).toString();
//            dirShader = this->file().left(this->file().lastIndexOf("axel-data") + 9); // to Remove later
            dirShader.append("/"+shader);
        }
        currentPlaneParametric->setShader(dirShader);
    }

    // Get size
    QString size = element.attribute("size");
    if  (!size.isEmpty())
        currentPlaneParametric->setSize(size.toFloat());

    // Get point
    QDomNodeList pointNodeList = element.elementsByTagName("point") ;
    QDomElement pointElement = pointNodeList.item(0).toElement() ;

    QStringList pointCoords = pointElement.text().simplified().split(QRegExp("\\s+"));
    if(pointCoords.size() == 3)
        currentPlaneParametric->getPlane()->setPoint(new axlPoint(pointCoords[0].toDouble(), pointCoords[1].toDouble(), pointCoords[2].toDouble()));
    else
        dtkWarn() << "Error within axlPlaneParametricReader::read, data cannot be read correctly: point coordinates";

    // Get normal
    QDomNodeList normalNodeList = element.elementsByTagName("normal") ;

    QDomElement normalElement = normalNodeList.item(0).toElement() ;

    QStringList normalCoords = normalElement.text().simplified().split(QRegExp("\\s+"));
    if(normalCoords.size() == 3)
        currentPlaneParametric->getPlane()->setNormal(new axlPoint(normalCoords[0].toDouble(), normalCoords[1].toDouble(), normalCoords[2].toDouble()));
    else
        dtkWarn() << "Error within axlPlaneParametricReader::read, data cannot be read correctly: normal coordinates";

    // Get refdir
    QDomNodeList refdirNodeList = element.elementsByTagName("refdir") ;

    QDomElement refdirElement = refdirNodeList.item(0).toElement() ;

    QStringList refdirCoords = refdirElement.text().simplified().split(QRegExp("\\s+"));
    if(refdirCoords.size() == 3)
        currentPlaneParametric->setI(new axlPoint(refdirCoords[0].toDouble(), refdirCoords[1].toDouble(), refdirCoords[2].toDouble()));
    else
        dtkWarn() << "Error within axlPlaneParametricReader::read, data cannot be read correctly: refdir coordinates";


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
                    QString newName = currentPlaneParametric->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentPlaneParametric->addField(fieldToAdd);
                }
            }
        }
    }

    return currentPlaneParametric;
}

dtkAbstractDataReader *createaxlPlaneParametricReader(void) {
    return new axlPlaneParametricReader;
}
