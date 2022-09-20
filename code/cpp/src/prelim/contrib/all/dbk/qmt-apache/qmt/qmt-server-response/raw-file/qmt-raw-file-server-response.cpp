
#include "qmt-raw-file-server-response.h"

#include "qmt-server-response.h"

#include "qmt-global-types.h"

#include <QDebug>

#include <QFile>

#include <QDateTime>

#include <syslog.h>

#define DEFAULT_FOLDER_BRANCH "public"

QMT_Raw_File_Server_Response::QMT_Raw_File_Server_Response(QMT_Server_Response* main_response,
  QString format, QString url_path, s1 response_mode, QString folder_branch)
  :  main_response_(main_response),
     format_(format), url_path_(url_path), response_mode_(response_mode) //, binary_content_(nullptr)
{
 if(folder_branch.isEmpty())
   folder_branch_ = DEFAULT_FOLDER_BRANCH;
 else
   folder_branch_ = folder_branch;
}


void QMT_Raw_File_Server_Response::proceed(QString prepend)
{
 QString path = url_path_;
 if(path.startsWith('/'))
 {
  path.prepend("%1/%2"_qt
    .arg(prepend.isEmpty()?
     PREFERRED_SERVER_FILES_FOLDER : prepend)
    .arg(folder_branch_));
 }

 if(!format_.isEmpty())
   path +=
     (non_lowercase_flag_.isNull()? format_.toLower() : format_).prepend('.');

 //QMT_Server_Response::Response_Modes rm {response_mode_};

 switch ((QMT_Server_Response::Response_Modes) response_mode_)
 {
 case QMT_Server_Response::Response_Modes::N_A:
   main_response_->text_html_utf8_error(); break;
 case QMT_Server_Response::Response_Modes::Show:
   main_response_->init_content_file_with_type(format_, path);
   break;
 case QMT_Server_Response::Response_Modes::Show_Base32:
   //? not implemented yet ...
   break;
 case QMT_Server_Response::Response_Modes::Info:
   main_response_->text_html_utf8("Request format: %1, path: %2"_qt
     .arg(format_).arg(path));
   break;
 case QMT_Server_Response::Response_Modes::Info_Verbose:
   main_response_->text_html_utf8("(Verbose not yet implemented) Request format: %1, path: %2"_qt
     .arg(format_).arg(path));
   break;
 }

}

