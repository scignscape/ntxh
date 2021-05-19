
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-dsmain-model.h"


#include "textio.h"
USING_KANS(TextIO)

#include <QString>
#include <QVariant>
#include <QByteArray>

#include <QUrl>

#include <QPoint>

#include "chasm-procedure-table/chasm-procedure-table.h"


Chasm_DSMain_Model::Chasm_DSMain_Model(Chasm_Procedure_Table* proctable)
  :  proctable_(proctable)
{

}

void Chasm_DSMain_Model::register_procedures()
{
 //proctable_->re
 //proctable_->register_s0(testqvar, @300762);
}

