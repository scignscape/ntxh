
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef GTAGML_PROJECT_INFO__H
#define GTAGML_PROJECT_INFO__H

#include "relae-graph/relae-node-ptr.h"

#include "accessors.h"

#include "flags.h"

#include "kans.h"

#include <QStringList>

KANS_(GTagML)

class GTagML_Parser;

class GTagML_Project_Info
{
public:

 flags_(1)
  bool manuscript_top_level_is_gt:1;
 _flags

private:

 QString root_folder_;
 QString sdi_template_file_;
 QString sdi_template_target_;

 QString gtagml_setup_;
 void* user_data_;


public:

 GTagML_Project_Info(QString root_folder);

 ACCESSORS(QString ,gtagml_setup)
 ACCESSORS(void* ,user_data)

};

_KANS(GTagML)


#endif
