/* axlCircleArcReader.h ---
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

#ifndef AXLCIRCLEARCREADER_H
#define AXLCIRCLEARCREADER_H

#include <axlCore/axlAbstractDataReader.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlCircleArcReader : public axlAbstractDataReader {
    Q_OBJECT

public:
    axlCircleArcReader(void);
    virtual ~axlCircleArcReader(void);

    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlCircleArcReader(void);

#endif // AXLCIRCLEARCREADER_H
