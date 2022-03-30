
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "xcsd-image-geometry.h"

#include "xcsd-tierbox.h"

#include <QPainter>

#include <QDebug>

#include <deque>

USING_XCNS(XCSD)

XCSD_Image_Geometry::XCSD_Image_Geometry()
  :  total_size_({0,0}),
     overall_tier_counts_({0,0}),
     full_tier_counts_({0,0}),
     horizontal_outer_sizes_({0,0}),
     vertical_outer_sizes_({0,0}),
     tierbox_count_(0),
     actual_tiergrid_setting_(TierGrid_Preferances::N_A)
{

}


pr2s TierBox_Location::mch_distance_from(const TierBox_Location& rhs)
{
 rc2s raw = rc_.minus(rhs.rc_);

 pr2s raw_sp = raw.spaceship_mask()._to<pr2s>();
 raw_sp.add(raw.zeros_mask());
 rc2 raw_abs = raw.abs();
 pr2 chebychev = raw_abs.greater_which()._to<pr2>();
 u2 manhattan = raw_abs.inner_sum();
 pr2s result = {(s2)manhattan, (s2)(manhattan - chebychev.first)};
 if(chebychev.second == 1) // && !raw.has_zero())
 {
  result._Transpose();
  if(raw.r != 0)
    raw_sp._Transpose();
 }
 result.multiply(raw_sp);
// if(chebychev.second == 0 && !raw.is_coequal())
//   result._Transpose();
 return result;
}


void XCSD_Image_Geometry::_calculate_mch_code_Full(TierBox_Location& tbl)
{
// u2 distance_from_edge = std::max({(u2) tbl.r(),
//   (u2) tbl.c(), (u2) (full_tier_counts_.height - tbl.r() - 1),
//   (u2) (full_tier_counts_.width - tbl.c() - 1)});

 //u4 mch_code = 0;

 TierBox_Location center = get_directed_center(tbl);
 pr2s pr = tbl.mch_distance_from(center);
 tbl.set_mch_code(pr);
}

// if(distance_from_edge == tbl.c())
//   tier_ring = (full_tier_counts_.width / 2) - distance_from_edge;
// else if(distance_from_edge == tbl.r())
//   tier_ring = (full_tier_counts_.height / 2) - distance_from_edge;
// else if(distance_from_edge == full_tier_counts_.height - tbl.r() - 1)
//   tier_ring = distance_from_edge - (full_tier_counts_.width / 2);
// else  tier_ring = distance_from_edge - (full_tier_counts_.height / 2);

void XCSD_Image_Geometry::init_directed_centers()
{
 rc2s first = (full_tier_counts_/2)._transposed()._to<rc2s>();
 std::deque<rc2s> deq {{first}};
 //directed_centers_.push_back(TierBox_Location(first));
 switch (actual_tiergrid_setting_)
 {
 case TierGrid_Preferances::Odd_H_Odd_V:
   // // simplest case because there's only one center
   break;
 case TierGrid_Preferances::Even_H_Odd_V:
   // // also the one to the left
   deq.push_front(first.minus({0, 1}));
   break;

 case TierGrid_Preferances::Odd_H_Even_V:
   // // also the one to the left
   deq.push_front(first.minus({1, 0}));
   break;

 case TierGrid_Preferances::Even_H_Even_V:
   // // also the one to the left
   deq.push_front(first.minus({0, 1}));
   deq.push_front(first.minus({1, 0}));
   deq.push_front(first.minus({1, 1}));
   break;

 default: break;
 }

 std::transform(deq.begin(), deq.end(), std::back_inserter(directed_centers_),
   [](rc2s rc)
 {
  return TierBox_Location(rc);
 });
}

TierBox_Location XCSD_Image_Geometry::get_directed_center(TierBox_Location& tbl)
{
 //rc2s result = (full_tier_counts_/2).transposed()._to<rc2s>();
 switch (actual_tiergrid_setting_)
 {
 case TierGrid_Preferances::Odd_H_Odd_V:
   // // simplest case because there's only one center
  return directed_centers_[0];

 case TierGrid_Preferances::Odd_H_Even_V:
  if(tbl.r() < (full_tier_counts_.height / 2))
    return directed_centers_[0];
  return directed_centers_[1];

 case TierGrid_Preferances::Even_H_Odd_V:
  if(tbl.c() < (full_tier_counts_.width / 2))
    return directed_centers_[0];
  return directed_centers_[1];

 case TierGrid_Preferances::Even_H_Even_V:
  if(tbl.rc() < (full_tier_counts_ / 2)._transposed())
    return directed_centers_[0];
  if(tbl.rc() >= (full_tier_counts_ / 2)._transposed())
    return directed_centers_[3];
  if(tbl.c() < (full_tier_counts_.width / 2))
    return directed_centers_[2];
  return directed_centers_[1];

 default: break;
 }
}


void XCSD_Image_Geometry::calculate_mch_code(TierBox_Location& tbl)
{
 if(tbl.is_full_tier())
   _calculate_mch_code_Full(tbl);
}


TierBox_Location XCSD_Image_Geometry::get_tierbox_location_from_ground_position(u2 x, u2 y)
{
 rc2s result {0,0};

 if(horizontal_outer_sizes_.left > 0)
 {
  if(x <= horizontal_outer_sizes_.left)
    result.c = 0;
  else
  {
   result.c = 1;
   x -= horizontal_outer_sizes_.left;
  }
 }
 x /= 27;
 result.c += x;

 if(vertical_outer_sizes_.top > 0)
 {
  if(y <= vertical_outer_sizes_.top)
    result.r = 0;
  else
  {
   result.r = 1;
   y -= vertical_outer_sizes_.top;
  }
 }
 y /= 27;
 result.r += y;

 if((horizontal_outer_sizes_.right > 0) &&
    (result.c == (overall_tier_counts_.width - 1)))
   result.c = -2;
 else if(horizontal_outer_sizes_.left > 0)
   --result.c;

 if((vertical_outer_sizes_.top > 0) &&
    (result.r == (overall_tier_counts_.height - 1)))
   result.r = -2;
 else if(vertical_outer_sizes_.top > 0)
   --result.r;

 return TierBox_Location(result);
}

lmr2 _split_lmr_even_pref(u2 size, u1 box_width)
{
 u1 dbl = box_width * 2;
 u2 main = size / dbl;
 u1 margins = size % dbl;
 u2 right = margins / 2;
 u2 left = right + (margins % 2);
 return {left, (u2) (main * 2), right};
}

lmr2 _split_lmr_odd_pref(u2 size, u1 box_width)
{
 u1 dbl = box_width * 2;
 u2 main = size / dbl;
 u1 margins = size % dbl;

 s1 adj = 0;

 if(margins > box_width)
 {
  margins -= box_width;
  adj = 1;
 }
 else if(margins < box_width)
 {
  margins += box_width;
  adj = -1;
 }
 else
   return {0, (u2) ((main * 2) + 1), 0};

 u2 right = margins / 2;
 u2 left = right + (margins % 2);
 return {left, (u2) ((main * 2) + adj), right};

}

lmr2 _split_lmr_min_pref(u2 size, u1 box_width)
{
 u1 margins = size % (box_width * 2);
 if(margins > box_width)
  return _split_lmr_odd_pref(size, box_width);
 else
  return _split_lmr_even_pref(size, box_width);
}

lmr2 _split_lmr_max_pref(u2 size, u1 box_width)
{
 u1 margins = size % (box_width * 2);
 if(margins > box_width)
  return _split_lmr_even_pref(size, box_width);
 else
  return _split_lmr_odd_pref(size, box_width);
}

lmr2 XCSD_Image_Geometry::split_lmr(u2 size, u1 box_width, TierGrid_Preferances pref)
{
 if(pref & TierGrid_Preferances::Maximize_Outer_Tiers)
   return _split_lmr_max_pref(size, box_width);
 if(pref & TierGrid_Preferances::Minimize_Outer_Tiers)
   return _split_lmr_min_pref(size, box_width);
 if(pref & TierGrid_Preferances::Odd)
   return _split_lmr_odd_pref(size, box_width);
 return _split_lmr_even_pref(size, box_width);
}

void XCSD_Image_Geometry::reconcile_actual_tiergrid_setting()
{
 if(full_tier_counts_.width % 2)
   actual_tiergrid_setting_ |= TierGrid_Preferances::Odd_H;
 else
   actual_tiergrid_setting_ |= TierGrid_Preferances::Even_H;

 if(full_tier_counts_.height % 2)
   actual_tiergrid_setting_ |= TierGrid_Preferances::Odd_V;
 else
   actual_tiergrid_setting_ |= TierGrid_Preferances::Even_V;
}

void XCSD_Image_Geometry::reconcile_overall_tier_counts()
{
 overall_tier_counts_ = full_tier_counts_;

 if(horizontal_outer_sizes_.left > 0)
   ++overall_tier_counts_.width;
 if(horizontal_outer_sizes_.right > 0)
   ++overall_tier_counts_.width;

 if(vertical_outer_sizes_.top > 0)
   ++overall_tier_counts_.height;
 if(vertical_outer_sizes_.top > 0)
   ++overall_tier_counts_.height;
}

xy2 XCSD_Image_Geometry::Grid_TierBox::top_left()
{
 return ground_center.double_zminus(tierbox_width / 2);
}

xy2 XCSD_Image_Geometry::Grid_TierBox::top_right()
{
 return ground_center.plus_and_zminus(tierbox_width / 2);
}

xy2 XCSD_Image_Geometry::Grid_TierBox::bottom_left()
{
 return ground_center.zminus_and_plus(tierbox_width / 2);
}

xy2 XCSD_Image_Geometry::Grid_TierBox::bottom_right()
{
 return ground_center.double_plus(tierbox_width / 2);
}


void XCSD_Image_Geometry::for_each_horizontal_gridline(std::function<void(Gridline&)> fn)
{
 u1 offset = vertical_outer_sizes_.top;
 for(u2 i = 0; i <= full_tier_counts_.height; ++i)
 {
  Gridline gl {HVD_Options::Horizontal, i, (u2)((i * tierbox_width) + offset)};
  fn(gl);
 }
}

void XCSD_Image_Geometry::for_each_vertical_gridline(std::function<void(Gridline&)> fn)
{
 u1 offset = horizontal_outer_sizes_.left;
 for(u2 i = 0; i <= full_tier_counts_.width; ++i)
 {
  Gridline gl {HVD_Options::Vertical, i, (u2)((i * tierbox_width) + offset)};
  fn(gl);
 }
}

void XCSD_Image_Geometry::for_each_full_tierbox(std::function<void(Grid_TierBox&)> fn)
{
// u1 offset = vertical_outer_sizes_.top;
 tl2 tl{vertical_outer_sizes_.top, horizontal_outer_sizes_.left};
// u4 area = full_tier_counts_.area();

 tl2 offsets = tl || 1;
 for(u2 r = 0; r < full_tier_counts_.height; ++r)
 {
  for(u2 c = 0; c < full_tier_counts_.width; ++c)
  {
   rc2 rc{r, c};
   //rc.add(offsets);
   TierBox_Location tbl(rc._to<rc2s>());
   calculate_mch_code(tbl);
   tbl.rc().add(offsets);
   Grid_TierBox gtb({tbl, ((rc * tierbox_width).plus(tl) + ((tierbox_width / 2) + 1))._transposed_to<xy2>()});
   fn(gtb);
  }
 }
}

void TierBox_Location::set_mch_code(pr2s mch)
{
 mch_code_ = mch.binary_merge();

//   (u4)mch.first << 16;
////  (((u4)mch.first << (16)) | (u4)mch.second);

// mch_code_ |= (u4)(u2)mch.second;

// s2 mc = (s2)(u2)(mch_code_ >> 16);
// s2 mc1 = (mch_code_ & ~(u2)0);

// s2 tt = mc - mc1;
}

pr2s TierBox_Location::get_mch_code()
{
 return {(s2)(mch_code_ >> 16), (s2)(mch_code_ & ~(u2)0)};
}

u1 TierBox_Location::get_mch_clock_code(pr2s pr, u1* mask)
{
// if(pr.has_zero())
// {
////  qDebug() << "pr = " << pr;
// }

 if(pr.is_zeros())
   return 0;

 u1 _mask = 0;

 pr2 abs = pr.abs();

 if(abs.is_ascending())
 {
  _mask |= 4;
  pr._Transpose();
  abs._Transpose();
 }
 if(pr.first < 0)
   _mask |= 2;
 if(pr.second < 0)
   _mask |= 1;

 if(mask)
   *mask = _mask;

// return mask;

 // // size_even_odd_code :
  //   0 = e_e  1 = e_o  2 = o_e  3 = o_o

// static u1 cycle_ortho[4][4] =
//  {
//   {18, 6, 12, 0},
//  // {12, 4, 8, 16},
//  // //  6 -> 0  2 -> 6  4 -> 12  0 -> 18
//   {18, 6, 12, 0},
//   {18, 6, 12, 0},
//  // //  6 -> 0  2 -> 6  4 -> 12  0 -> 18
//   {18, 6, 12, 0}
// };

 // //  6 -> 1  2 -> 7  4 -> 13  0 -> 19
 static u1 cycle_ortho[4] = {19, 7, 13, 1};
 if(pr.has_zero())
 {
  return cycle_ortho[_mask/2];
 }

 // 3 -> 4  2 -> 10  0 -> 16  1 -> 22
 static u1 cycle_diag[4] = {16, 22, 10, 4};

 if(abs.first == (abs.second * 2))
 {
  return cycle_diag[_mask];
 }

 // //  7 -> 3  3 -> 5   2 -> 9   6 -> 11
  //    4 -> 15  0 -> 17  1 -> 21  5 -> 23
 static u1 cycle[8] = {17, 21, 9, 5, 15, 23, 11, 3};
  //{11, 13, 5, 3, 9, 15, 7, 1},

 return cycle[_mask];
}

u1 TierBox_Location::get_mch_clock_code(u1* mask)
{
 return get_mch_clock_code(get_mch_code(), mask);
}

//u1 TierBox_Location::get_orthogonal_quadrant_from_mch_code(u1 size_even_odd_code, u1 quadrant_code, prr2 mch_code)
//{

//}

void TierBox_Location::reconcile_mch_quadrant(u1 size_even_odd_code, u1 quadrant_code,
  u2& clk //prr2& mch_code
  )
{
 if(size_even_odd_code == 3)
   return;

 u1 orthogonal_quadrant = (clk - 1) / 6;

 if((size_even_odd_code > 0)
   && ((size_even_odd_code % 2) != (orthogonal_quadrant % 2)))
   return;

 // //  make it clockwise ...
 if(quadrant_code == 2)
   quadrant_code = 3;
 else if(quadrant_code == 3)
  quadrant_code = 2;

 s1 offset = (quadrant_code == orthogonal_quadrant)? 1 : -1; //1 - 2 * (orthogonal_quadrant % 2);
 clk += offset;

 if(clk == 0)
   clk = 24;

// if((s1) mch_code.third == -1)
//   mch_code.third += 24;
}
// return;

//// s1 offset = (orthogonal_quadrant % 2)? 1 : -1; //1 - 2 * (orthogonal_quadrant % 2);


// if(size_even_odd_code == 0)
// {
//  mch_code.third += offset;
////  if(quadrant_code == orthogonal_quadrant)
////    ++mch_code.third;
////  else
////   --mch_code.third;

//  if((s1) mch_code.third == -1)
//    mch_code.third += 24;

//  return;
// }

// if(size_even_odd_code == 1)
// {
//  if(orthogonal_quadrant % 2)
//    mch_code.third += offset;

////  if(orthogonal_quadrant % 2)
////  {
////   if(quadrant_code == orthogonal_quadrant)
////     ++mch_code.third;
////   else
////    --mch_code.third;
////  }

//  if((s1) mch_code.third == -1)
//    mch_code.third += 24;

//  return;
// }
//  if(quadrant_code == 0 && orthogonal_quadrant == 1)
//    --mch_code.third;
//  else if(quadrant_code == 1 && orthogonal_quadrant == 1)
//    ++mch_code.third;
//  else if(quadrant_code == 2 && orthogonal_quadrant == 3)
//    --mch_code.third;
//  else if(quadrant_code == 3 && orthogonal_quadrant == 3)
//    ++mch_code.third;

//  if((s1) mch_code.third == -1)
//    mch_code.third += 24;

// if(size_even_odd_code == 2)
// {
//  if(orthogonal_quadrant % 2 == 0)
//    mch_code.third += offset;

////  if(orthogonal_quadrant % 2)
////  {
////   if(quadrant_code == orthogonal_quadrant)
////     ++mch_code.third;
////   else
////    --mch_code.third;
////  }

//  if((s1) mch_code.third == -1)
//    mch_code.third += 24;

//  return;
// }


// switch(quadrant_code)
// {
// case 0:
//  if(size_even_odd_code == 1 && orthogonal_quadrant == 1)
//    --mch_code.third;
//  else if(size_even_odd_code == 2 && orthogonal_quadrant == 0)
//    ++mch_code.third;
//  break;
// case 1:
//  if(size_even_odd_code == 1 && orthogonal_quadrant == 1)
//    ++mch_code.third;
//  else if(size_even_odd_code == 2 && orthogonal_quadrant == 2)
//    --mch_code.third;
//  else if(size_even_odd_code == 2 && orthogonal_quadrant == 3)
//    ++mch_code.third;
//  break;
// case 3:
//  if(size_even_odd_code == 1 && orthogonal_quadrant == 3)
//    ++mch_code.third;
//  else if(size_even_odd_code == 2 && orthogonal_quadrant == 2)
//    ++mch_code.third;
//  else if(size_even_odd_code == 2 && orthogonal_quadrant == 0)
//    mch_code.third = 23;
//  break;
// case 2:
//  if(size_even_odd_code == 1 && orthogonal_quadrant == 3)
//    --mch_code.third;
//  else if(size_even_odd_code == 2 && orthogonal_quadrant == 2)
//    ++mch_code.third;
//  break;
// }

// if((s1) mch_code.third == -1)
//   mch_code.third %= 24;

//}

prr2 TierBox_Location::get_mch_code_normalized(u1* mask)
{
 pr2s mch = get_mch_code();
 pr2 result = mch.abs().make_ascending();
 u1 clk = get_mch_clock_code(mch, mask);
 return {result.first, result.second, clk};
}

u1 XCSD_Image_Geometry::get_size_even_odd_code()
{
 switch (actual_tiergrid_setting_)
 {
 case TierGrid_Preferances::Even_H_Even_V: return 0;
 case TierGrid_Preferances::Even_H_Odd_V: return 1;
 case TierGrid_Preferances::Odd_H_Even_V: return 2;
 case TierGrid_Preferances::Odd_H_Odd_V: return 3;
 default: return 0;
 }
}

//u4 XCSD_Image_Geometry::MCH_Info::get_area_threshold_adjustment(wh2 tier_size,
//  u1 size_even_odd_code, u1 quadrant_code)
//{
// if(margin_code == 0)
//   return 0;

// // //  make it clockwise ...
// if(quadrant_code == 2)
//   quadrant_code = 3;
// else if(quadrant_code == 3)
//  quadrant_code = 2;

// return 0;
//}

u1 XCSD_Image_Geometry::MCH_Info::get_compressed_clock_index(u1 clk,
  u1 size_even_odd_code, u1 quadrant_code)
{
 // //  make it clockwise ...
 if(quadrant_code == 2)
   quadrant_code = 3;
 else if(quadrant_code == 3)
  quadrant_code = 2;

 s1 adj = clk - 4;

 if(clk == 0)
 {
  if(size_even_odd_code == 0)
    return quadrant_code;
  else if(size_even_odd_code < 2)
    return 1 - (quadrant_code % 2);
  else
    return 0;
 }

 if((adj % 6) == 0)
   return adj / 6;

 if( (clk % 2) && ((clk - 1) % 6))
 {
  u1 uclk = (clk - 3) / 2;
  if(uclk > 2)
    return uclk - (uclk - 2) / 3  - 1;
  return uclk;
 }

 pr1s adj_1_4;

 switch (size_even_odd_code)
 {
 case 0:
 {
  u1 uclk = clk % 6? clk + 1 : clk - 1;
  s1 sclk = (uclk / 3);
  if(clk % 6)
   --sclk;
  return (u1) (sclk % 8);
 }
 case 1:
  if(clk % 2) // 1, 13
   return (clk - 1) / 4;
  else if(clk % 6) // 8, 20            // !% ?
   adj_1_4 = {3, -12}; //return 3 + ((clk - 12) / 4);
  else  // 6, 18
   adj_1_4 = {-1, 2}; //return ((clk + 2) / 4) - 1;
  break;
 case 2:
  if(clk % 2) // 7, 19
   adj_1_4 = {1, -7}; //return 1 + ((clk - 7) / 4);
  else if(clk % 6) // 2, 14
   return (clk - 2) / 4;
  else // 12, 24
   adj_1_4 = {2, -12};
  break;//return 2 + ((clk - 12) / 4);
 case 3:
  return (clk - 1) / 6;
 default:
  break;
 }

 // //  return adj_1_4.times({4, 1}).plus({0, (s1)clk}).divide({1, 4}).inner_sum();
 return adj_1_4.first + ((clk + adj_1_4.second) / 4);
}

XCSD_Image_Geometry::MCH_Info::MCH_Info(const prr2& mch, const prr2& margin_info,
   u2 lesser_side, Size_Even_Odd_Info& size_even_odd_info, u1 quadrant_code)
{
 margin_code = (u1) margin_info.first;
 margin_gap = margin_info.second;

 u1 size_even_odd_code = size_even_odd_info.size_even_odd_code;

// clock_index_adjustment = 77;

// intra_tier_ring_index = mch.first;

 intra_tier_ring_index = mch.first; //quadrant_code;

 full_clock_index = mch.third;

// qDebug() << "margin code = " << margin_code << ", full_margin = " << margin_info.third;
// qDebug() << "quadrant code = " << quadrant_code;

// u1 v_center_adjustment = 1 - (size_even_odd_code % 2); // 1 extra center row
// u1 h_center_adjustment = 1 - ((size_even_odd_code >> 1) % 2); // 1 extra center column

// u1 full_ortho_cycle_size = 4 + 2 * v_center_adjustment + 2 * h_center_adjustment;

// u1 margin_ortho_cycle_size =
//   margin_code == 0? 0:
//   margin_code & 3;//


 if(margin_code == 0)
 {
  area_threshold_adjustment = 0;
  clock_index_adjustment = 0;
 }
 else
 {
  area_threshold_adjustment = (margin_gap - 1) * lesser_side * 2;


  switch (full_clock_index)
  {
   // 3 - 23: margin_code == 1
  default: clock_index_adjustment = 0; break;
  case 23: // top and bottom
   clock_index_adjustment = 4; break;
  case 24:  // 1 or 2, top and bottom ortho
   clock_index_adjustment = 2 * (1 + size_even_odd_info.h_center_adjustment);
   break;

   // 5 - 9: margin_code == 2
  case 5: // left
  case 6: case 7: case 8: // left ortho
   clock_index_adjustment = 1; break;

   // 11 - 15: margin_code == 3
  case 11: case 15: // top
    clock_index_adjustment = 2; break;
  case 12: case 13: case 14: // top ortho
    clock_index_adjustment = 1 + size_even_odd_info.h_center_adjustment; break;

   // 17 - 21: margin_code == 4
  case 17: case 21: // left and right
    clock_index_adjustment = 4; break;
  case 18: case 19: case 20: // left and right ortho
    // // only count the one extra v-center from the left
     //   because the other (if it exists) is at index 24
    clock_index_adjustment = 2 + size_even_odd_info.v_center_adjustment;
    break;
  }

//  if(margin_code & 1)
//  {
//   if(margin_code == 1)
//   {
//    if( (intra_tier_ring_index > 0) && (quadrant_code == 2) )
//    {
//     clock_index_adjustment = 13;
//    }
//    else
//      clock_index_adjustment = 0;
//   }
//   else if(quadrant_code == 3) // m == 3
//   {
//    clock_index_adjustment = 33;
//   }
//   else // q == 4, m == 3
//   {
//    clock_index_adjustment = 43;
//   }

//  }

 }

 tier_ring = mch.second - mch.first;
 inner_pushout = mch.first;

 if(tier_ring == 0)
 {
  area_threshold = 0;

  switch (size_even_odd_code)
  {
  case 0: // h even, v even
    compressed_clock_index = quadrant_code;
    if(compressed_clock_index == 2)
       compressed_clock_index = 3;
    else if(compressed_clock_index == 3)
      compressed_clock_index = 2;
    break;
  case 1: // h even, v odd
    compressed_clock_index = quadrant_code == 3; break;
  case 2: // h odd, v even
   compressed_clock_index = quadrant_code != 1; break;
  default:
  case 3: // h odd, v odd
    compressed_clock_index = 0; break;

  }

  full_tier_index = compressed_clock_index;

  //  if(quadrant_code > 0)
//  {
//   if(quadrant_code == 3)
//  }

  return;
 }



 if(tier_ring == 0)
   area_threshold = 0;
 else
 {
  u4 sq, sqh, sqv;

  if(margin_code == 0 || margin_gap == 1) //? (2 * tier_ring) - 1 : lesser_side;
//  {
    sq = (2 * tier_ring) - 1;
//  }
  else
//  {
//   if(margin_code == 1)
//   {
//    qDebug() << "sq = " << lesser_side;
//   }
    sq = lesser_side;
//   sqh = sq + 1 - (size_even_odd_code & 1);
//   sqv = sq + 1 - ((size_even_odd_code >> 1) & 1);
//  }

  // //  the -1 + 1 is mathematically redundant here
   //    but expresses that sq represents the square
   //    side spanned by the tier ring
  sqh = sq + 1 - (size_even_odd_code & 1);
  sqv = sq + 1 - ((size_even_odd_code >> 1) & 1);

//  qDebug() << "seoc = " << size_even_odd_code;

//  qDebug() << "sq = " << sq << ", sqh = " << sqh << ", sqv = " << sqv;

  area_threshold = sqh * sqv;
  //area_threshold = (2 * (tier_ring + 1));
 }


 area_threshold += area_threshold_adjustment;

 compressed_clock_index = get_compressed_clock_index(mch.third, size_even_odd_code, quadrant_code);


 // // calculate full_tier_index
 full_tier_index = area_threshold;

// if(full_clock_index > 0) // start at 0 for the inner 1, 2, or 4 tierboxes
//   ++full_tier_index;
// else
// {
//  qDebug() << "fti " << full_tier_index;
// }

 if(intra_tier_ring_index > 0)
 {
  if(margin_code == 0)
  {
   full_tier_index += size_even_odd_info.full_ortho_cycle_size;
   full_tier_index += ((intra_tier_ring_index - 1) * 8);
  }
  else
  {
   full_tier_index += size_even_odd_info.margin_ortho_cycle_size;
   full_tier_index += ((intra_tier_ring_index - 1) * 4);
  }
 }

 full_tier_index += compressed_clock_index - clock_index_adjustment;

 if(full_tier_index > 300)
 {
  qDebug() << "fti " << full_tier_index;
 }

 //get_area_threshold_adjustment(tier_size, size_even_odd_code, quadrant_code);
 //s1 adj = mch.third - 4;

 //u1 clk = mch.third;

}

prr2 XCSD_Image_Geometry::get_margin_info(const TierBox_Location& loc, u1 quadrant_code)
{
// u2 intra_tier_ring_index =

//   quadrant_code == 0? (full_tier_counts_.height / 2) - loc.r():
//   quadrant_code == 0? (full_tier_counts_.height / 2) - loc.r():
//                       ;


// if(full_tier_counts_.is_coequal())
//   return {0, 0, 0};

 //u1 size_even_odd_code = get_size_even_odd_code();


 u1 lmod = full_tier_counts_.width % 2;
 u1 hmod = full_tier_counts_.height % 2;

// qDebug() << "seoc = " << size_even_odd_code;
// qDebug() << "hmod = " << hmod;
// qDebug() << "lmod = " << lmod;

 u1 adj = hmod & lmod;

 u1 margin_code = 0;
 //
 u2 full_margin = 0;

 u2 margin_gap = 0;


 if(full_tier_counts_.is_ascending())
 {
  // //  portrait-like
  u2 r = loc.r();
  u2 top = full_tier_counts_._transposed().inner_difference() / 2;
  full_margin = top;

  if(r < top + hmod - adj)
  {
   margin_code = 2;
   margin_gap = top + hmod - adj - r;
  }

  if(r > top + full_tier_counts_.width + lmod - 1 - adj)
  {
   margin_code = 4;
   // margin_gap = r - (top + full_tier_counts_.width + lmod - 1 - adj);
   margin_gap = r - top - full_tier_counts_.width - lmod + 1 + adj;
  }

  //?

 }
 else
 {
 // //  landscape-like
  u2 c = loc.c();
  u2 left = full_tier_counts_.inner_difference() / 2;

  full_margin = left;

  if(c < left + lmod - adj)
  {
   margin_code = 1;
   margin_gap = left + lmod - adj - c;
  }

  if(c > left + full_tier_counts_.height + hmod - 1 - adj)
  {
   margin_code = 3;
   //margin_gap = c - (left + full_tier_counts_.height + hmod - 1 - adj);
   margin_gap = c - left - full_tier_counts_.height - hmod + 1 + adj;
  }

 }
 return {margin_code, margin_gap, full_margin};

#ifdef HIDE
 switch(size_even_odd_code)
 {
 case 0:
  if(c < left + lmod)  // lh = 00
    return 1;
  else if(c > left + full_tier_counts_.height + hmod - 1)
    return 3;
  break;
 case 1:
  if(c < left + lmod)    // lh = 01
    return 1;
  else if(c > left + full_tier_counts_.height + hmod - 1)
    return 3;
  break;
// case 2:
//  if(c < left)
//    return 1;
//  else if(c >= left + full_tier_counts_.height)
//    return 3;
//  break;

//  if(c < left + (full_tier_counts_.width % 2))
//    return 1;
//  else if(c > left + full_tier_counts_.height)
//    return 3;
//  break;
 case 2:   // lh = 10
  if(c < left + lmod)
    return 1;
  else if(c > left + full_tier_counts_.height + hmod - 1)
    return 3;
  break;
 case 3:
  adj = 1; // lh = 11
  if(c < left + lmod - adj)
    return 1;
  else if(c > left + full_tier_counts_.height + hmod - 1 + adj)
    return 3;
  break;
 default: break;
 }


 return 0;
#endif
}

void XCSD_Image_Geometry::Size_Even_Odd_Info::landscape()
{
 margin_ortho_cycle_size = 2 * (1 + v_center_adjustment);
}

void XCSD_Image_Geometry::Size_Even_Odd_Info::portrait()
{
 margin_ortho_cycle_size = 2 * (1 + h_center_adjustment);
}



void XCSD_Image_Geometry::draw_tier_summary(QString path, QString path1,
  r8 magnification, u1 circle_radius)
{
 static xy2s bl_text_pixel_offset {1, -6};
 static xy2s bl1_text_pixel_offset {1, -1};
 static xy2s tl_text_pixel_offset {1, 3};

 static xy2s br_text_pixel_offset {-5, -4};

 static xy2s br_text1_pixel_offset {-9, -3};

 static xy2s tr_text_pixel_offset {-3, 6};

 static xy2s ml_text_pixel_offset {1, 10};

 wh2 summary_image_size = total_size_ * magnification;
 QImage image(summary_image_size.width, summary_image_size.height, QImage::Format_RGB16);
 image.fill(-1);

 QImage image1(summary_image_size.width, summary_image_size.height, QImage::Format_RGB16);
 image1.fill(-1);

 u1 size_even_odd_code = get_size_even_odd_code();
 Size_Even_Odd_Info size_even_odd_info(size_even_odd_code);

 if(full_tier_counts_.is_ascending()) // w < h
   size_even_odd_info.portrait();
 else if(full_tier_counts_.is_descending()) // w > h
   size_even_odd_info.landscape();

 QPainter painter;
 painter.begin(&image);

 QPainter painter1;
 painter1.begin(&image1);

 for_each_horizontal_gridline([&painter, &painter1, &summary_image_size, magnification](Gridline& gl)
 {
  painter.drawLine(0, gl.ground_index * magnification,
    summary_image_size.width, gl.ground_index * magnification);

  painter1.drawLine(0, gl.ground_index * magnification,
    summary_image_size.width, gl.ground_index * magnification);
 });

 for_each_vertical_gridline([&painter, &painter1, &summary_image_size, magnification](Gridline& gl)
 {
  painter.drawLine(gl.ground_index * magnification, 0,
    gl.ground_index * magnification, summary_image_size.height);

  painter1.drawLine(gl.ground_index * magnification, 0,
    gl.ground_index * magnification, summary_image_size.height);
 });

 for_each_full_tierbox([this, &painter, &painter1, magnification,
   circle_radius, size_even_odd_code, &size_even_odd_info](Grid_TierBox& gtb)
 {
  xy2s extra_trtext_pixel_offset {0, 0};
  xy2s extra_brtext_pixel_offset {0, 0};
  xy2s extra_brtext1_pixel_offset {0, 0};

  bool is_notation_center = (gtb.loc.rc() == directed_centers_[0].rc());

  rc2s quadrant = gtb.loc.rc() - directed_centers_.back().rc();

//  qDebug() << "quadrant = " << quadrant;

  rc2s quadrant_mask = quadrant.spaceship_mask().plus(quadrant.zeros_mask());

  u1 quadrant_code = quadrant_mask.floor(0).times({2, 1}).inner_sum();

//  qDebug() << "quadrant_code = " << quadrant_code;

 // u3



  xy2 xyc = gtb.ground_center * magnification;

  //pr2s mch_code = gtb.loc.get_mch_code();

  u1 mask;
  prr2 mch = gtb.loc.get_mch_code_normalized(&mask);


  if(mch.first == 0)
  {
   if(mch.second == 0)
   {
    painter.setBrush(Qt::yellow);
    painter1.setBrush(Qt::yellow);
   }
   else
   {
    painter.setBrush(Qt::red);
    painter1.setBrush(Qt::red);
    TierBox_Location::reconcile_mch_quadrant(size_even_odd_code, quadrant_code, mch.third);
   }
  }
  else if(mch.second == mch.first * 2)
  {
   painter.setBrush(Qt::cyan);
   painter1.setBrush(Qt::cyan);
  }

  painter.drawEllipse(QPoint(xyc.x, xyc.y), circle_radius, circle_radius);
  painter1.drawEllipse(QPoint(xyc.x, xyc.y), circle_radius, circle_radius);

  painter.setBrush(Qt::NoBrush);
  painter1.setBrush(Qt::NoBrush);

  prr2 margin_info = get_margin_info(gtb.loc, quadrant_code);

  if(gtb.loc.rc() == rc2{3, 5})
  {
   qDebug() << "stop ...";
  }


  MCH_Info mchi(mch, margin_info, full_tier_counts_.lesser(),
    size_even_odd_info, quadrant_code);

  pr2s raw_mch = gtb.loc.get_mch_code();

  QString tl_text = QString("%1,%2")
    .arg(gtb.loc.r()).arg(gtb.loc.c())
    ;

  QString tl_text1 = QString("%1 %2 + %3")
    .arg(mchi.area_threshold).arg(mchi.margin_gap).arg(mchi.area_threshold_adjustment);

  QString ml_text1 = QString("%1 %2").arg(mchi.intra_tier_ring_index)
    .arg(mchi.clock_index_adjustment);

  QString bl_text = QString("%1,%2")
    .arg(mch.first).arg(mch.second)//.arg(mch.third)
    //.arg(raw_mch.first).arg(raw_mch.second)
     //.arg(raw_mch.first).arg(raw_mch.second).arg(mask)
    ;

  QString bl1_text = QString("%1 %2")
    //.arg(mch.first).arg(mch.second)//.arg(mch.third)
    .arg(raw_mch.first).arg(raw_mch.second)
     //.arg(raw_mch.first).arg(raw_mch.second).arg(mask)
    ;

  QString tr_text = QString::number(mask)
    ;

  QString tr_text1 = QString::number(mchi.margin_code);
    ;

  QString br_text = QString::number(mch.third)
    ;


  //QString br_text1 = QString::number(mchi.tier_ring); //mch.drop_last()._transposed().inner_difference());
  QString br_text1 = QString("%1, %2").arg(mchi.tier_ring).arg(quadrant_code);
//    .arg(mchi.clock_index); //mch.drop_last()._transposed().inner_difference());

  QString bl_text1 = QString("%1~ %2").arg(mchi.inner_pushout)
    .arg(mchi.full_tier_index); //mch.drop_last()._transposed().inner_difference());

  QString bl1_text1 = QString::number(mchi.compressed_clock_index); //mch.drop_last()._transposed().inner_difference());

  if(is_notation_center)
  {
   extra_trtext_pixel_offset.x = -11;
   extra_brtext_pixel_offset.x = -3;
   extra_brtext1_pixel_offset.x = -3;


   bl_text.prepend("mch=");
   bl1_text.prepend("raw= ");

   tr_text.prepend("mask=");
   br_text.prepend("clk ");

   tr_text1.prepend("mrgn ");
   tl_text1.prepend("ath ");
   br_text1.prepend("r,q ");

   bl_text1.prepend("psh,ti ");
   bl1_text1.prepend("index ");

   ml_text1.prepend("itr,cia ");

  }
  else if(br_text.length() == 1)
    extra_brtext_pixel_offset.x = 1;
   // br_text.prepend('0');

  xy2 bl_xy = gtb.bottom_left()._to<xy2s>().plus(bl_text_pixel_offset)._to<xy2>() * magnification;
  xy2 bl1_xy = gtb.bottom_left()._to<xy2s>().plus(bl1_text_pixel_offset)._to<xy2>() * magnification;
  xy2 tl_xy = gtb.top_left()._to<xy2s>().plus(tl_text_pixel_offset)._to<xy2>() * magnification;
  xy2 br_xy = gtb.bottom_right()._to<xy2s>().plus(br_text_pixel_offset)
    .plus(extra_brtext_pixel_offset)._to<xy2>() * magnification;
  xy2 br1_xy = gtb.bottom_right()._to<xy2s>().plus(br_text1_pixel_offset)
    .plus(extra_brtext1_pixel_offset)._to<xy2>() * magnification;
  xy2 tr_xy = gtb.top_right()._to<xy2s>().plus(tr_text_pixel_offset)
    .plus(extra_trtext_pixel_offset)._to<xy2>() * magnification;
  xy2 ml_xy = gtb.top_left()._to<xy2s>().plus(ml_text_pixel_offset)
    ._to<xy2>() * magnification;


  painter.drawText(bl1_xy.x, bl1_xy.y, bl1_text);
  painter.drawText(bl_xy.x, bl_xy.y, bl_text);
  painter.drawText(tl_xy.x, tl_xy.y, tl_text);

  painter.drawText(br_xy.x, br_xy.y, br_text);
  painter.drawText(tr_xy.x, tr_xy.y, tr_text);

  painter1.drawText(tr_xy.x, tr_xy.y, tr_text1);
  painter1.drawText(tl_xy.x, tl_xy.y, tl_text1);
  painter1.drawText(br1_xy.x, br1_xy.y, br_text1);
  painter1.drawText(bl_xy.x, bl_xy.y, bl_text1);
  painter1.drawText(bl1_xy.x, bl1_xy.y, bl1_text1);

  painter1.drawText(ml_xy.x, ml_xy.y, ml_text1);

  //qDebug() << "xy = " << xy << " str = " << str;
  });

 painter.end();
 painter1.end();

 image.save(path);
 image1.save(path1);
}




void XCSD_Image_Geometry::init_tier_counts(TierGrid_Preferances pref)
{
 u2 w = total_size_.width;
 u2 h = total_size_.height;

 lmr2 lmr = split_lmr(w, tierbox_width, (TierGrid_Preferances) (pref & 15));
 tmb2 tmb = split_tmb(h, tierbox_width, (TierGrid_Preferances) (pref >> 4));

 full_tier_counts_ = {lmr.main, tmb.main};

 horizontal_outer_sizes_ = lmr.drop_mid();
 vertical_outer_sizes_ = tmb.drop_mid();

 reconcile_actual_tiergrid_setting();
 init_directed_centers();
 reconcile_overall_tier_counts();

 //(TierGrid_Preferances) (pref >> 4)

// u2 ws = w / 27;
// u2 hs = h / 27;

// u2 w0 = w % 27 / 2;
// u2 h0 = h % 27 / 2;
// //return {(u2)image_.width(), (u2)image_.height()};

// if(w0 == 0)
// {
//  if((w % 27) == 1)
//  {
//   ++ws;
//   horizontal_outer_sizes_.right = 1;
//  }
// }
// else
// {
//  ws += 2;
//  horizontal_outer_sizes_ = {w0, (u2) (w0 + ((w % 27) % 2))};
// }

// if(h0 == 0)
// {
//  if((h % 27) == 1)
//  {
//   ++hs;
//   vertical_outer_sizes_.bottom = 1;
//  }
// }
// else
// {
//  hs += 2;
//  vertical_outer_sizes_ = {h0, (u2) (h0 + ((h % 27) % 2))};
// }

// tier_counts_ = {ws, hs};
// tierbox_count_ = tier_counts_.area();
}



//case 0:
// if(size_even_odd_code == 1 && orthogonal_quadrant == 1)
//   --mch_code.third;
// else if(size_even_odd_code == 2 && orthogonal_quadrant == 0)
//   ++mch_code.third;
// else if(size_even_odd_code == 0)
// { qDebug() << "0 - " << orthogonal_quadrant;
////   mch_code.third += offset;
//  if(orthogonal_quadrant == 1)
//    --mch_code.third;
//  else // 2
//    ++mch_code.third;
// }
// break;
//case 1:
// if(size_even_odd_code == 1 && orthogonal_quadrant == 1)
//   ++mch_code.third;
// else if(size_even_odd_code == 2 && orthogonal_quadrant == 2)
//   --mch_code.third;
// else if(size_even_odd_code == 2 && orthogonal_quadrant == 3)
//   ++mch_code.third;
// else if(size_even_odd_code == 0)
// { qDebug() << "1 - " << orthogonal_quadrant;
//  if(orthogonal_quadrant == 1)
//    ++mch_code.third;
//  else // == 2
//    --mch_code.third;
// }
// break;
//case 2:
// if(size_even_odd_code == 1 && orthogonal_quadrant == 3)
//   ++mch_code.third;
// else if(size_even_odd_code == 2 && orthogonal_quadrant == 2)
//   ++mch_code.third;
// else if(size_even_odd_code == 2 && orthogonal_quadrant == 0)
//   mch_code.third = 23;
// else if(size_even_odd_code == 0)
// { qDebug() << "2 - " << orthogonal_quadrant;
//  if(orthogonal_quadrant == 3)
//    ++mch_code.third;
//  else // == 4
//    --mch_code.third; // mch_code.third = 23;
// }
// break;
//case 3:
// if(size_even_odd_code == 1 && orthogonal_quadrant == 3)
//   --mch_code.third;
// else if(size_even_odd_code == 2 && orthogonal_quadrant == 2)
//   ++mch_code.third;
// else if(size_even_odd_code == 0)
// { qDebug() << "3 - " << orthogonal_quadrant;
//  if(orthogonal_quadrant == 2)
//    ++mch_code.third;
//  else // == 3
//    --mch_code.third;
// }



//XCSD_Image_Geometry::MCH_Info::MCH_Info(const prr2& mch, u1 size_even_odd_code, u1 quadrant_code)
//{
// tier_ring = mch.second - mch.first;
// inner_pushout = mch.first;

// clock_index = 0;

// // //  make it clockwise ...
// if(quadrant_code == 2)
//   quadrant_code = 3;
// else if(quadrant_code == 3)
//  quadrant_code = 2;

// //s1 adj = mch.third - 4;

// u1 clk = mch.third;

// s1 adj = clk - 4;

//// if(mch.first == 0)
//// {
////  if(mch.second == 0)
//  if(clk == 0)
//  {
//   if(size_even_odd_code == 0)
//     clock_index = quadrant_code;
//   else if(size_even_odd_code < 2)
//    clock_index = 1 - (quadrant_code % 2);
//  }

////   else if(clk % 2)
////   {
////    clock_index = 100 + ((clk - 3) / 2);
////   }

//  else if((adj % 6) == 0)
//  {

// //  if(adj % 6)
// //    ;
// //  else // clk = 4, 10, 16, 22
//   clock_index = adj / 6;
//  }

//  else if( (clk % 2) && ((clk - 1) % 6))
//  {
//   u1 uclk = (clk - 3) / 2;
//   if(uclk > 2)
//     clock_index = uclk - (uclk - 2) / 3  - 1;
//   else clock_index = uclk;
//   //clock_index = 100 + ((clk - 3) / 2);
//  }


//  else
////   if //(mch.first == 0) //
////   (  ((clk % 2) == 0)   //((clk % 2 == 0) && ((clk - 4) % 6))

////    ||  ((clk - 1) % 6) == 0
////   )
//    // 6,8, 12,14, 18,20  24,2
//  {
//   u1 uclk;
//   s1 sclk;
//   switch (size_even_odd_code)
//   {
//   case 0:
//    uclk = clk % 6? clk + 1 : clk - 1;
//    sclk = (uclk / 3);
//    if(clk % 6)
//      --sclk;
//    clock_index = (u1) (sclk % 8);
//    break;
//   case 1:
//    if(clk % 2) // 1, 13
//      clock_index = (clk - 1) / 4;
//    else if(clk % 6) // 8, 20            // !% ?
//      clock_index = 3 + ((clk - 12) / 4);
//    else  // 6, 18
//      clock_index = ((clk + 2) / 4) - 1;
//    break;
//   case 2:
//    if(clk % 2) // 7, 19
//      clock_index = 1 + ((clk - 7) / 4);
//    else if(clk % 6) // 2, 14
//      clock_index = (clk - 2) / 4;
//    else // 12, 24
//      clock_index = 2 + ((clk - 12) / 4);
//    break;
//   case 3:
//      clock_index = (clk - 1) / 6;
//    break;
//   default:
//    break;

//   }
//  }

// //}

//   //static u1 index[4] {};
////   switch (size_even_odd_code)
////   {
////   case 0: clock_index = quadrant_code; break;
////   case 1: clock_index = 1 - quadrant_code % 2; break;
////   case 2: clock_index = 1 - quadrant_code % 2; break;
////   default: break;
////   }

// //red
// //u1 index[4][25] =

//}


