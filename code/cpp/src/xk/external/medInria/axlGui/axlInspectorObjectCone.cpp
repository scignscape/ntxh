/* axlInspectorObjectCone.cpp ---
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

#include "axlInspectorObjectCone.h"
#include "axlInspectorUtils.h"

#include <axlCore/axlCone.h>
#include <axlCore/axlPoint.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectConePrivate
{
public:
    axlCone *cone;

    QDoubleSpinBox *coordinateApex_x;
    QDoubleSpinBox *coordinateApex_y;
    QDoubleSpinBox *coordinateApex_z;

    QDoubleSpinBox *coordinateBasePoint_x;
    QDoubleSpinBox *coordinateBasePoint_y;
    QDoubleSpinBox *coordinateBasePoint_z;

    QDoubleSpinBox *radius;

    dtkColorButton *colorButton;

    QComboBox *comboBoxShader;

    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;
};

axlInspectorObjectCone::axlInspectorObjectCone(QWidget *parent):
    axlInspectorObjectInterface(parent),
    //QFrame(parent),
    d(new axlInspectorObjectConePrivate)
{
    d->coordinateApex_x = NULL;
    d->coordinateApex_y = NULL;
    d->coordinateApex_z = NULL;

    d->coordinateBasePoint_x = NULL;
    d->coordinateBasePoint_y = NULL;
    d->coordinateBasePoint_z = NULL;

    d->radius = NULL;

    d->colorButton = NULL;

    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectCone::~axlInspectorObjectCone(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectCone::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectCone::setData(axlCone *cone)
{
    d->cone = cone;
    initWidget();
    connect(d->cone, SIGNAL(modifiedGeometry()), this, SLOT(updateValues()));
}

void axlInspectorObjectCone::initWidget()
{
    QVBoxLayout *layoutTop = new QVBoxLayout(this);
    layoutTop->addWidget(new QLabel("axlInspectorObjectCone", this));

    addPointLayout   (layoutTop, Apex, "Apex:",
                      d->coordinateApex, onCoordDataChangedApex,
                      d->cone->apex());

    addPointLayout   (layoutTop, BasePoint, "Base point:",
                      d->coordinateBasePoint, onCoordDataChangedBasePoint,
                      d->cone->basePoint());

    addValueLayout   (layoutTop, Radius, "Radius:", d->radius, onRadiusChanged, d->cone->radius());

    addColorButton   (layoutTop, d->colorButton, onColorChanged, initColorValue());
    addOpacitySlider (layoutTop, d->sliderOpacity, onOpacityChanged, initOpacityValue());
    addShaderComboBox(layoutTop,
                      d->comboBoxShader, d->checkBoxShader, d->lineEditShader, d->buttonShader,
                      onLineEditShaderChanged, onShaderStateChanged, onShaderChanged, openShader,
                      initShaderValue());

    QWidget *top = new QWidget(this);
    top->setMaximumWidth(295);
    top->setLayout(layoutTop);

}

void axlInspectorObjectCone::onLineEditShaderChanged(QString shader)
{
    d->lineEditShader->setText(this->filePath(shader));
}

QString axlInspectorObjectCone::initShaderValue(void)
{
    return d->cone->shader();
}

QColor axlInspectorObjectCone::initColorValue(void)
{
    return d->cone->color();
}

int axlInspectorObjectCone::initOpacityValue(void)
{
    double initOpacity = 0.0;
    double opacity = d->cone->opacity();

    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectCone::openShader()
{
    if(d->lineEditShader->isEnabled()) {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("vs file (*.vs)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectCone::onShaderChanged(QString shader)
{
    d->cone->setShader(shader);

//    emit modifiedProperty(d->cone, 2);
//    emit update();
    d->cone->touchProperty();
}

void axlInspectorObjectCone::onShaderStateChanged(bool isShader)
{
    if(isShader) {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());
    } else {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);
        d->cone->setShader("");
    }

//    emit modifiedProperty(d->cone, 2);
//    emit update();
    d->cone->touchProperty();
}

void axlInspectorObjectCone::onCoordDataChangedApex_x(double x)
{
    d->cone->apex()->x() = x;
    d->cone->touchGeometry();
//    emit update();
}

void axlInspectorObjectCone::onCoordDataChangedApex_y(double y)
{
    d->cone->apex()->y() = y;
    d->cone->touchGeometry();
//    emit update();
}

void axlInspectorObjectCone::onCoordDataChangedApex_z(double z)
{
    d->cone->apex()->z() = z;
    d->cone->touchGeometry();
//    emit update();
}

void axlInspectorObjectCone::onCoordDataChangedBasePoint_x(double x)
{
    d->cone->basePoint()->x() = x;
    d->cone->touchGeometry();
//    emit update();
}

void axlInspectorObjectCone::onCoordDataChangedBasePoint_y(double y)
{
    d->cone->basePoint()->y() = y;
    d->cone->touchGeometry();
//    emit update();
}

void axlInspectorObjectCone::onCoordDataChangedBasePoint_z(double z)
{
    d->cone->basePoint()->z() = z;
    d->cone->touchGeometry();
//    emit update();
}

void axlInspectorObjectCone::onRadiusChanged(double radius)
{
    d->cone->setRadius(radius);
    d->cone->touchGeometry();
//    emit update();
}

void axlInspectorObjectCone::onColorChanged(QColor color)
{
    QVariant variant = d->cone->QObject::property("color");

    if(variant.isValid()) {
        d->cone->setColor(color);

//        emit modifiedProperty(d->cone, 0);
        d->cone->touchProperty();
    }

//    emit update();
}

void axlInspectorObjectCone::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity;

    QVariant variant = d->cone->QObject::property("opacity");

    if(variant.isValid()) {
        d->cone->setOpacity(opacity_d);

//        emit modifiedProperty(d->cone, 1);
        d->cone->touchProperty();
    }

//    emit update();
}

void axlInspectorObjectCone::updateValues(void)
{
//    this->blockSignals(true);

    const QSignalBlocker blockerApexX(d->coordinateApex_x);
    const QSignalBlocker blockerApexY(d->coordinateApex_y);
    const QSignalBlocker blockerApexZ(d->coordinateApex_z);
    const QSignalBlocker blockerBasePointX(d->coordinateBasePoint_x);
    const QSignalBlocker blockerBasePointY(d->coordinateBasePoint_y);
    const QSignalBlocker blockerBasePointZ(d->coordinateBasePoint_z);
    const QSignalBlocker blockerRadius(d->radius);

    d->coordinateApex_x->setValue(d->cone->apex()->x());
    d->coordinateApex_y->setValue(d->cone->apex()->y());
    d->coordinateApex_z->setValue(d->cone->apex()->z());
    d->coordinateBasePoint_x->setValue(d->cone->basePoint()->x());
    d->coordinateBasePoint_y->setValue(d->cone->basePoint()->y());
    d->coordinateBasePoint_z->setValue(d->cone->basePoint()->z());
    d->radius->setValue(d->cone->radius());

//    this->blockSignals(false);
}
