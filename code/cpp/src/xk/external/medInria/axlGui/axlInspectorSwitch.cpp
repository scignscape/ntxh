/* axlInspectorSwitch.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Feb  4 17:35:45 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Mar 14 14:54:28 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 9
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorSwitch.h"

#include <QtGui/QPainter>
#include <QtGui/QPaintEvent>

class axlInspectorSwitchPrivate
{
public:
    QPixmap pixmap;

    bool toggled;
};

axlInspectorSwitch::axlInspectorSwitch(QWidget *parent) : QWidget(parent), d(new axlInspectorSwitchPrivate)
{
    d->pixmap = QPixmap(":dtkGuiSupport/pixmaps/axlInspectorSwitch-off.png");

    d->toggled = false;

    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

axlInspectorSwitch::~axlInspectorSwitch(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorSwitch::sizeHint(void) const
{
    return d->pixmap.size();
}

void axlInspectorSwitch::mousePressEvent(QMouseEvent *event)
{
    d->toggled = !d->toggled;

    if(d->toggled)
        d->pixmap = QPixmap(":dtkGuiSupport/pixmaps/axlInspectorSwitch-on.png");
    else
        d->pixmap = QPixmap(":dtkGuiSupport/pixmaps/axlInspectorSwitch-off.png");

    this->update();

    emit toggled(d->toggled);
}

void axlInspectorSwitch::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(event->rect(), d->pixmap);
}
