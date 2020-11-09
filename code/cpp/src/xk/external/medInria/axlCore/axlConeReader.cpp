/* axlConeReader.cpp ---
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

#include "axlConeReader.h"

#include <axlCore/axlCone.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldReadersFactory.h>
#include <axlCore/axlAbstractDataReader.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlConeReader
// /////////////////////////////////////////////////////////////////

axlConeReader::axlConeReader(void)
{
    this->setObjectName(this->description());
}

axlConeReader::~axlConeReader(void)
{

}

QString axlConeReader::identifier(void) const
{
    return "axlConeReader";
}

QString axlConeReader::description(void) const
{
    return "axlConeReader";
}

QStringList axlConeReader::handled(void) const
{
    return QStringList() << "axlCone";
}

bool axlConeReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlConeReader", QStringList(), createaxlConeReader);
}

bool axlConeReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "cone")
        return false;

    if(!hasChildNode(element, "point"))
        return false;

    if(!hasChildNode(element, "radius"))
        return false;

    return true;
}

bool axlConeReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}

axlAbstractData *axlConeReader::read(const QDomNode& node)
{
    QDomElement element = node.toElement();

    axlCone *currentCone = new axlCone();

    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        currentCone->setObjectName(name);
    }

    QString color = element.attribute("color");
    if(!color.isEmpty())
    {
        QStringList colorList = color.split(" ");
        if(colorList.size() > 2) // rgb components
            currentCone->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if(colorList.size() == 4)
            currentCone->setOpacity(colorList.at(3).toFloat());
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
        currentCone->setShader(dirShader);
    }

    QString size = element.attribute("size");
    if(!size.isEmpty())
        currentCone->setSize(size.toFloat());

    //Apex
    QDomNodeList nodelistApex = element.elementsByTagName("point") ;
    QDomElement elementApex = nodelistApex.item(0).toElement() ;

    QStringList coordinates = elementApex.text().simplified().split(QRegExp("\\s+"));
    if(coordinates.size() == 3)
    {
        currentCone->setApex(new axlPoint(coordinates[0].toDouble(), coordinates[1].toDouble(), coordinates[2].toDouble()));
    }
    else
        qDebug()<<"Cone data cannot be read correctly : coordinates";

    //BasePoint
    QDomNodeList nodelistBasePoint = element.elementsByTagName("point") ;
    QDomElement elementBasePoint = nodelistBasePoint.item(1).toElement() ;

    coordinates = elementBasePoint.text().simplified().split(QRegExp("\\s+"));
    if(coordinates.size() == 3)
    {
        currentCone->setBasePoint(new axlPoint(coordinates[0].toDouble(), coordinates[1].toDouble(), coordinates[2].toDouble()));

    }
    else
        qDebug()<<"Cone data cannot be read correctly : coordinates";

    //radius
    QDomNodeList nodelistradius = element.elementsByTagName("radius") ;
    QDomElement elementradius = nodelistradius.item(0).toElement() ;

    QStringList radius = elementradius.text().simplified().split(QRegExp("\\s+"));
    if(radius.size() == 1)
    {
        currentCone->setRadius(radius[0].toDouble());
    }
    else
        qDebug()<<"Cone data cannot be read correctly : radius";


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
                    QString newName = currentCone->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentCone->addField(fieldToAdd);
                }
            }
        }
    }

    return currentCone;

}

dtkAbstractDataReader *createaxlConeReader(void)
{
    return new axlConeReader;
}
