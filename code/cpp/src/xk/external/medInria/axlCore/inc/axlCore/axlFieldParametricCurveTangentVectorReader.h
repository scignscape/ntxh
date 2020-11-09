/* axlFieldParametricCurveTangentVectorReader.h ---
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

#ifndef AXLFIELDPARAMETRICCURVETANGENTVECTORREADER_H
#define AXLFIELDPARAMETRICCURVETANGENTVECTORREADER_H

#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlAbstractDataComposite.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlFieldParametricCurveTangentVectorReader : public axlAbstractDataReader
{
    Q_OBJECT

public :
    axlFieldParametricCurveTangentVectorReader(void);
    ~axlFieldParametricCurveTangentVectorReader(void);

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

AXLCORE_EXPORT dtkAbstractDataReader *createaxlFieldParametricCurveTangentVectorReader(void);

#endif // AXLFIELDPARAMETRICCURVETANGENTVECTORREADER_H
