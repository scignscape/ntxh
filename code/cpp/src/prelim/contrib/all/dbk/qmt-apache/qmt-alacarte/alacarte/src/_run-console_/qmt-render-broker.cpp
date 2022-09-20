
#include "qmt-render-broker.h"

#include "qt-logger.h"

#include "qmt-tile-object.h"

#include <QtMath>

#include "server/request_manager.hpp"


#include "general/configuration.hpp"
#include "general/geodata.hpp"

#include "server/cache.hpp"
#include "server/http_server.hpp"
#include "server/renderer/renderer.hpp"
#include "server/request_manager.hpp"
#include "server/stylesheet_manager.hpp"

#include <QFileInfo>



QMT_Render_Broker::QMT_Render_Broker(QString geodata_file, RequestManager* request_manager)
  : geodata_file_(geodata_file), zoom_(0), x_(0), y_(0), request_manager_(request_manager)
{
 shared_ptr<Configuration> config = boost::make_shared<Configuration>();

 configuration_qmap_ = QMap<QString, QString> {
  {"logfile", "/quasihome/nlevisrael/osm/alacarte/runtime/system/var/log/alacarte-maps/info.log"},
  {"access-log", "/quasihome/nlevisrael/osm/alacarte/runtime/system/var/log/alacarte-maps/access.log"},
  {"geo-data", geodata_file_},

  {"server.style-src", "/home/nlevisrael/gits/osm/alacarte-master/-run-cmake_/install/share/alacarte-maps/styles"},

 // {"server.style-src", "/home/nlevisrael/gits/osm/alacarte-master/-qlog_/test-styles"},

  {"#server.prerender-level", "12"},
  {"server.default-tile", "/home/nlevisrael/gits/osm/alacarte-master/-run-cmake_/install/share/alacarte-maps/default.png"},
  {"#server.cache-size", "1024"},
  {"server.cache-path", "/quasihome/nlevisrael/osm/alacarte/runtime/system/var/cache/alacarte-maps"},

  {"server.default-style", "default"},
  {"#server.parse-timeout", "1500"}, // // the code has default value 750



//  {"server.cache-keep-tile", "#0"},

//  cache-keep-tile

 };

 config->set_suppmental_qmap(&configuration_qmap_);

 Statistic::Init(config);

 //config.

 shared_ptr<Geodata> geodata = boost::make_shared<Geodata>();

 geodata->load(geodata_file_.toStdString());

 shared_ptr<Cache> cache = boost::make_shared<Cache>(config);
 shared_ptr<StylesheetManager> ssm = boost::make_shared<StylesheetManager>(config);
 shared_ptr<Renderer> renderer = boost::make_shared<Renderer>(geodata);


// shared_ptr<RequestManager> req_manager = make_shared<RequestManager>(config, geodata, renderer, cache, ssm);

 if(!request_manager_)
   request_manager_ = boost::make_shared<RequestManager>(this, config, geodata, renderer, cache, ssm);

 ssm->startStylesheetObserving(request_manager_);

}


void QMT_Render_Broker::generate_png()
{
// QString sfp = stylesheet_folder_path_;
// if(sfp.isEmpty())
//   sfp = configuration_qmap_.value("server.style-src");

 QString sn = stylesheet_path_name_;

 if(sn.isEmpty())
   sn = "default";

 QFileInfo qfi(current_out_file_);
 QString out_file = qfi.absoluteFilePath();

 QMT_Tile_Object_Coordinates coords {(u1)zoom_, x_, y_, &out_file};

 request_manager_->create_and_run_job(&coords, "png",
   stylesheet_folder_path_.toStdString(), sn.toStdString());

}
