/* axlToMesh.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLTOMESH_H
#define AXLTOMESH_H

#include "axlCoreExport.h"

#include "axlAbstractProcess.h"

#include <QtCore>

class axlAbstractData;

class axlToMeshPrivate;

class AXLCORE_EXPORT axlToMesh : public axlAbstractProcess
{
    Q_OBJECT

public:
    axlToMesh(QObject *parent = 0);
    ~axlToMesh(void);


public :
    axlAbstractData * getInput(int channel) const;

public :
    virtual int update(void);

public :
    QString description(void) const;
    QString identifier(void) const;

public :
//    virtual dtkAbstractData *output(int channel);
    dtkAbstractData *output(int channel);
    dtkAbstractData *output(void);
    void setInput(dtkAbstractData *newData, int channel=0);
//    void setInput(dtkAbstractData *newData);

    int channelCount(void);


public:
    QString form(void) const
    {
        return QString( "INPUT:0 data DataToConvertInMesh\n"
        "OUTPUT data mesh\n");
    }


signals :
    void dataInserted(axlAbstractData *data);


private:
    axlToMeshPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlToMeshProcess(void);

#endif  // AXLTOMESH
