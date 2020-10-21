
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dw-fcs-column.h"

#include <QDataStream>


DW_FCS_Column::DW_FCS_Column()
 : matrix_position_(0)
{

}


void DW_FCS_Column::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << matrix_position_ << label_;
}

void DW_FCS_Column::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
 qds >> matrix_position_ >> label_;
}



