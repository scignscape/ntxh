
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>
#include <QByteArray>
#include <QDataStream>

#include <QDate>

#include "dgdb/dgdb-instance.h"
#include "dgdb/wdb-manager.h"
#include "dgdb/dgenvironment.h"

#include "dgdb/types/dgdb-type.h"

#include "dgdb/wg-stage-value.h"

#include "global-types.h"


USING_KANS(DGDB)


struct Test
{
 QString title;
 QString author;
 u2 num;
 QDate publication_date;
 QTime test_time;
 

 void encode_wg_stage_values(QByteArray& qba,
   WG_Stage_Value::Callback_type cb);

 void read_stage_queue(QQueue<void*>& vals); 
};

void Test::encode_wg_stage_values(QByteArray& qba,
   WG_Stage_Value::Callback_type cb)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << WG_Stage_Value().new_qstring_pair(title, "English").run[1](cb)
   << author
   << WG_Stage_Value().set_u2_data(num).run[2](cb)
   << WG_Stage_Value().set_date_data(publication_date).run[3](cb)
   << WG_Stage_Value().set_time_data(test_time).run[4](cb)
   << WG_Stage_Value().set_xml_data(QString::number(num), "xs:integer")
     .run[5](cb)[XSD_TYPE_DECODING_Flag];
 ;
}

void Test::read_stage_queue(QQueue<void*>& vals)
{
 title = *(QString*) vals.dequeue();
 author = *(QString*) vals.dequeue();
 num = *(u2*) vals.dequeue();
 publication_date = *(QDate*) vals.dequeue();
 test_time = *(QTime*) vals.dequeue();
 QStringList qsl = *(QStringList*) vals.dequeue();
}

int main(int argc, char* argv[])
{
 DgDb_Instance* dgi = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/t1");

 dgi->Config.flags.scratch_mode = true;
 dgi->init();


 dgi->REGISTER_TYPE_NAME_RESOLUTION(QString);
 dgi->REGISTER_TYPE_NAME_RESOLUTION(Test);

 dgi->REGISTER_TYPE(Test)
   .default_object_layout()
   .set_stage_encoder(&Test::encode_wg_stage_values);
 
 DgDb_Type* testt = dgi->get_type_by_name("Test");

 std::function<void(void*, QByteArray& qba, 
   WG_Stage_Value::Callback_type cb)> fn = testt->stage_encoder();

 QMap<u4, WG_Stage_Value> svals;

 WG_Stage_Value::Callback_type cb = [dgi, &svals](u4 u, WG_Stage_Value* v)
 {
  svals[u] = *v;
 };

 dgi->REGISTER_TYPE_NAME_RESOLUTION_2_1(QVector ,u1);

 dgi->build_default_types();


 QString* qs = new QString("OK");
 DgDb_Node* dgn = dgi->add(qs);

 Test* test = new Test{"Critique of Pure Reason", "Immanuel Kant", 777, 
   QDate(1787, 4, 23), QTime(11,47,22,888)};
 QByteArray qba;
 fn(test, qba, cb);

 Test* dtest;
 Test* dtest1;
 void* rec = dgi->new_wg_record(qba, svals);

 dgi->parse_wg_record(rec, [&dtest](const QByteArray& qba, 
   QMap<u4, WG_Stage_Value>& qm, WG_Stage_Queue& sq)
 {
  dtest = new Test;

  QDataStream qds(qba);
  qds >> qm[1](&dtest->title);
  qds >> dtest->author;
  qds >> qm[2](&dtest->num);
  qds >> qm[3](&dtest->publication_date);  
  qds >> qm[4](&dtest->test_time);  

  QStringList* nn = new QStringList;

  qds >> qm[5](nn);  

  sq = {&dtest->title, &dtest->num, 
    &dtest->publication_date, &dtest->test_time, nn};
  
  sq << [](QQueue<void*> qq)
  {
   QString* s = (QString*) qq.dequeue();
   u2* uu = (u2*) qq.dequeue();
   QDate* qd = (QDate*) qq.dequeue();
   QTime* qtm = (QTime*) qq.dequeue();
   QStringList* qsl = (QStringList*) qq.dequeue();
   qDebug() << *qsl;
  };
 });

 dgi->parse_wg_record(rec, [&dtest1](const QByteArray& qba, 
   QMap<u4, WG_Stage_Value>& qm, WG_Stage_Queue& sq)
 {
  dtest1 = new Test;

  QDataStream qds(qba);
  QString* str = new QString;
  QString* str1 = new QString;
  QDate* qd = new QDate;
  QTime* qtm = new QTime;
  QStringList* qsl = new QStringList;

  u2* num = new u2;
  qds >> qm[1](str);
  qds >> *str1;
  qds >> qm[2](num);
  qds >> qm[3](qd);
  qds >> qm[4](qtm);
  qds >> qm[5](qsl);

  sq = {dtest1, str, str1, num, qd, qtm, qsl};
  sq << stage_queue_memfnptr<Test>(&Test::read_stage_queue);
 });

 qDebug() << dtest1->title; 
 qDebug() << dtest1->author;
 qDebug() << dtest1->num;  
 qDebug() << dtest1->publication_date;  
 qDebug() << dtest1->test_time;  


 DgDb_Node* dgn1 = dgi->add(test);

 DgDb_Node* dgn2 = dgi->add(new QVector<u1> {4, 44, 64});
 
 DgDb_Type* ty_u1 = dgi->get_type_by_name("u1");

 return 0;
}


