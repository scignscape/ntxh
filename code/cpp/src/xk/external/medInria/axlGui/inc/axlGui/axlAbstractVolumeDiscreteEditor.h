/* axlAbstractVolumeDiscreteEditor.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2008 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTVOLUMEDISCRETEEDITOR_H
#define AXLABSTRACTVOLUMEDISCRETEEDITOR_H

#include "axlGuiExport.h"
#include <QtCore>
#include <QtGui>
#include <axlCore/axlAbstractView.h>
#include <axlCore/axlAbstractVolumeDiscrete.h>
#include "axlInspectorObjectFactory.h"

class axlAbstractVolumeDiscreteEditorPrivate;

class AXLGUI_EXPORT axlAbstractVolumeDiscreteEditor : public axlInspectorObjectInterface
{
    Q_OBJECT

public:
    axlAbstractVolumeDiscreteEditor(QWidget *parent=0);
    virtual ~axlAbstractVolumeDiscreteEditor(void);

public slots:
    virtual void setView(axlAbstractView *view);
    virtual void setVolume(axlAbstractVolumeDiscrete *volume);

//protected slots:
//    virtual void onLogChecked(bool checked);
//    virtual void onSclChecked(bool checked);
//    virtual void onShdChecked(bool checked);

//protected slots:
//    virtual void outlineNone(void);
//    virtual void outlineCorners(void);
//    virtual void outlineBox(void);
//    virtual void outlineContour(void);

private:
    axlAbstractVolumeDiscreteEditorPrivate *d;
};

#endif // AXLABSTRACTVOLUMEDISCRETEEDITOR_H
