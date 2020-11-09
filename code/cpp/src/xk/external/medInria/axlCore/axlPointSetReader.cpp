/* axlPointSetReader.cpp ---
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

#include "axlPointSetReader.h"

#include <axlCore/axlPointSet.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlPointSetReader
// /////////////////////////////////////////////////////////////////

axlPointSetReader::axlPointSetReader(void)
{
    this->setObjectName(this->description());
}

axlPointSetReader::~axlPointSetReader(void)
{

}

QString axlPointSetReader::identifier(void) const
{
    return "axlPointSetReader";
}

QString axlPointSetReader::description(void) const
{
    return "axlPointSetReader";
}

QStringList axlPointSetReader::handled(void) const
{
    return QStringList() << "axlPointSet";
}

bool axlPointSetReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlPointSetReader", QStringList(), createaxlPointSetReader);
}

bool axlPointSetReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "pointset")
        return false;

    if(!hasChildNode(element, "numberofpoints"))
        return false;

    if(!hasChildNode(element, "points"))
        return false;

    return true;
}

bool axlPointSetReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}

dtkAbstractData *axlPointSetReader::read(const QDomNode& node)
{
    QDomElement element = node.toElement();

    bool colors = false ;
    axlPointSet *currentPointSet = new axlPointSet;

    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        currentPointSet->setObjectName(name);
    }

    QString color = element.attribute("color");

    if(!color.isEmpty())
    {
        if(color == "rgb") //mean each point of the point Set have a specific color
        {
            currentPointSet->setUniqueColor(false);
            colors = true;
        }
        else //mean the axlPointSet has one unique color
        {
            QStringList colorList = color.split(" ");
            if(colorList.size() > 2) // rgb components
                currentPointSet->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
            if(colorList.size() == 4)
                currentPointSet->setOpacity(colorList.at(3).toFloat());
        }
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
        currentPointSet->setShader(dirShader);
    }

    QString size = element.attribute("size");
    if(!size.isEmpty())
        currentPointSet->setSize(size.toFloat());

    //Coordinates
    QDomNodeList nodelistcoordinates = element.elementsByTagName("points") ;
    QDomElement elementCoordinates = nodelistcoordinates.item(0).toElement() ;

    QStringList coordinates = elementCoordinates.text().simplified().split(QRegExp("\\s+"));
    if(colors) {

        for(int i=0 ; i<coordinates.size() ; i+=6) {
            float x = coordinates[i+0].toFloat();
            float y = coordinates[i+1].toFloat();
            float z = coordinates[i+2].toFloat();
            int r = coordinates[i+3].toInt();
            int g = coordinates[i+4].toInt();
            int b = coordinates[i+5].toInt();
            axlPoint *currentPoint = new axlPoint(x, y, z);
            currentPoint->setColor(QColor(r, g, b));
            currentPointSet->push_back(currentPoint);
        }

    } else {

        for(int i=0 ; i<coordinates.size() ; i+=3) {
            float x = coordinates[i+0].toFloat() ;
            float y = coordinates[i+1].toFloat() ;
            float z = coordinates[i+2].toFloat() ;
            currentPointSet->push_back(new axlPoint(x, y, z));
        }
    }

    return currentPointSet;
}

dtkAbstractDataReader *createaxlPointSetReader(void)
{
    return new axlPointSetReader;
}
