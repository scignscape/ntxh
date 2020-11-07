// Version: $Id: 2562d51c5000e53246cc7cefdb72c9979881d370 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include <dtkConfig.h>

#include "dtkComposer.h"
#include "dtkComposerNodeFactory.h"
#include "dtkComposerExtension.h"
#include "dtkComposerSettings.h"
#include "dtkComposerDefaultExtensions.h"

#include <dtkCore/dtkArray.h>

#if defined(DTK_BUILD_DISTRIBUTED)
#include <dtkDistributed/dtkDistributed.h>
#endif

namespace dtkComposer
{
    namespace node
    {
        namespace _private {
            dtkComposerNodeFactory factory;
        }

        dtkComposerNodeFactory& factory(void)
        {
            return _private::factory;
        }

        void initialize(void)
        {
            dtkComposerBaseExtension baseExt;
            baseExt.extend(&(_private::factory));

            dtkComposerBooleanExtension boolExt;
            boolExt.extend(&(_private::factory));

            dtkComposerControlExtension controlExt;
            controlExt.extend(&(_private::factory));

            dtkComposerConstantsExtension constantsExt;
            constantsExt.extend(&(_private::factory));

#if defined(DTK_BUILD_DISTRIBUTED)
            bool verbose = dtkComposer::extension::pluginManager().verboseLoading();
            dtkDistributed::communicator::setVerboseLoading(verbose);
            dtkDistributed::communicator::initialize();
            dtkComposerDistributedExtension distributedExt;
            distributedExt.extend(&(_private::factory));
#endif

            dtkComposerFileExtension fileExt;
            fileExt.extend(&(_private::factory));

            dtkComposerNumberExtension numberExt;
            numberExt.extend(&(_private::factory));

            dtkComposerStringExtension stringExt;
            stringExt.extend(&(_private::factory));

            dtkComposerContainerExtension containerExt;
            containerExt.extend(&(_private::factory));
        }
    }

    namespace extension {

        namespace _private {
            dtkComposerExtensionPluginFactory factory;
            dtkComposerExtensionPluginManager manager;
            bool activate_obj_mgr = false;
        }

        dtkComposerExtensionPluginFactory& pluginFactory(void)
        {
            return _private::factory;
        }

        dtkComposerExtensionPluginManager& pluginManager(void)
        {
            return _private::manager;
        }

        void activateObjectManager(bool val)
        {
            _private::activate_obj_mgr = val;
        }

        bool isObjectManagerActive(void)
        {
            return _private::activate_obj_mgr ;
        }

        void initialize(const QString& path)
        {
            QString realpath = path;

            if (realpath.isEmpty()) {
                dtkComposerSettings composer_settings;
                composer_settings.beginGroup("extension");
                realpath = composer_settings.value("plugins").toString();
                composer_settings.endGroup();

                if (realpath.isEmpty()) {
                    QString dtk_prefix = DTK_INSTALL_PREFIX;
                    // ugly: remove null characters added by conda
                    realpath = QDir::cleanPath(dtk_prefix.remove(QChar::Null) + "/plugins/dtkComposer");
                    dtkDebug() << "no composer plugin path configured, use default:" << realpath ;
                }
                pluginManager().initialize(realpath);
            } else {
                dtkDebug() << "initialize composer plugins using path:" << path ;
                pluginManager().initialize(path);
            }

            // needed when the composer is run on a remote node
            // should we add more ?
            qMetaTypeId<dtkArray<qlonglong> *>();
            qMetaTypeId<dtkArray<double> *>();
            qRegisterMetaTypeStreamOperators<QStringList *>("QStringList *");
        }
    }
}

//
// dtkComposer.cpp ends here
