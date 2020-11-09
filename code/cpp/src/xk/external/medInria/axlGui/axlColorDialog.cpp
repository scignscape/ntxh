/* axlColorDialog.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Mon Mar 14 18:25:24 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Mar 14 18:25:57 2011 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 3
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlColorDialog.h"
#include <dtkCoreSupport/dtkGlobal.h>


axlColorDialog::axlColorDialog(QColorDialog *parent) : QColorDialog(parent)
{
    this->setWindowOpacity(0.95);
}

axlColorDialog::axlColorDialog(const QColor &initial, QColorDialog *parent) : QColorDialog(initial, parent)
{
    this->setWindowOpacity(0.95);
}

axlColorDialog::~axlColorDialog(void)
{

}
