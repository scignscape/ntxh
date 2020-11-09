/* axlAbstractCurve.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Apr 20 15:09:54 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 23
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTCONTROLER_H
#define AXLINSPECTOROBJECTCONTROLER_H

#include "axlGuiExport.h"

#include <QtCore/QObject>

class dtkAbstractData;

class axlInspectorObjectManagerTreeItem;
class axlInspectorObjectControllerPrivate;

class AXLGUI_EXPORT axlInspectorObjectController : public QObject
{
    Q_OBJECT

public:
    axlInspectorObjectController(void);
    virtual ~axlInspectorObjectController(void);

    axlInspectorObjectManagerTreeItem *item(dtkAbstractData *data);

    dtkAbstractData *data(axlInspectorObjectManagerTreeItem *item);
    dtkAbstractData *data(QString dataname);


    QList<axlInspectorObjectManagerTreeItem *> items(void);
    QList<dtkAbstractData  *> datas(void);

    int size(void);

public slots:
    bool insert(dtkAbstractData *data, axlInspectorObjectManagerTreeItem *item);
    void remove(dtkAbstractData *data);
    void onDataRemoved(QList<dtkAbstractData *> dataToRemoved);


signals:
    void inserted(void);

public:
    virtual QString description(void) const;

private:
    axlInspectorObjectControllerPrivate *d;
};

#endif //AXLINSPECTOROBJECTCONTROLER_H
