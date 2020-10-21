
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dw-fcs-matrix.h"

#include <QDataStream>


DW_FCS_Matrix::DW_FCS_Matrix()
 : number_of_columns_(0), number_of_rows_(0)
{

}

void DW_FCS_Matrix::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << number_of_columns_ << number_of_rows_;
}

void DW_FCS_Matrix::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
 qds >> number_of_columns_ >> number_of_rows_;
}



