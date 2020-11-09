/* axlInspectorObjectSceneWidgetFieldScalar.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Dec 17 22:47:05 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Jul 20 22:04:00 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTSCENEWIDGETFIELDSCALAR_H
#define AXLINSPECTOROBJECTSCENEWIDGETFIELDSCALAR_H

#include <QtWidgets>

#include "axlGuiExport.h"

class axlAbstractField;
class axlInspectorObjectSceneWidgetFieldScalarPrivate;
class axlAbstractView;

class AXLGUI_EXPORT axlInspectorObjectSceneWidgetFieldScalar : public QWidget
{
    Q_OBJECT

public:
     axlInspectorObjectSceneWidgetFieldScalar(QWidget *parent = 0);
    ~axlInspectorObjectSceneWidgetFieldScalar(void);

signals:
    void displayAsColor(void);
    void displayAsIso(void);
    void displayAsNone(void);

    void colRangeMinChanged(double);
    void colRangeMaxChanged(double);

    void isoCountChanged(int);
    void isoRadiusChanged(double);
    void isoRangeMinChanged(double);
    void isoRangeMaxChanged(double);

public slots:
    void setIsoCount(int count);
    void setIsoRangeMin(double min);
    void setIsoRangeMax(double max);

    void setField(axlAbstractField *field);
    void setView(axlAbstractView *view);

    void setDefaultDisplay(void);

protected slots:
    void onDisplayAsColorClicked(void);
    void onDisplayAsIsoClicked(void);
    void onDisplayAsNothingClicked(void);

private:
    axlInspectorObjectSceneWidgetFieldScalarPrivate *d;
};

#endif //axlInspectorObjectSceneWidgetFIELDSCALAR_H
