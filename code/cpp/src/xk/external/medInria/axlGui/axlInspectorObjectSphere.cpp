/* axlInspectorObjectSphere.cpp ---
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

#include "axlInspectorObjectSphere.h"

#include <axlCore/axlSphere.h>
#include <axlGui/axlInspectorUtils.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectSpherePrivate
{
public:
    axlSphere *sphere;

    QDoubleSpinBox *coordinate_x;
    QDoubleSpinBox *coordinate_y;
    QDoubleSpinBox *coordinate_z;
    QDoubleSpinBox *radius;


    //QSlider *sliderSize;


    dtkColorButton *colorButton;
    QComboBox *comboBoxShader;


    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;
};

axlInspectorObjectSphere::axlInspectorObjectSphere(QWidget *parent) : QFrame(parent), d(new axlInspectorObjectSpherePrivate)
{
    d->coordinate_x = NULL;
    d->coordinate_y = NULL;
    d->coordinate_z = NULL;
    d->radius = NULL;


    //d->sliderSize = NULL;

    d->colorButton = NULL;
    d->comboBoxShader = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectSphere::~axlInspectorObjectSphere(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectSphere::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectSphere::setData(axlSphere *sphere)
{
    d->sphere = sphere;

    // connect the modification of the geometry with the widget
    connect(d->sphere, SIGNAL(modifiedGeometry(void)), this, SLOT( updateValues(void)));

    initWidget();
}

void axlInspectorObjectSphere::initWidget()
{
    QVBoxLayout *layoutTop = new QVBoxLayout(this);
    layoutTop->addWidget(new QLabel("axlInspectorObjectSphere", this));

    ///////COORDINATE///////////////

    d->coordinate_x = new QDoubleSpinBox(this);
    d->coordinate_x->setRange(-1000, 1000);
    d->coordinate_x->setValue(d->sphere->x());
    d->coordinate_x->setSingleStep(0.1);

    d->coordinate_y = new QDoubleSpinBox(this);
    d->coordinate_y->setRange(-1000, 1000);
    d->coordinate_y->setValue(d->sphere->y());
    d->coordinate_y->setSingleStep(0.1);

    d->coordinate_z = new QDoubleSpinBox(this);
    d->coordinate_z->setRange(-1000, 1000);
    d->coordinate_z->setValue(d->sphere->z());
    d->coordinate_z->setSingleStep(0.1);

    d->radius = new QDoubleSpinBox(this);
    d->radius->setValue(d->sphere->radius());
    d->radius->setSingleStep(0.1);


    QHBoxLayout *layoutCoordinate_x = new QHBoxLayout;
    layoutCoordinate_x->addWidget(new QLabel("X",this));
    layoutCoordinate_x->addWidget(d->coordinate_x);

    QHBoxLayout *layoutCoordinate_y = new QHBoxLayout;
    layoutCoordinate_y->addWidget(new QLabel("Y",this));
    layoutCoordinate_y->addWidget(d->coordinate_y);

    QHBoxLayout *layoutCoordinate_z = new QHBoxLayout;
    layoutCoordinate_z->addWidget(new QLabel("Z",this));
    layoutCoordinate_z->addWidget(d->coordinate_z);

    QHBoxLayout *layoutRadius = new QHBoxLayout;
    layoutRadius->addWidget(new QLabel("Radius",this));
    layoutRadius->addWidget(d->radius);
    d->radius->setValue(d->sphere->radius());

    //    ///////SIZE///////////////

    //    d->sliderSize = new QSlider(Qt::Horizontal, this);

    //    QHBoxLayout *layoutSize = new QHBoxLayout;
    //    layoutSize->addWidget(new QLabel("Size",this));
    //    layoutSize->addWidget(d->sliderSize);
    //    d->sliderSize->setMaximum(1000);
    //    d->sliderSize->setValue(initSizeValue());

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
    layoutTop->addLayout(layoutRadius);

    //    layoutTop->addLayout(layoutSize);

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


    connect(d->coordinate_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChanged_x(double)));
    connect(d->coordinate_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChanged_y(double)));
    connect(d->coordinate_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChanged_z(double)));
    connect(d->radius, SIGNAL(valueChanged(double)), this, SLOT(onRadiusChanged(double)));

    //    connect(d->sliderSize, SIGNAL(valueChanged(int)), this, SLOT(onSizeChanged(int)));


    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));
    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));
    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));
    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));

    //connect(d->sphere, SIGNAL(dataChanged(void)), this, SLOT(onRecievedDataChanged(void)));
}

void axlInspectorObjectSphere::onRecievedDataChanged(void)
{
    //We need to block signal to don't have a boucle with connection
    this->blockSignals(true);
    d->coordinate_x->setValue(d->sphere->x());
    d->coordinate_y->setValue(d->sphere->y());
    d->coordinate_z->setValue(d->sphere->z());
    d->radius->setValue(d->sphere->radius());
    this->blockSignals(false);

}

void axlInspectorObjectSphere::initComboBoxShaderValue(void)
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

void axlInspectorObjectSphere::onLineEditShaderChanged(QString shader)
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

QString axlInspectorObjectSphere::initShaderValue(void)
{
    return  d->sphere->shader();
}


QColor axlInspectorObjectSphere::initColorValue(void)
{
    return d->sphere->color();
}


int axlInspectorObjectSphere::initOpacityValue(void)
{
    double initOpacity = 0.0;
    double opacity = d->sphere->opacity();
    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectSphere::openShader()
{
    if(d->lineEditShader->isEnabled())
    {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("xml document (*.xml)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectSphere::onShaderChanged(QString shader)
{
    d->sphere->setShader(shader);

    //emit dataChangedByShader(d->sphere, d->lineEditShader->text());
//    emit modifiedProperty(d->sphere, 2);

//    emit update();
    d->sphere->touchProperty();
}

void axlInspectorObjectSphere::onShaderStateChanged(bool isShader)
{
    if(isShader)
    {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());

        //emit dataChangedByShader(d->sphere, d->lineEditShader->text());
    }
    else
    {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);

        d->sphere->setShader("");
        //emit dataChangedByShader(d->sphere, "");
    }
//    emit modifiedProperty(d->sphere, 2);
//    emit update();
    d->sphere->touchProperty();
}

void axlInspectorObjectSphere::onCoordDataChanged_x(double x)
{
    d->sphere->onXChanged(x);

    //emit dataChangedByGeometry(d->sphere);
    d->sphere->touchGeometry();
//    emit update();
}

void axlInspectorObjectSphere::onCoordDataChanged_y(double y)
{
    d->sphere->onYChanged(y);

    //emit dataChangedByGeometry(d->sphere);
    d->sphere->touchGeometry();
//    emit update();
}

void axlInspectorObjectSphere::onCoordDataChanged_z(double z)
{
    d->sphere->onZChanged(z);

    //emit dataChangedByGeometry(d->sphere);
    d->sphere->touchGeometry();
//    emit update();
}

void axlInspectorObjectSphere::onRadiusChanged(double radius)
{
    d->sphere->setRadius(radius);

    //emit dataChangedByGeometry(d->sphere);
    d->sphere->touchGeometry();
//    emit update();
}

void axlInspectorObjectSphere::onColorChanged(QColor color)
{
    QVariant variant = d->sphere->QObject::property("color");
    if(variant.isValid())
    {
        d->sphere->setColor(color);

        //emit dataChangedByColor(d->sphere, color.redF(), color.greenF(), color.blueF());
//        emit modifiedProperty(d->sphere, 0);
        d->sphere->touchProperty();
    }

//    emit update();
}


void axlInspectorObjectSphere::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00

    QVariant variant = d->sphere->QObject::property("opacity");
    if(variant.isValid())
    {
        d->sphere->setOpacity(opacity_d);

        // emit dataChangedByOpacity(d->sphere, opacity_d);
//        emit modifiedProperty(d->sphere, 1);
        d->sphere->touchProperty();
    }

//    emit update();
}


void axlInspectorObjectSphere::updateValues(void)
{
    const QSignalBlocker blockerX(d->coordinate_x);
    const QSignalBlocker blockerY(d->coordinate_y);
    const QSignalBlocker blockerZ(d->coordinate_z);
    const QSignalBlocker blockerRadius(d->radius);

    d->coordinate_x->setValue(d->sphere->x());
    d->coordinate_y->setValue(d->sphere->y());
    d->coordinate_z->setValue(d->sphere->z());
    d->radius->setValue(d->sphere->radius());
}
