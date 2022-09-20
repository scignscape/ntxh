
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef BROWNGRAPH_INFO__H
#define BROWNGRAPH_INFO__H

#include "accessors.h"

#include "global-types.h"

#include "dgdb-white/dw-stage-value.h"

#include <QString>
#include <QByteArray>

#include "kans.h"
USING_KANS(DGDB)

KANS_CLASS_DECLARE(DGDB ,DW_Stage_Value)
KANS_CLASS_DECLARE(DGDB ,DW_Stage_Queue)


class BrownGraph_Info
{
 QString save_path_;

 u4 max_vertex_id_;
 u4 max_edge_id_;

 QVector<u4> active_vertex_ids_;
 QVector<u4> active_edge_ids_;
 
public:

 BrownGraph_Info(QString save_path  = {});

 ACCESSORS(QString ,save_path)

 void supply_data(QByteArray& qba);
 void absorb_data(const QByteArray& qba);

// void encode_stage_values(QByteArray& qba,
//   DW_Stage_Value::Callback_type cb);

// void read_stage_queue(QQueue<void*>& vals);
 
// static void init_stage_queue(const QByteArray& qba,
//   QMap<u4, DW_Stage_Value>& qm, DW_Stage_Queue& sq);



};



#endif // GTAGML_DOCUMENT_MARK__H
