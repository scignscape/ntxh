/* axlTorusParametricWriter.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Tue Aug  6 11:13:23 2013 (+0200)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLTORUSPARAMETRICWRITER_H
#define AXLTORUSPARAMETRICWRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"


class dtkAbstractData;

class axlTorusParametricWriter : public axlAbstractDataWriter {
    Q_OBJECT

public:
    axlTorusParametricWriter(void);
    virtual ~axlTorusParametricWriter(void);

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

dtkAbstractDataWriter *createaxlTorusParametricWriter(void);

#endif // AXLTORUSPARAMETRICWRITER_H
