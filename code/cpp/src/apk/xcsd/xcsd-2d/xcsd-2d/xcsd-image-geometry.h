
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_IMAGE_GEOMETRY__H
#define XCSD_IMAGE_GEOMETRY__H

#include "xcns.h"

#include "xcsd-sdi-structures.h"

#include "enum-macros.h"

#include <vector>


XCNS_(XCSD)

class TierBox_Location
{
 rc2s rc_;
 //u1 tier_ring_;
 u4 mch_code_;

public:

 explicit TierBox_Location(rc2s rc) : rc_(rc), mch_code_(0) {}

 ACCESSORS(u4 ,mch_code)
 ACCESSORS(rc2s ,rc)

 void set_mch_code(pr2s mch);
 pr2s get_mch_code() const;
 prr2 get_mch_code_normalized(//u1 size_even_odd_code,
                              u1* mask = nullptr) const;

 u1 get_mch_clock_code(u1* mask = nullptr);
 static u1 get_mch_clock_code(pr2s pr, u1* mask = nullptr);

 static void reconcile_mch_quadrant(u1 size_even_odd_code, u1 quadrant_code, u2& clk);
// static u1 get_orthogonal_quadrant_from_mch_code(u1 size_even_odd_code, u1 quadrant_code, prr2 mch_code);


 pr2s mch_distance_from(const TierBox_Location& rhs);

 s2 r() const { return rc_.r; }
 s2 c() const { return rc_.c; }

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
   Minimize_Outer_Tiers = 136,

   Even_H_Even_V = Even_H | Even_V,
   Even_H_Odd_V = Even_H | Odd_V,
   Odd_H_Even_V = Odd_H | Even_V,
   Odd_H_Odd_V = Odd_V | Odd_H,
 };

 ENUM_FLAGS_OP_MACROS(TierGrid_Preferances)

 struct Size_Even_Odd_Info {
  u1 size_even_odd_code;
  u1 v_center_adjustment;
  u1 h_center_adjustment;
  u1 full_ortho_cycle_size;
  u1 margin_ortho_cycle_size;

  void landscape();
  void portrait();

  Size_Even_Odd_Info(u1 code)
  {
   size_even_odd_code = code;
   v_center_adjustment = 1 - (size_even_odd_code % 2); // 1 extra center row
   h_center_adjustment = 1 - ((size_even_odd_code >> 1) % 2); // 1 extra center column

   full_ortho_cycle_size = 4 + 2 * v_center_adjustment + 2 * h_center_adjustment;
   margin_ortho_cycle_size = 0;
  }
 };

 struct MCH_Info {
   u2 tier_ring;
   u2 inner_pushout;
   u1 compressed_clock_index;
   u1 full_clock_index;
   u1 clock_index_adjustment;
   u4 area_threshold;
   u4 area_threshold_adjustment;
   u4 full_tier_index;
   u1 margin_code;
   u2 margin_gap;
   u2 intra_tier_ring_index;

   MCH_Info(const prr2& mch, const prr2& margin_info, u2 lesser_side,
     Size_Even_Odd_Info& size_even_odd_info, u1 quadrant_code);

   static u1 get_compressed_clock_index(u1 clk, u1 size_even_odd_code, u1 quadrant_code);
 };

 struct Gridline {
   HVD_Options hvd;
   u2 tier_index;
   u2 ground_index;
 };

 struct Grid_TierBox {
   TierBox_Location loc;
   xy2 ground_center;
   xy2 top_left();
   xy2 top_right();
   xy2 bottom_left();
   xy2 bottom_right();
 };

 struct Iteration_Environment {
   Size_Even_Odd_Info size_even_odd_info;

   Iteration_Environment(u1 size_even_odd_code);
 };

private:

 wh2 total_size_;

 wh2 overall_tier_counts_;
 wh2 full_tier_counts_;

 lr2 horizontal_outer_sizes_;
 tb2 vertical_outer_sizes_;

 u4 tierbox_count_;

 TierGrid_Preferances actual_tiergrid_setting_;

 std::vector<TierBox_Location> directed_centers_;

 void reconcile_overall_tier_counts();
 void reconcile_actual_tiergrid_setting();
 void init_directed_centers();

public:

 XCSD_Image_Geometry();

 ACCESSORS(wh2 ,total_size)
 ACCESSORS(wh2 ,overall_tier_counts)
 ACCESSORS(wh2 ,full_tier_counts)
 ACCESSORS(lr2 ,horizontal_outer_sizes)
 ACCESSORS(tb2 ,vertical_outer_sizes)

 Iteration_Environment formulate_iteration_environment();

 std::vector<TierBox_Location> get_directed_centers();

 static constexpr u1 tierbox_width = 27;

 u1 get_size_even_odd_code();

 prr2 get_margin_info(const TierBox_Location& loc, u1 quadrant_code);

 void for_each_horizontal_gridline(std::function<void(Gridline&)> fn);
 void for_each_vertical_gridline(std::function<void(Gridline&)> fn);
 void for_each_full_tierbox(std::function<void(Grid_TierBox&)> fn);

 TierBox_Location get_tierbox_location_from_ground_position(u2 x, u2 y);

 TierBox_Location get_directed_center(TierBox_Location& tbl);

 void calculate_mch_code(TierBox_Location& tbl);
 void _calculate_mch_code_Full(TierBox_Location& tbl);

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

 void draw_tier_summary(QString path, QString path1,
   r8 magnification, u1 circle_radius);

 u4 get_tierbox_index(const Grid_TierBox& gtb, Size_Even_Odd_Info size_even_odd_info);
};


_XCNS(XCSD)

#endif // XCSD_IMAGE_GEOMETRY__H

