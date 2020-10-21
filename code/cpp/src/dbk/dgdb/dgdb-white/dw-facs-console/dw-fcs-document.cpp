
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dw-fcs-document.h"

#include <QDataStream>


DW_FCS_Document::DW_FCS_Document()
{

}

void DW_FCS_Document::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << path_;
}

void DW_FCS_Document::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
 qds >> path_;
}



