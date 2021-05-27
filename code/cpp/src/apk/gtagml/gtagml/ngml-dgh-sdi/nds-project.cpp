
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nds-project.h"

#include "dgh-sdi/dgh-sdi-paragraph.h"
#include "dgh-sdi/dgh-sdi-sentence.h"

#include "ngml-sdi/ngml-sdi-document.h"


USING_KANS(NGML)


#include <QDebug>
#include <QDir>


NDS_Project::NDS_Project()
  :  ngml_(nullptr), dgh_(nullptr)
{

}

NDS_Project::NDS_Project(QString paper_short_name, QString paper_root_folder, QString paper_setup_folder)
  :  paper_short_name_(paper_short_name), paper_root_folder_(paper_root_folder),
     paper_setup_folder_(paper_setup_folder), ngml_(nullptr), dgh_(nullptr)
{

}

void NDS_Project::init_ngml_document()
{
 ngml_ = new NGML_SDI_Document(paper_sdi_file_, paper_setup_folder_);
 ngml_->load_prelatex_files(prelatex_files_);
 ngml_->parse();
 ngml_->merge_dgh();
}


QMap<QString, u2> NDS_Project::locate_files()
{
 QFileInfo qfi(QString("%1/%2.sdi.ntxh").arg(paper_short_name_).arg(paper_root_folder_));
 if(qfi.exists())
   paper_sdi_file_ = qfi.absoluteFilePath();

 QDir qd(paper_setup_folder_);
 if(!qd.cd("sdi"))
   qd.cd("sdi-prelatex");

 QStringList qsl = qd.entryList(QDir::Files);

 for(QString file : qsl)
 {
  if(file.endsWith("sdi-prelatex.ntxh"))
    prelatex_files_.push_back(qd.absoluteFilePath(file));

  else if(file.endsWith("marks-summary.txt"))
    marks_files_.push_back(qd.absoluteFilePath(file));

  else if(file.endsWith("htxn.txt"))
    htxn_files_.push_back(qd.absoluteFilePath(file));

 }

 return {{"prelatex", prelatex_files_.size()},
   {"marks", marks_files_.size()},
   {"htxn", htxn_files_.size()}
  };
}



