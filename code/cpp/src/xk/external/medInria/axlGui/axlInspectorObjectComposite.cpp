/* axlInspectorObjectComposite.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Mar 18 11:19:52 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Apr  3 14:20:31 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 60
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectComposite.h"
#include "axlParameterSpace.h"

#include <axlCore/axlAbstractDataComposite.h>
#include <dtkCoreSupport/dtkAbstractData.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>



class axlInspectorObjectCompositePrivate
{
public:
    axlAbstractDataComposite *data;
    dtkColorButton *colorButton;

    QComboBox *comboBoxShader;

    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;

public:
    axlParameterSpace *parameter_space;
};

axlInspectorObjectComposite::axlInspectorObjectComposite(QWidget *parent) : QFrame(parent), d(new axlInspectorObjectCompositePrivate)
{
    d->data = NULL;

    d->parameter_space = new axlParameterSpace(this);

    d->sliderOpacity = new QSlider(Qt::Horizontal, this);
    d->sliderOpacity->setMaximum(100);

    d->comboBoxShader  = new QComboBox(this);

    d->checkBoxShader = new QCheckBox(this);
    d->lineEditShader = new QLineEdit(this);
    d->buttonShader = new QPushButton(this);
    d->buttonShader->setText("open");
    d->lineEditShader->setEnabled(false);
    d->buttonShader->setEnabled(false);
    d->comboBoxShader->setEnabled(false);

    d->colorButton = new dtkColorButton(this);

    QHBoxLayout *layoutColorButton = new QHBoxLayout;
    layoutColorButton->addWidget(new QLabel("Color",this));
    layoutColorButton->addWidget(d->colorButton);

    QHBoxLayout *layoutOpacity = new QHBoxLayout;
    layoutOpacity->addWidget(new QLabel("Opacity",this));
    layoutOpacity->addWidget(d->sliderOpacity);

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

    QVBoxLayout *layoutTop = new QVBoxLayout;
    layoutTop->addWidget(new QLabel("axlInspectorObjectComposite", this));
    layoutTop->addLayout(layoutColorButton);
    layoutTop->addLayout(layoutOpacity);
    layoutTop->addLayout(layoutShader);
    layoutTop->addStretch(1);

    QWidget *top = new QWidget(this);
    top->setMaximumWidth(295);
    top->setLayout(layoutTop);

    dtkSplitter *splitter = new dtkSplitter(this, true);
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(top);
    splitter->addWidget(d->parameter_space);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(splitter);


    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));


    connect(d->parameter_space, SIGNAL(showCurrentPoint(double, double)), this, SLOT(onShowCurrentPoint(double, double)));
    connect(d->parameter_space, SIGNAL(hideCurrentPoint(double, double)), this, SLOT(onHideCurrentPoint(double, double)));
    connect(d->parameter_space, SIGNAL(moveCurrentPoint(double, double)), this, SLOT(onMoveCurrentPoint(double, double)));
    connect(d->parameter_space, SIGNAL(update()), this, SIGNAL(update()));
}

axlInspectorObjectComposite::~axlInspectorObjectComposite(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectComposite::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectComposite::setData(axlAbstractDataComposite *data)
{
    d->data = data;

    axlAbstractDataComposite *object = d->data;
    QColor color = object->color();

    d->colorButton->setColor(color);
    d->sliderOpacity->setValue(100 * (1.0 - d->data->opacity()));
    d->lineEditShader->setText(d->data->shader());
    this->initComboBoxShaderValue();


    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));

    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));
    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));


}

void axlInspectorObjectComposite::onColorChanged(QColor color)
{
    d->data->setColor(color);

    //    emit dataChangedByColor(d->data, color.redF(), color.greenF(), color.blueF());
    emit modifiedProperty(d->data, 0);

//    emit update();
}

void axlInspectorObjectComposite::openShader()
{
    if(d->lineEditShader->isEnabled())
    {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("vs file (*.vs)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectComposite::initComboBoxShaderValue(void)
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


void axlInspectorObjectComposite::onShaderChanged(QString shader)
{
    d->data->setShader(shader);

    //    emit dataChangedByShader(d->data, d->lineEditShader->text());
    emit modifiedProperty(d->data, 2);

//    emit update();
}

void axlInspectorObjectComposite::onLineEditShaderChanged(QString shader)
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

void axlInspectorObjectComposite::onShaderStateChanged(bool isShader)
{
    if(isShader)
    {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());

        //        emit dataChangedByShader(d->data, d->lineEditShader->text());
    }
    else
    {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);

        //        emit dataChangedByShader(d->data, "");
    }
    emit modifiedProperty(d->data, 2);
//    emit update();
}

void axlInspectorObjectComposite::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00
    d->data->setOpacity(opacity_d);

//    emit dataChangedByOpacity(d->data, opacity_d);
    emit modifiedProperty(d->data, 1);

//    emit update();
}

void axlInspectorObjectComposite::onShowCurrentPoint(double u, double v)
{
    emit showCurrentPoint(u, v, (dtkAbstractData *)d->data);
}

void axlInspectorObjectComposite::onMoveCurrentPoint(double u, double v)
{
    emit moveCurrentPoint(u, v, (dtkAbstractData *)d->data);
}

void axlInspectorObjectComposite::onHideCurrentPoint(double u, double v)
{
    emit hideCurrentPoint(u, v, (dtkAbstractData *)d->data);
}
