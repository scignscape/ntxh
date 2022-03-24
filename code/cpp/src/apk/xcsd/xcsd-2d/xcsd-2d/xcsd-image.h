
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_IMAGE__H
#define XCSD_IMAGE__H


#include "xcsd-1d/_vec1d.h"

#include "xcsd-1d/vec1d.h"

#include <QImage>

#include "accessors.h"

#include "xcsd-sdi-structures.h"
#include "xcsd-image-data.h"
#include "xcsd-image-geometry.h"

XCNS_(XCSD)



class XCSD_Image
{
 QImage image_;

 XCSD_Image_Data data_;
 XCSD_Image_Geometry geometry_;


public:

 XCSD_Image();

 ACCESSORS__RGET(QImage ,image)


 XCSD_TierBox* get_tierbox_at_ground_position(u2 x, u2 y);

 rc2 get_tierbox_at_ground_position_RC2(u2 x, u2 y);

 SDI_Position get_sdi_at_ground_position(u2 x, u2 y);

 void load_image(QString path);

 static constexpr u1 tierbox_width = 27;

 //get_pixel_vector(SDI_Position )


 wh2 get_wh()
 {
  return {(u2)image_.width(), (u2)image_.height()};
 }

 void init_tier_counts(XCSD_Image_Geometry::TierGrid_Preferances pref);

 void init_tierboxes();

 void get_255_palatte(QVector<QColor>& vec);




};


_XCNS(XCSD)

#endif // XCSD_IMAGE__H
