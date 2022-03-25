
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "xcsd-image-geometry.h"

#include "xcsd-tierbox.h"

#include <QPainter>

USING_XCNS(XCSD)

XCSD_Image_Geometry::XCSD_Image_Geometry()
  :  total_size_({0,0}),
     overall_tier_counts_({0,0}),
     full_tier_counts_({0,0}),
     horizontal_outer_sizes_({0,0}),
     vertical_outer_sizes_({0,0}),
     tierbox_count_(0)
{

}

void XCSD_Image_Geometry::_calculate_tier_ring_Full(TierBox_Location& tbl)
{
 u2 distance_from_edge = std::max({(u2) tbl.r(),
   (u2) tbl.c(), (u2) (full_tier_counts_.height - tbl.r() - 1),
   (u2) (full_tier_counts_.width - tbl.c() - 1)});

 u1 tier_ring = 0;

 if(distance_from_edge == tbl.c())
   tier_ring = (full_tier_counts_.width / 2) - distance_from_edge;
 else if(distance_from_edge == tbl.r())
   tier_ring = (full_tier_counts_.height / 2) - distance_from_edge;
 else if(distance_from_edge == full_tier_counts_.height - tbl.r() - 1)
   tier_ring = distance_from_edge - (full_tier_counts_.width / 2);
 else
   tier_ring = distance_from_edge - (full_tier_counts_.height / 2);

 tbl.set_tier_ring(tier_ring);
}


void XCSD_Image_Geometry::calculate_tier_ring(TierBox_Location& tbl)
{
 if(tbl.is_full_tier())
   _calculate_tier_ring_Full(tbl);
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

void XCSD_Image_Geometry::for_each_horizontal_gridline(std::function<void(Gridline&)> fn)
{
 u1 offset = horizontal_outer_sizes_.left;
 for(u2 i = 0; i <= full_tier_counts_.width; ++i)
 {
  Gridline gl {HVD_Options::Horizontal, i, (u2)(i * tierbox_width + offset)};
  fn(gl);
 }
}

void XCSD_Image_Geometry::for_each_vertical_gridline(std::function<void(Gridline&)> fn)
{
 u1 offset = vertical_outer_sizes_.top;
 for(u2 i = 0; i <= full_tier_counts_.height; ++i)
 {
  Gridline gl {HVD_Options::Vertical, i, (u2)(i * tierbox_width + offset)};
  fn(gl);
 }
}

void XCSD_Image_Geometry::for_each_full_tierbox(std::function<void(Grid_TierBox&)> fn)
{
// u1 offset = vertical_outer_sizes_.top;
 tl2 tl{vertical_outer_sizes_.top, horizontal_outer_sizes_.left};
// u4 area = full_tier_counts_.area();

 tl2 offsets = tl || 1;
 for(u2 r = 0; r <= full_tier_counts_.height; ++r)
 {
  for(u2 c = 0; c <= full_tier_counts_.width; ++c)
  {
   rc2 rc{r, c};
   rc.add(offsets);
   TierBox_Location tbl(rc._to<rc2s>());
   calculate_tier_ring(tbl);
   Grid_TierBox gtb({tbl, ((rc * tierbox_width).plus(tl))._transposed_to<xy2>()});
   fn(gtb);
  }
 }
}


void XCSD_Image_Geometry::draw_tier_summary(QString path)
{
 u1 mag = 4;
 wh2 summary_image_size = total_size_ * mag;
 QImage image(summary_image_size.width, summary_image_size.height, QImage::Format_Mono);
 image.fill(1);

 QPainter painter;
 painter.begin(&image);

 for_each_horizontal_gridline([&painter, &summary_image_size, mag](Gridline& gl)
 {
  painter.drawLine(0, gl.ground_index * mag,
    summary_image_size.width, gl.ground_index * mag);
 });

 for_each_vertical_gridline([&painter, &summary_image_size, mag](Gridline& gl)
 {
  painter.drawLine(gl.ground_index * mag, 0,
    gl.ground_index * mag, summary_image_size.height);
 });

 for_each_full_tierbox([&painter, mag](Grid_TierBox& gtb)
 {
  xy2 xy = gtb.ground_center * mag;
  QString str = QString("%1,%2")//:%3")
    .arg(gtb.loc.r()).arg(gtb.loc.c())
    //.arg((s1)gtb.loc.tier_ring())
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

