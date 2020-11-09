/* axlInspectorObjectSceneWidgetFieldScalarIso.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Sun Dec 19 18:51:51 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Jul 20 22:13:50 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 24
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTSCENEWIDGETFIELDSCALARISO_H
#define AXLINSPECTOROBJECTSCENEWIDGETFIELDSCALARISO_H

#include <QtWidgets>

#include "axlGuiExport.h"

class axlAbstractField;
class axlInspectorObjectSceneWidgetFieldScalarIsoPrivate;
class axlAbstractView;

class AXLGUI_EXPORT axlInspectorObjectSceneWidgetFieldScalarIso : public QWidget
{
    Q_OBJECT

public:
     axlInspectorObjectSceneWidgetFieldScalarIso(QWidget *parent = 0);
    ~axlInspectorObjectSceneWidgetFieldScalarIso(void);

signals:
    void isoCountChanged(int);
    void isoRadiusChanged(double);
    void isoRangeMinChanged(double);
    void isoRangeMaxChanged(double);

public slots:
    void setCount(int count);
    void setMin(double min);
    void setMax(double max);

    void setField(axlAbstractField *field);
    void setView(axlAbstractView *view);

protected slots:
    void onResetMinimalValueClicked(void);
    void onResetMaximalValueClicked(void);

private:
    axlInspectorObjectSceneWidgetFieldScalarIsoPrivate *d;
};

#endif //axlInspectorObjectSceneWidgetFIELDSCALARISO_H
