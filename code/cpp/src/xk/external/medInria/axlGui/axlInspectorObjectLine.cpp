/* axlInspectorObjectLine.cpp ---
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

#include "axlInspectorObjectLine.h"

#include <axlCore/axlLine.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlDataDynamic.h>
#include <axlGui/axlInspectorUtils.h>

//#include <math>
#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectLinePrivate
{
public:
    axlLine *line;
    QDoubleSpinBox *coordinateFirst_x;
    QDoubleSpinBox *coordinateFirst_y;
    QDoubleSpinBox *coordinateFirst_z;

    QDoubleSpinBox *coordinateSecond_x;
    QDoubleSpinBox *coordinateSecond_y;
    QDoubleSpinBox *coordinateSecond_z;

//    QSlider *sliderSize;
    QDoubleSpinBox *sizeSpinBox;

    dtkColorButton *colorButton;

    QComboBox *comboBoxShader;

    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;
};

axlInspectorObjectLine::axlInspectorObjectLine(QWidget *parent):
    axlInspectorObjectInterface(parent), //QFrame(parent),
    d(new axlInspectorObjectLinePrivate)
{
    d->line = NULL;
    d->coordinateFirst_x = NULL;
    d->coordinateFirst_y = NULL;
    d->coordinateFirst_z = NULL;

    d->coordinateSecond_x = NULL;
    d->coordinateSecond_y = NULL;
    d->coordinateSecond_z = NULL;

//    d->sliderSize = NULL;
    d->sizeSpinBox = NULL;

    d->colorButton = NULL;
    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectLine::~axlInspectorObjectLine(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectLine::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectLine::setData(axlLine *line)
{
    d->line = line;

    // connect the modification of the geometry with the widget
    connect(d->line, SIGNAL(modifiedGeometry(void)), this, SLOT( updateValues(void)));

    initWidget();
}

int axlInspectorObjectLine::initSizeValue(void)
{
    double initSize = 100.0*(log(d->line->size()/0.125))/log(2.0);

    return initSize;;
}

QString axlInspectorObjectLine::initShaderValue(void)
{
    return  d->line->shader();
}


QColor axlInspectorObjectLine::initColorValue(void)
{
    return d->line->color();
}

int axlInspectorObjectLine::initOpacityValue(void)
{
    double initOpacity = 0.0;
    double opacity = d->line->opacity();

    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectLine::initWidget()
{
    QVBoxLayout *layoutTop = new QVBoxLayout(this);
    layoutTop->addWidget(new QLabel("axlInspectorObjectLine", this));

    ///////COORDINATE///////////////
    d->coordinateFirst_x = new QDoubleSpinBox(this);
    d->coordinateFirst_x->setRange(-1000, 1000);
    d->coordinateFirst_x->setSingleStep(0.1);
    d->coordinateFirst_x->setValue(d->line->firstPoint()->x());

    d->coordinateFirst_y = new QDoubleSpinBox(this);
    d->coordinateFirst_y->setRange(-1000, 1000);
    d->coordinateFirst_y->setSingleStep(0.1);
    d->coordinateFirst_y->setValue(d->line->firstPoint()->y());

    d->coordinateFirst_z = new QDoubleSpinBox(this);
    d->coordinateFirst_z->setRange(-1000, 1000);
    d->coordinateFirst_z->setSingleStep(0.1);
    d->coordinateFirst_z->setValue(d->line->firstPoint()->z());

    d->coordinateSecond_x = new QDoubleSpinBox(this);
    d->coordinateSecond_x->setRange(-1000, 1000);
    d->coordinateSecond_x->setSingleStep(0.1);
    d->coordinateSecond_x->setValue(d->line->secondPoint()->x());

    d->coordinateSecond_y = new QDoubleSpinBox(this);
    d->coordinateSecond_y->setRange(-1000, 1000);
    d->coordinateSecond_y->setSingleStep(0.1);
    d->coordinateSecond_y->setValue(d->line->secondPoint()->y());

    d->coordinateSecond_z = new QDoubleSpinBox(this);
    d->coordinateSecond_z->setRange(-1000, 1000);
    d->coordinateSecond_z->setSingleStep(0.1);
    d->coordinateSecond_z->setValue(d->line->secondPoint()->z());


    QHBoxLayout *layoutcoordinateFirst_x = new QHBoxLayout;
    layoutcoordinateFirst_x->addWidget(new QLabel("X",this));
    layoutcoordinateFirst_x->addWidget(d->coordinateFirst_x);

    QHBoxLayout *layoutcoordinateFirst_y = new QHBoxLayout;
    layoutcoordinateFirst_y->addWidget(new QLabel("Y",this));
    layoutcoordinateFirst_y->addWidget(d->coordinateFirst_y);

    QHBoxLayout *layoutcoordinateFirst_z = new QHBoxLayout;
    layoutcoordinateFirst_z->addWidget(new QLabel("Z",this));
    layoutcoordinateFirst_z->addWidget(d->coordinateFirst_z);


    QHBoxLayout *layoutcoordinateSecond_x = new QHBoxLayout;
    layoutcoordinateSecond_x->addWidget(new QLabel("X",this));
    layoutcoordinateSecond_x->addWidget(d->coordinateSecond_x);

    QHBoxLayout *layoutcoordinateSecond_y = new QHBoxLayout;
    layoutcoordinateSecond_y->addWidget(new QLabel("Y",this));
    layoutcoordinateSecond_y->addWidget(d->coordinateSecond_y);

    QHBoxLayout *layoutcoordinateSecond_z = new QHBoxLayout;
    layoutcoordinateSecond_z->addWidget(new QLabel("Z",this));
    layoutcoordinateSecond_z->addWidget(d->coordinateSecond_z);

    ///////SIZE///////////////
//    d->sliderSize = new QSlider(Qt::Horizontal, this);
//
//    QHBoxLayout *layoutSize = new QHBoxLayout;
//    layoutSize->addWidget(new QLabel("Size",this));
//    layoutSize->addWidget(d->sliderSize);
//    d->sliderSize->setMinimum(-800);
//    d->sliderSize->setMaximum(500);
//    d->sliderSize->setValue(initSizeValue());

    d->sizeSpinBox = new QDoubleSpinBox(this);
    d->sizeSpinBox->setDecimals(3);
    d->sizeSpinBox->setRange(0, 10);
    d->sizeSpinBox->setSingleStep(0.005);
    d->sizeSpinBox->setValue(d->line->size());

    QHBoxLayout *layoutSize = new QHBoxLayout;
    layoutSize->addWidget(new QLabel("Size",this));
    layoutSize->addWidget(d->sizeSpinBox);

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

    ///////GUI///////////////
    layoutTop->addWidget(new QLabel("First point :",this));
    layoutTop->addLayout(layoutcoordinateFirst_x);
    layoutTop->addLayout(layoutcoordinateFirst_y);
    layoutTop->addLayout(layoutcoordinateFirst_z);

    layoutTop->addWidget(new QLabel("Second point :",this));
    layoutTop->addLayout(layoutcoordinateSecond_x);
    layoutTop->addLayout(layoutcoordinateSecond_y);
    layoutTop->addLayout(layoutcoordinateSecond_z);

    layoutTop->addLayout(layoutSize);

    layoutTop->addLayout(layoutColorButton);
    layoutTop->addLayout(layoutOpacity);
    layoutTop->addLayout(layoutShader);

    QWidget *top = new QWidget(this);

    top->setLayout(layoutTop);
    top->setMaximumWidth(295);


    connect(d->coordinateFirst_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedFirst_x(double)));
    connect(d->coordinateFirst_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedFirst_y(double)));
    connect(d->coordinateFirst_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedFirst_z(double)));
    connect(d->coordinateSecond_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedSecond_x(double)));
    connect(d->coordinateSecond_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedSecond_y(double)));
    connect(d->coordinateSecond_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChangedSecond_z(double)));

    connect(d->sizeSpinBox, SIGNAL(valueChanged(double)), this, SLOT(onSizeChanged(double)));

    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));
    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));
    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));
    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));
}

void axlInspectorObjectLine::initComboBoxShaderValue(void)
{
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

            if(currentFileInfo.exists()) {
                if(item == currentFileInfo.fileName())
                    indInitShader =indCurrentShader;
            }
        }

        // init the value from the lineEditShader.
        if(indInitShader != -1)
            d->comboBoxShader->setCurrentIndex(indInitShader);

    }
}

void axlInspectorObjectLine::onLineEditShaderChanged(QString shader)
{
    // First add item of axlShader.qrc, then find shader from shader path
    QDir dirShader( ":axlShader/shader/");
    dirShader.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

    QFileInfo currentFile(dirShader, shader);
    if(!currentFile.exists())
    {
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

void axlInspectorObjectLine::openShader()
{
    if(d->lineEditShader->isEnabled())
    {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("vs file (*.vs)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectLine::onShaderChanged(QString shader)
{
    d->line->setShader(shader);

//    emit dataChangedByShader(d->line, d->lineEditShader->text());
//    emit modifiedProperty(d->line, 2);
    d->line->touchProperty();
//    emit update();
}

void axlInspectorObjectLine::onShaderStateChanged(bool isShader)
{
    if(isShader)
    {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());

//        emit dataChangedByShader(d->line, d->lineEditShader->text());
    }
    else
    {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);

        d->line->setShader("");
//        emit dataChangedByShader(d->line, "");
    }

//    emit modifiedProperty(d->line, 2);
    d->line->touchProperty();
//    emit update();
}

void axlInspectorObjectLine::onCoordDataChangedFirst_x(double x)
{

    if(d->line->parent()){
        axlDataDynamic *dynamicLine = dynamic_cast<axlDataDynamic *>(d->line->parent());
        axlPoint *point1 = dynamic_cast<axlPoint *>(dynamicLine->inputs().at(0));
        point1->x() = x;
        point1->touchGeometry();
    }else{
        d->line->firstPoint()->x() = x;
    }

    d->line->touchGeometry();
//    emit update();
}

void axlInspectorObjectLine::onCoordDataChangedFirst_y(double y)
{
    if(d->line->parent()){
        axlDataDynamic *dynamicLine = dynamic_cast<axlDataDynamic *>(d->line->parent());
        axlPoint *point1 = dynamic_cast<axlPoint *>(dynamicLine->inputs().at(0));
        point1->y() = y;
        point1->touchGeometry();
    }else{
        d->line->firstPoint()->y() = y;
    }

    d->line->touchGeometry();
//    emit update();
}

void axlInspectorObjectLine::onCoordDataChangedFirst_z(double z)
{
    if(d->line->parent()){
        axlDataDynamic *dynamicLine = dynamic_cast<axlDataDynamic *>(d->line->parent());
        axlPoint *point1 = dynamic_cast<axlPoint *>(dynamicLine->inputs().at(0));
        point1->z() = z;
        point1->touchGeometry();
    }else{
        d->line->firstPoint()->z() = z;
    }

    d->line->touchGeometry();
//    emit update();
}


void axlInspectorObjectLine::onCoordDataChangedSecond_x(double x)
{
    if(d->line->parent()){
        axlDataDynamic *dynamicLine = dynamic_cast<axlDataDynamic *>(d->line->parent());
        axlPoint *point2 = dynamic_cast<axlPoint *>(dynamicLine->inputs().at(1));
        point2->x() = x;
        point2->touchGeometry();
    }else{
        d->line->secondPoint()->x() = x;
    }

    d->line->touchGeometry();
//    emit update();
}

void axlInspectorObjectLine::onCoordDataChangedSecond_y(double y)
{
    if(d->line->parent()){
        axlDataDynamic *dynamicLine = dynamic_cast<axlDataDynamic *>(d->line->parent());
        axlPoint *point2 = dynamic_cast<axlPoint *>(dynamicLine->inputs().at(1));
        point2->y() = y;
        point2->touchGeometry();
    }else{
        d->line->secondPoint()->y() = y;
    }

    d->line->touchGeometry();
//    emit update();
}

void axlInspectorObjectLine::onCoordDataChangedSecond_z(double z)
{
    if(d->line->parent()){
        axlDataDynamic *dynamicLine = dynamic_cast<axlDataDynamic *>(d->line->parent());
        axlPoint *point2 = dynamic_cast<axlPoint *>(dynamicLine->inputs().at(1));
        point2->z() = z;
        point2->touchGeometry();
    }else{
        d->line->secondPoint()->z() = z;
    }

    d->line->touchGeometry();
//    emit update();
}

void axlInspectorObjectLine::onColorChanged(QColor color)
{
    QVariant variant = d->line->QObject::property("color");
    if(variant.isValid())
    {
        d->line->setColor(color);

//        emit dataChangedByColor(d->line, color.redF(), color.greenF(), color.blueF());
//        emit modifiedProperty(d->line, 0);
        d->line->touchProperty();
    }

//    emit update();
}


//void axlInspectorObjectLine::onSizeChanged(int size)
//{
//    double size_d = pow(2.0, size/100.0 - 3.0);
//    QVariant variant = d->line->QObject::property("size");
//    if(variant.isValid())
//    {
//        d->line->setSize(size_d);
//        //emit dataChangedByGeometry(d->line);
//        emit modifiedProperty(d->line, 3);
//    }
//
//    emit update();
//}

void axlInspectorObjectLine::onSizeChanged(double size)
{
    d->line->setSize(size);

//    emit modifiedProperty(d->line, 3);
//    emit update();
    d->line->touchGeometry();
}

void axlInspectorObjectLine::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00

    QVariant variant = d->line->QObject::property("opacity");
    if(variant.isValid())
    {
        d->line->setOpacity(opacity_d);

//        emit dataChangedByOpacity(d->line, opacity_d);
//        emit modifiedProperty(d->line, 1);
        d->line->touchProperty();
    }

//    emit update();
}

void axlInspectorObjectLine::updateValues(void)
{
//    this->blockSignals(true);
    const QSignalBlocker blockerFirstX(d->coordinateFirst_x);
    const QSignalBlocker blockerFirstY(d->coordinateFirst_y);
    const QSignalBlocker blockerFirstZ(d->coordinateFirst_z);
    const QSignalBlocker blockerSecondX(d->coordinateSecond_x);
    const QSignalBlocker blockerSecondY(d->coordinateSecond_y);
    const QSignalBlocker blockerSecondZ(d->coordinateSecond_z);

    d->coordinateFirst_x->setValue(d->line->firstPoint()->x());
    d->coordinateFirst_y->setValue(d->line->firstPoint()->y());
    d->coordinateFirst_z->setValue(d->line->firstPoint()->z());

    d->coordinateSecond_x->setValue(d->line->secondPoint()->x());
    d->coordinateSecond_y->setValue(d->line->secondPoint()->y());
    d->coordinateSecond_z->setValue(d->line->secondPoint()->z());
//    this->blockSignals(false);
}
