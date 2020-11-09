/* axlInspectorObjectSceneWidgetFieldVectorGlyph.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Fri Sep  9 15:35:08 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Fri Sep  9 15:44:50 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 12
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectSceneWidgetFieldVectorGlyph.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtGui>

class axlInspectorObjectSceneWidgetFieldVectorGlyphPrivate
{
public:
    QDoubleSpinBox *glyph_scale_spin;
};

axlInspectorObjectSceneWidgetFieldVectorGlyph::axlInspectorObjectSceneWidgetFieldVectorGlyph(QWidget *parent) : QWidget(parent), d(new axlInspectorObjectSceneWidgetFieldVectorGlyphPrivate)
{
    QWidget *glyph_form = new QWidget(this);
    glyph_form->setObjectName("axlInspectorObjectSceneWidgetFieldVectorGlyphForm");

    d->glyph_scale_spin = new QDoubleSpinBox(this);
    d->glyph_scale_spin->setValue(0.1);
    d->glyph_scale_spin->setMinimum(0);
    d->glyph_scale_spin->setMaximum(100000);
    d->glyph_scale_spin->setSingleStep(0.01);
    d->glyph_scale_spin->setDecimals(5);

    QFormLayout *glyph_form_layout = new QFormLayout(glyph_form);
    glyph_form_layout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    glyph_form_layout->addRow("Scale", d->glyph_scale_spin);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(new QLabel("Glyph", this));
    layout->addWidget(glyph_form);


    connect(d->glyph_scale_spin, SIGNAL(valueChanged(double)), this, SIGNAL(glyphScaleValueChanged(double)));
}

axlInspectorObjectSceneWidgetFieldVectorGlyph::~axlInspectorObjectSceneWidgetFieldVectorGlyph(void)
{
    delete d;

    d = NULL;
}
