/* @(#)dtkComposerControlsListItemFactory.cpp ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2013 - Nicolas Niclausse, Inria.
 * Created: 2013/06/04 13:22:42
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkComposerControlsListItemFactory.h"

#include "dtkComposerControlsListItem.h"
#include "dtkComposerControlsListItemBoolean.h"
#include "dtkComposerControlsListItemFile.h"
#include "dtkComposerControlsListItemInteger.h"
#include "dtkComposerControlsListItemLeafProcess.h"
#include "dtkComposerControlsListItemReal.h"
#include "dtkComposerControlsListItemString.h"

#include "dtkComposerNodeBoolean.h"
#include "dtkComposerNodeFile.h"
#include "dtkComposerNodeInteger.h"
#include "dtkComposerNodeLeafProcess.h"
#include "dtkComposerNodeReal.h"
#include "dtkComposerNodeString.h"


dtkComposerControlsListItemFactory::dtkComposerControlsListItemFactory(void)
{
}

dtkComposerControlsListItemFactory::~dtkComposerControlsListItemFactory(void)
{
}

dtkComposerControlsListItemFactory  *dtkComposerControlsListItemFactory::instance(void)
{
    if (!s_instance)
        s_instance = new dtkComposerControlsListItemFactory;

    return s_instance;
}


dtkComposerControlsListItem *dtkComposerControlsListItemFactory::create(QListWidget *list, dtkComposerSceneNode *node)
{
    if (dynamic_cast<dtkComposerNodeInteger *>(node->wrapee()))
        return new dtkComposerControlsListItemInteger(list, node);

    else if (dynamic_cast<dtkComposerNodeBoolean *>(node->wrapee()))
        return new dtkComposerControlsListItemBoolean(list, node);

    else if (dynamic_cast<dtkComposerNodeReal *>(node->wrapee()))
        return new dtkComposerControlsListItemReal(list, node);

    else if (dynamic_cast<dtkComposerNodeString *>(node->wrapee()))
        return new dtkComposerControlsListItemString(list, node);

    else if (dynamic_cast<dtkComposerNodeFile *>(node->wrapee()))
        return new dtkComposerControlsListItemFile(list, node);

    else if (dynamic_cast<dtkComposerNodeLeafProcess *>(node->wrapee()))
        return new dtkComposerControlsListItemLeafProcess(list, node);

    else
        return new dtkComposerControlsListItem(list, node);
}

dtkToolBoxItem *dtkComposerControlsListItemFactory::create(dtkComposerSceneNode *node)
{
    if (dtkComposerNodeLeafProcess *p_node = dynamic_cast<dtkComposerNodeLeafProcess *>(node->wrapee())) {

        QObject *object = reinterpret_cast<QObject *>(p_node->process());

        if (object)
            return dtkToolBoxItem::fromObject(object);
    }

    return new dtkToolBoxItem();
}

dtkComposerControlsListItemFactory *dtkComposerControlsListItemFactory::s_instance = NULL;




