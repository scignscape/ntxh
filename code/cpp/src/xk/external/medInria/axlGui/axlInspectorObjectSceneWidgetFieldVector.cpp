/* axlInspectorObjectSceneWidgetFieldVector.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Dec 17 22:48:33 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Sep  9 15:41:42 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 132
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectSceneWidgetFieldVector.h"
#include "axlInspectorObjectSceneWidgetFieldVectorGlyph.h"
#include "axlInspectorObjectSceneWidgetFieldVectorStream.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractView.h>

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtGui>

class axlInspectorObjectSceneWidgetFieldVectorPrivate
{
public:
    axlAbstractField *field;
    axlInspectorObjectSceneWidgetFieldVectorGlyph *glyph;
    axlInspectorObjectSceneWidgetFieldVectorStream *stream;
    axlAbstractView *view;

public:
    QPushButton *disp_none_button;
    QPushButton *disp_hedge_button;
    QPushButton *disp_glyph_button;
    QPushButton *disp_strea_button;

    QVBoxLayout *layout;
};

axlInspectorObjectSceneWidgetFieldVector::axlInspectorObjectSceneWidgetFieldVector(QWidget *parent) : QWidget(parent), d(new axlInspectorObjectSceneWidgetFieldVectorPrivate)
{
    d->field = NULL;
    d->glyph = NULL;
    d->stream = NULL;
    d->view = NULL;

    d->disp_none_button = new QPushButton("Nothing");
    d->disp_none_button->setCheckable(true);
    d->disp_none_button->setChecked(false);
    d->disp_none_button->setObjectName("overLeft");

    d->disp_hedge_button = new QPushButton("Hedgehog");
    d->disp_hedge_button->setCheckable(true);
    d->disp_hedge_button->setChecked(false);
    d->disp_hedge_button->setObjectName("left");

    d->disp_glyph_button = new QPushButton("Glyphs");
    d->disp_glyph_button->setCheckable(true);
    d->disp_glyph_button->setChecked(false);
    d->disp_glyph_button->setObjectName("middle");

    d->disp_strea_button = new QPushButton("Stream");
    d->disp_strea_button->setCheckable(true);
    d->disp_strea_button->setChecked(false);
    d->disp_strea_button->setObjectName("right");

    QButtonGroup *disp_group = new QButtonGroup(this);
    disp_group->addButton(d->disp_none_button);
    disp_group->addButton(d->disp_hedge_button);
    disp_group->addButton(d->disp_glyph_button);
    disp_group->addButton(d->disp_strea_button);

    QHBoxLayout *disp_layout = new QHBoxLayout;
    disp_layout->setContentsMargins(0, 0, 0, 0);
    disp_layout->setSpacing(0);
    disp_layout->addWidget(d->disp_none_button);
    disp_layout->addSpacerItem(new QSpacerItem(10, 1));
    disp_layout->addWidget(d->disp_hedge_button);
    disp_layout->addSpacerItem(new QSpacerItem(10, 1));
    disp_layout->addWidget(d->disp_glyph_button);
    disp_layout->addSpacerItem(new QSpacerItem(10, 1));
    disp_layout->addWidget(d->disp_strea_button);

    d->layout = new QVBoxLayout(this);
    d->layout->setContentsMargins(0, 0, 0, 0);
    d->layout->addWidget(new QLabel("Display", this));
    d->layout->addLayout(disp_layout);

    connect(d->disp_none_button, SIGNAL(clicked()), this, SLOT(onDisplayAsNone()));
    connect(d->disp_hedge_button, SIGNAL(clicked()), this, SLOT(onDisplayAsHedge()));
    connect(d->disp_glyph_button, SIGNAL(clicked()), this, SLOT(onDisplayAsGlyph()));
    connect(d->disp_strea_button, SIGNAL(clicked()), this, SLOT(onDisplayAsStream()));

}

axlInspectorObjectSceneWidgetFieldVector::~axlInspectorObjectSceneWidgetFieldVector(void)
{
    delete d;

    d = NULL;
}

void axlInspectorObjectSceneWidgetFieldVector::setField(axlAbstractField *field)
{
    d->field = field;
}

void axlInspectorObjectSceneWidgetFieldVector::setView(axlAbstractView *view)
{
    d->view = view;
}

void axlInspectorObjectSceneWidgetFieldVector::onDisplayAsNone(void)
{
    if (d->glyph) {
        d->layout->removeWidget(d->glyph);
        delete d->glyph;
        d->glyph = NULL;
    }

    if (d->stream) {
        d->layout->removeWidget(d->stream);
        delete d->stream;
        d->stream = NULL;
    }

    emit displayAsNone();
}

void axlInspectorObjectSceneWidgetFieldVector::onDisplayAsHedge(void)
{
    if (d->glyph) {
        d->layout->removeWidget(d->glyph);
        delete d->glyph;
        d->glyph = NULL;
    }

    if (d->stream) {
        d->layout->removeWidget(d->stream);
        delete d->stream;
        d->stream = NULL;
    }

    emit displayAsHedge();
}

void axlInspectorObjectSceneWidgetFieldVector::onDisplayAsGlyph(void)
{
    if (d->glyph) {
        d->layout->removeWidget(d->glyph);
        delete d->glyph;
        d->glyph = NULL;
    }

    if (d->stream) {
        d->layout->removeWidget(d->stream);
        delete d->stream;
        d->stream = NULL;
    }

    d->glyph = new axlInspectorObjectSceneWidgetFieldVectorGlyph(this);

    connect(d->glyph, SIGNAL(glyphScaleValueChanged(double)), this, SIGNAL(glyphScaleValueChanged(double)));

    d->layout->addWidget(d->glyph);

    emit displayAsGlyph();
}

void axlInspectorObjectSceneWidgetFieldVector::onDisplayAsStream(void)
{
    if (d->glyph) {
        d->layout->removeWidget(d->glyph);
        delete d->glyph;
        d->glyph = NULL;
    }

    if (d->stream) {
        d->layout->removeWidget(d->stream);
        delete d->stream;
        d->stream = NULL;
    }

    d->stream = new axlInspectorObjectSceneWidgetFieldVectorStream(this);

    connect(d->stream, SIGNAL(streamRadiusValueChanged(double)), this, SIGNAL(streamRadiusValueChanged(double)));
    connect(d->stream, SIGNAL(streamPropagationValueChanged(double)), this, SIGNAL(streamPropagationValueChanged(double)));
    connect(d->stream, SIGNAL(streamDirectionValueChanged(int)), this, SIGNAL(streamDirectionValueChanged(int)));

    d->layout->addWidget(d->stream);

    emit displayAsStream();
}
