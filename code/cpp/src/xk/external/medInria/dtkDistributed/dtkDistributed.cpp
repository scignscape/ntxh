/* dtkDistributed.cpp ---
 *
 * Author: Julien Wintz
 * Created: Mon Mar 25 09:23:52 2013 (+0100)
 * Version:
 * Last-Updated: Fri Jun 24 10:32:02 2016 (+0200)
 *           By: tristan cabel
 *     Update #: 8
 */

/* Change Log:
 *
 */

#include "qthDistributedCommunicator.h"

#include <dtkConfig.h>

#include "dtkDistributed.h"
#include "dtkDistributedApplication.h"
#include "dtkDistributedCommunicator.h"
#include "dtkDistributedController.h"
#include "dtkDistributedPolicy.h"
#include "dtkDistributedSettings.h"

namespace dtkDistributed {
    namespace _private {
        dtkDistributed::Mode mode = dtkDistributed::Global;
        dtkDistributedApplication *app = NULL;
    }

    void setMode(dtkDistributed::Mode mode)
    {
        _private::mode = mode;
    }

    dtkDistributed::Mode mode(void)
    {
        return _private::mode;
    }

    dtkDistributedApplication *create(int& argc, char *argv[])
    {
        for (int i = 0; i < argc; i++)
            if (!qstrcmp(argv[i], "-nw") || !qstrcmp(argv[i], "--nw") ||  !qstrcmp(argv[i], "-no-window") || !qstrcmp(argv[i], "--no-window") || !qstrcmp(argv[i], "-h") || !qstrcmp(argv[i], "--help") || !qstrcmp(argv[i], "--version")) {
                qputenv("QT_QPA_PLATFORM", QByteArrayLiteral("minimal"));
            }

        _private::app = new dtkDistributedApplication(argc, argv);
        return _private::app;
    }

    dtkDistributedApplication *app(void)
    {
        if (!_private::app ) {
            _private::app = dynamic_cast<dtkDistributedApplication *>(qApp);
        }

        return _private::app;
    }

    dtkDistributedPolicy *policy(void)
    {
        if (!app())
            return NULL;

        return _private::app->policy();
    }

    void spawn(void)
    {
        if (!app())
            return;

        _private::app->spawn();
    }

    void exec(QRunnable *task)
    {
        if (!app())
            return;

        _private::app->exec(task);
    }

    void unspawn(void)
    {
        if (!app())
            return;

        _private::app->unspawn();
    }

    namespace communicator {
        namespace _private {
            dtkDistributedCommunicatorPluginFactory factory;
            dtkDistributedCommunicatorPluginManager manager;
            dtkDistributedCommunicator *communicator = NULL;
        }

        dtkDistributedCommunicatorPluginFactory& pluginFactory(void)
        {
            return _private::factory;
        }

        dtkDistributedCommunicatorPluginManager& pluginManager(void)
        {
            return _private::manager;
        }

        void setVerboseLoading(bool verbose)
        {
            _private::manager.setVerboseLoading(verbose);
        }

        void initialize(const QString& path)
        {
            QString real_path = path;
            pluginFactory().record("qthread", qthDistributedCommunicatorCreator);

            if (path.isEmpty()) {
                dtkDistributedSettings settings;
                settings.beginGroup("communicator");
                real_path = settings.value("plugins").toString();
                settings.endGroup();

                if (real_path.isEmpty()) {
                    real_path = QDir(DTK_INSTALL_PREFIX).filePath("plugins/dtkDistributed");
                    dtkDebug() << "no plugin path configured, use default:" << real_path ;
                }

                pluginManager().initialize(real_path);
            } else {
                pluginManager().initialize(path);
            }
        }
        // used to dtkDistributedGuiApplication: we can't link here to dtkWidgets so we need a setter
        void setInstance(dtkDistributedCommunicator *comm)
        {
            _private::communicator = comm;
        }

        dtkDistributedCommunicator *instance(void)
        {
            dtkDistributedApplication *app = dtkDistributed::app();

            if (_private::communicator) {
                return _private::communicator;
            } else if (app) {
                _private::communicator = app->communicator();
            } else {
                dtkInfo() << "no communicator, no application: create a default qthread communicator";
                dtkDistributedSettings settings;
                dtkDistributed::communicator::initialize(settings.value("plugins").toString());
                _private::communicator = dtkDistributed::communicator::pluginFactory().create("qthread");
            }

            return _private::communicator;
        }
    }
    namespace controller {
        namespace _private {
            dtkDistributedController *controller = NULL;
            QThread *controllerThread = NULL;
            QMutex mutex;
        }
        dtkDistributedController *instance(void)
        {
            QMutexLocker locker(&_private::mutex);
            if (_private::controller) {
                return _private::controller;
            } else {
                dtkInfo() << "no controller: create a default controller in its own thread";
                _private::controller = dtkDistributedController::instance();
                _private::controllerThread = new QThread();
                _private::controller->moveToThread(_private::controllerThread);

                QObject::connect(_private::controllerThread, SIGNAL(finished()), _private::controllerThread, SLOT(deleteLater()));
                _private::controllerThread->start();
                return _private::controller;
            }
        }

        bool connectSrv(const QUrl& server, bool ssh_rank, bool emit_connected)
        {
            bool res;
            QMetaObject::invokeMethod(_private::controller, "connectSrv", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, res),
                                      Q_ARG(QUrl, server), Q_ARG(bool, ssh_rank), Q_ARG(bool, emit_connected) );
            return res;
        }

        bool deploy(const QUrl& server, QString type, bool ssh_tunnel, QString path, QString loglevel)
        {
            bool res;
            QMetaObject::invokeMethod(_private::controller, "deploy", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, res),
                                      Q_ARG(QUrl, server), Q_ARG(QString, type), Q_ARG(bool, ssh_tunnel), Q_ARG(QString, path), Q_ARG(QString, loglevel) );
            return res;
        }
        bool submit(const QUrl& server, const QByteArray& resources, const QString& submit_id)
        {
            bool res;
            QMetaObject::invokeMethod(_private::controller, "submit", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, res),
                                      Q_ARG(QUrl, server), Q_ARG(QByteArray, resources), Q_ARG(QString, submit_id) );
            return res;
        }
    }

}
