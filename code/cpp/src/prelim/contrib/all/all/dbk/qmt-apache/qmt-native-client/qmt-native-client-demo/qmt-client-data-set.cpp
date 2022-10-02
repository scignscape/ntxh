
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qmt-client-data-set.h"

#include "lanternfly-data-set.h"

#include "global-types.h"

#include <QMessageBox>

#include <QDebug>

#include <QFile>

#include <QVector2D>



QMT_Client_Data_Set::QMT_Client_Data_Set(Lanternfly_Main_Window* main_window)
  :  main_window_(main_window)
{

}



QMT_Client_Data_Set_Base* QMT_Client_Data_Set::make_new_unattached_child_data_set()
{
 return new QMT_Client_Data_Set(main_window_);
}


void QMT_Client_Data_Set::prepare_ntxh_document(NTXH_Document& doc, QString file_path)
{

}

void QMT_Client_Data_Set::conclude_ntxh_document(NTXH_Document& doc, QString file_path)
{

}

void QMT_Client_Data_Set::read_ntxh_hypernode(NTXH_Graph& g, hypernode_type* h)
{
 if(h->type_descriptor().first == "Data_Set")
 {
  qDebug() << "Data_Set";
  g.get_sfsr(h, {{1, 2}}, [this](QVector<QPair<QString, void*>>& prs)
  {
   QString name_description = prs[0].first;
   if(name_description == "Lanternfly")
   {
    current_content_base_ = new Lanternfly_Data_Set;
   }
  });
 }

 else
 {
  current_content_base_->read_ntxh_hypernode(g, h);
 }

}

void QMT_Client_Data_Set::add_markings()
{
 current_content_base_->add_markings(*main_window_);
}
