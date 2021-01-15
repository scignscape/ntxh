
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "language-sample-group.h"

//#include "ngml-sdi/ngml-sdi-paragraph.h"


#include <QDebug>



USING_KANS(DSM)


//Language_Sample_Group::Language_Sample_Group()
//  :  in_database_id_(id), id_(0),
//     page_(0), order_in_page_(0)
//{

//}

//Language_Sample_Group::Language_Sample_Group() //NGML_SDI_Paragraph* ngml)
// :  in_database_id_(0), in_file_id_(0), file_id_(0),
//    page_(0), order_in_page_(0)//, ngml_(ngml)
//{

//}


Language_Sample_Group::Language_Sample_Group(u2 id)
  :  in_database_id_(0), id_(id),
     page_(0), order_in_page_(0), section_(0)
{

}


QString Language_Sample_Group::get_summary()
{
// if(ngml_)
//   return QString("%1 = %2:%3,%4-%5,%6; %7-%8").arg(file_id_)
//     .arg(ngml_->id())
//     .arg(ngml_->start_x())
//     .arg(ngml_->end_x())
//     .arg(ngml_->start_y())
//     .arg(ngml_->end_y())
//     .arg(ngml_->start_index())
//     .arg(ngml_->end_index())
//   ;
// return {};
}
