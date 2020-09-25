
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "axfd-tile-scope.h"

#include "axfd-document.h"


USING_KANS(AXFD)

AXFD_Tile_Scope::AXFD_Tile_Scope()
 //:  Flags(0), enter(e), leave(l), node_ref(nullptr), order(0)
{

}

QString AXFD_Tile_Scope::to_sieved_string(AXFD_Document& doc, 
  void* layer)
{
 for(const AXFD_Tile_Code& atc : *this)
 {
  if(atc.leave < (atc.enter - 1) )
    return doc.get_string_from_stash(
      atc.enter - atc.leave - doc.stash_count(), atc.leave);  
  else if(layer)
    return doc.get_string_from_layer(atc, layer);
  else
    return {}; 
 } 
}
