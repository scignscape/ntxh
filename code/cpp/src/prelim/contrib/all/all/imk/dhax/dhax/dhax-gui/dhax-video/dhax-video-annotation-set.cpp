

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-video-annotation-set.h"

#include <QtWidgets>
#include <qabstractvideosurface.h>
#include <qvideosurfaceformat.h>



DHAX_Video_Annotation_Set::DHAX_Video_Annotation_Set()
{

}


DHAX_Video_Annotation* DHAX_Video_Annotation_Set::get_annotation_by_start_frame(u4 key)
{
 auto it = find(key);
 if(it == end())
   return nullptr;
 return &it.value();
}
