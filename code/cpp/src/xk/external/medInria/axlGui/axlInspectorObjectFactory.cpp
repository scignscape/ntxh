/* axlInspectorObjectFactory.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: mar. mars 29 12:35:33 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Apr 20 14:03:24 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 20
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectFactory.h"

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

axlInspectorObjectInterface::axlInspectorObjectInterface(QWidget *parent) : QFrame(parent)
{
    m_objectFactorySingleton = axlInspectorObjectFactory::instance();
}

axlInspectorObjectInterface::~axlInspectorObjectInterface(void)
{

}

void axlInspectorObjectInterface::setObjectFactorySingleton(axlInspectorObjectFactory *objectFactorySingleton)
{
    m_objectFactorySingleton = objectFactorySingleton;
}

axlInspectorObjectFactory *axlInspectorObjectInterface::objectFactorySingleton(void)
{
    return m_objectFactorySingleton;
}

void axlInspectorObjectInterface::setData(dtkAbstractData *data)
{
    qDebug()<<"axlInspectorObjectInterface::setData : Default implementation";
}


void axlInspectorObjectInterface::initComboBoxShaderValue(QComboBox *comboBoxShader, QLineEdit *lineEditShader)
{
    if(comboBoxShader) {

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
            comboBoxShader->addItem(item);

            QFileInfo currentFileInfo(lineEditShader->text());

            if(currentFileInfo.exists())
            {
                if(item == currentFileInfo.fileName())
                    indInitShader =indCurrentShader;
            }
        }

        //init the value from the lineEditShader.
        if(indInitShader != -1)
            comboBoxShader->setCurrentIndex(indInitShader);
    }
}


QString axlInspectorObjectInterface::filePath(const QString& shader)
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
    return currentFile.absoluteFilePath();
}

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlInspectorObjectFactoryPrivate
{
public:
    axlInspectorObjectFactory::axlInspectorObjectCreatorHash creators;
};

axlInspectorObjectFactory *axlInspectorObjectFactory::instance(void)
{
    if(!s_instance)
        s_instance = new axlInspectorObjectFactory;

    return s_instance;
}

bool axlInspectorObjectFactory::registerInspectorObject(const QString& interface_name, axlInspectorObjectCreator func)
{
    if(!d->creators.contains(interface_name))
        d->creators.insert(interface_name, func);

    return true;
}

axlInspectorObjectInterface *axlInspectorObjectFactory::create(const QString& interface_name)
{
    if(!d->creators.contains(interface_name))
        return NULL;

    return d->creators[interface_name]();
}



axlInspectorObjectFactory::axlInspectorObjectFactory(void) : QObject(), d(new axlInspectorObjectFactoryPrivate)
{

}

axlInspectorObjectFactory::~axlInspectorObjectFactory(void)
{
    delete d;

    d = NULL;
}

axlInspectorObjectFactory *axlInspectorObjectFactory::s_instance = NULL;
