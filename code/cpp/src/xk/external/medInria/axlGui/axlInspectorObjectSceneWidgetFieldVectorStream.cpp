/* axlInspectorObjectSceneWidgetFieldVectorStream.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Dec 21 14:14:53 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Sep  9 15:35:25 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 107
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectSceneWidgetFieldVectorStream.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtGui>

class axlInspectorObjectSceneWidgetFieldVectorStreamPrivate
{
public:
    QDoubleSpinBox *stream_radius_spin;
    QDoubleSpinBox *stream_propagati_spin;
    QComboBox *stream_direction_comb;
};

axlInspectorObjectSceneWidgetFieldVectorStream::axlInspectorObjectSceneWidgetFieldVectorStream(QWidget *parent) : QWidget(parent), d(new axlInspectorObjectSceneWidgetFieldVectorStreamPrivate)
{
    QWidget *stream_form = new QWidget(this);
    stream_form->setObjectName("axlInspectorObjectSceneWidgetFieldVectorStreamForm");

    d->stream_propagati_spin = new QDoubleSpinBox(this);
    d->stream_propagati_spin->setValue(100);
    d->stream_propagati_spin->setMinimum(0);
    d->stream_propagati_spin->setMaximum(100000);
    d->stream_propagati_spin->setSingleStep(1);

    d->stream_radius_spin = new QDoubleSpinBox(this);
    d->stream_radius_spin->setValue(0.001);
    d->stream_radius_spin->setMinimum(0);
    d->stream_radius_spin->setMaximum(100000);
    d->stream_radius_spin->setSingleStep(0.001);
    d->stream_radius_spin->setDecimals(3);

    d->stream_direction_comb = new QComboBox(this);
    d->stream_direction_comb->addItem("Forward");
    d->stream_direction_comb->addItem("Backward");
    d->stream_direction_comb->addItem("Both");
    d->stream_direction_comb->setCurrentIndex(2);

    QFormLayout *stream_form_layout = new QFormLayout(stream_form);
    stream_form_layout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    stream_form_layout->addRow("Radius", d->stream_radius_spin);
    stream_form_layout->addRow("Propagation", d->stream_propagati_spin);
    stream_form_layout->addRow("Direction", d->stream_direction_comb);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(new QLabel("Stream", this));
    layout->addWidget(stream_form);


    connect(d->stream_radius_spin, SIGNAL(valueChanged(double)), this, SIGNAL(streamRadiusValueChanged(double)));
    connect(d->stream_propagati_spin, SIGNAL(valueChanged(double)), this, SIGNAL(streamPropagationValueChanged(double)));
    connect(d->stream_direction_comb, SIGNAL(currentIndexChanged(int)), this, SIGNAL(streamDirectionValueChanged(int)));
}

axlInspectorObjectSceneWidgetFieldVectorStream::~axlInspectorObjectSceneWidgetFieldVectorStream(void)
{
    delete d;

    d = NULL;
}
