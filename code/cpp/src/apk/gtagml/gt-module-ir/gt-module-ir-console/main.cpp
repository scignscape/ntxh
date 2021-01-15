
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gt-module-ir/gt-module-ir.h"


#include <QDebug>

#include "textio.h"

USING_KANS(TextIO)

USING_KANS(DGH)


int main(int argc, char *argv[])
{
 GT_Module_IR mir;

 mir.read_lines(QString(R"(
  .; the folder is just outside the archive
     but it is copied in @/dev/documents/ctg ...
   ;.

  gt-compile-manuscript  $  :no-first  :info-path
    :setup-once  :setup-sdi
      %1/ctg/src/ctg.tex
    :manuscript  %1/ctg/manuscript
    :gt-copy-folder  %1/ctg/gt-copy
   ;.
   )").arg(DEMO_DOCUMENT_FOLDER) );

 mir.run_lines();
 return 0;
}


