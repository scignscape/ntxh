
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


_XCNS(XCSD)


#endif // HIVE_STRUCTURE__H
