
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "wdb-manager.h"

#include "wdb-instance.h"

#include "wg-stage-value.h"

#include "dgdb-instance.h"

#include <QDebug>

#include "kans.h"
#include "textio.h"

#include "phaong/phaong.h"
#include "phaong/phaong-types.h"

#include "ntxh-parser/ntxh-document.h"


USING_KANS(TextIO)

extern "C" {
#include "_whitedb/_whitedb.h"
}


USING_KANS(DGDB)


WDB_Manager::WDB_Manager(DgDb_Instance* dgdb_instance)
  :  dgdb_instance_(dgdb_instance), 
     max_num_code_(1000), default_mem_size_(0), current_white_(0)
{


}

WDB_Instance* WDB_Manager::get_current_white()
{
 if(!current_white_)
 {
  current_white_ = new_white();
 }
 return current_white_;
}

void WDB_Manager::update_ntxh()
{
 QString ntxh;
 to_ntxh(ntxh);
 save_file(db_root_folder_ + "/" + "manager.ntxh", ntxh);  
}

void WDB_Manager::to_ntxh(QString& result)
{
 QString dty; 
 QString dr;
 dgdb_instance_->to_ntxh(dty, dr);

 result = QString(R"(

%1

%2

&/

%3
 )").arg(dty).arg(WDB_Instance::static_to_ntxh()).arg(dr);

 for(WDB_Instance* white : whites_.values())
 {
  QString wr;
  white->to_ntxh(wr);
  result += "\n" + wr + "\n";
 }

 result += "/&\n\n";
}


void WDB_Manager::init_from_ntxh()
{
 NTXH_Document doc(db_root_folder_ + "/" + "manager.ntxh");
 doc.parse();

 typedef NTXH_Graph::hypernode_type hypernode_type;

 QVector<hypernode_type*>& hns = doc.top_level_hypernodes();

 QVectorIterator<hypernode_type*> it(hns);

 hypernode_type* hn = it.next();
 doc.graph()->get_sfs(hn, {1,2}, 
   [this](QVector<QPair<QString, void*>>& prs)
 {
  QString fld = prs[0].first;
  u1 code = prs[1].first.toInt();
  dgdb_instance_->init_from_ntxh(fld, code);
 });

 while(it.hasNext())
 {
  hypernode_type* hn = it.next();
  QString name;
  QVector<QDateTime> dts {{},{},{}}; 

  doc.graph()->get_sfsr(hn, {{1,4}}, 
  [&name, &dts, this](QVector<QPair<QString, void*>>& prs)
  {
   name = prs[0].first;
   std::transform(prs.begin() + 1, prs.end(), dts.begin(), 
     [](const QPair<QString, void*>& pr) -> QDateTime
     { 
      if(!pr.first.isEmpty())
        return QDateTime::fromString(pr.first);
     });
  });

  qDebug() << "Database Name: " << name;
  qDebug() << "Database Datetimes: " << dts;
 }
 
}


// // helper function for the method following it ...
wg_int _rec_encode(void* wh, WG_Stage_Value& wsv)
{
 u1 et = wsv.get_wg_encoding_type();
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
   wg_int wi = wg_encode_record(wh, (void*) wsv.data());
   return wi;
  }
  break; 

 case WG_INTTYPE:
  {
   wg_int wi = wg_encode_int(wh, wsv.data());
   return wi;
  }
  break;

 case WG_DOUBLETYPE:
  {
   double* dbl = (double*) wsv.data();
   wg_int wi = wg_encode_double(wh, *dbl);
   wsv.cleanup();
   return wi;
  }
  break;

 case WG_STRTYPE:
  {
   char* cs = (char*) wsv.data();
   wg_int wi = wg_encode_str(wh, cs, nullptr);
   wsv.cleanup();
   return wi;
  }
  break;

 case WG_XMLLITERALTYPE:
  {
   char* lit, *xsdt;
   QByteArray qba1, qba2; // //  prevents the toUtf8 temporaries 
     // from going out of scope too soon ...

   if(wsv.check_data_has_type())
   {
    QPair<u8, QStringList*>* pr = (QPair<u8, QStringList*>*) wsv.data();
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
    lit = (char*) wsv.data();
    xsdt = nullptr;
   }
   wg_int wi = wg_encode_xmlliteral(wh, lit, xsdt);
   wsv.cleanup();   
   return wi;
  }
  break;

 case WG_URITYPE:
  {
   char* uri, *prefix;
   QByteArray qba1, qba2; // //  prevents the toUtf8 temporaries 
     // from going out of scope too soon ...

   if(wsv.check_data_has_type())
   {
    QPair<u8, QStringList*>* pr = (QPair<u8, QStringList*>*) wsv.data();
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
    uri = (char*) wsv.data();
    prefix = nullptr;
   }
   wg_int wi = wg_encode_uri(wh, uri, prefix);
   wsv.cleanup();
   return wi;
  }
  break;

 case WG_BLOBTYPE:
  {
   QPair<u4, char*>* pr = (QPair<u4, char*>*) wsv.data();
   wg_int wi = wg_encode_blob(wh, pr->second, nullptr, pr->first);
   wsv.cleanup();
   return wi;
  }
  break;

 case WG_CHARTYPE:
  {
   wg_int wi = wg_encode_char(wh, wsv.data());
   return wi;
  }
  break;

 case WG_FIXPOINTTYPE:
  {
   u4 rgt = wsv.data() & 0xFFFFFFFF;
   u4 lft = wsv.data() >> 32;
   double dbl = rgt + (lft/10000);
   wg_int wi = wg_encode_double(wh, dbl);
   return wi;
  }
  break;

 case WG_DATETYPE:
  {
   QDate qd = QDate::fromJulianDay(wsv.data());
   int wdate = wg_ymd_to_date(wh, qd.year(), qd.month(), qd.day());
   wg_int wi = wg_encode_date(wh, wdate);
   return wi;   
  }
  break;

 case WG_TIMETYPE:
  {
   // // data is msecsSinceStartOfDay(); 
    //   WhiteDB uses 100ths of a second ...
   wg_int wi = wg_encode_time(wh, wsv.data() / 10);
   return wi;
  }
  break;
 default: 
   break;
 } 
}

void* WDB_Manager::new_wg_record(QMap<u4, WG_Stage_Value>& wsvs,
  WDB_Instance* wdbi)
{
 if(!wdbi)
   wdbi = current_white_;

 void* wh = wdbi->white();

 QMutableMapIterator<u4, WG_Stage_Value> it(wsvs);

 QMap<u4, wg_int> wgim;

 u4 max = 0;

 while(it.hasNext())
 {
  it.next();

  u1 index = it.key();
  if(index > max)
    max = index;

  WG_Stage_Value& wsv = it.value();

  u1 ec = wsv.get_prelim_encoding_code();
  switch(ec)
  {
  case 0:  // same as char ...
   {
    wg_int wi = wg_encode_char(wh, wsv.data());
    wgim[index] = wi;
   }
   break;
  case 1:  // uint; same as int in this context ...
   {
    wg_int wi = wg_encode_int(wh, wsv.data());
    wgim[index] = wi;
   }
   break;
  case 2:  // qstring
   {
    char* qdata, *xdata;
    QByteArray qba1, qba2;  // //  prevents the toUtf8 temporaries 
     // from going out of scope too soon ...

    if(wsv.check_data_has_type())
    {
     QPair<u8, QStringList*>* pr = (QPair<u8, QStringList*>*) wsv.data();
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
     QString* qs = (QString*) wsv.data();
     qdata = qs->toUtf8().data();
     xdata = nullptr;
    }

    wg_int wi = wg_encode_str(wh, qdata, xdata);
    wgim[index] = wi;
    wsv.cleanup();
   }
   break;
  case 3:
   {
    wg_int wi = _rec_encode(wh, wsv);
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

 void* result = wg_create_record(wh, max + 1);
 QMapIterator<u4, wg_int> wit(wgim);

 while(wit.hasNext())
 {
  wit.next();
  wg_set_field(wh, result, wit.key(), wit.value());
 }

 return result;
}


// // helper function for the method following it ...
void _rec_decode(void* wh, void* rec, u4 index, 
  WG_Stage_Value& wsv, u1 ft = 0)
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
   switch(wsv.get_byte_length())
   {
   case 1: wsv.data_to_ref<u1>() = 0; break;
   case 2: wsv.data_to_ref<u2>() = 0; break;
   case 4: wsv.data_to_ref<u4>() = 0; break;
   case 8: wsv.data_to_ref<u8>() = 0; break;
   }
  }
  break; 

 case WG_RECORDTYPE: 
  {
   wg_int wi = wg_get_field(wh, rec, index);
   wsv.set_ptr_data(wg_decode_record(wh, wi));   
  }
  break; 

 case WG_INTTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   switch(wsv.get_byte_length())
   {
   case 1: wsv.data_to_ref<s1>() = wg_decode_int(wh, wi); break;
   case 2: wsv.data_to_ref<s2>() = wg_decode_int(wh, wi); break;
   case 4: wsv.data_to_ref<s4>() = wg_decode_int(wh, wi); break;
   case 8: wsv.data_to_ref<s8>() = wg_decode_int(wh, wi); break;
   }
  }
  break;

 case WG_DOUBLETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   if(wsv.get_byte_length() == 4)
     wsv.data_to_ref<float>() = wg_decode_double(wh, wi);
   else
     wsv.data_to_ref<double>() = wg_decode_double(wh, wi);
  }
  break;

 case WG_STRTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   char* ptr = wg_decode_str(wh, wi);
   wsv.data_to_ref<QString>() = QString(QLatin1String(ptr));
  }
  break;

 case WG_XMLLITERALTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   u1 dcf = wsv.get_prelim_decoding_flag();
   if(dcf & 128)
   {
    char* ptr = wg_decode_xmlliteral(wh, wi);
    char* xptr = wg_decode_xmlliteral_xsdtype(wh, wi);
    wsv.data_to_ref<QStringList>() = QStringList({
      QString::fromUtf8(ptr), QString::fromUtf8(xptr)});
   }
   else
   {
    char* ptr = wg_decode_xmlliteral(wh, wi);
    wsv.data_to_ref<QString>() = QString::fromUtf8(ptr);
   }
  }
  break;

 case WG_URITYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   u1 dcf = wsv.get_prelim_decoding_flag();
   if(dcf & 128)
   {
    char* ptr = wg_decode_uri(wh, wi);
    char* xptr = wg_decode_uri_prefix(wh, wi);
    wsv.data_to_ref<QStringList>() = QStringList({
      QString::fromUtf8(ptr), QString::fromUtf8(xptr)});
   }
   else
   {
    char* ptr = wg_decode_uri(wh, wi);
    wsv.data_to_ref<QString>() = QString::fromUtf8(ptr);
   }
  }
  break;

 case WG_BLOBTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   char* blob = wg_decode_blob(wh, wi);
   wg_int blen = wg_decode_blob_len(wh, wi);
   wsv.data_to_ref<QByteArray>() = QByteArray::fromRawData(blob, blen);
  }
  break;

 case WG_CHARTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   wsv.data_to_ref<char>() = wg_decode_char(wh, wi); 
  }
  break;

 case WG_FIXPOINTTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   if(wsv.get_byte_length() == 4)
     wsv.data_to_ref<float>() = wg_decode_double(wh, wi);
   else
     wsv.data_to_ref<double>() = wg_decode_double(wh, wi);
  }
  break;

 case WG_DATETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   int y, m, d;
   int wdate = wg_decode_date(wh, wi);
   wg_date_to_ymd(wh, wdate, &y, &m, &d);
   wsv.data_to_ref<QDate>() = QDate(y, m, d);
  }
  break;

 case WG_TIMETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   int tm = wg_decode_time(wh, wi);
   wsv.data_to_ref<QTime>() = QTime::fromMSecsSinceStartOfDay(tm * 10);  
  }
  break;

  default: 
   break;
 }
}

void WDB_Manager::decode_value(void* rec, u4 index, 
   WG_Stage_Value& wsv, WDB_Instance* wdbi)
{
 if(!wdbi)
  wdbi = current_white_;
 
 void* wh = wdbi->white();

 u1 dc = wsv.get_prelim_decoding_code();

 switch(dc)
 {
 case 0: // error
  break;
 case 1: // uint 
  {
   wg_int wi = wg_get_field(wh, rec, index);
   switch(wsv.get_byte_length())
   {
   case 1: wsv.data_to_ref<u1>() = wg_decode_int(wh, wi); break;
   case 2: wsv.data_to_ref<u2>() = wg_decode_int(wh, wi); break;
   case 4: wsv.data_to_ref<u4>() = wg_decode_int(wh, wi); break;
   case 8: wsv.data_to_ref<u8>() = wg_decode_int(wh, wi); break;
   }   
  }
  break;
 case 2: // QString 
  {
   wg_int wi = wg_get_field(wh, rec, index);
   const char* cs = wg_decode_str(wh, wi);
   wsv.data_to_ref<QString>() = QString(cs);
  }
  break;
 case 3:
  {
   _rec_decode(wh, rec, index, wsv);
  }
  break;

 case 16: // enum
  {
   wg_int wi = wg_get_field(wh, rec, index);
   wsv.data_to_ref<u1>() = wg_decode_char(wh, wi); 
  }
  break;

 case 17: // signed enum
  {
   wg_int wi = wg_get_field(wh, rec, index);
   wsv.data_to_ref<s1>() = wg_decode_char(wh, wi); 
  }
  break;

 case 18: // signed enum
  {
   wg_int wi = wg_get_field(wh, rec, index);
   wsv.data_to_ref<i1>() = wg_decode_char(wh, wi); 
  }
  break;
 }
}


void WDB_Manager::get_qba_from_record(void* rec, QByteArray& qba, 
  u4 qba_index, WDB_Instance* wdbi)
{
 if(!wdbi)
   wdbi = current_white_;
 
 void* wh = wdbi->white();

 wg_int wi = wg_get_field(wh, rec, qba_index);

 char* blob = wg_decode_blob(wh, wi);
 wg_int wlen = wg_decode_blob_len(wh, wi);
 qba = QByteArray(blob, wlen);
 
}

void WDB_Manager::set_qba_data_field(void* rec, QByteArray& qba,
  u4 qba_index, WDB_Instance* wdbi)
{
 if(!wdbi)
   wdbi = current_white_;
 
 void* wh = wdbi->white();
 wg_int wi = wg_encode_blob(wh, qba.data(), nullptr, qba.size());
 wg_set_field(wh, rec, qba_index, wi); 
}

WDB_Instance* WDB_Manager::new_white(u2 num_code, u8 mem, QString name)
{
 if( (num_code == 0) && !dgdb_instance_->Config.flags.local_scratch_mode )
 {
  max_num_code_ += 100;
  num_code = max_num_code_;
 }
 if(mem == 0)
   mem = default_mem_size_;

 void* db;

 if(dgdb_instance_->Config.flags.local_scratch_mode)
   db = wg_attach_local_database(mem); 
 else if(dgdb_instance_->Config.flags.scratch_mode)
 {
  void* _db = wg_attach_existing_database(
    QString::number(num_code).toLatin1().data());
  if(_db)
  {
   int ok = wg_delete_database(QString::number(num_code).toLatin1().data());
   if(ok > 0)
   {
    qDebug() << "Failed to delete database: " << num_code;
    // // error ... throw something?
   }
  } 
  db = wg_attach_database(QString::number(num_code).toLatin1().data(), mem);    
 }
 else
   db = wg_attach_database(QString::number(num_code).toLatin1().data(), mem);

 WDB_Instance* result = new WDB_Instance(db, name);
 result->set_creation_datetime();

 whites_[num_code] = result;

 if(!name.isEmpty())
 {
  whites_by_name_[name] = result;
 }

 update_ntxh();

 return result; 
}

