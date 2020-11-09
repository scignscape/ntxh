/* axlInspectorObjectManagerTree.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Thu Mar 17 18:34:33 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Nov  9 14:19:15 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 46
 */

/* Commentary: 
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectManagerTree.h"

#include "axlInspectorObjectManager.h"
#include "axlInspectorObjectManagerTreeItem.h"
#include "axlInspectorObjectController.h"

#include <axlCore/axlAbstractDataComposite.h>
#include <axlCore/axlAbstractProcess.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlInteger.h>

class axlInspectorObjectManagerTreePrivate
{
public:
    axlInspectorObjectController *scene_manager;

    QHash<dtkAbstractData *, QString> treeWidgetItem;

    bool append;
};

axlInspectorObjectManagerTree::axlInspectorObjectManagerTree(QWidget *parent) : QTreeWidget(parent), d(new axlInspectorObjectManagerTreePrivate)
{
    this->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->setCursor(Qt::ArrowCursor);
    this->setFrameShape(QFrame::NoFrame);
    this->setHeaderLabels(QStringList() << "Object" << "Type" << "Mode" << "");
    this->header()->setSectionsClickable(true);
    this->setColumnWidth(0, 50);
    this->setColumnWidth(1, 50);
    this->setColumnWidth(2, 50);
    this->setColumnWidth(3, 16);
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);

    d->append = false;
    connect(this, SIGNAL(itemSelectionChanged()), this, SLOT(onAllItemClickStatedChanged()));
    connect(this, SIGNAL(itemExpanded(QTreeWidgetItem *)),this, SLOT(onItemExpanded(QTreeWidgetItem *)));
    connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem *,int)), this, SLOT(onDoubleClickStateChanged(QTreeWidgetItem *,int)));
    connect(this, SIGNAL(itemClicked(QTreeWidgetItem *,int)), this, SLOT(onItemClickedStateChanged(QTreeWidgetItem *,int)));
    connect(this->header(),SIGNAL(sectionClicked(int)), this, SLOT(onVisibilityHeaderClick(int)));
}

axlInspectorObjectManagerTree::~axlInspectorObjectManagerTree(void)
{
    delete d;

    d = NULL;
}

void axlInspectorObjectManagerTree::setController(axlInspectorObjectController *controller)
{
    d->scene_manager = controller;
    connect(d->scene_manager, SIGNAL(inserted()), this, SIGNAL(inserted()));
}

void axlInspectorObjectManagerTree::onVisibilityHeaderClick(int index){
    if (!(index == 3))
        return;

    bool showAll = 1;
    axlInspectorObjectManagerTreeItem *axlCurrentItem;

    // if at least one visible -> hide all, if all hidden -> show all
    for (int i = 0; i<this->topLevelItemCount(); i++){
        axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(this->topLevelItem(i));
        if (axlCurrentItem->checkState(3) == Qt::Checked){
            showAll = 0;
            break;
        }
    }

    for (int i = 0; i<this->topLevelItemCount(); i++){
        axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(this->topLevelItem(i));
        axlCurrentItem->setCheckState(3,showAll ? Qt::Checked:Qt::Unchecked);
        itemVisibilityChanged(this->topLevelItem(i), showAll);
    }

}

void axlInspectorObjectManagerTree::remove(dtkAbstractData *data)
{
    if(!data) {
        qDebug() << DTK_PRETTY_FUNCTION << "data is NULL";
    }

    if(dynamic_cast<axlDataDynamic *>(data)){
        axlDataDynamic *axldata = dynamic_cast<axlDataDynamic *>(data);
        disconnect(axldata, SIGNAL(destroyed(QObject *)),this, SLOT(remove(QObject*)));
    }
    axlInspectorObjectManagerTreeItem *item = d->scene_manager->item(data);
    delete item;
    d->scene_manager->remove(data);
    d->treeWidgetItem.remove(data);

    //update data is the data come from a composite
    if(axlAbstractDataComposite *composite =  dynamic_cast<axlAbstractDataComposite *>(data->parent()))
    {
        composite->remove(data);
    }
}

void axlInspectorObjectManagerTree::remove(QObject *data)
{

    if(!data) {
        qDebug() << DTK_PRETTY_FUNCTION << "data is NULL";
    }

    if(axlDataDynamic *axldata = dynamic_cast<axlDataDynamic *>(data)){

        disconnect(axldata, SIGNAL(destroyed(QObject *)),this, SLOT(remove(QObject*)));
        axlInspectorObjectManagerTreeItem *item = d->scene_manager->item(axldata);
        delete item;

        QList<dtkAbstractData *> dataRemoved;
        dataRemoved << axldata;
        emit dataSetRemoved(dataRemoved);

        d->scene_manager->remove(axldata);
        d->treeWidgetItem.remove(axldata);


    }
}

void axlInspectorObjectManagerTree::onDataRemoved(QList<dtkAbstractData *> dataToRemoved)
{

    foreach(dtkAbstractData *data, dataToRemoved)
        this->remove(data);
}


axlInspectorObjectManagerTreeItem *axlInspectorObjectManagerTree::insert(axlAbstractData *data)
{
    if(!data) {
        qDebug() << DTK_PRETTY_FUNCTION << "data is NULL";
        return new axlInspectorObjectManagerTreeItem;
    }

    QString treeItemNameObject = data->objectName();
    int numOcurrence = d->treeWidgetItem.count(d->treeWidgetItem.key(data->objectName()));

    if(treeItemNameObject == data->identifier() || numOcurrence > 0)
    //if(numOcurrence > 0)
    {
        treeItemNameObject += QString::number(d->treeWidgetItem.size());
    }

    QString typeQString = data->identifier();
    if (axlDataDynamic *dataDynamic = dynamic_cast<axlDataDynamic *>(data)){
        if(dataDynamic->process() && dataDynamic->outputs()){
            typeQString = dataDynamic->process()->identifier();
            typeQString.remove("axl");
            typeQString.remove("abstract");

        }else{
            qDebug() << Q_FUNC_INFO << "this dynamic data has no process available";
            return new axlInspectorObjectManagerTreeItem;
        }

    }


    axlInspectorObjectManagerTreeItem *item = new axlInspectorObjectManagerTreeItem(this, QStringList() << treeItemNameObject << typeQString << "Passive" << "");
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable);
    item->setCheckState(3, Qt::Checked);
    item->setToolTip(0,data->description());
    item->setToolTip(1,data->description());
    item->setToolTip(2,data->description());
    item->setToolTip(3,data->description());

    d->scene_manager->insert(data, item);
    d->treeWidgetItem.insert(data,  treeItemNameObject);
    data->setObjectName(treeItemNameObject);

    if(axlDataDynamic *dataDynamic = dynamic_cast<axlDataDynamic *>(data)){
        connect(dataDynamic, SIGNAL(destroyed(QObject *)),this, SLOT(remove(QObject*)));

        //        //output name
        //        if(dataDynamic->outputs()){
        //            QString outputnameObject = dataDynamic->outputs()->objectName();
        //            outputnameObject+=QString::number(d->treeWidgetItem.size());
        //            dataDynamic->outputs()->setObjectName(outputnameObject);
        //        }

        // double inputs name, the same as the dynamic object
        foreach(axlAbstractData *axlData, dataDynamic->inputs()){
            if(dynamic_cast<axlDouble *>(axlData)){
                axlData->setObjectName(data->name());
            }
        }
    }

    //add child if data type is composite

    if(axlAbstractDataComposite *composite = dynamic_cast<axlAbstractDataComposite *>(data))
    {
        for(int i = 0; i < composite->count(); i++)
        {
            dtkAbstractData *compositeChild = composite->get(i);
            axlInspectorObjectManagerTreeItem *itemChild = new axlInspectorObjectManagerTreeItem(item);
            itemChild->setFlags( Qt::ItemIsEnabled |Qt::ItemIsSelectable | Qt::ItemIsUserCheckable  );
            itemChild->setCheckState(3, Qt::Checked);
            itemChild->setText(0, compositeChild->objectName());
            //itemChild->setText(1, "Data");
            itemChild->setText(1, compositeChild->identifier());
            itemChild->setText(2, "Passive");
            itemChild->setText(3, "");
            itemChild->setToolTip(0,compositeChild->description());
            itemChild->setToolTip(1,compositeChild->description());
            itemChild->setToolTip(2,compositeChild->description());
            itemChild->setToolTip(3,compositeChild->description());
            d->scene_manager->insert(compositeChild, itemChild);
            d->treeWidgetItem.insert(compositeChild,  compositeChild->objectName());

        }
    }

    // init of color child
    /*axlInspectorObjectManagerTreeItem *colorItem = new axlInspectorObjectManagerTreeItem(item);
    colorItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEditable);
    colorItem->setText(0, "Color");
    colorItem->setText(1, "0");
    colorItem->setText(2, "0");
    colorItem->setText(3, "0");
    QColor color(colorItem->text(1).toInt(), colorItem->text(2).toInt(), colorItem->text(3).toInt());
    colorItem->setBackgroundColor(1, color);

     // init of shader child
    axlInspectorObjectManagerTreeItem *shaderItem = new axlInspectorObjectManagerTreeItem(item);
    shaderItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEditable);
    shaderItem->setText(0, "Shader");*/



    return item;
}

void axlInspectorObjectManagerTree::onItemExpanded(QTreeWidgetItem *item)
{
    axlInspectorObjectManagerTreeItem *currentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(item);

    dtkAbstractData *data = d->scene_manager->data(currentItem);


    if(currentItem->text(2) != "Editable"){
        if(dynamic_cast<axlAbstractData *>(data)->editable())
            emit stateChanged(data, 2);
    }

    this->updateAxlTreeWidgetItem(currentItem, 2);


}

QList<dtkAbstractData *> axlInspectorObjectManagerTree::dataSet(void)
{
    QList<dtkAbstractData *> dataSet;
    for(int i = 0; i < this->topLevelItemCount(); i++)
    {
        dataSet << d->treeWidgetItem.key(this->topLevelItem(i)->text(0));
    }

    return dataSet;
}

void axlInspectorObjectManagerTree::onStateChanged(dtkAbstractData *data, int mode)
{
    axlInspectorObjectManagerTreeItem *currentItem = d->scene_manager->item(data);

    disconnect(this, SIGNAL(itemSelectionChanged()), this, SLOT(onAllItemClickStatedChanged()));

    this->updateAxlTreeWidgetItem(currentItem,mode);

    connect(this, SIGNAL(itemSelectionChanged()), this, SLOT(onAllItemClickStatedChanged()));


    axlInspectorObjectManagerTreeItem *axlCurrentItem = NULL;
    dtkAbstractData *currentData = NULL;

    // Creation on a list of dtkAbstractData in correspondance with the selectedItems list
    QList<dtkAbstractData *> dataSelected;

    for(int i = 0; i < this->topLevelItemCount(); i++)
    {
        axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(this->topLevelItem(i));

        if(!axlCurrentItem)
            return;

        //if(axlCurrentItem->checkState(3) && axlCurrentItem->isSelected() && (axlCurrentItem->text(2) == "Passive" || axlCurrentItem->text(2) == "Selected") )
        if(axlCurrentItem->checkState(3) && axlCurrentItem->isSelected() && (axlCurrentItem->text(2) == "Passive" || axlCurrentItem->text(2) == "Selected") )

        {
            currentData = d->scene_manager->data(axlCurrentItem);
            dataSelected.push_back(currentData);
        }


        for(int j = 0 ; j < axlCurrentItem->childCount(); j++)
        {
            axlInspectorObjectManagerTreeItem *axlCurrentItemChild = dynamic_cast<axlInspectorObjectManagerTreeItem *>(axlCurrentItem->child(j));

            if(!axlCurrentItemChild)
                return;

            // if(axlCurrentItemChild->checkState(3) && axlCurrentItemChild->isSelected() && (axlCurrentItemChild->text(2) == "Passive" || axlCurrentItemChild->text(2) == "Selected") )
            if(axlCurrentItemChild->checkState(3) && axlCurrentItemChild->isSelected())
            {
                currentData = d->scene_manager->data(axlCurrentItemChild);
                dataSelected.push_back(currentData);
            }
        }
    }
    if(dataSelected.size() != 0)
        emit dataSetSelected(dataSelected);

}


void axlInspectorObjectManagerTree::onDoubleClickStateChanged(QTreeWidgetItem* currentItem, int column)
{
    axlInspectorObjectManagerTreeItem *axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(currentItem);

    if(!axlCurrentItem)
        return;

    dtkAbstractData *data = d->scene_manager->data(axlCurrentItem);
    if(!data)
        return;


    if(axlCurrentItem->checkState(3) && column != 3)
    {
        if(axlCurrentItem->text(2) == "Passive")
        {
            this->updateAxlTreeWidgetItem(axlCurrentItem, 2);

            emit stateChanged(data, 2);
        }
        else if(axlCurrentItem->text(2) == "Selected")
        {
            this->updateAxlTreeWidgetItem(axlCurrentItem, 2);

            emit stateChanged(data, 2);

        }
        else if(axlCurrentItem->text(2) == "Editable")
        {
            this->updateAxlTreeWidgetItem(axlCurrentItem, 1);

            emit stateChanged(data, 1);

        }
    }
}

void axlInspectorObjectManagerTree::onAllItemClickStatedChanged()
{
    QTreeWidgetItem *currentItem = NULL;
    QTreeWidgetItem *currentItemChild = NULL;
    axlInspectorObjectManagerTreeItem *axlCurrentItem = NULL;
    dtkAbstractData *data = NULL;

    // Creation on a list of dtkAbstractData in correspondance with the selectedItems list
    QList<dtkAbstractData *> dataSelected;

    for(int i = 0; i < this->topLevelItemCount(); i++)
    {
        currentItem = this->topLevelItem(i);
        axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(currentItem);

        if(!axlCurrentItem)
            return;

        if(axlCurrentItem->checkState(3) && axlCurrentItem->isSelected() && (axlCurrentItem->text(2) == "Passive" || axlCurrentItem->text(2) == "Selected") )
        {
            this->updateAxlTreeWidgetItem(axlCurrentItem, 1);
            data = d->scene_manager->data(axlCurrentItem);
            dataSelected.push_back(data);

            emit stateChanged(data, 1);
            //emit selected(data);
        }
        else if(axlCurrentItem->checkState(3) && (!axlCurrentItem->isSelected()) && (axlCurrentItem->text(2) == "Selected" || axlCurrentItem->text(2) == "Editable"))
        {
            data = d->scene_manager->data(axlCurrentItem);
            axlAbstractDataComposite *dataComposite = dynamic_cast<axlAbstractDataComposite *>(data);
            if(dataComposite != NULL && axlCurrentItem->text(2) == "Editable"){}
            else
            {
                this->updateAxlTreeWidgetItem(axlCurrentItem, 0);

                emit stateChanged(data, 0);
            }
        }
        for(int j = 0 ; j < currentItem->childCount(); j++)
        {
            currentItemChild = currentItem->child(j);
            axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(currentItemChild);

            if(!axlCurrentItem)
                return;

            if(axlCurrentItem->checkState(3) && axlCurrentItem->isSelected() && (axlCurrentItem->text(2) == "Passive" || axlCurrentItem->text(2) == "Selected") )
            {
                this->updateAxlTreeWidgetItem(axlCurrentItem, 1);
                data = d->scene_manager->data(axlCurrentItem);
                dataSelected.push_back(data);

                emit stateChanged(data, 1);
                //emit selected(data);
            }
            else if(axlCurrentItem->checkState(3) && (!axlCurrentItem->isSelected()) && (axlCurrentItem->text(2) == "Selected" || axlCurrentItem->text(2) == "Editable"))
            {
                this->updateAxlTreeWidgetItem(axlCurrentItem, 0);
                data = d->scene_manager->data(axlCurrentItem);

                emit stateChanged(data, 0);
            }
        }

    }


    emit dataSetSelected(dataSelected);
}

void axlInspectorObjectManagerTree::onItemClickedStateChanged(QTreeWidgetItem *currentItem, int column)
{
    axlInspectorObjectManagerTreeItem *axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(currentItem);
    /*axlInspectorObjectManagerTreeItem *axlFatherCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(currentItem->parent());

    dtkAbstractData *dataFather = NULL;

    this->updateAxlTreeWidgetItem(axlFatherCurrentItem, 2);
    dataFather = d->scene_manager->data(axlFatherCurrentItem);
    emit stateChanged(dataFather, 2);*/

    if(!axlCurrentItem)
        return;

    dtkAbstractData *data = d->scene_manager->data(axlCurrentItem);

    if(!data)
        return;


    if(column == 3){
        itemVisibilityChanged(currentItem, (axlCurrentItem->checkState(3) == Qt::Checked));
        //emit actorVisibilityChanged(data, axlCurrentItem->checkState(3));
    }

    //emit selected(data);
}

void axlInspectorObjectManagerTree::itemVisibilityChanged(QTreeWidgetItem *currentItem, bool itemVisibility)
{
    if(currentItem->childCount() == 0)
    {
        axlInspectorObjectManagerTreeItem *axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(currentItem);
        dtkAbstractData *data = d->scene_manager->data(axlCurrentItem);
        emit actorVisibilityChanged(data, itemVisibility);
    }
    else
    {

        axlInspectorObjectManagerTreeItem *axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(currentItem);
        dtkAbstractData *data = d->scene_manager->data(axlCurrentItem);
        if(dynamic_cast<axlDataDynamic *>(data)){
            emit actorVisibilityChanged(data, itemVisibility);
        }else{
            delete data;
            delete axlCurrentItem;
        }
        for(int i = 0 ; i < currentItem->childCount(); i++)
        {
            currentItem->child(i)->setCheckState(3, itemVisibility ? Qt::Checked : Qt::Unchecked);
            itemVisibilityChanged(currentItem->child(i), itemVisibility);
        }
    }
}


void axlInspectorObjectManagerTree::setAppendMode(bool append)
{
    d->append = append;
}


void axlInspectorObjectManagerTree::updateAxlTreeWidgetItem(axlInspectorObjectManagerTreeItem *axlCurrentItem, int mode)
{
    if(mode==0)
    {
        axlCurrentItem->setText(2,"Passive");
        axlCurrentItem->setSelected(false);
        axlCurrentItem->setExpanded(false);
    }
    else if(mode==1)
    {
        axlCurrentItem->setText(2,"Selected");
        axlCurrentItem->setSelected(true);
        if(QTreeWidgetItem *parent = axlCurrentItem->parent())
            parent->setSelected(false);
    }
    else if(mode==2 )
    {
        if(dynamic_cast<axlDataDynamic *>(d->scene_manager->data(axlCurrentItem))){
            axlDataDynamic *dynamicData = dynamic_cast<axlDataDynamic *>(d->scene_manager->data(axlCurrentItem));
            axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(dynamicData->outputs());
            if(axlData->editable()){
                axlCurrentItem->setText(2,"Editable");
                axlCurrentItem->setSelected(true);
                if(QTreeWidgetItem *parent = axlCurrentItem->parent())
                    parent->setSelected(false);
            }
        }else{
            axlCurrentItem->setText(2,"Editable");
            axlCurrentItem->setSelected(true);
            if(QTreeWidgetItem *parent = axlCurrentItem->parent())
                parent->setSelected(false);
        }
    }


    if(d->scene_manager->data(axlCurrentItem)){
        axlCurrentItem->setToolTip(0, d->scene_manager->data(axlCurrentItem)->description());
        axlCurrentItem->setToolTip(1, d->scene_manager->data(axlCurrentItem)->description());
        axlCurrentItem->setToolTip(2, d->scene_manager->data(axlCurrentItem)->description());
        axlCurrentItem->setToolTip(3, d->scene_manager->data(axlCurrentItem)->description());
    }
}

void axlInspectorObjectManagerTree::keyPressEvent(QKeyEvent *event)
{
    dtkAbstractData *data = NULL;
    axlInspectorObjectManagerTreeItem *axlCurrentItem = NULL;

    if(event->key() == Qt::Key_E){
        for (int i = 0 ; i < this->selectedItems().size() ; i++)
        {
            axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(this->selectedItems().at(i));
            if(axlCurrentItem->text(2) == "Selected")
            {
                if(dynamic_cast<axlDataDynamic *>(d->scene_manager->data(axlCurrentItem))){
                    axlDataDynamic *dynamicData = dynamic_cast<axlDataDynamic *>(d->scene_manager->data(axlCurrentItem));
                    axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(dynamicData->outputs());
                    if(axlData->editable()){
                        axlCurrentItem->setText(2,"Editable");
                        data = d->scene_manager->data(axlCurrentItem);
                        emit stateChanged(data, 2);
                    }
                }else{
                    axlCurrentItem->setText(2,"Editable");
                    data = d->scene_manager->data(axlCurrentItem);
                    emit stateChanged(data, 2);
                }
            }
        }
    } else if(event->key() == Qt::Key_U){
        for(int i = 0 ; i < this->selectedItems().size() ; i++)
        {
            axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(this->selectedItems().at(i));
            if(axlCurrentItem->text(2) == "Editable")
            {
                axlCurrentItem->setText(2,"Selected");
                data = d->scene_manager->data(axlCurrentItem);
                emit stateChanged(data, 1);
            }
        }
    } else if(event->key() == Qt::Key_Delete ||
            (event->key() == Qt::Key_X  && event->modifiers().testFlag(Qt::ControlModifier))){
        deleteTreeWidgetItems(this->selectedItems());

//        QList<dtkAbstractData *> dataRemoved;
//        QList<dtkAbstractData *> dataNotDynamicList;
//        QList<axlDataDynamic *> dataDynamicList;
//        while( !this->selectedItems().isEmpty())
//        {
//            // delete also the children
//            foreach(auto i, this->selectedItems().first()->takeChildren()) {
//                axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(i);
//                data = d->scene_manager->data(axlCurrentItem);
//                removeTreeItems(data, dataNotDynamicList, dataDynamicList);
//            }
//            axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *>(this->selectedItems().first());
//            data = d->scene_manager->data(axlCurrentItem);
////            this->remove(data);
////            if(!dynamic_cast<axlDataDynamic *>(data)){
////                dataNotDynamicList <<data;
////            }else{
////                dataDynamicList << dynamic_cast<axlDataDynamic *>(data);
////            }
//            removeTreeItems(data, dataNotDynamicList, dataDynamicList);
//        }
//
//        //delete output that should not be deleted twice.
//        foreach(dtkAbstractData *data, dataNotDynamicList){
//            foreach (axlDataDynamic *dynamicData, dataDynamicList) {
//                if(!dynamicData->isNotOutputProcess(data)){
//                    dataNotDynamicList.removeOne(data);
//                }
//            }
//        }
//
//
//        //fill data list to be sent.
//        foreach(dtkAbstractData *data, dataNotDynamicList){
//            dataRemoved << data;
//        }
//        foreach(axlDataDynamic *data, dataDynamicList){
//            dataRemoved << data;
//        }
//
//        emit dataSetRemoved(dataRemoved);
//
//        while (!dataRemoved.isEmpty()){
//
//            delete dataRemoved.takeLast();
//        }
    } else if ((event->key() == Qt::Key_A)  && (event->modifiers().testFlag(Qt::ControlModifier)))
       this->selectAll();
}

void axlInspectorObjectManagerTree::removeAllItems(void){
    // list with all the items
    QList<QTreeWidgetItem*> itemList;
    for(int i=0;i<this->topLevelItemCount();i++)
        itemList<<this->topLevelItem(i);
    deleteTreeWidgetItems(itemList);

//    dtkAbstractData *data = NULL;
//
//    QList<dtkAbstractData *> dataRemoved;
//    QList<dtkAbstractData *> dataNotDynamicList;
//    QList<axlDataDynamic *> dataDynamicList;
////    this->selectAll();
////    while (!this->selectedItems().isEmpty()) {
////        axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *> (this->selectedItems().first());
////        data = d->scene_manager->data(axlCurrentItem);
//    // while there are still items
//    while (this->topLevelItemCount() > 0) {
//        // delete the first (starting from its children)
//        foreach(auto i, this->topLevelItem(0)->takeChildren()) {
//            data = d->treeWidgetItem.key(i->text(0));
//            removeTreeItems(data, dataNotDynamicList, dataDynamicList);
//        }
//
//        data = d->treeWidgetItem.key(this->topLevelItem(0)->text(0));
//        removeTreeItems(data, dataNotDynamicList, dataDynamicList);
//    }
//
//    //delete output that should not be deleted twice.
//
//    foreach(dtkAbstractData *data, dataNotDynamicList) {
//        foreach(axlDataDynamic *dynamicData, dataDynamicList) {
//            if (!dynamicData->isNotOutputProcess(data))
//                dataNotDynamicList.removeOne(data);
//        }
//    }
//
//    //fill data list to be sent.
//
//    foreach(dtkAbstractData *data, dataNotDynamicList) {
//        dataRemoved << data;
//    }
//
//    foreach(axlDataDynamic *data, dataDynamicList) {
//        dataRemoved << data;
//    }
//
//    emit dataSetRemoved(dataRemoved);
//
//    while (!dataRemoved.isEmpty()) {
//        delete dataRemoved.takeLast();
//    }

}

void axlInspectorObjectManagerTree::removeTreeItems(dtkAbstractData *data, QList<dtkAbstractData *> &dataNotDynamicList, QList<axlDataDynamic *> &dataDynamicList) {
    this->remove(data);
    if (!dynamic_cast<axlDataDynamic *> (data)) {
        dataNotDynamicList << data;
    } else {
        dataDynamicList << dynamic_cast<axlDataDynamic *> (data);
    }
}

void axlInspectorObjectManagerTree::deleteTreeWidgetItems(QList<QTreeWidgetItem*> itemsList){

    dtkAbstractData *data = NULL;
    axlInspectorObjectManagerTreeItem *axlCurrentItem = NULL;

    QList<dtkAbstractData *> dataRemoved;
    QList<dtkAbstractData *> dataNotDynamicList;
    QList<axlDataDynamic *> dataDynamicList;

    // for each item
    foreach(auto it, itemsList){
        // delete if any children
        foreach(auto i, it->takeChildren()) {
            axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *> (i);
            data = d->scene_manager->data(axlCurrentItem);
            removeTreeItems(data, dataNotDynamicList, dataDynamicList);
        }
        // then delete parent
        axlCurrentItem = dynamic_cast<axlInspectorObjectManagerTreeItem *> (it);
        data = d->scene_manager->data(axlCurrentItem);
        //            this->remove(data);
        //            if(!dynamic_cast<axlDataDynamic *>(data)){
        //                dataNotDynamicList <<data;
        //            }else{
        //                dataDynamicList << dynamic_cast<axlDataDynamic *>(data);
        //            }
        removeTreeItems(data, dataNotDynamicList, dataDynamicList);
    }

    //delete output that should not be deleted twice.

    foreach(dtkAbstractData *data, dataNotDynamicList) {

        foreach(axlDataDynamic *dynamicData, dataDynamicList) {
            if (!dynamicData->isNotOutputProcess(data)) {
                dataNotDynamicList.removeOne(data);
            }
        }
    }

    //fill data list to be sent.
    foreach(dtkAbstractData *data, dataNotDynamicList){
        dataRemoved << data;
    }
    foreach(axlDataDynamic *data, dataDynamicList){
        dataRemoved << data;
    }

    emit dataSetRemoved(dataRemoved);

    while (!dataRemoved.isEmpty()){
        delete dataRemoved.takeLast();
    }

}
