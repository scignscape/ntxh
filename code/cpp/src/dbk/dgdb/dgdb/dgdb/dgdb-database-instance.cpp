
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-database-instance.h"

#include <QDir>
#include <QFileInfo>
#include <QDebug>

#include "dgdb-location-structure.h"

#include "dwb/dwb-instance.h"



//#include <string_view>

#include "dgdb-record-processors.h"

#include "dtb/dtb-package.h"

#include "dgdb-hypernode.h"

#include "types/dh-type-system.h"

#include <QDataStream>

//class _rec_proc : public tkrzw::DBM::RecordProcessor
//{
//public:

// ~_rec_proc () = default;
// std::string_view ProcessFull	(std::string_view key, std::string_view value)
//   Q_DECL_OVERRIDE;

// std::string_view ProcessEmpty	(std::string_view key)
//   Q_DECL_OVERRIDE;

// u4 data;

//};

//std::string_view _rec_proc::ProcessFull(std::string_view key, std::string_view value)
//{
// data = *(u4*) value.data();
// return DBM::RecordProcessor::NOOP;
// //return key;
//}

//std::string_view _rec_proc::ProcessEmpty(std::string_view key)
//{
// return DBM::RecordProcessor::NOOP;
// //return key;
//}


DgDb_Database_Instance::DgDb_Database_Instance(QString private_folder_path)
  :  private_folder_path_(private_folder_path),
     blocks_dwb_(nullptr),
     hypernode_count_status_(_unknown),
     //pinterns_count_(0), finterns_count_(0),
     type_system_(nullptr),
     dtb_package_(nullptr)
{
}

void DgDb_Database_Instance::init_type_system()
{
 type_system_ = new DH_Type_System;
}

void DgDb_Database_Instance::init_dtb_package()
{
 dtb_package_ = new DTB_Package;
}

s4 DgDb_Database_Instance::read_hypernode_count_status()
{
 dtb_package_->check_info_dbm(private_folder_path_);
 hypernode_count_status_ = dtb_package_->read_hypernode_count_status();
}

void DgDb_Database_Instance::read_interns_count_status()
{
 dtb_package_->read_interns_count_status(); //pinterns_count_, finterns_count_);
}

void DgDb_Database_Instance::store_hypernode_count_status(u4 count)
{
 dtb_package_->store_hypernode_count_status(count);
}

void DgDb_Database_Instance::check_nodes_dbm()
{
 dtb_package_->check_nodes_dbm(private_folder_path_);
}

void DgDb_Database_Instance::check_interns_dbm()
{
 dtb_package_->check_interns_dbm(private_folder_path_);
}

void DgDb_Database_Instance::store_indexed_field(DgDb_Hypernode* dgh,
  u2 index, const QByteArray& value,
  DgDb_Location_Structure::Data_Options opts, QString field_name)
{
 DgDb_Location_Structure dls;

 dls.set_raw_primary_field_id(index);
 dls.set_data_options(opts);

 // dls.set_primary_field_id(index, DgDb_Location_Structure::Field_Id_Options::Raw_Index);
 dls.set_node_id(dgh->id());
 switch (opts)
 {
#define TEMP_MACRO(x) \
  case DgDb_Location_Structure::Data_Options::x: \
    store_indexed_field_<DgDb_Location_Structure::Data_Options::x>(dls, dgh, value, field_name); break;
  TEMP_MACRO(QVariant)
  TEMP_MACRO(Numeric)
  TEMP_MACRO(QString)
  TEMP_MACRO(Raw_Binary)
  TEMP_MACRO(Shm_Pointer)
  TEMP_MACRO(Shm_Pointer_With_Path_Code)
  TEMP_MACRO(Shm_Pointer_With_Size)
  TEMP_MACRO(Shm_Pointer_With_Size_and_Path_Code)
  TEMP_MACRO(Signed_Numeric)
  TEMP_MACRO(Typed_Numeric)
  TEMP_MACRO(Typed_QString)
  TEMP_MACRO(Typed_Raw_Binary)
  TEMP_MACRO(Typed_Shm_Pointer)
  TEMP_MACRO(Typed_Shm_Pointer_With_Path_Code)
  TEMP_MACRO(Typed_Shm_Pointer_With_Size)
  TEMP_MACRO(Typed_Shm_Pointer_With_Size_and_Path_Code)
 }
}


void DgDb_Database_Instance::fetch_indexed_field(DgDb_Hypernode* dgh,
  u2 index, QByteArray& value,
  DgDb_Location_Structure::Data_Options opts)
{
 DgDb_Location_Structure dls;
 dls.set_primary_field_id(index, DgDb_Location_Structure::Field_Id_Options::Raw_Index);
 dls.set_node_id(dgh->id());
 dls.set_data_options(opts);
 fetch_node_data(dls, value);
}


void DgDb_Database_Instance::fetch_indexed_field(DgDb_Hypernode* dgh, u2 index,
  DgDb_Location_Structure::Field_Id_Options fio,
  QByteArray& value,
  DgDb_Location_Structure::Data_Options opts)
{
 DgDb_Location_Structure dls;
 dls.set_primary_field_id(index, fio);
 dls.set_node_id(dgh->id());
 dls.set_data_options(opts);
 fetch_node_data(dls, value);
}

void DgDb_Database_Instance::fetch_indexed_field(DgDb_Hypernode* dgh, u2 index,
  DgDb_Location_Structure::Field_Id_Options fio,
  QByteArray& value, void*& pv,
  DgDb_Location_Structure::Data_Options opts)
{
 DgDb_Location_Structure dls;
 dls.set_primary_field_id(index, fio);
 dls.set_node_id(dgh->id());
 dls.set_data_options(opts);
 fetch_node_data(dls, pv);
 value = QByteArray( (char*) pv, 2);
}

DH_Type* DgDb_Database_Instance::get_type_by_name(QString tn, QString* res)
{
 return type_system_->get_type_by_name(tn, res);
}

DgDb_Hypernode* DgDb_Database_Instance::new_hypernode_(DH_Type* dht)
{
 DgDb_Hypernode* result = new_hypernode();
 result->set_dh_type(dht);
 return result;
}

DgDb_Hypernode* DgDb_Database_Instance::new_hypernode()
{
 ++hypernode_count_status_;
 DgDb_Hypernode* result = new DgDb_Hypernode(hypernode_count_status_);
 return result;
}



u2 DgDb_Database_Instance::check_field_id(QString key)
{
 return dtb_package_->check_field_id(key);
// auto it = field_ids_.find(key);
// if(it == field_ids_.end())
// {
//  ktype_<u2>::get kg;
//  Status st = finterns_dbm_->Process((char*)key.data(), &kg, true);
//  if(st == Status::NOT_FOUND_ERROR)
//  {

//  }
//  field_ids_[key] = kg.data();
//  return kg.data();
// }
// return *it;
}

u2 DgDb_Database_Instance::check_property_id(QString key)
{
 return dtb_package_->check_property_id(key);
// auto it = property_ids_.find(key);
// if(it == property_ids_.end())
// {
//  ktype_<u2>::get kg;
//  std::string_view kview((char*)key.data(), key.size() * 2);
//  Status st = pinterns_dbm_->Process(kview, &kg, false);
//  if(st == Status::BROKEN_DATA_ERROR)
//  {
//   ktype_<u2>::set ks(*pinterns_dbm_);
//   ++pinterns_count_;
//   ks(key, pinterns_count_);
//   property_ids_[key] = pinterns_count_;
//   return pinterns_count_;
//  }
//  property_ids_[key] = kg.data();
//  return kg.data();
// }
// return *it;
}

void DgDb_Database_Instance::fetch_node_data(DgDb_Location_Structure dls, QByteArray& result)
{
 dtb_package_->fetch_node_data(dls, result);
// std::string key(IntToStrBigEndian(dls.raw_code()));
// //std::string_view sval((char*)value.data(), value.size());
// //nodes_dbm_->Get(key, sval, true);

// ktype_<QByteArray*>::get kg(&result);

// Status st = nodes_dbm_->Process(key, &kg, true);

}


void DgDb_Database_Instance::fetch_node_data(DgDb_Location_Structure dls, QVariant& result)
{
 dtb_package_->fetch_node_data(dls, result);
// std::string key(IntToStrBigEndian(dls.raw_code()));
// //std::string_view sval((char*)value.data(), value.size());
// //nodes_dbm_->Get(key, sval, true);

// //std::string value;
// ktype_<QVariant>::get kg;

// //Status st = nodes_dbm_->Get(key, &value);

// Status st = nodes_dbm_->Process(key, &kg, true);

// result = kg.data();

 //result = kg.data();
// QByteArray qba(kg.data(), value.size());
// QDataStream qds(qba);
// qds >> result;
}


void DgDb_Database_Instance::store_node_data(DgDb_Location_Structure dls, const QByteArray& value)
{
 dtb_package_->store_node_data(dls, value);

// std::string key(IntToStrBigEndian(dls.raw_code()));
// std::string_view sval((char*)value.data(), value.size());
// nodes_dbm_->Set(key, sval, true);

// ktype_<n8>::set ks(*nodes_dbm_);
// ks();
}

void DgDb_Database_Instance::store_node_data(DgDb_Location_Structure dls, void* value)
{
 dtb_package_->store_node_data(dls, value);
// std::string key(IntToStrBigEndian(dls.raw_code()));
// std::string_view sval((char*)&value, sizeof(void*));
// nodes_dbm_->Set(key, sval, true);
}


void DgDb_Database_Instance::fetch_node_data(DgDb_Location_Structure dls, void*& result)
{
 dtb_package_->fetch_node_data(dls, result);
// std::string key(IntToStrBigEndian(dls.raw_code()));
// //std::string_view sval((char*)value.data(), value.size());
// //nodes_dbm_->Get(key, sval, true);

// ktype_<void*>::get kg(&result);

// Status st = nodes_dbm_->Process(key, &kg, true);

// result = kg.data();
}



void DgDb_Database_Instance::store_node_data(DgDb_Location_Structure dls, QVariant value)
{
 QByteArray qba;
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << value;
 store_node_data(dls, qba);
}

void DgDb_Database_Instance::set_property(DgDb_Hypernode* hypernode, QString key, QVariant value)
{
 u2 id = check_property_id(key);

 DgDb_Location_Structure dls;
 dls.set_primary_field_id(id, DgDb_Location_Structure::Field_Id_Options::Interned_Property_Name);

 dls.set_node_id(hypernode->id());

 store_node_data(dls, value);
}


QVariant DgDb_Database_Instance::get_property(DgDb_Hypernode* hypernode, QString key)
{
 u2 id = check_property_id(key);

 DgDb_Location_Structure dls;
 dls.set_primary_field_id(id, DgDb_Location_Structure::Field_Id_Options::Interned_Property_Name);

 dls.set_node_id(hypernode->id());

 QVariant result;
 fetch_node_data(dls, result);

 return result;
}



u1 DgDb_Database_Instance::check_construct_dwb_files(QDir qdir)
{
 u1 result = 0;
 qdir.cd("dwb/blocks");
 static QStringList files {"_config", "_restore"}; //, "_properties", "_fields"};

 for(QString f : files)
 {
  if(!qdir.exists(f))
  {
   QFile file(qdir.absoluteFilePath(f));
   if(file.open(QFile::ReadWrite))
     file.close();
   else
   {
    return 0;
   }
  }
  ++result;
 }
 return result;
}


void DgDb_Database_Instance::init_dwb_blocks()
{
 blocks_dwb_ = new DWB_Instance(confirmed_private_folder_path_
   + "/dwb/blocks/_config", confirmed_private_folder_path_ + "/dwb/blocks/_restore");

 DWB_Instance::_DB_Create_Status cst = blocks_dwb_->check_init();
 if(! ((u1)cst & 7) )
 {
  // //  unusual condition on the whitedb ...
  qDebug() << "WhiteDB Blocks Database not fully initialized";
 }
}


void DgDb_Database_Instance::check_construct_files()
{
 QDir qdir(private_folder_path_);
 static QStringList files {"_pinterns", "_finterns", "_info", "_nodes"};
 if(qdir.exists())
 {
  for(QString f : files)
  {
   if(!qdir.exists(f))
   {
    QFile file(qdir.absoluteFilePath(f));
    if(file.open(QFile::ReadWrite))
      file.close();
    else
    {
     hypernode_count_status_ = _file_create_failed;
     break;
    }
   }
  }
  if(!qdir.exists("dwb"))
  {
   if(!qdir.mkpath("./dwb"))
   {
    hypernode_count_status_ = _dwb_folder_create_failed;
    return;
   }
  }
 }
 else
 {
  if(!qdir.mkpath("."))
  {
   hypernode_count_status_ = _folder_create_failed;
   return;
  }
  if(!qdir.mkpath("./dwb"))
  {
   hypernode_count_status_ = _dwb_folder_create_failed;
   return;
  }

  // //  no need to check if the files exist
  for(QString f : files)
  {
   QFile file(qdir.absoluteFilePath(f));
   if(file.open(QFile::ReadWrite))
     file.close();
   else
   {
    hypernode_count_status_ = _file_create_failed;
    break;
   }
  }
 }

 if(!qdir.mkpath("./dwb/blocks"))
 {
  hypernode_count_status_ = _dwb_subfolder_create_failed;
  return;
 }

 if(!check_construct_dwb_files(qdir))
 {
  hypernode_count_status_ = _dwb_file_create_failed;
  return;
 }

 QFileInfo qfi(private_folder_path_);
 confirmed_private_folder_path_ = qfi.canonicalFilePath();
}

