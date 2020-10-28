
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DW_MANAGER__H
#define DW_MANAGER__H

#include <QMap>
#include <QString>

#include "global-types.h"

#include "accessors.h"


#include "kans.h"

KANS_(DGDB)

class WDB_Manager;

class WDB_Instance;
class DW_Instance;

class DW_Manager
{
 WDB_Manager* wdb_manager_;
 DW_Instance* dw_instance_;

 struct With_All_Tagged_Records_Package
 {
  DW_Manager* _this;
  QString tag;
  void operator <<
    (std::function<void(QByteArray&)> fn);
  void operator <<
    (std::function<void(QByteArray&, u4)> fn);
 };


public:

 DW_Manager(WDB_Manager* wdb_manager);

 u4 get_tagged_record_count(QString tag);

 void query_tagged_records(QString tag, 
   std::function<void(QByteArray&)> fn);

 void query_tagged_records(QString tag, 
   std::function<void(QByteArray&, u4)> fn);


 With_All_Tagged_Records_Package with_all_tagged_records(QString tag)
 {
  return {this, tag};
 }
};


_KANS(DGDB)


#endif // DW_MANAGER__H


