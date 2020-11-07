// Version: $Id: 6b018ffa086151783e53ce33b394d63ce0150083 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerViewLayout.h"
#include "dtkComposerViewLayoutItem.h"

class dtkComposerViewLayoutPrivate
{
public:
    dtkComposerViewLayoutItem *root;
    dtkComposerViewLayoutItem *current;
};

dtkComposerViewLayout::dtkComposerViewLayout(QWidget *parent) : QFrame(parent), d(new dtkComposerViewLayoutPrivate)
{
    d->root = new dtkComposerViewLayoutItem(0);
    d->root->setParent(this);
    d->root->setLayout(this);

    d->current = d->root;

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(d->root);

    connect(d->root, SIGNAL(focused(dtkComposerViewWidget *)), this, SIGNAL(focused(dtkComposerViewWidget *)));
    connect(d->root, SIGNAL(unfocused(dtkComposerViewWidget *)), this, SIGNAL(unfocused(dtkComposerViewWidget *)));
}

dtkComposerViewLayout::~dtkComposerViewLayout(void)
{
    delete d;

    d = NULL;
}

dtkComposerViewLayoutItem *dtkComposerViewLayout::root(void)
{
    return d->root;
}

dtkComposerViewLayoutItem *dtkComposerViewLayout::current(void)
{
    return d->current;
}

void dtkComposerViewLayout::setCurrent(dtkComposerViewLayoutItem *item)
{
    d->current = item;
}

void dtkComposerViewLayout::clear(void)
{
    d->root->clear();
}

//
// dtkComposerViewLayout.cpp ends here
