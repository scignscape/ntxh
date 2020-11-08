/* dtkComposerControlsListItemLeafProcess.cpp ---
 *
 * Author: Thibaud Kloczko
 * Created: jeu. oct. 10 16:19:35 2013 (+0200)
 * Version:
 * Last-Updated: mar. févr.  4 15:07:27 2014 (+0100)
 *           By: Nicolas Niclausse
 *     Update #: 598
 */

/* Change Log:
 *
 */

#include "dtkComposerControlsListItemLeafProcess.h"
#include "dtkComposerNodeLeafProcess.h"

#include <dtkComposerSupportExport.h>

#include <dtkCoreSupport/dtkGlobal.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <dtkWidgets/dtkObjectEditor.h>
#include <dtkWidgets/dtkToolBox.h>

#include <QObject>
#include <QVariant>
#include <QMetaProperty>

class dtkComposerControlsListItemLeafProcessPrivate
{
public:
    QListWidget *parent;

public:
    dtkComposerSceneNode *node;

public:
    dtkComposerNodeLeafProcess *p_node;

public:
    QString implementation;

public:
    dtkToolBoxItem *item;
};

// ///////////////////////////////////////////////////////////////////
//
// ///////////////////////////////////////////////////////////////////

dtkComposerControlsListItemLeafProcess::dtkComposerControlsListItemLeafProcess(QListWidget *parent, dtkComposerSceneNode *node) : dtkComposerControlsListItem(parent, node), d(new dtkComposerControlsListItemLeafProcessPrivate)
{
    d->node = node;

    if (dtkComposerNodeLeafProcess *p_node = dynamic_cast<dtkComposerNodeLeafProcess *>(d->node->wrapee())) {
        d->p_node = p_node;
        d->implementation = p_node->process()->identifier();
    } else {
        dtkError() << Q_FUNC_INFO << "Can't create control list item of type Leaf Process.";
        d->implementation = "";
    }

    d->parent = parent;

    d->item = NULL;
}


dtkComposerControlsListItemLeafProcess::~dtkComposerControlsListItemLeafProcess(void )
{
    delete d;
    d = NULL;
}

QWidget *dtkComposerControlsListItemLeafProcess::widget(void)
{
    if (d->item && !(d->p_node->implementationHasChanged(d->implementation)))
        return d->item;

    if (d->item)
        delete d->item;

    QObject *object = d->p_node->process();

    if (object) {
        d->item = dtkToolBoxItem::fromObject(object);
        d->implementation = d->p_node->process()->identifier();
    } else {
        d->implementation = "";
    }

    return d->item;
}


