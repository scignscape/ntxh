
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef AXFD_DOCUMENT__H
#define AXFD_DOCUMENT__H

#include "accessors.h"

#include "global-types.h"

#include "flags.h"

#include "kans.h"

#include <QString>
#include <QVector>
#include <QPair>

#include <functional>

#include "global-types.h"
#include "accessors.h"

#include "axfd-string-node.h"


KANS_(AXFD)

class AXFD_Tile_Scope;
struct AXFD_Tile_Code;

class AXFD_Document
{ 
 QString input_file_path_;
 QString input_folder_;
 QString output_folder_;

 u2 stash_count_;
  
public:

 AXFD_Document();

 ACCESSORS(QString ,input_file_path)
 ACCESSORS(QString ,input_folder)
 ACCESSORS(QString ,output_folder)

 ACCESSORS(u2 ,stash_count)

 QVector<QString*> string_stash_;
 QVector<AXFD_Tile_Scope*> scope_stash_;

 QPair<QString*, u4> stash_string(QString text);
 QPair<AXFD_Tile_Scope*, u4> stash_scope();

 QPair<AXFD_Tile_Scope*, u4> add_tile_scope_from_text(QString text);

 QString get_string_from_layer(const AXFD_Tile_Code& atc, 
   void* layer);
 
 QString get_string_from_stash(u4 code, u2 stash_id);

 QString tile_scope_to_string(AXFD_Tile_Scope* ats);

};


_KANS(AXFD)

#endif // AXFD_DOCUMENT__H


