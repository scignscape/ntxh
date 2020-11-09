/* axlInspectorSeparator.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Mar 15 14:06:35 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Thu Mar 17 23:58:51 2011 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 10
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORSEPARATOR_H
#define AXLINSPECTORSEPARATOR_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlInspectorSeparatorPrivate;


class AXLGUI_EXPORT axlInspectorSeparator : public QWidget
{
    Q_OBJECT

public:
     axlInspectorSeparator(QWidget *parent = 0, Qt::Orientation orientation = Qt::Horizontal);
    ~axlInspectorSeparator(void);

public:
    QSize sizeHint(void) const;

protected:
    void paintEvent(QPaintEvent *event);

private:
    axlInspectorSeparatorPrivate *d;
};

#endif
