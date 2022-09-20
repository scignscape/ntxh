
#ifndef QMT_RAW_FILE_SERVER_RESPONSE__H
#define QMT_RAW_FILE_SERVER_RESPONSE__H

#include "qmt-accessors.h"
#include "qmt-global-types.h"

#include <QString>

class QMT_Server_Response;

class QMT_Raw_File_Server_Response
{ 
 QMT_Server_Response* main_response_;
 QString format_;
 QString url_path_;

 QString folder_branch_;

 QChar non_lowercase_flag_;

 s1 response_mode_;

public:

 QMT_Raw_File_Server_Response(QMT_Server_Response* main_response,
    QString format, QString url_path,
    s1 response_mode, QString folder_branch = {});

 void proceed(QString prepend = {});

 ACCESSORS(QChar ,non_lowercase_flag)
// ACCESSORS(QString ,full_content_type)
// ACCESSORS(QString ,character_set)

// ACCESSORS(QString ,content_text)
// ACCESSORS(QString ,content_file)

// ACCESSORS(QByteArray* ,binary_content)


};



#endif // QMT_SERVER_RESPONSE__H
