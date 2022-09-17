
#include "qmt-server-response.h"

#include "qmt-global-types.h"

#include <QDebug>

#include <QFile>

#include <QDateTime>

#include <syslog.h>


QMT_Server_Response::QMT_Server_Response(QString log_file)
  :  log_file_(log_file), binary_content_(nullptr)
{

}


void QMT_Server_Response::log_or_debug(QString text)
{
 if(log_file_.isEmpty())
 {
  if(text.endsWith('\n'))
    text.chop(1);
  qDebug() << text;
 }
 else
 {
  static int line_count = 0;
  log_to_logfile(text, ++line_count);
 }
}


void QMT_Server_Response::log_to_logfile(QString text, int line_count)
{
 QFile outfile(log_file_);

 int ok = outfile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
 if(!ok)
 {
  QString errMsg = outfile.errorString();
  syslog(LOG_INFO, "Could not open qmt log file: %s", errMsg.toStdString().c_str());
  return;
 }

 QString qmsg = "(%1) %2. %3"_qt
   .arg(QDateTime::currentDateTime().toString()).arg(line_count).arg(text);
 outfile.write(qmsg.toLatin1());

 outfile.flush();

//#endif //def HIDE
}

QMap<QString, QString*>* QMT_Server_Response::get_field_map()
{
 QMap<QString, QString*>* result = new QMap<QString, QString*>
 {
  {"content-type", &content_type_},
  {"character-set", &character_set_},
  {"content-text", &content_text_},
  {"content-file", &content_file_}
 };

 if(!full_content_type_.isEmpty())
   result->insert("full-content-type", &full_content_type_);
 return result;
}

void QMT_Server_Response::init_binary_content(const QByteArray& qba)
{
 binary_content_ = new QByteArray(qba);
}

QString QMT_Server_Response::get_default_full_content_type()
{
 if(full_content_type().isEmpty())
 {
  return "%1;charset=%2"_qt.arg(content_type_)
    .arg(character_set_);
 }
 return full_content_type_;
}

void QMT_Server_Response::handle_request_from_uri(QString uri)
{
 content_type_ = "text/html";
 character_set_ = "UTF8";
 log_or_debug("Simply returning the uri ...\n");
 content_text_ = "Request url: %1"_qt.arg(uri);
}

