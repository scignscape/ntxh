/* axlFieldParametricVolumeReader.h ---
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

#ifndef AXLFIELDPARAMETRICVOLUMEREADER_H
#define AXLFIELDPARAMETRICVOLUMEREADER_H

#include <axlCore/axlAbstractDataReader.h>

#include "axlCoreExport.h"

class dtkAbstractData;

class AXLCORE_EXPORT axlFieldParametricVolumeReader : public axlAbstractDataReader
{
    Q_OBJECT

public :
    axlFieldParametricVolumeReader(void);
    ~axlFieldParametricVolumeReader(void);

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

AXLCORE_EXPORT dtkAbstractDataReader *createaxlFieldParametricVolumeReader(void);

#endif // AXLFIELDPARAMETRICVOLUMEREADER_H
