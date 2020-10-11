
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "facs-bridge/qvector-matrix-r8.h"


#include <QFile>
#include <QDebug>

//#include "kans.h"
//USING_KANS(MPF)

 // //  this is to test out the QVector_Matrix_R8 class ...

int main()
{
 QVector_Matrix_R8* qvm = new QVector_Matrix_R8(5, 6);
 qvm->merge_row({11, 12, 13, 14, 15}, 1);
 qvm->merge_row({31, 32, 33, 34, 35}, 3);
 qvm->patterned_fill_row(5);

 qvm->show(qDebug());

 QVector_Matrix_R8* qvm1 = qvm->new_from_dimensions();
 qvm1->patterned_fill();
 qvm1->show(qDebug());
 
 QVector_Matrix_R8* qvm2 = qvm->percentile_breakdown(10);
 qvm2->show(qDebug());

 QVector_Matrix_R8* qvm2a = qvm->percentile_rescale(10);
 qvm2a->show(qDebug());


 QVector_Matrix_R8* qvm3 = qvm1->percentile_breakdown(5);
 qvm3->show(qDebug());

 QVector_Matrix_R8* qvm3a = qvm1->percentile_rescale(5);
 qvm3a->show(qDebug());


 qDebug() << "OK";

 return 0;
}

