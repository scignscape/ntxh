

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dh-annotation-environment.h"

#include <QDataStream>


#include "axfi/axfi-annotation-environment.h"

#include "dgdb/dgdb-database-instance.h"


#define DDI DgDb_Database_Instance& ddi = *dgdb_;

DH_Annotation_Environment::DH_Annotation_Environment(AXFI_Annotation_Environment* axfi_env)
  :  axfi_env_(axfi_env), dgdb_(new DgDb_Database_Instance)
{

}

DgDb_Database_Instance* DH_Annotation_Environment::dgdb(QString path)
{
 dgdb_->set_private_folder_path(path);
 return dgdb_;
}


void DH_Annotation_Environment::init_database()
{
 DDI
 ddi.init_dtb_package();
 ddi.init_type_system();
 ddi.check_construct_files();
 ddi.check_interns_dbm();
 ddi.check_nodes_dbm();
 ddi.init_indices();
 ddi.read_hypernode_count_status();
 ddi.read_interns_count_status();
 ddi.init_dwb_blocks();
}


void DH_Annotation_Environment::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
// qds << a_string_ << a_number_;


#define TEMP_MACRO(cast, type ,name) << cast name##_
// qds _Demo_Class_fm(TEMP_MACRO);
#undef TEMP_MACRO


}

void DH_Annotation_Environment::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
// qds >> a_string_ >> a_number_;


#define TEMP_MACRO(cast, type ,name) >> cast name##_
// qds _Demo_Class_fm(TEMP_MACRO);
#undef TEMP_MACRO
}



