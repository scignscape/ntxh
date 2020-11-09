/* axlInspectorObjectCylinder.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Fri Mar 18 11:19:52 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Apr  3 14:20:40 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 60
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectCylinder.h"

#include <axlCore/axlCylinder.h>
#include <axlCore/axlPoint.h>
#include <axlGui/axlInspectorUtils.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectCylinderPrivate
{
public:
    axlCylinder *cylinder;
    QDoubleSpinBox *coordinateFirst_x;
    QDoubleSpinBox *coordinateFirst_y;
    QDoubleSpinBox *coordinateFirst_z;

    QDoubleSpinBox *coordinateSecond_x;
    QDoubleSpinBox *coordinateSecond_y;
    QDoubleSpinBox *coordinateSecond_z;

    QDoubleSpinBox *radius;


   // QSlider *sliderSize;


    dtkColorButton *colorButton;

    QComboBox *comboBoxShader;

    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;
};

axlInspectorObjectCylinder::axlInspectorObjectCylinder(QWidget *parent):
    axlInspectorObjectInterface(parent), //QFrame(parent),
    d(new axlInspectorObjectCylinderPrivate)
{
    d->coordinateFirst_x = NULL;
    d->coordinateFirst_y = NULL;
    d->coordinateFirst_z = NULL;

    d->coordinateSecond_x = NULL;
    d->coordinateSecond_y = NULL;
    d->coordinateSecond_z = NULL;

    d->radius = NULL;

   // d->sliderSize = NULL;

    d->colorButton = NULL;

    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectCylinder::~axlInspectorObjectCylinder(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectCylinder::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectCylinder::setData(axlCylinder *cylinder)
{
    d->cylinder = cylinder;
    connect(d->cylinder,SIGNAL(modifiedGeometry(void)), this, SLOT(updateValues()));
    initWidget();
}

void axlInspectorObjectCylinder::initWidget()
{
    QVBoxLayout *layoutTop = new QVBoxLayout(this);
    layoutTop->addWidget(new QLabel("axlInspectorObjectCylinder", this));

    addPointLayout(layoutTop, FirstPoint, "First point:",
                   d->coordinateFirst, onCoordDataChangedFirst,
                   d->cylinder->firstPoint());
    addPointLayout(layoutTop, SecondPoint, "Second point:",
                   d->coordinateSecond, onCoordDataChangedSecond,
                   d->cylinder->secondPoint());

    addValueLayout   (layoutTop, Radius, "Radius:", d->radius, onRadiusChanged, d->cylinder->radius());
    addColorButton   (layoutTop, d->colorButton, onColorChanged, initColorValue());
    addOpacitySlider (layoutTop, d->sliderOpacity, onOpacityChanged, initOpacityValue());
    addShaderComboBox(layoutTop,
                      d->comboBoxShader, d->checkBoxShader, d->lineEditShader, d->buttonShader,
                      onLineEditShaderChanged, onShaderStateChanged, onShaderChanged, openShader,
                      initShaderValue());

    QWidget *top = new QWidget(this);

    top->setLayout(layoutTop);
    top->setMaximumWidth(295);


}


void axlInspectorObjectCylinder::onLineEditShaderChanged(QString shader)
{
    d->lineEditShader->setText(this->filePath(shader));
}

QString axlInspectorObjectCylinder::initShaderValue(void)
{
    return  d->cylinder->shader();
}


QColor axlInspectorObjectCylinder::initColorValue(void)
{
    return d->cylinder->color();
}


int axlInspectorObjectCylinder::initOpacityValue(void)
{
    double initOpacity = 0.0;
    double opacity = d->cylinder->opacity();
    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectCylinder::openShader()
{
    if(d->lineEditShader->isEnabled())
    {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("vs file (*.vs)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectCylinder::onShaderChanged(QString shader)
{
    d->cylinder->setShader(shader);
    emit modifiedProperty(d->cylinder, 2);
}

void axlInspectorObjectCylinder::onShaderStateChanged(bool isShader)
{
    if(isShader)
    {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());

//        emit dataChangedByShader(d->cylinder, d->lineEditShader->text());
    }
    else
    {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);

        d->cylinder->setShader("");
//        emit dataChangedByShader(d->cylinder, "");
    }

//    emit modifiedProperty(d->cylinder, 2);
//    emit update();
    d->cylinder->touchProperty();
}

void axlInspectorObjectCylinder::onCoordDataChangedFirst_x(double x)
{
    d->cylinder->firstPoint()->x() = x;
    d->cylinder->touchGeometry();

    //emit dataChangedByGeometry(d->cylinder);
//    emit update();
}

void axlInspectorObjectCylinder::onCoordDataChangedFirst_y(double y)
{
    d->cylinder->firstPoint()->y() = y;
    d->cylinder->touchGeometry();

    //emit dataChangedByGeometry(d->cylinder);
//    emit update();
}

void axlInspectorObjectCylinder::onCoordDataChangedFirst_z(double z)
{
    d->cylinder->firstPoint()->z() = z;
    d->cylinder->touchGeometry();

    //emit dataChangedByGeometry(d->cylinder);
//    emit update();
}


void axlInspectorObjectCylinder::onCoordDataChangedSecond_x(double x)
{
    d->cylinder->secondPoint()->x() = x;
    d->cylinder->touchGeometry();

    //emit dataChangedByGeometry(d->cylinder);
//    emit update();
}

void axlInspectorObjectCylinder::onCoordDataChangedSecond_y(double y)
{
    d->cylinder->secondPoint()->y() = y;
    d->cylinder->touchGeometry();

    //emit dataChangedByGeometry(d->cylinder);
//    emit update();
}

void axlInspectorObjectCylinder::onCoordDataChangedSecond_z(double z)
{
    d->cylinder->secondPoint()->z() = z;
    d->cylinder->touchGeometry();

    //emit dataChangedByGeometry(d->cylinder);
//    emit update();
}

void axlInspectorObjectCylinder::onRadiusChanged(double radius)
{
    d->cylinder->setRadius(radius);
    d->cylinder->touchGeometry();

    //emit dataChangedByGeometry(d->cylinder);
//    emit update();
}


void axlInspectorObjectCylinder::onColorChanged(QColor color)
{
    QVariant variant = d->cylinder->QObject::property("color");
    if(variant.isValid())
    {
        d->cylinder->setColor(color);

//        emit dataChangedByColor(d->cylinder, color.redF(), color.greenF(), color.blueF());
//        emit modifiedProperty(d->cylinder, 0);
        d->cylinder->touchProperty();
    }

//    emit update();
}


//void axlInspectorObjectCylinder::onSizeChanged(int size)
//{
//    double size_d = size / 100.0; // range from 0.00 to 10.00

//    QVariant variant = d->cylinder->QObject::property("size");
//    if(variant.isValid())
//    {
//        d->cylinder->setSize(size_d);
//        emit dataChangedByGeometry(d->cylinder);

//        //emit dataChangedBySize(d->cylinder, size_d);
//    }

//    emit update();
//}

void axlInspectorObjectCylinder::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00

    QVariant variant = d->cylinder->QObject::property("opacity");
    if(variant.isValid())
    {
        d->cylinder->setOpacity(opacity_d);

//        emit dataChangedByOpacity(d->cylinder, opacity_d);
//        emit modifiedProperty(d->cylinder, 1);
        d->cylinder->touchProperty();
    }

//    emit update();
}


void axlInspectorObjectCylinder::updateValues(void)
{
//    this->blockSignals(true);
    const QSignalBlocker blockerFirstX(d->coordinateFirst_x);
    const QSignalBlocker blockerFirstY(d->coordinateFirst_y);
    const QSignalBlocker blockerFirstZ(d->coordinateFirst_z);
    const QSignalBlocker blockerSecondX(d->coordinateSecond_x);
    const QSignalBlocker blockerSecondY(d->coordinateSecond_y);
    const QSignalBlocker blockerSecondZ(d->coordinateSecond_z);
    const QSignalBlocker blockerRadius(d->radius);

    d->coordinateFirst_x->setValue(d->cylinder->firstPoint()->x());
    d->coordinateFirst_y->setValue(d->cylinder->firstPoint()->y());
    d->coordinateFirst_z->setValue(d->cylinder->firstPoint()->z());
    d->coordinateSecond_x->setValue(d->cylinder->secondPoint()->x());
    d->coordinateSecond_y->setValue(d->cylinder->secondPoint()->y());
    d->coordinateSecond_z->setValue(d->cylinder->secondPoint()->z());
    d->radius->setValue(d->cylinder->radius());
//    this->blockSignals(false);
}
