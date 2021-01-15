
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "browngraph-info.h"

#include <QDataStream>

#include "dgdb-white/dw-stage-value.h"
#include "dgdb-white/stage/dw-stage-queue.h"


BrownGraph_Info::BrownGraph_Info(QString save_path)
  : save_path_(save_path)
{

}

void BrownGraph_Info::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << save_path_ << max_vertex_id_ << max_edge_id_
   << active_vertex_ids_ << active_edge_ids_;
}

void BrownGraph_Info::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
 qds >> save_path_ >> max_vertex_id_ >> max_edge_id_
   >> active_vertex_ids_ >> active_edge_ids_;
}

