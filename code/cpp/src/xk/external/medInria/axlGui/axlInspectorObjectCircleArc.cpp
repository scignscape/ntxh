/* axlInspectorObjectCircleArc.cpp ---
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

#include "axlInspectorObjectCircleArc.h"

#include <axlCore/axlCircleArc.h>
#include <axlCore/axlPoint.h>
#include <axlGui/axlInspectorUtils.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectCircleArcPrivate {
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlCircleArc* arc;

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

//    QSlider *sliderSize;
    QDoubleSpinBox *size;

    QComboBox *comboBoxShader;

    QCheckBox* checkBoxShader;
    QLineEdit* lineEditShader;
    QPushButton* buttonShader;
};

axlInspectorObjectCircleArc::axlInspectorObjectCircleArc(QWidget* parent) :
    axlInspectorObjectInterface(parent),
    //QFrame(parent),
    d(new axlInspectorObjectCircleArcPrivate)
{

    d->coordinatePoint1_x = NULL;
    d->coordinatePoint1_y = NULL;
    d->coordinatePoint1_z = NULL;

    d->coordinatePoint2_x = NULL;
    d->coordinatePoint2_y = NULL;
    d->coordinatePoint2_z = NULL;

    d->coordinateCenter_x = NULL;
    d->coordinateCenter_y = NULL;
    d->coordinateCenter_z = NULL;

    d->coordinateNormal_x = NULL;
    d->coordinateNormal_y = NULL;
    d->coordinateNormal_z = NULL;

//    d->sliderSize = NULL;
    d->size = NULL;

    d->colorButton = NULL;

    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectCircleArc::~axlInspectorObjectCircleArc() {
    delete d;
    d = NULL;
}

QSize axlInspectorObjectCircleArc::sizeHint(void) const {
    return QSize(300, 300);
}

void axlInspectorObjectCircleArc::setData(axlCircleArc* arc) {
    d->arc = arc;
    initWidget();
    connect(d->arc, SIGNAL(modifiedGeometry()), this, SLOT(updateValues()));
}

void axlInspectorObjectCircleArc::initWidget(void) {

    //Lined up points message
    d->linedUpMessage = new QLabel("Point1, Point2 and Center are lined up.\nPlease provide the normal of the plane\ncontaining the circle arc.");
    d->linedUpMessage->setStyleSheet("color: #0000FF;");
    d->linedUpMessage->setVisible(false);

    //Center modified message
    d->centerModifiedMessage = new QLabel("Warning: your center has been modified\nto be on the mediatory of [Point1;Point2].");
    d->centerModifiedMessage->setStyleSheet("color: #FF6600;");
    d->centerModifiedMessage->setVisible(false);

    ///////SIZE///////////////
//    d->sliderSize = new QSlider(Qt::Horizontal, this);
    QHBoxLayout *layoutSize = new QHBoxLayout;
    layoutSize->addWidget(new QLabel("Size",this));
//    layoutSize->addWidget(d->sliderSize);
//    d->sliderSize->setMinimum(-800);
//    d->sliderSize->setMaximum(500);
//    d->sliderSize->setValue(initSizeValue());
    d->size = new QDoubleSpinBox(this);
    d->size->setDecimals(3);
    d->size->setRange(0, 100);
    d->size->setSingleStep(0.1);
    d->size->setValue(d->arc->size());
    layoutSize->addWidget(d->size);

    ///////OPACITY///////////////
    d->sliderOpacity = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *layoutOpacity = new QHBoxLayout;
    layoutOpacity->addWidget(new QLabel("Opacity",this));
    layoutOpacity->addWidget(d->sliderOpacity);
    d->sliderOpacity->setMaximum(100);
    d->sliderOpacity->setValue(initOpacityValue());

    ///////COLOR///////////////
    d->colorButton = new dtkColorButton(this);

    QHBoxLayout *layoutColorButton = new QHBoxLayout;
    layoutColorButton->addWidget(new QLabel("Color",this));
    layoutColorButton->addWidget(d->colorButton);
    d->colorButton->setColor(this->initColorValue());

    //POINT1//
    d->coordinatePoint1_x = new QDoubleSpinBox(this);
    d->coordinatePoint1_x->setRange(-1000.0, 1000.0);
    d->coordinatePoint1_x->setValue(d->arc->point1().x());
    d->coordinatePoint1_x->setSingleStep(0.1);

    QHBoxLayout *layoutPoint1_x = new QHBoxLayout;
    layoutPoint1_x->addWidget(new QLabel("X",this));
    layoutPoint1_x->addWidget(d->coordinatePoint1_x);

    d->coordinatePoint1_y = new QDoubleSpinBox(this);
    d->coordinatePoint1_y->setRange(-1000.0, 1000.0);
    d->coordinatePoint1_y->setValue(d->arc->point1().y());
    d->coordinatePoint1_y->setSingleStep(0.1);

    QHBoxLayout *layoutPoint1_y = new QHBoxLayout;
    layoutPoint1_y->addWidget(new QLabel("Y",this));
    layoutPoint1_y->addWidget(d->coordinatePoint1_y);

    d->coordinatePoint1_z = new QDoubleSpinBox(this);
    d->coordinatePoint1_z->setRange(-1000.0, 1000.0);
    d->coordinatePoint1_z->setValue(d->arc->point1().z());
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
    d->coordinatePoint2_x->setRange(-1000.0, 1000.0);
    d->coordinatePoint2_x->setValue(d->arc->point2().x());
    d->coordinatePoint2_x->setSingleStep(0.1);

    QHBoxLayout *layoutPoint2_x = new QHBoxLayout;
    layoutPoint2_x->addWidget(new QLabel("X",this));
    layoutPoint2_x->addWidget(d->coordinatePoint2_x);

    d->coordinatePoint2_y = new QDoubleSpinBox(this);
    d->coordinatePoint2_y->setRange(-1000.0, 1000.0);
    d->coordinatePoint2_y->setValue(d->arc->point2().y());
    d->coordinatePoint2_y->setSingleStep(0.1);

    QHBoxLayout *layoutPoint2_y = new QHBoxLayout;
    layoutPoint2_y->addWidget(new QLabel("Y",this));
    layoutPoint2_y->addWidget(d->coordinatePoint2_y);

    d->coordinatePoint2_z = new QDoubleSpinBox(this);
    d->coordinatePoint2_z->setRange(-1000.0, 1000.0);
    d->coordinatePoint2_z->setValue(d->arc->point2().z());
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
    d->coordinateCenter_x->setRange(-1000.0, 1000.0);
    d->coordinateCenter_x->setValue(d->arc->center().x());
    d->coordinateCenter_x->setSingleStep(0.1);

    QHBoxLayout *layoutCenter_x = new QHBoxLayout;
    layoutCenter_x->addWidget(new QLabel("X",this));
    layoutCenter_x->addWidget(d->coordinateCenter_x);

    d->coordinateCenter_y = new QDoubleSpinBox(this);
    d->coordinateCenter_y->setRange(-1000.0, 1000.0);
    d->coordinateCenter_y->setValue(d->arc->center().y());
    d->coordinateCenter_y->setSingleStep(0.1);

    QHBoxLayout *layoutCenter_y = new QHBoxLayout;
    layoutCenter_y->addWidget(new QLabel("Y",this));
    layoutCenter_y->addWidget(d->coordinateCenter_y);

    d->coordinateCenter_z = new QDoubleSpinBox(this);
    d->coordinateCenter_z->setRange(-1000.0, 1000.0);
    d->coordinateCenter_z->setValue(d->arc->center().z());
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
    d->radiusLabel = new QLabel(QString::number(d->arc->calculateRadius()));

    QHBoxLayout *layoutRadius = new QHBoxLayout;
    layoutRadius->addWidget(new QLabel("Radius",this));
    layoutRadius->addWidget(d->radiusLabel);

    //NORMAL//
    d->coordinateNormal_x = new QDoubleSpinBox(this);
    d->coordinateNormal_x->setRange(-1000.0, 1000.0);
    d->coordinateNormal_x->setValue(d->arc->normal().x());
    d->coordinateNormal_x->setSingleStep(0.1);

    d->coordinateNormalLabel_x = new QLabel(QString::number(d->arc->normal().x()));

    QHBoxLayout *layoutNormal_x = new QHBoxLayout;
    layoutNormal_x->addWidget(new QLabel("X",this));
    layoutNormal_x->addWidget(d->coordinateNormalLabel_x);
    layoutNormal_x->addWidget(d->coordinateNormal_x);

    d->coordinateNormal_y = new QDoubleSpinBox(this);
    d->coordinateNormal_y->setRange(-1000.0, 1000.0);
    d->coordinateNormal_y->setValue(d->arc->normal().y());
    d->coordinateNormal_y->setSingleStep(0.1);

    d->coordinateNormalLabel_y = new QLabel(QString::number(d->arc->normal().y()));

    QHBoxLayout *layoutNormal_y = new QHBoxLayout;
    layoutNormal_y->addWidget(new QLabel("Y",this));
    layoutNormal_y->addWidget(d->coordinateNormalLabel_y);
    layoutNormal_y->addWidget(d->coordinateNormal_y);

    d->coordinateNormal_z = new QDoubleSpinBox(this);
    d->coordinateNormal_z->setRange(-1000.0, 1000.0);
    d->coordinateNormal_z->setValue(d->arc->normal().z());
    d->coordinateNormal_z->setSingleStep(0.1);

    d->coordinateNormalLabel_z = new QLabel(QString::number(d->arc->normal().z()));

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
    d->counterClockWiseCheckBox->setChecked(d->arc->isDirect());

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

    QVBoxLayout *layoutTop = new QVBoxLayout(this);

    layoutTop->addWidget(new QLabel("axlInspectorObjectCircleArc", this));

    layoutTop->addLayout(layoutPoint1);
    layoutTop->addLayout(layoutPoint2);
    layoutTop->addLayout(layoutCenter);
    layoutTop->addLayout(layoutRadius);
    layoutTop->addLayout(layoutNormal);

    layoutTop->addWidget(d->counterClockWiseCheckBox);

    layoutTop->addLayout(layoutSize);

    layoutTop->addLayout(layoutColorButton);
    layoutTop->addLayout(layoutOpacity);

    layoutTop->addWidget(d->centerModifiedMessage);

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

    connect(d->coordinatePoint1_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedPoint1_x(double)));
    connect(d->coordinatePoint1_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedPoint1_y(double)));
    connect(d->coordinatePoint1_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedPoint1_z(double)));

    connect(d->coordinatePoint1_x, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinatePoint1_y, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinatePoint1_z, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));

    connect(d->coordinatePoint1_x, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));
    connect(d->coordinatePoint1_y, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));
    connect(d->coordinatePoint1_z, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));

    connect(d->coordinatePoint2_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedPoint2_x(double)));
    connect(d->coordinatePoint2_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedPoint2_y(double)));
    connect(d->coordinatePoint2_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedPoint2_z(double)));

    connect(d->coordinatePoint2_x, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinatePoint2_y, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinatePoint2_z, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));

    connect(d->coordinatePoint2_x, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));
    connect(d->coordinatePoint2_y, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));
    connect(d->coordinatePoint2_z, SIGNAL(valueChanged(double)), this, SLOT(manageCenter(double)));

    connect(d->coordinateCenter_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedCenter_x(double)));
    connect(d->coordinateCenter_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedCenter_y(double)));
    connect(d->coordinateCenter_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedCenter_z(double)));

    connect(d->coordinateNormal_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedNormal_x(double)));
    connect(d->coordinateNormal_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedNormal_y(double)));
    connect(d->coordinateNormal_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedNormal_z(double)));

    connect(d->coordinateCenter_x, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinateCenter_y, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));
    connect(d->coordinateCenter_z, SIGNAL(valueChanged(double)), this, SLOT(manageNormal(double)));

    connect(d->counterClockWiseCheckBox, SIGNAL(clicked()), this, SLOT(inverseNormal()));

//    connect(d->sliderSize, SIGNAL(valueChanged(int)), this, SLOT(onSizeChanged(int)));
    connect(d->size, SIGNAL(valueChanged(double)), this, SLOT(onSizeChanged(double)));

    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));
    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));
    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));
    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));
}

QString axlInspectorObjectCircleArc::initShaderValue(void) {
    return d->arc->shader();
}

int axlInspectorObjectCircleArc::initSizeValue(void) {
    return 100.0*(log(d->arc->size()/0.125))/log(2.0);
}

QColor axlInspectorObjectCircleArc::initColorValue(void) {
    return d->arc->color();
}

int axlInspectorObjectCircleArc::initOpacityValue(void) {
    double initOpacity = 0.0;
    double opacity = d->arc->opacity();
    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectCircleArc::openShader(void) {
    if(d->lineEditShader->isEnabled()) {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("vs file (*.vs)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectCircleArc::onShaderChanged(QString shader) {
    d->arc->setShader(shader);
//    emit dataChangedByShader(d->arc, d->lineEditShader->text());
//    emit modifiedProperty(d->arc,2);
//    emit update();
    d->arc->touchProperty();
}

void axlInspectorObjectCircleArc::onShaderStateChanged(bool isShader) {
    if(isShader) {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());

//        emit dataChangedByShader(d->arc, d->lineEditShader->text());
    } else {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);

        d->arc->setShader("");
//        emit dataChangedByShader(d->arc, "");
    }

//    emit modifiedProperty(d->arc, 2);
//     emit update();
    d->arc->touchProperty();
}

void axlInspectorObjectCircleArc::initComboBoxShaderValue(void) {
    if(d->comboBoxShader) {

        QStringList filters;
        filters << "*.vs";

        // First add item of axlShader.qrc, then find shader from shader path
        QDir dirShader( ":axlShader/shader/");
        dirShader.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

        dirShader.setNameFilters(filters);

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

            if(currentFileInfo.exists())
            {
                if(item == currentFileInfo.fileName())
                    indInitShader =indCurrentShader;
            }
        }

        //init the value from the lineEditShader.
        if(indInitShader != -1)
            d->comboBoxShader->setCurrentIndex(indInitShader);
    }
}

void axlInspectorObjectCircleArc::onLineEditShaderChanged(QString shader) {
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

void axlInspectorObjectCircleArc::onCoordDataChangedPoint1_x(double x) {
    d->arc->onPoint1XChanged(x);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedPoint1_y(double y) {
    d->arc->onPoint1YChanged(y);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedPoint1_z(double z) {
    d->arc->onPoint1ZChanged(z);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedPoint2_x(double x) {
    d->arc->onPoint2XChanged(x);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedPoint2_y(double y) {
    d->arc->onPoint2YChanged(y);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedPoint2_z(double z) {
    d->arc->onPoint2ZChanged(z);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedCenter_x(double x) {
    d->arc->onCenterXChanged(x);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedCenter_y(double y) {
    d->arc->onCenterYChanged(y);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedCenter_z(double z) {
    d->arc->onCenterZChanged(z);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedNormal_x(double x) {
    d->arc->onNormalXChanged(x);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedNormal_y(double y) {
    d->arc->onNormalYChanged(y);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onCoordDataChangedNormal_z(double z) {
    d->arc->onNormalZChanged(z);
    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::onSizeChanged(double size) {
    QVariant variant = d->arc->QObject::property("size");
    if(variant.isValid()) {
        d->arc->setSize(size);
//        d->arc->touchGeometry();
        emit modifiedProperty(d->arc, 3);
    }

//    emit update();
}

void axlInspectorObjectCircleArc::onColorChanged(QColor color) {
    QVariant variant = d->arc->QObject::property("color");
    if(variant.isValid()) {
        d->arc->setColor(color);
//        emit dataChangedByColor(d->arc, color.redF(), color.greenF(), color.blueF());
//        emit modifiedProperty(d->arc, 0);
        d->arc->touchProperty();
    }
//    emit update();
}

void axlInspectorObjectCircleArc::onOpacityChanged(int opacity) {
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00

    QVariant variant = d->arc->QObject::property("opacity");
    if(variant.isValid()) {
        d->arc->setOpacity(opacity_d);
//        emit dataChangedByOpacity(d->arc, opacity_d);
//        emit modifiedProperty(d->arc, 1);
        d->arc->touchProperty();
    }
//    emit update();
}

void axlInspectorObjectCircleArc::manageNormal(double) {
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

    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::manageCenter(double) {
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

    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::inverseNormal(void) {


    d->coordinateNormal_x->setValue(-d->coordinateNormal_x->value());
    d->coordinateNormal_y->setValue(-d->coordinateNormal_y->value());
    d->coordinateNormal_z->setValue(-d->coordinateNormal_z->value());

    d->coordinateNormalLabel_x->setText(QString("%1").arg(-d->coordinateNormalLabel_x->text().toDouble()));
    d->coordinateNormalLabel_y->setText(QString("%1").arg(-d->coordinateNormalLabel_y->text().toDouble()));
    d->coordinateNormalLabel_z->setText(QString("%1").arg(-d->coordinateNormalLabel_z->text().toDouble()));

    d->arc->onDirectChanged(d->counterClockWiseCheckBox->isChecked());

    d->arc->touchGeometry();
//    emit update();
}

void axlInspectorObjectCircleArc::updateValues(void)
{
//    this->blockSignals(true);
    const QSignalBlocker blockerCoordCenterX(d->coordinateCenter_x);
    const QSignalBlocker blockerCoordCenterY(d->coordinateCenter_y);
    const QSignalBlocker blockerCoordCenterZ(d->coordinateCenter_z);
    const QSignalBlocker blockerCoordPoint1X(d->coordinatePoint1_x);
    const QSignalBlocker blockerCoordPoint1Y(d->coordinatePoint1_y);
    const QSignalBlocker blockerCoordPoint1Z(d->coordinatePoint1_z);
    const QSignalBlocker blockerCoordPoint2X(d->coordinatePoint2_x);
    const QSignalBlocker blockerCoordPoint2Y(d->coordinatePoint2_y);
    const QSignalBlocker blockerCoordPoint2Z(d->coordinatePoint2_z);
    const QSignalBlocker blockerCoordNormalX(d->coordinateNormal_x);
    const QSignalBlocker blockerCoordNormalY(d->coordinateNormal_y);
    const QSignalBlocker blockerCoordNormalZ(d->coordinateNormal_z);

    d->coordinateCenter_x->setValue(d->arc->center().x());
    d->coordinateCenter_y->setValue(d->arc->center().y());
    d->coordinateCenter_z->setValue(d->arc->center().z());

    d->coordinatePoint1_x->setValue(d->arc->point1().x());
    d->coordinatePoint1_y->setValue(d->arc->point1().y());
    d->coordinatePoint1_z->setValue(d->arc->point1().z());

    d->coordinatePoint2_x->setValue(d->arc->point2().x());
    d->coordinatePoint2_y->setValue(d->arc->point2().y());
    d->coordinatePoint2_z->setValue(d->arc->point2().z());

    d->coordinateNormal_x->setValue(d->arc->normal().x());
    d->coordinateNormal_y->setValue(d->arc->normal().y());
    d->coordinateNormal_z->setValue(d->arc->normal().z());

//    this->blockSignals(false);
}

