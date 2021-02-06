
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NGML_LOADER__H
#define NGML_LOADER__H

#include "global-types.h"


#include <QDebug>

#include <QMap>

#include "kans.h"

#include "accessors.h"

class XpdfWidget;

class NGML_Loader
{
 struct element
 {
  int file_id;
  QString kind;
  int id;
  int rank_in_page;
  int pdf_end_x;
  int pdf_end_y;
  int start_index;
  int end_index;
 };

 struct file_job_info
 {
  QString job_name;
  int paragraph_count;
 };

 QVector<QMultiMap<QPair<int, int>, element>> elements_;

 QMap<int, file_job_info> file_job_info_;
  //
 QMap<QString, QVector<u1>> blocks_;

 QString pdf_file_;

 QString unzip_folder_;

 // QMap<QPair<int, int>, QString> welements_;

public:
 
 NGML_Loader();

 void load_pages(XpdfWidget* pdf, QString file_name);

 QPair<QString, QString> get_landmark_string(int page, int x, int y, QPair<int, int>& id,
   QPair<int, int>& start_index, QPair<int, int>& end_index, QString& file);

 QString read_sentence(QString landmark_file, u4 start_index, u4 end_index);

 void load_htxn_block(QString folder, QString file);

 void check_unzip_folder(QString zip_file_path);


};


#endif // NGML_LOADER__H
