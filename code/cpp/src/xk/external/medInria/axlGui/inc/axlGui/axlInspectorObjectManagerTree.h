/* axlInspectorObjectManagerTree.h ---
 *
 * Author: Julien Wintz
  * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Thu Mar 17 18:33:35 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Mar 18 10:28:52 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTMANAGERTREE_H
#define AXLINSPECTOROBJECTMANAGERTREE_H

#include "axlGuiExport.h"

#include <QtWidgets>

#include <axlCore/axlDataDynamic.h>

class axlAbstractData;
class dtkAbstractData;

class axlInspectorObjectController;
class axlInspectorObjectManagerTreeItem;

class axlInspectorObjectManagerTreePrivate;

class AXLGUI_EXPORT axlInspectorObjectManagerTree: public QTreeWidget
{
    Q_OBJECT

public:
     axlInspectorObjectManagerTree(QWidget *parent = 0);
    ~axlInspectorObjectManagerTree(void);

    axlInspectorObjectManagerTreeItem *insert(axlAbstractData *data);
    void remove(dtkAbstractData *data);
    void setController(axlInspectorObjectController *controller);

    QList<dtkAbstractData *> dataSet(void);

    void keyPressEvent(QKeyEvent *event);

    void removeAllItems(void);

signals:
    void inserted(void);
    void dataSetRemoved(QList<dtkAbstractData *> dataSetRemoved);
    void selected(dtkAbstractData *data);
    void dataSetSelected(QList<dtkAbstractData *> data);
    void stateChanged(dtkAbstractData *data, int mode);
    void actorVisibilityChanged(dtkAbstractData *data, bool actorVisibility);

public slots:
    void onAllItemClickStatedChanged();
    void onDoubleClickStateChanged(QTreeWidgetItem* currentItem, int column);
    void onItemClickedStateChanged(QTreeWidgetItem* currentItem, int column);
    void onItemExpanded(QTreeWidgetItem *);
    void onStateChanged(dtkAbstractData *data, int mode);
    void setAppendMode(bool append);
    void onDataRemoved(QList<dtkAbstractData *> dataToRemoved);
    void remove(QObject *data);
    void onVisibilityHeaderClick(int index);


private:
    void updateAxlTreeWidgetItem(axlInspectorObjectManagerTreeItem *axlCurrentItem, int mode);

private://recursive
    void itemVisibilityChanged(QTreeWidgetItem *currentItem, bool itemVisibility);
    void removeTreeItems(dtkAbstractData *data, QList<dtkAbstractData *> &dataNotDynamicList, QList<axlDataDynamic *> &dataDynamicList);
    void deleteTreeWidgetItems(QList<QTreeWidgetItem*> selectedItems);

private:
    axlInspectorObjectManagerTreePrivate *d;
};

#endif //AXLINSPECTOROBJECTMANAGERTREE_H
