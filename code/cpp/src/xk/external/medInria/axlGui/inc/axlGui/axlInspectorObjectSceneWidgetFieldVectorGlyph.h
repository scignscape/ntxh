/* axlInspectorObjectSceneWidgetFieldVectorGlyph.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Fri Sep  9 15:33:08 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Fri Sep  9 15:34:21 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 4
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTSCENEWIDGETFIELDVECTORGLYPH_H
#define AXLINSPECTOROBJECTSCENEWIDGETFIELDVECTORGLYPH_H

#include <QtWidgets>

#include "axlGuiExport.h"

class axlInspectorObjectSceneWidgetFieldVectorGlyphPrivate;

class AXLGUI_EXPORT axlInspectorObjectSceneWidgetFieldVectorGlyph : public QWidget
{
    Q_OBJECT

public:
     axlInspectorObjectSceneWidgetFieldVectorGlyph(QWidget *parent = 0);
    ~axlInspectorObjectSceneWidgetFieldVectorGlyph(void);

signals:
    void glyphScaleValueChanged(double);

private:
    axlInspectorObjectSceneWidgetFieldVectorGlyphPrivate *d;
};

#endif
