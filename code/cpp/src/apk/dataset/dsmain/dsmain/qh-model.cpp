
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

#include "qh-package/runtime/qh-type-system.h"
#include "qh-package/runtime/qh-type.h"

#include "language-sample.h"
#include "language-sample-group.h"
#include "discourse-markup-sample.h"

#include "dataset.h"

#include "dataset-info.h"

#include "qh-model.h"

#include "qh/local.h"


#include <QDateTime>
#include <QDebug>


USING_KANS(DSM)

Qh_Model::Qh_Model(Dataset* ds) :
  dataset_(ds), qh_type_system_(nullptr), qh_local_(nullptr)
{
}


void Qh_Model::init()
{
 qh_type_system_ = qh_runtime_.type_system();
 qh_local_ = new Qh_Local("demo");

 qh_type_system_
  ->REGISTER_TYPE(Language_Sample)
   .qh_local(qh_local_)
   .defpack(&Qh_Local::init_pack_code)
   .set_pack_encoder(&Language_Sample::supply_pack)
   .qh_class()
   .deffields(&Qh_Local::deffields<Language_Sample>)

  ->REGISTER_TYPE(Language_Sample_Group)
   .qh_local(qh_local_)
   .defpack(&Qh_Local::init_pack_code)
   .set_pack_encoder(&Language_Sample_Group::supply_pack)
   .qh_class()
    //? .deffields(&Qh_Local::deffields<Language_Sample_Group>)

  ->REGISTER_TYPE(Dataset_Info)
   .qh_local(qh_local_)
   .defpack(&Qh_Local::init_pack_code)
   .set_pack_encoder(&Dataset_Info::supply_pack)
   .qh_class()

  ->REGISTER_TYPE(Discourse_Markup_Sample)
   .qh_local(qh_local_)
   .defpack(&Qh_Local::init_pack_code)
   .set_pack_encoder(&Discourse_Markup_Sample::supply_pack)
   .qh_class()

   ;


}

