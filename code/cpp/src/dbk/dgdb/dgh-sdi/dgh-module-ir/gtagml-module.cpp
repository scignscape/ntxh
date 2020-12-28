
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gtagml-module.h"

#include <QDebug>

#include "textio.h"

USING_KANS(TextIO)

USING_KANS(DGH)


GTagML_Module::GTagML_Module()
{

}

void GTagML_Module::compile_gt_file(QString args)
{
 qDebug() << "args = " << args;
}

void GTagML_Module::compile_gt_folder(QString args)
{
 qDebug() << "args = " << args;
}

void GTagML_Module::compile_gt_manuscript(QString args)
{
 qDebug() << "args = " << args;
}

