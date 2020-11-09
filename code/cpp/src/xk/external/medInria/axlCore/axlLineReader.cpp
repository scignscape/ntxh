/* axlLineReader.cpp ---
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

#include "axlLineReader.h"

#include <axlCore/axlLine.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldReadersFactory.h>
#include <axlCore/axlAbstractDataReader.h>

// /////////////////////////////////////////////////////////////////
// axlLineReader
// /////////////////////////////////////////////////////////////////

axlLineReader::axlLineReader(void) {
    this->setObjectName(this->description());
}

axlLineReader::~axlLineReader(void) {
}

QString axlLineReader::identifier(void) const {
    return "axlLineReader";
}

QString axlLineReader::description(void) const {
    return "axlLineReader";
}

QStringList axlLineReader::handled(void) const {
    return QStringList() << "axlLine";
}

bool axlLineReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlLineReader", QStringList(), createaxlLineReader);
}

bool axlLineReader::accept(const QDomNode& node) {
    QDomElement element = node.toElement();

    if (element.tagName() != "line")
        return false;

    if (!hasChildNode(element, "point"))
        return false;

    return true;
}

bool axlLineReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlLineReader::read(const QDomNode& node) {
    QDomElement element = node.toElement();

    // Create line to fill and return
    axlLine *currentLine = new axlLine();

    // Get name
    QString name = element.attribute("name");
    if (!name.isEmpty()) {
        currentLine->setObjectName(name);
    }

    // Get color
    QString color = element.attribute("color");
    if (!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if(colorList.size() > 2) // rgb components
            currentLine->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if(colorList.size() == 4)
            currentLine->setOpacity(colorList.at(3).toFloat());
    }

    // Get shader
    QString shader = element.attribute("shader");
    QString dirShader;
    if (!shader.isEmpty()) {
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
        currentLine->setShader(dirShader);
    }

    // Get size
    QString size = element.attribute("size");
    if(!size.isEmpty())
        currentLine->setSize(size.toFloat());

    // Get first point
    QDomNodeList nodelistfirstPoint = element.elementsByTagName("point") ;
    QDomElement elementfirstPoint = nodelistfirstPoint.item(0).toElement() ;

    QStringList coordinates = elementfirstPoint.text().simplified().split(QRegExp("\\s+"));
    if(coordinates.size() == 3)
    {
        currentLine->setFirstPoint(new axlPoint(coordinates[0].toDouble(), coordinates[1].toDouble(), coordinates[2].toDouble()));
    } else
        dtkWarn() << "Error within axlLineReader::read, line first point data cannot be read correctly: coordinates";

    // Get second point
    QDomNodeList nodelistsecondPoint = element.elementsByTagName("point") ;
    QDomElement elementsecondPoint = nodelistsecondPoint.item(1).toElement() ;

    coordinates = elementsecondPoint.text().simplified().split(QRegExp("\\s+"));
    if (coordinates.size() == 3) {
        currentLine->setSecondPoint(new axlPoint(coordinates[0].toDouble(), coordinates[1].toDouble(), coordinates[2].toDouble()));

    } else
        dtkWarn() << "Error within axlLineReader::read, line second point data cannot be read correctly: coordinates";

    // If there are some field, read them thanks to the factory.
    QDomNodeList nodeListField = element.elementsByTagName("field");
    if (!nodeListField.isEmpty()) {
        for (int i = 0; i < nodeListField.size(); i++) {
            QDomElement fieldElement = nodeListField.at(i).toElement();
            QString fieldType = fieldElement.attribute("type");
            if (!fieldType.isEmpty()) {
                axlAbstractDataReader *field_reader = dynamic_cast<axlAbstractDataReader *>(axlFieldReadersFactory::instance()->create(fieldType));
                axlAbstractField * fieldToAdd = dynamic_cast<axlAbstractField *>(field_reader->read(fieldElement));
                if (fieldToAdd) {
                    QString newName = currentLine->changeFieldName(fieldToAdd->name());
                    fieldToAdd->setObjectName(newName);
                    currentLine->addField(fieldToAdd);
                }
            }
        }
    }

    return currentLine;
}

dtkAbstractDataReader *createaxlLineReader(void)
{
    return new axlLineReader;
}
