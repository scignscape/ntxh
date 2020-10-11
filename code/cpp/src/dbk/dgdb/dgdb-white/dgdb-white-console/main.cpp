
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>
#include <QByteArray>
#include <QDataStream>

#include <QDate>

#include "dgdb-white/dw-instance.h"
#include "dgdb-white/dw-record.h"


#include "dgdb-white/wdb-manager.h"
#include "dgdb-white/dgenvironment.h"

#include "dgdb-white/wdb-instance.h"

#include "global-types.h"



USING_KANS(DGDB)

int main(int argc, char* argv[])
{
 DW_Instance* dw = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/t1");

 dw->Config.flags.scratch_mode = true;
 dw->init();
 

 qDebug() << "DB root folder: " << dw->db_root_folder();

 QString test_payload = "Test Payload";
 QByteArray qba = test_payload.toLatin1();
 DW_Record dwr = dw->new_wg_hypernode_record(qba);
 qDebug() << "id: " << dwr.id();
}


