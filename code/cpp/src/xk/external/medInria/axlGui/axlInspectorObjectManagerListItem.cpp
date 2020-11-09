/* axlInspectorObjectManagerListItem.cpp ---
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

#include "axlInspectorObjectManagerListItem.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlDouble.h>

class axlInspectorObjectManagerListItemPrivate
{
public:
    axlAbstractField *field;
};

axlInspectorObjectManagerListItem::axlInspectorObjectManagerListItem(const QString & text, axlAbstractField *field, QListWidget *parent) : QListWidgetItem(text, parent) , d(new axlInspectorObjectManagerListItemPrivate)
{
    d->field = field;
}

axlInspectorObjectManagerListItem::~axlInspectorObjectManagerListItem(void)
{
    delete d;

    d = NULL;
}

axlAbstractField *axlInspectorObjectManagerListItem::field(void)
{
    return d->field;
}
