
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef AL_WRAP__H
#define AL_WRAP__H

#include "accessors.h"

template<typename T> struct wrapper_for;

#define AL_WRAP_DECL(x ,y) \
class x; \
namespace aim_lib{ class y; } \
template<> struct wrapper_for<aim_lib::y> { typedef x _class; }; \


//friend class wrapper_for<x>::_class; \

#define AL_WRAP_CLASS(x) \
class _al { \
  friend wrapper_for<aim_lib::x>::_class; \
  aim_lib::x* object_; \
public: \
  ACCESSORS(aim_lib::x* ,object) \
}; \
_al al; \
typedef aim_lib::x Wrapped_class; \
void alinit(); \
void alinit(aim_lib::x* object) { al.object_ = object; } \


//#define AL_INIT(x) \
void x::alinit() { al.object_ = new Wrapped_class; }

//#define AL_INIT ::alinit() { al.object_ = new Wrapped_class; }

#define AL_INIT(x) \
void wrapper_for<aim_lib::x>::_class::alinit() { al.object_ = new aim_lib::x; } \



#endif
