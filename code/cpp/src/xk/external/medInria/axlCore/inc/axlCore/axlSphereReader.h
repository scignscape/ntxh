/* axlSphereReader.h ---
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

#ifndef AXLSPHEREREADER_H
#define AXLSPHEREREADER_H

#include <axlCore/axlAbstractDataReader.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlSphereReader : public axlAbstractDataReader
{
    Q_OBJECT

public :
      axlSphereReader(void);
     ~axlSphereReader(void);

public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

public:
    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlSphereReader(void);

#endif //AXLSPHEREREADER_H