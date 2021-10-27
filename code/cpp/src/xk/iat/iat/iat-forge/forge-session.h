
#ifndef FORGE_SESSION__H
#define FORGE_SESSION__H

#include <QStringList>

#include "accessors.h"
#include "global-types.h"

#include <QNetworkAccessManager>

#include <QObject>

//struct _QPrivateSignal_ { private: explicit _QPrivateSignal_(QPrivateSignal = {}){} };

#define  USE_PRIVATE_SIGNALS \
struct _QPrivateSignal_ { explicit _QPrivateSignal_(QPrivateSignal = {}){} };

//struct _QPrivateSignal_ { private: explicit _QPrivateSignal_(QPrivateSignal){} }; \
//static _QPrivateSignal_ _to_prv_(QPrivateSymbol ps) { return _QPrivateSignal_(ps);}

class Forge_Bucket;

class Forge_Session : public QObject
{
 Q_OBJECT

 USE_PRIVATE_SIGNALS

 QString forge_client_id_;
 QString forge_client_secret_;

 QString token_type_;
 u4 expires_in_; // = json_object["expires_in"].toInt();
 QString access_token_; // = json_object["access_token"].toString();

 QNetworkAccessManager qnam_;

 QStringList scopes_;

 enum class TOKEN_CONTEXT
 {
  TWO_LEGGED = 2,
  THREE_LEGGED
 };

 enum class DATA
 {
    READ = 0,
    WRITE,
    CREATE,
    SEARCH,
    LAST
};


 enum class BUCKET : u1
 {
    CREATE = static_cast<int>(DATA::LAST),
    READ,
    UPDATE,
    DELETE,
    LAST

 };

 ENUM_PLUS_MACRO(BUCKET)

 enum class CODE
 {
    ALL = static_cast<int>(BUCKET::LAST),
    LAST
 };

 enum class ACCOUNT
 {
    READ = static_cast<int>(CODE::LAST),
    WRITE,
    LAST
 };

 enum class USER_PROFILE
 {
    READ = static_cast<int>(ACCOUNT::LAST),
    LAST
 };

// QString last_successful_save_path_;

public:

 Forge_Session(QString forge_client_id = {}, QString forge_client_secret = {});

 ACCESSORS(QString ,token_type)
 ACCESSORS(u4 ,expires_in) // = json_object["expires_in"].toInt();
 ACCESSORS(QString ,access_token) // = json_object["access_token"].toString();

 ACCESSORS(QString ,forge_client_id)
 ACCESSORS(QString ,forge_client_secret)
// ACCESSORS(QString ,last_successful_save_path)

 static QString default_upload_folder();

 QString client_id_prepend(QString s)
 {
//
  return forge_client_id_.toLower() + ".-" + s;
//  return forge_client_id_.toLower() + ".." + s;
 }

 void send_post_request(QString url, QMap<QString, QString> raw_headers,
   QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
   QMap<QString, QString> content_params,
   std::function<void(const QByteArray&)> cb);

 void send_upload_request(QString url, QMap<QString, QString> raw_headers,
   QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
   QString file_path,
   std::function<void(const QByteArray&)> cb);

 void send_download_request(QString url, QMap<QString, QString> raw_headers,
   QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
   QString save_path,
   std::function<void(int)> cb);

 void send_request(QString method, QString url,
   QMap<QString, QString> raw_headers,
   QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
   QByteArray content,
   std::function<void(const QByteArray&)> cb);

 void send_request(QString method, QString url,
   QMap<QString, QString> raw_headers,
   QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
   QString content,
   std::function<void(const QByteArray&)> cb)
 {
  send_request(method, url, raw_headers, known_headers, content.toLatin1(), cb);
 }

 void send_post_request(QString url,
   QMap<QString, QString> raw_headers,
   QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
   QString content,
   std::function<void(const QByteArray&)> cb);

 void send_json_post_request(QString url,
   QMap<QString, QString> raw_headers,
   QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
   QMap<QString, QString> content_params,
   std::function<void(const QByteArray&)> cb);

 void send_json_request(QString method, QString url,
   QMap<QString, QString> raw_headers,
   QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
   QMap<QString, QString> content_params,
   std::function<void(const QByteArray&)> cb);

 void send_get_request(QString url,
   QMap<QString, QString> raw_headers,
   QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
   std::function<void(const QByteArray&)> cb);

 void get_access_token(std::function<void()> cb = nullptr);

 void upload_file(Forge_Bucket& fb, QString file,
   std::function<void(QString,QString)> cb = nullptr);

 void download_file(Forge_Bucket& fb, QString file_name,
   QString save_path, std::function<void(QString)> cb = nullptr);

 void check_buckets(std::function<void(const QByteArray&)> cb = nullptr);
 void emit_done();

 void create_bucket(const Forge_Bucket& fb); //QString bucket_key);

Q_SIGNALS:

 void have_access_token();
 void done(_QPrivateSignal_);

};

class Forge_Runtime;
class Forge_API_Workflow;

QPair<Forge_Runtime*, Forge_API_Workflow*> init_forge(Forge_Session& fs);


#endif // FORGE_SESSION__H

