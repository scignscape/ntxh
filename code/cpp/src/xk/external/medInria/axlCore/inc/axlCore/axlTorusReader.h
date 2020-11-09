/* axlTorusReader.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008 - Valentin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:46:18 2010 (+0100)
 *           By: Valentin Michelet
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLTORUSREADER_H
#define AXLTORUSREADER_H

#include <axlCore/axlAbstractDataReader.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlTorusReader : public axlAbstractDataReader {
    Q_OBJECT

public:
    axlTorusReader(void);
    virtual ~axlTorusReader(void);

    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlTorusReader(void);

#endif // AXLTORUSREADER_H
