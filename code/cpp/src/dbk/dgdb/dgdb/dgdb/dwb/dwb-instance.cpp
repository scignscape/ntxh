
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dwb-instance.h"

//#include <sys/types.h>
//#include <sys/ipc.h>
#include <sys/shm.h>

#include <QFile>
#include <QDebug>

extern "C" {
#include "whitedb/_whitedb.h"
}



DWB_Instance::DWB_Instance(QString config_path, QString restore_path)
  :  config_path_(config_path),
     restore_path_(restore_path), wdb_instance_(nullptr)
{

}


DWB_Instance::_DB_Create_Status DWB_Instance::check_init()
{
 ftok_key_ = ftok(config_path_.toLatin1().data(), _FTOK_CHAR);

 if(ftok_key_ == -1)
   return _DB_Create_Status::FTOK_Failed;

 QByteArray qba = QByteArray::number(ftok_key_);

 if(( wdb_instance_ = wg_attach_existing_database(qba.data()) ))
 {
  return _DB_Create_Status::Attached;
 }

 if(( wdb_instance_ = wg_attach_database(qba.data(), 0) ))
 {
  QFile qf(restore_path_);
  if(qf.size() == 0)
    return _DB_Create_Status::Created_New;

  wg_int restore_result = wg_import_dump(wdb_instance_, restore_path_.toLatin1().data());
  if(restore_result == 0)
    return _DB_Create_Status::Created_Via_Restore;

  if(restore_result == -1)
    return _DB_Create_Status::Created_Restore_Failed;

  if(restore_result == -2)
     return _DB_Create_Status::Create_And_Restore_Failed;

  // // this should never be reached ...
  qDebug() << "Unexpected WhiteDB restore condition ...";
  return _DB_Create_Status::Created_New;
 }

 return _DB_Create_Status::Attach_Failed;
}

