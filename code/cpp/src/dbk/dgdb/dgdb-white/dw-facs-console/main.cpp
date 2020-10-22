
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>
#include <QByteArray>
#include <QDataStream>

#include <QDate>

#include "dw-fcs-matrix.h"
#include "dw-fcs-document.h"
#include "dw-fcs-column.h"


#include "dgdb-white/dw-instance.h"
#include "dgdb-white/dw-record.h"

#include "dgdb-white/dw-stage-value.h"
#include "dgdb-white/stage/dw-stage-queue.h"

#include "dgdb-white/dw-frame.h"
#include "dgdb-white/dw-dominion.h"


#include "dgdb-white/wdb-manager.h"
#include "dgdb-white/dgenvironment.h"

#include "dgdb-white/wdb-instance.h"
#include "dgdb-white/types/dw-type-system.h"
#include "dgdb-white/types/dw-type.h"

#include "global-types.h"


USING_KANS(DGDB)


int main(int argc, char* argv[])
{
 DW_Instance* dw = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/fcs");

 // // local_scratch_mode has no persistence at all.
  //   Scratch mode resents the database whenever it is 
  //   opened by DigammaDB, but keeps the database in memory 
  //   in between (so e.g. it can be examined via the wgdb utility). 
 //dw->Config.flags.local_scratch_mode = true;

 dw->Config.flags.scratch_mode = true;
 dw->Config.flags.avoid_record_pointers = true;


 dw->init();

 DW_Type_System* dwt = dw->type_system();
 dwt->REGISTER_TYPE_NAME_RESOLUTION(DW_FCS_Column);

 dwt->REGISTER_TYPE(DW_FCS_Column)
 //  .set_binary_encoder(&DW_FCS_Column::static_supply_data)
   .set_default_binary_encoder(&DW_FCS_Column::supply_data)
   .set_default_binary_decoder(&DW_FCS_Column::absorb_data)
  ;

 DW_FCS_Column* dfc = new DW_FCS_Column;
 dfc->set_label("$P1");
 dfc->set_matrix_position(1);

// QByteArray qba;
// dfc->supply_data(qba);
// DW_Record dwr = dw->new_binary_hypernode_record(qba);

 DW_Record dwr = dw->new_binary_hypernode_record(dfc);

//*
 QByteArray qba1;
 dw->get_hypernode_payload(dwr.id(), qba1);
 DW_FCS_Column dfc1;
 dfc1.absorb_data(qba1);
//*/


 qDebug() << "ok: " << dfc1.label() << dfc1.matrix_position(); 

 DW_Stage_Value dwsv;
 dwsv.set_u1_data(dfc->matrix_position());

 //u1 et = dwsv.get_dw_encoding_type();
   
 DW_Record dwr1 = dw->new_wg_index_record(dwr, dwsv);
 
 DW_Stage_Value dwsv1;
 dwsv1.set_u1_data(dfc->matrix_position());
 
 DW_Record dwr2 = dw->query_by_index_record(dwsv1);

 DW_FCS_Column* dfc2 = dw->parse_binary_record<DW_FCS_Column>(dwr2);
/*
 QByteArray qba2;
 dw->get_hypernode_payload(dwr2, qba2); 
 DW_FCS_Column dfc2;
 dfc2.absorb_data(qba2);
*/

 qDebug() << "ok: " << dfc2->label() << dfc2->matrix_position(); 

 QStringList qsl {"s1", "s2", "s3", "s4"};
 
 DW_Record dwr4 = dw->add_subvalues_record(dwr, qsl);


// dw->save_changes();

 return 0;
}




