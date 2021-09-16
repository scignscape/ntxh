
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DGDB_RECORD_PROCESSORS__H
#define DGDB_RECORD_PROCESSORS__H

#include <QByteArray>
#include <QVariant>

#include <functional>

#include "global-types.h"

#include "accessors.h"

#include "tkrzw/tkrzw_dbm.h"

#include <string_view>

#include <QString>
#include <QDataStream>


template<typename VALUE_Type>
class _ktype_Get : public tkrzw::DBM::RecordProcessor
{
 VALUE_Type data_;
 VALUE_Type* default_;

public:

 _ktype_Get(VALUE_Type* d = nullptr)
   : tkrzw::DBM::RecordProcessor(),
     data_{}, default_{d}
 {
 }

 void reset() { data_ = {}; }
 void reset_all(VALUE_Type* d = nullptr) { default_ = d; data_ = {}; }


 ~_ktype_Get() = default;

 std::string_view ProcessFull	(std::string_view key, std::string_view value)
   Q_DECL_OVERRIDE
 {
  data_ = *(VALUE_Type*) value.data();
  return DBM::RecordProcessor::NOOP;
 }

 std::string_view ProcessEmpty	(std::string_view key)
   Q_DECL_OVERRIDE
 {
  if(default_)
  {
   data_ = *default_;
   return DBM::RecordProcessor::NOOP;
  }
  return nullptr;
 }

 ACCESSORS__GET(VALUE_Type ,data)
};

template<>
class _ktype_Get<QVariant> : public tkrzw::DBM::RecordProcessor
{
 QVariant data_;
 QVariant* default_;

public:

 _ktype_Get(QVariant* d = nullptr)
   : tkrzw::DBM::RecordProcessor(),
     data_{}, default_{d}
 {
 }

 void reset() { data_ = {}; }
 void reset_all(QVariant* d = nullptr) { default_ = d; data_ = {}; }


 ~_ktype_Get() = default;

 std::string_view ProcessFull	(std::string_view key, std::string_view value)
   Q_DECL_OVERRIDE
 {
  QByteArray qba(value.data(), value.size());
  QDataStream qds(qba);
  qds >> data_;
  return DBM::RecordProcessor::NOOP;
 }

 std::string_view ProcessEmpty	(std::string_view key)
   Q_DECL_OVERRIDE
 {
  if(default_)
  {
   data_ = *default_;
   return DBM::RecordProcessor::NOOP;
  }
  return nullptr;
 }

 ACCESSORS__GET(QVariant ,data)

};

template<typename VALUE_Type, size_t SZ_Value = sizeof (VALUE_Type)>
struct ktype_
{
 typedef _ktype_Get<VALUE_Type> get;

 template<typename DBM_Type>
 class set : public tkrzw::DBM::RecordProcessor
 {
  DBM_Type& dbm_;

 public:

  set(DBM_Type& dbm) : dbm_(dbm) {}

  set& operator()(QString key, VALUE_Type v)
  {
   std::string_view ssv((char*)&v, SZ_Value);
   dbm_.Set(key.toLatin1().constData(), ssv);
  }
 };
};


#endif // DGDB_RECORD_PROCESSORS__H


