
#include "xcsd-image-geometry.h"

#include "xcsd-tierbox.h"

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

