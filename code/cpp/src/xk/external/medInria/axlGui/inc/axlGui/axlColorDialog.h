/* axlColorDialog.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Mon Mar 14 18:24:29 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Mar 14 18:25:06 2011 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 7
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLCOLORDIALOG_H
#define AXLCOLORDIALOG_H

#include "axlGuiExport.h"

#include <QtWidgets>

class AXLGUI_EXPORT axlColorDialog : public QColorDialog
{
     Q_OBJECT
public:
             axlColorDialog(QColorDialog *parent = 0);
             axlColorDialog(const QColor &initial, QColorDialog *parent);
    virtual ~axlColorDialog(void);

};

#endif //axlColorDialog_H
