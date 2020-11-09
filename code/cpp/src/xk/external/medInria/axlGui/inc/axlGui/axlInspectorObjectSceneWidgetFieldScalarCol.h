/* axlInspectorObjectSceneWidgetFieldScalarCol.h ---
 *
 * Author: Thibaud Kloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Mon Jun 20 14:15:15 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Jul 20 22:05:04 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 5
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTSCENEWIDGETFIELDSCALARCOL_H
#define AXLINSPECTOROBJECTSCENEWIDGETFIELDSCALARCOL_H

#include <QtWidgets>

#include "axlGuiExport.h"

class axlAbstractField;
class axlInspectorObjectSceneWidgetFieldScalarColPrivate;
class axlAbstractView;

class AXLGUI_EXPORT axlInspectorObjectSceneWidgetFieldScalarCol : public QWidget
{
    Q_OBJECT

public:
     axlInspectorObjectSceneWidgetFieldScalarCol(QWidget *parent = 0);
    ~axlInspectorObjectSceneWidgetFieldScalarCol(void);

signals:
    void colRangeMinChanged(double);
    void colRangeMaxChanged(double);

public slots:
    void setMin(double min);
    void setMax(double max);

    void setField(axlAbstractField *field);
    void setView(axlAbstractView *view);

protected slots:
    void onResetMinimalValueClicked(void);
    void onResetMaximalValueClicked(void);

private:
    axlInspectorObjectSceneWidgetFieldScalarColPrivate *d;
};

#endif //
