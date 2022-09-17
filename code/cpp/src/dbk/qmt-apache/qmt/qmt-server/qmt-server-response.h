
#ifndef QMT_SERVER_RESPONSE__H
#define QMT_SERVER_RESPONSE__H

#include "qmt-accessors.h"

#include <QString>

class QMT_Server_Response
{
 QString log_file_;

 QString content_type_;
 QString full_content_type_;
 QString character_set_;

 QString content_text_;
 QString content_file_;

 QByteArray* binary_content_;

 void log_or_debug(QString text);
 void log_to_logfile(QString text, int line_count);

public:

 QMT_Server_Response(QString log_file = QString());

 ACCESSORS(QString ,content_type)
 ACCESSORS(QString ,full_content_type)
 ACCESSORS(QString ,character_set)

 ACCESSORS(QString ,content_text)
 ACCESSORS(QString ,content_file)

 ACCESSORS(QByteArray* ,binary_content)

 void handle_request_from_uri(QString uri);

 QString get_default_full_content_type();
 QMap<QString, QString*>* get_field_map();

 void init_binary_content(const QByteArray& qba);


 template<typename T>
 friend T& operator << (T& lhs, const QMT_Server_Response& rhs)
 {
  lhs << (rhs.binary_content_? *rhs.binary_content_: QByteArray())
    << rhs.content_type_ << rhs.character_set_
    << rhs.full_content_type_ << rhs.content_file_
    << rhs.content_text_;
 }

 template<typename T>
 friend T& operator >> (T& lhs, QMT_Server_Response& rhs)
 {
  QByteArray qba;
  lhs >> qba
    >> rhs.content_type_ >> rhs.character_set_
    >> rhs.full_content_type_ >> rhs.content_file_
    >> rhs.content_text_;

  if(!qba.isEmpty())
  {
   rhs.init_binary_content(qba);
  }

 }


};



#endif // QMT_SERVER_RESPONSE__H
