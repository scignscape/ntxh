/* axlInspectorObjectPoint.cpp ---
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

#include "axlInspectorObjectPoint.h"

#include <axlCore/axlPoint.h>
#include <axlGui/axlInspectorUtils.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectPointPrivate
{
public:
    axlPoint *point;

    QDoubleSpinBox *coordinate_x;
    QDoubleSpinBox *coordinate_y;
    QDoubleSpinBox *coordinate_z;

//    QSlider *sliderSize;
    QDoubleSpinBox *sizeSpinBox;


    dtkColorButton *colorButton;
    QComboBox *comboBoxShader;

    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;
};

axlInspectorObjectPoint::axlInspectorObjectPoint(QWidget *parent):
    axlInspectorObjectInterface(parent), //QFrame(parent),
    d(new axlInspectorObjectPointPrivate)
{
    d->coordinate_x = NULL;
    d->coordinate_y = NULL;
    d->coordinate_z = NULL;

//    d->sliderSize = NULL;
    d->sizeSpinBox = NULL;

    d->colorButton = NULL;
    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectPoint::~axlInspectorObjectPoint(void)
{
//    if(d->point){
//        disconnect(d->point, SIGNAL(modifiedGeometry(void)), this,SLOT( onChangedBoxValue_x(void)));
//        disconnect(d->point, SIGNAL(modifiedGeometry(void)), this,SLOT( onChangedBoxValue_y(void)));
//        disconnect(d->point, SIGNAL(modifiedGeometry(void)), this,SLOT( onChangedBoxValue_z(void)));
//        d->point = NULL;
//    }

    delete d;
    d = NULL;
}

QSize axlInspectorObjectPoint::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectPoint::setData(axlPoint *point)
{
    d->point = point;
    connect(d->point, SIGNAL(modifiedGeometry(void)), this, SLOT( updateValues(void)));
    initWidget();
}

void axlInspectorObjectPoint::initWidget()
{
    QVBoxLayout *layoutTop = new QVBoxLayout(this);
    layoutTop->addWidget(new QLabel("axlInspectorObjectPoint", this));

    ///////COORDINATE///////////////

    d->coordinate_x = new QDoubleSpinBox(this);
    d->coordinate_x->setRange(-1000.0, 1000);
    d->coordinate_x->setValue(d->point->x());
    d->coordinate_x->setSingleStep(0.1);

    d->coordinate_y = new QDoubleSpinBox(this);
    d->coordinate_y->setRange(-1000.0, 1000);
    d->coordinate_y->setSingleStep(0.1);
    d->coordinate_y->setValue(d->point->y());

    d->coordinate_z = new QDoubleSpinBox(this);
    d->coordinate_z->setRange(-1000, 1000);
    d->coordinate_z->setValue(d->point->z());
    d->coordinate_z->setSingleStep(0.1);

    QHBoxLayout *layoutCoordinate_x = new QHBoxLayout;
    layoutCoordinate_x->addWidget(new QLabel("X",this));
    layoutCoordinate_x->addWidget(d->coordinate_x);

    QHBoxLayout *layoutCoordinate_y = new QHBoxLayout;
    layoutCoordinate_y->addWidget(new QLabel("Y",this));
    layoutCoordinate_y->addWidget(d->coordinate_y);

    QHBoxLayout *layoutCoordinate_z = new QHBoxLayout;
    layoutCoordinate_z->addWidget(new QLabel("Z",this));
    layoutCoordinate_z->addWidget(d->coordinate_z);

    ///////SIZE///////////////

//    d->sliderSize = new QSlider(Qt::Horizontal, this);
//
//    QHBoxLayout *layoutSize = new QHBoxLayout;
//    layoutSize->addWidget(new QLabel("Size     ",this));
//    layoutSize->addWidget(d->sliderSize);
//    d->sliderSize->setMinimum(-800);
//    d->sliderSize->setMaximum(500);
//    d->sliderSize->setValue(initSizeValue());
    d->sizeSpinBox = new QDoubleSpinBox(this);
    d->sizeSpinBox->setDecimals(3);
    d->sizeSpinBox->setRange(0, 4);
    d->sizeSpinBox->setSingleStep(0.005);
    d->sizeSpinBox->setValue(d->point->size());

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


    ///////GUI///////////////

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

    layoutTop->addLayout(layoutCoordinate_x);
    layoutTop->addLayout(layoutCoordinate_y);
    layoutTop->addLayout(layoutCoordinate_z);

    layoutTop->addLayout(layoutColorButton);
    layoutTop->addLayout(layoutSize);
    layoutTop->addLayout(layoutOpacity);
    layoutTop->addLayout(layoutShader);

    QWidget *top = new QWidget(this);
    top->setMaximumWidth(295);

    top->setLayout(layoutTop);

    //    dtkSplitter *splitter = new dtkSplitter(this, true);
    //    splitter->setOrientation(Qt::Vertical);
    //    splitter->addWidget(top);

    //QVBoxLayout *layout = new QVBoxLayout(this);
    //layout->setContentsMargins(0, 0, 0, 0);
    //layout->setSpacing(0);
    //layout->addWidget(splitter);


    connect(d->coordinate_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChanged_x(double)));
    connect(d->coordinate_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChanged_y(double)));
    connect(d->coordinate_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChanged_z(double)));

    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));
//    connect(d->sliderSize, SIGNAL(valueChanged(int)), this, SLOT(onSizeChanged(int)));
    connect(d->sizeSpinBox, SIGNAL(valueChanged(double)), this, SLOT(onSizeChanged(double)));
    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));

    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));
    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));
    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));

}


int axlInspectorObjectPoint::initSizeValue(void)
{
    double initSize =  100.0*(log(d->point->size()/0.125))/log(2.0);
    //    if(initSize > 10.0)
    //        initSize = 10;
    //    else if(initSize < 0.0)
    //        initSize = 0;

    return initSize;
}

void axlInspectorObjectPoint::initComboBoxShaderValue(void)
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

void axlInspectorObjectPoint::onLineEditShaderChanged(QString shader)
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


//some adds for dynamic objects
void axlInspectorObjectPoint::onChangedBoxValue_x(void)
{
    double x = d->point->x();
    d->coordinate_x->setValue(x);
}

void axlInspectorObjectPoint::onChangedBoxValue_y(void)
{
    double y = d->point->y();
    d->coordinate_y->setValue(y);
}

void axlInspectorObjectPoint::onChangedBoxValue_z(void)
{
    double z = d->point->z();
    d->coordinate_z->setValue(z);
}
//end adds for dynamic objects


void axlInspectorObjectPoint::updateValues(void)
{
    const QSignalBlocker blockerCoordX(d->coordinate_x);
    const QSignalBlocker blockerCoordY(d->coordinate_y);
    const QSignalBlocker blockerCoordZ(d->coordinate_z);

    d->coordinate_x->setValue(d->point->x());
    d->coordinate_y->setValue(d->point->y());
    d->coordinate_z->setValue(d->point->z());
}

QString axlInspectorObjectPoint::initShaderValue(void)
{
    return  d->point->shader();
}


QColor axlInspectorObjectPoint::initColorValue(void)
{
    return d->point->color();
}


int axlInspectorObjectPoint::initOpacityValue(void)
{
    double initOpacity = 0.0;
    double opacity = d->point->opacity();
    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectPoint::openShader()
{
    if(d->lineEditShader->isEnabled())
    {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("vs file (*.vs)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectPoint::onShaderChanged(QString shader)
{
    d->point->setShader(shader);

//    emit modifiedProperty(d->point, AXL_PROPERTY_SHADER);
//    emit update();
    d->point->touchProperty();
}

void axlInspectorObjectPoint::onShaderStateChanged(bool isShader)
{
    if(isShader)
    {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());

        d->point->setShader(d->lineEditShader->text());
    }
    else
    {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);

        d->point->setShader("");
    }

//    emit modifiedProperty(d->point, AXL_PROPERTY_SHADER);
//    emit update();
    d->point->touchProperty();
}

void axlInspectorObjectPoint::onCoordDataChanged_x(double x)
{
    d->point->x() = x;
    d->point->touchGeometry();
//    emit update();
}

void axlInspectorObjectPoint::onCoordDataChanged_y(double y)
{
    d->point->y() = y;
    d->point->touchGeometry();
//    emit update();
}

void axlInspectorObjectPoint::onCoordDataChanged_z(double z)
{
    d->point->z() = z;
    d->point->touchGeometry();
//    emit update();
}

void axlInspectorObjectPoint::onColorChanged(QColor color)
{
    QVariant variant = d->point->QObject::property("color");
    if(variant.isValid())
    {
        d->point->setColor(color);
//        emit modifiedProperty(d->point, AXL_PROPERTY_COLOR);
        d->point->touchProperty();
    }

//    emit update();
}


//void axlInspectorObjectPoint::onSizeChanged(int size)
//{
//    double size_d = pow(2.0, size/100.0 - 3.0); // range from 0.00 to 10.00
//    d->point->setSize(size_d);
//    d->point->touchGeometry();
//    emit update();
//}

void axlInspectorObjectPoint::onSizeChanged(double size)
{
    d->point->setSize(size);
    d->point->touchGeometry();

//    emit update();
}

void axlInspectorObjectPoint::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00
    d->point->setOpacity(opacity_d);
//    emit modifiedProperty(d->point, AXL_PROPERTY_OPACITY);
//    emit update();
    d->point->touchProperty();
}
