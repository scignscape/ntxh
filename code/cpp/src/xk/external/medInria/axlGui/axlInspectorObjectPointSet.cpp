/* axlInspectorObjectPointSet.cpp ---
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

#include "axlInspectorObjectPointSet.h"

#include <axlCore/axlPointSet.h>
#include <axlGui/axlInspectorUtils.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectPointSetPrivate
{
public:
    axlPointSet *pointSet;
    QSlider *sliderSize;

    dtkColorButton *colorButton;
    QComboBox *comboBoxShader;

    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;
};

axlInspectorObjectPointSet::axlInspectorObjectPointSet(QWidget *parent) : QFrame(parent), d(new axlInspectorObjectPointSetPrivate)
{
    d->sliderSize = NULL;

    d->colorButton = NULL;
    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectPointSet::~axlInspectorObjectPointSet(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectPointSet::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectPointSet::setData(axlPointSet *pointSet) {
    d->pointSet = pointSet;
    initWidget();
}

void axlInspectorObjectPointSet::initWidget()
{
    QVBoxLayout *layoutTop = new QVBoxLayout(this);
    layoutTop->addWidget(new QLabel("axlInspectorObjectPointSet", this));

    ///////NUMBER OF POINTS///////////////

    layoutTop->addWidget(new QLabel("NumberOfPoint : " +QString::number(d->pointSet->numberOfPoints()), this));

    ///////SIZE///////////////

    d->sliderSize = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *layoutSize = new QHBoxLayout;
    layoutSize->addWidget(new QLabel("Size",this));
    layoutSize->addWidget(d->sliderSize);
    d->sliderSize->setMinimum(-300);
    d->sliderSize->setMaximum(900);
    d->sliderSize->setValue(initSizeValue());

    ///////COLOR///////////////
    QHBoxLayout *layoutColorButton = new QHBoxLayout;
    if(d->pointSet->isUniqueColor())
    {
        d->colorButton = new dtkColorButton(this);

        layoutColorButton->addWidget(new QLabel("Color",this));
        layoutColorButton->addWidget(d->colorButton);
        d->colorButton->setColor(this->initColorValue());
    }
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

    layoutTop->addLayout(layoutSize);

    if(d->pointSet->isUniqueColor())
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

    connect(d->sliderSize, SIGNAL(valueChanged(int)), this, SLOT(onSizeChanged(int)));


    if(d->pointSet->isUniqueColor())
        connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));

    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));
    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));
    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));

}


int axlInspectorObjectPointSet::initSizeValue(void)
{
    double initSize =  100.0 * (log(d->pointSet->size()/0.125))/log(2);

    return initSize;
}

void axlInspectorObjectPointSet::initComboBoxShaderValue(void)
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

void axlInspectorObjectPointSet::onLineEditShaderChanged(QString shader)
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

QString axlInspectorObjectPointSet::initShaderValue(void)
{
    return  d->pointSet->shader();
}


QColor axlInspectorObjectPointSet::initColorValue(void)
{
    return d->pointSet->color();
}


int axlInspectorObjectPointSet::initOpacityValue(void)
{
    double initOpacity = 0.0;
    double opacity = d->pointSet->opacity();
    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectPointSet::openShader()
{
    if(d->lineEditShader->isEnabled())
    {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("vs file (*.vs)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectPointSet::onShaderChanged(QString shader)
{
    d->pointSet->setShader(shader);

    emit dataChangedByShader(d->pointSet, d->lineEditShader->text());

    emit update();
}

void axlInspectorObjectPointSet::onShaderStateChanged(bool isShader)
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

void axlInspectorObjectPointSet::onColorChanged(QColor color)
{
    QVariant variant = d->pointSet->QObject::property("color");
    if(variant.isValid())
    {
        d->pointSet->setColor(color);

        emit dataChangedByColor(d->pointSet, color.redF(), color.greenF(), color.blueF());
    }

    emit update();
}


void axlInspectorObjectPointSet::onSizeChanged(int size)
{
    double size_d = pow(2.0, size/100.0 - 3.0); // range from 0.00 to 10.00

    QVariant variant = d->pointSet->QObject::property("size");
    if(variant.isValid())
    {
        d->pointSet->setSize(size_d);

        emit dataChangedBySize(d->pointSet, size_d);
    }

    emit update();
}

void axlInspectorObjectPointSet::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00

    QVariant variant = d->pointSet->QObject::property("opacity");
    if(variant.isValid())
    {
        d->pointSet->setOpacity(opacity_d);

        emit dataChangedByOpacity(d->pointSet, opacity_d);
    }

    emit update();
}
