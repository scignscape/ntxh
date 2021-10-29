
#include "forge-runtime.h"

#include "forge-session.h"

#include "forge-bucket.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QLibrary>
#include <QDebug>
#include <QGridLayout>

#include <QFileDialog>
#include <QInputDialog>
#include <QEventLoop>
#include <QPushButton>

#include <QWizard>

#include "workflow-signal-generator.h"

Forge_Runtime::Forge_Runtime(Forge_Session* session, QWidget* parent_control)
  :  session_(session), current_bucket_(nullptr), cb_(nullptr), wzcb_(nullptr),
     current_wizard_(nullptr),
     parent_control_(parent_control),
     register_cb_(nullptr), workflow_signal_generator_(nullptr)
{
#define F_MACRO(x) \
  {#x, &Forge_Runtime::x},

 f0_methods_ = {
   F_MACRO(init_wizard_mode)
   F_MACRO(show_wizard)
   F_MACRO(get_access_token)
   F_MACRO(report_current_bucket)
   F_MACRO(get_upload_file_path)
   F_MACRO(upload_file)
   F_MACRO(check_ssl_libraries)
   F_MACRO(get_download_file_name)
   F_MACRO(get_bucket_name)
   F_MACRO(check_download_file)
   F_MACRO(check_current_bucket)
   F_MACRO(get_folder_via_dialog)
   F_MACRO(wait_on_release)
   };

 f1_methods_ = {
  F_MACRO(create_bucket)
  F_MACRO(check_bucket)
  F_MACRO(check_create_bucket)
  F_MACRO(load_ssl_libraries)
  F_MACRO(set_client_id)
  F_MACRO(set_client_secret)
 };
}

//f0_methods_ = {
//  {"get_access_token", &Forge_Runtime::get_access_token},
//  {"report_current_bucket", &Forge_Runtime::report_current_bucket},
//  {"get_upload_file_path", &Forge_Runtime::get_upload_file_path},
//  {"upload_file", &Forge_Runtime::upload_file},
//  };
//f1_methods_ = {
//  {"create_bucket", &Forge_Runtime::create_bucket},
//  {"check_bucket", &Forge_Runtime::check_bucket},
//  {"check_create_bucket", &Forge_Runtime::check_create_bucket},
//  {"load_ssl_libraries", &Forge_Runtime::load_ssl_libraries},
//  {"set_client_id", &Forge_Runtime::set_client_id},
//  {"set_client_secret", &Forge_Runtime::set_client_secret},
//};

fn0 Forge_Runtime::find_f0_method(QString name)
{
 name.replace('-', '_');
 return f0_methods_.value(name);
}

fn1 Forge_Runtime::find_f1_method(QString name)
{
 name.replace('-', '_');
 return f1_methods_.value(name);
}

void Forge_Runtime::wait_on_release()
{
 qDebug() << "creating qel;";
 QEventLoop* qel = new QEventLoop;
 workflow_signal_generator_->connect(workflow_signal_generator_,
   &Workflow_Signal_Generator::held_object_released,
   [this, &qel](QObject* obj)
 {
  if(obj == current_wizard_)
  {
   qel->exit();
   cb_();
  }
 });
 qel->exec();
}

void Forge_Runtime::next_wzcall(QWizardPage* page)
{
 if(page)
 {
  qDebug() << "page id: " << page->property("page-id");
 }
 QWizardPage* cpage = current_wizard_->currentPage();
 qDebug() << "cpage id: " << cpage->property("page-id");
 qDebug() << "cpage id: " << current_wizard_->currentId();

}


void Forge_Runtime::check_current_bucket()
{
 qDebug() << "check_current_bucket";

 if(current_wizard_)
 {
  if(current_wizard_->currentId() == -1)
  {
   // // i.e., the wizard sequence hasn't started yet,
    //   from the user's point of view ...

   // // need to register this step
   register_cb_(nullptr);

   cb_();
   return;
  }
  else
  {
   _check_bucket(input_values_.value("bucket-name"));
   wzcb_(nullptr);
  }
 }
 else
 {
  check_bucket(input_values_.value("bucket-name"));
  cb_();
 }
}


void Forge_Runtime::get_bucket_name()
{
 qDebug() << "get_bucket_name";

 QString* name = new QString;

 QInputDialog* qid = new QInputDialog;
 qid->setInputMode(QInputDialog::InputMode::TextInput);
 qid->setLabelText("Enter a bucket name (FORGE storage area)");
 qid->setWindowTitle("Input Bucket Name");

 qid->connect(qid, &QInputDialog::textValueChanged, [name](QString s)
 {
  *name = s;
//  input_values_["bucket-name"] = s;
//  qDebug() << "bn: " << s;
 });

 if(current_wizard_)
 {
  qid->show();
  QWizardPage* page = new QWizardPage(current_wizard_);

  page->connect(page, &QWizardPage::completeChanged, [this, name, page]()
  {
   input_values_["bucket-name"] = *name;
   qDebug() << "bn done: " << *name;
   //delete name;
   wzcb_(page);
  });

  page->setLayout(qid->layout());
  //page->registerField("value*", page);

  add_wizard_page(page);
//  current_wizard_->addPage(page);
  qid->hide();
  register_cb_(page);
 }

 else
 {
  QDialog::DialogCode ret = (QDialog::DialogCode) qid->exec();
  if(ret == QDialog::Accepted)
  {
   if(name->isEmpty())
   {
    qDebug() << "No bucket name entered; aborting workflow";
    delete name;
    return;
   }
   else
   {
    input_values_["bucket-name"] = *name;
    delete name;
    cb_();
   }
  }
  else
  {
   qDebug() << "Input dialog canceled; aborting workflow";
   delete name;
   return;
  }
 }

 cb_();
}

void Forge_Runtime::_get_folder_via_dialog(std::function<void(QString)> cb)
{
 //QString* path = new QString;
 if(current_wizard_)
 {
  QFileDialog* qfi = new QFileDialog(current_wizard_, "Select Folder", IMAGE_FOLDER);
  qfi->setFileMode(QFileDialog::Directory);
 // qfi->show();

  QWizardPage* page = new QWizardPage(current_wizard_);

  qfi->setOption(QFileDialog::DontUseNativeDialog, true);

  QGridLayout* layout = qobject_cast <QGridLayout*>(qfi->layout());

  page->setLayout(layout);

  page->connect(page, &QWizardPage::completeChanged, [qfi, cb]()
  {
   QString path = qfi->selectedFiles().isEmpty()?
      qfi->directory().absolutePath(): qfi->selectedFiles().first();
   qDebug() << "path done: " << path;
   cb(path);
  });

//  current_wizard_->addPage(page);
  register_cb_(page);

  add_wizard_page(page);

  //qfi->hide();
 }
 else
 {
  QString path = QFileDialog::getExistingDirectory(nullptr, "Select Folder", IMAGE_FOLDER);
  cb(path);
 }
}

void Forge_Runtime::add_wizard_page(QWizardPage* page)
{
 int sz = current_wizard_->pageIds().size();
 page->setProperty("page-id", sz);
 current_wizard_->addPage(page);
}

void Forge_Runtime::get_folder_via_dialog()
{
 _get_folder_via_dialog([](QString path)
 {
  qDebug() << "path = " << path;
 });
 cb_();
}


void Forge_Runtime::get_download_file_name()
{
 qDebug() << "get-download-file-name";

 QString* text = new QString;

 QInputDialog* qid = new QInputDialog;
 qid->setInputMode(QInputDialog::InputMode::TextInput);
 qid->setLabelText("Enter a file name (remote file name to download)");
 qid->setWindowTitle("Input File Name");

 qid->connect(qid, &QInputDialog::textValueChanged, [text](QString s)
 {
  *text = s;
 });

 if(current_wizard_)
 {
  qid->show();
  QWizardPage* page = new QWizardPage(current_wizard_);
  page->setLayout(qid->layout());

  page->connect(page, &QWizardPage::completeChanged, [text, this, page]()
  {
   qDebug() << "fn done: " << *text;
   if(!text->isEmpty())
     current_file_name_ = *text;
   wzcb_(page);
   // delete text;
  });

  //current_wizard_->addPage(page);
  add_wizard_page(page);
  qid->hide();
  register_cb_(page);
  cb_();
 }
 else
 {
  QDialog::DialogCode ret = QDialog::Accepted; //(QDialog::DialogCode)
  qid->open(); //qid->exec();
  if(ret == QDialog::Accepted)
  {
   if(text->isEmpty())
   {
    qDebug() << "No file name entered; aborting workflow";
    delete text;
    return;
   }
   else
   {
    current_file_name_ = *text;
    delete text;
    cb_();
   }
  }
  else
  {
   qDebug() << "Input dialog canceled; aborting workflow";
   delete text;
   return;
  }
 }


// = QInputDialog::getText(nullptr, "Input File Name",
//   "Enter the name of a file to download");
// cb_();
}


void Forge_Runtime::init_wizard_mode()
{
 workflow_signal_generator_ = new Workflow_Signal_Generator;

 current_wizard_ = new QWizard(parent_control_);
 current_wizard_->setProperty("last-page", (u1)-1);

 current_wizard_->connect(current_wizard_,
   &QWizard::currentIdChanged, [this](int id)
 {
  u1 last_page = current_wizard_->property("last-page").toInt();
  if(last_page != (u1)-1)
  {
   QWizardPage* page = current_wizard_->page(last_page);
   // // emit signal ...
   page->completeChanged();
  }
  current_wizard_->setProperty("last-page", (u1)id);
 });


 cb_();
}

void Forge_Runtime::show_wizard()
{
 //QWizardPage
 QList<int> ids = current_wizard_->pageIds();
 if(ids.isEmpty())
 {
  qDebug() << "Empty wizard; workflow aborted!";
  return;
 }
 QWizardPage* page = current_wizard_->page(ids.last());
 QPushButton* finish = current_wizard_->findChild<QPushButton*>("qt_wizard_finish");
 finish->connect(finish, &QPushButton::clicked,
   [page, this](bool)
 {
  page->completeChanged();
  workflow_signal_generator_->emit_held_object_released();
 });
 workflow_signal_generator_->hold(current_wizard_);
 current_wizard_->show();
 cb_();
}

void copy_to_save_path(QString dir, QString file_name, QString successful_save_path)
{
 QString new_path = dir + "/" + file_name;
 qDebug() << new_path;
 qDebug() << successful_save_path;
 if(QFile::copy(successful_save_path, new_path))
   qDebug() << "File saved.";
 else
   qDebug() << "File save/copy failed.";

}

void Forge_Runtime::_check_download_file(std::function<void()> cb)
{
 QDateTime qdt = QDateTime::currentDateTime();
 QString save_path = "%1/%2/%3"_q.arg(DEFAULT_TEMP_FOLDER)
   .arg(qdt.toMSecsSinceEpoch()).arg(current_file_name_);

 session_->download_file(*current_bucket_, current_file_name_, save_path,
   [this, cb](QString successful_save_path)
 {
  cb();
  if(successful_save_path.isEmpty())
  {
   qDebug() << "Download file not found; aborting workflow";
   return;
  }
  QString dir = input_values_.value("download-folder");
  if(dir.isEmpty())
  {
   if(current_wizard_)
   {
    // // waiting on input_values_.value("download-folder");
    workflow_signal_generator_->connect(workflow_signal_generator_,
      &Workflow_Signal_Generator::input_value_changed,
      [this, successful_save_path](QString key, QVariant value)
    {
     if(key == "download-folder")
     {
      copy_to_save_path(value.toString(), current_file_name_, successful_save_path);
      wzcb_(nullptr);
     }
    });
    return;
   }
   _get_folder_via_dialog([&dir](QString path)
   {
    dir = path;
   });
  }
  //QString dir = QFileDialog::getExistingDirectory(nullptr, "Select Folder", IMAGE_FOLDER);
  if(dir.isEmpty())
  {
   qDebug() << "No save folder chosen; aborting workflow";
   return;
  }
  copy_to_save_path(dir, current_file_name_, successful_save_path);
  if(current_wizard_)
    wzcb_(nullptr);
  else
    cb_();
 });
}

void Forge_Runtime::check_download_file()
{
 if(current_wizard_)
 {
  if(current_wizard_->currentId() == -1)
  {
   // // i.e., the wizard sequence hasn't started yet,
    //   from the user's point of view ...

   // // need to register this step
   register_cb_(nullptr);

   //QString* dir = new QString;
   _get_folder_via_dialog([this](QString path)
   {
    qDebug() << "download-folder = " << path;
    input_values_["download-folder"] = path;
    workflow_signal_generator_->input_value_changed("download-folder", path);
   });

   cb_();
   return;
  }
 }

 QEventLoop qel;
 _check_download_file([&qel](){ qel.exit(); });
 qel.exec();
 //cb_();
}


void Forge_Runtime::_create_bucket(QString name)
{
 Forge_Bucket fb(session_->client_id_prepend(name));
 session_->create_bucket(fb);
}

void Forge_Runtime::create_bucket(QString name)
{
 _create_bucket(name);
 qDebug() << "Create bucket " << name;
 cb_();
}

void Forge_Runtime::check_ssl_libraries()
{
 load_ssl_libraries("%1;%2"_q.arg(LIBCRYPTO_FILE_NAME).arg(LIBSSL_FILE_NAME));
}


void Forge_Runtime::load_ssl_libraries(QString file_paths)
{
 QStringList qsl = file_paths.split(';');
 if(qsl.size() < 2)
   return;

 QLibrary libcrypto, libssl;
 libcrypto.setFileName(qsl[0]); //"/home/nlevisrael/gits/ctg-temp/ssl/install/ldir/libcrypto.so.1.1");
 libssl.setFileName(qsl[1]); //"/home/nlevisrael/gits/ctg-temp/ssl/install/ldir/libssl.so.1.1");

 libcrypto.load();
 libssl.load();

 QString qssl = QSslSocket::sslLibraryBuildVersionString();
 qDebug() << "qssl: " << qssl;
 cb_();
}

void Forge_Runtime::set_client_secret(QString secret)
{
 session_->set_forge_client_secret(secret);
 cb_();
}

void Forge_Runtime::set_client_id(QString id)
{
 session_->set_forge_client_id(id);
 cb_();
}


void Forge_Runtime::_check_bucket(QString name, const QByteArray& qba)
{
 QJsonDocument doc = QJsonDocument::fromJson(qba);
 QJsonArray arr = doc.object().value("items").toArray();
 for(const QJsonValue &bucket_info : arr)
 {
  QJsonObject obj = bucket_info.toObject();
  QString key = obj["bucketKey"].toString();
  int index = key.lastIndexOf(".-");
  if(index == -1)
   continue;
  key = key.mid(index + 2);
  if(key == name)
  {
   qDebug() << "found";
   current_bucket_ = new Forge_Bucket(key);
    // //  it seems the API uses double ...
   current_bucket_->set_created_date(obj["createdDate"].toDouble());
   break;
  }
 }
 qDebug() << "doc = " << doc;
}

void Forge_Runtime::check_create_bucket(QString name)
{
 // //  create a bucket with this name if there is no current_bucket_;
 if(current_bucket_)
 {
  cb_();
  return;
 }
 _create_bucket(name);
 check_bucket(name);
}

void Forge_Runtime::check_bucket(QString name)
{
 session_->check_buckets([this, name](const QByteArray& qba)
 {
  _check_bucket(name, qba);
  cb_();
 });
}

void Forge_Runtime::_check_bucket(QString name)
{
 // //  no callback ...
 session_->check_buckets([this, name](const QByteArray& qba)
 {
  _check_bucket(name, qba);
 });
}

void Forge_Runtime::get_upload_file_path()
{
 QString path = QFileDialog::getOpenFileName(nullptr, "Select File", DEFAULT_UPLOAD_FOLDER);
 if(!path.isEmpty())
   current_file_ = path;
 cb_();
}


void Forge_Runtime::upload_file()
{
 if(current_file_.isEmpty())
 {
  qDebug() << "No current file; aborting workflow";
  return;
 }
 qDebug() << "Uploading file: " << current_file_;
 QEventLoop qel;
 session_->upload_file(*current_bucket_, current_file_, [this, &qel]
   (QString object_id, QString object_key)
 {
  if(object_id.isEmpty())
  {
   qDebug() << "No bytes uploaded; aborting workflow";
   return;
  }
  qDebug() << "Object id for key " << object_key << " = " << object_id;
  qel.exit();
  cb_();
 });
 qel.exec();
}


void Forge_Runtime::report_current_bucket()
{
 if(!current_bucket_)
   qDebug() << "No bucket loaded!";
 else
 {
  qDebug() << QString(R"(Bucket Information:
key: %1
owner: %2
policy: %3
created: %4
                      )"_q)
  .arg(current_bucket_->bucket_key())
  .arg(current_bucket_->owner())
  .arg(current_bucket_->get_policy_key())
  .arg(current_bucket_->created_datetime().toString());
 }
 cb_();
}


void Forge_Runtime::get_access_token()
{
 session_->get_access_token(cb_);
// qDebug() << "get_access_token ";
// cb_();
}

