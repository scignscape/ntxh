
#include "forge-session.h"

#include "forge-bucket.h"

#include "global-types.h"

#include <QJsonDocument>
#include <QJsonObject>

#include <QNetworkReply>

#include <QFileInfo>
#include <QDir>


#include "forge-runtime.h"
#include "forge-api-workflow.h"

QPair<Forge_Runtime*, Forge_API_Workflow*> init_forge(Forge_Session& fs)
{
 Forge_Runtime* fr = new Forge_Runtime(&fs);
 return {fr, new Forge_API_Workflow(fr)};
}

QString Forge_Session::default_upload_folder()
{
 return DEFAULT_UPLOAD_FOLDER;
}


Forge_Session::Forge_Session(QString forge_client_id, QString forge_client_secret)
  :  forge_client_id_(forge_client_id), forge_client_secret_(forge_client_secret)
{
 scopes_ = QStringList{
  "data:read",
  "data:write",
  "data:create",
  "data:search",
  "bucket:create",
  "bucket:read",
  "bucket:update",
  "bucket:delete",
  "code:all",
  "account:read",
  "account:write",
  "user-profile:read",
 };
}


void Forge_Session::download_file(Forge_Bucket& fb, QString file_name,
  QString save_path, std::function<void(QString)> cb)
{
 //last_successful_save_path_.clear();
 QFileInfo qfi(save_path);
 if(!qfi.exists())
 {
  QDir qd = qfi.absoluteDir();
  if(!qd.exists())
    qd.mkpath(".");
  QFile file(save_path);
  if(!file.open(QFile::WriteOnly))
  {
   qDebug() << "Unable to create file";
   return;
  }
  file.close();
 }
 save_path = qfi.canonicalFilePath();

 QString url = ("https://developer.api.autodesk.com/oss/v2/buckets/%1/objects/%2"_q)
   .arg(client_id_prepend(fb.bucket_key())).arg(file_name);

 send_download_request(url,
   {{"Authorization", "Bearer " + access_token_}},
  {{QNetworkRequest::ContentTypeHeader, "application/octet-stream"}},
    save_path, [cb, save_path](int len)
 {
  if(len)
  {
   qDebug() << "File saved: length " << len;
   if(cb)
     cb(save_path);
   //last_successful_save_path_ = save_path;
  }
  else
  {
   qDebug() << "File save failed";
   if(cb)
     cb({});
  }
 });

}


void Forge_Session::upload_file(Forge_Bucket& fb,
  QString file_path, std::function<void(QString,QString)> cb)
{
 QFileInfo qfi(file_path);
 file_path = qfi.canonicalFilePath();

 QString url = ("https://developer.api.autodesk.com/oss/v2/buckets/%1/objects/%2"_q)
   .arg(client_id_prepend(fb.bucket_key())).arg(qfi.fileName());

 send_upload_request(url,
   {{"Authorization", "Bearer " + access_token_}},
  {{QNetworkRequest::ContentTypeHeader, "application/octet-stream"}},
    file_path, [cb](const QByteArray& qba)
 {
  QJsonDocument doc = QJsonDocument::fromJson(qba);
  QJsonObject obj = doc.object();

  qDebug() << "qba: " << qba;
  if(cb)
   cb(obj["objectId"].toString(), obj["objectKey"].toString());
 });

}


void Forge_Session::send_json_post_request(QString url,
  QMap<QString, QString> raw_headers,
  QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
  QMap<QString, QString> content_params,
  std::function<void(const QByteArray&)> cb)
{
 send_json_request("post", url, raw_headers, known_headers, content_params, cb);
}

void Forge_Session::send_download_request(QString url, QMap<QString, QString> raw_headers,
  QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
  QString save_path,
  std::function<void(int)> cb)
{
 send_get_request(url, raw_headers, known_headers, [save_path, cb](const QByteArray& qba)
 {
  QFile file(save_path);
  if(file.open(QFile::WriteOnly))
  {
   file.write(qba);
   cb(qba.size());
   //cb("File saved: length " + QByteArray::number(qba.size()));
  }
  else
  {
   cb(0);
   //cb("File save failed");
  }
 });
}

void Forge_Session::send_json_request(QString method, QString url,
  QMap<QString, QString> raw_headers,
  QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
  QMap<QString, QString> content_params,
  std::function<void(const QByteArray&)> cb)
{
 QMapIterator<QString, QString> it(content_params);

 QJsonObject request_content;

 while(it.hasNext())
 {
  it.next();
  request_content[it.key()] = it.value();
 }
 QJsonDocument content(request_content);

 send_request(method, url, raw_headers, known_headers, content.toJson(), cb);
}


void Forge_Session::send_post_request(QString url,
  QMap<QString, QString> raw_headers,
  QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
  QString content,
  std::function<void(const QByteArray&)> cb)
{
 send_request("post", url, raw_headers, known_headers, content, cb);
}


void Forge_Session::send_request(QString method, QString url, QMap<QString, QString> raw_headers,
  QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
  QByteArray content,
  std::function<void(const QByteArray&)> cb)
{
 QNetworkRequest req;
 req.setUrl(QUrl(url));
 {
  QMapIterator<QString, QString> it(raw_headers);
  while(it.hasNext())
  {
   it.next();
   req.setRawHeader(it.key().toLatin1(), it.value().toLatin1());
  }
 }
 {
  QMapIterator<QNetworkRequest::KnownHeaders, QVariant> it(known_headers);
  while(it.hasNext())
  {
   it.next();
   req.setHeader(it.key(), it.value());
  }
 }

 if(!known_headers.contains(QNetworkRequest::ContentTypeHeader))
   req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

 if(method != "put")
   qDebug() << "request content: " << content;

 QNetworkReply* reply = (method == "post")? qnam_.post(req, content):
   (method == "put")? qnam_.put(req, content) : nullptr;


 QObject::connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
  [reply](QNetworkReply::NetworkError code)
 {
  qDebug() << "Network error: " << code << "\n";
  reply->deleteLater();
 });

 QObject::connect(reply, &QNetworkReply::readyRead, [reply, cb]()
 {
  QByteArray qba = reply->readAll();
  cb(qba);
  reply->deleteLater();
 });

}


void Forge_Session::send_upload_request(QString url, QMap<QString, QString> raw_headers,
  QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
  QString file_path,
  std::function<void(const QByteArray&)> cb)
{
 QFileInfo qfi(file_path);
 QFile file(file_path);
 if(!file.open(QIODevice::ReadOnly))
   return;

 QByteArray qba = file.readAll();

 if(!known_headers.contains(QNetworkRequest::ContentLengthHeader))
   known_headers[QNetworkRequest::ContentLengthHeader] = qba.size();

 send_request("put", url, raw_headers, known_headers, qba, cb);
}


void Forge_Session::send_post_request(QString url,
  QMap<QString, QString> raw_headers,
  QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
  QMap<QString, QString> content_params, std::function<void(const QByteArray&)> cb)
{
 QMapIterator<QString, QString> it(content_params);
 QString request_content;
 while(it.hasNext())
 {
  it.next();
  request_content += it.key() + "=" + it.value();
  if(it.hasNext())
    request_content += "&";
 }
 send_post_request(url, raw_headers, known_headers, request_content, cb);
}


void Forge_Session::send_get_request(QString url,
  QMap<QString, QString> raw_headers,
  QMap<QNetworkRequest::KnownHeaders, QVariant> known_headers,
  std::function<void(const QByteArray&)> cb)
{
 QNetworkRequest req;
 req.setUrl(QUrl(url));
 QString request_content;
 {
  QMapIterator<QString, QString> it(raw_headers);
  while(it.hasNext())
  {
   it.next();
   req.setRawHeader(it.key().toLatin1(), it.value().toLatin1());
  }
 }
 {
  QMapIterator<QNetworkRequest::KnownHeaders, QVariant> it(known_headers);
  while(it.hasNext())
  {
   it.next();
   req.setHeader(it.key(), it.value());
  }
 }

 QNetworkReply* reply = qnam_.get(req);

 QObject::connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
  [reply](QNetworkReply::NetworkError code)
 {
  qDebug() << "Network error: " << code << "\n";
  reply->deleteLater();
 });

 QObject::connect(reply, &QNetworkReply::finished, [reply, cb]()
 {
  qDebug() << "Finished: ";
  QByteArray qba = reply->readAll();
  cb(qba);
  reply->deleteLater();
 });

// uncomment to check progress before finished ...
// QObject::connect(reply, &QNetworkReply::readyRead, [reply, cb]()
// {
// });

}


void Forge_Session::check_buckets(std::function<void(const QByteArray&)> cb)
{
 send_get_request("https://developer.api.autodesk.com/oss/v2/buckets?region=US&limit=10",
   {{"Authorization", "Bearer " + access_token_}}, {}, [cb](const QByteArray& qba)
 {
  if(cb)
    cb(qba);
  else
    qDebug() << "qba: " << qba;
 });
}


void Forge_Session::emit_done()
{
 Q_EMIT done(_QPrivateSignal_{});
}


void Forge_Session::create_bucket(const Forge_Bucket& fb)
{
 static QString host = "https://developer.api.autodesk.com";
 static QString endpoint  = "/oss/v2/buckets";

 QString url = host + endpoint;
 //QString token_scope = setScopes(BUCKET::CREATE);
 QString token_scope = scopes_[+BUCKET::CREATE];

 send_json_post_request(url, {
   {"x-ads-region", "US"},
   {"Authorization", "Bearer " + access_token_}},
  {{QNetworkRequest::ContentTypeHeader, "application/json"}},
  {{"bucketKey", fb.bucket_key()},
   {"policyKey", fb.get_policy_key()}},
   [](const QByteArray& qba)
   {
    qDebug() << "Create Bucket: " << qba;
   });
}


void Forge_Session::get_access_token(std::function<void()> cb)
{
 send_post_request("https://developer.api.autodesk.com/authentication/v1/authenticate",
   {},
   {{QNetworkRequest::UserAgentHeader, "N/A"}},
   {{"client_id", forge_client_id_},
   {"client_secret", forge_client_secret_},
   {"grant_type", "client_credentials"},
   {"scope", "bucket%3Acreate%20bucket%3Aread%20data%3Awrite%20data%3Aread"}},
   [this, cb](const QByteArray& qba)
 {
  qDebug() << "qba: " << qba;

  QJsonDocument data = QJsonDocument::fromJson(qba); //json_data.toUtf8());
  QJsonObject json_object = data.object();

  token_type_ = json_object["token_type"].toString();
  expires_in_ = json_object["expires_in"].toInt();
  access_token_ = json_object["access_token"].toString();

  if(access_token_.isEmpty())
    qDebug() << "Access token error ...";
  else if(cb)
    cb();
  else
    Q_EMIT have_access_token();
 });
}




