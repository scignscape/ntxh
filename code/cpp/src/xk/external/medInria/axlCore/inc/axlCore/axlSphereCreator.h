/* axlSphereCreator.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLSPHERECREATOR_H
#define AXLSPHERECREATOR_H

#include "axlCoreExport.h"

#include "axlAbstractCreatorProcess.h"

#include <QtCore>

class axlSphere;
class axlDouble;
class axlAbstractData;

class axlSphereCreatorPrivate;

class AXLCORE_EXPORT axlSphereCreator : public axlAbstractCreatorProcess
{
    Q_OBJECT

public:
    axlSphereCreator(QObject *parent = 0);
    virtual ~axlSphereCreator(void);


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
    virtual void setParameter(double data);
    virtual dtkAbstractData *output(void);

private:
    axlSphereCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlSphereCreator(void);

#endif // AXLSPHERECREATOR_H
