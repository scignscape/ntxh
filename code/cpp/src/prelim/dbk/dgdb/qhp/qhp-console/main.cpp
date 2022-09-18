
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qh-package/qh-pack-code.h"

#include "qh-package/qh-pack-builder.h"
#include "qh-package/qh-pack-reader.h"

#include "qh-package/qh-hypernode.h"
#include "qh-package/qh-hyperedge.h"

#include "qh-package/qh-hyperedge-dominion.h"

#include "qh-package/qh-node-frame.h"

#include "qh-package/qh-class-object.h"

#include "qh-package/runtime/qh-runtime.h"
#include "qh-package/runtime/qh-type-system.h"
#include "qh-package/runtime/qh-type.h"


#include <QDebug>

#include "test-class.h"

#include "sdi/language-sample.h"

#include "qh/local.h"

USING_KANS(GHL)

int main(int argc, char* argv[])
{
 Qh_Runtime qhr;
 Qh_Type_System* qht = qhr.type_system();

 Qh_Local* lcl = new Qh_Local("demo");


// Qh_Class_Object qco("Test_Class");
// qco.pack_code() = qbc;

 //Qh_Class_Object& qco =
 qht->REGISTER_TYPE(Language_Sample)
   .qh_local(lcl)
   .set_pack_encoder(&Language_Sample::supply_pack)
   .defpack(&Qh_Local::_init_pack_code<Language_Sample>)
   .qh_class()
   .deffields(&Qh_Local::deffields<Language_Sample>)
   ;


 /*   Marianna  L*
  *
  *
  *
  */

 //    .set_pack_encoder(&Language_Sample::supply_pack)


 //    .defpack(&Language_Sample::init_pack_code)
 //     .set_pack_encoder(&Test_Class::supply_pack)


// qco.register_field_info("")

//   .set_qh_class_object(&qco);

// QString res;
// Qh_Type* tt = qht->get_type_by_name("Language_Sample", &res);
// tt->runb();

 Language_Sample ls("xxx");

 Qh_Pack_Builder* qpb = qhr.serialize(&ls);

// Test_Class tc;
// tc.set_a_number(33);
// tc.set_a_string("xxx");

// Qh_Hypernode* qhn = qhr.new_hypernode(&tc);

   //;// = qpb.as_hypernode();

 Qh_Pack_Code qbc1;
 qbc1.add_u4();
 qbc1.add_n8();
 qbc1.add_proxy();
 qbc1.add_u4(1);

 Qh_Pack_Builder qpb1(qbc1);
 qpb1.add_structure_value(QVariant::fromValue(77));
 qpb1.add_structure_value(QVariant::fromValue(78));

 qpb1.init_proxy_data();
 //qpb1.add_structure_proxy_value(qhn);

 qpb1.add_array_value(QVariant::fromValue(177));
 qpb1.add_array_value(QVariant::fromValue(278));

 Qh_Hypernode* qhn1 = qpb1.as_hypernode();

// Qh_Hyperedge* qhe = new Qh_Hyperedge("generic-connection");
// qhe->set_source(qhn);
// qhe->set_source(qhn1);

 Qh_Node_Frame& qnf = *new Qh_Node_Frame;

 Qh_Hyperedge_Dominion qhd; //("generic-connection");
 qhd.add_label("generic-connection", "gen");

 //qhn << qnf/qhd("gen") >> qhn1;


 Qh_Pack_Reader qpr1(qbc1, *qhn1);

 qpr1.set_proxy_data(qpb1.proxy_data());

 QVariant qvar1a = qpr1.read_value();
 QVariant qvar2a = qpr1.read_value();
 QVariant qvar3a = qpr1.read_value();
 QVariant qvar4a = qpr1.read_value();

 u1 uu1a = qvar1a.toUInt();
 u2 uu2a = qvar2a.toUInt();

 Qh_Hypernode* qhn2 = (Qh_Hypernode*) qvar3a.value<void*>();

 //qDebug() << ((qhn2 == qhn)? "yeah" : "nay");

// u1 uu3a = qvar3a.toUInt();
// u2 uu4a = qvar4a.toUInt();

// qDebug() << "uu1a = " << uu1a;
// qDebug() << "uu2a = " << uu2a;
// qDebug() << "uu3a = " << uu3a;
// qDebug() << "uu4a = " << uu4a;


// Qh_Pack_Reader qpr(qbc, *qhn);

// QVariant qvar1 = qpr.read_value();
// QVariant qvar2 = qpr.read_value();
// QVariant qvar3 = qpr.read_value();

// u1 uu1 = qvar1.toUInt();
// u2 uu2 = qvar2.toUInt();
// QString str = qvar3.toString();

// qDebug() << "uu1 = " << uu1;
// qDebug() << "uu2 = " << uu2;
// qDebug() << "str = " << str;


// qbc.each([](u1 code, Qh_Pack_Code::Type_Hints th, u2 c)
// {
//  qDebug() << "code = " << '(' << Qh_Pack_Code::get_type_hint_string(th) << ") " << code;
//  return c;
// });

 return 0;
}

