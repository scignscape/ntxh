/* axlInspectorObjectManagerTreeItem.cpp ---
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 18:25:24 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Mar 14 18:25:57 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 3
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "axlInspectorObjectManagerTreeItem.h"
#include <QtDebug>

class axlInspectorObjectManagerTreeItemPrivate
{
public:
};

axlInspectorObjectManagerTreeItem::axlInspectorObjectManagerTreeItem(QTreeWidgetItem *parent) : QTreeWidgetItem(parent), d(new axlInspectorObjectManagerTreeItemPrivate)
{

}

axlInspectorObjectManagerTreeItem::axlInspectorObjectManagerTreeItem(QTreeWidget *parent, const QStringList& strings,int type) : QTreeWidgetItem(parent, strings, type), d(new axlInspectorObjectManagerTreeItemPrivate)
{

}

axlInspectorObjectManagerTreeItem::~axlInspectorObjectManagerTreeItem(void)
{
    delete d;
    d = NULL;
}
