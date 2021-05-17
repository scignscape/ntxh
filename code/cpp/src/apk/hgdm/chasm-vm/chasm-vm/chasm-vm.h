
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CHASM_VM__H
#define CHASM_VM__H

#include <QString>

#include <QStack>
#include <QVariant>

#include <QDebug>



#include "accessors.h"
#include "flags.h"

#include "global-types.h"
#include "kans.h"


class Chasm_Runtime;

class Chasm_Runtime_Bridge;

class Chasm_VM
{
 Chasm_Runtime_Bridge* crb_;

public:

 Chasm_VM(Chasm_Runtime_Bridge* crb);

};

// _KANS(GTagML)

#endif // CHASM_VM__H
