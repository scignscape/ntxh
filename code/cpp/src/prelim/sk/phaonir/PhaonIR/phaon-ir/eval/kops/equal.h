
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef EQUAL__H
#define EQUAL__H


#include <QVector>


#include "eval/kop-base.h"

#include "kans.h"

KANS_(Phaon)


struct PHR_KOP_Equal : PHR_KOP_Base<qint32>
{

public:

 PHR_KOP_Equal();

 void run_eval(QPair<qint32, qint32>& args, qint32& result);
 void run_eval(QVector<qint32>& args, qint32& result);

};

_KANS(Phaon)

#endif // EQUAL__H
