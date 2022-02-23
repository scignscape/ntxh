
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef HIVE_STRUCTURE__H
#define HIVE_STRUCTURE__H


#include "accessors.h"

#include "global-types.h"

#include "enum-macros.h"

#include <QVector>
#include <QString>
#include <QMap>

#include "xcns.h"

#include <limits>


#ifndef Contiguous_breakdown_
#define Contiguous_breakdown_(_fn_, \
  _Contiguous_it1_, _Contiguous_it2_, _Contiguous_it3_,\
  _Non_Contiguous_it0_, \
  _Non_Contiguous_it1_, _Non_Contiguous_it2_, _Non_Contiguous_it3_,\
  _coll_, _ty1_, _ty2_, _start_, _end_) \
do{\
QVector<QPair<_ty1_*, _ty2_>> _breakdown_; \
if(_ty1_* Contiguous_it = _coll_.contiguous(_start_, _end_, _breakdown_)) \
{ \
 _fn_(_Contiguous_it1_, _Contiguous_it2_, _Contiguous_it3_); \
} \
else \
{ \
 auto Non_Contiguous_it = _Non_Contiguous_it0_; \
 for(QPair<_ty1_*, _ty2_> pr : _breakdown_) \
 { \
  _fn_(_Non_Contiguous_it1_, _Non_Contiguous_it2_, _Non_Contiguous_it3_); \
  Non_Contiguous_it += pr.second; \
 } \
}} while(0)
#endif



#ifndef _Contiguous_breakdown_
#define _Contiguous_breakdown_(_fn_, _target_, _coll_, _ty1_, _ty2_, _start_, _end_) \
{ \
 QVector<QPair<_ty1_*, _ty2_>> _breakdown_; \
 if(_ty1_* it = _coll_.contiguous(_start_, _end_, _breakdown_)) \
 { \
  _fn_(it, it + _end_, _target_.begin()); \
 } \
 else \
 { \
  auto it1 = _target_.begin(); \
  for(QPair<_ty1_*, _ty2_> pr : _breakdown_) \
  { \
   _fn_(pr.first, pr.first + pr.second, it1); \
   it1 += pr.second; \
  } \
}} while(0)
#endif


#ifndef Contiguous_breakdown_source_
#define Contiguous_breakdown_source_(_fn_, _target_, _coll_, _ty1_, _ty2_, _start_, _end_) \
Contiguous_breakdown_(_fn_, \
  (Contiguous_it), (Contiguous_it + _end_ + 1 - _start_), _target_.begin(), \
  _target_.begin(), \
  pr.first, pr.first + pr.second, Non_Contiguous_it, \
  _coll_, _ty1_, _ty2_, _start_, _end_)
#endif


#ifndef Contiguous_breakdown_target_
#define Contiguous_breakdown_target_(_fn_, _source_, _coll_, _ty1_, _ty2_, _start_, _end_) \
Contiguous_breakdown_(_fn_,\
  _source_.begin(), _source_.end(), Contiguous_it, \
  _source_.begin(), \
  Non_Contiguous_it, Non_Contiguous_it + pr.second, pr.first, \
  _coll_, _ty1_, _ty2_, _start_, _end_)
#endif



//do{\
//QVector<QPair<_ty1_*, _ty2_>> _breakdown_; \
//if(_ty1_* it = _coll_.contiguous(_start_, _end_, _breakdown_)) \
//{ \
// _fn_(_source_.begin(), _source_.end(), it); \
//} \
//else \
//{ \
// auto it1 = _source_.begin(); \
// for(QPair<_ty1_*, _ty2_> pr : _breakdown_) \
// { \
//  _fn_(it1, it1 + pr.second, pr.first); \
//  it1 += pr.second; \
// } \
//}} while(0)

#ifndef Contiguous_breakdown_target
#define Contiguous_breakdown_target(_fn_, _source_, _coll_, _start_, _end_) \
  Contiguous_breakdown_target_(_fn_, _source_, _coll_, typename decltype(_coll_)::Element_type, \
  typename decltype(_coll_)::Numeric_Index_type, _start_, _end_)
#endif

#ifndef Contiguous_breakdown_source
#define Contiguous_breakdown_source(_fn_, _source_, _coll_, _start_, _end_) \
  Contiguous_breakdown_source_(_fn_, _source_, _coll_, typename decltype(_coll_)::Element_type, \
  typename decltype(_coll_)::Numeric_Index_type, _start_, _end_)
#endif


#ifndef Action_scan
#define Action_scan(_fn_, _source_, _coll_, _start_, _end_) \
  Contiguous_breakdown_target(_fn_, _source_, _coll_, _start_, _end_)
#endif

#ifndef Action_span
#define Action_span(_fn_, _target_, _coll_, _start_, _end_) \
  Contiguous_breakdown_source(_fn_, _target_, _coll_, _start_, _end_)
#endif



//Contiguous_breakdown(std::copy, test2, vec, 19, 20);


//#ifndef Contiguous_breakdown
//#define Contiguous_breakdown(_fn_, _source_, _coll_, _start_, _end_) \
//  Contiguous_breakdown_(_fn_, _source_, _coll_, val_t, \
//  nx, _start_, _end_)
//#endif

XCNS_(XCSD)

//template<typename T, typename Numeric_Index_type = signed short>
//struct hive_galaxy
//{
// typedef T element_type;
//// typedef T index_type;
//// typedef T type_descriptor_type;
// typedef Numeric_Index_type nx;
//};

template <typename T, typename NT = s2>
struct index_types
{
 typedef T Numeric_Index_type;
 typedef T Numeric_Nested_Index_type;
};

template <typename T>
T _lower_bound()
{
 return std::numeric_limits<T>::lowest();
}

template <typename T>
T _upper_bound()
{
 return std::numeric_limits<T>::highest();
}

//template <>
//s2 _lower_bound()
//{
// return std::numeric_limits<s2>::lowest();
//}


//template<typename Numeric_Index_type = signed short,
//  typename Numeric_Nested_Index_type = Numeric_Index_type>


//template<typename NUMERIC_INDEX_Type = signed short,
//  typename NUMERIC_NESTED_INDEX_Type = NUMERIC_INDEX_Type>

enum class Out_of_Bounds_Resolution_Flags : u1 {
  N_A = 0,
  Use_Exceptions = 1,
  Automatic_Rebound = 2,
  Use_Default_Value_Pointer = 4,
  Call_Default_Value_Function = 8,
  Call_Default_Constructor_if_Possible = 16,
  Prefer_Initialize_to_Zero = 32,
  Use_Alternate_Fallback_Index = 64,
  Defer_to_Alternate_Fallback_Index = 128,

  Value_Type_Specific_Options = Use_Default_Value_Pointer | Call_Default_Value_Function
    | Call_Default_Constructor_if_Possible,

  Alternate_Fallback_Index_Options =
    Use_Alternate_Fallback_Index | Defer_to_Alternate_Fallback_Index,


};

ENUM_FLAGS_OP_MACROS_FREESTANDING(Out_of_Bounds_Resolution_Flags)


template<typename INDEX_Types>
class Hive_Structure
{
public:


// enum class Out_of_Bounds_Resolution_Flags : u1 {
//   N_A = 0,
//   Use_Exceptions = 1,
//   Automatic_Rebound = 2,
//   Use_Default_Value_Pointer = 4,
//   Call_Default_Value_Function = 8,
//   Call_Default_Constructor_if_Possible = 16,
//   Prefer_Initialize_to_Zero = 32,
//   Use_Alternate_Fallback_Index = 64,
//   Defer_to_Alternate_Fallback_Index = 128,

//   Alternate_Fallback_Index_Options =
//     Use_Alternate_Fallback_Index | Defer_to_Alternate_Fallback_Index,


// };

// ENUM_FLAGS_OP_MACROS(Out_of_Bounds_Resolution_Flags)


 typedef typename INDEX_Types::Numeric_Index_type Numeric_Index_type;
 typedef typename INDEX_Types::Numeric_Nested_Index_type Numeric_Nested_Index_type;

 typedef typename INDEX_Types::Numeric_Index_type nx;
 typedef typename INDEX_Types::Numeric_Nested_Index_type nnx;

// typedef typename GALAXY_Type::element_type element_type;
// typedef typename GALAXY_Type::index_type index_type;
// typedef typename GALAXY_Type::nx nx;
// typedef typename GALAXY_Type::type_descriptor_type type_descriptor_type;


 struct Hive_Layer
 {
  void* elements_;
 };

 struct Hive_Layer_Block
 {
  Hive_Layer* layers_;
  Hive_Layer_Block* next_;
 };

 struct Hive_Layer_Array_Package
 {
  Hive_Layer layer_;
  nnx size_;
//  nnx min_index_;
 };

 struct Hive_Layer_Block_Package
 {
  Hive_Layer_Block* first_block_;
  nnx block_size_;
//  nnx min_index_;
//  nnx max_index_;
 };


// u2 block_size_;
// u4 total_size_;
// u2 value_size_;

// Hive_Layer_Block* first_block_;

 union {
  Hive_Layer_Block_Package* block_package_;
  Hive_Layer_Array_Package* array_package_;
  Hive_Layer single_layer_;
 };

 nnx layer_size_;
 nnx value_size_;
 nx total_size_;

 Out_of_Bounds_Resolution_Flags default_out_of_bounds_resolution_flags_;

public:

// union {
//  Hypocell_Block_Package* block_package_;
//  Hypocell_Array_Package* array_package_;
//  Hypocell cell_;
// };
// nx size_;

 Hive_Structure(nnx layer_size, nnx block_size)
  :  block_package_(new Hive_Layer_Block_Package(
      {new Hive_Layer_Block{new Hive_Layer[block_size], nullptr}, block_size})), //?, 0, 0
      layer_size_(-layer_size), value_size_(QT_POINTER_SIZE), total_size_(0),
      default_out_of_bounds_resolution_flags_(Out_of_Bounds_Resolution_Flags::N_A)
 {
  for(nnx i = 0; i < block_size; ++i)
  {
   block_package_->first_block_->layers_[i] = {nullptr};
  }
 }


 Hive_Structure(Hive_Layer_Block_Package* block_package, nnx size)
  :  block_package_(block_package), layer_size_(-size), value_size_(QT_POINTER_SIZE), total_size_(0),
     default_out_of_bounds_resolution_flags_(Out_of_Bounds_Resolution_Flags::N_A)
 {
 }

 Hive_Structure(Hive_Layer_Array_Package* array_package)
  :  array_package_(array_package), layer_size_(0), value_size_(QT_POINTER_SIZE), total_size_(0),
     default_out_of_bounds_resolution_flags_(Out_of_Bounds_Resolution_Flags::N_A)
 {
 }

 Hive_Structure(Hive_Layer layer, nnx size)
  :  single_layer_(layer), layer_size_(size), value_size_(QT_POINTER_SIZE), total_size_(0),
     default_out_of_bounds_resolution_flags_(Out_of_Bounds_Resolution_Flags::N_A)
 {
 }

 Hive_Structure()
  :  block_package_(nullptr), layer_size_(0), value_size_(QT_POINTER_SIZE), total_size_(0),
     default_out_of_bounds_resolution_flags_(Out_of_Bounds_Resolution_Flags::N_A)
 {
 }

 ACCESSORS(nnx ,value_size)
 ACCESSORS(nx ,total_size)

 void* get_zeroed_location()
 {
  static void* result = nullptr;
  if(!result)
    result = calloc(1, value_size_);
  return result;
 }

 Hive_Layer* get_fixed_size_layer()
 {
  if(layer_size_ == 0)
    return &array_package_->layer_;
  return &single_layer_;
 }

 nnx get_block_number(Numeric_Index_type nix)
 {
  return nix / ((nx) block_size() * layer_size());
 }

 nnx get_block_position(Numeric_Index_type nix)
 {
  return nix % ((nx) block_size() * layer_size());
 }

 nnx get_layer_order(Numeric_Index_type nix)
 {
  return get_block_position(nix) / layer_size();
 }

 nx get_layer_rank(Numeric_Index_type nix)
 {
  return nix / layer_size();
 }

 nnx get_inner_index(Numeric_Index_type nix)
 {
  return nix % layer_size();
 }

 nnx block_size()
 {
  if(layer_size_ < 0)
    return block_package_->block_size_;
  return 0;
 }

 Numeric_Nested_Index_type layer_size()
 {
  if(layer_size_ < 0)
    return -layer_size_;
  if(layer_size_ == 0)
    return array_package_->size_;
  return layer_size_;
 }

 Hive_Layer* layer_ptr()
 {
  if(layer_size_ == 0)
    return &array_package_->layer_;
  return &single_layer_;
 }

 Hive_Layer* get_layer_by_layer_order(nnx block_number, nnx layer_order);
 Hive_Layer* get_layer_by_layer_rank(nnx layer_rank)
 {
  return get_layer_by_layer_order(layer_rank / block_size(), layer_rank % block_size());
 }

 void check_init_layer(Hive_Layer* hl)
 {
  if(!hl->elements_)
    hl->elements_ = malloc(value_size_ * layer_size());
 }

 Hive_Layer* new_hive_layers();

 bool fixed_size()
 {
  return layer_size_ >= 0;
 }

 void delete_block(Hive_Layer_Block* hlb)
 {
  for(nnx i = 0; i < block_package_->block_size_; ++i)
  {
   if(hlb->layers_[i].elements_)
     delete hlb->layers_[i].elements_;
  }
 }

 void check_max_index(nx ind)
 {
  if(layer_size_ < 0)
  {
   if(block_package_->max_index_ < ind)
     block_package_->max_index_ = ind;
  }
 }

 static nx the_invalid_index()
 {
  return _lower_bound<Numeric_Index_type>();
 }

 static nx the_invalid_upper_index()
 {
  return _upper_bound<Numeric_Index_type>();
 }


 nx get_minimum_array_index()
 {
  if(layer_size_ < 0)
    return block_package_->min_index_;
  if(layer_size_ == 0)
    return array_package_->min_index;
  return 0;
 }

 void set_maximum_array_index(nx ind)
 {
  if(layer_size_ < 0)
    block_package_->max_index_ = ind;
//   if(size_ == 0)
//     return 0; // array_package_->max_index;
//   return 0;
 }

 nx get_maximum_array_index()
 {
  if(layer_size_ < 0)
    return block_package_->max_index_;
  if(layer_size_ == 0)
    return 0; // array_package_->max_index;
  return 0;
 }

 nx normalized_array_index(nx ind)
 {
  if(layer_size_ < 0)
  {
   nx minin = block_package_->min_index_;
   nx maxin = block_package_->max_index_;

   ind += minin;
   maxin += minin;
   if(ind > maxin)
     ind = minin;
  }
  else if(layer_size_ == 0)
  {
   nx minin = array_package_->min_index;
   ind += minin;
   ind %= array_package_->size;
  }
  return ind;
 }

 //element_type& get_element(nx index);
 void* get_location(nx nix);

 struct pre_iterator
 {
  nnx block_number;
  nnx layer_order;
  nnx inner_index;

  QString to_qstring()
  {
   return QString("Block Number: %1\nLayer Order: %2\nInner Index: %3")
     .arg(block_number).arg(layer_order).arg(inner_index);
  }
 };

 void resize(nx nix);

 void rebound_to(nx nix)
 {
  set_total_size(nix + 1);
 }

 void* rebound(nx nix);

 void* fetch(nx nix, nx alt, Out_of_Bounds_Resolution_Flags oob);
 void* fetch(nx nix, Out_of_Bounds_Resolution_Flags oob)
 {
  fetch(nix, 0, oob);
 }

 void* fetch_at(nx nix, Out_of_Bounds_Resolution_Flags oob);

 void* fetch(nx nix, nx alt)
 {
  fetch(nix, alt, default_out_of_bounds_resolution_flags_);
 }

 //void* fetch_at(nx nix, nx alt, u1* val);

 void* get(nx nix);

 pre_iterator parse_location(nx nix);

 struct iterator
 {
  nnx block_number;
  nnx layer_order;
  nnx inner_index;
  nx total_index;

  static iterator start()
  {
   return iterator{0,0,0,0};
  }

  bool within(const iterator& rhs)
  {
   if(end())
     return false;
   return total_index < rhs.total_index;
  }

  bool end()
  {
   return total_index == the_invalid_index();
  }

  iterator _end()
  {
   return iterator{block_number, layer_order, inner_index, the_invalid_upper_index()};
  }

 };

 iterator iterator_at(nx nix)
 {
  pre_iterator pre = parse_location(nix);
  return {pre.block_number, pre.layer_order, pre.inner_index, nix};
 }

 //void fill(iterator it, const VAL_Type& v, iterator bound)

// Hive_Structure();


// ACCESSORS(u2, block_size)
// ACCESSORS(u4, total_size)
// ACCESSORS(u2, value_size)

// ACCESSORS(Hive_Block*, first_block)

 void* contiguous(nx nix1, nx nix2);
 void* contiguous(nx nix1, nx nix2, QVector<QPair<void*, nx>>* breakdown);



 void* get_push_back_location();
 void* get_back_location();

 void* get_indexed_location(nx nix);
 void* get_indexed_location(nnx block_number, nnx layer_order, nnx inner_index);

 void* get_raw_indexed_location(nx nix);
 void* get_raw_indexed_location(nnx block_number, nnx layer_order, nnx inner_index);

 void* get_indexed_location_unchecked(nx nix);

 Hive_Layer* get_layer_for_indexed_location(nnx block_number, nnx layer_order);

 Hive_Layer_Block* check_init_blocks(nnx max);
 Hive_Layer_Block* get_block_by_number(nnx desired_block_number);

 void* get_iterator_location(iterator& hit);

 void increment_iterator(iterator& hit);
 void increment_total_size();
 void reverse_iterator(iterator& hit);
 void decrement_iterator(iterator& hit);
 void position_iterator(iterator& hit, Numeric_Index_type nix);

 void check_start_iterator(iterator& hit);

 void pop_back();
 void pop_first_block();
 void push_first_block();

};

_XCNS(XCSD)

#include "hive-structure.templates.h"

USING_XCNS(XCSD)

using Hive_Structure_s2 = Hive_Structure<index_types<s2>>;
using Hive_Structure_s4 = Hive_Structure<index_types<s4>>;



#ifdef HIDE
struct Hive_Block
{
 void* values;
 Hive_Block* next_block;
};


class Hive_Structure
{
 u2 block_size_;
 u4 total_size_;
 u2 value_size_;

 Hive_Block* first_block_;

public:


 struct iterator
 {
  u4 block_index;
  u2 inner_index;
  u4 total_index;

  static iterator start()
  {
   return iterator{0,0,0};
  }

  bool end()
  {
   return total_index == -1;
  }
 };


 Hive_Structure();


 ACCESSORS(u2, block_size)
 ACCESSORS(u4, total_size)
 ACCESSORS(u2, value_size)

 ACCESSORS(Hive_Block*, first_block)

 void* get_push_back_location();
 void* get_back_location();

 void* get_indexed_location(u4 index);
 void* get_indexed_location(u4 blkn, u2 blki);
 void* get_indexed_location_unchecked(u4 index);

 Hive_Block* check_init_blocks(u4 max);

 void* get_iterator_location(iterator& hit);

 void increment_iterator(iterator& hit);
 void increment_total_size();
 void reverse_iterator(iterator& hit);
 void decrement_iterator(iterator& hit);
 void position_iterator(iterator& hit, u4 ix);

 void check_start_iterator(iterator& hit);

 void pop_back();
 void pop_first_block();
 void push_first_block();
};

#endif



#endif // HIVE_STRUCTURE__H
