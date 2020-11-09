/* axlInspectorToolCreatorDataDynamicDialog.h ---
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

#ifndef AXLINSPECTORTOOLCREATORDATADYNAMICDIALOG_H
#define AXLINSPECTORTOOLCREATORDATADYNAMICDIALOG_H

#include "axlGuiExport.h"

class dtkAbstractData;
class axlAbstractData;
//class axlDouble;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorDataDynamicDialogPrivate;

class AXLGUI_EXPORT axlInspectorToolCreatorDataDynamicDialog : public QFrame
{
    Q_OBJECT

public:
    axlInspectorToolCreatorDataDynamicDialog(QWidget *parent = 0);
    ~axlInspectorToolCreatorDataDynamicDialog(void);

    void setController(axlInspectorObjectController *controller);

signals:
    void dataInserted(axlAbstractData *data);
//    void doubleInputInserted(QList<axlDouble *> dataList);


public slots:
    void run(void);
    void setProcessName(void);

private:
    axlInspectorToolCreatorDataDynamicDialogPrivate *d;
};

#endif // AXLINSPECTORTOOLCREATORDATADYNAMICDIALOG_H
