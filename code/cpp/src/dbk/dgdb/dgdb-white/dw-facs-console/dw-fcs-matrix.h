
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DW_FCS_MATRIX__H
#define DW_FCS_MATRIX__H 

#include "accessors.h"

#include "global-types.h"


#include <QString>
#include <QByteArray>


class DW_FCS_Matrix
{
 u1 number_of_columns_;
 u4 number_of_rows_;

public:

 DW_FCS_Matrix();

 ACCESSORS(u1 ,number_of_columns)
 ACCESSORS(u4 ,number_of_rows)

 void supply_data(QByteArray& qba);
 void absorb_data(const QByteArray& qba);


};



#endif // DW_FCS_MATRIX__H

