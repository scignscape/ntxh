
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef WG_STAGE_VALUE__H
#define WG_STAGE_VALUE__H

#include <QVector>
#include <QQueue>

#include <QDateTime>
#include <QDate>

#include <functional>

#include "accessors.h"

#include "global-types.h"

#include "kans.h"

KANS_(DGDB)

static constexpr u1 C_STRING_DECODING_Flag = 64;
static constexpr u1 XSD_TYPE_DECODING_Flag = 128;
static constexpr u1 URI_PREFIX_DECODING_Flag = 128;

class DgDb_Node;

struct WG_Stage_Queue  
{
 QQueue<void*> values;
 std::function<void(QQueue<void*>&)> callback;
 WG_Stage_Queue() : callback(nullptr) {}
 void operator=(std::initializer_list<void*> vs) 
 { 
  values.append(QList<void*>(vs)); 
 }
 void operator<<(std::function<void(QQueue<void*>&)> cb)
   { callback = cb; }
};

template<typename T>
std::function<void(QQueue<void*>&)> stage_queue_memfnptr(void (T::*fn)(QQueue<void*>&))
{
 return [fn](QQueue<void*>& qq)
 {
  (((T*) qq.dequeue())->*fn)(qq);
 };
}

class WG_Stage_Value  
{
 u1 info_;
 u8 data_;

public:

 typedef std::function<void(u4, WG_Stage_Value*)> Callback_type;

private:

 struct _run_result
 {
  u1 info;
  u1 extra;
  u1 collapse_wg_encoding_type() const;
  operator u1() const;  
  _run_result operator [](u1 x)
  {
   return { info, extra | x };
  }
 };

 struct _run_hold
 {
  struct _run
  {
   WG_Stage_Value* _this;
   u4 arg;
   _run_result operator()(WG_Stage_Value::Callback_type cb);
  };
  WG_Stage_Value* _this;
  _run operator[](u4 field_index)
  {
   return {_this, field_index};
  }
  _run_result operator()(WG_Stage_Value::Callback_type cb);
 };

public:

 WG_Stage_Value();

 ACCESSORS(u8 ,data)

 WG_Stage_Value& set_ptr_data(void* ptr);

 u1 get_wg_encoding_type() const;
 u1 get_byte_length() const;
 u1 get_prelim_encoding_code() const;
 u1 get_read_encoding_type() const;

 u1 get_prelim_decoding_code() const;
 u1 get_prelim_decoding_flag() const;

 bool is_uninit() const
 {
  return info_ == 0;
 }

 u1& operator()(void* pv)
 {
  data_ = (u8) pv;
  return info_;
 }

 _run_result _run(Callback_type cb, u4 field_index = 0);

 _run_hold run;

 template<typename T>
 T& data_to_ref()
 {
  return *((T*) data_);
 }

 template<typename T>
 WG_Stage_Value& set_data(const T& data)
 {
  set_ptr_data(new T(data));
  return *this;
 }

 template<typename T>
 WG_Stage_Value& set_raw_data(const T& data)
 {
  data_ = data;
  return *this;
 }

 void cleanup()
 {
  if(check_no_delete())
    return;
  delete (void*) data_;
  data_ = 0;
 }

 WG_Stage_Value& note_unspec();
 WG_Stage_Value& note_enum();
 WG_Stage_Value& note_signed_enum();
 WG_Stage_Value& note_char_enum();
 WG_Stage_Value& note_qstring();
 WG_Stage_Value& note_uint();
 WG_Stage_Value& note_null();
 WG_Stage_Value& note_rec();
 WG_Stage_Value& note_int();
 WG_Stage_Value& note_dbl();
 WG_Stage_Value& note_str(); 
 WG_Stage_Value& note_xml();
 WG_Stage_Value& note_uri();
 WG_Stage_Value& note_blob();
 WG_Stage_Value& note_char();
 WG_Stage_Value& note_fixp();
 WG_Stage_Value& note_date();
 WG_Stage_Value& note_time();
 WG_Stage_Value& note_tbd();

 WG_Stage_Value& note_byte_length(u1 len);

 WG_Stage_Value& note_data_has_type();
 WG_Stage_Value& clear_data_has_type();
 bool check_data_has_type() { return info_ & 8; }

 WG_Stage_Value& note_no_delete();
 WG_Stage_Value& clear_no_delete();

 bool check_no_delete() { return info_ & 16; }

 WG_Stage_Value& new_qstring(const QString& qs);
 WG_Stage_Value& new_qstring_pair(const QString& qs);
 WG_Stage_Value& new_qstring_pair(const QString& qs1, const QString& qs2);

 WG_Stage_Value& new_qstring_xml_pair(const QString& qs1, const QString& qs2);
 WG_Stage_Value& new_qstring_uri_pair(const QString& qs1, const QString& qs2);

 template<typename T>
 WG_Stage_Value& set_uint_data(T t)
 {
  note_uint();
  set_raw_data(t);
  return *this;
 }

 template<typename T>
 WG_Stage_Value& set_u1_data(T t)
 {
  return set_uint_data(t).note_byte_length(1);
 }

 template<typename T>
 WG_Stage_Value& set_u2_data(T t)
 {
  return set_uint_data(t).note_byte_length(2);
 }

 template<typename T>
 WG_Stage_Value& set_u4_data(T t)
 {
  return set_uint_data(t).note_byte_length(4);
 }

 template<typename T>
 WG_Stage_Value& set_u8_data(T t)
 {
  return set_uint_data(t).note_byte_length(8);
 }

 template<typename T>
 WG_Stage_Value& set_int_data(T t)
 {
  note_int();
  set_raw_data(t);
  return *this;
 }

 template<typename T>
 WG_Stage_Value& set_s1_data(T t)
 {
  return set_int_data(t).note_byte_length(1);
 }

 template<typename T>
 WG_Stage_Value& set_s2_data(T t)
 {
  return set_int_data(t).note_byte_length(2);
 }

 template<typename T>
 WG_Stage_Value& set_s4_data(T t)
 {
  return set_int_data(t).note_byte_length(4);
 }

 template<typename T>
 WG_Stage_Value& set_s8_data(T t)
 {
  return set_int_data(t).note_byte_length(8);
 }

 WG_Stage_Value& set_null_data()
 {
  note_null();
  set_raw_data(0);
  return *this;
 }

 template<typename T>
 WG_Stage_Value& set_null_data(T t)
 {
  note_null();
  set_raw_data(t);
  return *this;
 }

 WG_Stage_Value& set_char_data(char chr)
 {
  note_char();
  set_raw_data(chr);
  return *this;
 }

 WG_Stage_Value& set_char_data(QChar chr)
 {
  return set_char_data(chr.toLatin1());
 }

 WG_Stage_Value& set_rec_data(void* rec)
 {
  note_rec();
  set_ptr_data(rec);
  return *this;
 }

 template<typename T>
 WG_Stage_Value& set_double_data(T t)
 {
  T* tt = new T(t);
  note_dbl();
  set_ptr_data(tt);
  return *this;
 }

 template<typename T>
 WG_Stage_Value& set_float_data(T t)
 {
  return set_double_data(t).set_byte_length(4);
 }

 template<typename T>
 WG_Stage_Value& set_fixpoint_data(T t)
 {
  u4 lft = (u4) t;
  u4 rgt = (u4) 10000 * (t - lft);
  
  note_fixp();
  set_raw_data( ((u8) (lft << 32)) | rgt);
  return *this;
 }

 WG_Stage_Value& set_date_data(QDate qdt)
 {
  note_date();
  set_raw_data(qdt.toJulianDay());
  return *this;
 }

 WG_Stage_Value& set_date_data(QDateTime qdt)
 {
  return set_date_data(qdt.date());
 }

 WG_Stage_Value& set_time_data(QTime qtm)
 {
  note_time();
  set_raw_data(qtm.msecsSinceStartOfDay());
  return *this;
 }

 WG_Stage_Value& set_time_data(QDateTime qdt)
 {
  return set_time_data(qdt.time());
 }

 WG_Stage_Value& set_str_data(char* cs, u4 len = 0)
 {
  if(len == 0) len = strlen(cs) + 1;
  char* ncs = (char*) malloc(len);
  strcpy(ncs, cs);
  note_str();
  set_ptr_data(ncs);
  return *this;
 }

 WG_Stage_Value& set_xml_data(QString str, u4 len = 0) //, QString xsd = {})
 {
  const char* cs = str.toLatin1().constData();
  if(len == 0) len = strlen(cs) + 1;
  char* ncs = (char*) malloc(len);
  strcpy(ncs, cs);
  note_xml();
  set_ptr_data(ncs);
  return *this;
 }

 WG_Stage_Value& set_xml_data(QString str, QString xsdt) 
 {
  return new_qstring_xml_pair(str, xsdt);
 }

 WG_Stage_Value& set_uri_data(QString str, u4 len = 0)
 {
  const char* cs = str.toLatin1().constData();
  if(len == 0) len = strlen(cs) + 1;
  char* ncs = (char*) malloc(len);
  strcpy(ncs, cs);
  note_uri();
  set_ptr_data(ncs);
  return *this;
 }

 WG_Stage_Value& set_uri_data(QString str, QString ns) //, QString xsd = {})
 {
  return new_qstring_uri_pair(str, ns);
 }

 WG_Stage_Value& set_blob_data(char* blob, u4 len) //, QString xsd = {})
 {
  note_blob();
  QPair<u4, char*>* pr = new QPair<u4, char*>(len, blob);
  set_ptr_data(pr);
  return *this;
 }

};



_KANS(DGDB)

#endif // WG_STAGE_VALUE__H


