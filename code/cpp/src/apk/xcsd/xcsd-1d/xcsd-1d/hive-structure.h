
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef HIVE_STRUCTURE__H
#define HIVE_STRUCTURE__H


#include "accessors.h"

#include "global-types.h"

#include <QVector>
#include <QString>
#include <QMap>

#include "xcns.h"

#include <limits>

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

template<typename INDEX_Types>
class Hive_Structure
{
public:

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
      layer_size_(-layer_size), value_size_(QT_POINTER_SIZE), total_size_(0)
 {
  for(nnx i = 0; i < block_size; ++i)
  {
   block_package_->first_block_->layers_[i] = {nullptr};
  }
 }


 Hive_Structure(Hive_Layer_Block_Package* block_package, nnx size)
  :  block_package_(block_package), layer_size_(-size), value_size_(QT_POINTER_SIZE), total_size_(0)
 {
 }

 Hive_Structure(Hive_Layer_Array_Package* array_package)
  :  array_package_(array_package), layer_size_(0), value_size_(QT_POINTER_SIZE), total_size_(0)
 {
 }

 Hive_Structure(Hive_Layer layer, nnx size)
  :  single_layer_(layer), layer_size_(size), value_size_(QT_POINTER_SIZE), total_size_(0)
 {
 }

 Hive_Structure()
  :  block_package_(nullptr), layer_size_(0), value_size_(QT_POINTER_SIZE), total_size_(0)
 {
 }

 ACCESSORS(nnx ,value_size)
 ACCESSORS(nx ,total_size)

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
 void* get_location(nx index);

 struct iterator
 {
  nnx inner_index;
  nnx layer_order;
  nnx block_number;
  nx total_index;

  static iterator start()
  {
   return iterator{0,0,0,0};
  }

  bool end()
  {
   return total_index == the_invalid_index();
  }

 };


// Hive_Structure();


// ACCESSORS(u2, block_size)
// ACCESSORS(u4, total_size)
// ACCESSORS(u2, value_size)

// ACCESSORS(Hive_Block*, first_block)

 void* get_push_back_location();
 void* get_back_location();

 void* get_indexed_location(nx nix);
 void* get_indexed_location(nnx block_number, nnx layer_order, nnx inner_index);
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
