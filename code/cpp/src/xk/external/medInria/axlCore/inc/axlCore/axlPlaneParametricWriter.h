/* axlPlaneParametricWriter.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Mon Jul 29 11:13:23 2013 (+0200)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLPLANEPARAMETRICWRITER_H
#define AXLPLANEPARAMETRICWRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"


class dtkAbstractData;

class AXLCORE_EXPORT axlPlaneParametricWriter : public axlAbstractDataWriter {
    Q_OBJECT

public:
    axlPlaneParametricWriter(void);
    virtual ~axlPlaneParametricWriter(void);

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

dtkAbstractDataWriter *createaxlPlaneParametricWriter(void);

#endif // AXLPLANEPARAMETRICWRITER_H
