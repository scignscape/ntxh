
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-ssr-integration-data.h"

#include <QDebug>

DHAX_SSR_Integration_Data::DHAX_SSR_Integration_Data()
  :  ssr_import_count_(nullptr)
{

}

void DHAX_SSR_Integration_Data::init_import_count()
{
 if(ssr_import_count_)
 {
  qDebug() << "Re-initializing SSR import count!";
 }
 static u4 static_u4 = 0;
 ssr_import_count_ = &static_u4;
}
