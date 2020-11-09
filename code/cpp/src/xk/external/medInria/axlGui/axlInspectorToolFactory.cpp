/* axlInspectorToolFactory.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: mar. mars 29 12:35:33 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Apr 20 14:03:24 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 20
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorToolFactory.h"

#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include <axlCore/axlAbstractFieldGenerator.h>


#include <axlGui/axlInspectorToolCreatorLine.h>
#include <axlGui/axlInspectorToolCreatorCone.h>
#include <axlGui/axlInspectorToolCreatorCylinder.h>
#include <axlGui/axlInspectorToolCreatorPlane.h>
#include <axlGui/axlInspectorToolCreatorTorus.h>
#include <axlGui/axlInspectorToolCreatorSphere.h>
#include <axlGui/axlInspectorToolCreatorEllipsoid.h>
#include <axlGui/axlInspectorToolFactory.h>

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

axlInspectorToolInterface::axlInspectorToolInterface(QWidget *parent) : QFrame(parent)
{
    m_view = NULL;
    m_controller = NULL;
    m_process = NULL;

    m_toolFactorySingleton = axlInspectorToolFactory::instance();

}

axlInspectorToolInterface::~axlInspectorToolInterface(void)
{
    //    if(m_process && !(dynamic_cast<axlAbstractFieldGenerator*>(m_process)) ){
    if(m_process){
        delete m_process;
    }

    m_process = NULL;


}

void axlInspectorToolInterface::setController(axlInspectorObjectController *controller)
{
    this->m_controller = controller;
}

void axlInspectorToolInterface::setImplementation(const QString& implementation)
{
    if(!(this->m_process = dtkAbstractProcessFactory::instance()->create(implementation))){

    }

    if(dynamic_cast<axlAbstractFieldGenerator*>(m_process)){
        connect(m_process, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData *>, QString)), this, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData *>, QString)));
    }

    this->setToolTip(m_process->description());

}

void axlInspectorToolInterface::setToolFactorySingleton(axlInspectorToolFactory *toolFactorySingleton)
{
    m_toolFactorySingleton = toolFactorySingleton;
}

axlInspectorToolFactory *axlInspectorToolInterface::toolFactorySingleton(void)
{
    return m_toolFactorySingleton;
}

//dtkAbstractProcess *axlInspectorToolInterface::getProcess(void)
//{
//    return m_process;
//}


void axlInspectorToolInterface::setView(axlAbstractView *view)
{
    this->m_view = view;
}

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlInspectorToolFactoryPrivate
{
public:
    axlInspectorToolFactory::axlInspectorToolCreatorHash creators;
};

axlInspectorToolFactory *axlInspectorToolFactory::instance(void)
{
    if(!s_instance)
        s_instance = new axlInspectorToolFactory;

    return s_instance;
}

bool axlInspectorToolFactory::registerInspectorTool(const QString& interface_name, axlInspectorToolCreator func)
{
    if(!d->creators.contains(interface_name))
    {
        d->creators.insert(interface_name, func);
    }

    return true;
}

axlInspectorToolInterface *axlInspectorToolFactory::create(const QString& interface_name)
{
    if(!d->creators.contains(interface_name))
        return NULL;

    return d->creators[interface_name]();
}


void axlInspectorToolFactory::initialize(void)
{

    d->creators.insert("axlLineCreator", createaxlInspectorToolCreatorLine);
    d->creators.insert("axlConeCreator",createaxlInspectorToolCreatorCone );
    d->creators.insert("axlCylinderCreator", createaxlInspectorToolCreatorCylinder);
    d->creators.insert("axlPlaneCreator", createaxlInspectorToolCreatorPlane);
    d->creators.insert("axlTorusCreator", createaxlInspectorToolCreatorTorus);
    d->creators.insert("axlSphereCreator", createaxlInspectorToolCreatorSphere);
    d->creators.insert("axlEllipsoidCreator", createaxlInspectorToolCreatorEllipsoid);


}

axlInspectorToolFactory::axlInspectorToolFactory(void) : QObject(), d(new axlInspectorToolFactoryPrivate)
{
}

axlInspectorToolFactory::~axlInspectorToolFactory(void)
{
    delete d;

    d = NULL;
}

axlInspectorToolFactory *axlInspectorToolFactory::s_instance = NULL;
