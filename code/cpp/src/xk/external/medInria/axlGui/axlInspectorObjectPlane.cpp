/* axlInspectorObjectPlane.cpp ---
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

#include "axlInspectorObjectPlane.h"

#include <axlCore/axlPlane.h>
#include <axlCore/axlPoint.h>
#include <axlGui/axlInspectorUtils.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectPlanePrivate
{
public:
    axlPlane *plane;
    QDoubleSpinBox *coordinatePoint_x;
    QDoubleSpinBox *coordinatePoint_y;
    QDoubleSpinBox *coordinatePoint_z;

    QDoubleSpinBox *coordinateNormal_x;
    QDoubleSpinBox *coordinateNormal_y;
    QDoubleSpinBox *coordinateNormal_z;

//    QSlider *sliderSize;
    QDoubleSpinBox *sizeSpinBox;

    dtkColorButton *colorButton;
    QComboBox *comboBoxShader;

    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;
};

axlInspectorObjectPlane::axlInspectorObjectPlane(QWidget *parent):
    axlInspectorObjectInterface(parent),
    //QFrame(parent),
    d(new axlInspectorObjectPlanePrivate)
{
    d->coordinatePoint_x = NULL;
    d->coordinatePoint_y = NULL;
    d->coordinatePoint_z = NULL;

    d->coordinateNormal_x = NULL;
    d->coordinateNormal_y = NULL;
    d->coordinateNormal_z = NULL;

//    d->sliderSize = NULL;
    d->sizeSpinBox = NULL;

    d->colorButton = NULL;
    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectPlane::~axlInspectorObjectPlane(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectPlane::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectPlane::setData(axlPlane *plane)
{
    d->plane = plane;
    connect(d->plane, SIGNAL(modifiedGeometry(void)), this, SLOT(updateValues(void)));
    initWidget();
}

void axlInspectorObjectPlane::initWidget()
{
    QVBoxLayout *layoutTop = new QVBoxLayout(this);
    layoutTop->addWidget(new QLabel("axlInspectorObjectPlane", this));

    addPointLayout(layoutTop, Point, "Point:",
                   d->coordinatePoint, onCoordDataChangedPoint,
                   d->plane->point());

    addPointLayout(layoutTop, Normal, "Normal:",
                   d->coordinateNormal, onCoordDataChangedNormal,
                   d->plane->normal());

//    addSizeSlider (layoutTop, d->sliderSize, onSizeChanged, initSizeValue());
    d->sizeSpinBox = new QDoubleSpinBox(this);
    d->sizeSpinBox->setDecimals(3);
    d->sizeSpinBox->setRange(0, 10);
    d->sizeSpinBox->setSingleStep(0.005);
    d->sizeSpinBox->setValue(d->plane->size());

    QHBoxLayout *layoutSize = new QHBoxLayout;
    layoutSize->addWidget(new QLabel("Size",this));
    layoutSize->addWidget(d->sizeSpinBox);
    layoutTop->addLayout(layoutSize);
    connect(d->sizeSpinBox, SIGNAL(valueChanged(double)), this, SLOT(onSizeChanged(double)));

    addColorButton(layoutTop, d->colorButton, onColorChanged, initColorValue());
    addOpacitySlider(layoutTop, d->sliderOpacity, onOpacityChanged, initOpacityValue());
    addShaderComboBox(layoutTop,
                      d->comboBoxShader, d->checkBoxShader, d->lineEditShader, d->buttonShader,
                      onLineEditShaderChanged, onShaderStateChanged, onShaderChanged, openShader,
                      initShaderValue());

    QWidget *top = new QWidget(this);
    top->setMaximumWidth(295);
    top->setLayout(layoutTop);
}


int axlInspectorObjectPlane::initSizeValue(void)
{
    double initSize =  100.0*(log(d->plane->size()/0.125))/log(2.0);

    return initSize;
}



void axlInspectorObjectPlane::onLineEditShaderChanged(QString shader)
{
    d->lineEditShader->setText(this->filePath(shader));
}

QString axlInspectorObjectPlane::initShaderValue(void)
{
    return  d->plane->shader();
}


QColor axlInspectorObjectPlane::initColorValue(void)
{
    return d->plane->color();
}


int axlInspectorObjectPlane::initOpacityValue(void)
{
    double initOpacity = 0.0;
    double opacity = d->plane->opacity();
    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectPlane::openShader()
{
    if(d->lineEditShader->isEnabled())
    {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("vs file (*.vs)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectPlane::onShaderChanged(QString shader)
{
    d->plane->setShader(shader);
//    emit modifiedProperty(d->plane, 2);
    d->plane->touchProperty();
//    emit update();
}

void axlInspectorObjectPlane::onShaderStateChanged(bool isShader)
{
    if(isShader)
    {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());
        d->plane->setShader(d->lineEditShader->text());
    }
    else
    {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);
        d->plane->setShader("");
    }

//    emit modifiedProperty(d->plane, 2);
    d->plane->touchProperty();
//    emit update();
}

void axlInspectorObjectPlane::onCoordDataChangedPoint_x(double x)
{
    d->plane->point()->x() = x;
    d->plane->touchGeometry();
//    emit update();
}

void axlInspectorObjectPlane::onCoordDataChangedPoint_y(double y)
{
    d->plane->point()->y() = y;
    d->plane->touchGeometry();
//    emit update();
}

void axlInspectorObjectPlane::onCoordDataChangedPoint_z(double z)
{
    d->plane->point()->z() = z;
    d->plane->touchGeometry();
//    emit update();
}


void axlInspectorObjectPlane::onCoordDataChangedNormal_x(double x)
{
    d->plane->normal()->x() = x;
    d->plane->touchGeometry();
//    emit update();
}

void axlInspectorObjectPlane::onCoordDataChangedNormal_y(double y)
{
    d->plane->normal()->y() = y;
    d->plane->touchGeometry();
//    emit update();
}

void axlInspectorObjectPlane::onCoordDataChangedNormal_z(double z)
{
    d->plane->normal()->z() = z;
    d->plane->touchGeometry();
//    emit update();
}

void axlInspectorObjectPlane::onColorChanged(QColor color)
{
    QVariant variant = d->plane->QObject::property("color");
    if(variant.isValid())
    {
        d->plane->setColor(color);
//        emit modifiedProperty(d->plane, 0);
        d->plane->touchProperty();
    }

//    emit update();
}


//void axlInspectorObjectPlane::onSizeChanged(int size)
//{
//    double size_d = pow(2.0, size/100.0 - 3.0); // range from 0.00 to 10.00
//
//    QVariant variant = d->plane->QObject::property("size");
//    if(variant.isValid())
//    {
//        d->plane->setSize(size_d);
//        emit modifiedProperty(d->plane, 3);
//    }
//
//    emit update();
//}

void axlInspectorObjectPlane::onSizeChanged(double size)
{
    d->plane->setSize(size);

//    emit modifiedProperty(d->plane, 3);
//    emit update();
    d->plane->touchGeometry();
}

void axlInspectorObjectPlane::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00

    QVariant variant = d->plane->QObject::property("opacity");
    if(variant.isValid())
    {
        d->plane->setOpacity(opacity_d);
//        emit modifiedProperty(d->plane, 1);
        d->plane->touchProperty();
    }

//    emit update();
}

void axlInspectorObjectPlane::updateValues(void)
{
//    this->blockSignals(true);
    const QSignalBlocker blockerPointX(d->coordinatePoint_x);
    const QSignalBlocker blockerPointY(d->coordinatePoint_y);
    const QSignalBlocker blockerPointZ(d->coordinatePoint_z);
    const QSignalBlocker blockerNormalX(d->coordinateNormal_x);
    const QSignalBlocker blockerNormalY(d->coordinateNormal_y);
    const QSignalBlocker blockerNormalZ(d->coordinateNormal_z);

    d->coordinatePoint_x->setValue(d->plane->point()->x());
    d->coordinatePoint_y->setValue(d->plane->point()->y());
    d->coordinatePoint_z->setValue(d->plane->point()->z());

    d->coordinateNormal_x->setValue(d->plane->normal()->x());
    d->coordinateNormal_y->setValue(d->plane->normal()->y());
    d->coordinateNormal_z->setValue(d->plane->normal()->z());

//    this->blockSignals(false);
}
