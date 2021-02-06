
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

// mir.read_lines(QString(R"(
//   .; the folder is just outside the archive
//      but it is copied in @/dev/documents/ctg ...
//    ;.

//  gt-compile-file  $  %1/test/src/t1.gt
//    ;.
//    )").arg(DEMO_DOCUMENT_FOLDER) );


//
 QString paper_name = "itm";
// QString paper_name = "ctg";
// QString paper_name = "icg";


 mir.read_lines(QString(R"(
  .; the folder is just outside the archive
     but it is copied in @/dev/documents/" + paper_name ...
   ;.

  gt-compile-manuscript  $  :no-first  :info-path
    :setup-once  :setup-sdi
      %1/%2/src/%2.tex
    :manuscript  %1/%2/manuscript
    :gt-copy-folder  %1/%2/gt-copy
   ;.
   )").arg(DEMO_DOCUMENT_FOLDER).arg(paper_name) );


// mir.read_lines(QString(R"(
//  .; the folder is just outside the archive
//     but it is copied in @/dev/documents/ctg ...
//   ;.

//  gt-compile-manuscript  $  :no-first  :info-path
//    :setup-once  :setup-sdi
//      %1/icg/src/icg.tex
//    :manuscript  %1/icg/manuscript
//    :gt-copy-folder  %1/icg/gt-copy
//   ;.
//   )").arg(DEMO_DOCUMENT_FOLDER) );


 mir.run_lines();
 return 0;
}


