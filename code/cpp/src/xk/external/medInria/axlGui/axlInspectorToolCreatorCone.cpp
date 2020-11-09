/* axlInspectorToolCreatorCone.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Wed Mar 16 17:19:51 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 16 17:38:31 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 31
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorToolCreatorCone.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlCone.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <axlCore/axlConeCreator.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <QtGui>

class axlInspectorToolCreatorConePrivate
{
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QDoubleSpinBox *spinBoxCoordinateApex_x;
    QDoubleSpinBox *spinBoxCoordinateApex_y;
    QDoubleSpinBox *spinBoxCoordinateApex_z;

    QDoubleSpinBox *spinBoxCoordinateBasePoint_x;
    QDoubleSpinBox *spinBoxCoordinateBasePoint_y;
    QDoubleSpinBox *spinBoxCoordinateBasePoint_z;

    QDoubleSpinBox *spinBoxRadius;

    QGroupBox *coordinates;

    QLabel *messageToDisplay;

};

axlInspectorToolCreatorCone::axlInspectorToolCreatorCone(QWidget *parent) : axlInspectorToolCreator(parent), d(new axlInspectorToolCreatorConePrivate)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

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

    //    QHBoxLayout *layoutDynamic = new QHBoxLayout();
    //    QLabel *labelDynamic = new QLabel("dynamic Object",this);
    //    d->checkBoxIsDynamic = new QCheckBox(this);


    QVBoxLayout *layoutCoordonate = new QVBoxLayout();
    QHBoxLayout *layoutCoordinateApex_x = new QHBoxLayout();
    QHBoxLayout *layoutCoordinateApex_y = new QHBoxLayout();
    QHBoxLayout *layoutCoordinateApex_z = new QHBoxLayout();
    QLabel *labelCoordinateApex_x = new QLabel("x",this);
    QLabel *labelCoordinateApex_y = new QLabel("y",this);
    QLabel *labelCoordinateApex_z = new QLabel("z",this);
    d->spinBoxCoordinateApex_x = new QDoubleSpinBox(this);
    d->spinBoxCoordinateApex_y = new QDoubleSpinBox(this);
    d->spinBoxCoordinateApex_z = new QDoubleSpinBox(this);

    QHBoxLayout *layoutCoordinateBasePoint_x = new QHBoxLayout();
    QHBoxLayout *layoutCoordinateBasePoint_y = new QHBoxLayout();
    QHBoxLayout *layoutCoordinateBasePoint_z = new QHBoxLayout();
    QLabel *labelCoordinateBasePoint_x = new QLabel("x",this);
    QLabel *labelCoordinateBasePoint_y = new QLabel("y",this);
    QLabel *labelCoordinateBasePoint_z = new QLabel("z",this);
    d->spinBoxCoordinateBasePoint_x = new QDoubleSpinBox(this);
    d->spinBoxCoordinateBasePoint_y = new QDoubleSpinBox(this);
    d->spinBoxCoordinateBasePoint_z = new QDoubleSpinBox(this);

    QHBoxLayout *layoutRadius = new QHBoxLayout();
    QLabel *labelRadius = new QLabel("radius :",this);
    d->spinBoxRadius = new QDoubleSpinBox(this);

    d->spinBoxCoordinateApex_x->setValue(0.0);
    d->spinBoxCoordinateApex_y->setValue(0.0);
    d->spinBoxCoordinateApex_z->setValue(0.0);
    d->spinBoxCoordinateApex_x->setRange(-1000, 1000);
    d->spinBoxCoordinateApex_y->setRange(-1000, 1000);
    d->spinBoxCoordinateApex_z->setRange(-1000, 1000);
    layoutCoordinateApex_x->addWidget(labelCoordinateApex_x);
    layoutCoordinateApex_x->addWidget(d->spinBoxCoordinateApex_x);
    layoutCoordinateApex_y->addWidget(labelCoordinateApex_y);
    layoutCoordinateApex_y->addWidget(d->spinBoxCoordinateApex_y);
    layoutCoordinateApex_z->addWidget(labelCoordinateApex_z);
    layoutCoordinateApex_z->addWidget(d->spinBoxCoordinateApex_z);
    layoutCoordonate->addWidget(new QLabel("Apex point :", this));
    layoutCoordonate->addLayout(layoutCoordinateApex_x);
    layoutCoordonate->addLayout(layoutCoordinateApex_y);
    layoutCoordonate->addLayout(layoutCoordinateApex_z);

    d->spinBoxCoordinateBasePoint_x->setValue(1.0);
    d->spinBoxCoordinateBasePoint_y->setValue(0.0);
    d->spinBoxCoordinateBasePoint_z->setValue(0.0);
    d->spinBoxCoordinateBasePoint_x->setRange(-1000, 1000);
    d->spinBoxCoordinateBasePoint_y->setRange(-1000, 1000);
    d->spinBoxCoordinateBasePoint_z->setRange(-1000, 1000);
    layoutCoordinateBasePoint_x->addWidget(labelCoordinateBasePoint_x);
    layoutCoordinateBasePoint_x->addWidget(d->spinBoxCoordinateBasePoint_x);
    layoutCoordinateBasePoint_y->addWidget(labelCoordinateBasePoint_y);
    layoutCoordinateBasePoint_y->addWidget(d->spinBoxCoordinateBasePoint_y);
    layoutCoordinateBasePoint_z->addWidget(labelCoordinateBasePoint_z);
    layoutCoordinateBasePoint_z->addWidget(d->spinBoxCoordinateBasePoint_z);
    layoutCoordonate->addWidget(new QLabel("BasePoint point :", this));
    layoutCoordonate->addLayout(layoutCoordinateBasePoint_x);
    layoutCoordonate->addLayout(layoutCoordinateBasePoint_y);
    layoutCoordonate->addLayout(layoutCoordinateBasePoint_z);

    layoutRadius->addWidget(labelRadius);
    layoutRadius->addWidget(d->spinBoxRadius);
    d->spinBoxRadius->setValue(1.0);

    d->spinBoxCoordinateApex_x->setSingleStep(0.1);
    d->spinBoxCoordinateApex_y->setSingleStep(0.1);
    d->spinBoxCoordinateApex_z->setSingleStep(0.1);
    d->spinBoxCoordinateBasePoint_x->setSingleStep(0.1);
    d->spinBoxCoordinateBasePoint_y->setSingleStep(0.1);
    d->spinBoxCoordinateBasePoint_z->setSingleStep(0.1);
    d->spinBoxRadius->setSingleStep(0.1);

    d->coordinates = new QGroupBox(tr("Enter coordinates"),this);
    d->coordinates->setLayout(layoutCoordonate);

    //message to display
    d->messageToDisplay = new QLabel("",this);
    axlConeCreator *creator = new axlConeCreator();
    d->messageToDisplay->setText(creator->description());
    delete creator;
    d->messageToDisplay->setStyleSheet("color: #ff0000;");

    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    layout->addWidget(new QLabel("axlInspectorToolCreatorCone", this));
    //    layout->addLayout(layoutCoordonate);
    layout->addWidget(d->messageToDisplay);
    layout->addWidget(d->coordinates);
    layout->addLayout(layoutRadius);
    layout->addLayout(layoutOpacity);
    layout->addLayout(layoutColorButton);
    layout->addWidget(button);
    d->coordinates->hide();
}

axlInspectorToolCreatorCone::~axlInspectorToolCreatorCone(void)
{
    delete d;

    d = NULL;
}

void axlInspectorToolCreatorCone::setController(axlInspectorObjectController *controller)
{
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
            d->coordinates->show();
            d->messageToDisplay->hide();
        }
    }
}

QList<axlAbstractData *> axlInspectorToolCreatorCone::returnInputsList(void){
    QList<axlAbstractData *>list;
    if(d->coordinates->isVisible()){
        axlPoint *Apex = new axlPoint(d->spinBoxCoordinateApex_x->value(), d->spinBoxCoordinateApex_y->value(), d->spinBoxCoordinateApex_z->value());
        axlPoint *basePoint = new axlPoint(d->spinBoxCoordinateBasePoint_x->value(), d->spinBoxCoordinateBasePoint_y->value(), d->spinBoxCoordinateBasePoint_z->value());

        axlDouble *radius =new axlDouble(d->spinBoxRadius->value());

        list << Apex << basePoint << radius;
    }
    return list;

}

void axlInspectorToolCreatorCone::run(void)
{


    if(/*d->firstRun &&*/ !d->coordinates->isVisible()){
        axlConeCreator *creator = new axlConeCreator();
        d->messageToDisplay->show();
        int nbPoints = 0;
        if( d->controller->size()>0 ){
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
            creator->setParameter(d->spinBoxRadius->value());
            creator->update();
            axlCone *cone = dynamic_cast<axlCone *>(creator->output());
            cone->setColor(d->colorButton->color());
            double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
            cone->setOpacity(opacity);
            emit dataInserted(cone);
            d->coordinates->hide();

        }else {
            //display the coordinates to be chosen for the extremal points
            d->coordinates->show();
            d->messageToDisplay->hide();
        }

        delete creator;
    }else{
        // WARNING THESE POINT ARE ONLY REFERENCED BY THE CONE : risk of memory leek when the cone will be deleted
        d->messageToDisplay->hide();
        axlPoint *Apex = new axlPoint(d->spinBoxCoordinateApex_x->value(), d->spinBoxCoordinateApex_y->value(), d->spinBoxCoordinateApex_z->value());
        axlPoint *basePoint = new axlPoint(d->spinBoxCoordinateBasePoint_x->value(), d->spinBoxCoordinateBasePoint_y->value(), d->spinBoxCoordinateBasePoint_z->value());

        axlCone* cone = new axlCone(Apex, basePoint, d->spinBoxRadius->value());
        cone->setColor(d->colorButton->color());
        double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
        cone->setOpacity(opacity);
        emit dataInserted(cone);

    }


}

axlInspectorToolInterface *createaxlInspectorToolCreatorCone(void)
{
    return new axlInspectorToolCreatorCone;
}
