/* axlTorusCreator.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLTORUSCREATOR_H
#define AXLTORUSCREATOR_H

#include "axlCoreExport.h"

#include "axlAbstractCreatorProcess.h"

#include <QtCore>

class axlPoint;
class axlDouble;
class axlAbstractData;
class axlTorus;

class axlTorusCreatorPrivate;

class AXLCORE_EXPORT axlTorusCreator : public axlAbstractCreatorProcess
{
    Q_OBJECT

public:
    axlTorusCreator(QObject *parent = 0);
    virtual ~axlTorusCreator(void);


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
    virtual void setParameter(double data, int channel);
    virtual dtkAbstractData *output(void);

private:
    axlTorusCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlTorusCreator(void);

#endif // AXLTORUSCREATOR_H
