
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CHASM_TYPE_OBJECT__H
#define CHASM_TYPE_OBJECT__H

#include <QString>

#include <QMetaType>

#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include <functional>

#include "kans.h"

#include "chasm-carrier.h"

#include "chasm-runtime.h"


//KANS_(GTagML)

class Chasm_Type_Object
{
 QString name_;
 QMetaType* qmetatype_;

 u2 codes_with_position_[4];

public:

 Chasm_Type_Object(QString name, u2 c0, u2 c1, u2 c2, u2 c3);

 ACCESSORS(QString ,name)

 Chasm_Typed_Value_Representation with_rep(QString rep)
 {
  return {this, 0, rep};
 }

};

// _KANS(GTagML)

#endif // CHASM_TYPE_OBJECT__H

