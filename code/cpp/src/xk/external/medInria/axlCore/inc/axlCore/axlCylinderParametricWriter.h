/* axlCylinderParametricWriter.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2011 - Valentin Michelet, Inria.
 * Created: Tue Aug 06 11:13:23 2013 (+0200)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLCYLINDERPARAMETRICWRITER_H
#define AXLCYLINDERPARAMETRICWRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"


class dtkAbstractData;

class axlCylinderParametricWriter : public axlAbstractDataWriter {
    Q_OBJECT

public:
    axlCylinderParametricWriter(void);
    virtual ~axlCylinderParametricWriter(void);

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

dtkAbstractDataWriter *createaxlCylinderParametricWriter(void);

#endif // AXLCYLINDERPARAMETRICWRITER_H
