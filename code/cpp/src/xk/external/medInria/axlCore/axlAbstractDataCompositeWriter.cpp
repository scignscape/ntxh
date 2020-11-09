/* axlAbstractDataCompositeWriter.cpp ---
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

#include "axlAbstractDataCompositeWriter.h"

#include <axlCore/axlAbstractDataComposite.h>
#include <axlCore/axlDataDynamic.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <QtGui>

// /////////////////////////////////////////////////////////////////
// axlAbstractDataCompositeWriter
// /////////////////////////////////////////////////////////////////

axlAbstractDataCompositeWriter::axlAbstractDataCompositeWriter(void)
{
    this->setObjectName(this->description());
}

axlAbstractDataCompositeWriter::~axlAbstractDataCompositeWriter(void)
{

}

QString axlAbstractDataCompositeWriter::identifier(void) const
{
    return "axlAbstractDataCompositeWriter";
}

QString axlAbstractDataCompositeWriter::description(void) const
{
    return "axlAbstractDataCompositeWriter";
}

QStringList axlAbstractDataCompositeWriter::handled(void) const
{
    return QStringList() << "axlAbstractDataComposite";
}

bool axlAbstractDataCompositeWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlAbstractDataCompositeWriter", QStringList(), createaxlAbstractDataCompositeWriter);
}

bool axlAbstractDataCompositeWriter::accept(dtkAbstractData *data)
{
    axlAbstractDataComposite *composite = qobject_cast<axlAbstractDataComposite *>(data);
    if(composite && !(dynamic_cast<axlDataDynamic *>(composite)))
        return true;

    return false;
}

bool axlAbstractDataCompositeWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlAbstractDataCompositeWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlAbstractDataComposite *composite = qobject_cast<axlAbstractDataComposite *>(data);

    QDomElement compositeElement = doc->createElement("composite");
    compositeElement.setAttribute("name",composite->name());

    QColor qcolor = composite->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) ;
    compositeElement.setAttribute("color", color);
    QString shader = composite->shader();
    QFileInfo shaderFileInfo(shader);
    compositeElement.setAttribute("shader", shaderFileInfo.fileName());

    for(int i = 0; i < composite->count(); i ++)
    {
        bool founded = false;

        // test for all reader registered in the factory
        foreach(QString writer, dtkAbstractDataFactory::instance()->writers()) {


            axlAbstractDataWriter *axl_writer = qobject_cast<axlAbstractDataWriter *>(dtkAbstractDataFactory::instance()->writer(writer));
            QDomElement element = this->elementByWriter(axl_writer, doc, composite->get(i));

            if(element.hasChildNodes()) {
                compositeElement.appendChild(element);
                founded = true;
            }

        }// end generic case

        if(!founded)
        {
            axlAbstractDataCompositeWriter *axl_writer = new axlAbstractDataCompositeWriter;
            QDomElement element = this->elementByWriter(axl_writer, doc, composite->get(i));

            if(element.hasChildNodes()) {
                compositeElement.appendChild(element);
                founded = true;
            }
        }// end particular dataComposite case

        if (!founded) {
            dtkWarn() << "No writer found for composite item:"<< composite->get(i)->identifier();
        }
    }

    return compositeElement;
}


QDomElement axlAbstractDataCompositeWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlAbstractDataCompositeWriter(void)
{
    return new axlAbstractDataCompositeWriter;
}
