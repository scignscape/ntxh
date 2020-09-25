
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-frame.h"

USING_KANS(DGDB)

DgDb_Frame::DgDb_Frame(DgDb_Frame* parent_frame)
  :  parent_frame_(parent_frame)
{

}


