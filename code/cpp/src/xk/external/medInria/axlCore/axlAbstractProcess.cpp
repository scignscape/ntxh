/* axlAbstractProcess.cpp ---
 *
 * Author: Bernard Mourrain
 * Copyright (C) 2011 - Bernard Mourrain, Inria.
 * Created: Tue Nov 11 16:58:59 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:32:45 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 22
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractProcess.h"
#include "axlAbstractField.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtGui>

class axlAbstractProcessPrivate
{
public:
    QString description;
    QString identifier;

};

axlAbstractProcess::axlAbstractProcess(void) : dtkAbstractProcess(), d(new axlAbstractProcessPrivate)
{

}

axlAbstractProcess::~axlAbstractProcess(void)
{
    delete d;

    d = NULL;
}

QString axlAbstractProcess::description(void) const
{
    return "Generic description of axlAbstractProcess";
}

QString axlAbstractProcess::identifier(void) const
{
    return "axlAbstractProcess";
}

void axlAbstractProcess::setDescription(QString description)
{
    d->description = description;
}

void axlAbstractProcess::setIdentifier(QString identifier)
{
    d->identifier = identifier;
}

void axlAbstractProcess::copyProcess(axlAbstractProcess *process)
{
    Q_UNUSED(process);
}

//! returns true if the process needs parameters. By default, equals false.
//!
/*!
 *
 */
bool axlAbstractProcess::hasParameters(void){
    DTK_DEFAULT_IMPLEMENTATION;
    return false;
}

//! Description of the form for the dialog with the process.
/**
 * The string use to describe the form is formatted as follows:
 * \code
 * "INPUT[:CHANNEL] TYPE LABEL"
 * "PARAMETER[:CHANNEL] TYPE LABEL"
 * "OUTPUT [:CHANNEL] LABEL"
 * \endcode
 * where:
 *  - CHANNEL is a number identifying the rank of an input, see dtkAbstractProcess. Write this value only if the process method setInput uses a channel in its parameters !
 *  - TYPE is either int, double or data.
 *  - LABEL is the input's name.
 *
 * Here is an example of such a declaration:
 * \code
 * QString form(void) const
 * {
 *       return QString(
 *            " INPUT:0 data StartPoint \n"
 *            " INPUT:1 data EndPoint \n"
 *            " PARAMETER:0 double Radius \n"
 *            " OUTPUT Cylinder ");
 * }
 * \endcode
**/
QString axlAbstractProcess::form(void) const
{
    return QString();
}
