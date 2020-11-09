/* axlConeCreator.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLCONECREATOR_H
#define AXLCONECREATOR_H

#include "axlCoreExport.h"

#include "axlAbstractCreatorProcess.h"

#include <QtCore>

class axlPoint;
class axlAbstractData;
class axlCone;

class axlConeCreatorPrivate;

class AXLCORE_EXPORT axlConeCreator : public axlAbstractCreatorProcess
{
    Q_OBJECT

public:
    axlConeCreator(QObject *parent = 0);
    virtual ~axlConeCreator(void);


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
    static bool registered(void);

public :
    virtual void setInput(dtkAbstractData *newData, int channel);
    virtual void setParameter(double value);
    virtual dtkAbstractData *output(void);

private:
    axlConeCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlConeCreator(void);


#endif // AXLCONECREATOR_H
