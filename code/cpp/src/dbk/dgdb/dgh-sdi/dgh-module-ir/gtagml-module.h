
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef GTAGML_MODULE__H
#define GTAGML_MODULE__H

#include <QString>
#include <QMap>
#include <QMultiMap>
#include <QStack>

#include <functional>

#include "accessors.h"

#include "kans.h"


//?#define MACRO_PASTE(...) __VA_ARGS__

KANS_(DGH)

class GTagML_Module
{

 public:

  GTagML_Module();

  void compile_gt_file(QString args);
  void compile_gt_folder(QString args);
  void compile_gt_manuscript(QString args);


};

_KANS(Phaon)

#endif // PHAON_IR__H
