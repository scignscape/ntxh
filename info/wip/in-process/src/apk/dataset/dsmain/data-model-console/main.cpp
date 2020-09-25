
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QString>
#include <QDebug>

#include "dsmain/language-sample.h"

#include "dsmain/language-sample-group.h"

#include "dsmain/dataset.h"


#include "phaong/phaong.h"
#include "phaong/phaong-types.h"

#include "kans.h"

USING_KANS(DSM)

int main(int argc, char **argv)
{
 Dataset ds;// (DEFAULT_RPH_FOLDER  "/samples.txt");

 //
 ds.load_from_file(DEFAULT_NTXH_FOLDER  "/ctg.ngml.ntxh");

// ds.save_to_file_udp();

//
// ds.load_from_file(DEFAULT_NTXH_FOLDER  "/handbook/h.ntxh");


 return 0;
}

#ifdef HIDE
int main(int argc, char **argv)
{
 phaong<pg_t> pg;

 QVector<phaong<pg_t>::Hypernode*> hypernodes;
 QVector<phaong<pg_t>::Hyperedge*> hyperedges;

 QPair<QVector<phaong<pg_t>::Hypernode*>&,
   QVector<phaong<pg_t>::Hyperedge*>&> graph {hypernodes, hyperedges};

 typedef QPair<QVector<phaong<pg_t>::Hypernode*>&,
   QVector<phaong<pg_t>::Hyperedge*>&> g_t;

 pg.set_user_data(&graph);

 pg.set_node_add_function([](phaong<pg_t>& _pg, phaong<pg_t>::Hypernode* hn)
 {
  QVector<phaong<pg_t>::Hypernode*>& hh = _pg.user_data_as<g_t>()->first;
  hh.push_back(hn);
 });

 pg.set_edge_add_function([](phaong<pg_t>& _pgs, phaong<pg_t>::Hyperedge* he)
 {
  QVector<phaong<pg_t>::Hyperedge*>& hv = _pgs.user_data_as<g_t>()->second;
  hv.push_back(he);
 });

 phaong<pg_t>::Hypernode* hn = pg.new_hypernode(-8);
 pg.set_data(hn, 0, {"xx", nullptr}, {"QString", nullptr});
 pg.get_data(hn, 0, [](QPair<QString, void*>& pr)
 {
  qDebug() << pr.first;
 });

 pg.set_af(hn, 0, {"aa", nullptr}, {"QString", nullptr});
 pg.get_af(hn, 0, [](QPair<QString, void*>& pr)
 {
  qDebug() << pr.first;
 });




// pg.set_data(hn, 82, {"aa", nullptr}, {"QString", nullptr});
// pg.get_data(hn, 82, [](QPair<QString, void*>& pr)
// {
//  qDebug() << pr.first;
// });

// pg.set_data(hn, 5, {"bx", nullptr}, {"QString", nullptr});
// pg.get_data(hn, 5, [](QPair<QString, void*>& pr)
// {
//  qDebug() << pr.first;
// });

// pg.set_data(hn, 52, {"ax", nullptr}, {"QString", nullptr});
// pg.get_data(hn, 52, [](QPair<QString, void*>& pr)
// {
//  qDebug() << pr.first;
// });

// pg.set_data(hn, 5, {"bx", nullptr}, {"QString", nullptr});
// pg.get_data(hn, 5, [](QPair<QString, void*>& pr)
// {
//  qDebug() << pr.first;
// });

 phaong<pg_t>::Hypernode* hn1 = pg.new_hypernode(8);
 pg.set_data(hn1, 11, {"yy", nullptr}, {"QString", nullptr});
 pg.get_data(hn1, 3, [](QPair<QString, void*>& pr)
 {
  qDebug() << pr.first;
 });

 pg.new_hyperedge(hn, hn1);

 return 0;
}


int main1(int argc, char* argv[])
{
 Dataset ds (DATA_FOLDER "all.txt");
 QVector<Language_Sample*>& samps = ds.samples();

 phaong<pg_t> pg;

 QVector<Language_Sample_Group*>& groups = ds.groups();
 Language_Sample_Group::read_groups_from_file
   (DATA_FOLDER "/all.g.txt", groups);

 Language_Sample::read_samples_from_file
   (pg, DATA_FOLDER "/all.txt", samps, groups);

// ds.save_to_file();


 return 0;
}
#endif// def HIDE
