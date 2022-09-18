
#ifndef FORGE_RUNTIME__H
#define FORGE_RUNTIME__H

#include <QStringList>

#include "accessors.h"
#include "global-types.h"

#include "forge-api-workflow.h"

#include <functional>

class Forge_Session;
class Forge_Bucket;


class QWizard;
class QWidget;
class QWizardPage;

class Workflow_Signal_Generator;

class Forge_Runtime
{
 QWidget* parent_control_;
 Workflow_Signal_Generator* workflow_signal_generator_;

 Forge_Session* session_;

 QMap<QString, fn0> f0_methods_;
 QMap<QString, fn1> f1_methods_;

 std::function<void()> cb_;
 std::function<void(QWizardPage*)> wzcb_;

 Forge_Bucket* current_bucket_;
 QString current_file_;
 QString current_file_name_;

 QWizard* current_wizard_;

 QMap<QString, QString> input_values_;

 //Forge_API_Workflow* current_workflow_;
 std::function<void(QWizardPage*)> register_cb_;

 void _create_bucket(QString name);
 void _get_folder_via_dialog(std::function<void(QString)> cb);
 void _check_download_file(std::function<void()> cb);
 void _check_bucket(QString name, const QByteArray& qba);
 void _check_bucket(QString name);

 void add_wizard_page(QWizardPage* page);


public:

 Forge_Runtime(Forge_Session* session, QWidget* parent_control = nullptr);

 ACCESSORS(std::function<void()> ,cb)
 ACCESSORS(std::function<void(QWizardPage*)> ,wzcb)
 //void set_cb(void(*cb)()) { cb_ = cb; }

 ACCESSORS(std::function<void(QWizardPage*)> ,register_cb)


 fn0 find_f0_method(QString name);
 fn1 find_f1_method(QString name);

 void next_wzcall(QWizardPage* page);
 void check_current_bucket();

 void check_create_bucket(QString name);
 void create_bucket(QString name);
 void check_bucket(QString name);
 void load_ssl_libraries(QString file_paths);
 void check_ssl_libraries();
 void get_access_token();
 void report_current_bucket();
 void get_upload_file_path();
 void upload_file();
 void init_wizard_mode();

 void set_client_secret(QString secret);
 void set_client_id(QString id);
 void get_download_file_name();
 void get_bucket_name();
 void check_download_file();
 void show_wizard();
 void get_folder_via_dialog();
 void wait_on_release();

};

#endif // FORGE_RUNTIME__H
