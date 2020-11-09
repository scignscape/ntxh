/* axlEllipsoidWriter.h ---
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

#ifndef AXLELLIPSOIDWRITER_H
#define AXLELLIPSOIDWRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"


class dtkAbstractData;

class AXLCORE_EXPORT axlEllipsoidWriter : public axlAbstractDataWriter
{
    Q_OBJECT

public :
      axlEllipsoidWriter(void);
     ~axlEllipsoidWriter(void);

public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

public:
    bool accept(dtkAbstractData *data);
    bool reject(dtkAbstractData *data);

    QDomElement write(QDomDocument *doc, dtkAbstractData *data);

private :
    QDomElement elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data);
};

dtkAbstractDataWriter *createaxlEllipsoidWriter(void);

#endif //AXLELLIPSOIDWRITER_H
