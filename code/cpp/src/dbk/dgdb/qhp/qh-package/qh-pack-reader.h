
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef QH_PACK_READER__H
#define QH_PACK_READER__H

#include <QByteArray>

#include <QVariant>

#include <functional>

#include "global-types.h"

//class Qh_Bundle_Code;


#include "qh-bundle-code.h"

class Qh_Pack_Reader
{
 Qh_Bundle_Code& bundle_code_;

 QVector<u1> data_;

 u2 current_index_;
 u4 current_byte_index_;

public:

 Qh_Pack_Reader(Qh_Bundle_Code& bundle_code, const QVector<u1>& data);

 QVariant read_value();

};


#endif // QH_PACK_READER__H


