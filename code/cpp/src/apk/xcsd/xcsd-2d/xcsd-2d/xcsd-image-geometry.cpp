
#include "xcsd-image-geometry.h"

#include "xcsd-tierbox.h"

USING_XCNS(XCSD)

XCSD_Image_Geometry::XCSD_Image_Geometry()
  :  total_size_({0,0}), tier_counts_({0,0}),
     horizontal_outer_sizes_({0,0}),
     vertical_outer_sizes_({0,0}),
     tierbox_count_(0)
{

}

