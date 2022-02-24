
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "hive-structure.h"

#include "global-types.h"

#include <QVector>
#include <QString>
#include <QMap>

#include <QDebug>

USING_XCNS(XCSD)


XCNS_(XCSD)

bool get_permutation_numbers(u1 code, u1& first, u1& second, u1& third, u1& fourth)
{
 static u1 result [96] {
  1, 2, 3, 4,  //  4
  1, 2, 4, 3,  //  8
  1, 3, 2, 4,  //  12
  1, 3, 4, 2,  //  16
  1, 4, 2, 3,  //  20
  1, 4, 3, 2,  //  24
  2, 1, 3, 4,  //  28
  2, 1, 4, 3,  //  32
  2, 3, 1, 4,  //  36
  2, 3, 4, 1,  //  40
  2, 4, 1, 3,  //  44
  2, 4, 3, 1,  //  48
  3, 1, 2, 4,  //  52
  3, 1, 4, 2,  //  56
  3, 2, 1, 4,  //  60
  3, 2, 4, 1,  //  64
  3, 4, 1, 2,  //  68
  3, 4, 2, 1,  //  72
  4, 1, 2, 3,  //  76
  4, 1, 3, 2,  //  80
  4, 2, 1, 3,  //  84
  4, 2, 3, 1,  //  88
  4, 3, 1, 2,  //  92
  4, 3, 2, 1,  //  96
 };

 u1 index = code * 4;

 if(index >= 96)
   return false;

 first = result[index];
 second = result[++index];
 third = result[++index];
 fourth = result[++index];

 return true;
}

bool get_permutation_numbers(u1 code, u1& first, u1& second, u1& third)
{
 static u1 result [18] {
  1, 2, 3,  //  3
  1, 3, 2,  //  6
  2, 1, 3,  //  9
  2, 3, 1,  //  12
  3, 1, 2,  //  15
  3, 2, 1,  //  18
 };

 u1 index = code * 3;

 if(index >= 6)
   return false;

 first = result[index];
 second = result[++index];
 third = result[++index];

 return true;
}

s1 get_permutation_code(u1& mask, Out_of_Bounds_Resolution_Flags first,
  Out_of_Bounds_Resolution_Flags second)
{
 mask = (u1) (first | second);

 if(first < second)
   return 30;
 return 31;
}

s1 get_permutation_code(u1& mask, Out_of_Bounds_Resolution_Flags first, Out_of_Bounds_Resolution_Flags second,
   Out_of_Bounds_Resolution_Flags third, Out_of_Bounds_Resolution_Flags fourth)
{
 mask = (u1) (first | second | third | fourth);

 u1 c1 = 1, _c1 = (u1) first >> 4;
 u1 c2 = 1, _c2 = (u1) second >> 4;
 u1 c3 = 1, _c3 = (u1) third >> 4;
 u1 c4 = 1, _c4 = (u1) fourth >> 4;

 while(_c1 >>= 1) ++c1;
 while(_c2 >>= 1) ++c2;
 while(_c3 >>= 1) ++c3;
 while(_c4 >>= 1) ++c4;

 u2 switch_code = c4 + c3 * 8 + c2 * 64 + c1 * 512;

 switch (switch_code)
 {
  case 01234: return 0;
  case 01243: return 1;
  case 01324: return 2;
  case 01342: return 3;
  case 01423: return 4;
  case 01432: return 5;
  case 02134: return 6;
  case 02143: return 7;
  case 02314: return 8;
  case 02341: return 9;
  case 02413: return 10;
  case 02431: return 11;
  case 03124: return 12;
  case 03142: return 13;
  case 03214: return 14;
  case 03241: return 15;
  case 03412: return 16;
  case 03421: return 17;
  case 04123: return 18;
  case 04132: return 19;
  case 04213: return 20;
  case 04231: return 21;
  case 04312: return 22;
  case 04321: return 23;
   break;

  default:
   return -1;
 }
}



s1 get_permutation_code(u1& mask, Out_of_Bounds_Resolution_Flags first, Out_of_Bounds_Resolution_Flags second,
   Out_of_Bounds_Resolution_Flags third)
{
 mask = (u1) (first | second | third);

 u1 c1 = 1, c2 = 1, c3 = 1;

 if(first > second)
   ++c1;
 else
   ++c2;
 if(first > third)
   ++c1;
 else
   ++c3;
 if(second > third)
   ++c2;
 else
   ++c3;


 u1 switch_code = c3 + c2 * 8 + c1 * 64;

 u1 offset = 24;

 switch (switch_code)
 {
  case 0123: return offset + 0;
  case 0132: return offset + 1;
  case 0213: return offset + 2;
  case 0231: return offset + 3;
  case 0312: return offset + 4;
  case 0321: return offset + 5;
   break;

  default:
   return -1;
 }
}

void parse_permutation_code(u1 code, u1 mask, Out_of_Bounds_Resolution_Flags& first, Out_of_Bounds_Resolution_Flags& second,
  Out_of_Bounds_Resolution_Flags& third, Out_of_Bounds_Resolution_Flags& fourth)
{
 u1 mshifted = mask >> 4;
 first = second = third = fourth = Out_of_Bounds_Resolution_Flags::N_A;
 if(mshifted == 0)
   return;
 if(code > 31)
   return;
 if(code > 29)
 {
  u1 low, high;
  switch(mshifted)
  {
  case 3: // 12
   low = 1; high = 2; break;
  case 5: // 14
   low = 1; high = 4; break;
  case 9: // 18
   low = 1; high = 8; break;
  case 6: // 24
   low = 2; high = 4; break;
  case 10: // 28
   low = 2; high = 8; break;
  case 12: // 48
   low = 4; high = 8; break;
  default: return;
  }
  if(code == 30)
  {
   first = (Out_of_Bounds_Resolution_Flags) (low << 4);
   second = (Out_of_Bounds_Resolution_Flags) (high << 4);
   return;
  }
  first = (Out_of_Bounds_Resolution_Flags) (high << 4);
  second = (Out_of_Bounds_Resolution_Flags) (low << 4);
  return;
 }

 if(code > 23)
 {
//  Out_of_Bounds_Resolution_Flags *low, *mid, *high;
  u1 low, mid, high;
//  get_permutation_numbers(code - 24, low, mid, high);

  switch(mshifted)
  {
  case 7: // 124
   low = 1; mid = 2; high = 3; break;
  case 11: // 128
   low = 1; mid = 2; high = 4; break;
  case 13: // 148
   low = 1; mid = 3; high = 4; break;
  case 14: // 248
   low = 2; mid = 3; high = 4; break;
  default: return;
  }

  u1 p1, p2, p3;
  bool ok = get_permutation_numbers(code - 24, p1, p2, p3);
  if(!ok)
    return;
  first = (p1 == 1)?(Out_of_Bounds_Resolution_Flags) (low << 4)
        : (p1 == 2)?(Out_of_Bounds_Resolution_Flags) (mid << 4)
        : (Out_of_Bounds_Resolution_Flags) (high << 4);
  second = (p2 == 1)?(Out_of_Bounds_Resolution_Flags) (low << 4)
         : (p2 == 2)?(Out_of_Bounds_Resolution_Flags) (mid << 4)
         : (Out_of_Bounds_Resolution_Flags) (high << 4);
  third = (p3 == 1)?(Out_of_Bounds_Resolution_Flags) (low << 4)
         : (p3 == 2)?(Out_of_Bounds_Resolution_Flags) (mid << 4)
         : (Out_of_Bounds_Resolution_Flags) (high << 4);
  return;
 }

 if(mshifted < 15)
 {
  switch (mshifted)
  {
  case 1: case 2: case 4: case 8: first = (Out_of_Bounds_Resolution_Flags) mask;
   return;
  default: return;;
  }
 }

 u1 p1, p2, p3, p4;
 bool ok = get_permutation_numbers(code, p1, p2, p3, p4);
 if(!ok)
   return;

 first = (Out_of_Bounds_Resolution_Flags) (p1 << 4);
 second = (Out_of_Bounds_Resolution_Flags) (p2 << 4);
 third = (Out_of_Bounds_Resolution_Flags) (p3 << 4);
 fourth = (Out_of_Bounds_Resolution_Flags) (p4 << 4);
}


_XCNS(XCSD)


//template<typename GALAXY_Type>
//typename GALAXY_Type::element_type&
//Hive_Structure<GALAXY_Type>::get_element(Hive_Structure::numeric_index_type ind)
//{
// int layer_index = ind % layer_size();

// int layer_order = fixed_size()? 0 :
//   ind / layer_size();

// Hive_Layer* hl = nullptr;

// if(fixed_size())
//   hl = layer_ptr();
// else
// {
//  Hive_Layer_Block* hlb = block_package_->first_block_;
//  numeric_index_type lcount = block_package_->block_size_;
//  int block_index = layer_order % lcount;
//  int block_order = layer_order / lcount;
//  int order = 0;
//  while(order < block_order)
//  {
//   if(!hlb->next)
//   {
//    Hive_Layer* new_hl = new Hive_Layer[lcount];
//    for(int i = 0; i < lcount; ++i)
//      new_hl[i] = {nullptr};
//    Hive_Layer_Block* new_hb = new Hive_Layer_Block{new_hl, nullptr};
//    hlb->next = new_hb;
//   }
//   hlb = hlb->next;
//   ++order;
//  }
//  hl = &(hlb->layers)[block_index];
//  if(hl->elements == nullptr)
//  {
//   hl->elements = new element_type[layer_size()];
//  }
// }
// return &(hl->elements)[layer_index];
//}


#ifdef HIDE
Hive_Structure::Hive_Structure()
 :  block_size_(0), total_size_(0),
   value_size_(0), first_block_(nullptr)
{

}

Hive_Block* Hive_Structure::check_init_blocks(u4 max)
{
 Hive_Block** current_block = 1_block_;
 Hive_Block* result = nullptr;
 for(int i = 0; i <= max; ++i)
 {
  if(*current_block)
  {
   result = *current_block;
   current_block = &(*current_block)->next_block;
   continue;
  }
  void* mem = malloc(block_size_ * value_size_);

  (*current_block) = new Hive_Block{mem, nullptr};
  result = *current_block;
  current_block = &(result->next_block);
 }
 return result;
}


void* Hive_Structure::get_indexed_location(u4 index)
{
 if(index >= total_size_)
   return nullptr;
 u4 blkn = index / block_size_;
 u2 blki = index % block_size_;
 return get_indexed_location(blkn, blki);
}

void* Hive_Structure::get_indexed_location_unchecked(u4 index)
{
 u4 blkn = index / block_size_;
 u2 blki = index % block_size_;
 return get_indexed_location(blkn, blki);
}


void* Hive_Structure::get_indexed_location(u4 blkn, u2 blki)
{
 Hive_Block* hb = check_init_blocks(blkn);

 return (unsigned char*)(hb->values)
   + (blki * value_size_);

}

void* Hive_Structure::get_back_location()
{
 if(total_size_ == 0)
   return nullptr;
 return get_indexed_location(total_size_ - 1);
}

void Hive_Structure::push_first_block()
{
 void* mem = malloc(block_size_ * value_size_);
 first_block_ = new Hive_Block{mem, first_block_};
 total_size_ += block_size_;
}

void Hive_Structure::pop_first_block()
{
 if(first_block_)
 {
  if(first_block_->next_block)
  {
   Hive_Block* hb = first_block_;
   first_block_ = first_block_->next_block;
   delete hb;
  }
  else
  {
   delete first_block_;
   first_block_ = nullptr;
  }
 }
}

void Hive_Structure::pop_back()
{
 if(total_size_ == 0)
   return;
 --total_size_;

 u2 blki = (total_size_ % block_size_);

 if(blki == 0)
 {
  u4 blkn = total_size_ / block_size_;
  Hive_Block* hb = check_init_blocks(blkn);
  if(hb)
  {
   if(hb->next_block)
   {
    delete hb->next_block;
    hb->next_block = nullptr;
   }
  }
 }


}

void* Hive_Structure::get_push_back_location()
{
 return get_indexed_location_unchecked(total_size_);
}

void* Hive_Structure::get_iterator_location(iterator& hit)
{
 return get_indexed_location(hit.block_index, hit.inner_index);
}

void Hive_Structure::increment_total_size()
{
 ++total_size_;
}

void Hive_Structure::check_start_iterator(iterator& hit)
{
 if(total_size_ == 0)
 {
  hit.total_index = -1;
  return;
 }
}

void Hive_Structure::reverse_iterator(iterator& hit)
{
 if(total_size_ == 0)
 {
  hit.total_index = -1;
  return;
 }
 hit.total_index = total_size_ - 1;
 hit.block_index = hit.total_index / block_size_;
 hit.inner_index = hit.total_index % block_size_;
}

void Hive_Structure::position_iterator(iterator& hit, u4 ix)
{
 if(ix >= total_size_)
 {
  hit.total_index = -1;
  return;
 }
 hit.total_index = ix;
 hit.block_index = ix / block_size_;
 hit.inner_index = ix % block_size_;
}

void Hive_Structure::increment_iterator(iterator& hit)
{
 if(++hit.total_index == total_size_)
   hit.total_index = -1;
 if(++hit.inner_index == block_size_)
 {
  hit.inner_index = 0;
  ++hit.block_index;
 }
}


void Hive_Structure::decrement_iterator(iterator& hit)
{
 if(hit.total_index == 0)
 {
  hit.total_index = -1;
  return;
 }
 --hit.total_index;
 if(hit.inner_index == 0)
 {
  hit.inner_index = block_size_ - 1;
  --hit.block_index;
 }
 else
   --hit.inner_index;
}

#endif // HIDE
