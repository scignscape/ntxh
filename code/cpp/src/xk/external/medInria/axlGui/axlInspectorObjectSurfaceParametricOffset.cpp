/* axlInspectorObjectSurfaceParametricOffset.cpp ---
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

#include "axlInspectorObjectSurfaceParametricOffset.h"

#include <axlCore/axlSurfaceParametricOffset.h>
#include <axlGui/axlInspectorUtils.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectSurfaceParametricOffsetPrivate
{
public:
    axlSurfaceParametricOffset *surface;

    QDoubleSpinBox *offset;

    QSlider *sliderSize;


    dtkColorButton *colorButton;
    QComboBox *comboBoxShader;

    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;
};

axlInspectorObjectSurfaceParametricOffset::axlInspectorObjectSurfaceParametricOffset(QWidget *parent) : QFrame(parent), d(new axlInspectorObjectSurfaceParametricOffsetPrivate)
{
    d->offset = NULL;

    d->sliderSize = NULL;

    d->colorButton = NULL;
    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectSurfaceParametricOffset::~axlInspectorObjectSurfaceParametricOffset(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectSurfaceParametricOffset::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectSurfaceParametricOffset::setData(axlSurfaceParametricOffset *surface)
{
    d->surface = surface;
    initWidget();
}

void axlInspectorObjectSurfaceParametricOffset::initWidget()
{
    QVBoxLayout *layoutTop = new QVBoxLayout(this);
    layoutTop->addWidget(new QLabel("axlInspectorObjectSurfaceParametricOffset", this));

    ///////SURFACE///////////////

    d->offset = new QDoubleSpinBox(this);
    d->offset->setRange(-1000, 1000);
    d->offset->setValue(d->surface->offset());
    d->offset->setSingleStep(0.1);

    QHBoxLayout *layoutoffset = new QHBoxLayout;
    layoutoffset->addWidget(new QLabel("offset",this));
    layoutoffset->addWidget(d->offset);


    ///////SIZE///////////////

    d->sliderSize = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *layoutSize = new QHBoxLayout;
    layoutSize->addWidget(new QLabel("Size",this));
    layoutSize->addWidget(d->sliderSize);
    d->sliderSize->setMinimum(-800);
    d->sliderSize->setMaximum(500);
    d->sliderSize->setValue(initSizeValue());

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

    layoutTop->addLayout(layoutoffset);
    layoutTop->addWidget(new QLabel(d->surface->surfaceParam()->description(), this));


    layoutTop->addLayout(layoutSize);

    layoutTop->addLayout(layoutColorButton);
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


    connect(d->offset, SIGNAL(valueChanged(double)), this, SLOT(onOffsetChanged(double)));

    connect(d->sliderSize, SIGNAL(valueChanged(int)), this, SLOT(onSizeChanged(int)));


    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));
    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));
    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));
    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));

}


int axlInspectorObjectSurfaceParametricOffset::initSizeValue(void)
{
    double initSize =  100.0*(log(d->surface->size()/0.125))/log(2.0);
//    if(initSize > 10.0)
//        initSize = 10;
//    else if(initSize < 0.0)
//        initSize = 0;

    return initSize;
}

void axlInspectorObjectSurfaceParametricOffset::initComboBoxShaderValue(void)
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

void axlInspectorObjectSurfaceParametricOffset::onLineEditShaderChanged(QString shader)
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

QString axlInspectorObjectSurfaceParametricOffset::initShaderValue(void)
{
    return  d->surface->shader();
}


QColor axlInspectorObjectSurfaceParametricOffset::initColorValue(void)
{
    return d->surface->color();
}


int axlInspectorObjectSurfaceParametricOffset::initOpacityValue(void)
{
    double initOpacity = 0.0;
    double opacity = d->surface->opacity();
    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectSurfaceParametricOffset::openShader()
{
    if(d->lineEditShader->isEnabled())
    {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("xml document (*.xml)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectSurfaceParametricOffset::onShaderChanged(QString shader)
{
    d->surface->setShader(shader);

    emit dataChangedByShader(d->surface, d->lineEditShader->text());

    emit update();
}

void axlInspectorObjectSurfaceParametricOffset::onShaderStateChanged(bool isShader)
{
    if(isShader)
    {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());

        emit dataChangedByShader(d->surface, d->lineEditShader->text());
    }
    else
    {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);

        emit dataChangedByShader(d->surface, "");
    }

    emit update();
}

void axlInspectorObjectSurfaceParametricOffset::onOffsetChanged(double offset)
{
    d->surface->setOffset(offset);

    emit dataChangedByGeometry(d->surface);

    emit update();
}

void axlInspectorObjectSurfaceParametricOffset::onColorChanged(QColor color)
{
    QVariant variant = d->surface->QObject::property("color");
    if(variant.isValid())
    {
        d->surface->setColor(color);

        emit dataChangedByColor(d->surface, color.redF(), color.greenF(), color.blueF());
    }

    emit update();
}


void axlInspectorObjectSurfaceParametricOffset::onSizeChanged(int size)
{
    double size_d = pow(2.0, size/100.0 - 3.0); // range from 0.00 to 10.00

    QVariant variant = d->surface->QObject::property("size");
    if(variant.isValid())
    {
        d->surface->setSize(size_d);

         emit dataChangedByGeometry(d->surface);
    }

    emit update();
}

void axlInspectorObjectSurfaceParametricOffset::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00

    QVariant variant = d->surface->QObject::property("opacity");
    if(variant.isValid())
    {
        d->surface->setOpacity(opacity_d);

        emit dataChangedByOpacity(d->surface, opacity_d);
    }

    emit update();
}




