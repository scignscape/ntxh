//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "local.h"

#include <QDebug>

#include "qh-package/qh-class-object.h"

#include "sdi/language-sample.h"
#include "sdi/language-sample-group.h"

#include <typeindex>


USING_KANS(GHL)

//#include "qh-package/qh-pack-builder.h"


Qh_Local::Qh_Local(QString description)
  :  description_(description)
{

}


void Qh_Local::supply_pack(QString tn, void* _this, Qh_Pack_Builder& qpb)
{
 Language_Sample& _this_ = *(Language_Sample*)(_this);

}


template<>
void Qh_Local::_supply_pack<Language_Sample>(Language_Sample& _this, Qh_Pack_Builder& qpb)
{

}


template<>
void Qh_Local::deffields<Language_Sample>(Qh_Class_Object& qco)
{

}

template<>
void Qh_Local::_init_pack_code<Language_Sample>(Qh_Pack_Code& qpc)
{
 qpc.add_str() // text
   .add_u4() // database_id
   .add_u2() // index
   .add_str() // full index string
   .add_u2() // chapter
   .add_u4() // page
   .add_opaque() // everything else
   ;
}

void Qh_Local::init_pack_code(QString tn, Qh_Pack_Code& qpc)
{
// static QMap<QString, std::type_info*> static_map {{
//   {"Language_Sample", &typeid(Language_Sample)},
//   {"Language_Sample_Group", &typeid(Language_Sample_Group)},
//                                      }};

// std::type_info* sti = static_map.value(tn);

// switch ((n8) sti)
// {
// case typeid(Language_Sample) : _init_pack_code<Language_Sample>(qpc); break;
// case typeid(Language_Sample_Group) : _init_pack_code<Language_Sample_Group>(qpc); break;
// default: break;
// }

}


//void Qh_Local::deffields(Qh_Class_Object& qco)
//{

//}

void Qh_Local::_static_deffields(Qh_Class_Object& qco)
{

}



void Qh_Local::static_deffields(Qh_Local* _this, Qh_Class_Object& qco)
{
 //_this->deffields(qco);
}
