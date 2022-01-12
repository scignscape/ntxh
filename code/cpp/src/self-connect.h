
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef SELF_CONNECT__H
#define SELF_CONNECT__H

#include <QtGlobal>
#include <QString>
#include <QMap>
#include <QValidator>
#include <QPair>

#include <functional>

#include "global-macros.h"


#define USE_SELF_CONNECT_normal \
 template<typename ... ARGS> \
 void self_connect(ARGS ... args) \
 { \
  connect(this, args...); \
 } \


#define USE_SELF_CONNECT_lambda \
template<typename MFN_Type> \
auto _self_connect(MFN_Type mfn) \
{ \
 return _self_connect_package<decltype (this), MFN_Type>{this, mfn}; \
} \


#define USE_SELF_CONNECT_1(x) USE_SELF_CONNECT_##x
#define USE_SELF_CONNECT_2(x, y) USE_SELF_CONNECT_##x USE_SELF_CONNECT_##y

#define USE_SELF_CONNECT(...) \
  _preproc_CONCAT(USE_SELF_CONNECT_, _preproc_NUM_ARGS (__VA_ARGS__))(__VA_ARGS__)


template<typename OBJ_Type, typename MFN_Type>
struct _self_connect_package
{
 OBJ_Type _this;
 MFN_Type mfn;
 template<typename LAMBDA_Type>
 void operator<<(LAMBDA_Type lam)
 {
  _this->self_connect(mfn, lam);
 }
};


#define _self_connect_(x, y) \
  x->_self_connect(&std::remove_reference<decltype(*x)>::type::y)

#define _bind_0_(x, y) \
  std::bind(&std::remove_reference<decltype(*x)>::type::y, x)

#define _std_placeholders_1 std::placeholders::_1
#define _std_placeholders_2 std::placeholders::_1, std::placeholders::_2
#define _std_placeholders_3 std::placeholders::_1, std::placeholders::_2, \
  std::placeholders::_3

#define _std_placeholders_4 std::placeholders::_1, std::placeholders::_2, \
  std::placeholders::_3, std::placeholders::_4
#define _std_placeholders_5 std::placeholders::_1, std::placeholders::_2, \
  std::placeholders::_3, std::placeholders::_4, std::placeholders::_5
#define _std_placeholders_6 std::placeholders::_1, std::placeholders::_2, \
  std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, \
  std::placeholders::_6
#define _std_placeholders_7 std::placeholders::_1, std::placeholders::_2, \
  std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, \
  std::placeholders::_6, std::placeholders::_7
#define _std_placeholders_8 std::placeholders::_1, std::placeholders::_2, \
  std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, \
  std::placeholders::_6, std::placeholders::_7, std::placeholders::_8
#define _std_placeholders_9 std::placeholders::_1, std::placeholders::_2, \
  std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, \
  std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, \
  std::placeholders::_9

#define _bind_1_(x, y) \
  std::bind(&std::remove_reference<decltype(*x)>::type::y, x, std_placeholders_1)

#define _bind_2_(x, y) \
  std::bind(&std::remove_reference<decltype(*x)>::type::y, x, \
  _std_placeholders_2)

#define _bind_3_(x, y) \
  std::bind(&std::remove_reference<decltype(*x)>::type::y, x, \
  _std_placeholders_3)

#define _bind_4_(x, y) \
  std::bind(&std::remove_reference<decltype(*x)>::type::y, x, \
  _std_placeholders_4)

#define _bind_5_(x, y) \
  std::bind(&std::remove_reference<decltype(*x)>::type::y, x, \
  _std_placeholders_5)

#define _bind_6_(x, y) \
  std::bind(&std::remove_reference<decltype(*x)>::type::y, x, \
  _std_placeholders_6)

#define _bind_7_(x, y) \
  std::bind(&std::remove_reference<decltype(*x)>::type::y, x, \
  _std_placeholders_7)

#define _bind_8_(x, y) \
  std::bind(&std::remove_reference<decltype(*x)>::type::y, x, \
  _std_placeholders_8)

#define _bind_9_(x, y) \
  std::bind(&std::remove_reference<decltype(*x)>::type::y, x, \
  _std_placeholders_9)


#define connect_to_this(x, y, z) \
  connect(x, y, this, &std::remove_reference<decltype(*this)>::type::z)



#endif // SELF_CONNECT__H
