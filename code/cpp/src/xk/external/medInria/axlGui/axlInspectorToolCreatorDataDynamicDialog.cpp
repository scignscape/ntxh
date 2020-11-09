/* axlInspectorToolCreatorDataDynamicDialog.cpp ---
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

#include "axlInspectorToolCreatorDataDynamicDialog.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlAbstractData.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <axlCore/axlAbstractProcess.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include "axlInspectorToolFactory.h"
#include "axlInspectorToolCreator.h"

#include <QtGui>

class axlInspectorToolCreatorDataDynamicDialogPrivate
{
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QLineEdit *process_name;
    QLineEdit *listDoubleValues;

    //display number of double inputs needed and their meanings.
    QLabel *messageToDisplay;
    QLabel *errorMessage;

    //main frame
    QVBoxLayout *layout;

    //process dialog
    axlInspectorToolInterface *dialog;

    //determine if it is a dynamic object or a computation node
    QCheckBox *isStatic;

};

axlInspectorToolCreatorDataDynamicDialog::axlInspectorToolCreatorDataDynamicDialog(QWidget *parent) : QFrame(parent), d(new axlInspectorToolCreatorDataDynamicDialogPrivate)
{

    d->dialog = new axlInspectorToolInterface(this);
    //    d->dialog->setImplementation("axlLineCreator");
    d->dialog->hide();

    d->layout = new QVBoxLayout(this);

    //OPACITY//
    d->sliderOpacity = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *layoutOpacity = new QHBoxLayout;
    layoutOpacity->addWidget(new QLabel("Opacity",this));
    layoutOpacity->addWidget(d->sliderOpacity);
    d->sliderOpacity->setMaximum(100);

    //COLOR//
    d->colorButton = new dtkColorButton(this);

    QHBoxLayout *layoutColorButton = new QHBoxLayout;
    layoutColorButton->addWidget(new QLabel("Color",this));
    layoutColorButton->addWidget(d->colorButton);
    d->colorButton->setColor(QColor("#a0a0a4"));

    // PROCESS NAME
    QHBoxLayout *layoutProcessName = new QHBoxLayout;
    layoutProcessName->addWidget(new QLabel("Process name",this));
    d->process_name = new QLineEdit(this);
    QCompleter *completer = new QCompleter(dtkAbstractProcessFactory::instance()->creators(), this);
    completer->setCaseSensitivity(Qt::CaseSensitive);
    d->process_name->setCompleter(completer);

    layoutProcessName->addWidget(d->process_name);
    connect(d->process_name, SIGNAL(textChanged(QString)), this, SLOT(setProcessName()));

    // DOUBLE VALUES
    QHBoxLayout *layoutDoubleValues = new QHBoxLayout;
    QLabel *labelParameters = new QLabel("double inputs values",this);
    layoutDoubleValues->addWidget(labelParameters);
    d->listDoubleValues = new QLineEdit(this);
    layoutDoubleValues->addWidget(d->listDoubleValues);

    // DOUBLE NAMES
    d->messageToDisplay = new QLabel("", this);
    d->messageToDisplay->setStyleSheet("color: #ff0000;");
    d->messageToDisplay->setVisible(false);// on ne l'affiche qu'en cas de besoin

    // ERROR MESSAGE
    d->errorMessage = new QLabel("wrong inputs number or type,\n please select them as describe above");
    d->errorMessage->setStyleSheet("color: #ff0000;");
    d->errorMessage->setVisible(false);// on ne l'affiche qu'en cas de besoin

    // checkbox
    QHBoxLayout *layoutIsDynamic = new QHBoxLayout(this);
    QLabel *labelIsStatic = new QLabel("static",this);
    layoutIsDynamic->addWidget(labelIsStatic);
    d->isStatic = new QCheckBox(this);
    layoutIsDynamic->addWidget(d->isStatic);


    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    d->layout->addWidget(new QLabel("axlInspectorToolCreatorDataDynamic", this));
    d->layout->addLayout(layoutOpacity);
    d->layout->addLayout(layoutColorButton);
    d->layout->addLayout(layoutProcessName);
    d->layout->addWidget(d->messageToDisplay);
    d->layout->addLayout(layoutDoubleValues);
    d->layout->addWidget(d->dialog);
    d->layout->addLayout(layoutIsDynamic);
    d->layout->addWidget(button);
    d->layout->addWidget(d->errorMessage);

    d->listDoubleValues->hide();
    labelParameters->hide();

}

//! Delete the dialog.
/*!
 *
 */
axlInspectorToolCreatorDataDynamicDialog::~axlInspectorToolCreatorDataDynamicDialog(void)
{
    delete d;

    d = NULL;
}

//! Assigns a controller.
/*!
 *
 */
void axlInspectorToolCreatorDataDynamicDialog::setController(axlInspectorObjectController *controller)
{
    d->controller = controller;
    d->dialog->setController(controller);
}



//! Checks if the process exits and then display appropriated dialog to enter and select inputs.
/*!
 *
 */
void axlInspectorToolCreatorDataDynamicDialog::setProcessName(void){

    if(d->dialog)
        d->dialog->hide();
    // list process inputs needed
    QString processName = d->process_name->text();

    if(!processName.isEmpty()){
        axlAbstractProcess *process = dynamic_cast<axlAbstractProcess *>(dtkAbstractProcessFactory::instance()->create(processName));
        if(process){
            axlInspectorToolInterface *newDialog =  axlInspectorToolFactory::instance()->create(process->identifier());
            if(newDialog){
                //                d->messageToDisplay->setText(process->description());
                //                d->messageToDisplay->show();
                d->layout->removeWidget(d->dialog);
                delete d->dialog;
                d->dialog = NULL;
                //                delete newDialog;
                //                d->dialog->setImplementation(process->identifier());
                d->dialog = newDialog;
                d->dialog->setController(d->controller);
                d->messageToDisplay->hide();
                d->listDoubleValues->hide();
                //utiliser le dialog du process
                if(dynamic_cast<axlInspectorToolCreator *>(d->dialog))
                    dynamic_cast<axlInspectorToolCreator *>(d->dialog)->setController(d->controller);
                else
                    d->dialog->setController(d->controller);

                QObjectList listChildren = d->dialog->children();
                for(int i = 0; i < listChildren.size();i++){
                    if(dynamic_cast<QPushButton *>(listChildren.at(i)) /*&& !dynamic_cast<dtkColorButton *>(listChildren.at(i))*/ ){
                        dynamic_cast<QWidget *>(listChildren.at(i))->hide();
                    }else if(dynamic_cast<QSlider *>(listChildren.at(i))){
                        dynamic_cast<QWidget *>(listChildren.at(i))->hide();
                    }else if(dynamic_cast<QLabel *>(listChildren.at(i))){
                        if(dynamic_cast<QLabel *>(listChildren.at(i))->text() == "Opacity" || dynamic_cast<QLabel *>(listChildren.at(i))->text() == "Color")
                            dynamic_cast<QWidget *>(listChildren.at(i))->hide();
                    }
                }
                //                for(int j = 0;j < listChildren.size();j++){
                //                    if(dynamic_cast<axlInspectorToolInterface *>(listChildren.at(j)))
                //                        qDebug() << "axlInspectorToolCreatorDataDynamicDialog::setProcessName" <<  j;
                //                }

                d->layout->insertWidget(6, d->dialog);
                d->dialog->show();

            }else{
                QString textToDisplay ;
                textToDisplay.append(process->description());
                //si le process necessite des parameters
                if(process->hasParameters())
                    textToDisplay.append("\n double inputs values: ");
                d->messageToDisplay->setText(textToDisplay);
                d->messageToDisplay->show();
                if(process->hasParameters())
                    d->listDoubleValues->show();

            }
        }else{
            d->listDoubleValues->hide();
            d->messageToDisplay->setText("This process doesn't exist");
            d->messageToDisplay->show();
        }
        delete process;
    }
}

//! Create the dynamic Object when the create button is clicked
/*!
 *
 */
void axlInspectorToolCreatorDataDynamicDialog::run(void)
{
    d->errorMessage->hide();
    axlDataDynamic *dynamicData = new axlDataDynamic();
    //create right process
    QString processName = d->process_name->text();
    if(!processName.isEmpty()){
        dynamicData->setProcess(processName);
    }

    //check if it is a computation node or a dynamic object.
    if(d->isStatic->isChecked()){
        dynamicData->setType(axlDataDynamic::Static);
    }

    if(dynamicData->process()){
        //setting inputs data
        //first by selecting inputs data in the axlinspectorObjectTree
        foreach(axlInspectorObjectManagerTreeItem *item, d->controller->items()) {

            if(item->text(2) == "Selected"|| item->text(2) == "Editable")
            {
                if(dynamic_cast<axlAbstractData *>(d->controller->data(item))) {
                    if(axlDataDynamic *axldata = dynamic_cast<axlDataDynamic *>(d->controller->data(item)))
                        dynamicData->setInput(axldata->outputs());
                    else
                        dynamicData->setInput(d->controller->data(item));
                }
            }

        }

        //setting inputs numbers (parameters)
        QString doubleValues = d->listDoubleValues->text();
        if(d->listDoubleValues->isVisible() && !doubleValues.isEmpty()){
            int sizeList = doubleValues.size();
            int indice = 0;
            QString value = "";
            while(indice <= sizeList){
                if(doubleValues.at(indice).isSpace() || indice ==(sizeList)){
                    if(!value.isEmpty()){
                        bool hasLetter = false;
                        for(int j = 0;j <value.size();j++){
                            if(value.at(j).isLetter())
                                hasLetter = true;
                        }
                        if(!hasLetter){
                            double newInputValue = value.toDouble();
                            axlDouble *input = new axlDouble(newInputValue);
                            dynamicData->setInput(input);
                        }
                        value.clear();
                    }

                }else{
                    value.append(doubleValues.at(indice));
                }
                indice++;
            }
        }
        QObjectList list = this->children();
        for(int i = 0;i < list.size();i++){
            if(QFrame *frame = dynamic_cast<QFrame *>(list.at(i))){
                QObjectList list1 = frame->children();
                for(int j = 0;j < list1.size();j++){
                    if(QDoubleSpinBox *box = dynamic_cast<QDoubleSpinBox *>(list1.at(j))){
                        double value = box->value();
                        axlDouble *input = new axlDouble(value);
                        dynamicData->setInput(input);
                    }else if(QSpinBox *box = dynamic_cast<QSpinBox *>(list1.at(j))){
                        int value = box->value();
                        axlInteger *input = new axlInteger(value);
                        dynamicData->setInput(input);
                    }
                }
            }

        }


        dynamicData->update();
        if(!dynamicData->outputs()){
            dynamicData->clearInputs();
            if(d->dialog && dynamic_cast<axlInspectorToolCreator *>(d->dialog)){
                QList<axlAbstractData *>listInputs = dynamic_cast<axlInspectorToolCreator *>(d->dialog)->returnInputsList();
                for(int j = 0;j< listInputs.size();j++){
                    dynamicData->setInput(listInputs.at(j));
                }

                dynamicData->update();
                if(dynamicData->outputs()){
                    for(int k = 0; k < dynamicData->inputs().size();k++){
                        if(!(dynamicData->inputs().at(k)->identifier() == "axlDouble") && !(dynamicData->inputs().at(k)->identifier() == "axlInteger")){
                            dynamicData->inputs().at(k)->setColor(d->colorButton->color());
                            double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
                            dynamicData->inputs().at(k)->setOpacity(opacity);
                            emit dataInserted(dynamicData->inputs().at(k));
                        }

                    }

                    dynamicData->setColor(d->colorButton->color());
                    double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
                    dynamicData->setOpacity(opacity);
                    emit dataInserted(dynamicData);
                    //                    d->dialog->hide();
                }else{
                    // not enough or appropriated inputs
                    d->errorMessage->show();
                    if(d->dialog && dynamic_cast<axlInspectorToolCreator *>(d->dialog)){
                        d->dialog->show();
                        dynamic_cast<axlInspectorToolCreator *>(d->dialog)->run();
                    }

                }


            }

        }else{
            //compute outputs
            dynamicData->setColor(d->colorButton->color());
            double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
            dynamicData->setOpacity(opacity);
            emit dataInserted(dynamicData);
            if(d->dialog){
                d->dialog->hide();
            }
        }


    }


}
// /////////////////////////////////////////////////////////////////
// axlInspectorToolCreatorDataDynamicDialog documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlInspectorToolCreatorDataDynamicDialog
 *
 *  \brief Class axlInspectorToolCreatorDataDynamicDialog is the dialog used to create dynamic data.
 *
 */
