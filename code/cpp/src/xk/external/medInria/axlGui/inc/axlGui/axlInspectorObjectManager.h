/* axlInspectorObjectManager.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 18:22:02 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Mar 18 10:29:45 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 32
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTMANAGER_H
#define AXLINSPECTOROBJECTMANAGER_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlAbstractField;
class axlAbstractData;
class axlAbstractView;
class dtkAbstractData;
class axlDouble;

class axlInspectorObjectController;
class axlInspectorObjectManagerTree;
class axlInspectorObjectManagerTreeItem;
class axlInspectorObjectManagerPrivate;

class AXLGUI_EXPORT axlInspectorObjectManager : public QWidget
{
    Q_OBJECT

public:
     axlInspectorObjectManager(QWidget *parent = 0);
    ~axlInspectorObjectManager(void);

    axlInspectorObjectManagerTreeItem *insert(axlAbstractData *data);
    void removeData(dtkAbstractData *data);
    void setController(axlInspectorObjectController *controller);
    void resizeColumnToContents();

    QList<dtkAbstractData *> dataSet(void);
    void setView(axlAbstractView *view);

    void clearScene(void);

signals:
    void inserted(void);
    void stateChanged(dtkAbstractData *data, int mode);
    void actorVisibilityChanged(dtkAbstractData *data, bool actorVisibility);

    void dataChangedByGeometry(dtkAbstractData *data);
//    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
//    void dataChangedByOpacity(dtkAbstractData *data, double opacity);
//    void dataChangedBySize(dtkAbstractData *data, double size);

    void interpolationChanded(dtkAbstractData *data, int interpolation);


//    void dataChangedByColor(dtkAbstractData *data, double red, double green, double blue);

    void modifiedProperty(dtkAbstractData *,int);
    void dataSetRemoved(QList<dtkAbstractData *> dataSetRemoved);

signals:
    void update(void);

    void showCurrentPoint(double u, double v, dtkAbstractData *data);
    void moveCurrentPoint(double u, double v, dtkAbstractData *data);
    void hideCurrentPoint(double u, double v, dtkAbstractData *data);

public slots:
    void onStateChanged(dtkAbstractData *data, int mode);
    void onDataRemoved(QList<dtkAbstractData *> dataToRemoved);
    void onFieldListSelectionChanged(void);
    void onFieldsCreatedOnData(QList<axlAbstractData *> dataList, QString fieldName);
//    void onDoubleInputInserted(QList<axlDouble *> dataList);
//    void onDoubleInputListSelectionChanged(void);
    void onFieldOpened(QList<axlAbstractData *> dataList, QString fieldName);

    axlAbstractField *onTransmitDataSelected(QListWidgetItem *fromItem,QListWidgetItem *toItem);



private slots:
    void onListSelectionChanged(void);


private:
    axlInspectorObjectManagerPrivate *d;
};

#endif // AXLINSPECTOROBJECTMANAGER_H
