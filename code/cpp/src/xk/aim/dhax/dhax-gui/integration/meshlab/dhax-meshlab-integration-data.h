
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_MESHLAB_INTEGRATION_DATA__H
#define DHAX_MESHLAB_INTEGRATION_DATA__H

#include "global-types.h"

#include <QQuaternion>

class DHAX_Meshlab_Integration_Data
{
 QQuaternion meshlab_track_info_;
 r4 meshlab_scale_info_;
 QVector3D meshlab_center_position_;
 QString meshlab_file_path_;
 u4* meshlab_import_count_;


public:

 DHAX_Meshlab_Integration_Data();

};


#endif //  DHAX_MESHLAB_INTEGRATION_DATA__H


