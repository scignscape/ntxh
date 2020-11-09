/* axlInspectorObjectMesh.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Mar 18 11:19:52 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Apr  3 14:21:04 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 60
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectMesh.h"
#include "axlParameterSpace.h"

#include <axlCore/axlMesh.h>
#include <axlCore/axlAbstractData.h>
#include <axlCore/axlAbstractDataConverter.h>
#include <axlGui/axlInspectorUtils.h>

#include <dtkCoreSupport/dtkAbstractData.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>


#include <dtkGuiSupport/dtkColorButton.h>
#include <dtkGuiSupport/dtkSplitter.h>

#include <QtGui>

class axlInspectorObjectMeshPrivate
{
public:
    axlAbstractData *data;

    QSlider *sliderSize;

    dtkColorButton *colorButton;
    QComboBox *comboBoxShader;

    QComboBox *comboInterpolation;

    QCheckBox *checkBoxShader;
    QLineEdit *lineEditShader;
    QPushButton *buttonShader;

    QCheckBox *checkBoxPoints;
    QCheckBox *checkBoxUseNormals;
    QCheckBox *checkBoxLines;
    QCheckBox *checkBoxPoly;

    QSlider *sliderOpacity;

};

axlInspectorObjectMesh::axlInspectorObjectMesh(QWidget *parent):
    axlInspectorObjectInterface(parent), //QFrame(parent),
    d(new axlInspectorObjectMeshPrivate)
{
    d->data = NULL;
    d->sliderSize = NULL;
    d->colorButton = NULL;
    d->comboBoxShader = NULL;

    d->comboInterpolation = NULL;

    d->checkBoxShader = NULL;
    d->lineEditShader = NULL;
    d->buttonShader = NULL;

    d->sliderOpacity = NULL;


}

axlInspectorObjectMesh::~axlInspectorObjectMesh(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorObjectMesh::sizeHint(void) const
{
    return QSize(300, 300);
}

void axlInspectorObjectMesh::setData(axlAbstractData *data)
{
    d->data = data;
    initWidget();
    // Detect the data composition
    this->setObjectDataState();
}

void axlInspectorObjectMesh::setObjectDataState(void)
{
    axlMesh *mesh;

    mesh = d->data->mesh();

    if(!mesh){

        if(!(mesh = dynamic_cast<axlMesh *>(d->data)))
        {
            // we have to transform the data in a mesh
            foreach(QString t, dtkAbstractDataFactory::instance()->converters())
            {
                if(!mesh)
                {
                    axlAbstractDataConverter *converter = qobject_cast<axlAbstractDataConverter *>(dtkAbstractDataFactory::instance()->converter(t));
                    if(converter){
                        converter->setData(d->data);
                        mesh = converter->toMesh();
                    }
                }
            }
        } // transform the axlAbstractData into mesh

    }

    if(mesh)
    {
        d->data->setMesh(mesh);
        d->checkBoxPoly->setChecked(mesh->face_show());
        d->checkBoxLines->setChecked(mesh->edge_show());
        d->checkBoxPoints->setChecked(mesh->vertex_show());

        if(mesh->normal_count() == mesh->vertex_count() && mesh->normal_count() != 0)
        {
            if(mesh->normal_used())
                d->checkBoxUseNormals->setChecked(true);
            else
                d->checkBoxUseNormals->setChecked(false);
        }
        else
        {
            d->checkBoxUseNormals->setDisabled(true);
            d->comboInterpolation->setCurrentIndex(0);
            d->comboInterpolation->setDisabled(true);
        }

    }

    // because for now we don't want to edit the checkbox :
    //    d->checkBoxPoints->setDisabled(true);
    //    d->checkBoxLines->setDisabled(true);
    //    d->checkBoxPoly->setDisabled(true);
    //    d->checkBoxUseNormals->setDisabled(true);

}

void axlInspectorObjectMesh::initWidget()
{
    ///////SIZE///////////////

    d->sliderSize = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *layoutSize = new QHBoxLayout;
    layoutSize->addWidget(new QLabel("Size",this));
    layoutSize->addWidget(d->sliderSize);
    d->sliderSize->setMinimum(-800);
    d->sliderSize->setMaximum(500);
    d->sliderSize->setValue(initSizeValue());

    ///////OPACITY///////////////

    d->sliderOpacity = new QSlider(Qt::Horizontal, this);
    d->sliderOpacity->setMaximum(100);
    QHBoxLayout *layoutOpacity = new QHBoxLayout;
    layoutOpacity->addWidget(new QLabel("Opacity",this));
    layoutOpacity->addWidget(d->sliderOpacity);
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

    ///////COLOR///////////////

    d->colorButton = new dtkColorButton(this);
    QHBoxLayout *layoutColorButton = new QHBoxLayout;
    layoutColorButton->addWidget(new QLabel("Color",this));
    layoutColorButton->addWidget(d->colorButton);
    d->colorButton->setColor(this->initColorValue());

    ///////INTERPOLATION///////////
    d->comboInterpolation = new QComboBox(this);
    d->comboInterpolation->setInsertPolicy(QComboBox::InsertAlphabetically);
    d->comboInterpolation->addItems(QStringList()<<"Flat"<<"Gouraud"<<"Phong");
    QHBoxLayout *layoutInterpolationCombobox = new QHBoxLayout;
    layoutInterpolationCombobox->addWidget(new QLabel("Interpolation",this));
    layoutInterpolationCombobox->addWidget(d->comboInterpolation);
    if (axlMesh *meshData = dynamic_cast<axlMesh *>(d->data))
        d->comboInterpolation->setCurrentIndex(meshData->interpolation());

    ///////CHECKBOX///////////////
    d->checkBoxPoints = new QCheckBox(this);
    d->checkBoxLines = new QCheckBox(this);
    d->checkBoxPoly = new QCheckBox(this);
    d->checkBoxUseNormals = new QCheckBox(this);


    QHBoxLayout *layoutPoints = new QHBoxLayout;
    layoutPoints->addWidget(new QLabel("Show Points",this));
    layoutPoints->addWidget(d->checkBoxPoints);

    QHBoxLayout *layoutLines = new QHBoxLayout;
    layoutLines->addWidget(new QLabel("Show Edges",this));
    layoutLines->addWidget(d->checkBoxLines);

    QHBoxLayout *layoutPolygons = new QHBoxLayout;
    layoutPolygons->addWidget(new QLabel("Show Faces",this));
    layoutPolygons->addWidget(d->checkBoxPoly);

    QHBoxLayout *layoutNormals = new QHBoxLayout;
    layoutNormals->addWidget(new QLabel("Use Normals",this));
    layoutNormals->addWidget(d->checkBoxUseNormals);

    ///////GUI///////////////

    QVBoxLayout *layoutTop = new QVBoxLayout;
    layoutTop->addWidget(new QLabel("axlInspectorObjectMesh", this));
    layoutTop->addLayout(layoutColorButton);
    layoutTop->addLayout(layoutSize);
    layoutTop->addLayout(layoutOpacity);
    layoutTop->addLayout(layoutShader);
    layoutTop->addLayout(layoutInterpolationCombobox);
    layoutTop->addLayout(layoutPoints);
    layoutTop->addLayout(layoutLines);
    layoutTop->addLayout(layoutPolygons);
    layoutTop->addLayout(layoutNormals);
    layoutTop->addStretch(1);

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


    connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onColorChanged(QColor)));
    connect(d->sliderSize, SIGNAL(valueChanged(int)), this, SLOT(onSizeChanged(int)));
    connect(d->sliderOpacity, SIGNAL(valueChanged(int)), this, SLOT(onOpacityChanged(int)));
    connect(d->comboBoxShader, SIGNAL(currentIndexChanged(QString)), this, SLOT(onLineEditShaderChanged(QString)));
    connect(d->comboInterpolation, SIGNAL(currentIndexChanged(int)), this, SLOT(onInterpolationChanged(int)));
    connect(d->checkBoxShader, SIGNAL(clicked(bool)), this, SLOT(onShaderStateChanged(bool)));
    connect(d->buttonShader, SIGNAL(clicked()), this, SLOT(openShader()));
    connect(d->lineEditShader, SIGNAL(textChanged(QString)), this, SLOT(onShaderChanged(QString)));

    connect(d->checkBoxPoints, SIGNAL(clicked()), this, SLOT(onUpdateGeometry()));
    connect(d->checkBoxLines, SIGNAL(clicked()), this, SLOT(onUpdateGeometry()));
    connect(d->checkBoxPoly, SIGNAL(clicked()), this, SLOT(onUpdateGeometry()));
    connect(d->checkBoxUseNormals, SIGNAL(clicked()), this, SLOT(onUpdateGeometry()));

}


int axlInspectorObjectMesh::initSizeValue(void)
{
    double initSize = 100.0*(log(d->data->size()/0.125))/log(2.0);
    //    if(initSize > 10.0)
    //        initSize = 10;
    //    else if(initSize < 0.0)
    //        initSize = 0;

    return initSize;
}

void axlInspectorObjectMesh::initComboBoxShaderValue(void)
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

void axlInspectorObjectMesh::onLineEditShaderChanged(QString shader)
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

void axlInspectorObjectMesh::onInterpolationChanged(int modeInterpolation)
{
    if (axlMesh *meshData = dynamic_cast<axlMesh *>(d->data))
        meshData->setInterpolation(modeInterpolation);

    if (modeInterpolation == 0 && d->checkBoxUseNormals->checkState()){
        d->checkBoxUseNormals->setChecked(false);
        this->onUpdateGeometry();
    } else if (modeInterpolation > 0 && (!d->checkBoxUseNormals->checkState())){
        d->checkBoxUseNormals->setChecked(true);
        this->onUpdateGeometry();
    }

    emit interpolationChanded(d->data, modeInterpolation);
    emit update();
}

QString axlInspectorObjectMesh::initShaderValue(void)
{
    return  d->data->shader();
}


QColor axlInspectorObjectMesh::initColorValue(void)
{
    return d->data->color();
}

int axlInspectorObjectMesh::initOpacityValue(void)
{
    double initOpacity = 0.0;
    double opacity = d->data->opacity();
    if(opacity > initOpacity)
        initOpacity = opacity;

    return 100 * (1.0 - initOpacity);
}

void axlInspectorObjectMesh::onColorChanged(QColor color)
{
    d->data->setColor(color);

    //    emit dataChangedByColor(d->data, color.redF(), color.greenF(), color.blueF());
//    emit modifiedProperty(d->data, 0);
    d->data->touchProperty();
//    emit update();
}

void axlInspectorObjectMesh::openShader()
{
    if(d->lineEditShader->isEnabled())
    {
        QString fileToOpen;
        fileToOpen = QFileDialog::getOpenFileName(this, tr("Open shader"), "", tr("vs file (*.vs)"));
        d->lineEditShader->setText(fileToOpen);
    }
}

void axlInspectorObjectMesh::onShaderChanged(QString shader)
{
    d->data->setShader(shader);

    //    emit dataChangedByShader(d->data, d->lineEditShader->text());
//    emit modifiedProperty(d->data, AXL_PROPERTY_SHADER);
    d->data->touchProperty();
//    emit update();
}

void axlInspectorObjectMesh::onShaderStateChanged(bool isShader)
{
    if(isShader)
    {
        d->comboBoxShader->setEnabled(true);
        d->lineEditShader->setEnabled(true);
        d->buttonShader->setEnabled(true);
        onLineEditShaderChanged(d->comboBoxShader->currentText());

        d->data->setShader(d->lineEditShader->text());
        //        emit dataChangedByShader(d->data, d->lineEditShader->text());
    }
    else
    {
        d->comboBoxShader->setEnabled(false);
        d->lineEditShader->setEnabled(false);
        d->buttonShader->setEnabled(false);

        d->data->setShader("");
        //        emit dataChangedByShader(d->data, "");
    }

//    emit modifiedProperty(d->data, AXL_PROPERTY_SHADER);
//    emit update();
    d->data->touchProperty();
}

void axlInspectorObjectMesh::onSizeChanged(int size)
{
    double size_d = pow(2.0, size/100.0 - 3.0);
    QVariant variant = d->data->QObject::property("size");
    if(variant.isValid())
    {
        d->data->setSize(size_d);
        if(d->data->mesh()){
            d->data->mesh()->setSize(size_d);
        }
    }else {
        if(d->data->mesh()){
            d->data->mesh()->setSize(size_d);
        }
    }
    emit modifiedProperty(d->data, AXL_PROPERTY_SIZE);
}

void axlInspectorObjectMesh::onOpacityChanged(int opacity)
{
    double opacity_d = 1.0 - 0.01 * opacity; // range from 0.00 to 1.00
    d->data->setOpacity(opacity_d);
    d->data->touchProperty();
    //    emit dataChangedByOpacity(d->data, opacity_d);
//    emit modifiedProperty(d->data, AXL_PROPERTY_OPACITY);
//    emit update();
}

void axlInspectorObjectMesh::onUpdateGeometry(void) {
    axlMesh* mesh = NULL;

    if ((mesh = dynamic_cast<axlMesh*>(d->data))) {
        mesh->vertex_show() = d->checkBoxPoints->isChecked();
        mesh->normal_used() = d->checkBoxUseNormals->isChecked();
        mesh->edge_show() = d->checkBoxLines->isChecked();
        mesh->face_show() = d->checkBoxPoly->isChecked();
        if (!mesh->normal_used())
                d->comboInterpolation->setCurrentIndex(0);
        else
            if (d->comboInterpolation->currentIndex()==0)
                d->comboInterpolation->setCurrentIndex(2);

        d->data->touchGeometry();
    }else{
        if(d->data->mesh()){
            d->data->mesh()->vertex_show() = d->checkBoxPoints->isChecked();
            d->data->mesh()->normal_used() = d->checkBoxUseNormals->isChecked();
            d->data->mesh()->edge_show() = d->checkBoxLines->isChecked();
            d->data->mesh()->face_show() = d->checkBoxPoly->isChecked();
            if (!d->data->mesh()->normal_used())
                d->comboInterpolation->setCurrentIndex(0);
            else
                if (d->comboInterpolation->currentIndex()==0)
                    d->comboInterpolation->setCurrentIndex(2);
            d->data->mesh()->touchGeometry();
        }
    }

//    emit dataChangedByGeometry(d->data);

//    emit update();
}
