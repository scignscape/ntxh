
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dw-manager.h"
#include "dw-instance.h"

#include "wdb-manager.h"



#include <QDebug>

#include "kans.h"
#include "textio.h"


USING_KANS(TextIO)

extern "C" {
#include "whitedb/_whitedb.h"
}


USING_KANS(DGDB)


DW_Manager::DW_Manager(WDB_Manager* wdb_manager)
  :  wdb_manager_(wdb_manager) 
{

}


void DW_Manager::With_All_Tagged_Records_Package::operator<<
  (std::function<void(QByteArray&)> fn)
{
 _this->query_tagged_records(tag, fn);

}

void DW_Manager::query_tagged_records(QString tag, 
  std::function<void(QByteArray&)> fn)
{
 QPair<u4, u4> range = DW_Instance::hypernodes_id_range();

  // //  column 3 is the tag column ...
 WDB_Manager::Query_Iterator* qi = wdb_manager_->new_query_iterator(tag, 
   range.first, range.second, 3);

 n8 brake = 0;

 while(brake == 0)
 {
  void* rec = wdb_manager_->cycle_query(qi);
  if(rec)
  {
   QByteArray qba;
   wdb_manager_->get_hypernode_payload(qi, qba);
   fn(qba);
  }
 }
}

void DW_Manager::query_tagged_records(QString tag, 
  std::function<void(QByteArray&, u4)> fn)
{
 QPair<u4, u4> range = DW_Instance::hypernodes_id_range();

  // //  column 3 is the tag column ...
 WDB_Manager::Query_Iterator* qi = wdb_manager_->new_query_iterator(tag, 
   range.first, range.second, 3);

 n8 brake = 0;

 u4 count = 0;
 while(brake == 0)
 {
  void* rec = wdb_manager_->cycle_query(qi);
  if(rec)
  {
   ++count;
   QByteArray qba;
   wdb_manager_->get_hypernode_payload(qi, qba);
   fn(qba, count);
  }
 }
}




