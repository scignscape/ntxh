
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef QH_TYPE__H
#define QH_TYPE__H

#include <QMap>
#include <QString>

#include "global-types.h"

#include "accessors.h"

#include "kans.h"

class Qh_Class_Object;
class Qh_Pack_Code;
class Qh_Pack_Builder;

class Qh_Type
{
 QString name_;
 QString cname_;

 u1 byte_length_code_;

 void* meta_object_;

 Qh_Class_Object* qh_class_object_;

 std::function<void(void*, Qh_Pack_Builder&)> static_pack_encoder_;

 template<typename T> struct _Class_Of_Member_Function {};

 template<typename RETURN_Type, typename CLASS_Type>
 struct _Class_Of_Member_Function<RETURN_Type (CLASS_Type::*)>
 {
  using type = CLASS_Type;
 };

 template< typename T>
 using Class_Of_Member_Function = typename _Class_Of_Member_Function<T>::type;


public:

 Qh_Type();

 ACCESSORS(QString ,name)
 ACCESSORS(QString ,cname)

 ACCESSORS(Qh_Class_Object* ,qh_class_object)

 ACCESSORS(MACRO_PASTE(std::function<void(void*, Qh_Pack_Builder&)>) ,static_pack_encoder)

 Qh_Type& defpack(void(*fn)(Qh_Pack_Code&));

 template<typename T>
 static std::function<void(void*, Qh_Pack_Builder&)> default_pack_encoder(void (T::*fn)(Qh_Pack_Builder&))
 {
  return [fn](void* v, Qh_Pack_Builder& qpb)
  {
   (((T*) v)->*fn)(qpb);
  };
 }

 template<typename VALUE_Type, typename PROC_Type>
 Qh_Type& _set_pack_encoder(PROC_Type pt)
 {
  set_static_pack_encoder(default_pack_encoder
    <VALUE_Type>(pt) );
  return *this;
 }

 template<typename PROC_Type>
 Qh_Type& set_pack_encoder(PROC_Type pt)
 {
  return _set_pack_encoder<
    Class_Of_Member_Function<PROC_Type>, PROC_Type>(pt);
 }


};


#endif // QH_TYPE__H


