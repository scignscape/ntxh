
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef LOCAL_HISTOGRAM_DATA__H
#define LOCAL_HISTOGRAM_DATA__H


#include "xcsd-1d/_vec1d.h"

#include "xcsd-1d/vec1d.h"
#include "xcsd-1d/arr1d.h"

#include "xcsd-sdi-structures.h"

#include <QImage>

#include "accessors.h"

XCNS_(XCSD)

//class XCSD_XPixel;



class Local_Histogram_Data
{

 QMap<u2, u2> rgb555_map_;
 QMap<u1, u2> hue_map_;

 QMap<u1, QVector<pr2>> combined_map_;

public:

 Local_Histogram_Data();

 ACCESSORS__RGET(MACRO_PASTE(QMap<u2, u2>) ,rgb555_map)
 ACCESSORS__RGET(MACRO_PASTE(QMap<u1, u2>) ,hue_map)
 ACCESSORS__RGET(MACRO_PASTE(QMap<u1, QVector<pr2>>) ,combined_map)

};


_XCNS(XCSD)

#endif // LOCAL_HISTOGRAM_DATA__H
