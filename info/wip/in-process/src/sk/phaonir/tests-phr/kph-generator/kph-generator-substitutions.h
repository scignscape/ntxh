
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef KPH_GENERATOR_SUBSTITUTIONS__H
#define KPH_GENERATOR_SUBSTITUTIONS__H


#include "kans.h"

#include <QString>
#include <QMap>

#include "accessors.h"

KANS_(Phaon)

class PHR_Carrier;

class KPH_Generator_Substitutions
{
 QString text_;

 QMap<int, QString> lambdas_;

public:

 KPH_Generator_Substitutions(QString text);

 ACCESSORS(QString ,text)

 QString get_lambda(int i);
 QString get_sigma(QString type_name);

 QString get_src_value(QString channel_name,
   const PHR_Carrier& car, int index);
};


_KANS(Phaon)


#endif //KPH_GENERATOR_SUBSTITUTIONS__H
