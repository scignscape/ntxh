/* axlPointReader.cpp ---
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

#include "axlPointReader.h"
#include <axlCore/axlAbstractField.h>

#include <axlCore/axlPoint.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlFieldReadersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlPointReader
// /////////////////////////////////////////////////////////////////

axlPointReader::axlPointReader(void)
{
    this->setObjectName(this->description());
}

axlPointReader::~axlPointReader(void)
{

}

QString axlPointReader::identifier(void) const
{
    return "axlPointReader";
}

QString axlPointReader::description(void) const
{
    return "axlPointReader";
}

QStringList axlPointReader::handled(void) const
{
    return QStringList() << "axlPoint";
}

bool axlPointReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlPointReader", QStringList(), createaxlPointReader);
}

bool axlPointReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "point")
        return false;


    return true;
}

bool axlPointReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}

axlAbstractData *axlPointReader::read(const QDomNode& node)
{
    QDomElement element = node.toElement();

    axlPoint *currentPoint = new axlPoint();

    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        currentPoint->setObjectName(name);
    }

    QString color = element.attribute("color");
    if(!color.isEmpty())
    {
        QStringList colorList = color.split(" ");
        if(colorList.size() > 2) // rgb components
            currentPoint->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if(colorList.size() == 4)
            currentPoint->setOpacity(colorList.at(3).toFloat());
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
        currentPoint->setShader(dirShader);
    }

    QString size = element.attribute("size");
    if(!size.isEmpty())
        currentPoint->setSize(size.toFloat());

    QStringList coordinates = element.text().simplified().split(QRegExp("\\s+"));

    if(coordinates.size() == 3)
    {
        currentPoint->coordinates()[0] = coordinates[0].toFloat();
        currentPoint->coordinates()[1] = coordinates[1].toFloat();
        currentPoint->coordinates()[2] = coordinates[2].toFloat();
    }
    else
        qDebug()<<"Point data cannot be read correctly";


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
                    QString newName = currentPoint->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentPoint->addField(fieldToAdd);
                }
            }
        }
    }


    return currentPoint;

}

dtkAbstractDataReader *createaxlPointReader(void)
{
    return new axlPointReader;
}
