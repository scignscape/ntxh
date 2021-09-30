
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

#include "conversions.h"

//#include <string_view>

#include "dgdb-record-processors.h"

#include "dgdb-data-out-stream.h"

#include "dtb/dtb-package.h"

#include "dgdb-hypernode.h"

#include "dh-stage-value.h"

#include "types/dh-type-system.h"
#include "types/dh-type.h"

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
     dtb_package_(nullptr), get_shm_field_ptr_(nullptr)
{
}


static constexpr u2 default_total_columns = 5;
// //   0         1          2       3?     4              5
// //   rec id    node id    block   msg?   branch-code    user-data


char* DgDb_Database_Instance::allocate_shm_block(DH_Type* dht, u4 dh_id,
  QString init_message, u1 max_fixed, u2 total_columns, Block_Options options)
{
 if(total_columns == 0)
 {
  total_columns = init_message.isEmpty()? default_total_columns : default_total_columns + 1;
  if(max_fixed == 0)
    max_fixed = total_columns - 1;
  u1 max_declared = dht->get_max_declared_field_column();
  total_columns += dht->get_internal_field_column_requirements();
  if(max_declared >= total_columns)
    total_columns = max_declared + 1;
 }
 return allocate_shm_block(dht->shm_block_size(), dht->shm_block_column(),
   dht->get_shm_message_column(), dh_id, init_message, max_fixed, total_columns, options);
}

char* DgDb_Database_Instance::allocate_shm_block(size_t size,
  u2 block_column, u2 message_column, u4 dh_id, QString init_message,
  u1 max_fixed, u2 total_columns, Block_Options options)
{
 if(total_columns == 0)
 {
  total_columns = init_message.isEmpty()? default_total_columns : default_total_columns + 1;
 }

 auto [rec, result] = blocks_dwb_->new_block_record(total_columns, size, block_column);
 if(options & Block_Options::Init_to_0)
   memset(result, 0, size);
 size_t current_ptr_offset = 0;
 if(options & Block_Options::Write_WhiteDB_Record)
   current_ptr_offset += blocks_dwb_->write_record_pointer_bytes(rec, result);
 if(options & Block_Options::Write_Max_Fixed)
   current_ptr_offset += blocks_dwb_->write_max_fixed(max_fixed, result + current_ptr_offset);

 u2 dh_id_column = 1;
 blocks_dwb_->write_u4_field(rec, dh_id_column, dh_id);

 if(! (init_message.isEmpty() && message_column == (u2)-1) )
 {
//  u2 mc = dh->get_shm_message_column(block_column);

  blocks_dwb_->write_str_field(rec, message_column, init_message);
 }
 return result;
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


void DgDb_Database_Instance::store_subvalue(DgDb_Hypernode* dh,
  DH_Subvalue_Field* sf, DH_Stage_Value& sv) //const QByteArray& value)
{
 DH_Type* dht = dh->dh_type();
 DH_Subvalue_Field::Write_Mode wm = sf->write_mode();
 u2 index = sf->index();

 DgDb_Location_Structure dls;
 dls.set_primary_field_id(index, DgDb_Location_Structure::Field_Id_Options::Structure_Field_Index);
 dls.set_data_options(DgDb_Location_Structure::Data_Options::Shm_Pointer);
 dls.set_node_id(dh->id());

 store_subvalue(dh, sf, dls, DgDb_Location_Structure::Data_Options::Shm_Pointer, sv); //value);
}


void DgDb_Database_Instance::store_subvalue(DgDb_Hypernode* dh,
  DH_Subvalue_Field* sf, DgDb_Location_Structure& dls,
  DgDb_Location_Structure::Data_Options opts,
  //const QByteArray& value
  DH_Stage_Value& sv)
{
 QString field_name = sf->field_name();

 switch (opts)
 {
#define TEMP_MACRO(x) \
  case DgDb_Location_Structure::Data_Options::x: \
    store_subvalue_<DgDb_Location_Structure::Data_Options::x>(dls, dh, sf, sv, field_name); break;
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

DWB_Instance* DgDb_Database_Instance::get_query_dwb(DH_Type* dht, DH_Subvalue_Field* sf)
{
 QString path = sf->checked_query_path();

 if(path.isEmpty())
 {
  path = sf->query_path();
  if(path.startsWith('&'))
  {
   path = path.mid(1);
   path.prepend(confirmed_private_folder_path_);
  }
  s4 index = path.indexOf("$type");
  if(index != -1)
  {
   path.replace(index, 5, dht->name());
  }
  sf->set_checked_query_path(path);
 }
 DWB_Instance* result = query_dwbs_.value(path);
 if(!result)
 {
  QDir qdir(path);
  if(!qdir.exists())
  {
   if(qdir.mkpath("."))
     qDebug() << "Created directory " << path;
  }
  u1 file_count = check_construct_dwb_files(qdir.absolutePath());
  if(file_count == 0)
  {
   qDebug() << "Failed to create query database files";
   return nullptr;
  }

  result = new DWB_Instance(path + "/_config", path + "/_restore");

  DWB_Instance::_DB_Create_Status cst = result->check_init();
  if(! ((u1)cst & 7) )
  {
   // //  unusual condition on the whitedb ...
   qDebug() << "WhiteDB Blocks Database not fully initialized";
  }

  qDebug() << "DWB opened with path " << path <<
    "and ftok key" << result->ftok_key();

  query_dwbs_[path] = result;
 }

 return result;
} //)


DH_Stage_Code DgDb_Database_Instance::get_stage_code(DgDb_Hypernode* dh, QString field_name)
{
 DH_Type* dht = dh->dh_type();
 DH_Subvalue_Field* sf = dht->get_subvalue_field_by_field_name(field_name);
 return get_stage_code(dht, sf);
}


DH_Stage_Code DgDb_Database_Instance::get_stage_code(DH_Type* dht, QString field_name)
{
 DH_Subvalue_Field* sf = dht->get_subvalue_field_by_field_name(field_name);
 return get_stage_code(dht, sf);
}

DH_Stage_Code DgDb_Database_Instance::get_stage_code(DH_Type* dht, DH_Subvalue_Field* sf)
{
 return sf->stage_code();
}


void DgDb_Database_Instance::store(DgDb_Hypernode* dh, QString field_or_property_name,
  DH_Stage_Value& sv) //                                 const QByteArray& value)
{
 DH_Type* dht = dh->dh_type();
 DH_Subvalue_Field* sf = dht->get_subvalue_field_by_field_name(field_or_property_name);
 if(sf)
 {
  store_subvalue(dh, sf, sv);

 }
 else
 {

 }
}


void DgDb_Database_Instance::store_indexed_field(DgDb_Hypernode* dh,
  u2 index, DH_Stage_Value& sv, // const QByteArray& value,
  DgDb_Location_Structure::Data_Options opts, QString field_name)
{
 DgDb_Location_Structure dls;

 dls.set_raw_primary_field_id(index);
 dls.set_data_options(opts);

 // dls.set_primary_field_id(index, DgDb_Location_Structure::Field_Id_Options::Raw_Index);
 dls.set_node_id(dh->id());
 switch (opts)
 {
#define TEMP_MACRO(x) \
  case DgDb_Location_Structure::Data_Options::x: \
    store_indexed_field_<DgDb_Location_Structure::Data_Options::x>(dls, dh, sv, field_name); break;
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



void DgDb_Database_Instance::fetch_subvalue(DgDb_Hypernode* dh, QString field_name,
  QByteArray& value, void*& pv)
{
 DH_Type* dht = dh->dh_type();
 if(DH_Subvalue_Field* sf = dht->get_subvalue_field_by_field_name(field_name))
   fetch_subvalue(dh, sf, value, pv);
}


DgDb_Hypernode* DgDb_Database_Instance::find_hypernode(DH_Type* dht, QString field_name,
  DH_Stage_Value& sv, void** rec)
{
 if(DH_Subvalue_Field* sf = dht->get_subvalue_field_by_field_name(field_name))
   return find_hypernode(dht, sf, sv, rec);
}

DgDb_Hypernode* DgDb_Database_Instance::find_hypernode(DH_Type* dht, DH_Subvalue_Field* sf,
  DH_Stage_Value& sv, void** rec)
{
 DH_Subvalue_Field::Write_Mode wm = sf->write_mode();

 switch (wm)
 {
 case DH_Subvalue_Field::Write_Mode::Redirect_External:
  {
   DWB_Instance* dwb = get_query_dwb(dht, sf);
   // //  assume always 2 for now ...
   static u1 rec_column = 2;
   void* qrec = dwb->find_query_record(sf->query_column(), sv);
   if(qrec)
   {
    void* result_rec = dwb->get_target_record_from_query_record(blocks_dwb_, qrec, rec_column);
    if(result_rec)
    {
     if(rec)
       *rec = result_rec;
     return get_hypernode_from_block_record(dht, result_rec);
    }
    return nullptr;
   }
   return nullptr;
  }
 }
}



DgDb_Hypernode* DgDb_Database_Instance::find_hypernode(DH_Type* dht, QString field_name,
  QString test, void** rec)
{
 if(DH_Subvalue_Field* sf = dht->get_subvalue_field_by_field_name(field_name))
   return find_hypernode(dht, sf, test, rec);
}




DgDb_Hypernode* DgDb_Database_Instance::find_hypernode(DH_Type* dht,
  DH_Subvalue_Field* sf, QString test, void** rec)
{
// u2 index = sf->index();
// DgDb_Location_Structure dls;
// dls.set_primary_field_id(index, DgDb_Location_Structure::Field_Id_Options::Structure_Field_Index);
// dls.set_node_id(dh->id());
// dls.set_data_options(DgDb_Location_Structure::Data_Options::Shm_Pointer);

// fetch_node_data(dls, pv);

 DH_Subvalue_Field::Write_Mode wm = sf->write_mode();

 switch (wm)
 {
 case DH_Subvalue_Field::Write_Mode::Redirect_External:
  {
   DWB_Instance* dwb = get_query_dwb(dht, sf);
   // //  assume always 2 for now ...
   static u1 rec_column = 2;
   void* qrec = dwb->find_query_record(sf->query_column(), test);
   if(qrec)
   {
    void* result_rec = dwb->get_target_record_from_query_record(blocks_dwb_, qrec, rec_column);
    if(result_rec)
    {
     if(rec)
       *rec = result_rec;
     return get_hypernode_from_block_record(dht, result_rec);
    }
    return nullptr;
   }
   return nullptr;
  }
 }
}


void _acc_conv(const QByteArray& source, QDataStream& target, u4 len)
{
 switch (len)
 {
 case 1: target << qba_to_u1(source); break;
 case 2: target << qba_to_u2(source); break;
 case 4: target << qba_to_u4(source); break;
 case 8: target << qba_to_n8(source); break;
 }
}


void DgDb_Database_Instance::init_hypernode_from_shm_block(DgDb_Hypernode* dh, void* rec,
  void* obj, std::function<void(void*, const QByteArray&)> cb)
{
 init_hypernode_from_shm_block(dh, QByteArray(dh->shm_block(), dh->get_shm_block_size()),
   rec, obj, cb);
}



std::function<void(void*, QByteArray&)> DgDb_Database_Instance::get_binary_encoder(DgDb_Hypernode* dh)
{
 if(DH_Type* dht = dh->dh_type())
  return dht->binary_encoder();
 return nullptr;
}


// //   currently there is no difference between
 //     the different write_mode implementations
 //     so we can use one procedure for all three ...
void _write_key_value(DgDb_Database_Instance& _this, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, char* mem)
{
 DgDb_Location_Structure dls;

 dls.set_data_options(DgDb_Location_Structure::Data_Options::Shm_Pointer);
 dls.set_primary_field_id(sf->index(), DgDb_Location_Structure::Field_Id_Options::Structure_Field_Index);
 dls.set_node_id(dh->id());

 _this.store_node_data(dls, mem);

}


template<>
void DgDb_Database_Instance::write_key_value<DH_Subvalue_Field::Write_Mode::In_Block>
  (DgDb_Hypernode* dh, DH_Subvalue_Field* sf, char* mem)
{
 _write_key_value(*this, dh, sf, mem);
}


template<>
void DgDb_Database_Instance::write_key_value<DH_Subvalue_Field::Write_Mode::Redirect_External>
  (DgDb_Hypernode* dh, DH_Subvalue_Field* sf, char* mem)
{
 _write_key_value(*this, dh, sf, mem);
}


template<>
void DgDb_Database_Instance::write_key_value<DH_Subvalue_Field::Write_Mode::Redirect_In_Record>
  (DgDb_Hypernode* dh, DH_Subvalue_Field* sf, char* mem)
{
 _write_key_value(*this, dh, sf, mem);
}


void  _acc_conv(char* mem, QDataStream& qds, u4 len)
{
 QByteArray qba;
 switch (len)
 {
 case 1: u1 u_1; qds >> u_1; qba = u1_to_qba(u_1); break;
 case 2: u2 u_2; qds >> u_2; qba = u2_to_qba(u_2); break;
 case 4: u4 u_4; qds >> u_4; qba = u4_to_qba(u_4); break;
 case 8: n8 n_8; qds >> n_8; qba = n8_to_qba(n_8); break;
 }
 memcpy(mem, qba.data(), len);
}

void DgDb_Database_Instance::init_hypernode_from_object(DgDb_Hypernode* dh, void* obj,
  std::function<void(void*, QByteArray&)> cb)
{
 QByteArray enc;
 cb(obj, enc);

 QDataStream qds(enc);

 DH_Type* dht = dh->dh_type();


 char* mem = dh->shm_block();
 if(!mem)
 {
  mem = allocate_shm_block(dht, dh->id(), "test=Ok");
  dh->set_shm_block(mem);
 }

 QVector<DH_Subvalue_Field*> sfs;
 dht->get_subvalue_fields_as_vector(sfs);

 u2 c = 0;
 for(DH_Subvalue_Field* sf : sfs)
 {
//  QByteArray temp;
//  QDataStream qds
  if(sf)
  {
   u4 s = sf->block_offset_start();
   u4 e = sf->block_offset_end();

   switch (sf->write_mode())
   {
    case DH_Subvalue_Field::Write_Mode::In_Block:
    {
     _acc_conv(mem + s, qds, e - s + 1);

     write_key_value<DH_Subvalue_Field::Write_Mode::In_Block>(dh, sf, mem + s);
    }
    break;

   case DH_Subvalue_Field::Write_Mode::Redirect_External:
   {
    DH_Stage_Value sv;
    QString value;
    qds >> value;
    store_subvalue_to_external_record(dh, sf, mem + s, sv);//value.toLatin1());
//    _acc_conv(mem + s, qds, e - s + 1);
    write_key_value<DH_Subvalue_Field::Write_Mode::Redirect_External>(dh, sf, mem + s);
//    store_node_data(dls, mem + s);
   }
   break;

   case DH_Subvalue_Field::Write_Mode::Redirect_In_Record:
   {
    DH_Stage_Value sv;
    QString value;
    qds >> value;
    store_subvalue_to_record(sf, mem + s, sv); //value.toLatin1());
//    _acc_conv(mem + s, qds, e - s + 1);
    write_key_value<DH_Subvalue_Field::Write_Mode::Redirect_In_Record>(dh, sf, mem + s);
//    store_node_data(dls, mem + s);
   }
   break;



   }
  }
 }
}

void DgDb_Database_Instance::init_hypernode_from_shm_block(DgDb_Hypernode* dh,
  const QByteArray& qba, void* rec, void* obj,
  std::function<void(void*, const QByteArray&)> cb)
{
 DH_Type* dht = dh->dh_type();

 QVector<DH_Subvalue_Field*> sfs;
 dht->get_subvalue_fields_as_vector(sfs);

 QByteArray enc;
 QDataStream qds(&enc, QIODevice::WriteOnly);

 u2 c = 0;
 for(DH_Subvalue_Field* sf : sfs)
 {
  QByteArray temp;
  if(sf)
  {
   u4 s = sf->block_offset_start();
   u4 e = sf->block_offset_end();

   temp = QByteArray(qba.mid(s, e - s + 1));
   switch (sf->write_mode())
   {
    case DH_Subvalue_Field::Write_Mode::In_Block:
    {
     _acc_conv(temp, qds, e - s + 1);
    }
    break;
   case DH_Subvalue_Field::Write_Mode::Redirect_External:
    {
     QByteArray value;
     //QByteArray qba = QByteArray( (char*) pv, 8);
     DWB_Instance* dwb = get_query_dwb(dh->dh_type(), sf);
     void* rec = dwb->get_record_from_qba(temp);
     dwb->get_qba_from_record(rec, sf->query_column(), value);

     qds << QString::fromLatin1(value);
    }
    break;
   }
  }
  ++c;
 }

 //std::function<void(void*, const QByteArray&)> cb = dht->binary_decoder();
 cb(obj, enc);

// QStringList qsl = dht->get_subvalue_field_names();
// for(QString name : qsl)
// {
//  DH_Subvalue_Field* sf = dht->get_subvalue_field_by_field_name(name);

// }

// DgDb_Data_Out_Stream ddo(qba);
// n8 nn;
// u4 uu;
// ddo /8/ nn /4/ uu;

}


DgDb_Hypernode* DgDb_Database_Instance::get_hypernode_from_block_record(DH_Type* dht, void* rec)
{
 u2 dh_id_column = 1;
 u4 id = blocks_dwb_->fetch_u4_field(rec, dh_id_column);

 DgDb_Hypernode* result = active_hypernodes_.value(id);
 if(!result)
 {
  result = new DgDb_Hypernode(id);
  auto [mem, len] = blocks_dwb_->fetch_blob_field(rec, dht->shm_block_column());
  result->set_shm_block(mem);
  //?result->set_shm_block_length(len);
  result->set_dh_type(dht);

//       QByteArray qba(mem, len);
//       init_hypernode_from_shm_block(result, qba, rec, );

    // init_hypernode_from_shm_block(result, qba, rec);

  //QByteArray qba(mem, len);
  //init_hypernode_from_shm_block(result, qba, rec);
 }
//  //  temporarily ...
//  {
//   auto [mem, len] = blocks_dwb_->fetch_blob_field(rec, dht->shm_block_column());
//   QByteArray qba(mem, len);
//   init_hypernode_from_shm_block(result, qba, rec);
//  }

 return result;
}


void* DgDb_Database_Instance::default_get_shm_field_ptr(DgDb_Location_Structure dls,
  DgDb_Hypernode* dh, u2 index_code, QString field_name, size_t* size, n8* shm_path_code)
{
 if(get_shm_field_ptr_)
   return get_shm_field_ptr_(*this,
     *dh, dls.get_raw_primary_field_id(),
     field_name, size, shm_path_code);

 qDebug() << "field name = " << field_name;
 auto [fio, index] = _class_DgDb_Location_Structure::_split_index_code(index_code);

 DH_Type* dht = dh->dh_type();
 char* block = dh->shm_block();
 auto [offset, end] = dht->get_field_block_offset(field_name);
 u4 sz = end - offset;
 if(!block)
 {
  //  size_t sbs = dht->shm_block_size();
  //  u2 block_column = dht->shm_block_column();
  block = allocate_shm_block(dht, dh->id(), "testOk");
  dh->set_shm_block(block);
  //  void* rec = ddi.get_wdb_record_from_block(block);
  //  QString msg = ddi.get_string_from_wdb_record(rec);
  //  qDebug() << "msg = " << msg;
 }
 return block + offset;
}

void DgDb_Database_Instance::fetch_subvalue(DgDb_Hypernode* dh, DH_Subvalue_Field* sf,
  QByteArray& value, void*& pv)
{
 u2 index = sf->index();
 DgDb_Location_Structure dls;
 dls.set_primary_field_id(index, DgDb_Location_Structure::Field_Id_Options::Structure_Field_Index);
 dls.set_node_id(dh->id());
 dls.set_data_options(DgDb_Location_Structure::Data_Options::Shm_Pointer);

 fetch_node_data(dls, pv);

 DH_Subvalue_Field::Write_Mode wm = sf->write_mode();

 switch (wm)
 {
 case DH_Subvalue_Field::Write_Mode::In_Block:
  {
   u4 len = sf->block_offset_end() - sf->block_offset_start() + 1;
   //char* cs = (char*) pv;
   //
   value = QByteArray( (char*) pv, len);
//  value.resize(2);
//  value[0] = cs[0];
//  value[1] = cs[1];
  }
  break;

 case DH_Subvalue_Field::Write_Mode::Redirect_External:
  {
   QByteArray qba = QByteArray( (char*) pv, 8);
   DWB_Instance* dwb = get_query_dwb(dh->dh_type(), sf);
   void* rec = dwb->get_record_from_qba(qba);
   dwb->get_qba_from_record(rec, sf->query_column(), value);
   //sf->query_column();
  }
  break;

 case DH_Subvalue_Field::Write_Mode::Redirect_In_Record:
  {
   QByteArray qba = QByteArray( (char*) pv, 2);
   u2 spl = qba_to_u2(qba);
   if( (spl & 0b00011111) == 0 )
   {
    // //  means that field is empty ...
   }
   else
   {
    auto [rec, column] = blocks_dwb_->get_record_via_known_split((char*) pv, qba_to_u2(qba));
    blocks_dwb_->get_qba_from_record(rec, column, value);
   }

//   auto [offset, column] = DH::block_offset_record_column_unsplit(qba_to_u2(qba));
//   char* rec_ptr = (char*) pv - offset;
//   void* rec = blocks_dwb_->get_record_from_block(rec_ptr);

//   qba = QByteArray( rec_ptr, sizeof (wg_int));
   //char* cs = (char*) pv;
   //
   //value = QByteArray( (char*) pv, 2);
//  value.resize(2);
//  value[0] = cs[0];
//  value[1] = cs[1];
  }
  break;

 }

}

void DgDb_Database_Instance::fetch_indexed_field(DgDb_Hypernode* dh,
  u2 index, QByteArray& value,
  DgDb_Location_Structure::Data_Options opts)
{
 DgDb_Location_Structure dls;
 dls.set_primary_field_id(index, DgDb_Location_Structure::Field_Id_Options::Raw_Index);
 dls.set_node_id(dh->id());
 dls.set_data_options(opts);
 fetch_node_data(dls, value);
}

void* DgDb_Database_Instance::get_wdb_record_from_block(char* block)
{
 return blocks_dwb_->get_record_from_block(block);
 //wg_int enc;
}

QString DgDb_Database_Instance::get_string_from_wdb_record(void* rec, u2 field_number)
{
 return blocks_dwb_->get_string_from_record(rec, field_number);
}


key_t DgDb_Database_Instance::ftok_key(QString which)
{
 if(which == "blocks")
   return blocks_dwb_->ftok_key();

 return 0;
}


void DgDb_Database_Instance::fetch_indexed_field(DgDb_Hypernode* dh, u2 index,
  DgDb_Location_Structure::Field_Id_Options fio,
  QByteArray& value,
  DgDb_Location_Structure::Data_Options opts)
{
 DgDb_Location_Structure dls;
 dls.set_primary_field_id(index, fio);
 dls.set_node_id(dh->id());
 dls.set_data_options(opts);
 fetch_node_data(dls, value);
}

void DgDb_Database_Instance::fetch_indexed_field(DgDb_Hypernode* dh, u2 index,
  DgDb_Location_Structure::Field_Id_Options fio,
  QByteArray& value, void*& pv,
  DgDb_Location_Structure::Data_Options opts)
{
 DgDb_Location_Structure dls;
 dls.set_primary_field_id(index, fio);
 dls.set_node_id(dh->id());
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
 active_hypernodes_[result->id()] = result;
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

u1 DgDb_Database_Instance::check_construct_dwb_files(QString folder_path)
{
 u1 result = 0;
 QDir qdir(folder_path);
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


u1 DgDb_Database_Instance::check_construct_dwb_files(QDir qdir)
{
 qdir.cd("dwb/blocks");
 return check_construct_dwb_files(qdir.absolutePath());
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

