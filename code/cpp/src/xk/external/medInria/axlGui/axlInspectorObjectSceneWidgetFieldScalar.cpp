/* axlInspectorObjectSceneWidgetFieldScalar.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Dec 17 22:48:33 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Jul 20 22:18:05 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 100
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectSceneWidgetFieldScalar.h"
#include "axlInspectorObjectSceneWidgetFieldScalarCol.h"
#include "axlInspectorObjectSceneWidgetFieldScalarIso.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractView.h>

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtGui>

class axlInspectorObjectSceneWidgetFieldScalarPrivate
{
public:
    axlAbstractField *field;
    axlInspectorObjectSceneWidgetFieldScalarCol *col;
    axlInspectorObjectSceneWidgetFieldScalarIso *iso;
    axlAbstractView *view;

public:
    QPushButton *disp_non_button;
    QPushButton *disp_col_button;
    QPushButton *disp_iso_button;

    QVBoxLayout *layout;
};

axlInspectorObjectSceneWidgetFieldScalar::axlInspectorObjectSceneWidgetFieldScalar(QWidget *parent) : QWidget(parent), d(new axlInspectorObjectSceneWidgetFieldScalarPrivate)
{
    d->field = NULL;
    d->col = NULL;
    d->iso = NULL;
    d->view = NULL;

    d->disp_col_button = new QPushButton("Color mapping");
    d->disp_col_button->setCheckable(true);
    d->disp_col_button->setChecked(false);
    d->disp_col_button->setObjectName("left");

    d->disp_iso_button = new QPushButton("Iso contours");
    d->disp_iso_button->setCheckable(true);
    d->disp_iso_button->setChecked(false);
    d->disp_iso_button->setObjectName("right");


    d->disp_non_button = new QPushButton("Nothing");
    d->disp_non_button->setCheckable(true);
    d->disp_non_button->setChecked(false);
    d->disp_non_button->setObjectName("overleft");

    QHBoxLayout *disp_layout = new QHBoxLayout;
    disp_layout->setContentsMargins(0, 0, 0, 0);
    disp_layout->setSpacing(0);
    disp_layout->addWidget(d->disp_non_button);
    disp_layout->addSpacerItem(new QSpacerItem(10, 1));
    disp_layout->addWidget(d->disp_col_button);
    disp_layout->addSpacerItem(new QSpacerItem(10, 1));
    disp_layout->addWidget(d->disp_iso_button);

    d->layout = new QVBoxLayout(this);
    d->layout->setContentsMargins(0, 0, 0, 0);
    d->layout->addWidget(new QLabel("Display", this));
    d->layout->addLayout(disp_layout);

    connect(d->disp_col_button, SIGNAL(clicked()), this, SLOT(onDisplayAsColorClicked()));
    connect(d->disp_iso_button, SIGNAL(clicked()), this, SLOT(onDisplayAsIsoClicked()));
    connect(d->disp_non_button, SIGNAL(clicked()), this, SLOT(onDisplayAsNothingClicked()));


}

axlInspectorObjectSceneWidgetFieldScalar::~axlInspectorObjectSceneWidgetFieldScalar(void)
{
    delete d;

    d = NULL;
}

void axlInspectorObjectSceneWidgetFieldScalar::setIsoCount(int count)
{
    if (d->iso)
        d->iso->setCount(count);
}

void axlInspectorObjectSceneWidgetFieldScalar::setIsoRangeMin(double min)
{
    if (d->iso)
        d->iso->setMin(min);
}

void axlInspectorObjectSceneWidgetFieldScalar::setIsoRangeMax(double max)
{
    if (d->iso)
        d->iso->setMax(max);
}

void axlInspectorObjectSceneWidgetFieldScalar::setField(axlAbstractField *field)
{
    d->field = field;
}

void axlInspectorObjectSceneWidgetFieldScalar::setView(axlAbstractView *view)
{
    d->view = view;
}

void axlInspectorObjectSceneWidgetFieldScalar::setDefaultDisplay(void)
{
    this->onDisplayAsColorClicked();
}

void axlInspectorObjectSceneWidgetFieldScalar::onDisplayAsNothingClicked(void)
{
    if (!d->disp_non_button->isChecked())
        return;

    d->disp_non_button->setChecked(true);
    d->disp_col_button->setChecked(false);
    d->disp_iso_button->setChecked(false);

    if (d->col) {
        d->layout->removeWidget(d->col);
        delete d->col;
        d->col = NULL;
    }

    if (d->iso) {
        d->layout->removeWidget(d->iso);
        delete d->iso;
        d->iso = NULL;
    }

    emit displayAsNone();
}

void axlInspectorObjectSceneWidgetFieldScalar::onDisplayAsColorClicked(void)
{

    if (!d->disp_col_button->isChecked())
        return;

    d->disp_non_button->setChecked(false);
    d->disp_col_button->setChecked(true);
    d->disp_iso_button->setChecked(false);

    if (d->col) {
        d->layout->removeWidget(d->col);
        delete d->col;
        d->col = NULL;
    }

    if (d->iso) {
        d->layout->removeWidget(d->iso);
        delete d->iso;
        d->iso = NULL;
    }

    d->col = new axlInspectorObjectSceneWidgetFieldScalarCol(this);
    d->col->setField(d->field);
    d->col->setView(d->view);

    connect(d->col, SIGNAL(colRangeMinChanged(double)), this, SIGNAL(colRangeMinChanged(double)));
    connect(d->col, SIGNAL(colRangeMaxChanged(double)), this, SIGNAL(colRangeMaxChanged(double)));

    d->layout->addWidget(d->col);

    emit displayAsColor();
}

void axlInspectorObjectSceneWidgetFieldScalar::onDisplayAsIsoClicked(void)
{
    if (!d->disp_iso_button->isChecked())
        return;

    d->disp_non_button->setChecked(false);
    d->disp_col_button->setChecked(false);
    d->disp_iso_button->setChecked(true);

    if (d->col) {
        d->layout->removeWidget(d->col);
        delete d->col;
        d->col = NULL;
    }

    if (d->iso) {
        d->layout->removeWidget(d->iso);
        delete d->iso;
        d->iso = NULL;
    }

    d->iso = new axlInspectorObjectSceneWidgetFieldScalarIso(this);
    d->iso->setField(d->field);
    d->iso->setView(d->view);

    connect(d->iso, SIGNAL(isoCountChanged(int)), this, SIGNAL(isoCountChanged(int)));
    connect(d->iso, SIGNAL(isoRadiusChanged(double)), this, SIGNAL(isoRadiusChanged(double)));
    connect(d->iso, SIGNAL(isoRangeMinChanged(double)), this, SIGNAL(isoRangeMinChanged(double)));
    connect(d->iso, SIGNAL(isoRangeMaxChanged(double)), this, SIGNAL(isoRangeMaxChanged(double)));

    d->layout->addWidget(d->iso);

    emit displayAsIso();
}
