
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef QH__LOCAL__H
#define QH__LOCAL__H

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>

#include "global-types.h"

//?KANS_(GHL)


class Qh_Class_Object;
class Qh_Pack_Code;
class Qh_Pack_Builder;


class Qh_Local
{
 QString description_;

public:

 Qh_Local(QString description);

 ACCESSORS(QString ,description)

 template<typename OBJ_Type>
 void deffields(Qh_Class_Object& qco);

 void init_pack_code(QString tn, Qh_Pack_Code& qpc);

 template<typename OBJ_Type>
 void _init_pack_code(Qh_Pack_Code& qpc);

 template<typename OBJ_Type>
 void _supply_pack(OBJ_Type& _this, Qh_Pack_Builder& qpb);

 void supply_pack(QString tn, void* _this, Qh_Pack_Builder& qpb);

 static void static_deffields(Qh_Local* _this, Qh_Class_Object& qco);
 static void _static_deffields(Qh_Class_Object& qco);

};


//?_KANS(GHL)

#endif // QH__LOCAL__H
