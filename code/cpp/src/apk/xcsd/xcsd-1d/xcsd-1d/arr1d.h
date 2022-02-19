
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef ARR1D__H
#define ARR1D__H


#include "_vec1d.h"

#include "accessors.h"

XCNS_(XCSD)

template<typename VAL_Type, typename INDEX_Types = index_types<s2>, typename PR_Type = _pr_break>
class Arr1d : public _Vec1d<VAL_Type>,
   public each_holders<Arr1d<VAL_Type>, VAL_Type, typename INDEX_Types::Numeric_Index_type, PR_Type>
{
 u4 length_;

public:

 Arr1d(u4 length, typename INDEX_Types::Numeric_Nested_Index_type layer_size = 16,
       typename INDEX_Types::Numeric_Nested_Index_type block_size = 16)
  :  _Vec1d<VAL_Type>(layer_size, block_size),
    each_holders<Arr1d<VAL_Type>, VAL_Type, typename INDEX_Types::Numeric_Index_type, PR_Type>({{*this}}),
    length_(length)
 {
 }

 u4 push_back(const VAL_Type& v)
 {
  u4 sz = this->size();
  if(sz >= length_)
    return 0;
  u4 result = sz - length_;
  _Vec1d<VAL_Type>::push_back(v);
  return result;
 }

};

_XCNS(XCSD)

#endif // ARR1D__H
