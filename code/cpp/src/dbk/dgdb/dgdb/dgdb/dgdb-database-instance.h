
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DGDB_DATABASE_INSTANCE__H
#define DGDB_DATABASE_INSTANCE__H

#include <QByteArray>
#include <QDir>

#include <functional>

#include "global-types.h"

#include "accessors.h"



#include "dgdb-location-structure.h"

#include <QVariant>

class DgDb_Hypernode;
class DWB_Instance;
class DH_Type;

class DH_Type_System; //* dht = ddi.type_system()

class DTB_Package;

class DgDb_Database_Instance
{
 QString private_folder_path_;
 QString confirmed_private_folder_path_;
 QString dwb_folder_path_;

 s4 hypernode_count_status_;
// u2 pinterns_count_;
// u2 finterns_count_;

 DTB_Package* dtb_package_;

 DWB_Instance* blocks_dwb_;

 DH_Type_System* type_system_;


 typedef void* (*get_shm_field_ptr_type)(DgDb_Database_Instance&,
   DgDb_Hypernode&, u2, QString, size_t*, n8*);

 get_shm_field_ptr_type get_shm_field_ptr_;

public:

 static constexpr s4 _unknown = -1;
 static constexpr s4 _file_create_failed = -2;
 static constexpr s4 _folder_create_failed = -3;
 static constexpr s4 _dwb_folder_create_failed = -4;
 static constexpr s4 _dwb_file_create_failed = -5;
 static constexpr s4 _dwb_subfolder_create_failed = -6;


 DgDb_Database_Instance(QString private_folder_path = {});


 ACCESSORS(QString ,private_folder_path)
 ACCESSORS(get_shm_field_ptr_type ,get_shm_field_ptr)
 ACCESSORS(DH_Type_System* ,type_system)


 DgDb_Hypernode* new_hypernode();

 DgDb_Hypernode* new_hypernode_(DH_Type* dh_type);

 DH_Type* get_type_by_name(QString tn, QString* res = nullptr);

 template<typename HYPERNODE_Type>
 DgDb_Hypernode* new_hypernode()
 {
  QString tn = QString::fromStdString(typeid(HYPERNODE_Type).name());
  QString res;
  DH_Type* dht = get_type_by_name(tn, &res);
  return new_hypernode_(dht);
 }

// {
//  QString tn = QString::fromStdString(typeid(HYPERNODE_Type).name());
//  tn = type_system_ type_name_resolutions_.value(tn, tn);

// }


 void init_dtb_package();
 void init_type_system();

 void store_indexed_field(DgDb_Hypernode* dh, u2 index,
   const QByteArray& value,
   DgDb_Location_Structure::Data_Options opts, QString field_name);


 template<DgDb_Location_Structure::Data_Options OPTS>
 void store_indexed_field_(DgDb_Location_Structure dls,
   DgDb_Hypernode* dh, const QByteArray& value, QString field_name);


 void fetch_indexed_field(DgDb_Hypernode* dgh, u2 index,
   QByteArray& value,
   DgDb_Location_Structure::Data_Options opts);

 void fetch_indexed_field(DgDb_Hypernode* dgh, u2 index,
   DgDb_Location_Structure::Field_Id_Options fio,
   QByteArray& value,
   DgDb_Location_Structure::Data_Options opts);

 void fetch_indexed_field(DgDb_Hypernode* dgh, u2 index,
   DgDb_Location_Structure::Field_Id_Options fio,
   QByteArray& value, void*& pv,
   DgDb_Location_Structure::Data_Options opts);

 u2 check_field_id(QString key);

 u2 check_property_id(QString key);
 void set_property(DgDb_Hypernode* hypernode, QString key, QVariant value);

 void check_construct_files();
 u1 check_construct_dwb_files(QDir qdir);

 s4 read_hypernode_count_status();
 void read_interns_count_status();


 void init_dwb_blocks();

 void check_interns_dbm();

 QVariant get_property(DgDb_Hypernode* hypernode, QString key);

 void check_info_dbm();
 void check_nodes_dbm();

 void store_hypernode_count_status(u4 count);
 void store_node_data(DgDb_Location_Structure dls, QVariant value);
 void store_node_data(DgDb_Location_Structure dls, const QByteArray& value);
 void store_node_data(DgDb_Location_Structure dls, void* value);

 void fetch_node_data(DgDb_Location_Structure dls, QVariant& result);
 void fetch_node_data(DgDb_Location_Structure dls, QByteArray& result);
 void fetch_node_data(DgDb_Location_Structure dls, void*& result);


};


#endif // DGDB_DATABASE_INSTANCE__H


