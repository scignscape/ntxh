
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef _VEC1D__H
#define _VEC1D__H


#include "accessors.h"

#include "hive-structure.h"

#include <QVector>
#include <QString>
#include <QMap>

#include <QDebug>

#include <functional>

#include "_each-holders.h"

#include "global-macros.h"


#define deffn_2(ty, arg) [](ty** def) \
{ \
 static ty _def = arg; \
 *def = &_def; \
} \

#define defzfn(ty) deffn_2(ty, 0)

#define deffn_1(ty) defzfn(ty)

#define deffn(...) \
  _preproc_CONCAT(deffn_, _preproc_NUM_ARGS (__VA_ARGS__))(__VA_ARGS__)





#ifndef QString_number
#define QString_number(ty) \
  [](ty _t_y_){ return QString::number(_t_y_);}
#endif

//#define _default_fn(ty ,arg) set_default_fn(deffn(ty, arg))
//#define _default_z(ty) _default_fn(ty ,0)

#include "xcns.h"

XCNS_(XCSD)

template<class OBJ_Type>
typename
std::enable_if<std::is_default_constructible<OBJ_Type>::value
&& !std::is_arithmetic<OBJ_Type>::value, void>::type
_check_construct(OBJ_Type** obj)
{
 if(!*obj)
 {
  *obj = new OBJ_Type();    // default-construct Obj
 }
}

template<class OBJ_Type>
typename
std::enable_if<std::is_default_constructible<OBJ_Type>::value
&& std::is_arithmetic<OBJ_Type>::value, void>::type
_check_construct(OBJ_Type** obj)
{
 if(!*obj)
 {
  *obj = new OBJ_Type();    // default-construct Obj
  **obj = 0;
 }
}

template<class OBJ_Type>
typename std::enable_if<!std::is_default_constructible<OBJ_Type>::value>::type
_check_construct(OBJ_Type**)
{
}




struct _pr_break
{
 u2 index;
 s1 level;

 typedef s1 level_type;
};

template<typename VAL_Type, typename INDEX_Types, typename PR_Type = _pr_break>
class Deq1d;


template<typename VAL_Type, typename INDEX_Types = index_types<s2>, typename NESTED_INDEX_Type = u2,
         typename PR_Type = _pr_break>
class _Vec1d
{
 using nnx = typename INDEX_Types::Numeric_Nested_Index_type;
 using nx = typename INDEX_Types::Numeric_Index_type;

 std::function<void(VAL_Type**)> default_fn_;

protected:

 friend class Deq1d<VAL_Type, INDEX_Types>;
 Hive_Structure<INDEX_Types>* hive_structure_;

public:

 using Numeric_Nested_Index_type = typename INDEX_Types::Numeric_Nested_Index_type;
 using Numeric_Index_type = typename INDEX_Types::Numeric_Index_type;
 using Element_type = VAL_Type;

 _Vec1d(nnx layer_size = 16, nnx block_size = 16)
  :  hive_structure_(new Hive_Structure<INDEX_Types>(layer_size, block_size)),
    default_fn_(nullptr)
 {
  //hive_structure_->set_layer_size(la);
  hive_structure_->set_value_size(sizeof(VAL_Type));
 }

 typedef typename Hive_Structure<INDEX_Types>::pre_iterator pre_iterator;
 typedef typename Hive_Structure<INDEX_Types>::iterator iterator;

 pre_iterator parse_location(nx nix)
 {
  return hive_structure_->parse_location(nix);
 }

 VAL_Type* contiguous(nx nix1, nx nix2)
 {
  return (VAL_Type*) hive_structure_->contiguous(nix1, nix2);
 }

 void rebound(nx nix, const VAL_Type& v)
 {
  if(void* pv = hive_structure_->rebound(nix))
    *(VAL_Type*)pv = v;
 }

 void rebound_first(const VAL_Type& v)
 {
  rebound(0, v);
 }

 static VAL_Type* static_default_value(VAL_Type* v = nullptr)
 {
  static VAL_Type* result = nullptr;
  if(v)
    result = v;

  return result;
 }

 void static_default_value(const VAL_Type& v)
 {
  static VAL_Type sv = v;
  static_default_value(&sv);
 }

 void use_default_value(const VAL_Type& v)
 {
  static VAL_Type pv = v;
  set_default_fn([](VAL_Type** ppv)
  {
   *ppv = &pv;
  });
 }

 VAL_Type* contiguous(nx nix1, nx nix2, QVector<QPair<VAL_Type*, nx>>& breakdown)
 {
  return (VAL_Type*) hive_structure_->contiguous(nix1, nix2,
    (QVector<QPair<void*, nx>>*) &breakdown);
 }

 static VAL_Type** check_init_default_value()
 {
  static VAL_Type** result = nullptr;
  if(!result)
  {
   VAL_Type* v;
   default_construct_if_needed_and_possible(result);
  }
  if(!result)
  {
   *result = (VAL_Type*)calloc(1, sizeof (VAL_Type));
  }
  return result;
 }

 static void default_construct_if_needed_and_possible(VAL_Type** result)
 {
  _check_construct<VAL_Type>(result);
 }

 VAL_Type* fetch_at(nx nix, nx fallback)
 {
  //VAL_Type** default_value = check_init_default_value();

 // return (VAL_Type*) hive_structure_->fetch_at(nix, fallback);
  return (VAL_Type*) hive_structure_->fetch(nix, fallback);

  u1* cv;
  static VAL_Type* default_value = nullptr;
  default_construct_if_needed_and_possible(&default_value);
  if(default_value)
    cv = (u1*) default_value;
  else
    cv = (u1*) calloc(1, sizeof (VAL_Type));

//?  return (VAL_Type*) hive_structure_->fetch_at(nix, fallback, cv); //(u1*) default_value);
 }

 VAL_Type* fetch_at(nx nix, nx fallback, VAL_Type v)
 {
  return (VAL_Type*) hive_structure_->fetch_at(nix, fallback, (u1*) &v);
 }

 VAL_Type* fetch(nx nix, nx fallback)
 {
  return (VAL_Type*) hive_structure_->fetch(nix, fallback);
 }

 VAL_Type* _fetch(nx nix, Out_of_Bounds_Resolution_Flags oobf,
   Out_of_Bounds_Resolution_Flags supplement = Out_of_Bounds_Resolution_Flags::N_A)
 {
  u1 value_type_specific_options = oobf
    & Out_of_Bounds_Resolution_Flags::Value_Type_Specific_Options;

  // //  with no Value_Type_Specific_Options
   //    the hive_structure_ can handle the other flags
//  if(value_type_specific_options == 0)
//    return (VAL_Type*) hive_structure_->fetch(nix, oobf | supplement);

  VAL_Type* result = (VAL_Type*) hive_structure_->get(nix);

  if(result)
    return result;


//  // //  now we (may) need to provide a new value for the memory area
//  if(oob & Out_of_Bounds_Resolution_Flags::Use_Alternate_Fallback_Index)
//  {
//   // //  this means we're getting value from the fallback

//   // //  the next question is whether to try initializing the
//    //    fallback if it too is missing ...

//   if(oob & Out_of_Bounds_Resolution_Flags::Fallback_Automatic_Rebound) //Defer_to_Alternate_Fallback_Index)
//   {
//    // //  having both Use_Alternate_Fallback_Index and
//      //    Defer_to_Alternate_Fallback_Index set indicates
//      //    that the fallback strategies are intended for the alternate
//      //    after rebounding for the provided index
//    default_value_ptr = fetch_at(fallback, oob);
//    // //  don't try to use other oob flags if they're intended for the alternate ...
//    goto check_memcpy;
//   }

//   else
//     // //  In this case (without Defer_to_Alternate_Fallback_Index)
//      //    we just assume the fallback index is valid, or at least
//      //    don't try to initialize it (maybe get the default
//      //    from somewhere else, depending on the other flags)
//     default_value_ptr = fetch_at(fallback, Out_of_Bounds_Resolution_Flags::N_A);
//  }


  switch((u1)oobf)
  {
  case (u1) Out_of_Bounds_Resolution_Flags::Call_Default_Value_Function:
    if(default_fn_)
      default_fn_(&result);
   break;
  case (u1) Out_of_Bounds_Resolution_Flags::Use_Default_Value_Pointer:
    result = static_default_value();
   break;
  case (u1) Out_of_Bounds_Resolution_Flags::Call_Default_Constructor_if_Possible:
    default_construct_if_needed_and_possible(&result);
   break;
//  case (u1) Out_of_Bounds_Resolution_Flags::Try_Default_Function_then_Pointer:
//   if(default_fn_)
//     default_fn_(&result);
//   else
//     result = static_default_value();
//   break;
//  case (u1) Out_of_Bounds_Resolution_Flags::Try_Default_Function_then_Constructor:
//   if(default_fn_)
//     default_fn_(&result);
//   else
//     default_construct_if_needed_and_possible(&result);
//   break;

//  case (u1) Out_of_Bounds_Resolution_Flags::Value_Type_Specific_Options:
//   if(default_fn_)
//   {
//    default_fn_(&result);
//    break;
//   }
//   [[fallthrough]];
//   // //  otherwise fallthrough ...
//  case (u1) Out_of_Bounds_Resolution_Flags::Try_Default_Pointer_then_Constructor:
//   result = static_default_value();
//   default_construct_if_needed_and_possible(&result);
//   break;
  }

  return result;
 }

 static nx the_invalid_index()
 {
  return _the_invalid_index<nx>();
 }

 static nx the_invalid_upper_index()
 {
  return _the_invalid_upper_index<nx>();
 }

 VAL_Type* _fetch_via_fallback(nx fallback, u1 count,
   Out_of_Bounds_Resolution_Flags oob[4], Out_of_Bounds_Resolution_Flags supplement)
 {
  VAL_Type* result = nullptr;
  for(u1 u = 0; u < count; ++u)
  {
   qDebug() << u << "f2 = " << (u1) oob[u];
   result = _fetch(fallback, oob[u]);
   if(result)
     break;
  }
  if(result && (supplement & Out_of_Bounds_Resolution_Flags::Fallback_Automatic_Rebound))
    hive_structure_->rebound(fallback, result);
  else
  {
   if(supplement & Out_of_Bounds_Resolution_Flags::Fallback_Automatic_Rebound)
   {
    supplement ^= Out_of_Bounds_Resolution_Flags::Fallback_Automatic_Rebound;
    supplement |= Out_of_Bounds_Resolution_Flags::Automatic_Rebound;
   }
   else if(supplement & Out_of_Bounds_Resolution_Flags::Fallback_Automatic_Rebound)
     supplement ^= Out_of_Bounds_Resolution_Flags::Automatic_Rebound;
   result = (VAL_Type*) hive_structure_->fetch(fallback, supplement);
  }
  return result;
 }

 VAL_Type* fetch(nx nix, _On_Out_of_Bounds_Pack oob, nx fallback = the_invalid_index())
 {
  Out_of_Bounds_Resolution_Flags supplement;

  Out_of_Bounds_Resolution_Flags f1 [4];// {Out_of_Bounds_Resolution_Flags::N_A};
  Out_of_Bounds_Resolution_Flags f2 [4];// {Out_of_Bounds_Resolution_Flags::N_A};

  std::pair<u1, u1> pr = oob.unpack(supplement, f1[0], f1[1], f1[2], f1[3], f2[0], f2[1], f2[2], f2[3]);

  VAL_Type* result = nullptr;

  for(u1 u = 0; u < oob.for_index_length; ++u)
  {
   if(f1[u] == Out_of_Bounds_Resolution_Flags::Use_Alternate_Fallback_Index)
   {
    if(fallback == the_invalid_index())
      continue;
    if(fallback == the_invalid_upper_index())
      continue;
    result = _fetch_via_fallback(fallback, oob.for_fallback_length, f2, supplement);
   }
   else
     result = _fetch(nix, f1[u], supplement);
   if(result)
     break;
   qDebug() << u << " f1 = " << (u1) f1[u];
  }

  if(result && (supplement & Out_of_Bounds_Resolution_Flags::Automatic_Rebound))
    hive_structure_->rebound(nix, result);
  else
    result = (VAL_Type*) hive_structure_->fetch(nix, supplement);

  return result;

  //fetch()
 }

 VAL_Type* fetch(nx nix)
 {
  return (VAL_Type*) hive_structure_->fetch(nix);
 }

 VAL_Type* get(nx nix)
 {
  return (VAL_Type*) hive_structure_->get(nix);
 }

 bool is_empty()
 {
  return hive_structure_->total_size() == 0;
 }


 QString to_qstring(nx nix1, nx nix2, std::function<QString(const VAL_Type& v)> fn,
   QString gap = " ", s2 chop = -1)
 {
  QString result;
  for(nx nix = nix1; nix <= nix2; ++nix)
  {
   result += fn(get_element(nix)) + gap;
  }
  if(!result.isEmpty())
  {
   if(chop == -1)
     chop = gap.size();
   if(chop > 0)
     result.chop(chop);
  }
  return result;
 }

 QString to_qstring(std::function<QString(const VAL_Type& v)> fn,
   QString gap = " ", s2 chop = -1)
 {
  return to_qstring(0, size() - 1, fn, gap, chop);
 }

 nx size()
 {
  return hive_structure_->total_size();
 }

 void declare_size(nx size)
 {
  hive_structure_->set_total_size(size);
 }

 void resize(nx size)
 {
  hive_structure_->resize(size);
 }


 void _set_default(std::function<void(VAL_Type**)> fn)
 {
  set_default_fn(fn);
 }

 ACCESSORS(std::function<void(VAL_Type**)> ,default_fn)

 void push_back(const VAL_Type& v)
 {
  void* spot = hive_structure_->get_push_back_location();
  //VAL_Type* vv = (VAL_Type*) spot;
  memcpy(spot, &v, hive_structure_->value_size());
  hive_structure_->increment_total_size();
 }

 void _each_from_index(nx nix,
   std::function<void(VAL_Type& v)> fn)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->position_iterator(hit, nix);
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   fn(*pv);
   hive_structure_->increment_iterator(hit);
  }
 }

 PR_Type _pr_each_from_index(nx nix,
   std::function<void(VAL_Type& v)> fn)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->position_iterator(hit, nix);
  nx index = 0;
  typename PR_Type::level_type l = -1;
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   ++index;
   l = fn(*pv);
   if(l >= 0)
     break;
   hive_structure_->increment_iterator(hit);
  }
  return {index, l};
 }

 void _each_from_index(nx nix,
   std::function<void(VAL_Type& v, const INDEX_Types& index)> fn)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->position_iterator(hit, nix);
  typename INDEX_Types::Numeric_Index_type index = 0;
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   ++index;
   fn(*pv, index);
   hive_structure_->increment_iterator(hit);
  }
 }

 PR_Type _pr_each_from_index(nx nix,
   std::function<typename PR_Type::level_type(VAL_Type& v, const typename INDEX_Types::Numeric_Index_type& index)> fn)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->position_iterator(hit, nix);
  typename INDEX_Types::Numeric_Index_type index = 0;
  typename PR_Type::level_type l = -1;
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   ++index;
   l = fn(*pv, index);
   if(l >= 0)
     break;
   hive_structure_->increment_iterator(hit);
  }
  return {index, l};
 }


 VAL_Type& last()
 {
  VAL_Type* vv = (VAL_Type*) hive_structure_->get_back_location();
  if(!vv)
    default_fn_(&vv);
  return *vv;
 }

 VAL_Type& first()
 {
  VAL_Type* vv = (VAL_Type*) hive_structure_->get_indexed_location(0);
  if(!vv)
    default_fn_(&vv);
  return *vv;
 }

 VAL_Type& at_index(nx nix)
 {
  VAL_Type* vv = (VAL_Type*) hive_structure_->get_indexed_location(nix);
  if(!vv)
    default_fn_(&vv);
  return *vv;
 }

 VAL_Type* location(nx nix)
 {
  return (VAL_Type*) hive_structure_->get_indexed_location(nix);
 }


 void fill(iterator it, const VAL_Type& v, iterator bound)
 {
  iterator hit = it;
  while(hit.within(bound))
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   *pv = v;
   hive_structure_->increment_iterator(hit);
  }
 }

 iterator iterator_at(nx nix)
 {
  return hive_structure_->iterator_at(nix);
 }

 VAL_Type get_element(nx nix)
 {
  return at_index(nix);
 }

 void _each(std::function<void(VAL_Type& v)> fn)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->check_start_iterator(hit);
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   fn(*pv);
   hive_structure_->increment_iterator(hit);
  }
 }

 PR_Type _pr_each(std::function<typename PR_Type::level_type(VAL_Type& v)> fn)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->check_start_iterator(hit);
  typename INDEX_Types::Numeric_Index_type index = 0;
  typename PR_Type::level_type l = -1;
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   ++index;
   l = fn(*pv);
   if(l >= 0)
     break;
   hive_structure_->increment_iterator(hit);
  }
  return {index, l};
 }

 PR_Type _pr_each(std::function<typename PR_Type::level_type(VAL_Type& v,
     const typename INDEX_Types::Numeric_Index_type& index)> fn,
   typename INDEX_Types::Numeric_Index_type index = 0)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->check_start_iterator(hit);
  typename PR_Type::level_type l = -1;
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   ++index;
   l = fn(*pv, index);
   if(l >= 0)
     break;
   hive_structure_->increment_iterator(hit);
  }
  return {index, l};
 }

 void _each(std::function<void(VAL_Type& v, const typename INDEX_Types::Numeric_Index_type& index)> fn,
   typename INDEX_Types::Numeric_Index_type index = 0)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->check_start_iterator(hit);
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   ++index;
   fn(*pv, index);
   hive_structure_->increment_iterator(hit);
  }
 }

 void _reach(std::function<void(VAL_Type& v)> fn, u4* bottom = nullptr)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->check_start_iterator(hit);
  hive_structure_->reverse_iterator(hit);
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   fn(*pv);
   if(bottom)
   {
    if(hit.total_index == *bottom)
      break;
   }
   hive_structure_->decrement_iterator(hit);
  }
 }

 void _reach_to_index(std::function<void(VAL_Type& v)> fn, u4 bottom)
 {
  _reach(fn, &bottom);
 }

 void _reach(std::function<void(VAL_Type& v, const typename INDEX_Types::Numeric_Index_type& index)> fn,
   u4* bottom = nullptr)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->reverse_iterator(hit);
  typename INDEX_Types::Numeric_Index_type index = 0;
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   ++index;
   fn(*pv, index);
   if(bottom)
   {
    if(hit.total_index == *bottom)
      break;
   }
   hive_structure_->decrement_iterator(hit);
  }
 }

 void _reach_to_index(std::function<void(VAL_Type& v, const typename INDEX_Types::Numeric_Index_type& index)> fn,
   u4 bottom)
 {
  _reach(fn, &bottom);
 }

 PR_Type _pr_reach(std::function<typename PR_Type::level_type(VAL_Type& v)> fn, u4* bottom = nullptr)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->reverse_iterator(hit);
  typename INDEX_Types::Numeric_Index_type index = 0;
  typename PR_Type::level_type l = -1;
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   ++index;
   l = fn(*pv, index);
   if(l >= 0)
     break;
   if(bottom)
   {
    if(hit.total_index == *bottom)
      break;
   }
   hive_structure_->decrement_iterator(hit);
  }
  return {index, l};
 }

 PR_Type _pr_reach_to_index(std::function<typename PR_Type::level_type(VAL_Type& v)> fn,
    u4 bottom)
 {
  return _pr_reach(fn, &bottom);
 }

 PR_Type _pr_reach(std::function<typename PR_Type::level_type(VAL_Type& v,
   const typename INDEX_Types::Numeric_Index_type& index)> fn, u4* bottom = nullptr)
 {
  typename Hive_Structure<INDEX_Types>::iterator hit = Hive_Structure<INDEX_Types>::iterator::start();
  hive_structure_->reverse_iterator(hit);
  typename INDEX_Types::Numeric_Index_type index = 0;
  typename PR_Type::level_type l = -1;
  while(!hit.end())
  {
   VAL_Type* pv = (VAL_Type*) hive_structure_->get_iterator_location(hit);
   ++index;
   l = fn(*pv, index);
   if(l >= 0)
     break;
   if(bottom)
   {
    if(hit.total_index == *bottom)
      break;
   }
   hive_structure_->decrement_iterator(hit);
  }
  return {index, l};
 }

 PR_Type _pr_reach_to_index(std::function<typename PR_Type::level_type(VAL_Type& v,
   const typename INDEX_Types::Numeric_Index_type& index)> fn, u4 bottom)
 {
  return _pr_reach(fn, &bottom);
 }

};


_XCNS(XCSD)

#endif // _VEC1D__H
