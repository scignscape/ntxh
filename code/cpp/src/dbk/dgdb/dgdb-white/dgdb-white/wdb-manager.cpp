
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "wdb-manager.h"

#include "wdb-instance.h"

#include "dw-instance.h"

#include <QDebug>

#include "kans.h"
#include "textio.h"

//?#include "phaong/phaong.h"
//?#include "phaong/phaong-types.h"

#include "ntxh-parser/ntxh-document.h"


USING_KANS(TextIO)

extern "C" {
#include "whitedb/_whitedb.h"
}


USING_KANS(DGDB)


WDB_Manager::WDB_Manager(DW_Instance* dw_instance)
  :  dw_instance_(dw_instance), 
     max_num_code_(1000), default_mem_size_(0), current_white_(0)
{


}

WDB_Instance* WDB_Manager::get_current_white()
{
 if(!current_white_)
 {
  current_white_ = new_white();
 }
 return current_white_;
}

void WDB_Manager::update_ntxh()
{
 QString ntxh;
 to_ntxh(ntxh);
 save_file(db_root_folder_ + "/" + "manager.ntxh", ntxh);  
}

void WDB_Manager::to_ntxh(QString& result)
{
 QString dty; 
 QString dr;
 dw_instance_->to_ntxh(dty, dr);

 result = QString(R"(

%1

%2

&/

%3
 )").arg(dty).arg(WDB_Instance::static_to_ntxh()).arg(dr);

 for(WDB_Instance* white : whites_.values())
 {
  QString wr;
  white->to_ntxh(wr);
  result += "\n" + wr + "\n";
 }

 result += "/&\n\n";
}


void WDB_Manager::init_from_ntxh()
{
 NTXH_Document doc(db_root_folder_ + "/" + "manager.ntxh");
 doc.parse();

 typedef NTXH_Graph::hypernode_type hypernode_type;

 QVector<hypernode_type*>& hns = doc.top_level_hypernodes();

 QVectorIterator<hypernode_type*> it(hns);

 hypernode_type* hn = it.next();
 doc.graph()->get_sfs(hn, {1,2}, 
   [this](QVector<QPair<QString, void*>>& prs)
 {
  QString fld = prs[0].first;
  u1 code = prs[1].first.toInt();
  dw_instance_->init_from_ntxh(fld, code);
 });

 while(it.hasNext())
 {
  hypernode_type* hn = it.next();
  QString name;
  QVector<QDateTime> dts {{},{},{}}; 

  doc.graph()->get_sfsr(hn, {{1,4}}, 
  [&name, &dts, this](QVector<QPair<QString, void*>>& prs)
  {
   name = prs[0].first;
   std::transform(prs.begin() + 1, prs.end(), dts.begin(), 
     [](const QPair<QString, void*>& pr) -> QDateTime
     { 
      if(!pr.first.isEmpty())
        return QDateTime::fromString(pr.first);
     });
  });

  qDebug() << "Database Name: " << name;
  qDebug() << "Database Datetimes: " << dts;
 }
 
}


WDB_Instance* WDB_Manager::new_white(u2 num_code, n8 mem, QString name)
{
 if( (num_code == 0) && !dw_instance_->Config.flags.local_scratch_mode )
 {
  max_num_code_ += 100;
  num_code = max_num_code_;
 }
 if(mem == 0)
   mem = default_mem_size_;

 void* db;

 if(dw_instance_->Config.flags.local_scratch_mode)
   db = wg_attach_local_database(mem); 
 else if(dw_instance_->Config.flags.scratch_mode)
 {
  void* _db = wg_attach_existing_database(
    QString::number(num_code).toLatin1().data());
  if(_db)
  {
   int ok = wg_delete_database(QString::number(num_code).toLatin1().data());
   if(ok > 0)
   {
    qDebug() << "Failed to delete database: " << num_code;
    // // error ... throw something?
   }
  } 
  db = wg_attach_database(QString::number(num_code).toLatin1().data(), mem);    
 }
 else
   db = wg_attach_database(QString::number(num_code).toLatin1().data(), mem);

 WDB_Instance* result = new WDB_Instance(db, name);
 result->set_creation_datetime();

 whites_[num_code] = result;

 if(!name.isEmpty())
 {
  whites_by_name_[name] = result;
 }

 update_ntxh();

 return result; 
}

