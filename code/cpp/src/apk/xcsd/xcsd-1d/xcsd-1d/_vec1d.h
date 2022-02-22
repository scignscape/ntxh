
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


#define deffn(ty, arg) [](ty** def) \
{ \
 static ty _def = arg; \
 *def = &_def; \
} \

#define defzfn(ty) deffn(ty, 0)


#ifndef QString_number
#define QString_number(ty) \
  [](ty _t_y_){ return QString::number(_t_y_);}
#endif

//#define _default_fn(ty ,arg) set_default_fn(deffn(ty, arg))
//#define _default_z(ty) _default_fn(ty ,0)

#include "xcns.h"

XCNS_(XCSD)

template<class OBJ_Type>
typename std::enable_if<std::is_default_constructible<OBJ_Type>::value, void>::type
_check_construct(OBJ_Type** obj)
{
 if(!*obj)
   *obj = new OBJ_Type;    // default-construct Obj
}

template<class OBJ_Type>
typename std::enable_if<!std::is_default_constructible<OBJ_Type>::value, void>::type
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

 VAL_Type* contiguous(nx nix1, nx nix2, QVector<QPair<VAL_Type*, nx>>& breakdown)
 {
  return (VAL_Type*) hive_structure_->contiguous(nix1, nix2,
    (QVector<QPair<void*, nx>>*) &breakdown);
 }

 static void default_construct_if_needed_and_possible(VAL_Type** result)
 {
  _check_construct<VAL_Type>(result);
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
