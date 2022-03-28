
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

u1 TierBox_Location::get_mch_clock_code(pr2s pr, u1 size_even_odd_code, u1* mask)
{
 if(pr.has_zero())
 {
//  qDebug() << "pr = " << pr;
 }

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

 static u1 cycle_ortho[4][4] =
  {
   {18, 6, 12, 0},
  // {12, 4, 8, 16},
  // //  6 -> 0  2 -> 6  4 -> 12  0 -> 18
   {18, 6, 12, 0},
   {18, 6, 12, 0},
  // //  6 -> 0  2 -> 6  4 -> 12  0 -> 18
   {18, 6, 12, 0}
 };

 if(pr.has_zero())
 {
  return cycle_ortho[size_even_odd_code][_mask/2];
 }

 // 3 -> 3  2 -> 9  0 -> 15  1 -> 21
 static u1 cycle_diag[4][4] =
  {
   {15, 21, 9, 3},
   //{10, 14, 6, 2},
   {15, 21, 9, 3},
   {15, 21, 9, 3},
   {15, 21, 9, 3},
 };




 if(abs.first == (abs.second * 2))
 {
  return cycle_diag[size_even_odd_code][_mask];
 }

 // //  7 -> 2  3 -> 4   2 -> 8   6 -> 10
  //    4 -> 14  0 -> 16  1 -> 20  5 -> 22
 static u1 cycle[4][8] = {
  {16, 20, 8, 4, 14, 22, 10, 2},
  //{11, 13, 5, 3, 9, 15, 7, 1},
  {16, 20, 8, 4, 14, 22, 10, 2},
  {16, 20, 8, 4, 14, 22, 10, 2},
  {16, 20, 8, 4, 14, 22, 10, 2},
 };

 return cycle[size_even_odd_code][_mask];
}

u1 TierBox_Location::get_mch_clock_code(u1 size_even_odd_code, u1* mask)
{
 return get_mch_clock_code(get_mch_code(), size_even_odd_code, mask);
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

 u1 orthogonal_quadrant = clk / 6;

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

prr2 TierBox_Location::get_mch_code_normalized(u1 size_even_odd_code, u1* mask)
{
 pr2s mch = get_mch_code();
 pr2 result = mch.abs().make_ascending();
 u1 clk = get_mch_clock_code(mch, size_even_odd_code, mask);
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

void XCSD_Image_Geometry::draw_tier_summary(QString path, r8 magnification, u1 circle_radius)
{
 static xy2s bl_text_pixel_offset {1, -6};
 static xy2s bl1_text_pixel_offset {1, -1};
 static xy2s tl_text_pixel_offset {1, 3};
 static xy2s br_text_pixel_offset {-5, -4};
 static xy2s tr_text_pixel_offset {-3, 4};

 wh2 summary_image_size = total_size_ * magnification;
 QImage image(summary_image_size.width, summary_image_size.height, QImage::Format_RGB16);
 image.fill(-1);

 u1 size_even_odd_code = get_size_even_odd_code();

 QPainter painter;
 painter.begin(&image);

 for_each_horizontal_gridline([&painter, &summary_image_size, magnification](Gridline& gl)
 {
  painter.drawLine(0, gl.ground_index * magnification,
    summary_image_size.width, gl.ground_index * magnification);
 });

 for_each_vertical_gridline([&painter, &summary_image_size, magnification](Gridline& gl)
 {
  painter.drawLine(gl.ground_index * magnification, 0,
    gl.ground_index * magnification, summary_image_size.height);
 });

 for_each_full_tierbox([this, &painter, magnification,
   circle_radius, size_even_odd_code](Grid_TierBox& gtb)
 {
  xy2s extra_trtext_pixel_offset {0, 0};
  xy2s extra_brtext_pixel_offset {0, 0};

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
  prr2 mch = gtb.loc.get_mch_code_normalized(size_even_odd_code, &mask);

  if(mch.first == 0)
  {
   if(mch.second == 0)
     painter.setBrush(Qt::yellow);
   else
   {
    painter.setBrush(Qt::red);
    TierBox_Location::reconcile_mch_quadrant(size_even_odd_code, quadrant_code, mch.third);

   }
  }
  else if(mch.second == mch.first * 2)
    painter.setBrush(Qt::cyan);

  painter.drawEllipse(QPoint(xyc.x, xyc.y), circle_radius, circle_radius);

  painter.setBrush(Qt::NoBrush);

  pr2s raw_mch = gtb.loc.get_mch_code();

  QString tl_text = QString("%1,%2")
    .arg(gtb.loc.r()).arg(gtb.loc.c())
    ;

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

  QString br_text = QString::number(mch.third)
    ;

  if(is_notation_center)
  {
   extra_trtext_pixel_offset.x = -9;
   extra_brtext_pixel_offset.x = -3;

   bl_text.prepend("mch=");
   bl1_text.prepend("raw= ");

   tr_text.prepend("mask=");
   br_text.prepend("clk ");
  }
  else if(br_text.length() == 1)
    extra_brtext_pixel_offset.x = 1;
   // br_text.prepend('0');

  xy2 bl_xy = gtb.bottom_left()._to<xy2s>().plus(bl_text_pixel_offset)._to<xy2>() * magnification;
  xy2 bl1_xy = gtb.bottom_left()._to<xy2s>().plus(bl1_text_pixel_offset)._to<xy2>() * magnification;
  xy2 tl_xy = gtb.top_left()._to<xy2s>().plus(tl_text_pixel_offset)._to<xy2>() * magnification;
  xy2 br_xy = gtb.bottom_right()._to<xy2s>().plus(br_text_pixel_offset)
    .plus(extra_brtext_pixel_offset)._to<xy2>() * magnification;
  xy2 tr_xy = gtb.top_right()._to<xy2s>().plus(tr_text_pixel_offset)
    .plus(extra_trtext_pixel_offset)._to<xy2>() * magnification;

  painter.drawText(bl1_xy.x, bl1_xy.y, bl1_text);
  painter.drawText(bl_xy.x, bl_xy.y, bl_text);
  painter.drawText(tl_xy.x, tl_xy.y, tl_text);

  painter.drawText(br_xy.x, br_xy.y, br_text);
  painter.drawText(tr_xy.x, tr_xy.y, tr_text);

  //qDebug() << "xy = " << xy << " str = " << str;
  });

 painter.end();

 image.save(path);
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
