/* axlAbstractDataReader.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Wed Sep 21 10:38:57 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Sep 21 10:40:38 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 5
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractDataReader.h"

#include <QtGui>

axlAbstractDataReader::axlAbstractDataReader(void) : dtkAbstractDataReader()
{

}

axlAbstractDataReader::~axlAbstractDataReader(void)
{

}

void axlAbstractDataReader::setNameOf(axlAbstractData* data, const QDomElement& e)
{
    if(e.hasAttribute("name"))
        data->setObjectName(e.attribute("name"));
}

void axlAbstractDataReader::setColorOf(axlAbstractData* data, const QDomElement& e)
{
    if(e.hasAttribute("color"))
    {
        QString color = e.attribute("color");
        QStringList colorList = color.split(" ");
        if(colorList.size() >= 3) // rgb components
            data->setColor(QColor(colorList.at(0).toInt(),
                                  colorList.at(1).toInt(),
                                  colorList.at(2).toInt()));
        if(colorList.size() >= 4)
            data->setOpacity(colorList.at(3).toFloat());
    }
}

void axlAbstractDataReader::setSizeOf(axlAbstractData* data, const QDomElement& e)
{
    if(e.hasAttribute("size"))
    {
        double size = e.attribute("size").toDouble();
        if (size<0) size=0.;
        data->setSize(size);
    }
}

void axlAbstractDataReader::setShaderOf(axlAbstractData* data, const QDomElement& e)
{
    if(e.hasAttribute("shader"))
    {
        QString shader = e.attribute("shader");
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
            data->setShader(dirShader);
        }
    }
}
