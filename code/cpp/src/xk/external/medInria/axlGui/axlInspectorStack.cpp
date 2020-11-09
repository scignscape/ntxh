/* axlInspectorStack.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Mar 15 14:09:00 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Dec 27 12:56:36 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 89
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorStack.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkGuiSupport/dtkSpacer.h>

#include <QtGui>

class axlInspectorStackPrivate
{
public:
    QStackedWidget *widget;
    QToolBar *bar;

    QMap<QAction *, QWidget *> actions;
};

axlInspectorStack::axlInspectorStack(QWidget *parent) : QFrame(parent), d(new axlInspectorStackPrivate)
{
    d->widget = new QStackedWidget(this);
    d->widget->setFixedWidth(290);
    // d->widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    d->bar = new QToolBar(this);
    d->bar->setFloatable(false);

    QScrollArea *area = new QScrollArea(this);
    area->setAttribute(Qt::WA_MacShowFocusRect, false);
    area->setFrameShape(QFrame::NoFrame);
    area->setContentsMargins(0, 0, 0, 0);
    area->setWidget(d->widget);
    area->setWidgetResizable(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(d->bar);
    layout->addWidget(area);
    layout->setSpacing(0);



    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
}

axlInspectorStack::~axlInspectorStack(void)
{
    delete d;

    d = NULL;
}

void axlInspectorStack::addWidget(QString title, QWidget *widget)
{
    static int count = 0;

    d->widget->addWidget(widget);

    QAction *action = d->bar->addAction(title, this, SLOT(onActionClicked()));
    action->setShortcut(QKeySequence(QString("Ctrl+%1").arg(QString::number(++count))));

    this->addAction(action);

    d->actions.insert(action, widget);
}

int axlInspectorStack::width(void) const
{
   return QFrame::width();
}

void axlInspectorStack::setWidth(int width)
{
   this->setFixedWidth(width);
}

void axlInspectorStack::onActionClicked(void)
{
    d->widget->setCurrentWidget(d->actions.value(dynamic_cast<QAction *>(this->sender())));
}
