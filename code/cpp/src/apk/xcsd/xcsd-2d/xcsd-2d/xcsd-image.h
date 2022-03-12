
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_IMAGE__H
#define XCSD_IMAGE__H


#include "xcsd-1d/_vec1d.h"

#include <QImage>

#include "accessors.h"

XCNS_(XCSD)

// template<typename VAL_Type, typename = index_types<s2>,
//typename = _pr_break> class

class XCSD_Image
{
 QImage image_;

public:

 XCSD_Image();

 ACCESSORS__RGET(QImage ,image)

 void load_image(QString path);

  //(255);

 void get_255_palatte(QVector<QColor>& vec);




};


_XCNS(XCSD)

#endif // XCSD_IMAGE__H
