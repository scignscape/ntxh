/* axlFieldParametricNormalVectorCreator.h ---
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

#ifndef AXLFIELDPARAMETRICNORMALVECTORCREATOR_H
#define AXLFIELDPARAMETRICNORMALVECTORCREATOR_H

#include "axlCoreExport.h"
#include <axlCore/axlAbstractFieldGenerator.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <QtGui>

class axlFieldParametricNormalVectorCreatorPrivate;
class axlAbstractField;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldParametricNormalVectorCreator : public axlAbstractFieldGenerator
{
    Q_OBJECT

public:
     axlFieldParametricNormalVectorCreator(void);
    ~axlFieldParametricNormalVectorCreator(void);

public:
    QString description(void) const;
    QString identifier(void) const;




public slots:
    void setInput(dtkAbstractData *data, int channel);

public slots:
    int update(void);
    int channelCount(void);

public:
    QString form(void) const
    {
        return QString(
             " INPUT:0 data supportData");
    }

public:
    static bool registered(void);

private:
    axlFieldParametricNormalVectorCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlFieldParametricNormalVectorCreator(void);

#endif // AXLFIELDPARAMETRICNORMALVECTORCREATOR_H
