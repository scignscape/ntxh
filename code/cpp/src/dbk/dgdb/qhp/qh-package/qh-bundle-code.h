
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef QH_BUNDLE_CODE__H
#define QH_BUNDLE_CODE__H

#include <QByteArray>

#include <functional>

#include "global-types.h"


class Qh_Bundle_Code
{
 QVector<u1> field_codes_;


public:

 enum class Type_Hints {
   N_A, Signed, Real, Chars_QString,
   Chars_Encoded, Blob, Opaque, Enum, Unsigned
 };

 Qh_Bundle_Code();

 void add_u1(u2 array = 0);
 void add_u2(u2 array = 0);
 void add_u4(u2 array = 0);
 void add_n8(u2 array = 0);

 void add_s1(u2 array = 0);
 void add_s2(u2 array = 0);
 void add_s4(u2 array = 0);
 void add_s8(u2 array = 0);

 void add_ratio(u2 array = 0);
 void add_posit(u2 array = 0);
 void add_r4(u2 array = 0);
 void add_r8(u2 array = 0);

 void add_str(u2 array = 0);
 void add_txn(u2 array = 0);


 u1 with_type_hint(u1 cue, Type_Hints th);

 static u1 get_type_hint_code(Type_Hints th);
 static QString get_type_hint_string(Type_Hints th);

 void each(std::function<u2(u1, u2)> fn);

 void each(std::function<u2(u1, Type_Hints, u2)> fn);

 Type_Hints get_type_hint(u2 index);

 static Type_Hints parse_type_hint(u1 cue);

 QByteArray as_qba();

 QPair<u1, Type_Hints> get_requirements(u2 index);


};


#endif // QH_BUNDLE_CODE__H


