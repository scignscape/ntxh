
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "xcsd-image-geometry.h"

#include "xcsd-tierbox.h"

#include <QPainter>

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
 rc2s raw = rhs.rc_.minus(rc_);
 pr2s raw_sp = rhs.rc_.spaceship_mask()._to<pr2s>();
 rc2 raw_abs = raw.abs();
 pr2 chebychev = raw_abs.lesser_which()._to<pr2>();
 u2 manhattan = raw_abs.inner_sum();
 pr2s result = {(s2)manhattan, (s2)(manhattan - chebychev.first)};
 result.multiply(raw_sp);
 if(chebychev.second == 1)
   result.transpose();
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
 rc2s first = (full_tier_counts_/2).transposed()._to<rc2s>();
 std::deque<rc2s> deq {{first}};
 //directed_centers_.push_back(TierBox_Location(first));
 switch (actual_tiergrid_setting_)
 {
 case TierGrid_Preferances::Odd_H_Odd_V:
   // // simplest case because there's only one center
   break;
 case TierGrid_Preferances::Even_H_Odd_V:
   // // also the one to the left
   deq.push_front(first.subtract({0, 1}));
   break;

 case TierGrid_Preferances::Odd_H_Even_V:
   // // also the one to the left
   deq.push_front(first.subtract({1, 0}));
   break;

 case TierGrid_Preferances::Even_H_Even_V:
   // // also the one to the left
   deq.push_front(first.subtract({1, 1}));
   deq.push_front(first.subtract({0, 1}));
   deq.push_front(first.subtract({1, 0}));
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
}

pr2s TierBox_Location::get_mch_code()
{
 return {(s2)(mch_code_ >> 16), (s2)(mch_code_ & ~(u2)0)};
}


void XCSD_Image_Geometry::draw_tier_summary(QString path, u1 magnification)
{
 static xy2s text_pixel_offset {2, -1};
 static u1 circle_radius = 2;

 wh2 summary_image_size = total_size_ * magnification;
 QImage image(summary_image_size.width, summary_image_size.height, QImage::Format_Mono);
 image.fill(1);

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

 for_each_full_tierbox([&painter, magnification](Grid_TierBox& gtb)
 {
  xy2 xyc = gtb.ground_center * magnification;
  painter.drawEllipse(QPoint(xyc.x, xyc.y), circle_radius, circle_radius);

  pr2s mch_code = gtb.loc.get_mch_code();

  xy2 xy = gtb.bottom_left()._to<xy2s>().plus(text_pixel_offset)._to<xy2>() * magnification;
  QString str = QString("%1,%2:%3-%4")
    .arg(gtb.loc.r()).arg(gtb.loc.c())
    .arg(mch_code.first).arg(mch_code.second)
    ;
  painter.drawText(xy.x, xy.y, str);
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

 horizontal_outer_sizes_ = lmr.fold_in();
 vertical_outer_sizes_ = tmb.fold_in();

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

