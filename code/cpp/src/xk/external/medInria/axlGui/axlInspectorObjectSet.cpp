/* axlInspectorObjectSet.cpp ---
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

#include "axlInspectorObjectSet.h"

#include <axlCore/axlAbstractCurveBSpline.h>
#include <axlCore/axlAbstractDataComposite.h>
#include <axlCore/axlAbstractSurfaceBSpline.h>
#include <axlCore/axlMesh.h>

#include <axlGui/axlInspectorUtils.h>

#include <dtkCoreSupport/dtkAbstractData.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectSetPrivate
{
public:
    QList<dtkAbstractData *> dataSet;

    QSpinBox *spinBoxSampling_u;
    QSpinBox *spinBoxSampling_v;

    QSlider *sliderSize;

    dtkColorButton *colorButton;
    QComboBox *comboBoxShader;

    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;

    bool tagSpinBoxSampling_u;
    bool tagSpinBoxSampling_v;
    bool tagSizeSlider;
    bool tagColorButton;
    bool tagOpacitySlider;
    bool tagCheckBoxShader;
};

axlInspectorObjectSet::axlInspectorObjectSet(QWidget *parent) : QFrame(parent), d(new axlInspectorObjectSetPrivate)
{
    d->spinBoxSampling_u = NULL;
    d->spinBoxSampling_v = NULL;

    d->sliderSize = NULL;

    d->colorButton = NULL;
    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;

    d->tagSpinBoxSampling_u = true;
    d->tagSpinBoxSampling_v = true;
    d->tagSizeSlider = true;
    d->tagColorButton = true;
    d->tagCheckBoxShader = true;
    d->tagOpacitySlider = true;
}

axlInspectorObjectSet::~axlInspectorObjectSet(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectSet::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectSet::setData(QList<dtkAbstractData *> dataSet)
{
    d->dataSet = dataSet;
    initTag();
    initWidget();
}

void axlInspectorObjectSet::initTag()
{
    foreach(dtkAbstractData *data, d->dataSet)
    {
        if (dynamic_cast<axlAbstractSurfaceBSpline *>(data))
        {

        }
        else if (dynamic_cast<axlAbstractCurveBSpline *>(data))
        {
            d->tagSpinBoxSampling_v = false;
        }
        else
        {
            d->tagSpinBoxSampling_u = false;
            d->tagSpinBoxSampling_v = false;
        }
    }
}

void axlInspectorObjectSet::initWidget()
{

    QVBoxLayout *layoutTop = new QVBoxLayout;
    layoutTop->addWidget(new QLabel("axlInspectorObjectSet", this));

    if( d->tagSpinBoxSampling_u)
    {
        d->spinBoxSampling_u = new QSpinBox(this);
        d->spinBoxSampling_u->setMaximum(10000);
        d->spinBoxSampling_u->setMinimum(1);
        d->spinBoxSampling_u->setValue(40);

        QHBoxLayout *layoutSampling_u = new QHBoxLayout;
        layoutSampling_u->addWidget(new QLabel("Sampling U",this));
        layoutSampling_u->addWidget(d->spinBoxSampling_u);

        layoutTop->addLayout(layoutSampling_u);

        connect(d->spinBoxSampling_u, SIGNAL(valueChanged(int)), this, SLOT(onSamplingDataChanged_u(int)));

    }

    if(d->tagSpinBoxSampling_v)
    {
        d->spinBoxSampling_v = new QSpinBox(this);
        d->spinBoxSampling_v->setMaximum(10000);
        d->spinBoxSampling_v->setMinimum(1);
        d->spinBoxSampling_v->setValue(40);

        QHBoxLayout *layoutSampling_v = new QHBoxLayout;
        layoutSampling_v->addWidget(new QLabel("Sampling V",this));
        layoutSampling_v->addWidget(d->spinBoxSampling_v);

        layoutTop->addLayout(layoutSampling_v);

        connect(d->spinBoxSampling_v, SIGNAL(valueChanged(int)), this, SLOT(onSamplingDataChanged_v(int)));


    }

    if(d->tagSizeSlider)
    {
        d->sliderSize = new QSlider(Qt::Horizontal, this);

        QHBoxLayout *layoutSize = new QHBoxLayout;
        layoutSize->addWidget(new QLabel("Size",this));
        layoutSize->addWidget(d->sliderSize);
        d->sliderSize->setMinimum(-800);
        d->sliderSize->setMaximum(500);
        d->sliderSize->setValue(initSizeValue());

        layoutTop->addLayout(layoutSize);

        connect(d->sliderSize, SIGNAL(valueChanged(int)), this, SLOT(onSizeChanged(int)));

    }


    if(d->tagColorButton)
    {
        d->colorButton = new dtkColorButton(this);

        QHBoxLayout *layoutColorButton = new QHBoxLayout;
        layoutColorButton->addWidget(new QLabel("Color",this));
        layoutColorButton->addWidget(d->colorButton);

        layoutTop->addLayout(layoutColorButton);

        connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    }

    if(d->tagOpacitySlider)
    {
        d->sliderOpacity = new QSlider(Qt::Horizontal, this);

        QHBoxLayout *layoutOpacity = new QHBoxLayout;
        layoutOpacity->addWidget(new QLabel("Opacity",this));
        layoutOpacity->addWidget(d->sliderOpacity);
        d->sliderOpacity->setMaximum(100);
        d->sliderOpacity->setValue(initOpacityValue());

        layoutTop->addLayout(layoutOpacity);

        connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));

    }

    if(d->tagCheckBoxShader)
    {
        d->comboBoxShader = new QComboBox(this);
        d->comboBoxShader->setInsertPolicy(QComboBox::InsertAlphabetically);
        d->checkBoxShader = new QCheckBox(this);
        d->lineEditShader = new QLineEdit(this);
        d->buttonShader = new QPushButton(this);
        d->buttonShader->setText("open");
        this->initComboBoxShaderValue();

        connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));
        connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
        connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));
        connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));


        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);
        d->comboBoxShader->setEnabled(false);



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

        layoutTop->addLayout(layoutShader);
    }

    layoutTop->addStretch(1);

    QWidget *top = new QWidget(this);
    top->setMaximumWidth(295);

    top->setLayout(layoutTop);

    dtkSplitter *splitter = new dtkSplitter(this, true);
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(top);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(splitter);

}

int axlInspectorObjectSet::initSizeValue()
{
    double initSize = 0.0;
    foreach(dtkAbstractData *data, d->dataSet)
    {

        if (axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data))
        {
            double size = axlData->size();
            if(size > initSize)
                initSize = size;
        }

    }// we have the hight opacity.

    return 100.0 * (log(initSize / 0.125)) / log(2.0);
}

int axlInspectorObjectSet::initOpacityValue()
{
    double initOpacity = 0.0;
    foreach(dtkAbstractData *data, d->dataSet)
    {

        if (axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data))
        {
            double opacity = axlData->opacity();
            if(opacity > initOpacity)
                initOpacity = opacity;
        }

    }// we have the hight opacity.

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectSet::initComboBoxShaderValue(void)
{
    if(d->comboBoxShader)
    {
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


        foreach(QString item, items)
        {
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

void axlInspectorObjectSet::onLineEditShaderChanged(QString shader)
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

void axlInspectorObjectSet::openShader()
{
    if(d->lineEditShader->isEnabled())
    {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("xml document (*.xml)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectSet::onShaderChanged(QString shader)
{
    foreach(dtkAbstractData *data, d->dataSet)
    {
        if (axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data))
        {
            QVariant variant = axlData->QObject::property("shader");
            if(variant.isValid())
                axlData->setShader(shader);
        }

//        emit dataChangedByShader(data, d->lineEditShader->text());
        emit modifiedProperty(data, 2);
    }

//    emit update();
}

void axlInspectorObjectSet::onShaderStateChanged(bool isShader)
{
    if(isShader)
    {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
    }
    else
    {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);
    }
}

void axlInspectorObjectSet::onSamplingDataChanged_u(int numSamples)
{
    foreach(dtkAbstractData *data, d->dataSet)
    {
        if (axlAbstractCurveBSpline *spline_curve = dynamic_cast<axlAbstractCurveBSpline *>(data))
        {
            spline_curve->setNumSamples(numSamples);
        }

        else if (axlAbstractSurfaceBSpline *spline_surface = dynamic_cast<axlAbstractSurfaceBSpline *>(data))
        {
            spline_surface->setNumSamples_u(numSamples);
        }
    }

    emit update();
}

void axlInspectorObjectSet::onSamplingDataChanged_v(int numSamples)
{
    foreach(dtkAbstractData *data, d->dataSet)
    {
        if (axlAbstractSurfaceBSpline *spline_surface = dynamic_cast<axlAbstractSurfaceBSpline *>(data))
        {
            spline_surface->setNumSamples_v(numSamples);
        }
    }

    emit update();
}

void axlInspectorObjectSet::onSizeChanged(int size)
{
    double size_d = pow(2.0, size / 100.0 - 3.0);

    foreach(dtkAbstractData *data, d->dataSet)
    {
        if (axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data))
        {
            QVariant variant = data->QObject::property("size");
            if(variant.isValid())
                axlData->setSize(size_d);
        }

//        emit dataChangedByGeometry(data);
//      //  emit dataChangedBySize(data, size_d);
        emit modifiedProperty(data,3);

    }

//    emit update();
}

void axlInspectorObjectSet::onColorChanged(QColor color)
{
    foreach(dtkAbstractData *data, d->dataSet)
    {
        if (axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data))
        {
            QVariant variant = data->QObject::property("color");
            if(variant.isValid())
                axlData->setColor(color);
        }


//        emit dataChangedByColor(data, color.redF(), color.greenF(), color.blueF());
        emit modifiedProperty(data, 0);
    }

//    emit update();
}

void axlInspectorObjectSet::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00

    foreach(dtkAbstractData *data, d->dataSet)
    {
        if (axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data))
        {
            QVariant variant = axlData->QObject::property("opacity");
            if(variant.isValid())
                axlData->setOpacity(opacity_d);
        }
//        emit dataChangedByOpacity(data, opacity_d);
        emit modifiedProperty(data, 1);
    }

//    emit update();
}




