/* axlPointSetReader.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008-2011 - Meriadeg Perrinel, Inria.
 * Created: Wed Sep 21 11:13:23 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Sep 21 11:49:25 2011 (+0200)
 *           By: Meriadeg Perrinel
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLPOINTSETREADER_H
#define AXLPOINTSETREADER_H

#include <axlCore/axlAbstractDataReader.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlPointSetReader : public axlAbstractDataReader
{
    Q_OBJECT

public :
      axlPointSetReader(void);
     ~axlPointSetReader(void);

public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

public:
    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    dtkAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlPointSetReader(void);

#endif //AXLPOINTSETREADER_H
