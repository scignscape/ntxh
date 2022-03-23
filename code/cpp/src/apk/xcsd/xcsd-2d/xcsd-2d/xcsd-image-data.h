
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_IMAGE_DATA__H
#define XCSD_IMAGE_DATA__H

#include "xcns.h"

#include "xcsd-1d/_vec1d.h"

#include "xcsd-1d/vec1d.h"


XCNS_(XCSD)

class XCSD_TierBox;

class XCSD_Image_Data
{
 Vec1d<XCSD_TierBox*>* tierboxes_;

public:

 XCSD_Image_Data();


};


_XCNS(XCSD)

#endif // XCSD_IMAGE_DATA__H

