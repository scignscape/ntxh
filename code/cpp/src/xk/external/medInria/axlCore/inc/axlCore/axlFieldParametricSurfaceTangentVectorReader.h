/* axlFieldParametricSurfaceTangentVectorReader.h ---
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

#ifndef AXLFIELDPARAMETRICSURFACETANGENTVECTORREADER_H
#define AXLFIELDPARAMETRICSURFACETANGENTVECTORREADER_H

#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlAbstractDataComposite.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlFieldParametricSurfaceTangentVectorReader : public axlAbstractDataReader
{
    Q_OBJECT

public :
    axlFieldParametricSurfaceTangentVectorReader(void);
    ~axlFieldParametricSurfaceTangentVectorReader(void);

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

AXLCORE_EXPORT dtkAbstractDataReader *createaxlFieldParametricSurfaceTangentVectorReader(void);

#endif // AXLFIELDPARAMETRICSURFACETANGENTVECTORREADER_H
