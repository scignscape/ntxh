/* axlEllipsoidWriter.cpp ---
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

#include "axlEllipsoidWriter.h"

#include <axlCore/axlEllipsoid.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlEllipsoidWriter
// /////////////////////////////////////////////////////////////////

axlEllipsoidWriter::axlEllipsoidWriter(void)
{
    this->setObjectName(this->description());
}

axlEllipsoidWriter::~axlEllipsoidWriter(void)
{

}

QString axlEllipsoidWriter::identifier(void) const
{
    return "axlEllipsoidWriter";
}

QString axlEllipsoidWriter::description(void) const
{
    return "axlEllipsoidWriter";
}

QStringList axlEllipsoidWriter::handled(void) const
{
    return QStringList() << "axlEllipsoid";
}

bool axlEllipsoidWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlEllipsoidWriter", QStringList(), createaxlEllipsoidWriter);
}

bool axlEllipsoidWriter::accept(dtkAbstractData *data)
{
    axlEllipsoid *ellipsoid = dynamic_cast<axlEllipsoid *>(data);
    if(ellipsoid)
        return true;

    return false;
}

bool axlEllipsoidWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlEllipsoidWriter::write(QDomDocument *doc, dtkAbstractData *data) {
    axlEllipsoid *ellipsoid = dynamic_cast<axlEllipsoid *>(data);

    /////Name
    QDomElement ellipsoidElement = doc->createElement("ellipsoid");
    ellipsoidElement.setAttribute("name",ellipsoid->name());


    /////Size
    ellipsoidElement.setAttribute("size", QString::number(ellipsoid->size()));



    ////Color
    QColor qcolor = ellipsoid->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(ellipsoid->opacity());
    ellipsoidElement.setAttribute("color", color);

    ////Shader
    QString shader = ellipsoid->shader();
    QFileInfo shaderFileInfo(shader);
    ellipsoidElement.setAttribute("shader", shaderFileInfo.fileName());

    //Write ellipsoid
    //center
    QDomElement center = doc->createElement("center");
    QString centerStr;
    QTextStream(&centerStr) << QString::number(ellipsoid->center()->x()) << " "<< QString::number(ellipsoid->center()->y()) << " "<< QString::number(ellipsoid->center()->z());
    QDomText centerDomText = doc->createTextNode(centerStr);
    center.appendChild(centerDomText);

    ellipsoidElement.appendChild(center);

    //semiX
    QDomElement semix = doc->createElement("semix");
    QString semixStr;
    QTextStream(&semixStr) << QString::number(ellipsoid->semiX()->x()) << " "<< QString::number(ellipsoid->semiX()->y()) << " "<< QString::number(ellipsoid->semiX()->z());
    QDomText semixDomText = doc->createTextNode(semixStr);
    semix.appendChild(semixDomText);

    ellipsoidElement.appendChild(semix);

    //semiY
    QDomElement semiy = doc->createElement("semiy");
    QString semiyStr;
    QTextStream(&semiyStr) << QString::number(ellipsoid->semiY()->x()) << " "<< QString::number(ellipsoid->semiY()->y()) << " "<< QString::number(ellipsoid->semiY()->z());
    QDomText semiyDomText = doc->createTextNode(semiyStr);
    semiy.appendChild(semiyDomText);

    ellipsoidElement.appendChild(semiy);

    //semiZ
    QDomElement semiz = doc->createElement("semiz");
    QString semizStr;
    QTextStream(&semizStr) << QString::number(ellipsoid->semiZ()->x()) << " "<< QString::number(ellipsoid->semiZ()->y()) << " "<< QString::number(ellipsoid->semiZ()->z());
    QDomText semizDomText = doc->createTextNode(semizStr);
    semiz.appendChild(semizDomText);

    ellipsoidElement.appendChild(semiz);


    //Write fields if exist.
    if(!ellipsoid->fields().isEmpty()){
        foreach(axlAbstractField *field, ellipsoid->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            ellipsoidElement.appendChild(fieldElement);
        }
    }


    return ellipsoidElement;
}


QDomElement axlEllipsoidWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlEllipsoidWriter(void)
{
    return new axlEllipsoidWriter;
}
