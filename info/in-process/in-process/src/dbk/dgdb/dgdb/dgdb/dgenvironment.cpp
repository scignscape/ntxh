
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgenvironment.h"

#include "dgdb-instance.h"

KANS_(DGDB)

DgDb_Instance* DGEnvironment(QString path)
{
 DgDb_Instance* result = new DgDb_Instance;
 result->set_db_root_folder(path);
 return result; 
}

_KANS(DGDB)


