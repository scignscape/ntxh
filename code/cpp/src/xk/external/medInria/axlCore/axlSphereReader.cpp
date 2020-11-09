/* axlSphereReader.cpp ---
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

#include "axlSphereReader.h"

#include <axlCore/axlSphere.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlFieldReadersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlSphereReader
// /////////////////////////////////////////////////////////////////

axlSphereReader::axlSphereReader(void)
{
    this->setObjectName(this->description());
}

axlSphereReader::~axlSphereReader(void)
{

}

QString axlSphereReader::identifier(void) const
{
    return "axlSphereReader";
}

QString axlSphereReader::description(void) const
{
    return "axlSphereReader";
}

QStringList axlSphereReader::handled(void) const
{
    return QStringList() << "axlSphere";
}

bool axlSphereReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlSphereReader", QStringList(), createaxlSphereReader);
}

bool axlSphereReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "sphere")
        return false;

    if(!hasChildNode(element, "center"))
        return false;

    if(!hasChildNode(element, "radius"))
        return false;


    return true;
}

bool axlSphereReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}

axlAbstractData *axlSphereReader::read(const QDomNode& node)
{
    QDomElement element = node.toElement();

    axlSphere *currentSphere = new axlSphere();

    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        currentSphere->setObjectName(name);
    }

    QString color = element.attribute("color");
    if(!color.isEmpty())
    {
        QStringList colorList = color.split(" ");
        if(colorList.size() > 2) // rgb components
            currentSphere->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if(colorList.size() == 4)
            currentSphere->setOpacity(colorList.at(3).toFloat());
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
        currentSphere->setShader(dirShader);
    }

    QString size = element.attribute("size");
    if(!size.isEmpty())
        currentSphere->setSize(size.toFloat());

    //Center
    QDomNodeList nodelistcenter = element.elementsByTagName("center") ;
    QDomElement elementCenter = nodelistcenter.item(0).toElement() ;

    QStringList coordinates = elementCenter.text().simplified().split(QRegExp("\\s+"));
    if(coordinates.size() == 3)
    {

        currentSphere->coordinates()[0] = coordinates[0].toFloat();
        currentSphere->coordinates()[1] = coordinates[1].toFloat();
        currentSphere->coordinates()[2] = coordinates[2].toFloat();
    }
    else
        qDebug()<<"Sphere data cannot be read correctly : coordinates";

    //radius
    QDomNodeList nodelistradius = element.elementsByTagName("radius") ;
    QDomElement elementRadius = nodelistradius.item(0).toElement() ;
    QStringList radius = elementRadius.text().simplified().split(QRegExp("\\s+"));
    if(radius.size() == 1)
    {
        currentSphere->setRadius(radius[0].toFloat());
    }
    else
        qDebug()<<"Sphere data cannot be read correctly : radius";

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
                    QString newName = currentSphere->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentSphere->addField(fieldToAdd);
                }
            }
        }
    }

    return currentSphere;

}

dtkAbstractDataReader *createaxlSphereReader(void)
{
    return new axlSphereReader;
}
