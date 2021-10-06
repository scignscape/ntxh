//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dh-instance.h"

#include "graph/dh-frame.h"

#include <QDebug>


//? USING_KANS(DGDB)


DH_Instance::DH_Instance(DgDb_Database_Instance* ddi)
  :  ddi_(ddi),
     current_inedges_record_count_(nullptr),
     current_outedges_record_count_(nullptr),
     current_multi_relation_record_count_(nullptr),
     inedges_floor_(0),
     outedges_floor_(0),
     multi_relation_floor_(0)
{}


DH_Frame* DH_Instance::new_frame()
{
 return new DH_Frame(this);
}


u4 DH_Instance::new_inedges_record_id()
{
 ++*current_inedges_record_count_;
 return *current_inedges_record_count_ + inedges_floor_;
}

u4 DH_Instance::new_outedges_record_id()
{
 ++current_outedges_record_count_;
 return *current_outedges_record_count_ + outedges_floor_;

}

u4 DH_Instance::new_multi_relation_record_id()
{
 ++current_multi_relation_record_count_;
 return *current_multi_relation_record_count_ + inedges_floor_;
}


DH_Record DH_Instance::new_outedges_or_multi_relation_record(DH_Record base,
  u4 col, u4 (DH_Instance::*cb)(),
  QVector<QPair<QPair<QString, DH_Record>, DH_Record>>& targets)
{
 //? DH_Record result = wdb_instance_->check_reset_ref_field(base, col, targets.size() * 3);
}

DH_Record DH_Instance::new_outedges_record(DH_Record base,
  QVector<QPair<QPair<QString, DH_Record>, DH_Record>>& targets)
{
  // // col 6 is outedges ...
 return new_outedges_or_multi_relation_record(base, 6, &DH_Instance::new_outedges_record_id, targets);
}

DH_Record DH_Instance::new_multi_relation_record(DH_Record base,
  QVector<QPair<QPair<QString, DH_Record>, DH_Record>>& targets)
{
  // // col 7 is relations ...
 return new_outedges_or_multi_relation_record(base, 7, &DH_Instance::new_multi_relation_record_id, targets);
}


QPair<u4, u4> DH_Instance::commit_new_triples(QVector<String_Label_Triple>& triples)
{
 QPair<u4, u4> result = {0, 0};
 for(String_Label_Triple& triple : triples)
 {
  if(triple.multi_relation_kind > 0)
  {
   ++result.first;
   qDebug() << "adding multi relation ..." << triple.connector_label;
   add_multi_relation(*triple.source, triple.connector_label, *triple.target,
     triple.multi_relation_kind);
  }
  else
  {
   ++result.second;
   qDebug() << "adding hyperedge ..." << triple.connector_label;
   add_hyperedge(*triple.source, triple.connector_label, *triple.target);
  }
 }
 return result;
}

DH_Record DH_Instance::add_hyperedge_or_multi_relation(DH_Record& source, QString connector,
  const DH_Record* annotation,
  DH_Record& target, u4 multi_relation_code)
{
 QPair<QPair<QString, DH_Record>, DH_Record> edge = annotation?
   QPair<QPair<QString, DH_Record>, DH_Record>{{connector, *annotation}, target}
   : QPair<QPair<QString, DH_Record>, DH_Record>{QPair{connector, QPair{0, nullptr} }, target};

 QVector<QPair<QPair<QString, DH_Record>, DH_Record>> targets {edge};

// if(multi_relation_code == 0)
//   return new_outedges_record(source, targets);
// else
//   return new_multi_relation_record(source, targets);

}

DH_Record DH_Instance::add_hyperedge(DH_Record& source, QString connector, const DH_Record& annotation,
  DH_Record& target)
{
 return add_hyperedge_or_multi_relation(source, connector, &annotation, target);
}

DH_Record DH_Instance::add_hyperedge(DH_Record& source, QString connector, DH_Record& target)
{
 return add_hyperedge_or_multi_relation(source, connector, nullptr, target);
}

DH_Record DH_Instance::add_multi_relation(DH_Record& source, QString connector, const DH_Record& annotation,
  DH_Record& target, u4 multi_relation_code)
{
 return add_hyperedge_or_multi_relation(source, connector, &annotation, target, multi_relation_code);
}

DH_Record DH_Instance::add_multi_relation(DH_Record& source, QString connector, DH_Record& target, u4 multi_relation_code)
{
 return add_hyperedge_or_multi_relation(source, connector, nullptr, target, multi_relation_code);
}
