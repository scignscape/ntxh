
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-database-instance.h"

#include <QDir>
#include <QFileInfo>

#include "dgdb-location-structure.h"


#include "tkrzw/tkrzw_dbm.h"

using namespace tkrzw;

#include <string_view>

#include "dgdb-record-processors.h"

#include "dgdb-hypernode.h"

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


DGDB_Database_Instance::DGDB_Database_Instance(QString private_folder_path)
  :  private_folder_path_(private_folder_path),
     hypernode_count_status_(_unknown), info_dbm_(nullptr),
     nodes_dbm_(nullptr),
     pinterns_dbm_(nullptr), finterns_dbm_(nullptr),
     pinterns_count_(0), finterns_count_(0)
{
}

s4 DGDB_Database_Instance::read_hypernode_count_status()
{
 check_info_dbm();
 ktype_<u4>::get kg;
 info_dbm_->Process(":_hypernode_count", &kg, true);
 hypernode_count_status_ = (s4) kg.data();
 return hypernode_count_status_;
}

void DGDB_Database_Instance::read_interns_count_status()
{
 check_info_dbm();
 static u2 kg_default = 0;
 ktype_<u2>::get kg (&kg_default);
 info_dbm_->Process(":_pinterns_count", &kg, true);
 pinterns_count_ = kg.data();
 kg.reset();
 info_dbm_->Process(":_finterns_count", &kg, true);
 finterns_count_ = kg.data();
 kg.reset();
}

void DGDB_Database_Instance::store_hypernode_count_status(u4 count)
{
 //HashDBM* dbm =
 check_info_dbm();

 // //  possibilities for other range checking as well ...
 u4 c = count & 0b0011'1111'1111'1111'1111'1111'1111'1111;

 ktype_<u4>::set ks(*info_dbm_);

 ks(":_hypernode_count", c);
}


DGDB_Hypernode* DGDB_Database_Instance::new_hypernode()
{
 ++hypernode_count_status_;
 DGDB_Hypernode* result = new DGDB_Hypernode(hypernode_count_status_);
 return result;
}


void DGDB_Database_Instance::check_interns_dbm()
{
 check_internal_dbm("_pinterns", pinterns_dbm_);
 check_internal_dbm("_finterns", finterns_dbm_);
 //return interns_dbm_;
}

HashDBM* DGDB_Database_Instance::check_info_dbm()
{
 check_internal_dbm("_info", info_dbm_);
 return info_dbm_;
}

HashDBM* DGDB_Database_Instance::check_nodes_dbm()
{
 check_internal_dbm("_nodes", nodes_dbm_);
 return info_dbm_;
}

void DGDB_Database_Instance::check_internal_dbm(QString which, tkrzw::HashDBM*& result)
{
 if(result)
 {
  if(!result->IsOpen())
    result->Open( (private_folder_path_ + "/" + which).toStdString(), true);
 }
 else
 {
  result = new HashDBM;
  result->Open( (private_folder_path_ + "/" + which).toStdString(), true);
 }
}


u2 DGDB_Database_Instance::check_field_id(QString key)
{
 auto it = field_ids_.find(key);
 if(it == field_ids_.end())
 {
  ktype_<u2>::get kg;
  Status st = finterns_dbm_->Process((char*)key.data(), &kg, true);
  if(st == Status::NOT_FOUND_ERROR)
  {

  }
  field_ids_[key] = kg.data();
  return kg.data();
 }
 return *it;
}

u2 DGDB_Database_Instance::check_property_id(QString key)
{
 auto it = property_ids_.find(key);
 if(it == property_ids_.end())
 {
  ktype_<u2>::get kg;
  std::string_view kview((char*)key.data(), key.size() * 2);
  Status st = pinterns_dbm_->Process(kview, &kg, false);
  if(st == Status::BROKEN_DATA_ERROR)
  {
   ktype_<u2>::set ks(*pinterns_dbm_);
   ++pinterns_count_;
   ks(key, pinterns_count_);
   property_ids_[key] = pinterns_count_;
   return pinterns_count_;
  }
  property_ids_[key] = kg.data();
  return kg.data();
 }
 return *it;
}


void DGDB_Database_Instance::get_node_data(DGDB_Location_Structure dls, QVariant& result)
{
 std::string key(IntToStrBigEndian(dls.raw_code()));
 //std::string_view sval((char*)value.data(), value.size());
 //nodes_dbm_->Get(key, sval, true);

 std::string value;
 ktype_<QVariant>::get kg;

 Status st = nodes_dbm_->Get(key, &value);

 Status st1 = nodes_dbm_->Process(key, &kg, true);

 result = kg.data();

 //result = kg.data();
// QByteArray qba(kg.data(), value.size());
// QDataStream qds(qba);
// qds >> result;
}


void DGDB_Database_Instance::store_node_data(DGDB_Location_Structure dls, QByteArray& value)
{
 std::string key(IntToStrBigEndian(dls.raw_code()));
 std::string_view sval((char*)value.data(), value.size());
 nodes_dbm_->Set(key, sval, true);
// ktype_<n8>::set ks(*nodes_dbm_);
// ks();
}

void DGDB_Database_Instance::store_node_data(DGDB_Location_Structure dls, QVariant value)
{
 QByteArray qba;
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << value;
 store_node_data(dls, qba);
}

void DGDB_Database_Instance::set_property(DGDB_Hypernode* hypernode, QString key, QVariant value)
{
 u2 id = check_property_id(key);

 DGDB_Location_Structure dls;
 dls.set_primary_field_id(id, DGDB_Location_Structure::Field_Id_Options::Interned_Property_Name);

 dls.set_node_id(hypernode->id());

 store_node_data(dls, value);
}


QVariant DGDB_Database_Instance::get_property(DGDB_Hypernode* hypernode, QString key)
{
 u2 id = check_property_id(key);

 DGDB_Location_Structure dls;
 dls.set_primary_field_id(id, DGDB_Location_Structure::Field_Id_Options::Interned_Property_Name);

 dls.set_node_id(hypernode->id());

 QVariant result;
 get_node_data(dls, result);

 return result;
}





void DGDB_Database_Instance::check_construct_files()
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
 }
 else
 {
  if(!qdir.mkpath("."))
  {
   hypernode_count_status_ = _folder_create_failed;
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
 QFileInfo qfi(private_folder_path_);
 confirmed_private_folder_path_ = qfi.canonicalFilePath();
}

