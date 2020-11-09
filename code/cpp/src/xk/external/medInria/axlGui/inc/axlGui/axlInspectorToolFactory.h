/* axlInspectorToolFactory.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: mar. mars 29 12:29:01 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Apr 20 13:59:01 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 31
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */


#ifndef AXLINSPECTORTOOLFACTORY_H
#define AXLINSPECTORTOOLFACTORY_H

#include "axlGuiExport.h"

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

class dtkAbstractData;
class dtkAbstractProcess;

class axlAbstractData;
class axlAbstractView;
class axlInspectorObjectController;
class axlInspectorToolFactory;

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class AXLGUI_EXPORT axlInspectorToolInterface : public QFrame
{
    Q_OBJECT
public:
             axlInspectorToolInterface(QWidget *parent = 0);
    virtual ~axlInspectorToolInterface(void);

    virtual void setController(axlInspectorObjectController *controller);
    void setImplementation(const QString& implementation);
    void setView(axlAbstractView *view);

    void setToolFactorySingleton(axlInspectorToolFactory *toolFactorySingleton);
    axlInspectorToolFactory *toolFactorySingleton(void);

signals:
    void update(void);
    void modifiedProperty(dtkAbstractData* data,int);
    void dataChanged(dtkAbstractData *data);
    void dataChangedByControlPoints(dtkAbstractData*);
    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
    void dataChangedByShaderFromString(dtkAbstractData *data, QString isophoteShaderXml);
    void dataSetToRemove(QList<dtkAbstractData *> data);

signals:
     void dataSetFieldsChanged(QList<axlAbstractData *> dataSet, QString fieldName);
     void finished(void);

protected:
    axlAbstractView *m_view;
    axlInspectorObjectController *m_controller;
    dtkAbstractProcess *m_process;
    QList<dtkAbstractData *> dataSet;

private:
    axlInspectorToolFactory *m_toolFactorySingleton;
};

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlInspectorToolFactoryPrivate;

class AXLGUI_EXPORT axlInspectorToolFactory : public QObject
{
    Q_OBJECT

public:
    typedef axlInspectorToolInterface *(*axlInspectorToolCreator)(void);

    typedef QHash<QString, axlInspectorToolCreator> axlInspectorToolCreatorHash;

public:
    static axlInspectorToolFactory *instance(void);

    bool registerInspectorTool(const QString& type, axlInspectorToolCreator func);

    axlInspectorToolInterface *create(const QString& type);
    void initialize(void);

protected:
    static axlInspectorToolFactory *s_instance;

private:
     axlInspectorToolFactory(void);
    ~axlInspectorToolFactory(void);

private:
    axlInspectorToolFactoryPrivate *d;
};

#endif
