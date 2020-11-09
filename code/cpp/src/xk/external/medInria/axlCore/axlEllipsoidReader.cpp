/* axlEllipsoidReader.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008-2011 - Meriadeg Perrinel, Inria.
 * Created: Wed Sep 21 11:36:52 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Sep 21 12:11:29 2011 (+0200)
 *           By: Meriadeg Perrinel
 *     Update #: 88
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlEllipsoidReader.h"

#include <axlCore/axlEllipsoid.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldReadersFactory.h>
#include <axlCore/axlAbstractDataReader.h>

#include <dtkMathSupport/dtkQuaternion.h>

// /////////////////////////////////////////////////////////////////
// axlEllipsoidReader
// /////////////////////////////////////////////////////////////////

axlEllipsoidReader::axlEllipsoidReader(void) {
    this->setObjectName(this->description());
}

axlEllipsoidReader::~axlEllipsoidReader(void) {
}

QString axlEllipsoidReader::identifier(void) const {
    return "axlEllipsoidReader";
}

QString axlEllipsoidReader::description(void) const {
    return "axlEllipsoidReader";
}

QStringList axlEllipsoidReader::handled(void) const {
    return QStringList() << "axlEllipsoid";
}

bool axlEllipsoidReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlEllipsoidReader", QStringList(), createaxlEllipsoidReader);
}

bool axlEllipsoidReader::accept(const QDomNode& node) {
    QDomElement element = node.toElement();

    if(element.tagName() != "ellipsoid")
        return false;

    if(!hasChildNode(element, "center"))
        return false;

    if(!hasChildNode(element, "semix"))
        return false;

    if(!hasChildNode(element, "semiy"))
        return false;

    if(!hasChildNode(element, "semiz"))
        return false;

    return true;
}

bool axlEllipsoidReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlEllipsoidReader::read(const QDomNode& node) {
    QDomElement element = node.toElement();

    axlEllipsoid *currentEllipsoid = new axlEllipsoid();

    QString name = element.attribute("name");
    if(!name.isEmpty()) {
        currentEllipsoid->setObjectName(name);
    }

    QString color = element.attribute("color");
    if(!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if(colorList.size() > 2) // rgb components
            currentEllipsoid->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if(colorList.size() == 4)
            currentEllipsoid->setOpacity(colorList.at(3).toFloat());
    }

    QString shader = element.attribute("shader");
    QString dirShader;
    if(!shader.isEmpty()) {
        // try to read from axelShader.qrc
        dirShader = ":axlShader/shader/"+shader;
        if(!QFile::exists(dirShader))
        {
            QSettings settings("inria", "dtk");
            QString defaultPath;
            settings.beginGroup("shader");
            dirShader = settings.value("path", defaultPath).toString();
            //dirShader = this->file().left(this->file().lastIndexOf("axel-data") + 9); // to Remove later
            dirShader.append("/"+shader);
        }
        currentEllipsoid->setShader(dirShader);
    }

    QString size = element.attribute("size");
    if(!size.isEmpty())
        currentEllipsoid->setSize(size.toFloat());

    //Center
    QDomNodeList nodelistcenter = element.elementsByTagName("center") ;
    QDomElement elementCenter = nodelistcenter.item(0).toElement() ;

    QStringList centerCoords = elementCenter.text().simplified().split(QRegExp("\\s+"));
    if (centerCoords.size() == 3) {
        currentEllipsoid->setCenter(new axlPoint(centerCoords[0].toFloat(), centerCoords[1].toFloat(), centerCoords[2].toFloat()));
    } else
        qDebug()<<"Ellispoid data cannot be read correctly : center Coords";

    //SemiX
    QDomNodeList nodelistSemiX = element.elementsByTagName("semix") ;
    QDomElement elementSemiX = nodelistSemiX.item(0).toElement() ;

    QStringList semiXCoords = elementSemiX.text().simplified().split(QRegExp("\\s+"));
    if (semiXCoords.size() == 3) {
        currentEllipsoid->setSemiX(new axlPoint(semiXCoords[0].toFloat(), semiXCoords[1].toFloat(), semiXCoords[2].toFloat()));
    } else
        qDebug()<<"Ellispoid data cannot be read correctly : semiX Coords";

    //SemiY
    QDomNodeList nodelistSemiY = element.elementsByTagName("semiy") ;
    QDomElement elementSemiY = nodelistSemiY.item(0).toElement() ;

    QStringList semiYCoords = elementSemiY.text().simplified().split(QRegExp("\\s+"));
    if (semiYCoords.size() == 3) {
        currentEllipsoid->setSemiY(new axlPoint(semiYCoords[0].toFloat(), semiYCoords[1].toFloat(), semiYCoords[2].toFloat()));
    } else
        qDebug()<<"Ellispoid data cannot be read correctly : semiY Coords";

    //SemiZ
    QDomNodeList nodelistSemiZ = element.elementsByTagName("semiz") ;
    QDomElement elementSemiZ = nodelistSemiZ.item(0).toElement() ;

    QStringList semiZCoords = elementSemiZ.text().simplified().split(QRegExp("\\s+"));
    if (semiZCoords.size() == 3) {
        currentEllipsoid->setSemiZ(new axlPoint(semiZCoords[0].toFloat(), semiZCoords[1].toFloat(), semiZCoords[2].toFloat()));
    } else
        qDebug()<<"Ellispoid data cannot be read correctly : semiZ Coords";

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
                    QString newName = currentEllipsoid->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentEllipsoid->addField(fieldToAdd);
                }
            }
        }
    }
    return currentEllipsoid;
}

dtkAbstractDataReader *createaxlEllipsoidReader(void) {
    return new axlEllipsoidReader;
}
