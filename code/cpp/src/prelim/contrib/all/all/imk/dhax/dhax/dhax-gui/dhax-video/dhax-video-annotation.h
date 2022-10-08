
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_VIDEO_ANNOTATION__H
#define DHAX_VIDEO_ANNOTATION__H

#include <QtWidgets>

#include <QVideoFrame>
#include <QVideoSurfaceFormat>
#include <QAbstractVideoSurface>

#include "global-types.h"
#include "accessors.h"


class DHAX_Video_Annotation
{

 u4 starting_frame_number_;
 u4 ending_frame_number_;

 QString text_;
 QString inner_style_sheet_;;

public:

 DHAX_Video_Annotation();

 ACCESSORS(u4 ,starting_frame_number)
 ACCESSORS(u4 ,ending_frame_number)

 ACCESSORS(QString ,text)
 ACCESSORS(QString ,inner_style_sheet)

};

#endif //DHAX_VIDEO_ANNOTATION__H
