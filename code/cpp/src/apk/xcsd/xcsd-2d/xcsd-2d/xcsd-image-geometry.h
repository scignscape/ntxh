
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_IMAGE_GEOMETRY__H
#define XCSD_IMAGE_GEOMETRY__H

#include "xcns.h"

#include "xcsd-sdi-structures.h"


XCNS_(XCSD)

class XCSD_Image_Geometry
{
 wh2 total_size_;

 wh2 tier_counts_;
 lr2 horizontal_outer_sizes_;
 tb2 vertical_outer_sizes_;

 u4 tierbox_count_;

public:

 XCSD_Image_Geometry();

 ACCESSORS(wh2 ,total_size)
 ACCESSORS(wh2 ,tier_counts)
 ACCESSORS(lr2 ,horizontal_outer_sizes)
 ACCESSORS(tb2 ,vertical_outer_sizes)

 static constexpr u1 tierbox_width = 27;


 void init_tier_counts();
 void init_tierboxes();

};


_XCNS(XCSD)

#endif // XCSD_IMAGE_GEOMETRY__H

