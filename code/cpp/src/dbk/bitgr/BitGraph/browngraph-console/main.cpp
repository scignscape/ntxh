#include <iostream>
#include <cstdio>

#include "structure/BrownGraph.h"
#include "traversal/GraphTraversal.h"

#include "dgdb/browngraph-info.h"

#include "util/C.h"

#include <QDebug>


#include "dgdb-white/dw-instance.h"
#include "dgdb-white/dw-record.h"
#include "dgdb-white/dgenvironment.h"
#include "dgdb-white/types/dw-type-system.h"
#include "dgdb-white/types/dw-type.h"


USING_KANS(DGDB)


#define LABEL_V "basic_vertex"
#define LABEL_E "basic_edge"
#define NAME "name"

#define brownv value<Vertex*>

#include "qmetas.h"


int main()
{
// BrownGraph_Info bgi(DEFAULT_DEV_DGDB_FOLDER "/browngraph/t1");

 QString save_path = DEFAULT_DEV_DGDB_FOLDER "/browngraph/t1";

 DW_Instance* dw = DGEnvironment(
   save_path);

 // // local_scratch_mode has no persistence at all.
  //   Scratch mode resets the database whenever it is
  //   opened by DigammaDB, but keeps the database in memory
  //   in between (so e.g. it can be examined via the wgdb utility).
 // dw->Config.flags.local_scratch_mode = true;

 dw->Config.flags.scratch_mode = true;
 dw->Config.flags.avoid_record_pointers = true;

 dw->init();

 DW_Type_System* dwt = dw->type_system();

 dwt->REGISTER_TYPE_NAME_RESOLUTION(BrownGraph_Info);

 dwt->REGISTER_TYPE(BrownGraph_Info)
   .default_object_layout()
   .set_opaque_encoder(&BrownGraph_Info::supply_data)
   .set_opaque_decoder(&BrownGraph_Info::absorb_data);

//   .set_opaque_encoder(&BrownGraph_Info::supply_data)
//   .set_opaque_decoder(&BrownGraph_Info::absorb_data);

// dwt->REGISTER_TYPE(Queue_Demo_Class)
//   .default_object_layout()
//   .set_stage_encoder(&Queue_Demo_Class::encode_stage_values)
//   .set_stage_queue_initializer(&Queue_Demo_Class::init_stage_queue)
//   .set_default_stage_queue_reader(&Queue_Demo_Class::read_stage_queue)
//  ;

 BrownGraph_Info* bgi = new BrownGraph_Info();
 if(! dw->load_typed_value(bgi) )
 {
  bgi->set_save_path(save_path);
  dw->save_typed_value(bgi);
 }


// dw->


}

int main1(int argc, char* argv[])
{
 BrownGraph graph;
 GraphTraversalSource* g = graph.traversal();

 Vertex* v1 = g->addV(LABEL_V)->property(NAME ,"n1")->next().brownv();
 Vertex* v2 = g->addV(LABEL_V)->property(NAME ,"n2")->next().brownv();

 Vertex* v3 = g->addV(LABEL_V)->property(NAME ,"n3")->next().brownv();
 Vertex* v4 = g->addV(LABEL_V)->property(NAME ,"n4")->next().brownv();


 qDebug() << v1->id().toULongLong();
 qDebug() << v2->id().toULongLong();


// Vertex* v11 = g->V()->has(NAME ,"n1")->next().brownv();
// qDebug() << v11->id().toULongLong();

 try
 {
  g->V(v1)->addE(LABEL_E)->to(v2)->iterate();
  g->V(v1)->addE(LABEL_E)->to(v4)->iterate();
  g->V(v3)->addE(LABEL_E)->to(v4)->iterate();
 }
 catch(const std::exception& err)
 {
  qDebug() << err.what() << "\n";
  return -1;
 }

 g->V()->in()->forEachRemaining([](QVariant& v)
 {
  Vertex* vtx = QVariant_cast<Vertex*>(v);
  qDebug() << "in id: " << QVariant_cast<QString>(vtx->property(NAME)->value()) << "\n";
 });

 g->V()->out()->forEachRemaining([](QVariant& v)
 {
  Vertex* vtx = QVariant_cast<Vertex*>(v);
  qDebug() << "out id: " << QVariant_cast<QString>(vtx->property(NAME)->value()) << "\n";
 });

 qDebug() << "count: " << graph.all_edges().size() << "\n";
 for(Edge* e : graph.all_edges())
   qDebug() << QVariant_cast<QString>(e->outV()->property(NAME)->value()) << " -> " << QVariant_cast<QString>(e->inV()->property(NAME)->value()) << "\n";

 return 0;
}


int main2(int argc, char* argv[])
{
 BrownGraph graph;
 GraphTraversalSource* g = graph.traversal();

 QString filename = QString(argv[1]);
 FILE* f = fopen(filename.to_c_str(), "r");

 char id1[10];
 char id2[10];
 std::set<QString> names;
 while(2 == fscanf(f, "%s %s\n", id1, id2))
 {
  qDebug() << id1 << ", " << id2 << "\n";
  Vertex* v1;
  Vertex* v2;

  if(names.count(QString(id1)) == 0)
   v1 = QVariant_cast<Vertex*>(
      g->addV(LABEL_V)->property(NAME, QString(id1))->next());
  else
   v1 = QVariant_cast<Vertex*>(
      g->V()->has(NAME, QString(id1))->next());

  names.insert(QString(id1));

  qDebug() << QVariant_cast<uint64_t>(v1->id()) << " " << QVariant_cast<QString>(v1->property(NAME)->value()) << "\n";

  if(names.count(QString(id2)) == 0)
   v2 = QVariant_cast<Vertex*>(g->addV(LABEL_V)->property(NAME, QString(id2))->next());
  else
   v2 = QVariant_cast<Vertex*>(g->V()->has(NAME, QString(id2))->next());
  names.insert(QString(id2));

  qDebug() << QVariant_cast<uint64_t>(v2->id()) << " " << QVariant_cast<QString>(v2->property(NAME)->value()) << "\n";
  qDebug() << QVariant_cast<uint64_t>(v1->id()) << " - - " << QVariant_cast<uint64_t>(v2->id()) << "\n";

  try
  {
   g->V(v1)->addE(LABEL_E)->to(v2)->iterate();
  }
  catch(const std::exception& err)
  {
   qDebug() << err.what() << "\n";
   return -1;
  }
 }

 fclose(f);

 g->V()->in()->forEachRemaining([](QVariant& v) {
  Vertex* vtx = QVariant_cast<Vertex*>(v);
  qDebug() << "id: " << QVariant_cast<QString>(vtx->property(NAME)->value()) << "\n";
 });

 qDebug() << "count: " << graph.all_edges().size() << "\n";
 for(Edge* e : graph.all_edges()) qDebug() << QVariant_cast<QString>(e->outV()->property(NAME)->value()) << " -> " << QVariant_cast<QString>(e->inV()->property(NAME)->value()) << "\n";

 try {
  //        __->both()->id()->forEachRemaining([](QVariant& w) {
  // Vertex* v = QVariant_cast<Vertex*>(w);
  // QVariant a = v->property("cc")->value();
  // qDebug() << QVariant_cast<QString>(v->property(NAME)->value());
  // qDebug() << QVariant_cast<uint64_t>(v->property("cc")->value());
  //         } );

  g->V()->property("cc", QVariant::fromValue((new GraphTraversal)->both()->id()))
    ->forEachRemaining([](QVariant& w) {
   Vertex* v = QVariant_cast<Vertex*>(w);
   QVariant a = v->property("cc")->value();
   //? qDebug() << a.type().name() << "\n";
   qDebug() << QVariant_cast<QString>(v->property(NAME)->value()) << "/" << QVariant_cast<uint64_t>(v->id()) << ": " << QVariant_cast<uint64_t>(v->property("cc")->value()) << "\n";
  });
 } catch(const std::exception& err) {
  qDebug() << err.what() << "\n";
  return -1;
 }

 //    try {
 ////?
 ////        GPUGraphTraversal* gpu_trv = dynamic_cast<GPUGraphTraversal*>(dynamic_cast<BrownGraphTraversalSource*>(graph.traversal())->withGPU()->V()->id());
 ////        gpu_trv->filter(Q<uint64_t>::eq((uint64_t)1, gpu_trv))->iterate();
 //    } catch(const std::exception& err) {
 //        qDebug() << err.what() << "\n";
 //        return -1;
 //    }

 //    try {
 //        qDebug() << "min id: " << QVariant_cast<uint64_t>(graph.traversal()->V()->id()->min(C<uint64_t>::compare())->next()) << "\n";
 //        dynamic_cast<BrownGraphTraversalSource*>(graph.traversal())->withGPU()->V()->id()->min(C<uint64_t>::compare())->iterate();
 //    } catch(const std::exception& err) {
 //        qDebug() << err.what() << "\n";
 //        return -1;
 //    }

 try {
  qDebug() << "coalesce:";// << std::endl;
  graph.traversal()->V()->coalesce({__->id(), __->id()})->forEachRemaining([](QVariant& i) {
   uint64_t id = QVariant_cast<uint64_t>(i);
   qDebug() << id;// << std::endl;
  });
  qDebug() << "\n";// std::endl;
 } catch(const std::exception& err) {
  qDebug() << err.what(); // << std::endl;
  return -1;
 }
}
