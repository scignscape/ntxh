// Version: $Id: f73b115d80ffe40b08592edf55d86ff16c9e5dad $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerScene.h"
#include "dtkComposerSceneModel.h"
#include "dtkComposerSceneView.h"

class dtkComposerSceneViewPrivate
{
public:
    dtkComposerScene *scene;
};

dtkComposerSceneView::dtkComposerSceneView(QWidget *parent) : QTreeView(parent), d(new dtkComposerSceneViewPrivate)
{
    d->scene = NULL;

    this->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->setFrameStyle(QFrame::NoFrame);
}

dtkComposerSceneView::~dtkComposerSceneView(void)
{
    delete d;

    d = NULL;
}

void dtkComposerSceneView::setScene(dtkComposerScene *scene)
{
    d->scene = scene;

    connect(d->scene, SIGNAL(selectionCleared()), this, SLOT(clearSelection()));
}

void dtkComposerSceneView::reset(void)
{
    QTreeView::reset();

    this->expandAll();
}

void dtkComposerSceneView::clearSelection(void)
{
    this->selectionModel()->clearSelection();
}

void dtkComposerSceneView::selectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    QTreeView::selectionChanged(selected, deselected);

    d->scene->blockSignals(true);

    d->scene->clearSelection();

    if (selected.indexes().count())
        if (QGraphicsItem *item = static_cast<QGraphicsItem *>(selected.indexes().first().internalPointer()))
            item->setSelected(true);

    if (deselected.indexes().count())
        if (QGraphicsItem *item = static_cast<QGraphicsItem *>(deselected.indexes().first().internalPointer()))
            item->setSelected(false);

    d->scene->blockSignals(false);
}

//
// dtkComposerSceneView.cpp ends here
