/* dtkComposerSceneNote.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Fri Feb  3 14:02:44 2012 (+0100)
 * Version: $Id: 28a0ae2a0bba42ca7d0b88351b8a9aa455472dc8 $
 * Last-Updated: Mon Mar 25 09:22:11 2013 (+0100)
 *           By: Thibaud Kloczko
 *     Update #: 34
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkComposerSceneNode.h"
#include "dtkComposerSceneNodeComposite.h"
#include "dtkComposerSceneNote.h"

class dtkComposerSceneNotePrivate
{
public:
    dtkComposerSceneNode *parent;

public:
    QPointF drag_point;

public:
    QRectF bounding_rect;

public:
    QGraphicsTextItem *text;
};

dtkComposerSceneNote::dtkComposerSceneNote(void) : QGraphicsItem(), d(new dtkComposerSceneNotePrivate)
{
    d->bounding_rect = QRectF(-100, -100, 200, 200);

    d->text = new QGraphicsTextItem("Note", this);
    d->text->setPos(-100, -100);
    d->text->setTextInteractionFlags(Qt::TextEditorInteraction);
    d->text->setTextWidth(200);

    d->parent = NULL;

    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setZValue(-4000);
}

dtkComposerSceneNote::~dtkComposerSceneNote(void)
{
    delete d;

    d = NULL;
}

QString dtkComposerSceneNote::text(void) const
{
    return d->text->toPlainText();
}

void dtkComposerSceneNote::setSize(const QSizeF& size)
{
    d->bounding_rect.setHeight(size.height());
    d->bounding_rect.setWidth(size.width());

    d->text->setTextWidth(size.width());
}

void dtkComposerSceneNote::setText(const QString& text)
{
    d->text->setPlainText(text);
}

QRectF dtkComposerSceneNote::boundingRect(void) const
{
    return d->bounding_rect;
}

void dtkComposerSceneNote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->fillRect(option->rect, QColor(Qt::yellow).darker());

    painter->fillRect(this->mapRectFromItem(d->text, d->text->boundingRect()), QColor(Qt::yellow));

    // Drawing size grip

    QPainterPath path;
    path.moveTo(d->bounding_rect.bottomRight());
    path.lineTo(d->bounding_rect.bottomRight() + QPointF(-12, 0));
    path.lineTo(d->bounding_rect.bottomRight() + QPointF(0, -12));
    path.lineTo(d->bounding_rect.bottomRight());

    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor("#ffff88"));
    painter->drawPath(path);

    if (this->isSelected()) {
        QPen pen;
        pen.setColor(Qt::magenta);
        pen.setWidth(2);
        painter->setPen(pen);
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(option->rect);
    }
}

void dtkComposerSceneNote::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && !d->drag_point.isNull()) {

        QPointF delta = QPointF(event->scenePos() - d->drag_point);

        d->bounding_rect.setBottomRight(d->bounding_rect.bottomRight() + delta);
        d->text->setTextWidth(d->bounding_rect.width());

        d->drag_point = event->scenePos();

        event->accept();

        this->scene()->update();

    } else {

        QGraphicsItem::mouseMoveEvent(event);
    }
}

void dtkComposerSceneNote::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF br = d->bounding_rect.bottomRight();

    QRectF corner(br.x() - 16, br.y() - 16, 16, 16);

    if (event->button() & Qt::LeftButton && corner.contains(event->pos())) {
        d->drag_point = event->scenePos();
        event->accept();
    }

    QGraphicsItem::mousePressEvent(event);
}

void dtkComposerSceneNote::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton && !d->drag_point.isNull()) {
        d->drag_point = QPointF(0, 0);
        event->accept();
    }

    QGraphicsItem::mouseReleaseEvent(event);
}

dtkComposerSceneNode *dtkComposerSceneNote::parent(void)
{
    return d->parent;
}

void dtkComposerSceneNote::setParent(dtkComposerSceneNode *parent)
{
    d->parent = parent;
}
