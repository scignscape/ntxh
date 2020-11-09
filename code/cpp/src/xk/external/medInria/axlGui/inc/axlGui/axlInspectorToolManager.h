/* axlInspectorToolManager.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 19:38:48 2011 (+0100)
 * Version: $Id$
 * Last-Updated: mar. mars 29 12:28:43 2011 (+0200)
 *           By: Meriadeg Perrinel
 *     Update #: 8
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORTOOLMANAGER_H
#define AXLINSPECTORTOOLMANAGER_H

#include "axlGuiExport.h"

#include <QtWidgets>

class dtkAbstractData;
class dtkAbstractProcess;
class axlDouble;

class axlAbstractView;
class axlAbstractData;
class axlInspectorObjectController;

class axlInspectorToolManagerPrivate;

class AXLGUI_EXPORT axlInspectorToolManager: public QFrame
{
    Q_OBJECT

public:
     axlInspectorToolManager(QWidget *parent = 0);
    ~axlInspectorToolManager(void);

    QSize sizeHint(void) const;

    void setController(axlInspectorObjectController *controller);
    void setView(axlAbstractView *view);

signals:
    void selected(QString, QString);
    void update(void);
    void dataInserted(axlAbstractData *data);

    void dataSetToRemove(QList<dtkAbstractData*>);
    void dataChanged(dtkAbstractData *data);
    void dataChangedByControlPoints(dtkAbstractData *data);
//    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
//    void dataChangedByShaderFromString(dtkAbstractData *data, QString isophoteShaderXml);
    void fieldsCreatedOnData(QList<axlAbstractData *> dataList, QString fieldName);
    void modifiedProperty(dtkAbstractData *,int);

//    //useful for data dynamic objects which contain axlDouble inputs.
//    void doubleInputInserted(QList<axlDouble *> dataList);


private:
    axlInspectorToolManagerPrivate *d;
};

#endif // AXLINSPECTORTOOLMANAGER_H
