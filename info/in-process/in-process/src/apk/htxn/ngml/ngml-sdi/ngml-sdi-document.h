
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef NGML_SDI_DOCUMENT__H
#define NGML_SDI_DOCUMENT__H

#include "global-types.h"


#include <QDebug>

#include <QTextStream>

#include "ntxh-parser/ntxh-document.h"

#include "kans.h"

KANS_CLASS_DECLARE(HGDMCore ,NTXH_Graph)

USING_KANS(HGDMCore)

#include "rzns.h"

//class hypernode_type;
class NGML_SDI_Page;

class NGML_SDI_Document
{
 QString path_;
 QString folder_;
 u8 global_base_line_skip_;// = 12

 QVector<NGML_SDI_Page*> pages_;

 QMap<QPair<QString, u4>, void*> open_elements_;

 QString* unzip_folder_;

 QString review_file_path_;

 QMap<QChar, QVector<u4>> review_;

 QString zip_path_;
 QString copy_path_;
 QString unzip_test_path_;

 QStringList review_lines_;


public:
 
 NGML_SDI_Document(QString path, QString folder);

 ACCESSORS(QString ,zip_path)
 ACCESSORS(QString ,copy_path)
 ACCESSORS(QString ,unzip_test_path)

 QMap<QChar, QVector<u4>>& review() { return review_; }

 ACCESSORS(u8 ,global_base_line_skip)

 void load_review_file(QString path);

 void parse();

 void parse_paragraph_start_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);
 void parse_paragraph_end_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);

 void parse_sentence_start_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);
 void parse_sentence_end_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);

 void parse_element_start_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);
 void parse_element_end_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);


 void parse_info_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);

 NGML_SDI_Page* get_page(u4 page);
 void output_pages();

 NGML_SDI_Page* check_read_page(QString zip_file_path, 
   QString unzip_path, QString unzip_folder_name, u4 page_number);

 void check_unzip_folder(QString zip_file_path, 
  QString unzip_path, QString unzip_folder_name);

};


#endif // NGML_SDI_DOCUMENT__H
