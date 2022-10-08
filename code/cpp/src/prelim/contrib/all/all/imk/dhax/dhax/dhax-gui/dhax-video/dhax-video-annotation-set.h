
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

#include "ntxh-parser/ntxh-document.h"

USING_KANS(HGDMCore)

class DHAX_Video_Annotation_Set : public QMap<u4, DHAX_Video_Annotation>
{
 typedef NTXH_Graph::hypernode_type hypernode_type;

 QMap<u4, QVector<void*>> end_frame_data_;

public:

 DHAX_Video_Annotation_Set();

 DHAX_Video_Annotation* get_annotation_by_start_frame(u4 key);

 void* get_data_by_end_frame(u4 key);
 void set_end_frame_data(u4 key, void* data);

 void load_sample_annotations();

 void load_annotation(DHAX_Video_Annotation& dva);
 void load_annotation_file(QString file_path);

 void read_ntxh_hypernode(NTXH_Graph& g, hypernode_type* h);


};

#endif //DHAX_VIDEO_ANNOTATION_SET__H
