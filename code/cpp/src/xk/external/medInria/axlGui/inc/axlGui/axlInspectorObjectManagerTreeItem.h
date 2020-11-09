/* axlInspectorObjectManagerTreeItem.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 18:24:29 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Mar 14 18:25:06 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 7
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTMANAGERTREEITEM_H
#define AXLINSPECTOROBJECTMANAGERTREEITEM_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlInspectorObjectManagerTreeItemPrivate;

class AXLGUI_EXPORT axlInspectorObjectManagerTreeItem : public QTreeWidgetItem
{

public:
             axlInspectorObjectManagerTreeItem(QTreeWidgetItem *parent = 0);
             axlInspectorObjectManagerTreeItem(QTreeWidget *parent, const QStringList & strings, int type = 0);
    virtual ~axlInspectorObjectManagerTreeItem(void);

private:
    axlInspectorObjectManagerTreeItemPrivate *d;
};

#endif //AXLINSPECTOROBJECTMANAGERTREEITEM_H
