/* axlInspectorToolCreatorTorus.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008 - Valentin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Valentin Michelet
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorToolCreatorTorus.h"

#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlTorus.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <axlCore/axlDouble.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlTorusCreator.h>

#include <QtGui>

class axlInspectorToolCreatorTorusPrivate {
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QDoubleSpinBox* coordinateCenter_x;
    QDoubleSpinBox* coordinateCenter_y;
    QDoubleSpinBox* coordinateCenter_z;

    QDoubleSpinBox* coordinateDirection_x;
    QDoubleSpinBox* coordinateDirection_y;
    QDoubleSpinBox* coordinateDirection_z;

    QDoubleSpinBox* ringRadius;

    QDoubleSpinBox* crossSectionRadius;

    QGroupBox *coordinates;
    QLabel *messageToDisplay;

};

axlInspectorToolCreatorTorus::axlInspectorToolCreatorTorus(QWidget *parent) :
    axlInspectorToolCreator(parent), d(new axlInspectorToolCreatorTorusPrivate) {

    //OPACITY//
    d->sliderOpacity = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *layoutOpacity = new QHBoxLayout;
    layoutOpacity->addWidget(new QLabel("Opacity",this));
    layoutOpacity->addWidget(d->sliderOpacity);
    d->sliderOpacity->setMaximum(100);

    //COLOR//
    d->colorButton = new dtkColorButton(this);

    QHBoxLayout *layoutColorButton = new QHBoxLayout;
    layoutColorButton->addWidget(new QLabel("Color",this));
    layoutColorButton->addWidget(d->colorButton);
    d->colorButton->setColor(QColor("#a0a0a4"));

    //CENTER//
    d->coordinateCenter_x = new QDoubleSpinBox(this);
    d->coordinateCenter_x->setValue(0.0);
    d->coordinateCenter_x->setRange(-1000, 1000);
    d->coordinateCenter_x->setSingleStep(0.1);
    d->coordinateCenter_y = new QDoubleSpinBox(this);
    d->coordinateCenter_y->setValue(0.0);
    d->coordinateCenter_y->setRange(-1000, 1000);
    d->coordinateCenter_y->setSingleStep(0.1);
    d->coordinateCenter_z = new QDoubleSpinBox(this);
    d->coordinateCenter_z->setValue(0.0);
    d->coordinateCenter_z->setRange(-1000, 1000);
    d->coordinateCenter_z->setSingleStep(0.1);

    QVBoxLayout *layoutCenter = new QVBoxLayout;

    QHBoxLayout *layoutCenter_x = new QHBoxLayout;
    QLabel *labelCenter_x = new QLabel("x",this);
    QHBoxLayout *layoutCenter_y = new QHBoxLayout;
    QLabel *labelCenter_y = new QLabel("y",this);
    QHBoxLayout *layoutCenter_z = new QHBoxLayout;
    QLabel *labelCenter_z = new QLabel("z",this);

    layoutCenter_x->addWidget(labelCenter_x);
    layoutCenter_x->addWidget(d->coordinateCenter_x);
    layoutCenter_y->addWidget(labelCenter_y);
    layoutCenter_y->addWidget(d->coordinateCenter_y);
    layoutCenter_z->addWidget(labelCenter_z);
    layoutCenter_z->addWidget(d->coordinateCenter_z);

    layoutCenter->addWidget(new QLabel("Center:", this));
    layoutCenter->addLayout(layoutCenter_x);
    layoutCenter->addLayout(layoutCenter_y);
    layoutCenter->addLayout(layoutCenter_z);

    //DIRECTION//
    d->coordinateDirection_x = new QDoubleSpinBox(this);
    d->coordinateDirection_x->setValue(0.0);
    d->coordinateDirection_x->setRange(-1000, 1000);
    d->coordinateDirection_x->setSingleStep(0.1);
    d->coordinateDirection_y = new QDoubleSpinBox(this);
    d->coordinateDirection_y->setValue(0.0);
    d->coordinateDirection_y->setRange(-1000, 1000);
    d->coordinateDirection_y->setSingleStep(0.1);
    d->coordinateDirection_z = new QDoubleSpinBox(this);
    d->coordinateDirection_z->setValue(1.0);
    d->coordinateDirection_z->setRange(-1000, 1000);
    d->coordinateDirection_z->setSingleStep(0.1);

    QVBoxLayout *layoutDirection = new QVBoxLayout;

    QHBoxLayout *layoutDirection_x = new QHBoxLayout;
    QLabel *labelDirection_x = new QLabel("x",this);
    QHBoxLayout *layoutDirection_y = new QHBoxLayout;
    QLabel *labelDirection_y = new QLabel("y",this);
    QHBoxLayout *layoutDirection_z = new QHBoxLayout;
    QLabel *labelDirection_z = new QLabel("z",this);

    layoutDirection_x->addWidget(labelDirection_x);
    layoutDirection_x->addWidget(d->coordinateDirection_x);
    layoutDirection_y->addWidget(labelDirection_y);
    layoutDirection_y->addWidget(d->coordinateDirection_y);
    layoutDirection_z->addWidget(labelDirection_z);
    layoutDirection_z->addWidget(d->coordinateDirection_z);

    layoutDirection->addWidget(new QLabel("Second point to create direction:", this));
    layoutDirection->addLayout(layoutDirection_x);
    layoutDirection->addLayout(layoutDirection_y);
    layoutDirection->addLayout(layoutDirection_z);

    //RING RADIUS//
    d->ringRadius = new QDoubleSpinBox(this);
    d->ringRadius->setValue(1.0);
    d->ringRadius->setSingleStep(0.1);

    QHBoxLayout *layoutRingRadius = new QHBoxLayout;
    QLabel *labelRingRadius = new QLabel("Ring Radius:",this);

    layoutRingRadius->addWidget(labelRingRadius);
    layoutRingRadius->addWidget(d->ringRadius);

    //CROSS SECTION RADIUS//
    d->crossSectionRadius = new QDoubleSpinBox(this);
    d->crossSectionRadius->setValue(0.2);
    d->crossSectionRadius->setSingleStep(0.1);

    QHBoxLayout *layoutCrossSectionRadius = new QHBoxLayout;
    QLabel *labelCrossSectionRadius = new QLabel("Cross Section Radius:",this);

    layoutCrossSectionRadius->addWidget(labelCrossSectionRadius);
    layoutCrossSectionRadius->addWidget(d->crossSectionRadius);

    d->coordinates = new QGroupBox(tr("Enter coordinates"),this);
    QVBoxLayout *layoutCoordonate = new QVBoxLayout(this);
    layoutCoordonate->addLayout(layoutCenter);
    layoutCoordonate->addLayout(layoutDirection);
    d->coordinates->setLayout(layoutCoordonate);

    d->messageToDisplay = new QLabel("Select two points : the torus center  \n and the other one to determine its orientation", this);
    d->messageToDisplay->setStyleSheet("color: #ff0000;");


    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("axlInspectorToolCreatorTorus", this));
    //    layout->addLayout(layoutCenter);
    //    layout->addLayout(layoutDirection);
    layout->addWidget(d->messageToDisplay);
    layout->addWidget(d->coordinates);
    layout->addLayout(layoutRingRadius);
    layout->addLayout(layoutCrossSectionRadius);
    layout->addLayout(layoutOpacity);
    layout->addLayout(layoutColorButton);
    layout->addWidget(button);
    d->coordinates->hide();
    d->messageToDisplay->show();
}

axlInspectorToolCreatorTorus::~axlInspectorToolCreatorTorus(void) {
    delete d;
    d = NULL;
}

void axlInspectorToolCreatorTorus::setController(axlInspectorObjectController *controller) {
    d->controller = controller;
    if(d->controller->size() < 2){
        d->messageToDisplay->hide();
        d->coordinates->show();
    }else{
        d->coordinates->hide();
        bool hasRigthType = false;
        int nbRigthType = 0;
        foreach(axlInspectorObjectManagerTreeItem *item, d->controller->items()){
            if(dynamic_cast<axlPoint *>(d->controller->data(item)))
                nbRigthType++;
            else if(dynamic_cast<axlDataDynamic *>(d->controller->data(item)))
                if(dynamic_cast<axlDataDynamic *>(d->controller->data(item))->outputs())
                    if(dynamic_cast<axlPoint *>(dynamic_cast<axlDataDynamic *>(d->controller->data(item))->outputs()))
                        nbRigthType++;
        }

        if(nbRigthType > 1)
            hasRigthType = true;
        if(!hasRigthType){
            d->messageToDisplay->hide();
            d->coordinates->show();
        }
    }
}

QList<axlAbstractData *>  axlInspectorToolCreatorTorus::returnInputsList(void){
    QList<axlAbstractData *>list;
    if(d->coordinates->isVisible()){
        axlPoint *center = new axlPoint(d->coordinateCenter_x->value(), d->coordinateCenter_y->value(), d->coordinateCenter_z->value());
        axlPoint *direction = new axlPoint(d->coordinateDirection_x->value(), d->coordinateDirection_y->value(), d->coordinateDirection_z->value());

        //parameters
        axlDouble *ringRadius = new axlDouble(d->ringRadius->value());
        axlDouble *crossSectionRadius = new axlDouble(d->crossSectionRadius->value());

        list << center << direction << ringRadius << crossSectionRadius;
    }
    return list;

}

void axlInspectorToolCreatorTorus::run(void) {

    if(!d->coordinates->isVisible()){
        d->messageToDisplay->show();
        axlTorusCreator *creator = new axlTorusCreator();
        int nbPoints = 0;
        if(d->controller->size() > 0){
            foreach(axlInspectorObjectManagerTreeItem *item, d->controller->items()){

                if(item->text(2) == "Selected"|| item->text(2) == "Editable")
                {
                    if(nbPoints < 2){
                        if(dynamic_cast<axlPoint *>(d->controller->data(item))) {
                            axlPoint *point = dynamic_cast<axlPoint *>(d->controller->data(item));
                            creator->setInput(point,nbPoints);
                            nbPoints++;
                        }
                    }else{
                        qDebug() << "To many inputs selected, only the two first points were used";
                    }
                }

            }
        }

        if(nbPoints == 2){
            creator->setParameter(d->ringRadius->value(),0);
            creator->setParameter(d->crossSectionRadius->value(),1);
            creator->update();
            axlTorus *torus = dynamic_cast<axlTorus *>(creator->output());
            torus->setColor(d->colorButton->color());
            double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
            torus->setOpacity(opacity);
            emit dataInserted(torus);
            d->coordinates->hide();

        }else {
            //display the coordinates to be chosen for the extremal points
            d->messageToDisplay->hide();
            d->coordinates->show();
        }
        delete creator;
    }else{
        d->messageToDisplay->hide();
        axlPoint *center = new axlPoint(d->coordinateCenter_x->value(), d->coordinateCenter_y->value(), d->coordinateCenter_z->value());
        axlPoint *direction = new axlPoint(d->coordinateDirection_x->value(), d->coordinateDirection_y->value(), d->coordinateDirection_z->value());

        axlTorus* newTorus = new axlTorus(center, direction, d->ringRadius->value(), d->crossSectionRadius->value());

        newTorus->setColor(d->colorButton->color());
        double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
        newTorus->setOpacity(opacity);
        emit dataInserted(newTorus);
    }
}

axlInspectorToolInterface *createaxlInspectorToolCreatorTorus(void)
{
    return new axlInspectorToolCreatorTorus;
}
