/* axlDataDynamicReader.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLDATADYNAMICREADER_H
#define AXLDATADYNAMICREADER_H

#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlAbstractDataComposite.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlDataDynamicReader : public axlAbstractDataReader
{
    Q_OBJECT

public :
    axlDataDynamicReader(void);
    ~axlDataDynamicReader(void);

public :
    axlAbstractData *readInputs(axlDataDynamic *data, const QDomNode& node, const QList<axlAbstractData *> &list);

public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    axlAbstractData *dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node);

    static bool registered(void);

public:
    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlDataDynamicReader(void);

#endif// AXLDATADYNAMICREADER_H
