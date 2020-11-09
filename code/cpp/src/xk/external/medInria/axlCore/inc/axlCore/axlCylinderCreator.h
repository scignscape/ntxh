/* axlCylinderCreator.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLCYLINDERCREATOR_H
#define AXLCYLINDERCREATOR_H

#include "axlCoreExport.h"

#include "axlAbstractCreatorProcess.h"

#include <QtCore>

class axlPoint;
class axlCylinder;
class axlAbstractData;

class axlCylinderCreatorPrivate;

class AXLCORE_EXPORT axlCylinderCreator : public axlAbstractCreatorProcess
{
    Q_OBJECT

public:
    axlCylinderCreator(QObject *parent = 0);
    virtual ~axlCylinderCreator(void);


public :
    virtual axlAbstractData *getInput(int channel) const;
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

public :
    static bool registered(void);

private:
    axlCylinderCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlCylinderCreator(void);

#endif // AXLCYLINDERCREATOR_H
