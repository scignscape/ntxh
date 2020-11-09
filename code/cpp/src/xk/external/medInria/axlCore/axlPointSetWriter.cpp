/* axlPointSetWriter.cpp ---
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

#include "axlPointSetWriter.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlPointSet.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlPointSetWriter
// /////////////////////////////////////////////////////////////////

axlPointSetWriter::axlPointSetWriter(void)
{
    this->setObjectName(this->description());
}

axlPointSetWriter::~axlPointSetWriter(void)
{

}

QString axlPointSetWriter::identifier(void) const
{
    return "axlPointSetWriter";
}

QString axlPointSetWriter::description(void) const
{
    return "axlPointSetWriter";
}

QStringList axlPointSetWriter::handled(void) const
{
    return QStringList() << "axlPointSet";
}

bool axlPointSetWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlPointSetWriter", QStringList(), createaxlPointSetWriter);
}

bool axlPointSetWriter::accept(dtkAbstractData *data)
{
    axlPointSet *pointSet = dynamic_cast<axlPointSet *>(data);
    if(pointSet)
        return true;

    return false;
}

bool axlPointSetWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlPointSetWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlPointSet *pointSet = dynamic_cast<axlPointSet *>(data);

    /////Name
    QDomElement pointElement = doc->createElement("pointset");
    pointElement.setAttribute("name",pointSet->name());


    /////Size
    pointElement.setAttribute("size", QString::number(pointSet->size()));

    //pointElement.setAttribute("numberOfPoints", QString::number(pointSet->numberOfPoints()));



    ////Color
    QString color ;
    if(pointSet->isUniqueColor())
    {
        QColor qcolor = pointSet->color();
        QTextStream(&color) << QString::number(qcolor.red()) << " "
                            << QString::number(qcolor.green()) << " "
                            << QString::number(qcolor.blue()) << " "
                            << QString::number(pointSet->opacity());
    }
    else
        color = "rgb";
    pointElement.setAttribute("color", color);

    ////Shader
    QString shader = pointSet->shader();
    QFileInfo shaderFileInfo(shader);
    pointElement.setAttribute("shader", shaderFileInfo.fileName());

    //Write point
    //number of points
    QDomElement numberofpoints = doc->createElement("numberofpoints");
    QString numberofpointsStr;
    QTextStream(&numberofpointsStr) << QString::number(pointSet->numberOfPoints());
    QDomText numberofpointsDomText = doc->createTextNode(numberofpointsStr);
    numberofpoints.appendChild(numberofpointsDomText);

    pointElement.appendChild(numberofpoints);

    //coordinate
    QDomElement coordinates = doc->createElement("points");
    QString pointSetText;
    if(pointSet->isUniqueColor())
    {
        for(int i = 0 ; i < pointSet->numberOfPoints(); i++)
            QTextStream(&pointSetText)<< "\n" << QString::number(pointSet->value(i)->x()) << " "<< QString::number(pointSet->value(i)->y()) << " "<< QString::number(pointSet->value(i)->z());
    }
    else
    {
        for(int i = 0 ; i < pointSet->numberOfPoints(); i++)
            QTextStream(&pointSetText)<< "\n" << QString::number(pointSet->value(i)->x()) << " "<< QString::number(pointSet->value(i)->y()) << " "<< QString::number(pointSet->value(i)->z())<< " " << QString::number(pointSet->value(i)->color().red()) << " "<< QString::number(pointSet->value(i)->color().green()) << " "<< QString::number(pointSet->value(i)->color().blue());
    }
    QTextStream(&pointSetText)<< "\n"; // for easy read of the file

    QDomText pointDomText = doc->createTextNode(pointSetText);

    coordinates.appendChild(pointDomText);

    pointElement.appendChild(coordinates);

    return pointElement;
}


QDomElement axlPointSetWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlPointSetWriter(void)
{
    return new axlPointSetWriter;
}
