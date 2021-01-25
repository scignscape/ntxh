
//           Copyright Nathaniel Christen 2019.
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

#include "language-sample.h"
#include "language-sample-group.h"

#include "dataset.h"

#include "qh-model.h"

#include "qh/local.h"


#include <QDateTime>


USING_KANS(DSM)

Qh_Model::Qh_Model(Dataset* ds)
{
 Qh_Runtime qhr;
 Qh_Type_System* qht = qhr.type_system();

 Qh_Local* lcl = new Qh_Local("demo");


//// Qh_Class_Object qco("Test_Class");
//// qco.pack_code() = qbc;

// //Qh_Class_Object& qco =
 qht->REGISTER_TYPE(Language_Sample)
   .qh_local(lcl)
   .set_pack_encoder(&Language_Sample::supply_pack)
   .defpack(&Qh_Local::init_pack_code)
   .qh_class()
   .deffields(&Qh_Local::deffields<Language_Sample>)
   ;

}


void Qh_Model::init()
{

}

