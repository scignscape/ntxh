
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DWB_INSTANCE__H
#define DWB_INSTANCE__H

#include <QByteArray>

#include <functional>

#include "global-types.h"

#include "accessors.h"

#include <sys/types.h>


class DWB_Instance
{
 QString config_path_;
 QString restore_path_;

 void* wdb_instance_;

 key_t ftok_key_;

public:

 DWB_Instance(QString config_path, QString restore_path);

 ACCESSORS(QString ,config_path)

 enum class _DB_Create_Status
 {
  N_A = 0, Attached = 1,
  Created_Via_Restore = 2, Created_New = 4,
  FTOK_Failed = 8, Created_Restore_Failed = 16,
  Create_And_Restore_Failed = 32, Attach_Failed = 64
 };

 _DB_Create_Status check_init();

};


#endif // DWB_INSTANCE__H


