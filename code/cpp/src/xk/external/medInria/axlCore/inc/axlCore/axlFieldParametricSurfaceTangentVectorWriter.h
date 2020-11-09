/* axlFieldParametricSurfaceTangentVectorWriter.h ---
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

#ifndef AXLFIELDPARAMETRICSURFACETANGENTVECTORWRITER_H
#define AXLFIELDPARAMETRICSURFACETANGENTVECTORWRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"


class dtkAbstractData;

class AXLCORE_EXPORT axlFieldParametricSurfaceTangentVectorWriter : public axlAbstractDataWriter
{
    Q_OBJECT

public :
      axlFieldParametricSurfaceTangentVectorWriter(void);
     ~axlFieldParametricSurfaceTangentVectorWriter(void);

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

dtkAbstractDataWriter *createaxlFieldParametricSurfaceTangentVectorWriter(void);

#endif  // AXLFIELDPARAMETRICSURFACETANGENTVECTORWRITER_H
