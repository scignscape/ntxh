/* axlFieldParametricCurveTangentVectorCreator.h ---
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

#ifndef AXLFIELDPARAMETRICCURVETANGENTVECTORCREATOR_H
#define AXLFIELDPARAMETRICCURVETANGENTVECTORCREATOR_H

#include "axlCoreExport.h"
#include <axlCore/axlAbstractFieldGenerator.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <QtGui>

class axlFieldParametricCurveTangentVectorCreatorPrivate;
class axlAbstractField;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldParametricCurveTangentVectorCreator : public axlAbstractFieldGenerator
{
    Q_OBJECT

public:
     axlFieldParametricCurveTangentVectorCreator(void);
    ~axlFieldParametricCurveTangentVectorCreator(void);

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
    axlFieldParametricCurveTangentVectorCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlFieldParametricCurveTangentVectorCreator(void);

#endif// AXLFIELDPARAMETRICCURVETANGENTVECTORCREATOR_H
