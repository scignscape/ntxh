
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "hQVariant.h"

#include "mpf-package-hgdm.h"

#include <QDebug>


hQVariant::hQVariant(QVariant qv)
  :  ref_count_(0), qv_(new QVariant(qv))
{
}

void hQVariant::add_ref()
{
 // Increase the reference counter
 ++ref_count_;
}
 
void hQVariant::release()
{
 // Decrease ref count and delete if it reaches 0
 if( --ref_count_ == 0 )
 {
  delete qv_;
  delete this;
 }
}


