/* axlInspectorObjectManagerListItem.h ---
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

#ifndef AXLINSPECTOROBJECTMANAGERLISTITEM_H
#define AXLINSPECTOROBJECTMANAGERLISTITEM_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlAbstractField;
class axlInspectorObjectManagerListItemPrivate;

class AXLGUI_EXPORT axlInspectorObjectManagerListItem : public QListWidgetItem
{

public:
     axlInspectorObjectManagerListItem(const QString & text, axlAbstractField *field, QListWidget *parent = 0);
    ~axlInspectorObjectManagerListItem(void);

public:
    axlAbstractField *field(void);

private:
    axlInspectorObjectManagerListItemPrivate *d;
};

#endif //AXLINSPECTOROBJECTMANAGERLISTITEM_H
