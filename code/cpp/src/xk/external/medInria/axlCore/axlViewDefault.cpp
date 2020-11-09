#include "axlViewDefault.h"
#include "axlAbstractSurfaceBSpline.h"
#include "axlAbstractActor.h"
#include "axlViewController.h"

#include <QtWidgets>

class axlViewDefaultPrivate
{
public:
    QLabel *label;
};

axlViewDefault::axlViewDefault(void) : axlAbstractView(), d(new axlViewDefaultPrivate)
{
    d->label = new QLabel("No view implementation available");
    d->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

axlViewDefault::~axlViewDefault(void)
{
    delete d;

    d = NULL;
}

QWidget *axlViewDefault::widget(void)
{
    return d->label;
}
