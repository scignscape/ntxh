
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>
#include <QByteArray>
#include <QDataStream>

#include <QDate>

#include "demo-class.h"

#include "dgdb-white/dw-instance.h"
#include "dgdb-white/dw-record.h"

#include "dgdb-white/dw-stage-value.h"

#include "dgdb-white/dw-frame.h"
#include "dgdb-white/dw-dominion.h"


#include "dgdb-white/wdb-manager.h"
#include "dgdb-white/dgenvironment.h"

#include "dgdb-white/wdb-instance.h"

#include "global-types.h"


USING_KANS(DGDB)


int main2(int argc, char* argv[])
{
 DW_Instance* dw = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/t1");

 // // local_scratch_mode has no persistence at all.
  //   Scratch mode resents the database whenever it is 
  //   opened by DigammaDB, but keeps the database in memory 
  //   in between (so e.g. it can be examined via the wgdb utility). 
 //dw->Config.flags.local_scratch_mode = true;

 dw->Config.flags.scratch_mode = true;
 dw->init();




 DW_Stage_Value dwsv1;
 //?
// dwsv1.set_str_data("test", 5);
 //dwsv1.set_u4_data(66);

 dwsv1.set_int_data(5);

 void* rec = dw->add_raw_record(2, {dwsv1});

 qDebug() << "rec = " << rec;


 DW_Stage_Value dwsv0;
 dwsv0.set_str_data("test", 5);
 void* rec0 = dw->add_raw_record(2, {dwsv0});

// DW_Stage_Value dwsv2;
// dwsv2.set_rec_data(rec);
// dw->set_raw_record_fields(rec, 1, {dwsv2});


 DW_Stage_Value dwsv2;
 //dwsv2.set_str_data("rec");
 dwsv2.set_rec_data(rec0);
 dw->set_raw_record_fields(rec, 1, {dwsv2});

// void* v1 = dw->query_leading_str(0); 
//? 
 void* v2 = dw->query_leading_int(0); 
 qDebug() << "v2 = " << v2;

 void* v1 = dw->query_leading_rec(1); 
 qDebug() << "v1 = " << v1;

 void* v3 = dw->query_leading_str(0); 
 qDebug() << "v3 = " << v3;

 
}

int main1(int argc, char* argv[])
{
 DW_Instance* dw = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/t1");

 // // local_scratch_mode has no persistence at all.
  //   Scratch mode resents the database whenever it is 
  //   opened by DigammaDB, but keeps the database in memory 
  //   in between (so e.g. it can be examined via the wgdb utility). 
 //dw->Config.flags.local_scratch_mode = true;

 dw->Config.flags.scratch_mode = true;
 dw->init();
 

 qDebug() << "DB root folder: " << dw->db_root_folder();

 Demo_Class dc1;
 dc1.set_a_string("Test Payload");
 dc1.set_a_number(77);

 QByteArray qba1;
 dc1.supply_data(qba1);

 DW_Record dwr1 = dw->new_wg_hypernode_record(qba1);


 Demo_Class dc2;
 dc2.set_a_string("Test Hyperedge");
 dc2.set_a_number(88);

 QByteArray qba2;
 dc2.supply_data(qba2);

 DW_Record dwr2 = dw->new_wg_hypernode_record(qba2);

 DW_Frame& fr = *dw->new_frame(); // new DW_Frame(dw);
 DW_Dominion* dom = new DW_Dominion();

 DW_Context* ctxt = fr.new_context();


 dwr1 << (fr/dom/ctxt)["Demo.SomeRelation"] >> dwr2;
//?
 fr.commit();

 //(fr/dw)

 //dw->new_wg_outedges_record(dwr1 "Demo.SomeRelation" 

//? dw->add_hyperedge(dwr1, "Demo.SomeRelation", dwr2);



 //? dwr1 << (fr/dw)["Demo.SomeRelation"] >> dwr2;   

// DW_Record dwr3 = 
 
}

int main(int argc, char* argv[])
{
 DW_Instance* dw = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/t1");

 // // local_scratch_mode has no persistence at all.
  //   Scratch mode resents the database whenever it is 
  //   opened by DigammaDB, but keeps the database in memory 
  //   in between (so e.g. it can be examined via the wgdb utility). 
 //dw->Config.flags.local_scratch_mode = true;

// dw->Config.flags.scratch_mode = true;
 dw->init();

 QString rf = dw->get_restore_file();

 qDebug() << "RF = " << rf; 

 if(!rf.isEmpty())
 {
  dw->restore_from_file(rf);
  dw->reinit();
 }


}

int main4(int argc, char* argv[])
{
 DW_Instance* dw = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/t1");

 // // local_scratch_mode has no persistence at all.
  //   Scratch mode resents the database whenever it is 
  //   opened by DigammaDB, but keeps the database in memory 
  //   in between (so e.g. it can be examined via the wgdb utility). 
 //dw->Config.flags.local_scratch_mode = true;

// dw->Config.flags.scratch_mode = true;
 dw->init();

 QString rf = dw->get_restore_file();

 qDebug() << "RF = " << rf; 

 qDebug() << "DB root folder: " << dw->db_root_folder();

 Demo_Class dc;
 dc.set_a_string("Test Payload");
 dc.set_a_number(77);

 QByteArray qba;
 dc.supply_data(qba);

 DW_Record dwr = dw->new_wg_hypernode_record(qba);

 QByteArray qba1;
 dw->get_hypernode_payload(dwr.id(), qba1);

 Demo_Class dc1;
 dc1.absorb_data(qba1);

 qDebug() << "ok: " << dc1.a_string() << dc1.a_number(); 

 DW_Stage_Value dwsv;
 dwsv.set_u4_data(dc.a_number());

 u1 et = dwsv.get_dw_encoding_type();
   
 DW_Record dwr1 = dw->new_wg_index_record(dwr, dwsv);
 
 DW_Stage_Value dwsv1;
 dwsv1.set_u4_data(dc.a_number());
 
 DW_Record dwr2 = dw->query_by_index_record(dwsv1);

 QByteArray qba2;
 dw->get_hypernode_payload(dwr2, qba2);
 
 Demo_Class dc2;
 dc2.absorb_data(qba2);
 qDebug() << "ok: " << dc2.a_string() << dc2.a_number(); 

 dw->save_changes();

}


