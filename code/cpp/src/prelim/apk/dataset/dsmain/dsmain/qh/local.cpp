
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "local.h"

#include <QDebug>

#include "qh-package/qh-class-object.h"

//#include "sdi/language-sample.h"
//#include "sdi/language-sample-group.h"

#include <typeindex>

#include "language-sample.h"
#include "language-sample-group.h"

#include "qh-package/qh-pack-builder.h"
#include "qh-package/qh-pack-code.h"


USING_KANS(DSM)



Qh_Local::Qh_Local(QString description)
  :  description_(description)
{

}


void Qh_Local::supply_pack(QString tn, void* _this, Qh_Pack_Builder& qpb)
{
 Language_Sample& _this_ = *(Language_Sample*)(_this);

}

KANS_(DSM)

template<>
void Qh_Local::_supply_pack<Language_Sample>(Language_Sample& _this, Qh_Pack_Builder& qpb)
{

}


template<>
void Qh_Local::deffields<Language_Sample>(Qh_Class_Object& qco)
{

}


template<>
void Qh_Local::_init_pack_code<Discourse_Markup_Sample>(Qh_Pack_Code& qpc)
{
 qpc.add_str()   //  ref_
//   .add_str()    //  pdf_
//   .add_u2()     //  number_of_samples_
//   .add_u2()     //  number_of_groups_
   .add_opaque() //  everything else
   ;
}

template<>
void Qh_Local::_init_pack_code<Dataset_Info>(Qh_Pack_Code& qpc)
{
 qpc.add_str()   //  samples_file_
   .add_str()    //  pdf_
   .add_u2()     //  number_of_samples_
   .add_u2()     //  number_of_groups_
   .add_opaque() //  everything else
   ;
}

template<>
void Qh_Local::_init_pack_code<Language_Sample_Group>(Qh_Pack_Code& qpc)
{
 qpc.add_u4() // in_database_id_
   .add_u2() // id_
   .add_u2() // page_
   .add_u2() // section_
   .add_opaque() // everything else
   ;
}

template<>
void Qh_Local::_init_pack_code<Language_Sample>(Qh_Pack_Code& qpc)
{
 qpc.add_str() // text
   .add_str() // latex_label
   .add_str() // issue
   .add_u2() // page
   .add_opaque() // everything else
   ;
}

_KANS(DSM)

void Qh_Local::init_pack_code(QString tn, Qh_Pack_Code& qpc)
{
 static QMap<QString, Known_Types> static_map {{
#define TYPE_DECLARE(x) {#x, Known_Types::_##x},
#include "known-types.h"
#undef TYPE_DECLARE
}};

 Known_Types kt = static_map.value(tn);

 switch(kt)
 {
#define TYPE_DECLARE(x) case Known_Types::_##x: _init_pack_code<x>(qpc); break;
#include "known-types.h"
#undef TYPE_DECLARE
 default: break;
 }

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
