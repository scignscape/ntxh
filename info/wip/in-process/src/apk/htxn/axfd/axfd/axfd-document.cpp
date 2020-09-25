
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "axfd-document.h"

#include "axfd-tile-scope.h"

USING_KANS(AXFD)


AXFD_Document::AXFD_Document()
  :  stash_count_(2)
{
}

QPair<AXFD_Tile_Scope*, u4> AXFD_Document::add_tile_scope_from_text(QString text)
{
 QPair<QString*, u4> pr = stash_string(text);
 QPair<AXFD_Tile_Scope*, u4> result = stash_scope();
 result.first->push_back({pr.second, 2}); // 2 == string stash id
 return result;
 //AXFD_Tile_Scope* result = 
}

QString AXFD_Document::tile_scope_to_string(AXFD_Tile_Scope* ats)
{
 return ats->to_sieved_string(*this);
}

QString AXFD_Document::get_string_from_layer(
  const AXFD_Tile_Code& atc, void* layer)
{
 return {};
}

QString AXFD_Document::get_string_from_stash(u4 code, u2 stash_id)
{
 if(stash_id == 2)
   return *string_stash_.value(code - 1);
 return {};
}


QPair<QString*, u4> AXFD_Document::stash_string(QString text)
{
 QString* result = new QString(text);
 string_stash_.push_back(result);
 return {result, string_stash_.size() + 
   stash_count_ + 2}; // 2 == string stash id
}

QPair<AXFD_Tile_Scope*, u4> AXFD_Document::stash_scope()
{
 AXFD_Tile_Scope* result = new AXFD_Tile_Scope;
 scope_stash_.push_back(result);
 return {result, scope_stash_.size() + 
   stash_count_ + 3};  // 3 == scope stash id
}





