/* axlAbstractFieldGenerator.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2011 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov 11 16:58:59 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:32:45 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 22
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTFIELDGENERATOR_H
#define AXLABSTRACTFIELDGENERATOR_H

#include "axlCoreExport.h"

#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <axlCore/axlAbstractProcess.h>

#include <QtCore>

class axlAbstractFieldGeneratorPrivate;
class axlAbstractField;
class axlAbstractData;

class AXLCORE_EXPORT axlAbstractFieldGenerator : public axlAbstractProcess
{
    Q_OBJECT

public:
    axlAbstractFieldGenerator(void);
    virtual ~axlAbstractFieldGenerator(void);

public:

    virtual QString description(void) const;


signals:
    void dataSetFieldsChanged(QList<axlAbstractData *> dataSet, QString fieldName);

public slots:
    virtual void setInput(dtkAbstractData *data, int channel = 0);
    virtual int update(void);

};
#endif
