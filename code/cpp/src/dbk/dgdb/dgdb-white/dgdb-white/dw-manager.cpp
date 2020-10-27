
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dw-manager.h"
#include "dw-instance.h"

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


 //WCM_Column* aqc = _this->get_column_by_name(col);
 //if(!aqc)
 //  return;
 //u4 rc = aqc->record_count();
// for(u4 i = 1; i <= rc; ++i)
// {
//  QByteArray qba;
//  _this->retrieve_indexed_record(qba, col, i);
//  fn(qba);
// }
}


