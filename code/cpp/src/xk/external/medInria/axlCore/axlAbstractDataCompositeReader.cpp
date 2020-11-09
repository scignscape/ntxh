/* axlAbstractDataCompositeReader.cpp ---
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

#include "axlAbstractDataCompositeReader.h"

#include <axlCore/axlAbstractDataComposite.h>
#include <axlCore/axlMesh.h>
#include <axlCore/axlMeshReader.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlAbstractDataCompositeReader
// /////////////////////////////////////////////////////////////////

axlAbstractDataCompositeReader::axlAbstractDataCompositeReader(void)
{
    this->setObjectName(this->description());
}

axlAbstractDataCompositeReader::~axlAbstractDataCompositeReader(void)
{

}

QString axlAbstractDataCompositeReader::identifier(void) const
{
    return "axlAbstractDataCompositeReader";
}

QString axlAbstractDataCompositeReader::description(void) const
{
    return "axlAbstractDataCompositeReader";
}

QStringList axlAbstractDataCompositeReader::handled(void) const
{
    return QStringList() << "axlAbstractDataComposite";
}

bool axlAbstractDataCompositeReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlAbstractDataCompositeReader", QStringList(), createaxlAbstractDataCompositeReader);
}

bool axlAbstractDataCompositeReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "composite")
        return false;


    return true;
}

bool axlAbstractDataCompositeReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}

axlAbstractData *axlAbstractDataCompositeReader::read(const QDomNode& node)
{
    QDomElement element = node.toElement();

    axlAbstractDataComposite *composite = new axlAbstractDataComposite;

    // Get name
    QString name = element.attribute("name");
    if (!name.isEmpty()) {
        composite->setObjectName(name);
    }

    QDomNode n = element.firstChild();

    while (!n.isNull()) {

        if (n.isElement()) {

            QDomElement e = n.toElement();

            bool founded = false;

            // test for all reader registered in the factory
            foreach(QString reader, dtkAbstractDataFactory::instance()->readers()) {


                axlAbstractDataReader *axl_reader = qobject_cast<axlAbstractDataReader *>(dtkAbstractDataFactory::instance()->reader(reader));
                dtkAbstractData *data = this->dataByReader(axl_reader, e);

                if(data) {
                    data->setParent(composite);
                    composite->add(data);
                    founded = true;
                }

            }

            // test for particular case
            if(!founded)
            {
                axlMeshReader *axl_reader = new axlMeshReader;
                dtkAbstractData *data = this->dataByReader(axl_reader, e);

                if(data) {
                    data->setParent(composite);
                    composite->add(data);
                    founded = true;
                }

            }

            if(!founded)
            {
                axlAbstractDataCompositeReader *axl_reader = new axlAbstractDataCompositeReader;
                dtkAbstractData *data = this->dataByReader(axl_reader, node);

                if(data) {
                    data->setParent(composite);
                    composite->add(data);
                    founded = true;
                }

            }

        }
        n = n.nextSibling();
    }

    return composite;
}

axlAbstractData *axlAbstractDataCompositeReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
{
    if(!axl_reader)
        return NULL;

    if(!axl_reader->accept(node))
        return NULL;

    axl_reader->dtkAbstractDataReader::read(this->file());

    if(axlAbstractData *data = axl_reader->read(node))
        return data;


    return NULL;
}

dtkAbstractDataReader *createaxlAbstractDataCompositeReader(void)
{
    return new axlAbstractDataCompositeReader;
}
