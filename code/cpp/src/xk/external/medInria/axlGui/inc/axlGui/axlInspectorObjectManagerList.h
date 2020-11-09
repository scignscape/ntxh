/* axlInspectorObjectManagerList.h ---
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

#ifndef AXLINSPECTOROBJECTMANAGERLIST_H
#define AXLINSPECTOROBJECTMANAGERLIST_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlAbstractData;

class axlInspectorObjectManagerListPrivate;

class AXLGUI_EXPORT axlInspectorObjectManagerList : public QListWidget
{
     Q_OBJECT

public:
             axlInspectorObjectManagerList(QWidget *parent = 0);
    virtual ~axlInspectorObjectManagerList(void);

public :
    axlAbstractData *axlData(void);
    void setData(axlAbstractData *data);



private:
    axlInspectorObjectManagerListPrivate *d;
};

#endif //AXLINSPECTOROBJECTMANAGERLIST_H
