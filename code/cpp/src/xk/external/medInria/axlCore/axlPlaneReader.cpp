/* axlPlaneReader.cpp ---
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

#include "axlPlaneReader.h"

#include <axlCore/axlPlane.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldReadersFactory.h>
#include <axlCore/axlAbstractDataReader.h>

// /////////////////////////////////////////////////////////////////
// axlPlaneReader
// /////////////////////////////////////////////////////////////////

axlPlaneReader::axlPlaneReader(void)
{
    this->setObjectName(this->description());
}

axlPlaneReader::~axlPlaneReader(void)
{

}

QString axlPlaneReader::identifier(void) const
{
    return "axlPlaneReader";
}

QString axlPlaneReader::description(void) const
{
    return "axlPlaneReader";
}

QStringList axlPlaneReader::handled(void) const
{
    return QStringList() << "axlPlane";
}

bool axlPlaneReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlPlaneReader", QStringList(), createaxlPlaneReader);
}

bool axlPlaneReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "plane")
        return false;

    if(!hasChildNode(element, "point"))
        return false;

    if(!hasChildNode(element, "normal"))
        return false;

    return true;
}

bool axlPlaneReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}

axlAbstractData *axlPlaneReader::read(const QDomNode& node)
{
    QDomElement element = node.toElement();

    axlPlane *currentPlane = new axlPlane();

    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        currentPlane->setObjectName(name);
    }

    QString color = element.attribute("color");
    if(!color.isEmpty())
    {
        QStringList colorList = color.split(" ");
        if(colorList.size() > 2) // rgb components
            currentPlane->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if(colorList.size() == 4)
            currentPlane->setOpacity(colorList.at(3).toFloat());
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

        currentPlane->setShader(dirShader);
    }

    QString size = element.attribute("size");
    if(!size.isEmpty())
        currentPlane->setSize(size.toFloat());

    //Point
    QDomNodeList nodelistPoint = element.elementsByTagName("point") ;
    QDomElement elementPoint = nodelistPoint.item(0).toElement() ;

    QStringList coordinates = elementPoint.text().simplified().split(QRegExp("\\s+"));
    if(coordinates.size() == 3)
    {
        currentPlane->setPoint(new axlPoint(coordinates[0].toDouble(), coordinates[1].toDouble(), coordinates[2].toDouble()));
    }
    else
        qDebug()<<"Plane data cannot be read correctly : point";

    //Normal
    QDomNodeList nodelistNormal = element.elementsByTagName("normal") ;
    QDomElement elementNormal = nodelistNormal.item(0).toElement() ;

    coordinates = elementNormal.text().simplified().split(QRegExp("\\s+"));
    if(coordinates.size() == 3)
    {
        currentPlane->setNormal(new axlPoint(coordinates[0].toDouble(), coordinates[1].toDouble(), coordinates[2].toDouble()));

    }
    else
        qDebug()<<"Plane data cannot be read correctly : normal";


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
                    QString newName = currentPlane->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentPlane->addField(fieldToAdd);
                }
            }
        }
    }

    return currentPlane;

}

dtkAbstractDataReader *createaxlPlaneReader(void)
{
    return new axlPlaneReader;
}
