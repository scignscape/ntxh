/* axlInspectorObjectSceneWidgetField.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Jul 30 21:27:51 2010 (+0200)
 * Version: $Id$
 * Last-Updated: Fri Sep  9 15:43:08 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 44
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTSCENEWIDGETFIELD_H
#define AXLINSPECTOROBJECTSCENEWIDGETFIELD_H

#include <QtWidgets>

#include "axlGuiExport.h"

class axlAbstractField;
class axlAbstractActorField;
class axlAbstractView;
class axlInspectorObjectSceneWidgetFieldPrivate;

class AXLGUI_EXPORT axlInspectorObjectSceneWidgetField : public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectSceneWidgetField(QWidget *parent = 0);
    ~axlInspectorObjectSceneWidgetField(void);

public slots:
    void setField(axlAbstractField *field);
    void setActorField(axlAbstractActorField *mesh);
    void setView(axlAbstractView *view);

protected slots:
    void onDisplayAsNoneScalar(void);
    void onDisplayAsColor(void);
    void onDisplayAsIso(void);

    void onDisplayAsNoneVector(void);
    void onDisplayAsHedge(void);
    void onDisplayAsGlyph(void);
    void onDisplayAsStream(void);

    void onColRangeMinChanged(double min);
    void onColRangeMaxChanged(double max);

    void onIsoCountChanged(int count);
    void onIsoRadiusChanged(double radius);
    void onIsoRangeMinChanged(double min);
    void onIsoRangeMaxChanged(double max);

    void onGlyphScaleValueChanged(double scale);

    void onStreamRadiusValueChanged(double radius);
    void onStreamPropagationValueChanged(double propagation);
    void onStreamDirectionValueChanged(int direction);

private:
    axlInspectorObjectSceneWidgetFieldPrivate *d;
};

#endif //axlInspectorObjectSceneWidgetFIELD_H
