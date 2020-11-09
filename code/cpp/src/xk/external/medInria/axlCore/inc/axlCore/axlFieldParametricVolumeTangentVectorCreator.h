/* axlFieldParametricVolumeTangentVectorCreator.h ---
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

#ifndef AXLFIELDPARAMETRICVOLUMETANGENTVECTORCREATOR_H
#define AXLFIELDPARAMETRICVOLUMETANGENTVECTORCREATOR_H

#include "axlCoreExport.h"
#include <axlCore/axlAbstractFieldGenerator.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <QtGui>

class axlFieldParametricVolumeTangentVectorCreatorPrivate;
class axlAbstractField;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldParametricVolumeTangentVectorCreator : public axlAbstractFieldGenerator
{
    Q_OBJECT

public:
    axlFieldParametricVolumeTangentVectorCreator(void);
    ~axlFieldParametricVolumeTangentVectorCreator(void);

public:
    QString description(void) const;
    QString identifier(void) const;




public slots:
    void setInput(dtkAbstractData *data, int channel);
    void setParameter(double data, int channel);

public slots:
    int update(void);
    int channelCount(void);

public:
    QString form(void) const
    {
        return QString(
                    " INPUT:0 data supportData \n"
                    " PARAMETER:0 double u-direction 1.0 \n"
                    " PARAMETER:1 double v-direction 0.0 \n"
                    " PARAMETER:2 double w-direction 0.0 ");
    }

public:
    static bool registered(void);

private:
    axlFieldParametricVolumeTangentVectorCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlFieldParametricVolumeTangentVectorCreator(void);

#endif // AXLFIELDPARAMETRICVOLUMETANGENTVECTORCREATOR_H
