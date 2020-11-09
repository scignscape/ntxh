/* axlOFFWriter.h ---
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

#ifndef AXLOFFWRITER_H
#define AXLOFFWRITER_H

#include <dtkCoreSupport/dtkAbstractDataWriter.h>
#include "axlCoreExport.h"
#include <QtGui>


class dtkAbstractData;
class axlOFFWriterPrivate;


class AXLCORE_EXPORT axlOFFWriter : public dtkAbstractDataWriter
{
    Q_OBJECT

public :
    axlOFFWriter(void);
    ~axlOFFWriter(void);


public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

public slots:
    bool canWrite(const QString& file);
    bool write(const QString& file);


};

dtkAbstractDataWriter *createaxlOFFWriter(void);

#endif // AXLOFFWRITER_H
