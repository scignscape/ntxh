/* dtkAbstractProcessFactory.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Nov  7 15:48:10 2008 (+0100)
 * Version: $Id: d19e5f1d628364f2ad3d3fbdcff221122159fe8e $
 * Last-Updated: Thu Sep 27 16:11:54 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 67
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include <QtCore>
#include <QtWidgets>

#include "axlCoreExport.h"


class AXLCORE_EXPORT axlMenuFactory : public QObject
{
    Q_OBJECT

public:
    static axlMenuFactory *instance(void);

    bool registerMenu(QMenu *menu);

    QList<QMenu *> menus(void);

protected:
     axlMenuFactory(void);
    ~axlMenuFactory(void);

private:
    static axlMenuFactory   *s_instance;

private:

// forward decl.
    class axlMenuFactoryPrivate *d;
};

