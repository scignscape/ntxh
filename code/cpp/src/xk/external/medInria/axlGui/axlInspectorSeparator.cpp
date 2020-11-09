/* axlInspectorSeparator.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Mar 15 14:09:00 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Thu Mar 17 23:58:44 2011 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 50
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorSeparator.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtGui>

class axlInspectorSeparatorPrivate
{
public:
    Qt::Orientations orientation;

};


axlInspectorSeparator::axlInspectorSeparator(QWidget *parent, Qt::Orientation orientation) : QWidget(parent), d(new axlInspectorSeparatorPrivate)
{
    d->orientation = orientation;

    if(d->orientation == Qt::Horizontal)
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    else
        this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

}

axlInspectorSeparator::~axlInspectorSeparator(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorSeparator::sizeHint(void) const
{
    if(d->orientation == Qt::Horizontal)
        return QSize(100, 2);
    else
        return QSize(2, 100);
}

void axlInspectorSeparator::paintEvent(QPaintEvent *event)
{
    if(d->orientation == Qt::Horizontal)
    {
        QRect r = event->rect();
        QPainter painter(this);
        painter.setPen(QPen(QColor("#9b9b9b")));
        painter.drawLine(r.topLeft(), r.topRight());
        painter.setPen(QPen(QColor("#ffffff")));
        painter.drawLine(r.bottomLeft(), r.bottomRight());
    }
    else
    {
        QRect r = event->rect();
        QPainter painter(this);
        painter.setPen(QPen(QColor("#9b9b9b")));
        painter.drawLine(r.topLeft(), r.bottomLeft());
        painter.setPen(QPen(QColor("#ffffff")));
        painter.drawLine(r.topRight(), r.bottomRight());
    }
}
