

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-video-annotation.h"

#include <QtWidgets>
#include <qabstractvideosurface.h>
#include <qvideosurfaceformat.h>



DHAX_Video_Annotation::DHAX_Video_Annotation()
  :  ref_time_offset_(0), ref_annotation_(nullptr), scene_data_(nullptr),
     starting_frame_number_(-1), ending_frame_number_(-1),
     scene_type_data_(nullptr), pause_time_(0)
{

}

void DHAX_Video_Annotation::finalize_html_text()
{
 static QString html = "<div style=\"%1\">%2</div>";

 html_text_ = html.arg(inner_style_sheet_)
   .arg(text_);
}


