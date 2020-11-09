/* axlInspectorObjectSceneWidgetFieldScalarCol.cpp ---
 *
 * Author: Thibaud Kloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Mon Jun 20 14:16:20 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Jul 20 22:11:34 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 18
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectSceneWidgetFieldScalarCol.h"

#include <axlCore/axlAbstractFieldDiscrete.h>
#include <axlCore/axlAbstractActorField.h>
#include <axlCore/axlAbstractView.h>

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtGui>

class axlInspectorObjectSceneWidgetFieldScalarColPrivate
{
public:
    axlAbstractField *field;
    axlAbstractView *view;

public:
          QSpinBox *col_count_spin;
    QDoubleSpinBox *col_range_min_spin;
    QDoubleSpinBox *col_range_max_spin;
       QPushButton *button_reset_min;
       QPushButton *button_reset_max;
};

axlInspectorObjectSceneWidgetFieldScalarCol::axlInspectorObjectSceneWidgetFieldScalarCol(QWidget *parent) : QWidget(parent), d(new axlInspectorObjectSceneWidgetFieldScalarColPrivate)
{
    d->field = NULL;
    d->view = NULL;

    QWidget *col_form = new QWidget(this);
    col_form->setObjectName("axlInspectorObjectSceneWidgetFieldScalarColForm");

    QWidget *col_form_range_min = new QWidget(col_form);
    QWidget *col_form_range_max = new QWidget(col_form);

    d->col_range_min_spin = new QDoubleSpinBox(col_form);
    d->col_range_min_spin->setDecimals(6);
    d->col_range_min_spin->setMinimum(-1.e6);
    d->col_range_min_spin->setMaximum(1.e6);

    d->col_range_max_spin = new QDoubleSpinBox(col_form);
    d->col_range_max_spin->setDecimals(6);
    d->col_range_max_spin->setMinimum(-1.e6);
    d->col_range_max_spin->setMaximum(1.e6);

    d->button_reset_min = new QPushButton("reset", col_form);
    d->button_reset_max = new QPushButton("reset", col_form);

    QHBoxLayout *col_form_range_min_layout = new QHBoxLayout(col_form_range_min);
    col_form_range_min_layout->setContentsMargins(0, 0, 0, 0);
    col_form_range_min_layout->addWidget(d->col_range_min_spin);
    col_form_range_min_layout->addWidget(d->button_reset_min);

    QHBoxLayout *col_form_range_max_layout = new QHBoxLayout(col_form_range_max);
    col_form_range_max_layout->setContentsMargins(0, 0, 0, 0);
    col_form_range_max_layout->addWidget(d->col_range_max_spin);
    col_form_range_max_layout->addWidget(d->button_reset_max);

    QFormLayout *col_form_layout = new QFormLayout(col_form);
    col_form_layout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    col_form_layout->setContentsMargins(0, 0, 0, 0);
    col_form_layout->addRow(new QLabel("Range", this));
    col_form_layout->addRow("Minimum value:", col_form_range_min);
    col_form_layout->addRow("Maximum value:", col_form_range_max);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(col_form);


    connect(d->col_range_min_spin, SIGNAL(valueChanged(double)), this, SIGNAL(colRangeMinChanged(double)));
    connect(d->button_reset_min, SIGNAL(clicked()), this, SLOT(onResetMinimalValueClicked()));
    connect(d->col_range_max_spin, SIGNAL(valueChanged(double)), this, SIGNAL(colRangeMaxChanged(double)));
    connect(d->button_reset_max, SIGNAL(clicked()), this, SLOT(onResetMaximalValueClicked()));
}

axlInspectorObjectSceneWidgetFieldScalarCol::~axlInspectorObjectSceneWidgetFieldScalarCol(void)
{
    delete d;

    d = NULL;
}

void axlInspectorObjectSceneWidgetFieldScalarCol::setMin(double min)
{
    d->col_range_min_spin->setValue(min);
}

void axlInspectorObjectSceneWidgetFieldScalarCol::setMax(double max)
{
    d->col_range_max_spin->setValue(max);
}

void axlInspectorObjectSceneWidgetFieldScalarCol::setField(axlAbstractField *field)
{
    d->field = field;

    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field))) {
        this->setMax(actor->colRangeMax());
        this->setMin(actor->colRangeMin());
    }
}

void axlInspectorObjectSceneWidgetFieldScalarCol::setView(axlAbstractView *view)
{
    d->view = view;

    if(!d->field)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field))) {
        this->setMax(actor->colRangeMax());
        this->setMin(actor->colRangeMin());
    }
}

void axlInspectorObjectSceneWidgetFieldScalarCol::onResetMinimalValueClicked(void)
{
    this->setMin(d->field->minValue());
}

void axlInspectorObjectSceneWidgetFieldScalarCol::onResetMaximalValueClicked(void)
{
    this->setMax(d->field->maxValue());
}
