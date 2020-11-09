/* axlInspectorObjectManagerList.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Mon Mar 14 18:25:24 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Mar 14 18:25:57 2011 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 3
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectManagerList.h"
#include "axlInspectorObjectManagerListItem.h"

#include "axlCore/axlAbstractData.h"
#include "axlCore/axlAbstractField.h"


class axlInspectorObjectManagerListPrivate
{
public:
    axlAbstractData *axlData;


    //public:
    //    QList<axlInspectorObjectManagerListItem *> itemList;
};

axlInspectorObjectManagerList::axlInspectorObjectManagerList(QWidget *parent) : QListWidget(parent), d(new axlInspectorObjectManagerListPrivate)
{
    d->axlData = NULL;

    this->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->setFrameShape(QFrame::NoFrame);
}

axlInspectorObjectManagerList::~axlInspectorObjectManagerList(void)
{
    delete d;

    d = NULL;
}

axlAbstractData *axlInspectorObjectManagerList::axlData(void)
{
    return d->axlData;
}

void axlInspectorObjectManagerList::setData(axlAbstractData *data)
{
    this->clear();

    d->axlData = data;

    foreach(axlAbstractField *field, data->fields()){
        this->addItem(new axlInspectorObjectManagerListItem(field->name(), field,this));
    }

}
