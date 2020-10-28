
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "clo-species.h"

#include <QDataStream>

CLO_Species::CLO_Species()
{

}

void CLO_Species::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << abbreviation_ << instances_ << name_;
}

void CLO_Species::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
 qds >> abbreviation_ >> instances_ >> name_;
}


