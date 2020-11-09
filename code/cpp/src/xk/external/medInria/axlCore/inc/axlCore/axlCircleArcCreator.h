/* axlCircleArcCreator.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLCIRCLEARCCREATOR_H
#define AXLCIRCLEARCCREATOR_H

#include "axlCoreExport.h"

#include "axlAbstractCreatorProcess.h"

#include <QtCore>

class axlPoint;
class axlDouble;
class axlAbstractData;
class axlCircleArc;

class axlCircleArcCreatorPrivate;

class AXLCORE_EXPORT axlCircleArcCreator : public axlAbstractCreatorProcess
{
    Q_OBJECT

public:
    axlCircleArcCreator(QObject *parent = 0);
    virtual ~axlCircleArcCreator(void);


public :
    virtual axlAbstractData * getInput(int channel) const;
    void copyProcess(axlAbstractProcess *process);
    bool hasParameters(void);


/* dtk overload */
public :
    virtual int update(void);

public :

    virtual QString description(void) const;
    virtual QString identifier(void) const;

public :
    virtual void setInput(dtkAbstractData *newData, int channel);
    virtual void setParameter(int data);
    virtual dtkAbstractData *output(void);

private:
    axlCircleArcCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlCircleArcCreator(void);

#endif // AXLCIRCLEARCCREATOR_H
