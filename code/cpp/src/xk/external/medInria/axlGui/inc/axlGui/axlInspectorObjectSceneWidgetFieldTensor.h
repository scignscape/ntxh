/* axlInspectorObjectSceneWidgetFieldTensor.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Dec 17 22:47:05 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Jun 17 17:14:22 2011 (+0200)
 *           By: Thibaud Kloczko
 *     Update #: 11
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTSCENEWIDGETFIELDTENSOR_H
#define AXLINSPECTOROBJECTSCENEWIDGETFIELDTENSOR_H

#include <QtWidgets>

#include "axlGuiExport.h"

class axlAbstractField;
class axlInspectorObjectSceneWidgetFieldTensorPrivate;

class AXLGUI_EXPORT axlInspectorObjectSceneWidgetFieldTensor : public QWidget
{
    Q_OBJECT

public:
     axlInspectorObjectSceneWidgetFieldTensor(QWidget *parent = 0);
    ~axlInspectorObjectSceneWidgetFieldTensor(void);

public slots:
    void setField(axlAbstractField *field);

private:
    axlInspectorObjectSceneWidgetFieldTensorPrivate *d;
};

#endif //axlInspectorObjectSceneWidgetFIELDTENSOR_H
