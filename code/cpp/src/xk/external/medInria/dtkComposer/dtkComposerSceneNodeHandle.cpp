// Version: $Id: 0dd38a1b3237d9c5888d1efa3b8d472a41dbd6c2 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerSceneNodeComposite.h"
#include "dtkComposerSceneNodeControl.h"
#include "dtkComposerSceneNodeHandle.h"

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class dtkComposerSceneNodeHandlePrivate
{
public:
    dtkComposerSceneNodeControl *parent;

public:
    dtkComposerSceneNodeComposite *top;
    dtkComposerSceneNodeComposite *bot;

public:
    QRectF rect;
};

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

dtkComposerSceneNodeHandle::dtkComposerSceneNodeHandle(dtkComposerSceneNodeControl *parent) : QGraphicsItem(parent), d(new dtkComposerSceneNodeHandlePrivate)
{
    d->parent = parent;

    d->top = NULL;
    d->bot = NULL;

    d->rect = QRectF(-20, -3, 40, 6);

    this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

dtkComposerSceneNodeHandle::~dtkComposerSceneNodeHandle(void)
{
    delete d;

    d = NULL;
}

void dtkComposerSceneNodeHandle::setTopBlock(dtkComposerSceneNodeComposite *block)
{
    d->top = block;
}

void dtkComposerSceneNodeHandle::setBotBlock(dtkComposerSceneNodeComposite *block)
{
    d->bot = block;
}

void dtkComposerSceneNodeHandle::layout(void)
{
    if (d->top && d->bot) {
        QRectF top_rec = d->top->boundingRect();
        this->setPos(top_rec.width() / 2, d->top->pos().y() + top_rec.bottom() - 2);
    }
}

QRectF dtkComposerSceneNodeHandle::boundingRect(void) const
{
    return d->rect;
}

void dtkComposerSceneNodeHandle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::lightGray);
    painter->setBrush(QColor(60, 60, 60));
    painter->drawRoundedRect(d->rect, 3, 3);
}

void dtkComposerSceneNodeHandle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qreal delta = event->pos().y() - event->lastPos().y();

    d->parent->resizeBlock(d->top, 0.0, delta);
    d->parent->moveBlock(d->bot, 0.0, delta);

    d->parent->layout();
}

//
// dtkComposerSceneNodeHandle.cpp ends here
