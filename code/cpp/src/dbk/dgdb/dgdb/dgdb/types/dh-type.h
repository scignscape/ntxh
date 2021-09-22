
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DH_TYPE__H
#define DH_TYPE__H

#include <functional>

#include <QMap>

#include "global-types.h"

//#include "dw-stage-value.h"
//#include "stage/dw-stage-queue.h"

// #include "_whitedb/_whitedb.h"

#include "accessors.h"

#ifndef RTTI_READ
#define RTTI_READ(tn) \
rtti_read<tn>(#tn)
#endif

#ifndef RTTI_READ_2_1
#define RTTI_READ_2_1(ho_tname ,tn) \
rtti_read<ho_tname<tn>>("(" #ho_tname \
  " " #tn ")")
#endif

#include "kans.h"

 //?KANS_(DgDb)

//class DgDb_Node;

//class DH_Node;
//class DH_Stage_Value;
//struct DH_Stage_Queue;


class DgDb_Hypernode;


class DH_Type
{
 QString name_;
 QString cname_;

 u4 byte_length_;
 u1 byte_length_code_;

 s2 stash_id_;

 void* meta_object_;

 size_t shm_block_size_;

 QMap<QString, QPair<u4, u4>> field_block_offsets_;


 std::function<void*(DgDb_Hypernode*,
   std::function<void*(u4)> )> raw_binary_encoder_;

 std::function<void(void*, QByteArray& qba)> binary_encoder_;
 std::function<void(void*, const QByteArray& qba)> binary_decoder_;

 std::function<void(void*, QByteArray& qba)> opaque_encoder_;
 std::function<void(void*, const QByteArray& qba)> opaque_decoder_;


 template<typename T> struct _Class_Of_Member_Function {};

 template<typename RETURN_Type, typename CLASS_Type>
 struct _Class_Of_Member_Function<RETURN_Type (CLASS_Type::*)>
 {  
  using type = CLASS_Type;    
 };

 template< typename T> 
 using Class_Of_Member_Function = typename _Class_Of_Member_Function<T>::type;


public:


 ACCESSORS__GET(std::function<void(void*, QByteArray&)> ,binary_encoder)
 ACCESSORS__GET(std::function<void(void*, const QByteArray&)> ,binary_decoder)

 ACCESSORS__GET(std::function<void(void*, QByteArray&)> ,opaque_encoder)
 ACCESSORS__GET(std::function<void(void*, const QByteArray&)> ,opaque_decoder)

 ACCESSORS(MACRO_PASTE(std::function<void*(DgDb_Hypernode*,
   std::function<void*(u4)> )>) ,raw_binary_encoder)


 ACCESSORS(u4 ,byte_length)
 ACCESSORS(u1 ,byte_length_code)

 ACCESSORSR(size_t ,shm_block_size)

 ACCESSORS(s2 ,stash_id)

 ACCESSORS(QString ,name)
 ACCESSORS(QString ,cname)

 void _note_field_block_offset(QString field_name, u4 start, u4 end);

 struct note_field_block_offset_intermediary
 {
  QString field_name;
  DH_Type& _this;
  note_field_block_offset_intermediary& operator()(u4 start, u4 end)
  {
   _this._note_field_block_offset(field_name, start, end);
   return *this;
  }
  note_field_block_offset_intermediary& operator()(QString another_field_name)
  {
   field_name = another_field_name;
   return *this;
  }
  DH_Type* operator->()
  {
   return &_this;
  }
 };

 note_field_block_offset_intermediary note_field_block_offset(QString field_name)
 {
  return {field_name, *this};
 }

 template<typename T>
 static std::function<void(void*, QByteArray&)> default_binary_encoder(void (T::*fn)(QByteArray&))
 {
  return [fn](void* v, QByteArray& qba)
  {
   (((T*) v)->*fn)(qba);
  };
 }


 template<typename T>
 static std::function<void(void*, const QByteArray&)> 
   default_binary_decoder(void (T::*fn)(const QByteArray&))
 {
  return [fn](void* v, const QByteArray& qba)
  {
   (((T*) v)->*fn)(qba);
  };
 }


 template<typename PROC_Type>
 DH_Type& set_binary_encoder(PROC_Type pt)
 {
  binary_encoder_ = pt;
  return *this;
 }  

 template<typename VALUE_Type, typename PROC_Type>
 DH_Type& _set_default_binary_encoder(PROC_Type pt)
 {
  return set_binary_encoder(default_binary_encoder
     <VALUE_Type>(pt) );
  return *this;
 }  

 template<typename PROC_Type>
 DH_Type& set_default_binary_encoder(PROC_Type pt)
 {
  return _set_default_binary_encoder<
    Class_Of_Member_Function<PROC_Type>, PROC_Type>(pt);
 }  


 template<typename PROC_Type>
 DH_Type& _set_static_opaque_encoder(PROC_Type pt)
 {
  opaque_encoder_ = pt;
  return *this;
 }

 template<typename PROC_Type>
 DH_Type& set_static_opaque_encoder(PROC_Type pt)
 {
  static s2 stash_id = 0;
  --stash_id;
  opaque_encoder_ = pt;
  stash_id_ = stash_id;
  return *this;
 }

 template<typename VALUE_Type, typename PROC_Type>
 DH_Type& _set_opaque_encoder(PROC_Type pt)
 {
  return set_static_opaque_encoder(default_binary_encoder
     <VALUE_Type>(pt) );
  //return *this;
 }


 template<typename PROC_Type>
 DH_Type& set_opaque_encoder(PROC_Type pt)
 {
  return _set_opaque_encoder<
    Class_Of_Member_Function<PROC_Type>, PROC_Type>(pt);
 }



 template<typename PROC_Type>
 DH_Type& set_binary_decoder(PROC_Type pt)
 {
  binary_decoder_ = pt;
  return *this;
 }  

 template<typename VALUE_Type, typename PROC_Type>
 DH_Type& _set_default_binary_decoder(PROC_Type pt)
 {
  return set_binary_decoder(default_binary_decoder
     <VALUE_Type>(pt) );
  return *this;
 }  

 template<typename PROC_Type>
 DH_Type& set_default_binary_decoder(PROC_Type pt)
 {
  return _set_default_binary_decoder<
    Class_Of_Member_Function<PROC_Type>, PROC_Type>(pt);
 }  


 template<typename PROC_Type>
 DH_Type& set_static_opaque_decoder(PROC_Type pt)
 {
  opaque_decoder_ = pt;
  return *this;
 }

 template<typename VALUE_Type, typename PROC_Type>
 DH_Type& _set_opaque_decoder(PROC_Type pt)
 {
  return set_static_opaque_decoder(default_binary_decoder
     <VALUE_Type>(pt) );
  return *this;
 }

 template<typename PROC_Type>
 DH_Type& set_opaque_decoder(PROC_Type pt)
 {
  return _set_opaque_decoder<
    Class_Of_Member_Function<PROC_Type>, PROC_Type>(pt);
 }


 template<typename CType>
 void rtti_read(QString name)
 {
  name_ = name;
  cname_ = QString::fromStdString(typeid(CType).name());
  byte_length_ = sizeof(CType);
  if( (byte_length_ == 1) || (byte_length_ == 2)
    || (byte_length_ == 4) || (byte_length_ == 8) )
    byte_length_code_ = byte_length_; 
 } 


 DH_Type();

 DH_Type& default_object_layout();
 
 QPair<u4, u4> get_field_block_offset(QString field_name);

};


 //?_KANS(DgDb)

#endif // DH_TYPE__H


