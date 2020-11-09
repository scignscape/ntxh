/* axlInspectorObjectManager.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 18:23:13 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Apr  3 14:20:50 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 52
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObject.h"
#include "axlInspectorObjectManager.h"
#include "axlInspectorObjectManagerList.h"
#include "axlInspectorObjectManagerListItem.h"
#include "axlInspectorObjectManagerTree.h"
#include "axlInspectorObjectManagerTreeItem.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorSeparator.h"
#include "axlInspectorObjectSceneWidgetField.h"

#include <axlCore/axlAbstractData.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractView.h>
#include <axlCore/axlAbstractActorField.h>

#include <axlCore/axlDataDynamic.h>

#include <axlGui/axlInspectorObjectSceneWidgetVolumeDiscrete.h>
#include <axlCore/axlAbstractVolumeDiscrete.h>

#include <QtGui>

class axlInspectorObjectManagerPrivate
{
public:
    axlInspectorObjectController *controller;
    axlInspectorObject *inspector_object;
    axlInspectorObjectSceneWidgetField *field;
    QString lastScalarFieldName;
    QString lastVectorFieldName;
    axlInspectorSeparator *fieldSeparator;
    //    QList<axlInspectorObjectSceneWidgetDouble*>value;


public:
    axlInspectorObjectManagerTree *tree;
    axlInspectorObjectManagerList *list;
    axlInspectorSeparator *listSeparator;

public :
    //displayed for discrete volume only
    axlInspectorObjectSceneWidgetVolumeDiscrete *editor;


    axlAbstractView *view;

    QVBoxLayout *layout;

};

axlInspectorObjectManager::axlInspectorObjectManager(QWidget *parent) : QWidget(parent), d(new axlInspectorObjectManagerPrivate)
{
    d->controller = NULL;
    d->view = NULL;

    d->inspector_object = new axlInspectorObject(this);
    //d->inspector_object->showMaximized();
    d->inspector_object->setController(d->controller);

    //d->editor = new axlInspectorObjectSceneWidgetVolumeDiscrete(this);
    d->editor = NULL;


    d->field = new axlInspectorObjectSceneWidgetField(this);
    d->fieldSeparator = new axlInspectorSeparator(this);
    d->lastScalarFieldName = "";
    d->lastVectorFieldName = "";

    //d->value = new axlInspectorObjectSceneWidgetDouble(this);

    d->list = new axlInspectorObjectManagerList(this);
    d->listSeparator = new axlInspectorSeparator(this);

    //QVBoxLayout *field_layout = new QVBoxLayout;
    //append_layout->addWidget(new QLabel("Apppend:", this));
    //field_layout->addWidget(d->list);
    // field_layout->addWidget(new axlInspectorSeparator(this));
    //field_layout->addWidget(d->field);
    //field_layout->setContentsMargins(3, 3, 3, 3);


    d->tree = new axlInspectorObjectManagerTree(this);


    d->layout = new QVBoxLayout(this);
    d->layout->setAlignment(Qt::AlignTop);
    d->layout->setContentsMargins(0, 0, 0, 0);
    d->layout->setSpacing(0);
    d->layout->addWidget(d->tree);
    d->layout->addWidget(new axlInspectorSeparator(this));
    d->layout->addWidget(d->inspector_object);
    d->layout->addWidget(d->listSeparator);
    d->layout->addWidget(d->list);
    d->layout->addWidget(d->fieldSeparator);
    d->layout->addWidget(d->field);
    //d->layout->addWidget(d->editor);
    //    layout->addWidget(d->value);
    d->inspector_object->hide();
    d->listSeparator->hide();
    d->list->hide();
    d->field->hide();
    d->fieldSeparator->hide();
    //d->editor->hide();
    //    d->value->hide();


    connect(d->list, SIGNAL(currentItemChanged(QListWidgetItem *,QListWidgetItem *)), this, SLOT(onTransmitDataSelected(QListWidgetItem *,QListWidgetItem *)));
    connect(d->list, SIGNAL(itemSelectionChanged()), this, SLOT(onFieldListSelectionChanged()));

    connect(d->tree, SIGNAL(itemSelectionChanged()), this, SLOT(onListSelectionChanged()));

    connect(d->tree, SIGNAL(inserted()), this, SIGNAL(inserted()));
    connect(d->tree, SIGNAL(stateChanged(dtkAbstractData *, int)), this, SIGNAL(stateChanged(dtkAbstractData *, int)));
    connect(d->tree, SIGNAL(actorVisibilityChanged(dtkAbstractData *, bool)), this, SIGNAL(actorVisibilityChanged(dtkAbstractData *, bool)));
    connect(d->tree, SIGNAL(dataSetRemoved(QList<dtkAbstractData *>)), this, SIGNAL(dataSetRemoved(QList<dtkAbstractData*>)));


    connect(d->tree, SIGNAL(dataSetRemoved(QList<dtkAbstractData *>)), d->inspector_object, SLOT(onDataSetRemoved(QList<dtkAbstractData*>)));

    connect(d->tree, SIGNAL(selected(dtkAbstractData *)), d->inspector_object, SLOT(onDataSelected(dtkAbstractData *)));
    connect(d->tree, SIGNAL(dataSetSelected(QList<dtkAbstractData *>)), d->inspector_object, SLOT(onDataSetSelected(QList<dtkAbstractData *>)));
    connect(d->inspector_object, SIGNAL(update()), this, SIGNAL(update()));
    connect(d->inspector_object, SIGNAL(showCurrentPoint(double, double, dtkAbstractData *)), this, SIGNAL(showCurrentPoint(double, double, dtkAbstractData *)));
    connect(d->inspector_object, SIGNAL(hideCurrentPoint(double, double, dtkAbstractData *)), this, SIGNAL(hideCurrentPoint(double, double, dtkAbstractData *)));
    connect(d->inspector_object, SIGNAL(moveCurrentPoint(double, double, dtkAbstractData *)), this, SIGNAL(moveCurrentPoint(double, double, dtkAbstractData *)));
    connect(d->inspector_object, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
    //    connect(d->inspector_object, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData * ,QString)));
    //    connect(d->inspector_object, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
    //    connect(d->inspector_object, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
    //    connect(d->inspector_object, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
    connect(d->inspector_object, SIGNAL(modifiedProperty(dtkAbstractData*,int)), this,SIGNAL(modifiedProperty(dtkAbstractData*,int)));
    connect(d->inspector_object, SIGNAL(interpolationChanded(dtkAbstractData*,int)), this, SIGNAL(interpolationChanded(dtkAbstractData*,int)));


}

axlInspectorObjectManager::~axlInspectorObjectManager(void)
{

    delete d;

    d = NULL;
}

axlInspectorObjectManagerTreeItem *axlInspectorObjectManager::insert(axlAbstractData *data)
{
    return d->tree->insert(data);
}

void axlInspectorObjectManager::removeData(dtkAbstractData *data){
    d->tree->remove(data);
}

QList<dtkAbstractData *> axlInspectorObjectManager::dataSet(void)
{
    return d->tree->dataSet();
}

void axlInspectorObjectManager::resizeColumnToContents()
{
    for(int i = 0; i < d->tree->columnCount(); i++)
    {
        d->tree->resizeColumnToContents(i);
    }
}

void axlInspectorObjectManager::onStateChanged(dtkAbstractData *data, int mode)
{
    d->tree->onStateChanged(data, mode);
}

void axlInspectorObjectManager::onDataRemoved(QList<dtkAbstractData *> dataToRemoved)
{

    foreach(dtkAbstractData *data, dataToRemoved){
        if(dynamic_cast<axlAbstractVolumeDiscrete *>(data)){
            if(d->editor){
                d->editor->hide();
                d->layout->removeWidget(d->editor);
                delete d->editor;
                d->editor = NULL;
            }
        }
    }
    d->tree->onDataRemoved(dataToRemoved);

}

void axlInspectorObjectManager::clearScene(void)
{
    d->tree->removeAllItems();
}

void axlInspectorObjectManager::setController(axlInspectorObjectController *controller)
{
    d->controller = controller;
    d->inspector_object->setController(controller);
    d->tree->setController(controller);
}


void axlInspectorObjectManager::onListSelectionChanged(void)
{
    if(d->tree->selectedItems().size() == 0 && d->controller)
    {
        d->inspector_object->hide();
        d->list->hide();
        d->listSeparator->hide();
        d->field->hide();
        d->fieldSeparator->hide();
        if(d->editor){
            d->editor->hide();
            d->layout->removeWidget(d->editor);
            delete d->editor;
            d->editor = NULL;
        }

        //        for(int i = 0; i < d->value.size(); i++){
        //            dynamic_cast<axlInspectorObjectSceneWidgetDouble *>(d->value.at(i))->hide();
        //        }

    }
    if(d->tree->selectedItems().size() == 1 && d->controller)
    {
        d->inspector_object->show();
        axlInspectorObjectManagerTreeItem *axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(d->tree->selectedItems().first());

        if(axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(d->controller->data(axlCurrentItem)))
        {
            if(axlData->fields().count() != 0)
            {
                d->list->show();
                d->listSeparator->show();

            }

            if(dynamic_cast<axlAbstractVolumeDiscrete *>(axlData)){
                d->editor = new axlInspectorObjectSceneWidgetVolumeDiscrete(this);
                d->layout->addWidget(d->editor);
                d->editor->setView(d->view);
                d->editor->setData(axlData);
                d->editor->show();
            }else{
                if(d->editor){
                    d->editor->hide();
                    d->layout->removeWidget(d->editor);
                    delete d->editor;
                    d->editor = NULL;

                }
            }


            d->list->setData(axlData);

            //            if(axlDataDynamic *dataDynamic  = dynamic_cast<axlDataDynamic *>(axlData)){

            //                //check that the dynamic object has double input.
            //                bool hasDoubleInputs = false;
            //                foreach(axlAbstractData *input, dataDynamic->inputs()){
            //                    if(dynamic_cast<axlDouble *>(input)){
            //                        hasDoubleInputs = true;
            //                    }
            //                }
            //                if(hasDoubleInputs){
            //                    for(int i = 0; i < d->value.size(); i++){
            //                        // display dialog only of it referenced an input of the dynamic object selected
            //                        if(dynamic_cast<axlInspectorObjectSceneWidgetDouble *>(d->value.at(i))->name() == dataDynamic->name() )
            //                            dynamic_cast<axlInspectorObjectSceneWidgetDouble *>(d->value.at(i))->show();
            //                    }
            //                }
            //            }
        }

    }
}


axlAbstractField *axlInspectorObjectManager::onTransmitDataSelected(QListWidgetItem *fromItem,QListWidgetItem *toItem)
{
    if (axlInspectorObjectManagerListItem *axlCurrentItem = dynamic_cast<axlInspectorObjectManagerListItem *>(fromItem)) {

        if(axlAbstractField *field = axlCurrentItem->field() )
        {
            //we do nothing if we try to select a field that it's the same last field we selected in function of the kind
            //            if(field->name() != d->lastScalarFieldName && field->name() != d->lastVectorFieldName)
            //            {
            //                for ( int i = 0 ; i < d->list->count() ; i++)
            //                {
            //                    QListWidgetItem *listItem = d->list->item(i);
            //                    if(field->kind() == axlAbstractField::Scalar &&  dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == axlAbstractField::Scalar )
            //                    {
            //                        if(axlAbstractActorField * currentActorField = dynamic_cast<axlAbstractActorField *>(d->view->actor(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field())))
            //                        {
            //                            currentActorField->displayAsNoneScalar();
            //                            d->lastScalarFieldName = field->name();
            //                        }
            //                    }

            //                    if(field->kind() == axlAbstractField::Vector &&  dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == axlAbstractField::Vector)
            //                    {
            //                        if(axlAbstractActorField *currentField = dynamic_cast<axlAbstractActorField *>(d->view->actor(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field())))
            //                        {
            //                            currentField->displayAsNoneVector();
            //                            d->lastVectorFieldName = field->name();
            //                        }
            // }
            //                }

            //            }


            ////add
            //hide all actor Fields;
            for ( int i = 0 ; i < d->controller->items().size() ; i++)
            {
                axlInspectorObjectManagerTreeItem *item = d->controller->items().at(i);
                axlAbstractData *axldata = dynamic_cast<axlAbstractData *>(d->controller->data(item));
                if(axldata->fields().size() > 0){
                    d->list->setData(axldata);



                    //hide all actor Fields;
                    for ( int i = 0 ; i < d->list->count() ; i++)
                    {
                        QListWidgetItem *listItem = d->list->item(i);
                        if(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == axlAbstractField::Scalar && dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == dynamic_cast<axlInspectorObjectManagerListItem *>(d->list->item(d->list->count() - 1))->field()->kind())
                            dynamic_cast<axlAbstractActorField *>(d->view->actor(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()))->displayAsNoneScalar();

                        if( dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == axlAbstractField::Vector  && dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == dynamic_cast<axlInspectorObjectManagerListItem *>(d->list->item(d->list->count() - 1))->field()->kind())
                        {
                            axlAbstractActorField *currentField = dynamic_cast<axlAbstractActorField *>(d->view->actor(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()));
                            currentField->displayAsNoneVector();
                        }
                    }


                }
            }
            this->onListSelectionChanged();
            ///end add

            d->view->update();


            d->field->setField(field);

            ////second add
            // run defaut view
            if(field->kind() == axlAbstractField::Scalar)
            {
                dynamic_cast<axlAbstractActorField *>(d->view->actor(field))->displayAsColor();
                d->lastScalarFieldName = field->name();

            }

            if(field->kind() == axlAbstractField::Vector)
            {
                axlAbstractActorField *currentField = dynamic_cast<axlAbstractActorField *>(d->view->actor(field));
                currentField->displayAsGlyph();
                d->lastVectorFieldName = field->name();

            }
            ////second add end

            // if ( axlAbstractActorField *currentActorField = dynamic_cast<axlAbstractActorField *>(d->view->actor(field)) )
            if ( dynamic_cast<axlAbstractActorField *>(d->view->actor(field)) )
            {
                // TO DO
                //currentActorField->setActiveFieldKind();
            }
            return field;
        }
    } else {
        qDebug() << "axlInspectorObjectManager::onTransmitDataSelected" << "error";
    }

    return NULL;
}

void axlInspectorObjectManager::onFieldListSelectionChanged(void)
{
    if(d->list->selectedItems().isEmpty())
    {
        d->field->hide();
        d->fieldSeparator->hide();

    }
    else
    {
        d->field->show();
        d->fieldSeparator->show();
    }

}


//void axlInspectorObjectManager::onDoubleInputListSelectionChanged(void)
//{

//    qDebug() << "axlInspectorObjectManager::onDoubleInputListSelectionChanged";
//    if(d->list->selectedItems().isEmpty())
//    {
//        d->value->hide();

//    }
//    else
//    {
//        d->value->show();
//    }

//}

void axlInspectorObjectManager::onFieldOpened(QList<axlAbstractData *> dataList, QString fieldName)
{

    //hide all actor Fields;
    for ( int i = 0 ; i < d->controller->items().size() ; i++)
    {
        axlInspectorObjectManagerTreeItem *item = d->controller->items().at(i);
        axlAbstractData *axldata = dynamic_cast<axlAbstractData *>(d->controller->data(item));
        if(axldata->fields().size() > 0){
            d->list->setData(axldata);



            //hide all actor Fields;
            for ( int i = 0 ; i < d->list->count() ; i++)
            {
                QListWidgetItem *listItem = d->list->item(i);
                if(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == axlAbstractField::Scalar && dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == dynamic_cast<axlInspectorObjectManagerListItem *>(d->list->item(d->list->count() - 1))->field()->kind())
                    dynamic_cast<axlAbstractActorField *>(d->view->actor(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()))->displayAsNoneScalar();

                if( dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == axlAbstractField::Vector  && dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == dynamic_cast<axlInspectorObjectManagerListItem *>(d->list->item(d->list->count() - 1))->field()->kind())
                {
                    axlAbstractActorField *currentField = dynamic_cast<axlAbstractActorField *>(d->view->actor(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()));
                    currentField->displayAsNoneVector();
                }
            }


        }
    }


    foreach (axlAbstractData *axlData, dataList)
    {
        axlAbstractField *field = NULL;
        //focus the good field
        foreach(axlAbstractField *currentField, axlData->fields())
            if(currentField->name() == fieldName)
                field = currentField;

        if(field)
        {
            // field is finded, we remove all field with the same kind before
            foreach(axlAbstractField *currentField, axlData->fields())
            {
                //   qDebug()<< "axlInspectorObjectManager::onFieldsCreatedOnData "<<currentField->name();
                if(field->kind() == axlAbstractField::Scalar && currentField->kind() == axlAbstractField::Scalar)
                    dynamic_cast<axlAbstractActorField *>(d->view->actor(currentField))->displayAsNoneScalar();
                else if(field->kind() == axlAbstractField::Vector && currentField->kind() == axlAbstractField::Vector)
                    dynamic_cast<axlAbstractActorField *>(d->view->actor(currentField))->displayAsNoneVector();

            }

            // then we draw it by default
            if(field->kind() == axlAbstractField::Scalar)
                dynamic_cast<axlAbstractActorField *>(d->view->actor(field))->displayAsColor();
            else if(field->kind() == axlAbstractField::Vector)
                dynamic_cast<axlAbstractActorField *>(d->view->actor(field))->displayAsGlyph();
        }
    }


    d->view->update();
}

void axlInspectorObjectManager::onFieldsCreatedOnData(QList<axlAbstractData *> dataList, QString fieldName)
{
    if(d->tree->selectedItems().size() > 1 ) // we draw by default the field for all d->tree items selected
    {
        foreach (axlAbstractData *axlData, dataList)
        {
            axlAbstractField *field = NULL;
            //focus the good field
            foreach(axlAbstractField *currentField, axlData->fields())
                if(currentField->name() == fieldName)
                    field = currentField;

            if(field)
            {
                // field is finded, we remove all field with the same kind before
                foreach(axlAbstractField *currentField, axlData->fields())
                {
                    if(field->kind() == axlAbstractField::Scalar && currentField->kind() == axlAbstractField::Scalar)
                        dynamic_cast<axlAbstractActorField *>(d->view->actor(currentField))->displayAsNoneScalar();
                    else if(field->kind() == axlAbstractField::Vector && currentField->kind() == axlAbstractField::Vector)
                        dynamic_cast<axlAbstractActorField *>(d->view->actor(currentField))->displayAsNoneVector();

                }

                // then we draw it by default
                if(field->kind() == axlAbstractField::Scalar)
                    dynamic_cast<axlAbstractActorField *>(d->view->actor(field))->displayAsColor();
                else if(field->kind() == axlAbstractField::Vector)
                    dynamic_cast<axlAbstractActorField *>(d->view->actor(field))->displayAsGlyph();
            }
        }

    }
    else
    {
        // int fieldCountBefore = d->list->count();
        // add the field into Inspector list fields
        //this->onListSelectionChanged();

        //hide all actor Fields;
        for ( int i = 0 ; i < d->controller->items().size() ; i++)
        {
            axlInspectorObjectManagerTreeItem *item = d->controller->items().at(i);
            axlAbstractData *axldata = dynamic_cast<axlAbstractData *>(d->controller->data(item));
            if(axldata->fields().size() > 0){
                d->list->setData(axldata);


                //hide all actor Fields
                for ( int i = 0 ; i < d->list->count() ; i++)
                {
                    QListWidgetItem *listItem = d->list->item(i);
                    if(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == axlAbstractField::Scalar && dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == dynamic_cast<axlInspectorObjectManagerListItem *>(d->list->item(d->list->count() - 1))->field()->kind())
                        dynamic_cast<axlAbstractActorField *>(d->view->actor(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()))->displayAsNoneScalar();

                    if( dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == axlAbstractField::Vector  && dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()->kind() == dynamic_cast<axlInspectorObjectManagerListItem *>(d->list->item(d->list->count() - 1))->field()->kind())
                    {
                        axlAbstractActorField *currentField = dynamic_cast<axlAbstractActorField *>(d->view->actor(dynamic_cast<axlInspectorObjectManagerListItem *>(listItem)->field()));
                        currentField->displayAsNoneVector();
                    }
                }


            }
        }

        //show the last field
        //this->onListSelectionChanged();
        d->list->setData(dataList.last());

        //simulate defaut display on last field created if new one was just created
        if(axlInspectorObjectManagerListItem *axlCurrentItem = dynamic_cast<axlInspectorObjectManagerListItem *>(d->list->item(d->list->count() - 1)))
        {

            if(axlAbstractField *field = axlCurrentItem->field())
            {
                // update field widget
                d->field->setField(field);

                dynamic_cast<axlAbstractActorField *>(d->view->actor(field))->setActiveFieldKind();

                //make sure widget is shown
                d->field->show();
                d->fieldSeparator->show();

                // run defaut view
                if(axlCurrentItem->field()->kind() == axlAbstractField::Scalar)
                {
                    dynamic_cast<axlAbstractActorField *>(d->view->actor(axlCurrentItem->field()))->displayAsColor();
                    d->lastScalarFieldName = field->name();

                }

                if( axlCurrentItem->field()->kind() == axlAbstractField::Vector)
                {
                    axlAbstractActorField *currentField = dynamic_cast<axlAbstractActorField *>(d->view->actor(axlCurrentItem->field()));
                    currentField->displayAsGlyph();
                    d->lastVectorFieldName = field->name();

                }
            }
        }

    }


    d->view->update();

}

//void axlInspectorObjectManager::onDoubleInputInserted(QList<axlDouble *> dataList)
//{


//    foreach(axlInspectorObjectSceneWidgetDouble *insp, d->value){
//        if(dataList.first()->name() == insp->name()){
//            d->value.removeOne(insp);
//        }
//    }


//    foreach(axlDouble *axlData, dataList){
//        axlInspectorObjectSceneWidgetDouble *newWidget = new axlInspectorObjectSceneWidgetDouble(this);
//        newWidget->setDouble(axlData);
//        d->layout->addWidget(newWidget);
//        newWidget->hide();
//        d->value.append(newWidget);
//        newWidget->setView(d->view);
//    }


//    d->view->update();

//}



void axlInspectorObjectManager::setView(axlAbstractView *view)
{
    d->view = view;
    d->field->setView(view);
    //d->editor->setView(view);
    //    for(int i = 0; i < d->value.size(); i++){
    //        dynamic_cast<axlInspectorObjectSceneWidgetDouble *>(d->value.at(i))->setView(view);
    //    }


    connect(d->inspector_object, SIGNAL(tubeFilterRadiusChanged(dtkAbstractData *, double)), d->view, SLOT(onTubeFilterRadiusChanged(dtkAbstractData *, double)));

}
