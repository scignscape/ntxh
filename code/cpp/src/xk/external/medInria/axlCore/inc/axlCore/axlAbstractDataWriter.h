/* axlAbstractDataWriter.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008-2011 - Meriadeg Perrinel, Inria.
 * Created: Wed Sep 21 10:36:05 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Tue Jan 24 10:53:48 2012 (+0100)
 *           By: Julien Wintz
 *     Update #: 27
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTDATAWRITER_H
#define AXLABSTRACTDATAWRITER_H

#include "axlCoreExport.h"

#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataWriter.h>

#include <QtCore>
#include <QtXml>

class axlMesh;

class dtkAbstractData;

class AXLCORE_EXPORT axlAbstractDataWriter : public dtkAbstractDataWriter
{
    Q_OBJECT

public:
    axlAbstractDataWriter(void);
    virtual ~axlAbstractDataWriter(void);

public:
    virtual bool accept(dtkAbstractData *data) = 0;
    virtual bool reject(dtkAbstractData *data) = 0;

    using   dtkAbstractDataWriter::write;
    virtual QDomElement write(QDomDocument *doc, dtkAbstractData *data) = 0;
    // virtual axlMesh *toAxlMesh(dtkAbstractData *data);

    void setName   (QDomElement& e, axlAbstractData *data);
    void setColor  (QDomElement& e, axlAbstractData *data);
    void setSize   (QDomElement& e, axlAbstractData *data);
    void setShader (QDomElement& e, axlAbstractData *data);

};

#define append_element_doc(Elt, Doc, Name, fct) \
{ QDomElement dom = Doc->createElement(Name); \
    dom.appendChild(Doc->createTextNode(fct)); \
    Elt.appendChild(dom); }

#endif //AXLABSTRACTDATAWRITER_H
