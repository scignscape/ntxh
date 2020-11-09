/* axlInspectorToolCreatorCircleArc.cpp ---
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

#include "axlInspectorToolCreatorCircleArc.h"

#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlCircleArc.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <QtGui>

class axlInspectorToolCreatorCircleArcPrivate {
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QDoubleSpinBox* coordinatePoint1_x;
    QDoubleSpinBox* coordinatePoint1_y;
    QDoubleSpinBox* coordinatePoint1_z;

    QDoubleSpinBox* coordinatePoint2_x;
    QDoubleSpinBox* coordinatePoint2_y;
    QDoubleSpinBox* coordinatePoint2_z;

    QDoubleSpinBox* coordinateCenter_x;
    QDoubleSpinBox* coordinateCenter_y;
    QDoubleSpinBox* coordinateCenter_z;

    QDoubleSpinBox* coordinateNormal_x;
    QDoubleSpinBox* coordinateNormal_y;
    QDoubleSpinBox* coordinateNormal_z;

    QLabel* coordinateNormalLabel_x;
    QLabel* coordinateNormalLabel_y;
    QLabel* coordinateNormalLabel_z;

    QCheckBox* counterClockWiseCheckBox;

    QLabel* radiusLabel;

    QLabel* linedUpMessage;
    QLabel* centerModifiedMessage;
};

axlInspectorToolCreatorCircleArc::axlInspectorToolCreatorCircleArc(QWidget *parent) :
    axlInspectorToolCreator(parent), d(new axlInspectorToolCreatorCircleArcPrivate) {

    //Lined up points message
    d->linedUpMessage = new QLabel("Point1, Point2 and Center are lined up.\nPlease provide the normal of the plane\ncontaining the circle arc.");
    d->linedUpMessage->setStyleSheet("color: #0000FF;");
    d->linedUpMessage->setVisible(false);

    //Center modified message
    d->centerModifiedMessage = new QLabel("Warning: your center has been modified\nto be on the mediatory of [Point1;Point2].");
    d->centerModifiedMessage->setStyleSheet("color: #FF6600;");
    d->centerModifiedMessage->setVisible(false);

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

    //POINT1//
    d->coordinatePoint1_x = new QDoubleSpinBox(this);
    d->coordinatePoint1_x->setRange(-1000, 1000);
    d->coordinatePoint1_x->setValue(1.0);
    d->coordinatePoint1_x->setSingleStep(0.1);

    QHBoxLayout *layoutPoint1_x = new QHBoxLayout;
    layoutPoint1_x->addWidget(new QLabel("X",this));
    layoutPoint1_x->addWidget(d->coordinatePoint1_x);

    d->coordinatePoint1_y = new QDoubleSpinBox(this);
    d->coordinatePoint1_y->setRange(-1000, 1000);
    d->coordinatePoint1_y->setValue(0.0);
    d->coordinatePoint1_y->setSingleStep(0.1);

    QHBoxLayout *layoutPoint1_y = new QHBoxLayout;
    layoutPoint1_y->addWidget(new QLabel("Y",this));
    layoutPoint1_y->addWidget(d->coordinatePoint1_y);

    d->coordinatePoint1_z = new QDoubleSpinBox(this);
    d->coordinatePoint1_z->setRange(-1000, 1000);
    d->coordinatePoint1_z->setValue(0.0);
    d->coordinatePoint1_z->setSingleStep(0.1);

    QHBoxLayout *layoutPoint1_z = new QHBoxLayout;
    layoutPoint1_z->addWidget(new QLabel("Z",this));
    layoutPoint1_z->addWidget(d->coordinatePoint1_z);

    QVBoxLayout *layoutPoint1 = new QVBoxLayout;

    layoutPoint1->addWidget(new QLabel("Point1:", this));
    layoutPoint1->addLayout(layoutPoint1_x);
    layoutPoint1->addLayout(layoutPoint1_y);
    layoutPoint1->addLayout(layoutPoint1_z);

    //POINT2//
    d->coordinatePoint2_x = new QDoubleSpinBox(this);
    d->coordinatePoint2_x->setRange(-1000, 1000);
    d->coordinatePoint2_x->setValue(0.0);
    d->coordinatePoint2_x->setSingleStep(0.1);

    QHBoxLayout *layoutPoint2_x = new QHBoxLayout;
    layoutPoint2_x->addWidget(new QLabel("X",this));
    layoutPoint2_x->addWidget(d->coordinatePoint2_x);

    d->coordinatePoint2_y = new QDoubleSpinBox(this);
    d->coordinatePoint2_y->setRange(-1000, 1000);
    d->coordinatePoint2_y->setValue(1.0);
    d->coordinatePoint2_y->setSingleStep(0.1);

    QHBoxLayout *layoutPoint2_y = new QHBoxLayout;
    layoutPoint2_y->addWidget(new QLabel("Y",this));
    layoutPoint2_y->addWidget(d->coordinatePoint2_y);

    d->coordinatePoint2_z = new QDoubleSpinBox(this);
    d->coordinatePoint2_z->setRange(-1000, 1000);
    d->coordinatePoint2_z->setValue(0.0);
    d->coordinatePoint2_z->setSingleStep(0.1);

    QHBoxLayout *layoutPoint2_z = new QHBoxLayout;
    layoutPoint2_z->addWidget(new QLabel("Z",this));
    layoutPoint2_z->addWidget(d->coordinatePoint2_z);

    QVBoxLayout *layoutPoint2 = new QVBoxLayout;

    layoutPoint2->addWidget(new QLabel("Point2:", this));
    layoutPoint2->addLayout(layoutPoint2_x);
    layoutPoint2->addLayout(layoutPoint2_y);
    layoutPoint2->addLayout(layoutPoint2_z);

    //CENTER//
    d->coordinateCenter_x = new QDoubleSpinBox(this);
    d->coordinateCenter_x->setRange(-1000, 1000);
    d->coordinateCenter_x->setValue(0.0);
    d->coordinateCenter_x->setSingleStep(0.1);

    QHBoxLayout *layoutCenter_x = new QHBoxLayout;
    layoutCenter_x->addWidget(new QLabel("X",this));
    layoutCenter_x->addWidget(d->coordinateCenter_x);

    d->coordinateCenter_y = new QDoubleSpinBox(this);
    d->coordinateCenter_y->setRange(-1000, 1000);
    d->coordinateCenter_y->setValue(0.0);
    d->coordinateCenter_y->setSingleStep(0.1);

    QHBoxLayout *layoutCenter_y = new QHBoxLayout;
    layoutCenter_y->addWidget(new QLabel("Y",this));
    layoutCenter_y->addWidget(d->coordinateCenter_y);

    d->coordinateCenter_z = new QDoubleSpinBox(this);
    d->coordinateCenter_z->setRange(-1000, 1000);
    d->coordinateCenter_z->setValue(0.0);
    d->coordinateCenter_z->setSingleStep(0.1);

    QHBoxLayout *layoutCenter_z = new QHBoxLayout;
    layoutCenter_z->addWidget(new QLabel("Z",this));
    layoutCenter_z->addWidget(d->coordinateCenter_z);

    QVBoxLayout *layoutCenter = new QVBoxLayout;

    layoutCenter->addWidget(new QLabel("Center:", this));
    layoutCenter->addLayout(layoutCenter_x);
    layoutCenter->addLayout(layoutCenter_y);
    layoutCenter->addLayout(layoutCenter_z);

    //RADIUS//
    d->radiusLabel = new QLabel("1.0");

    QHBoxLayout *layoutRadius = new QHBoxLayout;
    layoutRadius->addWidget(new QLabel("Radius",this));
    layoutRadius->addWidget(d->radiusLabel);

    //NORMAL//
    d->coordinateNormal_x = new QDoubleSpinBox(this);
    d->coordinateNormal_x->setRange(-1000, 1000);
    d->coordinateNormal_x->setValue(0.0);
    d->coordinateNormal_x->setSingleStep(0.1);

    d->coordinateNormalLabel_x = new QLabel("0.0");

    QHBoxLayout *layoutNormal_x = new QHBoxLayout;
    layoutNormal_x->addWidget(new QLabel("X",this));
    layoutNormal_x->addWidget(d->coordinateNormalLabel_x);
    layoutNormal_x->addWidget(d->coordinateNormal_x);

    d->coordinateNormal_y = new QDoubleSpinBox(this);
    d->coordinateNormal_y->setRange(-1000, 1000);
    d->coordinateNormal_y->setValue(0.0);
    d->coordinateNormal_y->setSingleStep(0.1);

    d->coordinateNormalLabel_y = new QLabel("0.0");

    QHBoxLayout *layoutNormal_y = new QHBoxLayout;
    layoutNormal_y->addWidget(new QLabel("Y",this));
    layoutNormal_y->addWidget(d->coordinateNormalLabel_y);
    layoutNormal_y->addWidget(d->coordinateNormal_y);

    d->coordinateNormal_z = new QDoubleSpinBox(this);
    d->coordinateNormal_z->setRange(-1000, 1000);
    d->coordinateNormal_z->setValue(1.0);
    d->coordinateNormal_z->setSingleStep(0.1);

    d->coordinateNormalLabel_z = new QLabel("1.0");

    QHBoxLayout *layoutNormal_z = new QHBoxLayout;
    layoutNormal_z->addWidget(new QLabel("Z",this));
    layoutNormal_z->addWidget(d->coordinateNormalLabel_z);
    layoutNormal_z->addWidget(d->coordinateNormal_z);

    QVBoxLayout *layoutNormal = new QVBoxLayout;

    layoutNormal->addWidget(new QLabel("Normal:", this));
    layoutNormal->addWidget(d->linedUpMessage);
    layoutNormal->addLayout(layoutNormal_x);
    layoutNormal->addLayout(layoutNormal_y);
    layoutNormal->addLayout(layoutNormal_z);

    d->coordinateNormal_x->setVisible(false);
    d->coordinateNormal_y->setVisible(false);
    d->coordinateNormal_z->setVisible(false);

    //COUNTER CLOCK WISE CHECK BOX
    d->counterClockWiseCheckBox = new QCheckBox("Counter Clock Wise", this);
    d->counterClockWiseCheckBox->setChecked(true);

    //BUTTON//
    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    //LAYOUTS//
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("axlInspectorToolCreatorCircleArc", this));
    layout->addLayout(layoutPoint1);
    layout->addLayout(layoutPoint2);
    layout->addLayout(layoutCenter);
    layout->addLayout(layoutRadius);
    layout->addLayout(layoutNormal);
    layout->addWidget(d->counterClockWiseCheckBox);
    layout->addLayout(layoutOpacity);
    layout->addLayout(layoutColorButton);
    layout->addWidget(d->centerModifiedMessage);
    layout->addWidget(button);

    connect(d->coordinatePoint1_x, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinatePoint1_y, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinatePoint1_z, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));

    connect(d->coordinatePoint1_x, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));
    connect(d->coordinatePoint1_y, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));
    connect(d->coordinatePoint1_z, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));

    connect(d->coordinatePoint2_x, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinatePoint2_y, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinatePoint2_z, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));

    connect(d->coordinatePoint2_x, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));
    connect(d->coordinatePoint2_y, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));
    connect(d->coordinatePoint2_z, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));

    connect(d->coordinateCenter_x, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinateCenter_y, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinateCenter_z, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));

    connect(d->counterClockWiseCheckBox, SIGNAL(clicked()), this, SLOT(inverseNormal()));
}

axlInspectorToolCreatorCircleArc::~axlInspectorToolCreatorCircleArc(void) {
    delete d;
    d = NULL;
}

void axlInspectorToolCreatorCircleArc::setController(axlInspectorObjectController* /* controller */) {

//    d->controller = controller;
//    if(d->controller->size() < 3){
//        //d->coordinates->show();
//    }else{
//        bool hasRigthType = false;
//        int nbRigthType = 0;
//        foreach(axlInspectorObjectManagerTreeItem *item, d->controller->items()){
//            if(dynamic_cast<axlPoint *>(d->controller->data(item)))
//                nbRigthType++;
//            else if(dynamic_cast<axlDataDynamic *>(d->controller->data(item)))
//                if(dynamic_cast<axlDataDynamic *>(d->controller->data(item))->outputs())
//                    if(dynamic_cast<axlPoint *>(dynamic_cast<axlDataDynamic *>(d->controller->data(item))->outputs()))
//                        nbRigthType++;
//        }

//        if(nbRigthType > 2)
//            hasRigthType = true;
//        //if(!hasRigthType)
//        //d->coordinates->show();
//    }
}

QList<axlAbstractData *> axlInspectorToolCreatorCircleArc::returnInputsList(void){
    QList<axlAbstractData *> list;
    bool condition = true;
    if(condition){
        axlPoint *newCenter = new axlPoint(d->coordinateCenter_x->value(), d->coordinateCenter_y->value(), d->coordinateCenter_z->value());
        axlPoint *point1 = new axlPoint(d->coordinatePoint1_x->value(), d->coordinatePoint1_y->value(), d->coordinatePoint1_z->value());
        axlPoint *point2 = new axlPoint(d->coordinatePoint2_x->value(), d->coordinatePoint2_y->value(), d->coordinatePoint2_z->value());
        axlPoint *normal = new axlPoint(d->coordinateNormal_x->value(), d->coordinateNormal_y->value(), d->coordinateNormal_z->value());
        axlInteger *direct = new axlInteger(d->counterClockWiseCheckBox->isChecked());

        list << newCenter << point1 << point2 << normal << direct;

    }
    return list;

}

void axlInspectorToolCreatorCircleArc::manageNormal(double) {
    axlPoint p1(d->coordinatePoint1_x->text().toDouble(), d->coordinatePoint1_y->text().toDouble(), d->coordinatePoint1_z->text().toDouble());
    axlPoint p2(d->coordinatePoint2_x->text().toDouble(), d->coordinatePoint2_y->text().toDouble(), d->coordinatePoint2_z->text().toDouble());
    axlPoint c(d->coordinateCenter_x->text().toDouble(), d->coordinateCenter_y->text().toDouble(), d->coordinateCenter_z->text().toDouble());

    d->radiusLabel->setText(QString("%1").arg(axlPoint::distance(p1, c)));

    axlPoint calculatedNormal = axlPoint::crossProduct((p1-c), (p2-c)).normalized();
    bool linedUpPoints = calculatedNormal.norm() < 0.001;

    d->coordinateNormal_x->setVisible(linedUpPoints);

    d->coordinateNormalLabel_x->setVisible(!linedUpPoints);
    d->coordinateNormalLabel_x->setText(QString("%1").arg(calculatedNormal.x()));

    d->coordinateNormal_y->setVisible(linedUpPoints);

    d->coordinateNormalLabel_y->setVisible(!linedUpPoints);
    d->coordinateNormalLabel_y->setText(QString("%1").arg(calculatedNormal.y()));

    d->coordinateNormal_z->setVisible(linedUpPoints);

    d->coordinateNormalLabel_z->setVisible(!linedUpPoints);
    d->coordinateNormalLabel_z->setText(QString("%1").arg(calculatedNormal.z()));

    d->linedUpMessage->setVisible(linedUpPoints);
}

void axlInspectorToolCreatorCircleArc::manageCenter(double) {
    axlPoint p1(d->coordinatePoint1_x->text().toDouble(), d->coordinatePoint1_y->text().toDouble(), d->coordinatePoint1_z->text().toDouble());
    axlPoint p2(d->coordinatePoint2_x->text().toDouble(), d->coordinatePoint2_y->text().toDouble(), d->coordinatePoint2_z->text().toDouble());
    axlPoint c(d->coordinateCenter_x->text().toDouble(), d->coordinateCenter_y->text().toDouble(), d->coordinateCenter_z->text().toDouble());

    axlPoint calculatedNormal;
    calculatedNormal = axlPoint(d->coordinateNormal_x->value(), d->coordinateNormal_y->value(), d->coordinateNormal_z->value());

    axlPoint p1p2(p2-p1);
    axlPoint middle((p1+p2)/2);
    axlPoint mediatory = axlPoint::crossProduct(p1p2, calculatedNormal).normalized();
    double ps = axlPoint::dotProduct(mediatory, (c-middle));
    axlPoint newCenter = middle+mediatory*ps;

    d->coordinateCenter_x->setValue(newCenter.x());
    d->coordinateCenter_y->setValue(newCenter.y());
    d->coordinateCenter_z->setValue(newCenter.z());
}

void axlInspectorToolCreatorCircleArc::inverseNormal(void) {
    d->coordinateNormal_x->setValue(-d->coordinateNormal_x->value());
    d->coordinateNormal_y->setValue(-d->coordinateNormal_y->value());
    d->coordinateNormal_z->setValue(-d->coordinateNormal_z->value());

    d->coordinateNormalLabel_x->setText(QString("%1").arg(-d->coordinateNormalLabel_x->text().toDouble()));
    d->coordinateNormalLabel_y->setText(QString("%1").arg(-d->coordinateNormalLabel_y->text().toDouble()));
    d->coordinateNormalLabel_z->setText(QString("%1").arg(-d->coordinateNormalLabel_z->text().toDouble()));
}

void axlInspectorToolCreatorCircleArc::run(void) {
    axlPoint oldCenter(d->coordinateCenter_x->value(), d->coordinateCenter_y->value(), d->coordinateCenter_z->value());
    manageCenter(0.0);
    axlPoint newCenter(d->coordinateCenter_x->value(), d->coordinateCenter_y->value(), d->coordinateCenter_z->value());

    d->centerModifiedMessage->setVisible(axlPoint::distance(oldCenter, newCenter) > 0.01);

    axlPoint point1(d->coordinatePoint1_x->value(), d->coordinatePoint1_y->value(), d->coordinatePoint1_z->value());
    axlPoint point2(d->coordinatePoint2_x->value(), d->coordinatePoint2_y->value(), d->coordinatePoint2_z->value());
    axlPoint normal(d->coordinateNormal_x->value(), d->coordinateNormal_y->value(), d->coordinateNormal_z->value());

    axlCircleArc* newArc = new axlCircleArc(point1, point2, newCenter, normal, d->counterClockWiseCheckBox->isChecked());
    newArc->setColor(d->colorButton->color());
    double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
    newArc->setOpacity(opacity);
    emit dataInserted(newArc);
}
