// Version: $Id: a657a155cef5c3adf96b4159997815ca1531780d $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#pragma once

#include <QtCore>

#include <dtkComposerExport.h>

#include <dtkCore/dtkCorePlugin.h>

class dtkComposerNodeFactory;

class DTKCOMPOSER_EXPORT dtkComposerExtension : public QObject
{
    Q_OBJECT

public:
             dtkComposerExtension(void) {}
    virtual ~dtkComposerExtension(void) {}

public:
    virtual void extend(dtkComposerNodeFactory *factory) = 0;
};

DTK_DECLARE_OBJECT(dtkComposerExtension *)
DTK_DECLARE_PLUGIN(dtkComposerExtension, DTKCOMPOSER_EXPORT)
DTK_DECLARE_PLUGIN_FACTORY(dtkComposerExtension, DTKCOMPOSER_EXPORT)
DTK_DECLARE_PLUGIN_MANAGER(dtkComposerExtension, DTKCOMPOSER_EXPORT)

//
// dtkComposerExtension.h ends here
