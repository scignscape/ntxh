/* axlInspectorToolManager_p.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 20:06:24 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Apr  3 14:19:49 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 29
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORTOOLMANAGER_P_H
#define AXLINSPECTORTOOLMANAGER_P_H

#include <QtCore/QObject>
#include <QtCore/QStringList>

#include <QtWidgets>

class axlInspectorTool;
class axlInspectorObjectController;
class dtkItem;
class dtkTag;
class dtkTagCloud;
class dtkTagScope;

// /////////////////////////////////////////////////////////////////
// axlInspectorToolManagerView
// /////////////////////////////////////////////////////////////////

class axlInspectorToolManagerView : public QTreeWidget
{
    Q_OBJECT

public:
     axlInspectorToolManagerView(QWidget *parent = 0);
    ~axlInspectorToolManagerView(void);

signals:
    void clicked(QString implementation, QString interface_name);

protected slots:
    void onItemDoubleClicked(QTreeWidgetItem *item, int column);
};

// /////////////////////////////////////////////////////////////////
// axlInspectorToolManagerController
// /////////////////////////////////////////////////////////////////

class axlInspectorToolManagerController : public QObject
{
    Q_OBJECT

public:
     axlInspectorToolManagerController(QObject *parent = 0);
    ~axlInspectorToolManagerController(void);

    void attach(axlInspectorToolManagerView *view);
    void attach(dtkTagCloud *cloud);
    void attach(dtkTagScope *scope);

    void addItem(QString name);
    void addItem(QString name, QString description);
    void addItem(QString name, QString description, QStringList tags);
    // void addItem(QString name, QString description, QStringList tags, QStringList types);

    void update(void);
    void render(void);

private slots:
    void addFilter(QString tag);
    void setFilter(QString tag);
    void clear(void);
    void onUnionMode(bool mode);

private:
    axlInspectorToolManagerView *view;
    dtkTagCloud *cloud;
    dtkTagScope *scope;

    QList<dtkTag>  tags;
    QList<dtkItem> items;
    QStringList    filters;
    bool union_mode;
};

// /////////////////////////////////////////////////////////////////
// axlInspectorToolManagerPrivate
// /////////////////////////////////////////////////////////////////

class axlInspectorToolManagerPrivate
{
public:
    axlInspectorToolManagerView *view;
    dtkTagCloud *cloud;
    dtkTagScope *scope;
    axlInspectorObjectController *ObjectController;
    axlInspectorTool *inspector_tool;

public:
    axlInspectorToolManagerController *controller;
};

#endif //AXLINSPECTORTOOLMANAGER_P_H
