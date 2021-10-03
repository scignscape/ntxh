
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dwb-instance.h"

#include "types/dh-subvalue-field.h"
#include "dh-stage-value.h"

#include "conversions.h"

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



wg_int _wg_encode_query_param(void* wh, DH_Stage_Value& sv)
{
 u1 et = 0;
 u1 ec = sv.get_prelim_encoding_code();
 switch(ec)
 {
 case 0:  // same as char ...
  et = WG_CHARTYPE; break;
 case 1:  // uint; same as int in this context ...
  et = WG_INTTYPE; break;
 case 2:  // qstring
  return 0; // what here? et = sv.get_dw_encoding_type();

 default:
  et = sv.get_wg_encoding_type();
 }

 switch(et)
 {
 case WG_NULLTYPE:
  {
   wg_int wi = wg_encode_query_param_null(wh, nullptr);
   return wi;
  }
  break;

 case WG_RECORDTYPE:
  {
   wg_int wi = wg_encode_query_param_record(wh, (void*) sv.data());
   return wi;
  }
  break;

 case WG_INTTYPE:
  {
   wg_int wi = wg_encode_query_param_int(wh, sv.data());
   return wi;
  }
  break;

 case WG_DOUBLETYPE:
  {
   double* dbl = (double*) sv.data();
   wg_int wi = wg_encode_query_param_double(wh, *dbl);
   sv.cleanup<double>();
   return wi;
  }
  break;

 case WG_STRTYPE:
  {
   char* cs = (char*) sv.data();
   wg_int wi = wg_encode_query_param_str(wh, cs, nullptr);
   //?sv.cleanup();
   return wi;
  }
  break;

 case WG_XMLLITERALTYPE:
  {
   // // not implemented
   return 0;
  }
  break;

 case WG_URITYPE:
  {
   // // currently not implemented
   return 0;
  }
  break;

 case WG_BLOBTYPE:
  {
   // // not implemented
   return 0;
  }
  break;

 case WG_CHARTYPE:
  {
   wg_int wi = wg_encode_char(wh, sv.data());
   return wi;
  }
  break;

 case WG_FIXPOINTTYPE:
  {
   u4 rgt = sv.data() & 0xFFFFFFFF;
   u4 lft = sv.data() >> 32;
   double dbl = rgt + (lft/10000);
   wg_int wi = wg_encode_query_param_double(wh, dbl);
   return wi;
  }
  break;

 case WG_DATETYPE:
  {
   QDate qd = QDate::fromJulianDay(sv.data());
   int wdate = wg_ymd_to_date(wh, qd.year(), qd.month(), qd.day());
   wg_int wi = wg_encode_query_param_date(wh, wdate);
   return wi;
  }
  break;

 case WG_TIMETYPE:
  {
   // // data is msecsSinceStartOfDay();
    //   WhiteDB uses 100ths of a second ...
   wg_int wi = wg_encode_query_param_time(wh, sv.data() / 10);
   return wi;
  }
  break;
 default:
   break;
 }

 return 0;
}

void* DWB_Instance::find_query_record(u2 query_column, DH_Stage_Value& sv)
{
 wg_query_arg arglist[1];
 arglist[0].column = query_column;
 arglist[0].cond = WG_COND_EQUAL;
 arglist[0].value = _wg_encode_query_param(wdb_instance_, sv);

 wg_query* wq = wg_make_query(wdb_instance_, nullptr, 0,
   arglist, 1);

 void* result = wg_fetch(wdb_instance_, wq);

 wg_free_query(wdb_instance_, wq);
 wg_free_query_param(wdb_instance_, arglist[0].value);

 return result;
}
// u2 rec_column,


void* DWB_Instance::find_query_record(u2 query_column, QString test)
{
 wg_query_arg arglist[1];
 arglist[0].column = query_column;
 arglist[0].cond = WG_COND_EQUAL;
 arglist[0].value = wg_encode_query_param_str(wdb_instance_, test.toLatin1().data(), nullptr);

 wg_query* wq = wg_make_query(wdb_instance_, nullptr, 0,
   arglist, 1);

 void* result = wg_fetch(wdb_instance_, wq);

 wg_free_query(wdb_instance_, wq);
 wg_free_query_param(wdb_instance_, arglist[0].value);

 return result;
}


void* DWB_Instance::get_target_record_from_query_record(DWB_Instance* origin_dwb, void* qrec, u2 rec_column)
{
 wg_int wi = wg_get_field(wdb_instance_, qrec, rec_column);
 return wg_decode_record(origin_dwb->wdb_instance_, wi);
}

u4 DWB_Instance::fetch_u4_field(void* rec, u2 dh_id_column)
{
 wg_int wi = wg_get_field(wdb_instance_, rec, dh_id_column);
 return wg_decode_int(wdb_instance_, wi);
}

QPair<char*, size_t> DWB_Instance::fetch_blob_field(void* rec, u2 column)
{
 wg_int wi = wg_get_field(wdb_instance_, rec, column);
 return {wg_decode_blob(wdb_instance_, wi), wg_decode_blob_len(wdb_instance_, wi)};
}


void* DWB_Instance::get_record_from_qba(const QByteArray& qba)
{
 wg_int enc = qba_to_n8(qba);
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



// // helper function for the method following it ...
void _rec_decode(void* wh, void* rec, u4 index,
  DH_Stage_Value& sv, u1 ft = 0)
{
 if(ft == 0)
   ft = wg_get_field_type(wh, rec, index);
 switch(ft)
 {
 case 0:
  {
   // // error ... uninit
  }
  break;

 case WG_NULLTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   char* c = wg_decode_null(wh, wi);
   // //  should always be nullptr ...
   switch(sv.get_byte_length())
   {
   case 1: sv.data_to_ref<u1>() = 0; break;
   case 2: sv.data_to_ref<u2>() = 0; break;
   case 4: sv.data_to_ref<u4>() = 0; break;
   case 8: sv.data_to_ref<n8>() = 0; break;
   }
  }
  break;

 case WG_RECORDTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   sv.set_ptr_data(wg_decode_record(wh, wi));
  }
  break;

 case WG_INTTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   if(sv.is_uninit())
   {
    sv.generic_int(wg_decode_int(wh, wi));
    break;
   }
   switch(sv.get_byte_length())
   {
   case 1: sv.data_to_ref<s1>() = wg_decode_int(wh, wi); break;
   case 2: sv.data_to_ref<s2>() = wg_decode_int(wh, wi); break;
   case 4: sv.data_to_ref<s4>() = wg_decode_int(wh, wi); break;
   case 8: sv.data_to_ref<s8>() = wg_decode_int(wh, wi); break;
   }
  }
  break;

 case WG_DOUBLETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   if(sv.get_byte_length() == 4)
     sv.data_to_ref<float>() = wg_decode_double(wh, wi);
   else
     sv.data_to_ref<double>() = wg_decode_double(wh, wi);
  }
  break;

 case WG_STRTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   char* ptr = wg_decode_str(wh, wi);
   wg_int len = wg_decode_str_len(wh, wi);
     //? QLatin1String?
   if(sv.data())
     sv.data_to_ref<QString>() = QString::fromStdString(std::string(ptr, len));
   else
     sv.set_data(QString::fromStdString(std::string(ptr, len)));
  }
  break;

 case WG_XMLLITERALTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   u1 dcf = sv.get_prelim_decoding_flag();
   if(dcf & 128)
   {
    char* ptr = wg_decode_xmlliteral(wh, wi);
    char* xptr = wg_decode_xmlliteral_xsdtype(wh, wi);
    sv.data_to_ref<QStringList>() = QStringList({
      QString::fromUtf8(ptr), QString::fromUtf8(xptr)});
   }
   else
   {
    char* ptr = wg_decode_xmlliteral(wh, wi);
    sv.data_to_ref<QString>() = QString::fromUtf8(ptr);
   }
  }
  break;

 case WG_URITYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   u1 dcf = sv.get_prelim_decoding_flag();
   if(dcf & 128)
   {
    char* ptr = wg_decode_uri(wh, wi);
    char* xptr = wg_decode_uri_prefix(wh, wi);
    sv.data_to_ref<QStringList>() = QStringList({
      QString::fromUtf8(ptr), QString::fromUtf8(xptr)});
   }
   else
   {
    char* ptr = wg_decode_uri(wh, wi);
    sv.data_to_ref<QString>() = QString::fromUtf8(ptr);
   }
  }
  break;

 case WG_BLOBTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   char* blob = wg_decode_blob(wh, wi);
   wg_int blen = wg_decode_blob_len(wh, wi);
   sv.data_to_ref<QByteArray>() = QByteArray::fromRawData(blob, blen);
  }
  break;

 case WG_CHARTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   sv.data_to_ref<char>() = wg_decode_char(wh, wi);
  }
  break;

 case WG_FIXPOINTTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   if(sv.get_byte_length() == 4)
     sv.data_to_ref<float>() = wg_decode_double(wh, wi);
   else
     sv.data_to_ref<double>() = wg_decode_double(wh, wi);
  }
  break;

 case WG_DATETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   int y, m, d;
   int wdate = wg_decode_date(wh, wi);
   wg_date_to_ymd(wh, wdate, &y, &m, &d);
   if(sv.data())
     sv.data_to_ref<QDate>() = QDate(y, m, d);
   else
     sv.set_date_data(QDate(y, m, d));
  }
  break;

 case WG_TIMETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   int tm = wg_decode_time(wh, wi);
   if(sv.data())
     sv.data_to_ref<QTime>() = QTime::fromMSecsSinceStartOfDay(tm * 10);
   else
     sv.set_time_data(QTime::fromMSecsSinceStartOfDay(tm * 10));
  }
  break;

// case qtc_QDateTime:
//  {
//   wg_int wi = wg_get_field(wh, rec, index);
//   int tm = wg_decode_time(wh, wi);
//   if(sv.data())
//     sv.data_to_ref<QTime>() = QTime::fromMSecsSinceStartOfDay(tm * 10);
//   else
//     sv.set_time_data(QTime::fromMSecsSinceStartOfDay(tm * 10));
//  }
//  break;

  default:
   break;
 }
}

void DWB_Instance::get_qba_from_record(void* rec, u2 field_number,
  QByteArray& result, DH_Stage_Code::Query_Typecode qtc, u1 len, bool is_signed)
{
 //u1 dc = sv.get_prelim_decoding_code();

 // //  here we're starting with an empty sv and
  //    reconciling the data provided with the
  //    existing len, sign, qtc info after ...
  //    though it might be better to have
  //    _rec_decode consider that info too ...
 DH_Stage_Value sv;
 _rec_decode(wdb_instance_, rec, field_number, sv);

 switch(qtc)
 {
 case DH_Stage_Code::Query_Typecode::qtc_qstr:
 case DH_Stage_Code::Query_Typecode::qtc_QDateTime:
  sv.to_qba(result, (u1) qtc);
  break;

 case DH_Stage_Code::Query_Typecode::qtc_WG_INTTYPE:
  sv.check_confirm_byte_length(len, is_signed);
  sv.to_qba(result);

 default:
  sv.to_qba(result);
  break;
 }

// wg_int enc = wg_get_field(wdb_instance_, rec, field_number);
// char* str = wg_decode_str(wdb_instance_, enc);
// wg_int len = wg_decode_str_len(wdb_instance_, enc);
// result = QByteArray(str, len);
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

QByteArray DWB_Instance::encode_record(void* rec)
{
 wg_int enc = wg_encode_record(wdb_instance_, rec);
 return n8_to_qba(enc);
}



// // helper function for the method following it ...
wg_int _rec_encode(void* wh, DH_Stage_Value& sv)
{
 u1 et = sv.get_wg_encoding_type();
 switch(et)
 {
 case WG_NULLTYPE:
  {
   wg_int wi = wg_encode_null(wh, nullptr);
   return wi;
  }
  break;

 case WG_RECORDTYPE:
  {
   wg_int wi = wg_encode_record(wh, (void*) sv.data());
   return wi;
  }
  break;

 case WG_INTTYPE:
  {
   wg_int wi = wg_encode_int(wh, sv.data());
   return wi;
  }
  break;

 case WG_DOUBLETYPE:
  {
   double* dbl = (double*) sv.data();
   wg_int wi = wg_encode_double(wh, *dbl);
   sv.cleanup<double>();
   return wi;
  }
  break;

 case WG_STRTYPE:
  {
   char* cs = (char*) sv.data();
   wg_int wi = wg_encode_str(wh, cs, nullptr);
   //?sv.cleanup<double>();
   return wi;
  }
  break;

 case WG_XMLLITERALTYPE:
  {
   char* lit, *xsdt;
   QByteArray qba1, qba2; // //  prevents the toUtf8 temporaries
     // from going out of scope too soon ...

   if(sv.check_data_has_type())
   {
    QPair<n8, QStringList*>* pr = (QPair<n8, QStringList*>*) sv.data();
    if(pr->first)
      break; // //  TODO: special types
    if(pr->second->isEmpty())
      break; // //  something's wrong ...
    qba1 = pr->second->first().toUtf8();
    lit = qba1.data();
    if(pr->second->size() > 1)
    {
     qba2 = pr->second->at(1).toUtf8();
     xsdt = qba2.data();
    }
    else
      xsdt = nullptr;
   }
   else
   {
    lit = (char*) sv.data();
    xsdt = nullptr;
   }
   wg_int wi = wg_encode_xmlliteral(wh, lit, xsdt);
   //?sv.cleanup();
   return wi;
  }
  break;

 case WG_URITYPE:
  {
   char* uri, *prefix;
   QByteArray qba1, qba2; // //  prevents the toUtf8 temporaries
     // from going out of scope too soon ...

   if(sv.check_data_has_type())
   {
    QPair<n8, QStringList*>* pr = (QPair<n8, QStringList*>*) sv.data();
    if(pr->first)
      break; // //  TODO: special types
    if(pr->second->isEmpty())
      break; // //  something's wrong ...
    qba1 = pr->second->first().toLatin1();
    uri = qba1.data();
    if(pr->second->size() > 1)
    {
     qba2 = pr->second->at(1).toUtf8();
     prefix = qba2.data();
    }
    else
      prefix = nullptr;
   }
   else
   {
    uri = (char*) sv.data();
    prefix = nullptr;
   }
   wg_int wi = wg_encode_uri(wh, uri, prefix);
   //?sv.cleanup();
   return wi;
  }
  break;

 case WG_BLOBTYPE:
  {
   QPair<u4, char*>* pr = (QPair<u4, char*>*) sv.data();
   wg_int wi = wg_encode_blob(wh, pr->second, nullptr, pr->first);
   //?sv.cleanup();
   return wi;
  }
  break;

 case WG_CHARTYPE:
  {
   wg_int wi = wg_encode_char(wh, sv.data());
   return wi;
  }
  break;

 case WG_FIXPOINTTYPE:
  {
   u4 rgt = sv.data() & 0xFFFFFFFF;
   u4 lft = sv.data() >> 32;
   double dbl = rgt + (lft/10000);
   wg_int wi = wg_encode_double(wh, dbl);
   return wi;
  }
  break;

 case WG_DATETYPE:
  {
   QDate qd = QDate::fromJulianDay(sv.data());
   int wdate = wg_ymd_to_date(wh, qd.year(), qd.month(), qd.day());
   wg_int wi = wg_encode_date(wh, wdate);
   return wi;
  }
  break;

 case WG_TIMETYPE:
  {
   // // data is msecsSinceStartOfDay();
    //   WhiteDB uses 100ths of a second ...
   wg_int wi = wg_encode_time(wh, sv.data() / 10);
   return wi;
  }
  break;
 default:
   break;
 }
}


void* DWB_Instance::new_query_record(DWB_Instance* origin_dwb,
  void* target_record, u2 target_column,
  u2 value_column, DH_Stage_Value& sv, u2 field_count)
{
 void* result = wg_create_record(wdb_instance_, field_count);

 wg_int origin_rec = wg_encode_record(origin_dwb->wdb_instance_, target_record);

 wg_int wi = _rec_encode(wdb_instance_, sv);

 wg_set_field(wdb_instance_, result, value_column, wi);

// wg_set_field(wdb_instance_, result, value_column,
//   wg_encode_str(wdb_instance_, (char*) value.data(), NULL));

 wg_set_field(wdb_instance_, result, target_column, origin_rec);

 return result;

}



u2 DWB_Instance::write_rec_field_via_split(char* ptr, u2 spl, DH_Stage_Value& sv) //const QByteArray& text)
{
 auto [rec, column_adj] = get_record_via_split(ptr, spl);
 auto [column, adj] = column_adj;

 DH_Stage_Code::Query_Typecode qtc = sv.get_qtc_code();

 if(qtc == DH_Stage_Code::Query_Typecode::qtc_WG_STRTYPE)
 {
  wg_set_str_field(wdb_instance_, rec, column, (char*) sv.data());
 }
 //?wg_set_str_field(wdb_instance_, rec, column, (char*) text.data());
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

