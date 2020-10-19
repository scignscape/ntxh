
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "wdb-instance.h"

extern "C" {
#include "whitedb/_whitedb.h"
}

#include <QDebug>


USING_KANS(DGDB)


WDB_Instance::WDB_Instance(void* w, QString n)
  :  white_(w), name_(n), num_code_(0)
{


}

void WDB_Instance::load_from_file(QString rf)
{
 wg_import_dump(white_, rf.toLatin1().data());
}


QString WDB_Instance::get_local_file_name(QString folder, QString file_name)
{
 if(file_name.isEmpty())
   file_name = QString::number(num_code_);
 return folder + "/" + file_name;
}

void WDB_Instance::save_to_local_file(QString folder, QString file_name)
{
 if(file_name.isEmpty())
   file_name = QString::number(num_code_);
 QString file = folder + "/" + file_name;
 wg_dump(white_, file.toLatin1().data());
}

// // helper function for the method following it ...
wg_int _rec_encode(void* wh, DW_Stage_Value& dwsv)
{
 u1 et = dwsv.get_dw_encoding_type();
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
   wg_int wi = wg_encode_record(wh, (void*) dwsv.data());
   return wi;
  }
  break; 

 case WG_INTTYPE:
  {
   wg_int wi = wg_encode_int(wh, dwsv.data());
   return wi;
  }
  break;

 case WG_DOUBLETYPE:
  {
   double* dbl = (double*) dwsv.data();
   wg_int wi = wg_encode_double(wh, *dbl);
   dwsv.cleanup();
   return wi;
  }
  break;

 case WG_STRTYPE:
  {
   char* cs = (char*) dwsv.data();
   wg_int wi = wg_encode_str(wh, cs, nullptr);
   dwsv.cleanup();
   return wi;
  }
  break;

 case WG_XMLLITERALTYPE:
  {
   char* lit, *xsdt;
   QByteArray qba1, qba2; // //  prevents the toUtf8 temporaries 
     // from going out of scope too soon ...

   if(dwsv.check_data_has_type())
   {
    QPair<n8, QStringList*>* pr = (QPair<n8, QStringList*>*) dwsv.data();
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
    lit = (char*) dwsv.data();
    xsdt = nullptr;
   }
   wg_int wi = wg_encode_xmlliteral(wh, lit, xsdt);
   dwsv.cleanup();   
   return wi;
  }
  break;

 case WG_URITYPE:
  {
   char* uri, *prefix;
   QByteArray qba1, qba2; // //  prevents the toUtf8 temporaries 
     // from going out of scope too soon ...

   if(dwsv.check_data_has_type())
   {
    QPair<n8, QStringList*>* pr = (QPair<n8, QStringList*>*) dwsv.data();
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
    uri = (char*) dwsv.data();
    prefix = nullptr;
   }
   wg_int wi = wg_encode_uri(wh, uri, prefix);
   dwsv.cleanup();
   return wi;
  }
  break;

 case WG_BLOBTYPE:
  {
   QPair<u4, char*>* pr = (QPair<u4, char*>*) dwsv.data();
   wg_int wi = wg_encode_blob(wh, pr->second, nullptr, pr->first);
   dwsv.cleanup();
   return wi;
  }
  break;

 case WG_CHARTYPE:
  {
   wg_int wi = wg_encode_char(wh, dwsv.data());
   return wi;
  }
  break;

 case WG_FIXPOINTTYPE:
  {
   u4 rgt = dwsv.data() & 0xFFFFFFFF;
   u4 lft = dwsv.data() >> 32;
   double dbl = rgt + (lft/10000);
   wg_int wi = wg_encode_double(wh, dbl);
   return wi;
  }
  break;

 case WG_DATETYPE:
  {
   QDate qd = QDate::fromJulianDay(dwsv.data());
   int wdate = wg_ymd_to_date(wh, qd.year(), qd.month(), qd.day());
   wg_int wi = wg_encode_date(wh, wdate);
   return wi;   
  }
  break;

 case WG_TIMETYPE:
  {
   // // data is msecsSinceStartOfDay(); 
    //   WhiteDB uses 100ths of a second ...
   wg_int wi = wg_encode_time(wh, dwsv.data() / 10);
   return wi;
  }
  break;
 default: 
   break;
 } 
}

void* WDB_Instance::new_wg_record(QMap<u4, DW_Stage_Value>& svs)
{
 return new_wg_record(0, {}, svs);
}

void WDB_Instance::set_wg_record_field_rec(DW_Record dr, u4 col, void* rec)
{
 wg_int recenc = wg_encode_record(white_, rec);
 wg_set_field(white_, dr.wg_record(), col, recenc);
}


void* WDB_Instance::query_leading_rec(u4 col)
{
 static void* dummy = wg_create_record(white_, 0);

 return wg_find_record_record(white_, col, WG_COND_NOT_EQUAL, dummy, NULL);

/*
 wg_query_arg arglist[1];
 arglist[0].column = col;
 arglist[0].cond = WG_COND_NOT_EQUAL;
 arglist[0].value = wg_encode_query_param_record(white_, dummy);
 
 wg_query* wq = wg_make_query(white_, nullptr, 0, 
   arglist, 1);

 void* result = wg_fetch(white_, wq); 

 wg_free_query(white_, wq);
 wg_free_query_param(white_, arglist[0].value);

 return result;
*/
}

void* WDB_Instance::query_leading_str(u4 col)
{
 return wg_find_record_str(white_, col, WG_COND_NOT_EQUAL, "", NULL);

/*
 wg_query_arg arglist[1];
 arglist[0].column = col;
 arglist[0].cond = WG_COND_NOT_EQUAL;
 arglist[0].value = wg_encode_query_param_str(white_, "te", nullptr); 

 wg_query* wq = wg_make_query(white_, nullptr, 0, 
   arglist, 1);

 void* result = wg_fetch(white_, wq); 

 wg_free_query(white_, wq);
 wg_free_query_param(white_, arglist[0].value);

 return result;
*/
}

void* WDB_Instance::query_leading_int(u4 col)
{
 return wg_find_record_int(white_, col, WG_COND_NOT_EQUAL, 0, NULL);

/*
 wg_query_arg arglist[1];
 arglist[0].column = col;
 arglist[0].cond = WG_COND_NOT_EQUAL;
 arglist[0].value = wg_encode_query_param_int(white_, 0); 

 wg_query* wq = wg_make_query(white_, nullptr, 0, 
   arglist, 1);

 void* result = wg_fetch(white_, wq); 

 wg_free_query(white_, wq);
 wg_free_query_param(white_, arglist[0].value);

 return result;
*/
}

wg_int _wg_encode_query_param(void* wh, DW_Stage_Value& dwsv)
{
 u1 et = 0;
 u1 ec = dwsv.get_prelim_encoding_code();
 switch(ec)
 {
 case 0:  // same as char ...
  et = WG_CHARTYPE; break;
 case 1:  // uint; same as int in this context ...
  et = WG_INTTYPE; break;
 case 2:  // qstring
  return 0; // what here? et = dwsv.get_dw_encoding_type();

 default:
  et = dwsv.get_dw_encoding_type();
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
   wg_int wi = wg_encode_query_param_record(wh, (void*) dwsv.data());
   return wi;
  }
  break; 

 case WG_INTTYPE:
  {
   wg_int wi = wg_encode_query_param_int(wh, dwsv.data());
   return wi;
  }
  break;

 case WG_DOUBLETYPE:
  {
   double* dbl = (double*) dwsv.data();
   wg_int wi = wg_encode_query_param_double(wh, *dbl);
   dwsv.cleanup();
   return wi;
  }
  break;

 case WG_STRTYPE:
  {
   char* cs = (char*) dwsv.data();
   wg_int wi = wg_encode_query_param_str(wh, cs, nullptr);
   dwsv.cleanup();
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
   wg_int wi = wg_encode_char(wh, dwsv.data());
   return wi;
  }
  break;

 case WG_FIXPOINTTYPE:
  {
   u4 rgt = dwsv.data() & 0xFFFFFFFF;
   u4 lft = dwsv.data() >> 32;
   double dbl = rgt + (lft/10000);
   wg_int wi = wg_encode_query_param_double(wh, dbl);
   return wi;
  }
  break;

 case WG_DATETYPE:
  {
   QDate qd = QDate::fromJulianDay(dwsv.data());
   int wdate = wg_ymd_to_date(wh, qd.year(), qd.month(), qd.day());
   wg_int wi = wg_encode_query_param_date(wh, wdate);
   return wi;   
  }
  break;

 case WG_TIMETYPE:
  {
   // // data is msecsSinceStartOfDay(); 
    //   WhiteDB uses 100ths of a second ...
   wg_int wi = wg_encode_query_param_time(wh, dwsv.data() / 10);
   return wi;
  }
  break;
 default: 
   break;
 } 

 return 0;
}

void* WDB_Instance::query_within_id_range(u4 range_col, u4 low, u4 high, 
  u4 param_column, DW_Stage_Value& dwsv)
{
 wg_query_arg arglist[3];

 arglist[0].column = range_col;
 arglist[0].cond = WG_COND_LESSTHAN;
 arglist[0].value = wg_encode_query_param_int(white_, high);

 arglist[1].column = range_col;
 arglist[1].cond = WG_COND_GREATER;
 arglist[1].value = wg_encode_query_param_int(white_, low);

 arglist[2].column = param_column;
 arglist[2].cond = WG_COND_EQUAL;
 arglist[2].value = _wg_encode_query_param(white_, dwsv);

 wg_query* query = wg_make_query(white_, nullptr, 0, arglist, 3);

 void* result = wg_fetch(white_, query);

 wg_free_query(white_, query);
 wg_free_query_param(white_, arglist[0].value);
 wg_free_query_param(white_, arglist[1].value);
 wg_free_query_param(white_, arglist[2].value);

 return result;
}

n8 WDB_Instance::set_record_field(void* rec, u4 col, DW_Stage_Value& dwsv)
{
 wg_int result = NULL;
 u1 ec = dwsv.get_prelim_encoding_code();
 switch(ec)
 {
 case 0:  // same as char ...
  {
   wg_int wi = wg_encode_char(white_, dwsv.data());
   result = wg_set_field(white_, rec, col, wi);
  }
  break;
 case 1:  // uint; same as int in this context ...
  {
   wg_int wi = wg_encode_char(white_, dwsv.data());
   result = wg_set_field(white_, rec, col, wi);
  }
  break;
 case 2:  // qstring
  {
   char* qdata, *xdata;
   QByteArray qba1, qba2;  // //  prevents the toUtf8 temporaries 
     // from going out of scope too soon ...

   if(dwsv.check_data_has_type())
   {
    QPair<n8, QStringList*>* pr = (QPair<n8, QStringList*>*) dwsv.data();
    if(pr->first)
      break; // //  TODO: special types
    if(pr->second->isEmpty())
      break; // //  something's wrong ...
    qba1 = pr->second->first().toUtf8();
    qdata = qba1.data();
    if(pr->second->size() > 1)
    {
     qba2 = pr->second->at(1).toUtf8();       
     xdata = qba2.data();
    }
    else
      xdata = nullptr;
   }
   else
   {
    QString* qs = (QString*) dwsv.data();
    qdata = qs->toUtf8().data();
    xdata = nullptr;
   }

   wg_int wi = wg_encode_str(white_, qdata, xdata);
   result = wg_set_field(white_, rec, col, wi);
   dwsv.cleanup();
  }
  break;
 case 3:
  {
   wg_int wi = _rec_encode(white_, dwsv);
   result = wg_set_field(white_, rec, col, wi);
  }
  break;
 case 15:
   // // unimplemented ...
  break;
 default:
    // // error ...  
  break;
 }
 return (n8) result;
}

void* WDB_Instance::new_wg_record(u4 id, QString col1, 
  QMap<u4, DW_Stage_Value>& svs)
{
 QMutableMapIterator<u4, DW_Stage_Value> it(svs);

 QMap<u4, wg_int> wgim;

 if(id)
 {
  wgim[0] = wg_encode_int(white_, id);
 }

 if(!col1.isEmpty())
 {
  wgim[1] = wg_encode_str(white_, col1.toLatin1().data(), nullptr);
 }

 u4 max = 0;

 while(it.hasNext())
 {
  it.next();

  u1 index = it.key();
  if(index > max)
    max = index;

  DW_Stage_Value& dwsv = it.value();

  u1 ec = dwsv.get_prelim_encoding_code();
  switch(ec)
  {
  case 0:  // same as char ...
   {
    wg_int wi = wg_encode_char(white_, dwsv.data());
    wgim[index] = wi;
   }
   break;
  case 1:  // uint; same as int in this context ...
   {
    wg_int wi = wg_encode_int(white_, dwsv.data());
    wgim[index] = wi;
   }
   break;
  case 2:  // qstring
   {
    char* qdata, *xdata;
    QByteArray qba1, qba2;  // //  prevents the toUtf8 temporaries 
     // from going out of scope too soon ...

    if(dwsv.check_data_has_type())
    {
     QPair<n8, QStringList*>* pr = (QPair<n8, QStringList*>*) dwsv.data();
     if(pr->first)
       break; // //  TODO: special types
     if(pr->second->isEmpty())
       break; // //  something's wrong ...
     qba1 = pr->second->first().toUtf8();
     qdata = qba1.data();
     if(pr->second->size() > 1)
     {
      qba2 = pr->second->at(1).toUtf8();       
      xdata = qba2.data();
     }
     else
       xdata = nullptr;
    }
    else
    {
     QString* qs = (QString*) dwsv.data();
     qdata = qs->toUtf8().data();
     xdata = nullptr;
    }

    wg_int wi = wg_encode_str(white_, qdata, xdata);
    wgim[index] = wi;
    dwsv.cleanup();
   }
   break;
  case 3:
   {
    wg_int wi = _rec_encode(white_, dwsv);
    wgim[index] = wi;
   }
   break;
  case 15:
    // // unimplemented ...
   break;
  default:
    // // error ...  
   break;
  }
 }

 void* result = wg_create_record(white_, max + 1);
 QMapIterator<u4, wg_int> wit(wgim);

 while(wit.hasNext())
 {
  wit.next();
  wg_set_field(white_, result, wit.key(), wit.value());
 }

 return result;
}


// // helper function for the method following it ...
void _rec_decode(void* wh, void* rec, u4 index, 
  DW_Stage_Value& dwsv, u1 ft = 0)
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
   switch(dwsv.get_byte_length())
   {
   case 1: dwsv.data_to_ref<u1>() = 0; break;
   case 2: dwsv.data_to_ref<u2>() = 0; break;
   case 4: dwsv.data_to_ref<u4>() = 0; break;
   case 8: dwsv.data_to_ref<n8>() = 0; break;
   }
  }
  break; 

 case WG_RECORDTYPE: 
  {
   wg_int wi = wg_get_field(wh, rec, index);
   dwsv.set_ptr_data(wg_decode_record(wh, wi));   
  }
  break; 

 case WG_INTTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   switch(dwsv.get_byte_length())
   {
   case 1: dwsv.data_to_ref<s1>() = wg_decode_int(wh, wi); break;
   case 2: dwsv.data_to_ref<s2>() = wg_decode_int(wh, wi); break;
   case 4: dwsv.data_to_ref<s4>() = wg_decode_int(wh, wi); break;
   case 8: dwsv.data_to_ref<s8>() = wg_decode_int(wh, wi); break;
   }
  }
  break;

 case WG_DOUBLETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   if(dwsv.get_byte_length() == 4)
     dwsv.data_to_ref<float>() = wg_decode_double(wh, wi);
   else
     dwsv.data_to_ref<double>() = wg_decode_double(wh, wi);
  }
  break;

 case WG_STRTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   char* ptr = wg_decode_str(wh, wi);
   dwsv.data_to_ref<QString>() = QString(QLatin1String(ptr));
  }
  break;

 case WG_XMLLITERALTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   u1 dcf = dwsv.get_prelim_decoding_flag();
   if(dcf & 128)
   {
    char* ptr = wg_decode_xmlliteral(wh, wi);
    char* xptr = wg_decode_xmlliteral_xsdtype(wh, wi);
    dwsv.data_to_ref<QStringList>() = QStringList({
      QString::fromUtf8(ptr), QString::fromUtf8(xptr)});
   }
   else
   {
    char* ptr = wg_decode_xmlliteral(wh, wi);
    dwsv.data_to_ref<QString>() = QString::fromUtf8(ptr);
   }
  }
  break;

 case WG_URITYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   u1 dcf = dwsv.get_prelim_decoding_flag();
   if(dcf & 128)
   {
    char* ptr = wg_decode_uri(wh, wi);
    char* xptr = wg_decode_uri_prefix(wh, wi);
    dwsv.data_to_ref<QStringList>() = QStringList({
      QString::fromUtf8(ptr), QString::fromUtf8(xptr)});
   }
   else
   {
    char* ptr = wg_decode_uri(wh, wi);
    dwsv.data_to_ref<QString>() = QString::fromUtf8(ptr);
   }
  }
  break;

 case WG_BLOBTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   char* blob = wg_decode_blob(wh, wi);
   wg_int blen = wg_decode_blob_len(wh, wi);
   dwsv.data_to_ref<QByteArray>() = QByteArray::fromRawData(blob, blen);
  }
  break;

 case WG_CHARTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   dwsv.data_to_ref<char>() = wg_decode_char(wh, wi); 
  }
  break;

 case WG_FIXPOINTTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   if(dwsv.get_byte_length() == 4)
     dwsv.data_to_ref<float>() = wg_decode_double(wh, wi);
   else
     dwsv.data_to_ref<double>() = wg_decode_double(wh, wi);
  }
  break;

 case WG_DATETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   int y, m, d;
   int wdate = wg_decode_date(wh, wi);
   wg_date_to_ymd(wh, wdate, &y, &m, &d);
   dwsv.data_to_ref<QDate>() = QDate(y, m, d);
  }
  break;

 case WG_TIMETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   int tm = wg_decode_time(wh, wi);
   dwsv.data_to_ref<QTime>() = QTime::fromMSecsSinceStartOfDay(tm * 10);  
  }
  break;

  default: 
   break;
 }
}

void WDB_Instance::decode_wg_record_value(void* rec, u4 index, 
   DW_Stage_Value& dwsv)
{
 u1 dc = dwsv.get_prelim_decoding_code();

 switch(dc)
 {
 case 0: // error
  break;
 case 1: // uint 
  {
   wg_int wi = wg_get_field(white_, rec, index);
   switch(dwsv.get_byte_length())
   {
   case 1: dwsv.data_to_ref<u1>() = wg_decode_int(white_, wi); break;
   case 2: dwsv.data_to_ref<u2>() = wg_decode_int(white_, wi); break;
   case 4: dwsv.data_to_ref<u4>() = wg_decode_int(white_, wi); break;
   case 8: dwsv.data_to_ref<n8>() = wg_decode_int(white_, wi); break;
   }   
  }
  break;
 case 2: // QString 
  {
   wg_int wi = wg_get_field(white_, rec, index);
   const char* cs = wg_decode_str(white_, wi);
   dwsv.data_to_ref<QString>() = QString(cs);
  }
  break;
 case 3:
  {
   _rec_decode(white_, rec, index, dwsv);
  }
  break;

 case 16: // enum
  {
   wg_int wi = wg_get_field(white_, rec, index);
   dwsv.data_to_ref<u1>() = wg_decode_char(white_, wi); 
  }
  break;

 case 17: // signed enum
  {
   wg_int wi = wg_get_field(white_, rec, index);
   dwsv.data_to_ref<s1>() = wg_decode_char(white_, wi); 
  }
  break;

 case 18: // signed enum
  {
   wg_int wi = wg_get_field(white_, rec, index);
   dwsv.data_to_ref<i1>() = wg_decode_char(white_, wi); 
  }
  break;
 }
}


void WDB_Instance::get_qba_from_record(void* rec, u4 field_number, QByteArray& qba)
{
 wg_int data = wg_get_field(white_, rec, field_number);
 wg_int len = wg_decode_blob_len(white_, data);
 qba.resize(len);
 wg_int ok = wg_decode_blob_copy(white_, data, qba.data(), len);

// char* blob = wg_decode_blob(white_, wi);
// wg_int wlen = wg_decode_blob_len(white_, wi);
// qba = QByteArray(blob, wlen);
}

void WDB_Instance::set_qba_record_field(void* rec, u4 field_number, QByteArray& qba)
{
 wg_int wi = wg_encode_blob(white_, qba.data(), nullptr, qba.size());
 wg_set_field(white_, rec, field_number, wi); 
}

void WDB_Instance::set_qba_record_field(void* rec, u4 field_number, const QByteArray& qba)
{
 wg_int enc = wg_encode_blob(white_, const_cast<char*>(qba.data()), NULL, qba.length());
 wg_set_field(white_, rec, field_number, enc);
}


void* WDB_Instance::new_wg_record(u4 number_of_columns)
{
 void* result = wg_create_record(white_, number_of_columns);
 return result;
}

void* WDB_Instance::get_record_by_id(u4 id)
{
 return wg_find_record_int(white_, 0, WG_COND_EQUAL, id, NULL);
}


u4 WDB_Instance::get_record_id(void* rec)
{
 wg_int data = wg_get_field(white_, rec, 0);
 return wg_decode_int(white_, data);
}

void* WDB_Instance::get_record_ref_target(void* rec, u4* and_ref_id)
{
 wg_int data = wg_get_field(white_, rec, 1);
 void* result = wg_decode_record(white_, data);
 if(result) 
 {
  if(and_ref_id)
  {
   wg_int data1 = wg_get_field(white_, rec, 2);
   *and_ref_id = wg_decode_int(white_, data1);
  }
 }
 return result;
}


void* WDB_Instance::new_wg_record(u4 number_of_columns, u4 col1)
{
 void* result = wg_create_record(white_, number_of_columns);
 wg_int c1val = wg_encode_int(white_, col1);
 wg_set_field(white_, result, 0, c1val);

 return result;
}

DW_Record WDB_Instance::check_reset_ref_field(DW_Record& ref, u4 col, u4 new_size) //, u4 (*fn)() )
{
 void* old_ref = nullptr; 
 wg_int ftype = wg_get_field_type(white_, ref.wg_record(), col);

 if(ftype == WG_RECORDTYPE)
 {
  wg_int wgi = wg_get_field(white_, ref.wg_record(), col);
  old_ref = wg_decode_record(white_, wgi);
 }

 void* result = wg_create_record(white_, new_size + 3);
 wg_int recenc = wg_encode_record(white_, result);
 wg_set_field(white_, ref.wg_record(), col, recenc);
 if(old_ref)
 {
  u4 old_id = get_record_id(old_ref);
  wg_set_int_field(white_, result, 0, old_id); 
  wg_delete_record(white_, old_ref);
  return {old_id, result};
 }
 else
 {
  //u4 new_id = fn();
  //wg_set_int_field(white_, result, 0, old_id);
  return {0, result};
 }
}

void WDB_Instance::set_record_id_field(void* rec, u4 id)
{
 wg_set_int_field(white_, rec, 0, id);
}

void WDB_Instance::populate_edges_record(DW_Record& new_rec, DW_Record& ref, 
  QVector<QPair<QPair<QString, DW_Record>, DW_Record>>& targets)
{
 void* vn = new_rec.wg_record();

 wg_int refenc = wg_encode_record(white_, ref.wg_record());
 wg_set_field(white_, vn, 1, refenc);

 wg_set_int_field(white_, vn, 2, ref.id());
 
 u4 rcol = 3;
 for(QPair<QPair<QString, DW_Record>, DW_Record>& pr : targets)
 {
  wg_set_str_field(white_, vn, rcol, pr.first.first.toLatin1().data());
  ++rcol;

   // //  the edge-annotation column should be null before maybe setting it ...
    //    but this code does not check that because it assumes the provided 
    //    record is newly constructed ...  
    //    If that assumptions proves unwarranted due to some change in the 
    //    interface it's ok to explicitly null out the column if 
    //    pr.first.second.wg_record() is null ... 
  if(pr.first.second.wg_record())
  {
   wg_int target_enc = wg_encode_record(white_, pr.first.second.wg_record());
   wg_set_field(white_, vn, rcol, target_enc);
  }
  ++rcol; 
  wg_int target_enc1 = wg_encode_record(white_, pr.second.wg_record());
  wg_set_field(white_, vn, rcol, target_enc1);

 }
}


void* WDB_Instance::new_wg_record(u4 number_of_columns, u4 col1, QString col2)
{
 void* result = wg_create_record(white_, number_of_columns);
 wg_int c1val = wg_encode_int(white_, col1);
 wg_int c2val = wg_encode_str(white_, col2.toLatin1().data(), nullptr);

 wg_set_field(white_, result, 0, c1val);
 wg_set_field(white_, result, 1, c2val);
 return result;
}



QString WDB_Instance::static_to_ntxh()
{
 return R"(&type WDB_Instance {4}
  :name:1 :created:2 :attached:3 :llff:4 ;
 )";
}

void WDB_Instance::to_ntxh(QString& result)
{
 QString cr = datetimes_.value(Created).toString();
 QString ra = datetimes_.value(Recent_Attach).toString();
 QString llff = datetimes_.value(Last_Load_From_File).toString();

 result = QString(R"(!/ WDB_Instance
$name: %1
$created: %2
$attached: %3
$llff: %4
/!

<+>
)").arg(name_).arg(cr).arg(ra).arg(llff);

}


void WDB_Instance::set_creation_datetime()
{
 datetimes_.insert(Created, QDateTime::currentDateTime());
}

void WDB_Instance::set_creation_datetime(QDateTime dtm)
{
 datetimes_.insert(Created, dtm);
}


