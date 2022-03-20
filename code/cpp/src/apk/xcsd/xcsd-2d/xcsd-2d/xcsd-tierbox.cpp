
#include "xcsd-tierbox.h"

Box3x3_8bytepx::Box3x3_8bytepx()
 :  pixels({9})
{
 for(u1 count = 0; count < 9; ++count)
 {
  pixels.get_at(count) = 0;
 }
}

Box9x9_8bytepx::Box9x9_8bytepx()
 :  vec_3x3({0})
{
 vec_3x3.init_static_hive(9);
 for(u1 count = 0; count < 9; ++count)
 {
  Box3x3_8bytepx* ptr = vec_3x3.get(count);
  Box3x3_8bytepx* box = new (ptr) Box3x3_8bytepx;
  //vec_3x3.get_at(count) = box
//  Box3x3_8bytepx* box = new Box3x3_8bytepx;
//  Box3x3_8bytepx* box1 = new (ptr) Box3x3_8bytepx;
 }
}



XCSD_TierBox::XCSD_TierBox()
  :  non_full_(0)
{

}

void XCSD_TierBox::init_boxes()
{
 if(non_full_ == 0)
 {
  box9x9_.init_static_hive(9);
  for(u1 count = 0; count < 9; ++count)
  {
   //box9x9_[count] = Box9x9_8bytepx()
   //box9x9_.get_at(count) = Box9x9_8bytepx();
   Box9x9_8bytepx* ptr = box9x9_.get(count);
   Box9x9_8bytepx* box = new (ptr) Box9x9_8bytepx;

  }
 }
}


u2 XCSD_TierBox::non_full_h() const
{
 u1 result = non_full_ & 0b0000'0000'0001'1111;
 if(result < 27)
   return result;
 return 0;
}

u2 XCSD_TierBox::non_full_v() const
{
 u1 result = (non_full_ & 0b0000'0111'1100'0000) >> 6;
 if(result < 27)
   return result;
 return 0;
}

void XCSD_TierBox::set_non_full_h(u2 h)
{
 if(h < 27)
 {
  non_full_ &= 0b0000'0000'0001'1111;
  non_full_ |= h;
 }
}

void XCSD_TierBox::set_non_full_v(u2 v)
{
 if(v < 27)
 {
  non_full_ &= 0b0000'0111'1100'0000;
  non_full_ |= (v << 6);
 }
}


bool XCSD_TierBox::non_full_up() const
{
 u1 result = non_full_ & 0b0000'0000'0001'1111;
 if(result < 27)
   return result;
 return 0;
}

bool XCSD_TierBox::non_full_left() const
{
 u1 result = (non_full_ & 0b0000'0111'1100'0000) >> 6;
 if(result < 27)
   return result;
 return 0;
}

void XCSD_TierBox::set_non_full_up(bool v)
{
 if(v)
   non_full_ |= 0b0000'0000'0010'0000;
 else
   non_full_ &= 0b1111'1111'1101'1111;
}

void XCSD_TierBox::set_non_full_left(bool h)
{
 if(h)
   non_full_ |= 0b0000'1000'0000'0000;
 else
   non_full_ &= 0b1111'0111'1111'1111;
}

