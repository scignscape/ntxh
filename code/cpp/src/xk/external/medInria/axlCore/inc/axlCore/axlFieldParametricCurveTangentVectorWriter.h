/* axlFieldParametricCurveTangentVectorWriter.h ---
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

#ifndef AXLFIELDPARAMETRICCURVETANGENTVECTORWRITER_H
#define AXLFIELDPARAMETRICCURVETANGENTVECTORWRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"


class dtkAbstractData;

class AXLCORE_EXPORT axlFieldParametricCurveTangentVectorWriter : public axlAbstractDataWriter
{
    Q_OBJECT

public :
      axlFieldParametricCurveTangentVectorWriter(void);
     ~axlFieldParametricCurveTangentVectorWriter(void);

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

dtkAbstractDataWriter *createaxlFieldParametricCurveTangentVectorWriter(void);

#endif // AXLFIELDPARAMETRICCURVETANGENTVECTORWRITER_H
