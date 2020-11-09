/* axlLineCreator.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLLINECREATOR_H
#define AXLLINECREATOR_H

#include "axlCoreExport.h"

#include "axlAbstractCreatorProcess.h"

#include <QtCore>

class axlPoint;
class axlLine;
class axlAbstractData;

class axlLineCreatorPrivate;

class AXLCORE_EXPORT axlLineCreator : public axlAbstractCreatorProcess
{
    Q_OBJECT

public:
    axlLineCreator(QObject *parent = 0);
    axlLineCreator(const axlLineCreator *other,QObject *parent = 0);
    virtual ~axlLineCreator(void);


public :
    virtual axlAbstractData * getInput(int channel) const;
    bool hasParameters(void);



/* dtk overload */
public :
    virtual int update(void);

public :

    virtual QString description(void) const;
    virtual QString identifier(void) const;

public :
    virtual void setInput(dtkAbstractData *newData, int channel);
    virtual dtkAbstractData *output(void);
    virtual dtkAbstractData *output(int channel);

private:
    axlLineCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlLineCreator(void);

#endif // AXLLINECREATOR_H
