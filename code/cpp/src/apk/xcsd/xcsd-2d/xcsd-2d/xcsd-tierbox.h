
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_TIERBOX__H
#define XCSD_TIERBOX__H


#include "xcsd-1d/_vec1d.h"

#include "xcsd-1d/vec1d.h"
#include "xcsd-1d/arr1d.h"

#include "xcsd-sdi-structures.h"

#include <QImage>

#include "accessors.h"

XCNS_(XCSD)

//class XCSD_XPixel;


struct Box3x3_8bytepx
{
 Arr1d<n8> pixels;
 Box3x3_8bytepx();
};

struct Box9x9_8bytepx
{
 Vec1d<Box3x3_8bytepx> vec_3x3;
 Box9x9_8bytepx();
};

class XCSD_TierBox
{
// u2 pixel_bytelength_;

 u2 non_full_;
 Vec1d<Box9x9_8bytepx> box9x9_;


 rc2 position_;

public:

 XCSD_TierBox(rc2 position);

 ACCESSORS__DECLARE(u2 ,non_full_h)
 ACCESSORS__DECLARE(u2 ,non_full_v)

 ACCESSORS__DECLARE(bool ,non_full_up)
 ACCESSORS__DECLARE(bool ,non_full_left)

 void set_non_full_up() { set_non_full_up(true); }
 void set_non_full_left() { set_non_full_left(true); }

 void init_boxes();

};


_XCNS(XCSD)

#endif // XCSD_IMAGE__H
