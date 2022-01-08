
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_APPLICATION_STATE__H
#define DHAX_APPLICATION_STATE__H


#include "accessors.h"

#include "global-types.h"

#include <QString>
#include <QMap>
#include <QDir>

class DHAX_Application_State
{
public:

 struct Image_Margins
 {
  u1 top, bottom, left, right;
   struct Border {
     u1 top, bottom, left, right;
   };
   struct Percent {
     s1 top, bottom, left, right;
   };

  Border border;
  Percent percent;

  bool via_percent() { return percent.top >= 0; }

  Image_Margins ()
    :  top(0), bottom(0), left(0), right(0),
       border({0,0,0,0}),
       percent({-1,0,0,0}) {}
 };

private:

 Image_Margins image_margins_;


public:

 DHAX_Application_State();

 ACCESSORS__RGET(Image_Margins ,image_margins)
};


#endif //  DHAX_APPLICATION_STATE__H


