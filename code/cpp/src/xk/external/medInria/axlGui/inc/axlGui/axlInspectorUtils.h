/* axlInspectorUtils.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORUTILS_H
#define AXLINSPECTORUTILS_H

#include "axlGuiExport.h"
#include <QtCore>

#define AXL_PROPERTY_COLOR 0
#define AXL_PROPERTY_OPACITY 1
#define AXL_PROPERTY_SHADER  2
#define AXL_PROPERTY_SIZE 3

bool AXLGUI_EXPORT caseInsensitiveLessThan(const QString &s1, const QString &s2);

#ifndef addColorButton
#define addColorButton(layoutTop, colorButton, slot, init)\
    colorButton = new dtkColorButton(this);\
    QHBoxLayout *layoutColorButton = new QHBoxLayout;\
    layoutColorButton->addWidget(new QLabel("Color",this));\
    layoutColorButton->addWidget(colorButton);\
    colorButton->setColor(this->initColorValue());\
    layoutTop->addLayout(layoutColorButton);\
    connect(colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(slot (QColor)));
#endif

#ifndef addSizeSlider
#define addSizeSlider(layoutTop, sliderSize, slot, init)\
    sliderSize = new QSlider(Qt::Horizontal, this);\
    QHBoxLayout *layoutSize = new QHBoxLayout;\
    layoutSize->addWidget(new QLabel("Size",this));\
    layoutSize->addWidget(sliderSize);\
    sliderSize->setMinimum(-800);\
    sliderSize->setMaximum(500);\
    sliderSize->setValue(init);\
    layoutTop->addLayout(layoutSize);\
    connect(sliderSize, SIGNAL(valueChanged(int)), this, SLOT(slot (int)));
#endif

#ifndef addOpacitySlider
#define addOpacitySlider(layoutTop, sliderOpacity, slot, init)\
    sliderOpacity = new QSlider(Qt::Horizontal, this);\
    sliderOpacity->setMaximum(100);\
    sliderOpacity->setValue(init);\
    QHBoxLayout *layoutOpacity = new QHBoxLayout;\
    layoutOpacity->addWidget(new QLabel("Opacity", this));\
    layoutOpacity->addWidget(sliderOpacity);\
    layoutTop->addLayout(layoutOpacity);\
    connect(sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(slot (int)));
#endif

#ifndef addShaderComboBox
#define addShaderComboBox(layoutTop, comboBoxShader, checkBoxShader, lineEditShader, buttonShader,\
    onComboBoxChanged, onCheckBoxChanged, onTextChanged, openShader, init)\
    comboBoxShader = new QComboBox(this);\
    comboBoxShader->setInsertPolicy(QComboBox::InsertAlphabetically);\
    checkBoxShader = new QCheckBox(this);\
    lineEditShader = new QLineEdit(this);\
    buttonShader = new QPushButton(this);\
    buttonShader->setText("open");\
    lineEditShader->setText(init);\
    this->initComboBoxShaderValue(comboBoxShader,lineEditShader);\
    if(lineEditShader->text().isEmpty())\
    {\
        lineEditShader->setEnabled(false);\
        buttonShader->setEnabled(false);\
        comboBoxShader->setEnabled(false);\
    }\
    else\
        checkBoxShader->setChecked(true);\
    \
    QVBoxLayout *layoutShader = new QVBoxLayout;\
    QHBoxLayout *layoutShader1 = new QHBoxLayout;\
    \
    QLabel *labelShader  = new QLabel("Shader",this);\
    layoutShader1->addWidget(labelShader);\
    layoutShader1->addWidget(checkBoxShader);\
    layoutShader1->addWidget(comboBoxShader);\
    layoutShader1->addWidget(buttonShader);\
    \
    layoutShader1->setStretchFactor(labelShader, 2);\
    layoutShader1->setStretchFactor(checkBoxShader, 1);\
    layoutShader1->setStretchFactor(comboBoxShader, 4);\
    layoutShader1->setStretchFactor(buttonShader, 3);\
    \
    layoutShader->addLayout(layoutShader1);\
    layoutShader->addWidget(lineEditShader);\
    layoutTop->addLayout(layoutShader);\
    connect(comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onComboBoxChanged (QString)));\
    connect(checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onCheckBoxChanged (bool)));\
    connect(buttonShader, SIGNAL(clicked()), this, SLOT(openShader ()));\
    connect(lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged (QString)));
#endif

#ifndef addPointLayout
#define addPointLayout(layoutTop, name, title, coordinatePoint, slot, init)\
    coordinatePoint##_x = new QDoubleSpinBox(this);\
    coordinatePoint##_x->setRange(-1000, 1000);\
    coordinatePoint##_x->setValue(init->x());\
    coordinatePoint##_x->setSingleStep(0.1);\
    \
    coordinatePoint##_y = new QDoubleSpinBox(this);\
    coordinatePoint##_y->setRange(-1000, 1000);\
    coordinatePoint##_y->setValue(init->y());\
    coordinatePoint##_y->setSingleStep(0.1);\
    \
    coordinatePoint##_z = new QDoubleSpinBox(this);\
    coordinatePoint##_z->setRange(-1000, 1000);\
    coordinatePoint##_z->setValue(init->z());\
    coordinatePoint##_z->setSingleStep(0.1);\
    \
    QHBoxLayout * name##LayoutCoordinate_x = new QHBoxLayout;\
    name##LayoutCoordinate_x->addWidget(new QLabel("X",this));\
    name##LayoutCoordinate_x->addWidget(coordinatePoint##_x);\
    \
    QHBoxLayout *name##LayoutCoordinate_y = new QHBoxLayout;\
    name##LayoutCoordinate_y->addWidget(new QLabel("Y",this));\
    name##LayoutCoordinate_y->addWidget(coordinatePoint##_y);\
    \
    QHBoxLayout *name##LayoutCoordinate_z = new QHBoxLayout;\
    name##LayoutCoordinate_z->addWidget(new QLabel("Z",this));\
    name##LayoutCoordinate_z->addWidget(coordinatePoint##_z);\
    \
    layoutTop->addWidget(new QLabel(title,this));\
    layoutTop->addLayout(name##LayoutCoordinate_x);\
    layoutTop->addLayout(name##LayoutCoordinate_y);\
    layoutTop->addLayout(name##LayoutCoordinate_z);\
    \
    connect(coordinatePoint##_x, SIGNAL(valueChanged(double)), this, SLOT(slot##_x (double)));\
    connect(coordinatePoint##_y, SIGNAL(valueChanged(double)), this, SLOT(slot##_y (double)));\
    connect(coordinatePoint##_z, SIGNAL(valueChanged(double)), this, SLOT(slot##_z (double)));

#endif

#ifndef addValueLayout
#define addValueLayout(layoutTop, name, title, data, slot, init)\
    \
    data = new QDoubleSpinBox(this);\
    data->setValue(init);\
    data->setSingleStep(0.1);\
    \
    QHBoxLayout* name##Layout = new QHBoxLayout;\
    name##Layout->addWidget(new QLabel(title,this));\
    name##Layout->addWidget(data);\
    data->setValue(init);\
    layoutTop->addLayout(name##Layout);\
    connect(data, SIGNAL(valueChanged(double)), this, SLOT(slot (double)));

#endif

#endif // AXLINSPECTORUTILS_H
