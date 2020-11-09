/* axlPlaneParametricReader.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Tue Aug 06 11:13:23 2013 (+0200)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLPLANEPARAMETRICREADER_H
#define AXLPLANEPARAMETRICREADER_H

#include <axlCore/axlAbstractDataReader.h>
#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlPlaneParametricReader : public axlAbstractDataReader
{
    Q_OBJECT

public :
     axlPlaneParametricReader(void);
     virtual ~axlPlaneParametricReader(void);

public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

public:
    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData* read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlPlaneParametricReader(void);

#endif // AXLPLANEPARAMETRICREADER_H
