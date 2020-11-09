/* axlShapeReader.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Tue Jul 21 14:13:23 2013 (+0200)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLSHAPEREADER_H
#define AXLSHAPEREADER_H

#include <axlCore/axlAbstractDataReader.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlShapeReader : public axlAbstractDataReader {
    Q_OBJECT

public:
    axlShapeReader(void);
    virtual ~axlShapeReader(void);

    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlShapeReader(void);

#endif // AXLSHAPEREADER_H
