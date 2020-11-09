/* axlAbstractDataReader.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Wed Sep 21 10:36:05 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Sep 21 11:06:17 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 26
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTDATAREADER_H
#define AXLABSTRACTDATAREADER_H

#include "axlCoreExport.h"

#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataReader.h>

#include <axlCore/axlFormat.h>

class AXLCORE_EXPORT axlAbstractDataReader : public dtkAbstractDataReader
{
    Q_OBJECT

public:
    axlAbstractDataReader(void);
    virtual ~axlAbstractDataReader(void);

public:
    virtual bool accept(const QDomNode& node) = 0;
    virtual bool reject(const QDomNode& node) = 0;

    using   dtkAbstractDataReader::read;
    virtual axlAbstractData* read(const QDomNode& node) = 0;

    void setNameOf(axlAbstractData* data, const QDomElement& e);
    void setColorOf (axlAbstractData* data, const QDomElement& e);
    void setSizeOf  (axlAbstractData* data, const QDomElement& e);
    void setShaderOf(axlAbstractData* data, const QDomElement& e);
};


bool hasChildNode(QDomElement element, const QString& tag);

#endif
