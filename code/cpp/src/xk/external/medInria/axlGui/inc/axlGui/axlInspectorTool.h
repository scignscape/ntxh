/* axlInspectorTool.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 19:39:37 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Apr 20 14:04:56 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 9
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORTOOL_H
#define AXLINSPECTORTOOL_H

#include "axlGuiExport.h"

#include <QtWidgets>

class dtkAbstractProcess;
class dtkAbstractData;
class axlDouble;

class axlAbstractData;
class axlAbstractView;
class axlInspectorObjectController;
class axlInspectorToolPrivate;

class AXLGUI_EXPORT axlInspectorTool : public QScrollArea
{
    Q_OBJECT

public:
     axlInspectorTool(QWidget *parent = 0);
    ~axlInspectorTool(void);

     void setController(axlInspectorObjectController *controller);
     void setView(axlAbstractView *view);

signals:
     void update(void);
     void dataInserted(axlAbstractData *data);
     void dataSetToRemove(QList<dtkAbstractData *> dataSet);
     void dataChanged(dtkAbstractData *data);
     void dataChangedByControlPoints(dtkAbstractData *data);
//     void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
//     void dataChangedByShaderFromString(dtkAbstractData *data, QString isophoteShaderXml);
     void fieldsCreatedOnData(QList<axlAbstractData *> dataList, QString fieldName);
//     void doubleInputInserted(QList<axlDouble *> dataList);
     void modifiedProperty(dtkAbstractData *,int);


public slots:
    void onProcessSelected(QString implementation, QString interface_name);
    void onCloseProcessDialog(void);

private:
    axlInspectorToolPrivate *d;
};

#endif // axlInspectorTool_H
