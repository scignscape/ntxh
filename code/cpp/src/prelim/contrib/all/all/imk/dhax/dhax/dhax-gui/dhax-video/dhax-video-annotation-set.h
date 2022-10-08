
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_VIDEO_ANNOTATION_SET__H
#define DHAX_VIDEO_ANNOTATION_SET__H


#include <QMap>

#include <QVideoFrame>
#include <QVideoSurfaceFormat>
#include <QAbstractVideoSurface>

#include "global-types.h"
#include "accessors.h"

#include "dhax-video-annotation.h"


class DHAX_Video_Annotation_Set : public QMap<u4, DHAX_Video_Annotation>
{
public:

 DHAX_Video_Annotation_Set();

 DHAX_Video_Annotation* get_annotation_by_start_frame(u4 key);

};

#endif //DHAX_VIDEO_ANNOTATION_SET__H
