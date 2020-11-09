/* axlInspectorObjectSceneWidgetField.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Jul 30 21:28:55 2010 (+0200)
 * Version: $Id$
 * Last-Updated: Fri Sep  9 15:43:52 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 265
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectSceneWidgetField.h"
#include "axlInspectorObjectSceneWidgetFieldScalar.h"
#include "axlInspectorObjectSceneWidgetFieldVector.h"
#include "axlInspectorObjectSceneWidgetFieldTensor.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractActorField.h>
#include <axlCore/axlAbstractView.h>

#include <QtGui>

class axlInspectorObjectSceneWidgetFieldPrivate
{
public:
    axlAbstractField *field;
    axlAbstractActorField *actorField;
    axlAbstractView *view;

    QLineEdit *stats_type_edit;
    QLineEdit *stats_kind_edit;
    QLineEdit *stats_supp_edit;

    QVBoxLayout *layout;

    axlInspectorObjectSceneWidgetFieldScalar *widgetFieldScalar;
    axlInspectorObjectSceneWidgetFieldVector *widgetFieldVector;
    axlInspectorObjectSceneWidgetFieldTensor *widgetFieldTensor;
};

axlInspectorObjectSceneWidgetField::axlInspectorObjectSceneWidgetField(QWidget *parent) : QFrame(parent), d(new axlInspectorObjectSceneWidgetFieldPrivate)
{
    d->field = NULL;
    d->actorField = NULL;
    d->view = NULL;

    d->widgetFieldScalar = NULL;
    d->widgetFieldVector = NULL;
    d->widgetFieldTensor = NULL;

    d->stats_type_edit = new QLineEdit(this);
    d->stats_type_edit->setReadOnly(true);

    d->stats_kind_edit = new QLineEdit(this);
    d->stats_kind_edit->setReadOnly(true);

    d->stats_supp_edit = new QLineEdit(this);
    d->stats_supp_edit->setReadOnly(true);

    QWidget *stats_widget = new QWidget(this);
    stats_widget->setObjectName("axlInspectorObjectSceneWidgetFieldStatsForm");

    QHBoxLayout *stats_layout = new QHBoxLayout(stats_widget);
    //stats_layout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    stats_layout->addWidget(d->stats_type_edit);
    stats_layout->addWidget (d->stats_kind_edit);
    stats_layout->addWidget (d->stats_supp_edit);



    d->layout = new QVBoxLayout(this);
    d->layout->addWidget(new QLabel("Field", this));
    d->layout->addWidget(stats_widget);

}

axlInspectorObjectSceneWidgetField::~axlInspectorObjectSceneWidgetField(void)
{

    delete d;

    d = NULL;
}

void axlInspectorObjectSceneWidgetField::setField(axlAbstractField *field)
{
    d->field = field;

    switch (d->field->type()) {
    case axlAbstractField::Int:
        d->stats_type_edit->setText("Integer");
        break;
    case axlAbstractField::Float:
        d->stats_type_edit->setText("Float");
        break;
    case axlAbstractField::Double:
        d->stats_type_edit->setText("Double");
        break;
    }

    switch (d->field->kind()) {
    case axlAbstractField::Scalar:
        d->stats_kind_edit->setText("Scalar");
        break;
    case axlAbstractField::Vector:
        d->stats_kind_edit->setText("Vector");
        break;
    case axlAbstractField::Tensor:
        d->stats_kind_edit->setText("Tensor");
        break;
    }

    switch (d->field->support()) {
    case axlAbstractField::Point:
        d->stats_supp_edit->setText("Point");
        break;
    case axlAbstractField::Cell:
        d->stats_supp_edit->setText("Cell");
        break;
    case axlAbstractField::Custom:
        d->stats_supp_edit->setText("Custom");
        break;
    }

    // We Want to have only one widget
    if(d->widgetFieldScalar)
    {
        disconnect(d->widgetFieldScalar, SIGNAL(displayAsColor()), this, SLOT(onDisplayAsColor()));
        disconnect(d->widgetFieldScalar, SIGNAL(displayAsIso()), this, SLOT(onDisplayAsIso()));
        disconnect(d->widgetFieldScalar, SIGNAL(displayAsNone()), this, SLOT(onDisplayAsNoneScalar()));

        disconnect(d->widgetFieldScalar, SIGNAL(colRangeMinChanged(double)), this, SLOT(onColRangeMinChanged(double)));
        disconnect(d->widgetFieldScalar, SIGNAL(colRangeMaxChanged(double)), this, SLOT(onColRangeMaxChanged(double)));

        disconnect(d->widgetFieldScalar, SIGNAL(isoCountChanged(int)), this, SLOT(onIsoCountChanged(int)));
        disconnect(d->widgetFieldScalar, SIGNAL(isoRadiusChanged(double)), this, SLOT(onIsoRadiusChanged(double)));

        disconnect(d->widgetFieldScalar, SIGNAL(isoRangeMinChanged(double)), this, SLOT(onIsoRangeMinChanged(double)));
        disconnect(d->widgetFieldScalar, SIGNAL(isoRangeMaxChanged(double)), this, SLOT(onIsoRangeMaxChanged(double)));

        d->layout->removeWidget(d->widgetFieldScalar);

        delete d->widgetFieldScalar;
        d->widgetFieldScalar = NULL;
    }

    if(d->widgetFieldVector)
    {
        disconnect(d->widgetFieldVector, SIGNAL(displayAsHedge()), this, SLOT(onDisplayAsHedge()));
        disconnect(d->widgetFieldVector, SIGNAL(displayAsGlyph()), this, SLOT(onDisplayAsGlyph()));
        disconnect(d->widgetFieldVector, SIGNAL(displayAsStream()), this, SLOT(onDisplayAsStream()));
        disconnect(d->widgetFieldVector, SIGNAL(displayAsNone()), this, SLOT(onDisplayAsNoneVector()));


        disconnect(d->widgetFieldVector, SIGNAL(glyphScaleValueChanged(double)), this, SLOT(onGlyphScaleValueChanged(double)));

        disconnect(d->widgetFieldVector, SIGNAL(streamRadiusValueChanged(double)), this, SLOT(onStreamRadiusValueChanged(double)));
        disconnect(d->widgetFieldVector, SIGNAL(streamPropagationValueChanged(double)), this, SLOT(onStreamPropagationValueChanged(double)));
        disconnect(d->widgetFieldVector, SIGNAL(streamDirectionValueChanged(int)), this, SLOT(onStreamDirectionValueChanged(int)));

        d->layout->removeWidget(d->widgetFieldVector);
        delete d->widgetFieldVector;
        d->widgetFieldVector = NULL;
    }

    if(d->widgetFieldTensor)
    {
        d->layout->removeWidget(d->widgetFieldTensor);

        delete d->widgetFieldTensor;
        d->widgetFieldTensor = NULL;
    }

    if (d->field->kind() == axlAbstractField::Scalar) {


        d->widgetFieldScalar = new axlInspectorObjectSceneWidgetFieldScalar(this);
        d->widgetFieldScalar->setField(d->field);
        d->widgetFieldScalar->setView(d->view);
        //d->widgetFieldScalar->setDefaultDisplay();

        d->layout->addWidget(d->widgetFieldScalar);
        d->layout->addStretch(1);

        connect(d->widgetFieldScalar, SIGNAL(displayAsColor()), this, SLOT(onDisplayAsColor()));
        connect(d->widgetFieldScalar, SIGNAL(displayAsIso()), this, SLOT(onDisplayAsIso()));
        connect(d->widgetFieldScalar, SIGNAL(displayAsNone()), this, SLOT(onDisplayAsNoneScalar()));


        connect(d->widgetFieldScalar, SIGNAL(colRangeMinChanged(double)), this, SLOT(onColRangeMinChanged(double)));
        connect(d->widgetFieldScalar, SIGNAL(colRangeMaxChanged(double)), this, SLOT(onColRangeMaxChanged(double)));

        connect(d->widgetFieldScalar, SIGNAL(isoCountChanged(int)), this, SLOT(onIsoCountChanged(int)));
        connect(d->widgetFieldScalar, SIGNAL(isoRadiusChanged(double)), this, SLOT(onIsoRadiusChanged(double)));
        connect(d->widgetFieldScalar, SIGNAL(isoRangeMinChanged(double)), this, SLOT(onIsoRangeMinChanged(double)));
        connect(d->widgetFieldScalar, SIGNAL(isoRangeMaxChanged(double)), this, SLOT(onIsoRangeMaxChanged(double)));

    }

    if (d->field->kind() == axlAbstractField::Vector){

        d->widgetFieldVector = new axlInspectorObjectSceneWidgetFieldVector(this);
        d->widgetFieldVector->setField(d->field);
        d->widgetFieldVector->setView(d->view);

        d->layout->addWidget(d->widgetFieldVector);
        d->layout->addStretch(1);

        connect(d->widgetFieldVector, SIGNAL(displayAsHedge()), this, SLOT(onDisplayAsHedge()));
        connect(d->widgetFieldVector, SIGNAL(displayAsGlyph()), this, SLOT(onDisplayAsGlyph()));
        connect(d->widgetFieldVector, SIGNAL(displayAsStream()), this, SLOT(onDisplayAsStream()));
        connect(d->widgetFieldVector, SIGNAL(displayAsNone()), this, SLOT(onDisplayAsNoneVector()));

        connect(d->widgetFieldVector, SIGNAL(glyphScaleValueChanged(double)), this, SLOT(onGlyphScaleValueChanged(double)));

        connect(d->widgetFieldVector, SIGNAL(streamRadiusValueChanged(double)), this, SLOT(onStreamRadiusValueChanged(double)));
        connect(d->widgetFieldVector, SIGNAL(streamPropagationValueChanged(double)), this, SLOT(onStreamPropagationValueChanged(double)));
        connect(d->widgetFieldVector, SIGNAL(streamDirectionValueChanged(int)), this, SLOT(onStreamDirectionValueChanged(int)));
    }

    if (d->field->kind() == axlAbstractField::Tensor) {

        d->widgetFieldTensor = new axlInspectorObjectSceneWidgetFieldTensor(this);
        d->widgetFieldTensor->setField(d->field);

        d->layout->addWidget(d->widgetFieldTensor);
        d->layout->addStretch(1);
    }
}

void axlInspectorObjectSceneWidgetField::setActorField(axlAbstractActorField *actorField)
{
    d->actorField = actorField;
}

void axlInspectorObjectSceneWidgetField::setView(axlAbstractView *view)
{
    d->view = view;
}

void axlInspectorObjectSceneWidgetField::onDisplayAsNoneScalar(void)
{
    if(!d->view)
        return;


    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->displayAsNoneScalar();


    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onDisplayAsColor(void)
{
    if(!d->view)
        return;


    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->displayAsColor();


    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onDisplayAsIso(void)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->displayAsIso();

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onDisplayAsNoneVector(void)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->displayAsNoneVector();

    d->view->update();
}


void axlInspectorObjectSceneWidgetField::onDisplayAsHedge(void)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->displayAsHedge();

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onDisplayAsGlyph(void)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->displayAsGlyph();

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onDisplayAsStream(void)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->displayAsStream();

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onIsoCountChanged(int count)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->setIsoCount(count);

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onIsoRadiusChanged(double radius)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->onIsoRadiusChanged(radius);

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onColRangeMinChanged(double min)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->setColRangeMin(min);

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onColRangeMaxChanged(double max)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->setColRangeMax(max);

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onIsoRangeMinChanged(double min)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->setIsoRangeMin(min);

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onIsoRangeMaxChanged(double max)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->setIsoRangeMax(max);

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onGlyphScaleValueChanged(double scale)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->setGlyphScale(scale);

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onStreamRadiusValueChanged(double radius)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->setStreamRadius(radius);

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onStreamPropagationValueChanged(double propagation)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->setStreamPropagation(propagation);

    d->view->update();
}

void axlInspectorObjectSceneWidgetField::onStreamDirectionValueChanged(int direction)
{
    if(!d->view)
        return;

    if(axlAbstractActorField *actor = dynamic_cast<axlAbstractActorField *>(d->view->actor(d->field)))
        actor->setStreamDirection(direction);

    d->view->update();
}
