
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

#include <QSet>

#include <functional>

#include "accessors.h"

#include "kans.h"

KANS_CLASS_DECLARE(GTagML ,GTagML_Folder)

USING_KANS(GTagML)
//?#define MACRO_PASTE(...) __VA_ARGS__

KANS_(DGH)

class GTagML_Module
{
 QString gtagml_setup_;

 void process_gtagml_file(QString path, QSet<QString> flagset, GTagML_Folder* fld);

public:

 GTagML_Module();

 void compile_gt_file(QString args);
 void compile_gt_folder(QString args);
 void compile_gt_manuscript(QString args);
 void compile_gt_manuscript_file(QString args);


};

_KANS(Phaon)

#endif // PHAON_IR__H
