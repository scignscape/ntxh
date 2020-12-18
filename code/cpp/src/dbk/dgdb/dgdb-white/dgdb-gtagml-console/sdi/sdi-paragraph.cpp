
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "sdi-paragraph.h"


#include <QDebug>



USING_KANS(GHL)


SDI_Paragraph::SDI_Paragraph(u4 id, u4 start, u4 end)
  :  id_(id), start_(0), end_(0), 
     first_sentence_(nullptr), last_sentence_(nullptr)
{

}

