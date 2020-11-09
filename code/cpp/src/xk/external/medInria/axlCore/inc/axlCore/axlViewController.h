/* axlViewController.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:46:18 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLVIEWCONTROLER_H
#define AXLVIEWCONTROLER_H

#include "axlCoreExport.h"

#include <QtCore/QObject>

class dtkAbstractData;
class axlAbstractActorField;
class axlAbstractField;
class axlAbstractActor;
class axlAbstractData;
class axlViewControllerPrivate;

class AXLCORE_EXPORT axlViewController : public QObject
{
    Q_OBJECT

public:
             axlViewController(void);
    virtual ~axlViewController(void);

    axlAbstractActor *actor(dtkAbstractData *data);
    dtkAbstractData *data(axlAbstractActor *actor);

    QList<dtkAbstractData *> data(void);

    int size(void);

    axlAbstractActorField *actorField(axlAbstractField *dataField);
    axlAbstractField *dataField(axlAbstractActorField *actorField);

    QList<axlAbstractField *> dataField(void);

    int sizeField(void);

    bool contains(axlAbstractData *data);

signals:
    void inserted(void);
    void insertedField(void);

public slots:
    bool insert(dtkAbstractData *data, axlAbstractActor *actor);
    void remove(dtkAbstractData *data);

    bool insertField(axlAbstractField *dataField, axlAbstractActorField *actorField);
    void removeField(axlAbstractField *dataField);

public:
    virtual QString description(void) const;

private:
    axlViewControllerPrivate *d;
};

#endif //AXLVIEWCONTROLER_H
