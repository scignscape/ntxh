
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include "axfd/axfd-rnode.h"

#include "axfd/axfd-document.h"


USING_KANS(AXFD)


int main(int argc, char *argv[])
{
 AXFD_Document doc;
 doc.set_input_folder(DEFAULT_AXFD_FOLDER "/t1");
 doc.set_output_folder(DEFAULT_AXFD_FOLDER "/t1");

 AXFD_Tile_Scope* ats = doc.add_tile_scope_from_text("OK").first;
 
 qDebug() << doc.tile_scope_to_string(ats);

 return 0;
}


