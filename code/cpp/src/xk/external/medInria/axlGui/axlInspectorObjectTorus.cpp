/* axlInspectorObjectTorus.cpp ---
 *
 * Author: Valntin Michelet
 * Copyright (C) 2008 - Valntin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Valntin Michelet
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectTorus.h"

#include <axlCore/axlTorus.h>
#include <axlCore/axlPoint.h>
#include <axlGui/axlInspectorUtils.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectTorusPrivate {
public:
    axlTorus* torus;

    QDoubleSpinBox* coordinateCenter_x;
    QDoubleSpinBox* coordinateCenter_y;
    QDoubleSpinBox* coordinateCenter_z;

    QDoubleSpinBox* coordinateDirection_x;
    QDoubleSpinBox* coordinateDirection_y;
    QDoubleSpinBox* coordinateDirection_z;

    QDoubleSpinBox* ringRadius;
    QDoubleSpinBox* crossSectionRadius;

    dtkColorButton *colorButton;

    QComboBox *comboBoxShader;

    QCheckBox* checkBoxShader;
    QLineEdit* lineEditShader;
    QPushButton* buttonShader;

    QSlider* sliderOpacity;
};

axlInspectorObjectTorus::axlInspectorObjectTorus(QWidget* parent) :
    QFrame(parent),
    d(new axlInspectorObjectTorusPrivate) {

    d->coordinateCenter_x = NULL;
    d->coordinateCenter_y = NULL;
    d->coordinateCenter_z = NULL;

    d->coordinateDirection_x = NULL;
    d->coordinateDirection_y = NULL;
    d->coordinateDirection_z = NULL;

    d->ringRadius = NULL;
    d->crossSectionRadius = NULL;

    d->colorButton = NULL;

    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectTorus::~axlInspectorObjectTorus() {
    delete d;
    d = NULL;
}

QSize axlInspectorObjectTorus::sizeHint(void) const {
    return QSize(300, 300);
}

void axlInspectorObjectTorus::setData(axlTorus* torus) {
    d->torus = torus;
    connect(d->torus, SIGNAL(modifiedGeometry(void)), this, SLOT( updateValues(void)));
    initWidget();
}

void axlInspectorObjectTorus::initWidget(void) {

    QVBoxLayout *layoutTop = new QVBoxLayout(this);
    layoutTop->addWidget(new QLabel("axlInspectorObjectTorus", this));

    //CENTER//
    d->coordinateCenter_x = new QDoubleSpinBox(this);
    d->coordinateCenter_x->setRange(-1000, 1000);
    d->coordinateCenter_x->setValue(d->torus->centerPoint()->x());
    d->coordinateCenter_x->setSingleStep(0.1);

    QHBoxLayout *layoutCenter_x = new QHBoxLayout;
    layoutCenter_x->addWidget(new QLabel("X",this));
    layoutCenter_x->addWidget(d->coordinateCenter_x);

    d->coordinateCenter_y = new QDoubleSpinBox(this);
    d->coordinateCenter_y->setRange(-1000, 1000);
    d->coordinateCenter_y->setValue(d->torus->centerPoint()->y());
    d->coordinateCenter_y->setSingleStep(0.1);

    QHBoxLayout *layoutCenter_y = new QHBoxLayout;
    layoutCenter_y->addWidget(new QLabel("Y",this));
    layoutCenter_y->addWidget(d->coordinateCenter_y);

    d->coordinateCenter_z = new QDoubleSpinBox(this);
    d->coordinateCenter_z->setRange(-1000, 1000);
    d->coordinateCenter_z->setValue(d->torus->centerPoint()->z());
    d->coordinateCenter_z->setSingleStep(0.1);

    QHBoxLayout *layoutCenter_z = new QHBoxLayout;
    layoutCenter_z->addWidget(new QLabel("Z",this));
    layoutCenter_z->addWidget(d->coordinateCenter_z);

    //DIRECTION//
    d->coordinateDirection_x = new QDoubleSpinBox(this);
    d->coordinateDirection_x->setRange(-1000, 1000);
    d->coordinateDirection_x->setValue(d->torus->direction()->x());
    d->coordinateDirection_x->setSingleStep(0.1);

    QHBoxLayout *layoutDirection_x = new QHBoxLayout;
    layoutDirection_x->addWidget(new QLabel("X",this));
    layoutDirection_x->addWidget(d->coordinateDirection_x);

    d->coordinateDirection_y = new QDoubleSpinBox(this);
    d->coordinateDirection_y->setRange(-1000, 1000);
    d->coordinateDirection_y->setValue(d->torus->direction()->y());
    d->coordinateDirection_y->setSingleStep(0.1);

    QHBoxLayout *layoutDirection_y = new QHBoxLayout;
    layoutDirection_y->addWidget(new QLabel("Y",this));
    layoutDirection_y->addWidget(d->coordinateDirection_y);

    d->coordinateDirection_z = new QDoubleSpinBox(this);
    d->coordinateDirection_z->setRange(-1000, 1000);
    d->coordinateDirection_z->setValue(d->torus->direction()->z());
    d->coordinateDirection_z->setSingleStep(0.1);

    QHBoxLayout *layoutDirection_z = new QHBoxLayout;
    layoutDirection_z->addWidget(new QLabel("Z",this));
    layoutDirection_z->addWidget(d->coordinateDirection_z);

    //RING RADIUS//
    d->ringRadius = new QDoubleSpinBox(this);
    d->ringRadius->setValue(d->torus->ringRadius());
    d->ringRadius->setSingleStep(0.1);

    QHBoxLayout *layoutRingRadius = new QHBoxLayout;
    layoutRingRadius->addWidget(new QLabel("Ring Radius",this));
    layoutRingRadius->addWidget(d->ringRadius);
    d->ringRadius->setValue(d->torus->ringRadius());

    //CROSS SECTION RADIUS//
    d->crossSectionRadius = new QDoubleSpinBox(this);
    d->crossSectionRadius->setValue(d->torus->crossSectionRadius());
    d->crossSectionRadius->setSingleStep(0.1);

    QHBoxLayout *layoutCrossSectionRadius = new QHBoxLayout;
    layoutCrossSectionRadius->addWidget(new QLabel("Cross Section Radius",this));
    layoutCrossSectionRadius->addWidget(d->crossSectionRadius);
    d->crossSectionRadius->setValue(d->torus->crossSectionRadius());

    ///////COLOR///////////////
    d->colorButton = new dtkColorButton(this);

    QHBoxLayout *layoutColorButton = new QHBoxLayout;
    layoutColorButton->addWidget(new QLabel("Color",this));
    layoutColorButton->addWidget(d->colorButton);
    d->colorButton->setColor(this->initColorValue());

    ///////OPACITY///////////////
    d->sliderOpacity = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *layoutOpacity = new QHBoxLayout;
    layoutOpacity->addWidget(new QLabel("Opacity",this));
    layoutOpacity->addWidget(d->sliderOpacity);
    d->sliderOpacity->setMaximum(100);
    d->sliderOpacity->setValue(initOpacityValue());

    ///////SHADER///////////////
    d->comboBoxShader = new QComboBox(this);
    d->comboBoxShader->setInsertPolicy(QComboBox::InsertAlphabetically);

    d->checkBoxShader = new QCheckBox(this);
    d->lineEditShader = new QLineEdit(this);
    d->buttonShader = new QPushButton(this);
    d->buttonShader->setText("open");

    d->lineEditShader->setText(this->initShaderValue());
    this->initComboBoxShaderValue();

    if(d->lineEditShader->text().isEmpty())
    {
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);
        d->comboBoxShader->setEnabled(false);
    }
    else
        d->checkBoxShader->setChecked(true);

    ///////LAYOUTS///////////////
    QVBoxLayout *layoutShader = new QVBoxLayout;
    QHBoxLayout *layoutShader1 = new QHBoxLayout;

    QLabel *labelShader  = new QLabel("Shader",this);
    layoutShader1->addWidget(labelShader);
    layoutShader1->addWidget(d->checkBoxShader);
    layoutShader1->addWidget(d->comboBoxShader);
    layoutShader1->addWidget(d->buttonShader);

    layoutShader1->setStretchFactor(labelShader, 2);
    layoutShader1->setStretchFactor(d->checkBoxShader, 1);
    layoutShader1->setStretchFactor(d->comboBoxShader, 4);
    layoutShader1->setStretchFactor(d->buttonShader, 3);

    layoutShader->addLayout(layoutShader1);
    layoutShader->addWidget(d->lineEditShader);


    layoutTop->addWidget(new QLabel("Center:",this));
    layoutTop->addLayout(layoutCenter_x);
    layoutTop->addLayout(layoutCenter_y);
    layoutTop->addLayout(layoutCenter_z);

    layoutTop->addWidget(new QLabel("Second point to create direction:",this));
    layoutTop->addLayout(layoutDirection_x);
    layoutTop->addLayout(layoutDirection_y);
    layoutTop->addLayout(layoutDirection_z);

    layoutTop->addLayout(layoutRingRadius);
    layoutTop->addLayout(layoutCrossSectionRadius);

    layoutTop->addLayout(layoutColorButton);
    layoutTop->addLayout(layoutOpacity);
    layoutTop->addLayout(layoutShader);

    QWidget *top = new QWidget(this);
    top->setLayout(layoutTop);
    top->setMaximumWidth(295);

    dtkSplitter *splitter = new dtkSplitter(this, true);
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(top);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(splitter);

    connect(d->coordinateCenter_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedCenter_x(double)));
    connect(d->coordinateCenter_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedCenter_y(double)));
    connect(d->coordinateCenter_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedCenter_z(double)));

    connect(d->coordinateDirection_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedDirection_x(double)));
    connect(d->coordinateDirection_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedDirection_y(double)));
    connect(d->coordinateDirection_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedDirection_z(double)));

    connect(d->ringRadius, SIGNAL(valueChanged(double)), this, SLOT(onRingRadiusChanged(double)));
    connect(d->crossSectionRadius, SIGNAL(valueChanged(double)), this, SLOT(onCrossSectionRadiusChanged(double)));

    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));
    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));
    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));
    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));
}

QString axlInspectorObjectTorus::initShaderValue(void) {
    return d->torus->shader();
}

QColor axlInspectorObjectTorus::initColorValue(void) {
    return d->torus->color();
}

int axlInspectorObjectTorus::initOpacityValue(void) {
    double initOpacity = 0.0;
    double opacity = d->torus->opacity();
    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectTorus::openShader(void) {
    if(d->lineEditShader->isEnabled()) {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("xml document (*.xml)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectTorus::onShaderChanged(QString shader) {
    d->torus->setShader(shader);
//    emit dataChangedByShader(d->torus, d->lineEditShader->text());
//    emit modifiedProperty(d->torus, 2);
    d->torus->touchProperty();
//    emit update();
}

void axlInspectorObjectTorus::onShaderStateChanged(bool isShader) {
    if(isShader) {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());

//        emit dataChangedByShader(d->torus, d->lineEditShader->text());
    } else {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);

        d->torus->setShader("");
//        emit dataChangedByShader(d->torus, "");
    }

//    emit modifiedProperty(d->torus, 2);
    d->torus->touchProperty();
//    emit update();
}

void axlInspectorObjectTorus::initComboBoxShaderValue(void) {
    if(d->comboBoxShader) {
        // First add item of axlShader.qrc, then find shader from shader path
        QDir dirShader( ":axlShader/shader/");
        dirShader.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

        QFileInfoList list = dirShader.entryInfoList();
        //        for (int i = 0; i < list.size(); ++i) {
        //            d->comboBoxShader->addItem(list.at(i).fileName());
        //        }

        QSettings settings("inria", "dtk");
        QString defaultPath;
        settings.beginGroup("shader");
        QString defaultPathShader = settings.value("path", defaultPath).toString();
        defaultPathShader.append("/");

        QDir defaultDirShader(defaultPathShader);
        QStringList filters;
        filters << "*.xml";
        defaultDirShader.setNameFilters(filters);
        QFileInfoList list2 = defaultDirShader.entryInfoList();

        list.append(list2);

        QStringList items;

        for (int i = 0; i < list.size(); ++i) {
            if(!items.contains(list.at(i).fileName()))
                items << list.at(i).fileName();
        }

        qSort(items.begin(), items.end(), caseInsensitiveLessThan);
        int indInitShader = -1;
        int indCurrentShader = -1;


        foreach(QString item, items) {
            indCurrentShader++;
            d->comboBoxShader->addItem(item);

            QFileInfo currentFileInfo(d->lineEditShader->text());

            if(currentFileInfo.exists()) {
                if(item == currentFileInfo.fileName())
                    indInitShader = indCurrentShader;
            }
        }

        //init the value from the lineEditShader.
        if(indInitShader != -1)
            d->comboBoxShader->setCurrentIndex(indInitShader);
    }
}

void axlInspectorObjectTorus::onLineEditShaderChanged(QString shader) {
    // First add item of axlShader.qrc, then find shader from shader path
    QDir dirShader( ":axlShader/shader/");
    dirShader.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

    QFileInfo currentFile(dirShader, shader);
    if(!currentFile.exists()) {
        QSettings settings("inria", "dtk");
        QString defaultPath;
        settings.beginGroup("shader");
        QString defaultPathShader = settings.value("path", defaultPath).toString();
        defaultPathShader.append("/");

        QDir defaultDirShader(defaultPathShader);
        currentFile = QFileInfo(defaultDirShader, shader);
    }
    d->lineEditShader->setText(currentFile.absoluteFilePath());
}

void axlInspectorObjectTorus::onCoordDataChangedCenter_x(double x) {
    d->torus->centerPoint()->x() = x;
    d->torus->touchGeometry();
    //emit dataChangedByGeometry(d->torus);
//    emit update();
}

void axlInspectorObjectTorus::onCoordDataChangedCenter_y(double y) {
    d->torus->centerPoint()->y() = y;
    d->torus->touchGeometry();
    //emit dataChangedByGeometry(d->torus);
//    emit update();
}

void axlInspectorObjectTorus::onCoordDataChangedCenter_z(double z) {
    d->torus->centerPoint()->z() = z;
    d->torus->touchGeometry();
    //emit dataChangedByGeometry(d->torus);
//    emit update();
}

void axlInspectorObjectTorus::onCoordDataChangedDirection_x(double x) {
    d->torus->direction()->x() = x;
    d->torus->touchGeometry();
    //emit dataChangedByGeometry(d->torus);
//    emit update();
}

void axlInspectorObjectTorus::onCoordDataChangedDirection_y(double y) {
    d->torus->direction()->y() = y;
    d->torus->touchGeometry();
    //emit dataChangedByGeometry(d->torus);
//    emit update();
}

void axlInspectorObjectTorus::onCoordDataChangedDirection_z(double z) {
    d->torus->direction()->z() = z;
    d->torus->touchGeometry();
    //emit dataChangedByGeometry(d->torus);
//    emit update();
}

void axlInspectorObjectTorus::onRingRadiusChanged(double ringRadius) {
    d->torus->setRingRadius(ringRadius);
    d->torus->touchGeometry();
    //emit dataChangedByGeometry(d->torus);
//    emit update();
}

void axlInspectorObjectTorus::onCrossSectionRadiusChanged(double crossSectionRadius) {
    d->torus->setCrossSectionRadius(crossSectionRadius);
    d->torus->touchGeometry();
    //emit dataChangedByGeometry(d->torus);
//    emit update();
}

void axlInspectorObjectTorus::onColorChanged(QColor color) {
    QVariant variant = d->torus->QObject::property("color");
    if(variant.isValid()) {
        d->torus->setColor(color);
//        emit dataChangedByColor(d->torus, color.redF(), color.greenF(), color.blueF());
//        emit modifiedProperty(d->torus, 0);
        d->torus->touchProperty();
    }
//    emit update();
}

void axlInspectorObjectTorus::onOpacityChanged(int opacity) {
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00

    QVariant variant = d->torus->QObject::property("opacity");
    if(variant.isValid()) {
        d->torus->setOpacity(opacity_d);
//        emit dataChangedByOpacity(d->torus, opacity_d);
//        emit modifiedProperty(d->torus, 1);
        d->torus->touchProperty();
    }
//    emit update();
}

void axlInspectorObjectTorus::updateValues(void)
{
//    this->blockSignals(true);
    const QSignalBlocker blockerCoordCenterX(d->coordinateCenter_x);
    const QSignalBlocker blockerCoordCenterY(d->coordinateCenter_y);
    const QSignalBlocker blockerCoordCenterZ(d->coordinateCenter_z);
    const QSignalBlocker blockerCoordDirectionX(d->coordinateDirection_x);
    const QSignalBlocker blockerCoordDirectionY(d->coordinateDirection_y);
    const QSignalBlocker blockerCoordDirectionZ(d->coordinateDirection_z);
    const QSignalBlocker blockerRingRadius(d->ringRadius);
    const QSignalBlocker blockerCrossSectionRadius(d->crossSectionRadius);

    d->coordinateCenter_x->setValue(d->torus->centerPoint()->x());
    d->coordinateCenter_y->setValue(d->torus->centerPoint()->y());
    d->coordinateCenter_z->setValue(d->torus->centerPoint()->z());

    d->coordinateDirection_x->setValue(d->torus->direction()->x());
    d->coordinateDirection_y->setValue(d->torus->direction()->y());
    d->coordinateDirection_z->setValue(d->torus->direction()->z());

    d->ringRadius->setValue(d->torus->ringRadius());
    d->crossSectionRadius->setValue(d->torus->crossSectionRadius());
//    this->blockSignals(false);
}
