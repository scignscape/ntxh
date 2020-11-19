/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

#include "plugindialog.h"
#include <common/interfaces/filter_plugin_interface.h>
#include <common/interfaces/io_plugin_interface.h>
#include <common/interfaces/decorate_plugin_interface.h>
#include <common/interfaces/render_plugin_interface.h>
#include <common/interfaces/edit_plugin_interface.h>



#include <QLabel>
#include <QDir>
#include <QPluginLoader>
#include <QTreeWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QHeaderView>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QStringList>

PluginDialog::PluginDialog(const QString &path, const QStringList &fileNames,QWidget *parent): QDialog(parent)
{
	label = new QLabel;
	label->setWordWrap(true);
	QStringList headerLabels;
	headerLabels << tr("Components");
	
	treeWidget = new QTreeWidget;
	treeWidget->setAlternatingRowColors(false);
	treeWidget->setHeaderLabels(headerLabels);
	treeWidget->header()->hide();
	
	groupBox=new QGroupBox(tr("Info Plugin"));
	
	okButton = new QPushButton(tr("OK"));
	okButton->setDefault(true);
	
	spacerItem = new QSpacerItem(363, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	
	labelInfo=new QLabel(groupBox);
	labelInfo->setWordWrap(true);
	//tedit->hide();
	
	connect(okButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(displayInfo(QTreeWidgetItem*,int)));
	
	QGridLayout *mainLayout = new QGridLayout;
	QHBoxLayout *gboxLayout = new QHBoxLayout(groupBox);
	gboxLayout->addWidget(labelInfo);
	//mainLayout->setColumnStretch(0, 1);
	//mainLayout->setColumnStretch(2, 1);
	mainLayout->addWidget(label, 0, 0, 1, 2);
	mainLayout->addWidget(treeWidget, 1, 0, 4, 2);
	mainLayout->addWidget(groupBox,5,0,1,2);
	mainLayout->addItem(spacerItem, 6, 0, 1, 1);
	mainLayout->addWidget(okButton,6,1,1,1);
	
	
	//mainLayout->addWidget(okButton, 3, 1,Qt::AlignHCenter);
	//mainLayout->addLayout(buttonLayout,3,1);
	setLayout(mainLayout);
	
	interfaceIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon),QIcon::Normal, QIcon::On);
	interfaceIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirClosedIcon),QIcon::Normal, QIcon::Off);
	featureIcon.addPixmap(style()->standardPixmap(QStyle::SP_FileIcon));
	
	setWindowTitle(tr("Plugin Information"));
	populateTreeWidget(path, fileNames);
	pathDirectory=path;
}

static QString computeXmlFilename(const QDir & dir, const QString & filename)
{
	QFileInfo f(dir.absoluteFilePath(filename));
	QString tmp = f.baseName() + ".xml";
	if (tmp.startsWith("lib")) {
		tmp.replace("lib", "");
	}
	return dir.absoluteFilePath(tmp);
}

void PluginDialog::populateTreeWidget(const QString &path,const QStringList &fileNames)
{
	if (fileNames.isEmpty()) {
		label->setText(tr("Can't find any plugins in the %1 " "directory.").arg(QDir::toNativeSeparators(path)));
		treeWidget->hide();
	}
	else {
		int nPlugins = 0;
		QDir dir(path);
		foreach (QString fileName, fileNames) {
			QPluginLoader loader(dir.absoluteFilePath(fileName));
			QObject *plugin = loader.instance();
			
			QTreeWidgetItem *pluginItem = new QTreeWidgetItem(treeWidget);
			pluginItem->setText(0, fileName);
			pluginItem->setIcon(0, interfaceIcon);
			treeWidget->setItemExpanded(pluginItem, false);
			
			QFont boldFont = pluginItem->font(0);
			boldFont.setBold(true);
			pluginItem->setFont(0, boldFont);
			
			if (plugin) {
				IOPluginInterface *iMeshIO = qobject_cast<IOPluginInterface *>(plugin);
				if (iMeshIO){
					nPlugins++;
					QStringList Templist;
					foreach(const IOPluginInterface::Format f,iMeshIO->importFormats()){
						QString formats;
						foreach(const QString s,f.extensions) formats+="Importer_"+s+" ";
						Templist.push_back(formats);
					}
					foreach(const IOPluginInterface::Format f,iMeshIO->exportFormats()){
						QString formats;
						foreach(const QString s,f.extensions) formats+="Exporter_"+s+" ";
						Templist.push_back(formats);
					}
					addItems(pluginItem,Templist);
				}
				DecoratePluginInterface *iDecorate = qobject_cast<DecoratePluginInterface *>(plugin);
				if (iDecorate){
					nPlugins++;
					QStringList Templist;
					foreach(QAction *a,iDecorate->actions()){Templist.push_back(a->text());}
					addItems(pluginItem,Templist);
				}
				FilterPluginInterface *iFilter = qobject_cast<FilterPluginInterface *>(plugin);
				if (iFilter){
					nPlugins++;
					QStringList Templist;
					foreach(QAction *a,iFilter->actions()){Templist.push_back(a->text());}
					addItems(pluginItem,Templist);
				}
				RenderPluginInterface *iRender = qobject_cast<RenderPluginInterface *>(plugin);
				if (iRender){
					nPlugins++;
					QStringList Templist;
					foreach(QAction *a,iRender->actions()){Templist.push_back(a->text());}
					addItems(pluginItem,Templist);
				}
				EditPluginInterfaceFactory *iEdit = qobject_cast<EditPluginInterfaceFactory *>(plugin);
				if (iEdit){
					nPlugins++;
					QStringList Templist;
					foreach(QAction *a,iEdit->actions()){Templist.push_back(a->text());}
					addItems(pluginItem,Templist);
				}
			}
		}
		std::string lbl = "Found the following " + std::to_string(nPlugins) + " plugins in the %1 " "directory:";
		label->setText(tr(lbl.c_str()).arg(QDir::toNativeSeparators(path)));
	}
}


void PluginDialog::addItems(QTreeWidgetItem *pluginItem,const QStringList &features){
	
	foreach (QString feature, features) {
		QTreeWidgetItem *featureItem = new QTreeWidgetItem(pluginItem);
		featureItem->setText(0, feature);
		featureItem->setIcon(0, featureIcon);
	}
}


void PluginDialog::displayInfo(QTreeWidgetItem* item,int /* ncolumn*/)
{
	QString parent;
	QString actionName;
	if(item==NULL) return;
	if (item->parent()!=NULL)	{parent=item->parent()->text(0);actionName=item->text(0);}
	else parent=item->text(0);
	QString fileName=pathDirectory+"/"+parent;
	QDir dir(pathDirectory);
	QPluginLoader loader(fileName);
	qDebug("Trying to load the plugin '%s'", qUtf8Printable(fileName));
	QObject *plugin = loader.instance();
	if (plugin) {
		IOPluginInterface *iMeshIO = qobject_cast<IOPluginInterface *>(plugin);
		if (iMeshIO){
			foreach(const IOPluginInterface::Format f,iMeshIO->importFormats()){
				QString formats;
				foreach(const QString s,f.extensions) formats+="Importer_"+s+" ";
				if (actionName==formats) labelInfo->setText(f.description);
			}
			foreach(const IOPluginInterface::Format f,iMeshIO->exportFormats()){
				QString formats;
				foreach(const QString s,f.extensions) formats+="Exporter_"+s+" ";
				if (actionName==formats) labelInfo->setText(f.description);
			}
		}
		DecoratePluginInterface *iDecorate = qobject_cast<DecoratePluginInterface *>(plugin);
		if (iDecorate)
		{
			foreach(QAction *a,iDecorate->actions())
				if (actionName==a->text())
					labelInfo->setText(iDecorate->decorationInfo(a));
		}
		FilterPluginInterface *iFilter = qobject_cast<FilterPluginInterface *>(plugin);
		if (iFilter)
		{
			foreach(QAction *a,iFilter->actions())
				if (actionName==a->text()) labelInfo->setText(iFilter->filterInfo(iFilter->ID(a)));
		}
		RenderPluginInterface *iRender = qobject_cast<RenderPluginInterface *>(plugin);
		if (iRender){
		}
		EditPluginInterfaceFactory *iEditFactory = qobject_cast<EditPluginInterfaceFactory *>(plugin);
		if (iEditFactory)
		{
			foreach(QAction *a, iEditFactory->actions())
			{
				if(iEditFactory) labelInfo->setText(iEditFactory->getEditToolDescription(a));
			}
		}
	}
}
