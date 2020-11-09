/* dtkAbstractProcessFactory.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Nov  7 15:54:10 2008 (+0100)
 * Version: $Id: 2460ccb9838680880c0ff0a202c702fd0d42c97f $
 * Last-Updated: mar. févr.  4 15:17:39 2014 (+0100)
 *           By: Nicolas Niclausse
 *     Update #: 125
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlMenuFactory.h"

class axlMenuFactoryPrivate
{
public:
    QList<QMenu *> menus;
};

axlMenuFactory *axlMenuFactory::instance(void)
{
    if(!s_instance)
        s_instance = new axlMenuFactory;

    return s_instance;
}


QList<QMenu *> axlMenuFactory::menus(void)
{
    return d->menus;
}

bool axlMenuFactory::registerMenu(QMenu * m)
{
    if ( ! d->menus.contains(m) )
    {
        d->menus << m;
        return true;
    }
    else        
        return false;
}

axlMenuFactory::axlMenuFactory(void) : QObject(), d(new axlMenuFactoryPrivate)
{

}

axlMenuFactory::~axlMenuFactory(void)
{
    delete d;

    d = NULL;
}

axlMenuFactory *axlMenuFactory::s_instance = NULL;
