// Version: $Id: 354fbbb0b6fff3cbe5ed7b294e7f4423664c5528 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerViewManager.h"
#include "dtkComposerViewList.h"
#include "dtkComposerViewLayout.h"
#include "dtkComposerViewListControl.h"
#include "dtkComposerViewWidget.h"

#include <QtWidgets>

class dtkComposerViewManagerPrivate
{
public:
    dtkComposerViewList *view_list;
    dtkComposerViewLayout *view_layout;
    QStackedWidget *view_inspector;
};

dtkComposerViewManager::dtkComposerViewManager(QWidget *parent) : QFrame(parent), d(new dtkComposerViewManagerPrivate)
{
    d->view_list = new dtkComposerViewList;
    d->view_layout = new dtkComposerViewLayout;
    d->view_inspector = new QStackedWidget;

    dtkComposerViewListControl *view_control = new dtkComposerViewListControl(this);
    view_control->setLayout(d->view_layout);
    view_control->setList(d->view_list);

    QFrame *frame = new QFrame;
    frame->setAutoFillBackground(true);
    frame->setFixedWidth(300);

    QVBoxLayout *layout = new QVBoxLayout(frame);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(view_control);
    layout->addWidget(d->view_list);
    layout->addWidget(d->view_inspector);

    QHBoxLayout *main_layout = new QHBoxLayout(this);
    main_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->setSpacing(0);
    main_layout->addWidget(frame);
    main_layout->addWidget(d->view_layout);

    // Behaviour

    connect(d->view_layout, SIGNAL(focused(dtkComposerViewWidget *)), this, SIGNAL(focused(dtkComposerViewWidget *)));
    connect(d->view_layout, SIGNAL(focused(dtkComposerViewWidget *)), this, SLOT(onViewFocused(dtkComposerViewWidget *)));
    connect(d->view_layout, SIGNAL(unfocused(dtkComposerViewWidget *)), this, SLOT(onViewUnfocused(dtkComposerViewWidget *)));
}

dtkComposerViewManager::~dtkComposerViewManager(void)
{
    delete d;

    d = NULL;
}

void dtkComposerViewManager::clear(void)
{
    d->view_list->clear();
    d->view_layout->clear();
}

void dtkComposerViewManager::onViewFocused(dtkComposerViewWidget *widget)
{
    if (!widget->inspector())
        return;

    d->view_inspector->addWidget(widget->inspector());
    d->view_inspector->setCurrentWidget(widget->inspector());
}

void dtkComposerViewManager::onViewUnfocused(dtkComposerViewWidget *widget)
{
    if (!widget->inspector())
        return;

    d->view_inspector->removeWidget(widget->inspector());
}

//
// dtkComposerViewManager.cpp ends here
