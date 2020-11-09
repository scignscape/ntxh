/* axlInspectorObjectSceneWidgetFieldVector.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Dec 17 22:47:05 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Sep  9 15:49:27 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 22
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTSCENEWIDGETFIELDVECTOR_H
#define AXLINSPECTOROBJECTSCENEWIDGETFIELDVECTOR_H

#include <QtWidgets>

#include "axlGuiExport.h"

class axlAbstractField;
class axlInspectorObjectSceneWidgetFieldVectorPrivate;
class axlAbstractView;

class AXLGUI_EXPORT axlInspectorObjectSceneWidgetFieldVector : public QWidget
{
    Q_OBJECT

public:
     axlInspectorObjectSceneWidgetFieldVector(QWidget *parent = 0);
    ~axlInspectorObjectSceneWidgetFieldVector(void);

signals:
    void displayAsHedge(void);
    void displayAsGlyph(void);
    void displayAsStream(void);
    void displayAsNone(void);

    void glyphScaleValueChanged(double);

    void streamRadiusValueChanged(double);
    void streamPropagationValueChanged(double);
    void streamDirectionValueChanged(int);

public slots:
    void setField(axlAbstractField *field);
    void setView(axlAbstractView *view);

protected slots:
    void onDisplayAsHedge(void);
    void onDisplayAsGlyph(void);
    void onDisplayAsStream(void);
    void onDisplayAsNone(void);

private:
    axlInspectorObjectSceneWidgetFieldVectorPrivate *d;
};

#endif
