/* axlAbstractVisitor.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractVisitor.h"
#include <dtkCoreSupport/dtkGlobal.h>
//#include <axlGui/axlInspectorObjectFactory.h>

class axlAbstractVisitorPrivate
{
public:
};

axlAbstractVisitor::axlAbstractVisitor(QObject *parent) : dtkAbstractObject(), d(new axlAbstractVisitorPrivate)
{
    this->setParent(parent);
}

axlAbstractVisitor::~axlAbstractVisitor(void)
{
    delete d;

    d = NULL;
}


//! Return a dialog.
/*!
 *
 */
//axlInspectorObjectInterface *axlAbstractVisitor::form(void){
//    DTK_DEFAULT_IMPLEMENTATION;
//    return NULL;
//}

// /////////////////////////////////////////////////////////////////
// axlAbstractVisitor documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlAbstractVisitor
 *
 *  \brief Class axlAbstractVisitor defines an API for all type of axel Visitor (design pattern).
 *
 *  Every axel Visitor must inherite from this abstract class.
 */

