/* axlOFFReader.h ---
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

#ifndef AXLOFFREADER_H
#define AXLOFFREADER_H

#include <dtkCoreSupport/dtkAbstractDataReader.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlOFFReader : public dtkAbstractDataReader
{
    Q_OBJECT

public :
      axlOFFReader(void);
     ~axlOFFReader(void);

public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

public slots:
    bool canRead(const QString& file);

    bool read(const QString& file);
};

dtkAbstractDataReader *createaxlOFFReader(void);

#endif // AXLOFFREADER_H
