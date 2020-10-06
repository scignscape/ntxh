
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef HQVARIANT__H
#define HQVARIANT__H

#include <QDebug>
#include <QVector>
#include <QString>

//#include "angelscript.h"

#include "accessors.h"

#include "global-types.h"

#include <string>

#include "kans.h"


class hQVariant
{
 int ref_count_;
 
 QVariant* qv_;

public:

 hQVariant(QVariant qv);

 QVariant value() { return *qv_; }

 void add_ref();
 void release();
};


#endif //  HQVARIANT__H

