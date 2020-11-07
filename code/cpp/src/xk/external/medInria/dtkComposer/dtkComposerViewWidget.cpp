// Version: $Id: b7aa3e92b90709307f253d152dd8b3719a5811e3 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerViewWidget.h"

class dtkComposerViewWidgetPrivate
{
public:

};

dtkComposerViewWidget::dtkComposerViewWidget(void)
{
    d = new dtkComposerViewWidgetPrivate;
}

dtkComposerViewWidget::~dtkComposerViewWidget(void)
{
    delete d;
}

QWidget *dtkComposerViewWidget::widget(void)
{
    return NULL;
}

QWidget *dtkComposerViewWidget::inspector(void)
{
    return NULL;
}

//
// dtkComposerViewWidget.cpp ends here
