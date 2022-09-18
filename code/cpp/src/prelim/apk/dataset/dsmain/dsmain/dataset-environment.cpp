
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dataset-environment.h"

#include "dataset.h"


#include "language-sample.h"
#include "language-sample-group.h"

#include "qh-package/qh-pack-builder.h"
#include "qh-package/qh-pack-reader.h"

#include <QDataStream>

#include <QDir>

#include "textio.h"
USING_KANS(TextIO)


USING_KANS(DSM)


Dataset_Environment::Dataset_Environment(const QStringList& cmd_args, QString first_paper)
  :  cmd_args_(cmd_args)
{
 if(cmd_args_.size() >= 3)
 {
  current_paper_name_ = cmd_args_.at(2);
 }
 else
 {
  //
  current_paper_name_ = first_paper;
  // "ctg";
  // paper_name = "icg";
  // paper_name = "itm";
 }

 // //  Here in case need to override the cmdline ...
 // paper_name = "ctg";
 // paper_name = "icg";
 // paper_name = "itm";

 initial_paper_name_ = current_paper_name_;
}

Dataset_Environment* Dataset_Environment::_new(const QStringList& cmd_args,
  QString first_paper, u1 original_argc)
{
 return new Dataset_Environment(cmd_args, first_paper);
}


bool Dataset_Environment::check_setup_only()
{
 if(cmd_args_.size() >= 4)
 {
  QString flag = cmd_args_.at(3);
  return (flag == "-s");
 }
 return false;
}


void Dataset_Environment::init_dsfolder()
{
 current_dataset_folder_ = QString("%1/%2").arg(default_dataset_folder_).arg(current_paper_name_);

 // // put these in the dataset folder if they're not already ...
 QString _mergefile = QString("%1/%2/sdi-merge.ntxh").arg(default_sdi_folder_).arg(current_paper_name_);
 QString _samplesfile = QString("%1/%2/out/%2.ntxh").arg(default_sdi_folder_).arg(current_paper_name_);
 QString _pdffile = QString("%1/%2/out/%2.pdf").arg(default_sdi_folder_).arg(current_paper_name_);
 QString _ppcfile = QString("%1/%2/src/ppc.txt").arg(default_sdi_folder_).arg(current_paper_name_);


 QDir qd(current_dataset_folder_);

 if(!qd.exists("sdi-merge.ntxh"))
   copy_file_to_folder(_mergefile, current_dataset_folder_);

 if(!qd.exists("samples.ntxh"))
   copy_file_to_folder_with_rename(_samplesfile, current_dataset_folder_, "samples");

 if(!qd.exists("ppc.txt"))
   copy_file_to_folder(_ppcfile, current_dataset_folder_);

 if(!qd.exists("main.pdf"))
   copy_binary_file_to_folder_with_rename(_pdffile, current_dataset_folder_, "main");

}
