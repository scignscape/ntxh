/* axlInspectorObjectDataDynamic.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectDataDynamic.h"

#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlLine.h>
#include <axlGui/axlInspectorUtils.h>
#include <axlGui/axlInspectorObjectLine.h>
#include <axlCore/axlAbstractCreatorProcess.h>

//#include <math>
#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectDataDynamicPrivate
{
public:
    axlDataDynamic *dynamicData;
    //    dtkColorButton *colorButton;

    //    QComboBox *comboBoxShader;

    //    QCheckBox *checkBoxShader;
    //    QLineEdit *lineEditShader;
    //    QPushButton *buttonShader;

    //    QSlider *sliderOpacity;
    QVBoxLayout *layoutTop;
};

axlInspectorObjectDataDynamic::axlInspectorObjectDataDynamic(QWidget *parent):
    axlInspectorObjectInterface(parent), //QFrame(parent),
    d(new axlInspectorObjectDataDynamicPrivate)
{
    d->dynamicData = NULL;

    d->layoutTop = new QVBoxLayout;
    d->layoutTop->addWidget(new QLabel("axlInspectorObjectDataDynamic", this));
    d->layoutTop->addStretch(1);

    QWidget *top = new QWidget(this);
    top->setMaximumWidth(295);
    top->setLayout(d->layoutTop);

    //    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    //    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));

}

axlInspectorObjectDataDynamic::~axlInspectorObjectDataDynamic(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectDataDynamic::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectDataDynamic::setData(axlDataDynamic *dynamicData)
{

    d->dynamicData = dynamicData;

    //display outputs names
    QLabel *newLabelOutput= new QLabel(this);
    newLabelOutput->setText("Outputs :");
    d->layoutTop->addWidget(newLabelOutput);
    for(int i = 0;i < dynamicData->numberOfChannels();i++){
        QLabel *newLabel= new QLabel(this);
        newLabel->setText(d->dynamicData->outputs(i)->name());
        d->layoutTop->addWidget(newLabel);
    }

    //display inputs data and double
    QLabel *newLabel= new QLabel(this);
    newLabel->setText("Inputs :");
    d->layoutTop->addWidget(newLabel);
    for(int i = 0; i < d->dynamicData->inputs().size();i++){
        if(axlDouble *valueInput = dynamic_cast<axlDouble *>(d->dynamicData->inputs().at(i))){
            QDoubleSpinBox *newBox = new QDoubleSpinBox(this);
            newBox->setValue(valueInput->value());
            newBox->setSingleStep(0.10);
            connect(newBox, SIGNAL(valueChanged(double)), valueInput, SLOT(setValue(double)));
            connect(newBox, SIGNAL(valueChanged(double)), this, SIGNAL(update()));
            d->layoutTop->addWidget(newBox);
        }else if(axlInteger *valueInput = dynamic_cast<axlInteger *>(d->dynamicData->inputs().at(i))) {
            QSpinBox *newBox = new QSpinBox(this);
            newBox->setValue(valueInput->value());
            connect(newBox, SIGNAL(valueChanged(int)), valueInput, SLOT(setValue(int)));
            connect(newBox, SIGNAL(valueChanged(int)), this, SIGNAL(update()));
            d->layoutTop->addWidget(newBox);
        }else {
            QLabel *newLabel= new QLabel(this);
            newLabel->setText(d->dynamicData->inputs().at(i)->name());
            d->layoutTop->addWidget(newLabel);
        }
    }


    //    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    //    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));

    //    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));
    //    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));



}

//void axlInspectorObjectDataDynamic::onPropertiesChanged(void){


//    QObject *emitter = sender();
//    axlAbstractData *data = qobject_cast<axlAbstractData *>(emitter);

//    qDebug() << Q_FUNC_INFO << data->name();

//    this->onColorChanged(data->color());
//    d->colorButton->setColor(data->color());
//    this->onOpacityChanged(data->opacity());
//    d->sliderOpacity->setValue(100 * (1.0 - data->opacity()));
//    this->onShaderChanged(data->shader());
//    d->lineEditShader->setText(data->shader());

//}

//void axlInspectorObjectDataDynamic::initComboBoxShaderValue(void)
//{
//    if(d->comboBoxShader)
//    {
//        // First add item of axlShader.qrc, then find shader from shader path
//        QDir dirShader( ":axlShader/shader/");
//        dirShader.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

//        QFileInfoList list = dirShader.entryInfoList();
//        //        for (int i = 0; i < list.size(); ++i) {
//        //            d->comboBoxShader->addItem(list.at(i).fileName());
//        //        }

//        QSettings settings("inria", "dtk");
//        QString defaultPath;
//        settings.beginGroup("shader");
//        QString defaultPathShader = settings.value("path", defaultPath).toString();
//        defaultPathShader.append("/");

//        QDir defaultDirShader(defaultPathShader);
//        QStringList filters;
//        filters << "*.xml";
//        defaultDirShader.setNameFilters(filters);
//        QFileInfoList list2 = defaultDirShader.entryInfoList();

//        list.append(list2);

//        QStringList items;

//        for (int i = 0; i < list.size(); ++i) {
//            if(!items.contains(list.at(i).fileName()))
//                items << list.at(i).fileName();
//        }

//        qSort(items.begin(), items.end(), caseInsensitiveLessThan);
//        int indInitShader = -1;
//        int indCurrentShader = -1;


//        foreach(QString item, items)
//        {
//            indCurrentShader++;
//            d->comboBoxShader->addItem(item);

//            QFileInfo currentFileInfo(d->lineEditShader->text());

//            if(currentFileInfo.exists())
//            {
//                if(item == currentFileInfo.fileName())
//                    indInitShader =indCurrentShader;
//            }

//        }

//        //init the value from the lineEditShader.
//        if(indInitShader != 1)
//            d->comboBoxShader->setCurrentIndex(indInitShader);

//    }
//}

//void axlInspectorObjectDataDynamic::onLineEditShaderChanged(QString shader)
//{
//    // First add item of axlShader.qrc, then find shader from shader path
//    QDir dirShader( ":axlShader/shader/");
//    dirShader.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

//    QFileInfo currentFile(dirShader, shader);
//    if(!currentFile.exists())
//    {
//        QSettings settings("inria", "dtk");
//        QString defaultPath;
//        settings.beginGroup("shader");
//        QString defaultPathShader = settings.value("path", defaultPath).toString();
//        defaultPathShader.append("/");

//        QDir defaultDirShader(defaultPathShader);
//        currentFile = QFileInfo(defaultDirShader, shader);

//    }

//    d->lineEditShader->setText(currentFile.absoluteFilePath());
//}



//void axlInspectorObjectDataDynamic::openShader()
//{
//    if(d->lineEditShader->isEnabled())
//    {
//        QString fileToOpen;
//        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("xml document (*.xml)"));
//        d->lineEditShader->setText(fileToOpen);
//    }
//}

//void axlInspectorObjectDataDynamic::onShaderChanged(QString shader)
//{
//    d->dynamicData->setShader(shader);

//    //    emit dataChangedByShader(d->dynamicData, d->lineEditShader->text());
//    emit modifiedProperty(d->dynamicData, 2);

//    emit update();
//}

//void axlInspectorObjectDataDynamic::onShaderStateChanged(bool isShader)
//{
//    if(isShader)
//    {
//        d->comboBoxShader->setEnabled(true);
//        d->lineEditShader->setEnabled(true);
//        d->buttonShader->setEnabled(true);
//        onLineEditShaderChanged(d->comboBoxShader->currentText());

//        d->dynamicData->setShader(d->lineEditShader->text());
//        //        emit dataChangedByShader(d->dynamicData, d->lineEditShader->text());
//    }
//    else
//    {
//        d->comboBoxShader->setEnabled(false);
//        d->lineEditShader->setEnabled(false);
//        d->buttonShader->setEnabled(false);

//        d->dynamicData->setShader("");
//        //        emit dataChangedByShader(d->dynamicData, "");
//    }

//    emit modifiedProperty(d->dynamicData, 2);
//    emit update();
//}



//void axlInspectorObjectDataDynamic::onColorChanged(QColor color)
//{

//    d->dynamicData->setColor(color);
//    d->dynamicData->outputs()->setColor(color);
//    //    emit dataChangedByColor(d->dynamicData, color.redF(), color.greenF(), color.blueF());
//    emit modifiedProperty(d->dynamicData, 0);

//    emit update();
//}


//void axlInspectorObjectDataDynamic::onOpacityChanged(int opacity)
//{
//    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00
//    d->dynamicData->setOpacity(opacity_d);
//    d->dynamicData->outputs()->setOpacity(opacity_d);

//    //    emit dataChangedByOpacity(d->dynamicData, opacity_d);
//    emit modifiedProperty(d->dynamicData, 1);

//    emit update();
//}


