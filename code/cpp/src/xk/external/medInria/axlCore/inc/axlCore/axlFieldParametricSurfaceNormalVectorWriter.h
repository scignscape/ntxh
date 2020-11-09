/* axlFieldParametricSurfaceNormalVectorWriter.h ---
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

#ifndef AXLFIELDPARAMETRICSURFACENORMALVECTORWRITER_H
#define AXLFIELDPARAMETRICSURFACENORMALVECTORWRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"


class dtkAbstractData;

class AXLCORE_EXPORT axlFieldParametricSurfaceNormalVectorWriter : public axlAbstractDataWriter
{
    Q_OBJECT

public :
      axlFieldParametricSurfaceNormalVectorWriter(void);
     ~axlFieldParametricSurfaceNormalVectorWriter(void);

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

dtkAbstractDataWriter *createaxlFieldParametricSurfaceNormalVectorWriter(void);

#endif// AXLFIELDPARAMETRICSURFACENORMALVECTORWRITER_H
