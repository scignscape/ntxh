// Version: $Id: 1f6e48088d9d00efd84fc61e84a29db837674859 $
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

#include <dtkComposerExport.h>

#include <QtCore>

class dtkComposerNodeFactory;
class dtkComposerExtensionPlugin;
class dtkComposerExtensionPluginManager;
class dtkComposerExtensionPluginFactory;

namespace dtkComposer {

    namespace node {
        DTKCOMPOSER_EXPORT dtkComposerNodeFactory& factory(void);
        DTKCOMPOSER_EXPORT void initialize(void);
    }

    namespace extension {
        DTKCOMPOSER_EXPORT dtkComposerExtensionPluginFactory& pluginFactory(void);
        DTKCOMPOSER_EXPORT dtkComposerExtensionPluginManager& pluginManager(void);
        DTKCOMPOSER_EXPORT void initialize(const QString& path = "");
        DTKCOMPOSER_EXPORT void activateObjectManager(bool val = true);
        DTKCOMPOSER_EXPORT bool isObjectManagerActive(void);
    }
}

//
// dtkComposer.h ends here
