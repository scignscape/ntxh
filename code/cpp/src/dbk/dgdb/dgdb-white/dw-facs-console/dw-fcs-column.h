
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DW_FCS_COLUMN__H
#define DW_FCS_COLUMN__H 

#include "accessors.h"

#include "global-types.h"


#include <QString>
#include <QByteArray>


class DW_FCS_Column
{
 QString label_;
 u1 matrix_position_;

public:

 DW_FCS_Column();

 ACCESSORS(QString ,label)
 ACCESSORS(u1 ,matrix_position)

 void supply_data(QByteArray& qba);
 void absorb_data(const QByteArray& qba);

};



#endif // DW_FCS_COLUMN__H

