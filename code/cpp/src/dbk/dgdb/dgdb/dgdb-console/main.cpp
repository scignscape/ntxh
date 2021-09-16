
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include <QDebug>

#include <QFileInfo>
#include <QDirIterator>

#include <QString>
#include <QDataStream>

#include "tkrzw_dbm_hash.h"

#include "dgdb/dgdb-location-structure.h"
#include "dgdb/dgdb-database-instance.h"

#include "dgdb/dgdb-hypernode.h"


using namespace tkrzw;

int main(int argc, char *argv[])
{
 DGDB_Location_Structure dls;

 //dls.set_raw_code();

 dls.set_primary_field_id(33, DGDB_Location_Structure::Field_Id_Options::Mapped_Field_Name);
 dls.set_secondary_field_id(44, DGDB_Location_Structure::Field_Id_Options::Negative_Raw_Array_Position);

// QPair<DGDB_Location_Structure::Field_Id_Options, u2> pr1 = dls.get_primary_field_id();
// QPair<DGDB_Location_Structure::Field_Id_Options, u2> pr2 = dls.get_secondary_field_id();

// qDebug() << dls.raw_code();
//// qDebug() << (u1) pr1.first << pr1.second;
// // qDebug() << (u1) pr2.first << pr2.second;

 dls.set_node_id(1001);

 // qDebug() << dls.raw_code();

 dls.set_data_options(DGDB_Location_Structure::Data_Options::Shm_Pointer_With_Size);

 // // qDebug() << dls.raw_code();
 QPair<DGDB_Location_Structure::Data_Options, u4> pr3 = dls.get_node_id();


 QPair<DGDB_Location_Structure::Field_Id_Options, u2> pr1 = dls.get_primary_field_id();
 QPair<DGDB_Location_Structure::Field_Id_Options, u2> pr2 = dls.get_secondary_field_id();

 qDebug() << (u1) pr1.first << pr1.second;
 qDebug() << (u1) pr2.first << pr2.second;
 qDebug() << (u1) pr3.first << pr3.second;




 return 0;
}


int main1(int argc, char *argv[])
{
 DGDB_Database_Instance ddi(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.check_construct_files();
 ddi.check_interns_dbm();
 ddi.check_nodes_dbm();
 ddi.read_hypernode_count_status();
 ddi.read_interns_count_status();

 DGDB_Hypernode* dgh = ddi.new_hypernode();
 ddi.set_property(dgh, "test", 78);

 QVariant qv = ddi.get_property(dgh, "test");

 qDebug() << "qv = " << qv;

// s4 st = ddi.read_hypernode_count_status();
// qDebug() << "st = " << st;

// ddi.store_hypernode_count_status(55);
// s4 st1 = ddi.read_hypernode_count_status();
// qDebug() << "st1 = " << st1;


// DGDB_Location_Structure dls;

// //dls.set_raw_code();

// dls.set_primary_field_id(33, DGDB_Location_Structure::Field_Id_Options::Interned_Field_Name);
// dls.set_secondary_field_id(44, DGDB_Location_Structure::Field_Id_Options::Offset_Array_Position);

// QPair<DGDB_Location_Structure::Field_Id_Options, u2> pr1 = dls.get_primary_field_id();
// QPair<DGDB_Location_Structure::Field_Id_Options, u2> pr2 = dls.get_secondary_field_id();

// qDebug() << dls.raw_code();
// qDebug() << (u1) pr1.first << pr1.second;
// qDebug() << (u1) pr2.first << pr2.second;

 return 0;

}
