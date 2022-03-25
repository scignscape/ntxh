
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_IMAGE_GEOMETRY__H
#define XCSD_IMAGE_GEOMETRY__H

#include "xcns.h"

#include "xcsd-sdi-structures.h"

#include "enum-macros.h"


XCNS_(XCSD)

class TierBox_Location
{
 rc2s rc_;
 u1 tier_ring_;

public:

 explicit TierBox_Location(rc2s rc) : rc_(rc), tier_ring_(0) {}

 ACCESSORS(u1 ,tier_ring)
 ACCESSORS(rc2s ,rc)

 s2 r() { return rc_.r; }
 s2 c() { return rc_.c; }

 bool is_full_tier()
 {
  return rc_.is_nonnegative();
 }

};


class XCSD_Image_Geometry
{
public:

 enum class HVD_Options {  Horizontal, Vertical, Diagonal,
   Horizontal_Positive, Horizontal_Negative,
   Vertical_Positive, Vertical_Negative,
   Diagonal_0, Diagonal_1, Diagonal_2, Diagonal_3
          };

 enum class TierGrid_Preferances {
   N_A = 0,
   Even_H = 1,
   Even_V = 16,
   Even = 17,
   Odd_H = 2,
   Odd_V = 32,
   Odd = 34,
   Maximize_Outer_Tiers_H = 4,
   Maximize_Outer_Tiers_V = 64,
   Maximize_Outer_Tiers = 68,
   Minimize_Outer_Tiers_H = 8,
   Minimize_Outer_Tiers_V = 128,
   Minimize_Outer_Tiers = 136
 };

 ENUM_FLAGS_OP_MACROS(TierGrid_Preferances)

 struct Gridline {
  HVD_Options hvd;
  u2 tier_index;
  u2 ground_index;
 };

 struct Grid_TierBox {
   TierBox_Location loc;
   xy2 ground_center;
 };

private:

 wh2 total_size_;

 wh2 overall_tier_counts_;
 wh2 full_tier_counts_;

 lr2 horizontal_outer_sizes_;
 tb2 vertical_outer_sizes_;

 u4 tierbox_count_;

 TierGrid_Preferances actual_tiergrid_setting_;

 void reconcile_overall_tier_counts();

public:

 XCSD_Image_Geometry();

 ACCESSORS(wh2 ,total_size)
 ACCESSORS(wh2 ,overall_tier_counts)
 ACCESSORS(wh2 ,full_tier_counts)
 ACCESSORS(lr2 ,horizontal_outer_sizes)
 ACCESSORS(tb2 ,vertical_outer_sizes)

 static constexpr u1 tierbox_width = 27;

 void for_each_horizontal_gridline(std::function<void(Gridline&)> fn);
 void for_each_vertical_gridline(std::function<void(Gridline&)> fn);
 void for_each_full_tierbox(std::function<void(Grid_TierBox&)> fn);

 TierBox_Location get_tierbox_location_from_ground_position(u2 x, u2 y);

 void calculate_tier_ring(TierBox_Location& tbl);
 void _calculate_tier_ring_Full(TierBox_Location& tbl);

 void set_total_size(u2 w, u2 h)
 {
  set_total_size({w, h});
 }

 static lmr2 split_lmr(u2 size, u1 box_width, TierGrid_Preferances pref);

 static tmb2 split_tmb(u2 size, u1 box_width, TierGrid_Preferances pref)
 {
  return split_lmr(size, box_width, pref)._to<tmb2>();
 }

 void init_tier_counts(TierGrid_Preferances pref);
 void init_tierboxes();

 void draw_tier_summary(QString path);


};


_XCNS(XCSD)

#endif // XCSD_IMAGE_GEOMETRY__H

