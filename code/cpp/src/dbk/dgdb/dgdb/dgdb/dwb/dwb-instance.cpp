
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dwb-instance.h"

#include "types/dh-subvalue-field.h"

//#include <sys/types.h>
//#include <sys/ipc.h>
#include <sys/shm.h>

#include <QFile>
#include <QDebug>

#include <QtEndian>

extern "C" {
#include "whitedb/_whitedb.h"
}



DWB_Instance::DWB_Instance(QString config_path, QString restore_path)
  :  config_path_(config_path),
     restore_path_(restore_path), wdb_instance_(nullptr)
{

}


void DWB_Instance::write_str_field(void* rec, u2 field_number, QString str)
{
 wg_set_str_field(wdb_instance_, rec, field_number, str.toLatin1().data());
}

void DWB_Instance::write_u4_field(void* rec, u2 field_number, u4 value)
{
 wg_set_int_field(wdb_instance_, rec, field_number, value);
   //_field(wdb_instance_, rec, field_number, str.toLatin1().data());
}

size_t DWB_Instance::write_max_fixed(u1 max_fixed, char* destination)
{
 *destination = max_fixed;
 *(destination + 1) = 1;
 return 2;
}

size_t DWB_Instance::write_record_pointer_bytes(void* rec, char* destination)
{
 wg_int enc = wg_encode_record(wdb_instance_, rec);
 //? enc = qToBigEndian(enc);
 memcpy(destination, &enc, sizeof (wg_int));
 return sizeof (wg_int);
}

void* DWB_Instance::get_record_from_block(char* block)
{
 wg_int enc;
 memcpy(&enc, block, sizeof (wg_int));
 return wg_decode_record(wdb_instance_, enc);
}

u1 DWB_Instance::get_max_used_from_block(char* block)
{
 // //  should we always assume rec is written before?
 return *(block + sizeof (wg_int) + 1);
}

u1 DWB_Instance::inc_max_used_from_block(char* block)
{
 u1 result = get_max_used_from_block(block);
 // //  should we always assume rec is written before?
 *(block + sizeof (wg_int) + 1) = result + 1;
 return result;
}


u1 DWB_Instance::get_max_fixed_from_block(char* block)
{
 // //  should we always assume rec is written before?
 return *(block + sizeof (wg_int));
}

void DWB_Instance::get_qba_from_record(void* rec, u2 field_number, QByteArray& result)
{
 wg_int enc = wg_get_field(wdb_instance_, rec, field_number);
 char* str = wg_decode_str(wdb_instance_, enc);
 wg_int len = wg_decode_str_len(wdb_instance_, enc);
 result = QByteArray(str, len);
}

QString DWB_Instance::get_string_from_record(void* rec, u2 field_number)
{
 wg_int enc = wg_get_field(wdb_instance_, rec, field_number);
 char* str = wg_decode_str(wdb_instance_, enc);
 return QString::fromLatin1(str);
}

QPair<void*, char*> DWB_Instance::new_block_record(u2 field_count,
  size_t size, u2 block_column)
{
 void* rec = wg_create_record(wdb_instance_, field_count);
 char array[size];
 wg_int blob = wg_encode_blob(wdb_instance_, array, nullptr, size);
 wg_set_field(wdb_instance_, rec, block_column, blob);
 char* result = wg_decode_blob(wdb_instance_, blob);
 return {rec, result};
}


QPair<void*, u2> DWB_Instance::get_record_via_known_split(char* ptr, u2 spl)
{
 auto [offset, column] = DH::block_offset_record_column_unsplit(spl);

 char* block_start = (char*) ptr - offset;


 // //  the 6th bit is a flag that the column was set
  //    ahead of time and should not be adjusted ...
 if(column & 0b0010'0000)
    column &= 0b0001'1111;

 return {get_record_from_block(block_start), column};
}


QPair<void*, QPair<u2, u2>> DWB_Instance::get_record_via_split(char* ptr, u2 spl)
{
 auto [offset, column] = DH::block_offset_record_column_unsplit(spl);

 char* block_start = (char*) ptr - offset;

 u2 adj = 0;

 if(column)
 {
  if(column & 0b0010'0000)
    // //  the 6th bit is a flag that the column is set
     //    ahead of time and should not be adjusted ...
    column &= 0b0001'1111;
  else
    column += get_max_fixed_from_block(block_start);
 }
 else
 {
  // //  column = 0 means we have to use first available non-fixed ...
  column = get_max_fixed_from_block(block_start) + inc_max_used_from_block(block_start);
  // //  set the column part of the split ... assume we won't overflow
  adj = spl + column;
 }

 // // returning adj as part of the return value, when it's not
  //   0, signals that the split to be stored is different
  //   than the one passed to this function ...
 return {get_record_from_block(block_start), {column, adj} };
}

//void* DWB_Instance::get_record_via_split(char* ptr, u2 spl)
//{
// auto [offset, column] = DH::block_offset_record_column_unsplit(spl);

// char* block_start = (char*) ptr - offset;

// return get_record_from_block(block_start);
//}

u2 DWB_Instance::write_rec_field_via_split(char* ptr, u2 spl, const QByteArray& text)
{
 auto [rec, column_adj] = get_record_via_split(ptr, spl);
 auto [column, adj] = column_adj;

 wg_set_str_field(wdb_instance_, rec, column, (char*) text.data());
 return adj;
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

