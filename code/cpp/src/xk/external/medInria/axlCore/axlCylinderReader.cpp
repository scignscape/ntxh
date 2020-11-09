/* axlCylinderReader.cpp ---
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

#include "axlCylinderReader.h"

#include <axlCore/axlCylinder.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlFieldReadersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlCylinderReader
// /////////////////////////////////////////////////////////////////

axlCylinderReader::axlCylinderReader(void)
{
    this->setObjectName(this->description());
}

axlCylinderReader::~axlCylinderReader(void)
{

}

QString axlCylinderReader::identifier(void) const
{
    return "axlCylinderReader";
}

QString axlCylinderReader::description(void) const
{
    return "axlCylinderReader";
}

QStringList axlCylinderReader::handled(void) const
{
    return QStringList() << "axlCylinder";
}

bool axlCylinderReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlCylinderReader", QStringList(), createaxlCylinderReader);
}

bool axlCylinderReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "cylinder")
        return false;

    if(!hasChildNode(element, "point"))
        return false;

    if(!hasChildNode(element, "radius"))
        return false;

    return true;
}

bool axlCylinderReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}

axlAbstractData *axlCylinderReader::read(const QDomNode& node)
{
    QDomElement element = node.toElement();

    axlCylinder *currentCylinder = new axlCylinder();

    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        currentCylinder->setObjectName(name);
    }

    QString color = element.attribute("color");
    if(!color.isEmpty())
    {
        QStringList colorList = color.split(" ");
        if(colorList.size() > 2) // rgb components
            currentCylinder->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if(colorList.size() == 4)
            currentCylinder->setOpacity(colorList.at(3).toFloat());
    }

    QString shader = element.attribute("shader");
    QString dirShader;
    if(!shader.isEmpty())
    {
        // try to read from axelShader.qrc
        dirShader = ":axlShader/shader/"+shader;
        if(!QFile::exists(dirShader))
        {
            QSettings settings("inria", "dtk");
            QString defaultPath;
            settings.beginGroup("shader");
            dirShader = settings.value("path", defaultPath).toString();
//            dirShader = this->file().left(this->file().lastIndexOf("axel-data") + 9); // to Remove later
            dirShader.append("/"+shader);
        }
        currentCylinder->setShader(dirShader);
    }

    QString size = element.attribute("size");
    if(!size.isEmpty())
        currentCylinder->setSize(size.toFloat());

    QDomNodeList nodelistPoint = element.elementsByTagName("point") ;

    //FirstPoint
    QDomElement elementfirstPoint = nodelistPoint.item(0).toElement() ;

    QStringList coordinates = elementfirstPoint.text().simplified().split(QRegExp("\\s+"));
    if(coordinates.size() == 3)
    {
        currentCylinder->setFirstPoint(new axlPoint(coordinates[0].toDouble(), coordinates[1].toDouble(), coordinates[2].toDouble()));
    }
    else
        qDebug()<<"Cylinder data cannot be read correctly : coordinates";

    //SecondPOint
    QDomElement elementsecondPoint = nodelistPoint.item(1).toElement() ;

    coordinates = elementsecondPoint.text().simplified().split(QRegExp("\\s+"));
    if(coordinates.size() == 3)
    {
        currentCylinder->setSecondPoint(new axlPoint(coordinates[0].toDouble(), coordinates[1].toDouble(), coordinates[2].toDouble()));

    }
    else
        qDebug()<<"Cylinder data cannot be read correctly : coordinates";

    //radius
    QDomNodeList nodelistradius = element.elementsByTagName("radius") ;
    QDomElement elementradius = nodelistradius.item(0).toElement() ;

    QStringList radius = elementradius.text().simplified().split(QRegExp("\\s+"));
    if(radius.size() == 1)
    {
        currentCylinder->setRadius(radius[0].toDouble());
    }
    else
        qDebug()<<"Cylinder data cannot be read correctly : radius";


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
                    QString newName = currentCylinder->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentCylinder->addField(fieldToAdd);
                }
            }
        }
    }

    return currentCylinder;

}

dtkAbstractDataReader *createaxlCylinderReader(void)
{
    return new axlCylinderReader;
}
