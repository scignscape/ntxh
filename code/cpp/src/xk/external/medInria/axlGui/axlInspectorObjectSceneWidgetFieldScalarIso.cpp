/* axlInspectorObjectSceneWidgetFieldScalarIso.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Sun Dec 19 18:53:23 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Jul 20 22:20:43 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 145
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectSceneWidgetFieldScalarIso.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractActorField.h>
#include <axlCore/axlAbstractView.h>

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtGui>

class axlInspectorObjectSceneWidgetFieldScalarIsoPrivate
{
public:
    axlAbstractField *field;
    axlAbstractView *view;

public:
          QSpinBox *iso_count_spin;
    QDoubleSpinBox *iso_radius_spin;
    QDoubleSpinBox *iso_range_min_spin;
    QDoubleSpinBox *iso_range_max_spin;
       QPushButton *button_reset_min;
       QPushButton *button_reset_max;
};

axlInspectorObjectSceneWidgetFieldScalarIso::axlInspectorObjectSceneWidgetFieldScalarIso(QWidget *parent) : QWidget(parent), d(new axlInspectorObjectSceneWidgetFieldScalarIsoPrivate)
{
    d->field = NULL;
    d->view = NULL;

    QWidget *iso_form = new QWidget(this);
    iso_form->setObjectName("axlInspectorObjectSceneWidgetFieldScalarIsoForm");

    QWidget *iso_form_range_min = new QWidget(iso_form);
    QWidget *iso_form_range_max = new QWidget(iso_form);

    d->iso_count_spin = new QSpinBox(iso_form); d->iso_count_spin->setMaximum(1000);

    d->iso_radius_spin = new QDoubleSpinBox(iso_form);
     d->iso_radius_spin->setValue(0.01);
    d->iso_radius_spin->setMaximum(1000);
    d->iso_radius_spin->setMinimum(0.0);
    d->iso_radius_spin->setDecimals(5);
    d->iso_radius_spin->setSingleStep(0.01);

    d->iso_range_min_spin = new QDoubleSpinBox(iso_form);
    d->iso_range_min_spin->setDecimals(5);
    d->iso_range_min_spin->setMinimum(-1.e6);
    d->iso_range_min_spin->setMaximum(1.e6);


    d->iso_range_max_spin = new QDoubleSpinBox(iso_form);
    d->iso_range_max_spin->setDecimals(5);
    d->iso_range_max_spin->setMinimum(-1.e6);
    d->iso_range_max_spin->setMaximum(1.e6);


    d->button_reset_min = new QPushButton("reset", iso_form);
    d->button_reset_max = new QPushButton("reset", iso_form);

    QHBoxLayout *iso_form_range_min_layout = new QHBoxLayout(iso_form_range_min);
    iso_form_range_min_layout->setContentsMargins(0, 0, 0, 0);
    iso_form_range_min_layout->addWidget(d->iso_range_min_spin);
    iso_form_range_min_layout->addWidget(d->button_reset_min);

    QHBoxLayout *iso_form_range_max_layout = new QHBoxLayout(iso_form_range_max);
    iso_form_range_max_layout->setContentsMargins(0, 0, 0, 0);
    iso_form_range_max_layout->addWidget(d->iso_range_max_spin);
    iso_form_range_max_layout->addWidget(d->button_reset_max);

    QFormLayout *iso_form_layout = new QFormLayout(iso_form);
    iso_form_layout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    iso_form_layout->setContentsMargins(0, 0, 0, 0);
    iso_form_layout->addRow("Number of contours:", d->iso_count_spin);
    iso_form_layout->addRow("Radius of tubes:", d->iso_radius_spin);
    iso_form_layout->addRow(new QLabel("Range", this));
    iso_form_layout->addRow("Minimum value:", iso_form_range_min);
    iso_form_layout->addRow("Maximum value:", iso_form_range_max);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(new QLabel("Iso contours", this));
    layout->addWidget(iso_form);


    connect(d->iso_count_spin, SIGNAL(valueChanged(int)), this, SIGNAL(isoCountChanged(int)));
    connect(d->iso_radius_spin, SIGNAL(valueChanged(double)), this, SIGNAL(isoRadiusChanged(double)));
    connect(d->iso_range_min_spin, SIGNAL(valueChanged(double)), this, SIGNAL(isoRangeMinChanged(double)));
    connect(d->button_reset_min, SIGNAL(clicked()), this, SLOT(onResetMinimalValueClicked()));
    connect(d->iso_range_max_spin, SIGNAL(valueChanged(double)), this, SIGNAL(isoRangeMaxChanged(double)));
    connect(d->button_reset_max, SIGNAL(clicked()), this, SLOT(onResetMaximalValueClicked()));
}

axlInspectorObjectSceneWidgetFieldScalarIso::~axlInspectorObjectSceneWidgetFieldScalarIso(void)
{
    delete d;

    d = NULL;
}

void axlInspectorObjectSceneWidgetFieldScalarIso::setCount(int count)
{
    d->iso_count_spin->setValue(count);
}

void axlInspectorObjectSceneWidgetFieldScalarIso::setMin(double min)
{
    d->iso_range_min_spin->setValue(min);
}

void axlInspectorObjectSceneWidgetFieldScalarIso::setMax(double max)
{
    d->iso_range_max_spin->setValue(max);
}

void axlInspectorObjectSceneWidgetFieldScalarIso::setField(axlAbstractField *field)
{
    d->field = field;

    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field))) {

        this->setCount(actor->isoCount());
        this->setMax(actor->isoRangeMax());
        this->setMin(actor->isoRangeMin());
    }
}

void axlInspectorObjectSceneWidgetFieldScalarIso::setView(axlAbstractView *view)
{
    d->view = view;

    if(!d->field)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field))) {

        this->setCount(actor->isoCount());
        this->setMax(actor->isoRangeMax());
        this->setMin(actor->isoRangeMin());
    }
}

void axlInspectorObjectSceneWidgetFieldScalarIso::onResetMinimalValueClicked(void)
{
    this->setMin(d->field->minValue());
}

void axlInspectorObjectSceneWidgetFieldScalarIso::onResetMaximalValueClicked(void)
{
    this->setMax(d->field->maxValue());
}
