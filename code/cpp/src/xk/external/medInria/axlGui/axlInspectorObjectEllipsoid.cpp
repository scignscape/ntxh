/* axlInspectorObjectEllipsoid.cpp ---
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

#include "axlInspectorObjectEllipsoid.h"

#include <axlCore/axlEllipsoid.h>
#include <axlCore/axlPoint.h>
#include <axlGui/axlInspectorUtils.h>

#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectEllipsoidPrivate
{
public:
    axlEllipsoid *ellipsoid;

    QDoubleSpinBox *center_x;
    QDoubleSpinBox *center_y;
    QDoubleSpinBox *center_z;
    QDoubleSpinBox *semix;
    QDoubleSpinBox *semix_x;
    QDoubleSpinBox *semix_y;
    QDoubleSpinBox *semix_z;
    QDoubleSpinBox *semiy;
    QDoubleSpinBox *semiy_x;
    QDoubleSpinBox *semiy_y;
    QDoubleSpinBox *semiy_z;
    QDoubleSpinBox *semiz;
    QDoubleSpinBox *semiz_x;
    QDoubleSpinBox *semiz_y;
    QDoubleSpinBox *semiz_z;

    dtkColorButton *colorButton;

    QComboBox *comboBoxShader;
    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QSlider *sliderOpacity;
};

axlInspectorObjectEllipsoid::axlInspectorObjectEllipsoid(QWidget *parent) :
    axlInspectorObjectInterface(parent),
    //QFrame(parent),
    d(new axlInspectorObjectEllipsoidPrivate)
{
    d->center_x = NULL;
    d->center_y = NULL;
    d->center_z = NULL;
    d->semix = NULL;
    d->semix_x = NULL;
    d->semix_y = NULL;
    d->semix_z = NULL;
    d->semiy = NULL;
    d->semiy_x = NULL;
    d->semiy_y = NULL;
    d->semiy_z = NULL;
    d->semiz = NULL;
    d->semiz_x = NULL;
    d->semiz_y = NULL;
    d->semiz_z = NULL;

    d->colorButton = NULL;

    d->comboBoxShader = NULL;
    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;
}

axlInspectorObjectEllipsoid::~axlInspectorObjectEllipsoid(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectEllipsoid::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectEllipsoid::setData(axlEllipsoid *ellipsoid)
{
    d->ellipsoid = ellipsoid;
    connect(d->ellipsoid, SIGNAL(modifiedGeometry(void)), this, SLOT(updateValues(void)));
    initWidget();
}

void axlInspectorObjectEllipsoid::initWidget()
{
    QVBoxLayout *layoutTop = new QVBoxLayout(this);
    layoutTop->addWidget(new QLabel("axlInspectorObjectEllipsoid", this));

    ///////CENTER///////////////

    d->center_x = new QDoubleSpinBox(this);
    d->center_x->setRange(-1000, 1000);
    d->center_x->setValue(d->ellipsoid->center()->x());
    d->center_x->setSingleStep(0.1);

    d->center_y = new QDoubleSpinBox(this);
    d->center_y->setRange(-1000, 1000);
    d->center_y->setValue(d->ellipsoid->center()->y());
    d->center_y->setSingleStep(0.1);

    d->center_z = new QDoubleSpinBox(this);
    d->center_z->setRange(-1000, 1000);
    d->center_z->setValue(d->ellipsoid->center()->z());
    d->center_z->setSingleStep(0.1);

    QHBoxLayout *layoutCenter_x = new QHBoxLayout;
    layoutCenter_x->addWidget(new QLabel("X",this));
    layoutCenter_x->addWidget(d->center_x);

    QHBoxLayout *layoutCenter_y = new QHBoxLayout;
    layoutCenter_y->addWidget(new QLabel("Y",this));
    layoutCenter_y->addWidget(d->center_y);

    QHBoxLayout *layoutCenter_z = new QHBoxLayout;
    layoutCenter_z->addWidget(new QLabel("Z",this));
    layoutCenter_z->addWidget(d->center_z);

    QVBoxLayout* layoutCenter = new QVBoxLayout;
    layoutCenter->addLayout(layoutCenter_x);
    layoutCenter->addLayout(layoutCenter_y);
    layoutCenter->addLayout(layoutCenter_z);

    QGroupBox* centerGroupBox = new QGroupBox("Center");
    centerGroupBox->setLayout(layoutCenter);

    ///////SEMIX///////////////

    d->semix = new QDoubleSpinBox(this);
    d->semix->setRange(-1000, 1000);
    d->semix->setValue(d->ellipsoid->semiX()->norm());
    d->semix->setSingleStep(0.1);

    d->semix_x = new QDoubleSpinBox(this);
    d->semix_x->setRange(-1000, 1000);
    d->semix_x->setValue(d->ellipsoid->semiX()->x());
    d->semix_x->setSingleStep(0.1);

    d->semix_y = new QDoubleSpinBox(this);
    d->semix_y->setRange(-1000, 1000);
    d->semix_y->setValue(d->ellipsoid->semiX()->y());
    d->semix_y->setSingleStep(0.1);

    d->semix_z = new QDoubleSpinBox(this);
    d->semix_z->setRange(-1000, 1000);
    d->semix_z->setValue(d->ellipsoid->semiX()->z());
    d->semix_z->setSingleStep(0.1);

    QHBoxLayout *layoutSemixRadius = new QHBoxLayout;
    layoutSemixRadius->addWidget(new QLabel("X radius", this));
    layoutSemixRadius->addWidget(d->semix);

    QHBoxLayout *layoutSemix_x = new QHBoxLayout;
    layoutSemix_x->addWidget(new QLabel("X",this));
    layoutSemix_x->addWidget(d->semix_x);

    QHBoxLayout *layoutSemix_y = new QHBoxLayout;
    layoutSemix_y->addWidget(new QLabel("Y",this));
    layoutSemix_y->addWidget(d->semix_y);

    QHBoxLayout *layoutSemix_z = new QHBoxLayout;
    layoutSemix_z->addWidget(new QLabel("Z",this));
    layoutSemix_z->addWidget(d->semix_z);

    QVBoxLayout* layoutSemiX = new QVBoxLayout;
    layoutSemiX->addLayout(layoutSemixRadius);
    layoutSemiX->addLayout(layoutSemix_x);
    layoutSemiX->addLayout(layoutSemix_y);
    layoutSemiX->addLayout(layoutSemix_z);

    QGroupBox* semiXGroupBox = new QGroupBox("Semi Axis X");
    semiXGroupBox->setLayout(layoutSemiX);

    ///////SEMIY///////////////

    d->semiy = new QDoubleSpinBox(this);
    d->semiy->setRange(-1000, 1000);
    d->semiy->setValue(d->ellipsoid->semiY()->norm());
    d->semiy->setSingleStep(0.1);

    d->semiy_x = new QDoubleSpinBox(this);
    d->semiy_x->setRange(-1000, 1000);
    d->semiy_x->setValue(d->ellipsoid->semiY()->x());
    d->semiy_x->setSingleStep(0.1);

    d->semiy_y = new QDoubleSpinBox(this);
    d->semiy_y->setRange(-1000, 1000);
    d->semiy_y->setValue(d->ellipsoid->semiY()->y());
    d->semiy_y->setSingleStep(0.1);

    d->semiy_z = new QDoubleSpinBox(this);
    d->semiy_z->setRange(-1000, 1000);
    d->semiy_z->setValue(d->ellipsoid->semiY()->z());
    d->semiy_z->setSingleStep(0.1);

    QHBoxLayout *layoutSemiyRadius = new QHBoxLayout;
    layoutSemiyRadius->addWidget(new QLabel("Y radius", this));
    layoutSemiyRadius->addWidget(d->semiy);

    QHBoxLayout *layoutSemiy_x = new QHBoxLayout;
    layoutSemiy_x->addWidget(new QLabel("X",this));
    layoutSemiy_x->addWidget(d->semiy_x);

    QHBoxLayout *layoutSemiy_y = new QHBoxLayout;
    layoutSemiy_y->addWidget(new QLabel("Y",this));
    layoutSemiy_y->addWidget(d->semiy_y);

    QHBoxLayout *layoutSemiy_z = new QHBoxLayout;
    layoutSemiy_z->addWidget(new QLabel("Z",this));
    layoutSemiy_z->addWidget(d->semiy_z);

    QVBoxLayout* layoutSemiY = new QVBoxLayout;
    layoutSemiY->addLayout(layoutSemiyRadius);
    layoutSemiY->addLayout(layoutSemiy_x);
    layoutSemiY->addLayout(layoutSemiy_y);
    layoutSemiY->addLayout(layoutSemiy_z);

    QGroupBox* semiYGroupBox = new QGroupBox("Semi Axis Y");
    semiYGroupBox->setLayout(layoutSemiY);

    ///////SEMIZ///////////////

    d->semiz = new QDoubleSpinBox(this);
    d->semiz->setRange(-1000, 1000);
    d->semiz->setValue(d->ellipsoid->semiZ()->norm());
    d->semiz->setSingleStep(0.1);

    d->semiz_x = new QDoubleSpinBox(this);
    d->semiz_x->setRange(-1000, 1000);
    d->semiz_x->setValue(d->ellipsoid->semiZ()->x());
    d->semiz_x->setSingleStep(0.1);

    d->semiz_y = new QDoubleSpinBox(this);
    d->semiz_y->setRange(-1000, 1000);
    d->semiz_y->setValue(d->ellipsoid->semiZ()->y());
    d->semiz_y->setSingleStep(0.1);

    d->semiz_z = new QDoubleSpinBox(this);
    d->semiz_z->setRange(-1000, 1000);
    d->semiz_z->setValue(d->ellipsoid->semiZ()->z());
    d->semiz_z->setSingleStep(0.1);

    QHBoxLayout *layoutSemizRadius = new QHBoxLayout;
    layoutSemizRadius->addWidget(new QLabel("Z radius", this));
    layoutSemizRadius->addWidget(d->semiz);

    QHBoxLayout *layoutSemiz_x = new QHBoxLayout;
    layoutSemiz_x->addWidget(new QLabel("X",this));
    layoutSemiz_x->addWidget(d->semiz_x);

    QHBoxLayout *layoutSemiz_y = new QHBoxLayout;
    layoutSemiz_y->addWidget(new QLabel("Y",this));
    layoutSemiz_y->addWidget(d->semiz_y);

    QHBoxLayout *layoutSemiz_z = new QHBoxLayout;
    layoutSemiz_z->addWidget(new QLabel("Z",this));
    layoutSemiz_z->addWidget(d->semiz_z);

    QVBoxLayout* layoutSemiZ = new QVBoxLayout;
    layoutSemiZ->addLayout(layoutSemizRadius);
    layoutSemiZ->addLayout(layoutSemiz_x);
    layoutSemiZ->addLayout(layoutSemiz_y);
    layoutSemiZ->addLayout(layoutSemiz_z);

    QGroupBox* semiZGroupBox = new QGroupBox("Semi Axis Z");
    semiZGroupBox->setLayout(layoutSemiZ);

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

    layoutTop->addWidget(centerGroupBox);
    layoutTop->addWidget(semiXGroupBox);
    layoutTop->addWidget(semiYGroupBox);
    layoutTop->addWidget(semiZGroupBox);

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

    ///////CONNECTIONS///////////////

    connect(d->center_x, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChanged_x(double)));
    connect(d->center_y, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChanged_y(double)));
    connect(d->center_z, SIGNAL(valueChanged(double)), this, SLOT(onCoordDataChanged_z(double)));

    connect(d->semix, SIGNAL(valueChanged(double)), this, SLOT(onUpdateSemix(double)));
    connect(d->semiy, SIGNAL(valueChanged(double)), this, SLOT(onUpdateSemiy(double)));
    connect(d->semiz, SIGNAL(valueChanged(double)), this, SLOT(onUpdateSemiz(double)));


    connect(d->semix_x, SIGNAL(valueChanged(double)), this, SLOT(onSemiXDataChanged(double)));
    connect(d->semix_y, SIGNAL(valueChanged(double)), this, SLOT(onSemiXDataChanged(double)));
    connect(d->semix_z, SIGNAL(valueChanged(double)), this, SLOT(onSemiXDataChanged(double)));

    connect(d->semiy_x, SIGNAL(valueChanged(double)), this, SLOT(onSemiYDataChanged(double)));
    connect(d->semiy_y, SIGNAL(valueChanged(double)), this, SLOT(onSemiYDataChanged(double)));
    connect(d->semiy_z, SIGNAL(valueChanged(double)), this, SLOT(onSemiYDataChanged(double)));

    connect(d->semiz_x, SIGNAL(valueChanged(double)), this, SLOT(onSemiZDataChanged(double)));
    connect(d->semiz_y, SIGNAL(valueChanged(double)), this, SLOT(onSemiZDataChanged(double)));
    connect(d->semiz_z, SIGNAL(valueChanged(double)), this, SLOT(onSemiZDataChanged(double)));

    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));

    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));
    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));
    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));
    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));

}

void axlInspectorObjectEllipsoid::updateValues(void)
{
//    this->blockSignals(true);
    const QSignalBlocker blockerCenterX(d->center_x);
    const QSignalBlocker blockerCenterY(d->center_y);
    const QSignalBlocker blockerCenterZ(d->center_z);
    const QSignalBlocker blockerSemiX_X(d->semix_x);
    const QSignalBlocker blockerSemiX_Y(d->semix_y);
    const QSignalBlocker blockerSemiX_Z(d->semix_z);
    const QSignalBlocker blockerSemiY_X(d->semiy_x);
    const QSignalBlocker blockerSemiY_Y(d->semiy_y);
    const QSignalBlocker blockerSemiY_Z(d->semiy_z);
    const QSignalBlocker blockerSemiZ_X(d->semiz_x);
    const QSignalBlocker blockerSemiZ_Y(d->semiz_y);
    const QSignalBlocker blockerSemiZ_Z(d->semiz_z);

    d->center_x->setValue(d->ellipsoid->center()->x());
    d->center_y->setValue(d->ellipsoid->center()->y());
    d->center_z->setValue(d->ellipsoid->center()->z());
    d->semix_x->setValue(d->ellipsoid->semiX()->x());
    d->semix_y->setValue(d->ellipsoid->semiX()->y());
    d->semix_z->setValue(d->ellipsoid->semiX()->z());
    d->semiy_x->setValue(d->ellipsoid->semiY()->x());
    d->semiy_y->setValue(d->ellipsoid->semiY()->y());
    d->semiy_z->setValue(d->ellipsoid->semiY()->z());
    d->semiz_x->setValue(d->ellipsoid->semiZ()->x());
    d->semiz_y->setValue(d->ellipsoid->semiZ()->y());
    d->semiz_z->setValue(d->ellipsoid->semiZ()->z());
//    this->blockSignals(false);
}

void axlInspectorObjectEllipsoid::initComboBoxShaderValue(void)
{
    if(d->comboBoxShader) {

        QStringList filters;
        filters << "*.vs";

        // First add item of axlShader.qrc, then find shader from shader path
        QDir dirShader(":axlShader/shader/");
        dirShader.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

        dirShader.setNameFilters(filters);

        QFileInfoList list = dirShader.entryInfoList();

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

void axlInspectorObjectEllipsoid::onLineEditShaderChanged(QString shader)
{
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

QString axlInspectorObjectEllipsoid::initShaderValue(void)
{
    return  d->ellipsoid->shader();
}

QColor axlInspectorObjectEllipsoid::initColorValue(void)
{
    return d->ellipsoid->color();
}

int axlInspectorObjectEllipsoid::initOpacityValue(void)
{
    double initOpacity = 0.0;
    double opacity = d->ellipsoid->opacity();

    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectEllipsoid::openShader()
{
    if(d->lineEditShader->isEnabled()) {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("vs file (*.vs)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectEllipsoid::onShaderChanged(QString shader)
{
    d->ellipsoid->setShader(shader);

//    emit modifiedProperty(d->ellipsoid, 2);
//    emit update();
    d->ellipsoid->touchProperty();
}

void axlInspectorObjectEllipsoid::onShaderStateChanged(bool isShader)
{
    if(isShader) {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());
    } else {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);
        d->ellipsoid->setShader("");
    }

//    emit modifiedProperty(d->ellipsoid, 2);
//    emit update();
    d->ellipsoid->touchProperty();
}

void axlInspectorObjectEllipsoid::onCoordDataChanged_x(double x)
{
    d->ellipsoid->modifyCenterX(x);
    d->ellipsoid->touchGeometry();

//    emit dataChangedByGeometry(d->ellipsoid);
//    emit update();
}

void axlInspectorObjectEllipsoid::onCoordDataChanged_y(double y)
{
    d->ellipsoid->modifyCenterY(y);
    d->ellipsoid->touchGeometry();

//    emit dataChangedByGeometry(d->ellipsoid);
//    emit update();
}

void axlInspectorObjectEllipsoid::onCoordDataChanged_z(double z)
{
    d->ellipsoid->modifyCenterZ(z);
    d->ellipsoid->touchGeometry();

//    emit dataChangedByGeometry(d->ellipsoid);
//    emit update();
}

void axlInspectorObjectEllipsoid::onSemiXDataChanged(double)
{
    axlPoint semix(d->semix_x->value(), d->semix_y->value(), d->semix_z->value());

    d->ellipsoid->modifySemiX(semix.coordinates());
    d->ellipsoid->calculateYZ();

    updateDataNoSignals();

    d->ellipsoid->touchGeometry();

//    emit dataChangedByGeometry(d->ellipsoid);
//    emit update();
}

void axlInspectorObjectEllipsoid::onSemiYDataChanged(double)
{
    axlPoint semiy(d->semiy_x->value(), d->semiy_y->value(), d->semiy_z->value());

    d->ellipsoid->modifySemiY(semiy.coordinates());
    d->ellipsoid->calculateXZ();

    updateDataNoSignals();

    d->ellipsoid->touchGeometry();

//    emit dataChangedByGeometry(d->ellipsoid);
//    emit update();
}

void axlInspectorObjectEllipsoid::onSemiZDataChanged(double)
{
    axlPoint semiz(d->semiz_x->value(), d->semiz_y->value(), d->semiz_z->value());

    d->ellipsoid->modifySemiZ(semiz.coordinates());
    d->ellipsoid->calculateXY();

    updateDataNoSignals();

    d->ellipsoid->touchGeometry();

//    emit dataChangedByGeometry(d->ellipsoid);
//    emit update();
}

void axlInspectorObjectEllipsoid::updateDataNoSignals()
{
    this->blockSignals(true);

    d->semix->setValue(d->ellipsoid->semiX()->norm());
    d->semix_x->setValue(d->ellipsoid->semiX()->x());
    d->semix_y->setValue(d->ellipsoid->semiX()->y());
    d->semix_z->setValue(d->ellipsoid->semiX()->z());
    d->semiy->setValue(d->ellipsoid->semiY()->norm());
    d->semiy_x->setValue(d->ellipsoid->semiY()->x());
    d->semiy_y->setValue(d->ellipsoid->semiY()->y());
    d->semiy_z->setValue(d->ellipsoid->semiY()->z());
    d->semiz->setValue(d->ellipsoid->semiZ()->norm());
    d->semiz_x->setValue(d->ellipsoid->semiZ()->x());
    d->semiz_y->setValue(d->ellipsoid->semiZ()->y());
    d->semiz_z->setValue(d->ellipsoid->semiZ()->z());

    this->blockSignals(false);
}

void axlInspectorObjectEllipsoid::onUpdateSemix(double radius)
{
    axlPoint semix(d->semix_x->value(), d->semix_y->value(), d->semix_z->value());

    semix.normalize();
    semix *= radius;

    this->blockSignals(true);

    d->semix_x->setValue(semix.x());
    d->semix_y->setValue(semix.y());
    d->semix_z->setValue(semix.z());

    this->blockSignals(false);

    d->ellipsoid->modifySemiX(semix.coordinates());
    d->ellipsoid->touchGeometry();

//    emit dataChangedByGeometry(d->ellipsoid);
//    emit update();
}

void axlInspectorObjectEllipsoid::onUpdateSemiy(double radius)
{
    axlPoint semiy(d->semiy_x->value(), d->semiy_y->value(), d->semiy_z->value());

    semiy.normalize();
    semiy *= radius;

    this->blockSignals(true);

    d->semiy_x->setValue(semiy.x());
    d->semiy_y->setValue(semiy.y());
    d->semiy_z->setValue(semiy.z());

    this->blockSignals(false);

    d->ellipsoid->modifySemiY(semiy.coordinates());
    d->ellipsoid->touchGeometry();

//    emit dataChangedByGeometry(d->ellipsoid);
//    emit update();
}

void axlInspectorObjectEllipsoid::onUpdateSemiz(double radius)
{
    axlPoint semiz(d->semiz_x->value(), d->semiz_y->value(), d->semiz_z->value());

    semiz.normalize();
    semiz *= radius;

    this->blockSignals(true);

    d->semiz_x->setValue(semiz.x());
    d->semiz_y->setValue(semiz.y());
    d->semiz_z->setValue(semiz.z());

    this-> blockSignals(false);

    d->ellipsoid->modifySemiZ(semiz.coordinates());
    d->ellipsoid->touchGeometry();

//    emit dataChangedByGeometry(d->ellipsoid);
//    emit update();
}

void axlInspectorObjectEllipsoid::onColorChanged(QColor color)
{
    QVariant variant = d->ellipsoid->QObject::property("color");

    if(variant.isValid())
    {
        d->ellipsoid->setColor(color);

//        emit modifiedProperty(d->ellipsoid, 0);
        d->ellipsoid->touchProperty();
    }

//    emit update();
}

void axlInspectorObjectEllipsoid::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity;

    QVariant variant = d->ellipsoid->QObject::property("opacity");

    if(variant.isValid())
    {
        d->ellipsoid->setOpacity(opacity_d);

//        emit modifiedProperty(d->ellipsoid, 1);
        d->ellipsoid->touchProperty();
    }

//    emit update();
}
