
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgh-module-ir/module-ir.h"


#include <QDebug>

#include "textio.h"

USING_KANS(TextIO)

USING_KANS(DGH)


int main(int argc, char *argv[])
{
 Module_IR mir;

 mir.read_lines(R"(
.; comment ... ;.
gt-compile-file $ /home/nlevisrael/lgt/src/ideas.gt ;.
                )");

 mir.run_lines();
 return 0;
}


