/* axlFieldParametricVolumeTangentVectorReader.h ---
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

#ifndef AXLFIELDPARAMETRICVOLUMETANGENTVECTORREADER_H
#define AXLFIELDPARAMETRICVOLUMETANGENTVECTORREADER_H

#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlAbstractDataComposite.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlFieldParametricVolumeTangentVectorReader : public axlAbstractDataReader
{
    Q_OBJECT

public :
    axlFieldParametricVolumeTangentVectorReader(void);
    ~axlFieldParametricVolumeTangentVectorReader(void);

public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    dtkAbstractData *dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node);

    static bool registered(void);

public:
    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

AXLCORE_EXPORT dtkAbstractDataReader *createaxlFieldParametricVolumeTangentVectorReader(void);

#endif // AXLFIELDPARAMETRICVOLUMETANGENTVECTORREADER_H