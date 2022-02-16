
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

XCNS_(XCSD)

template<typename T, typename Numeric_Index_type = signed short>
struct hive_galaxy
{
 typedef T element_type;
// typedef T index_type;
// typedef T type_descriptor_type;
 typedef Numeric_Index_type numeric_index_type;
};

template<typename GALAXY_Type>
class Hive_Structure
{
public:

 typedef typename GALAXY_Type::element_type element_type;
// typedef typename GALAXY_Type::index_type index_type;
 typedef typename GALAXY_Type::numeric_index_type numeric_index_type;
// typedef typename GALAXY_Type::type_descriptor_type type_descriptor_type;

 struct Hive_Layer
 {
  element_type* elements_;
 };

 struct Hive_Layer_Block
 {
  Hive_Layer* layers_;
  Hive_Layer_Block* next_;
 };

 struct Hive_Layer_Array_Package
 {
  Hive_Layer layer_;
  numeric_index_type size_;
  numeric_index_type min_index_;
 };

 struct Hive_Layer_Block_Package
 {
  Hive_Layer_Block* first_block_;
  numeric_index_type block_size_;
  numeric_index_type min_index_;
  numeric_index_type max_index_;
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

 numeric_index_type size_;

public:

// union {
//  Hypocell_Block_Package* block_package_;
//  Hypocell_Array_Package* array_package_;
//  Hypocell cell_;
// };
// numeric_index_type size_;

 Hive_Structure(numeric_index_type layer_size, numeric_index_type block_size)
  :  block_package_(new Hive_Layer_Block_Package(
                     {new Hive_Layer_Block{new Hive_Layer[block_size], nullptr}, block_size, 0, 0})), size_(-layer_size)
 {
  for(numeric_index_type i = 0; i < block_size; ++i)
  {
   block_package_->first_block_->layers_[i] = {nullptr};
  }
 }


 Hive_Structure(Hive_Layer_Block_Package* block_package, numeric_index_type size)
  :  block_package_(block_package), size_(-size)
 {
 }

 Hive_Structure(Hive_Layer_Array_Package* array_package)
  :  array_package_(array_package), size_(0)
 {
 }

 Hive_Structure(Hive_Layer layer, numeric_index_type size)
  :  single_layer_(layer), size_(size)
 {
 }

 Hive_Structure()
  :  block_package_(nullptr), size_(0)
 {
 }

 numeric_index_type layer_size()
 {
  if(size_ < 0)
    return -size_;
  if(size_ == 0)
    return array_package_->size_;
  return size_;
 }

 Hive_Layer* layer_ptr()
 {
  if(size_ == 0)
    return &array_package_->layer_;
  return &single_layer_;
 }

 bool fixed_size()
 {
  return size_ >= 0;
 }

 void check_max_index(numeric_index_type ind)
 {
  if(size_ < 0)
  {
   if(block_package_->max_index_ < ind)
     block_package_->max_index_ = ind;
  }
 }

 numeric_index_type get_minimum_array_index()
 {
  if(size_ < 0)
    return block_package_->min_index_;
  if(size_ == 0)
    return array_package_->min_index;
  return 0;
 }

 void set_maximum_array_index(numeric_index_type ind)
 {
  if(size_ < 0)
    block_package_->max_index_ = ind;
//   if(size_ == 0)
//     return 0; // array_package_->max_index;
//   return 0;
 }

 numeric_index_type get_maximum_array_index()
 {
  if(size_ < 0)
    return block_package_->max_index_;
  if(size_ == 0)
    return 0; // array_package_->max_index;
  return 0;
 }

 numeric_index_type normalized_array_index(numeric_index_type ind)
 {
  if(size_ < 0)
  {
   numeric_index_type minin = block_package_->min_index_;
   numeric_index_type maxin = block_package_->max_index_;

   ind += minin;
   maxin += minin;
   if(ind > maxin)
     ind = minin;
  }
  else if(size_ == 0)
  {
   numeric_index_type minin = array_package_->min_index;
   ind += minin;
   ind %= array_package_->size;
  }
  return ind;
 }

 element_type& get_element(numeric_index_type index);

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


// Hive_Structure();


// ACCESSORS(u2, block_size)
// ACCESSORS(u4, total_size)
// ACCESSORS(u2, value_size)

// ACCESSORS(Hive_Block*, first_block)

 void* get_push_back_location();
 void* get_back_location();

 void* get_indexed_location(u4 index);
 void* get_indexed_location(u4 blkn, u2 blki);
 void* get_indexed_location_unchecked(u4 index);

 Hive_Layer_Block* check_init_blocks(u4 max);

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

template<typename GALAXY_Type>
typename GALAXY_Type::element_type&
Hive_Structure<GALAXY_Type>::get_element(Hive_Structure::numeric_index_type ind)
{
 int layer_index = ind % layer_size();

 int layer_order = fixed_size()? 0 :
   ind / layer_size();

 Hive_Layer* hl = nullptr;

 if(fixed_size())
   hl = layer_ptr();
 else
 {
  Hive_Layer_Block* hlb = block_package_->first_block_;
  numeric_index_type lcount = block_package_->block_size_;
  int block_index = layer_order % lcount;
  int block_order = layer_order / lcount;
  int order = 0;
  while(order < block_order)
  {
   if(!hlb->next_)
   {
    Hive_Layer* new_hl = new Hive_Layer[lcount];
    for(int i = 0; i < lcount; ++i)
      new_hl[i] = {nullptr};
    Hive_Layer_Block* new_hb = new Hive_Layer_Block{new_hl, nullptr};
    hlb->next_ = new_hb;
   }
   hlb = hlb->next_;
   ++order;
  }
  hl = &(hlb->layers_)[block_index];
  if(hl->elements_ == nullptr)
  {
   hl->elements_ = new element_type[layer_size()];
  }
 }
 return (hl->elements_)[layer_index];
}



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

_XCNS(XCSD)


#endif // HIVE_STRUCTURE__H
