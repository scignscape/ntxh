/* axlFieldDiscreteReader.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2008-2011 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLFIELDDISCRETEREADER_H
#define AXLFIELDDISCRETEREADER_H

#include <axlCore/axlAbstractDataReader.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlFieldDiscreteReader : public axlAbstractDataReader
{
    Q_OBJECT

public :
      axlFieldDiscreteReader(void);
     ~axlFieldDiscreteReader(void);

public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

public:
    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlFieldDiscreteReader(void);

#endif // AXLFIELDDISCRETEREADER_H
