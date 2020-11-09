/* axlTorusParametricReader.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Mon Jul 29 11:13:23 2013 (+0200)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLTORUSPARAMETRICREADER_H
#define AXLTORUSPARAMETRICREADER_H

#include <axlCore/axlAbstractDataReader.h>
#include "axlCoreExport.h"


class dtkAbstractData;

class AXLCORE_EXPORT axlTorusParametricReader : public axlAbstractDataReader {
    Q_OBJECT

public:
    axlTorusParametricReader(void);
    virtual ~axlTorusParametricReader(void);

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

dtkAbstractDataReader *createaxlTorusParametricReader(void);

#endif // AXLTORUSPARAMETRICREADER_H
