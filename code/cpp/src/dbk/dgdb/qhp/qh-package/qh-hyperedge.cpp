
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qh-hyperedge.h"


Qh_Hyperedge::Qh_Hyperedge(QString description)
  :  source_(nullptr),
     target_(nullptr), annotation_(nullptr),
     description_(description), supplement_(0)
{

}

