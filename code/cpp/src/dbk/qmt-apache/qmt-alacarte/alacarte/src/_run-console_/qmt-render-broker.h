
#ifndef QMT_RENDER_BROKER__H
#define QMT_RENDER_BROKER__H

#include <QString>
#include <QMap>

#include <string>

#include "qmt-accessors.h"

#include "qmt-global-types.h"

#include <boost/smart_ptr/shared_ptr.hpp>

//#include "../server/http/re

class RequestManager;


class QMT_Render_Broker
{
 QString geodata_file_;

 QString current_out_file_;

 QString stylesheet_path_name_;
 QString stylesheet_folder_path_;

 u4 zoom_;
 u4 x_;
 u4 y_;

 boost::shared_ptr<RequestManager> request_manager_;

 QMap<QString, QString> configuration_qmap_;


public:

 QMT_Render_Broker(QString geodata_file, RequestManager* request_manager = nullptr);

 ACCESSORS(QString ,geodata_file)

 ACCESSORS(QString ,current_out_file)

 ACCESSORS(QString ,stylesheet_path_name)
 ACCESSORS(QString ,stylesheet_folder_path)

 ACCESSORS(u4 ,zoom)
 ACCESSORS(u4 ,x)
 ACCESSORS(u4 ,y)

 void generate_png();


};


#endif // QMT_RENDER_BROKER__H
