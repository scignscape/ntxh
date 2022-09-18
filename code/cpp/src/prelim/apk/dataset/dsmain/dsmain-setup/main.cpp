
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>
#include <QFile>


// #include "ngml-sdi/ngml-sdi-document.h"

#include <QDir>
#include <QDebug>

#include <QCommandLineParser>

#include <QIcon>



#include "dsmain/dsm-sdi-document.h"

//#include "dgh-sdi/dgh-sdi-document.h"

#include "dsmain/dataset.h"
USING_KANS(DSM)


#include "get-cmdl.h"
USING_KANS(Util)

#include "textio.h"
USING_KANS(TextIO)


int main(int argc, char **argv)
{

 QString paper_name;

 QStringList cmds = get_cmdl(argc, argv);

 if(cmds.size() >= 3)
 {
  paper_name = cmds.at(2);
 }
 else
 {
  paper_name = "ctg";
  // paper_name = "icg";
  // paper_name = "itm";
 }

 // //  Here in case need to override the cmdline ...
 // paper_name = "ctg";
 // paper_name = "icg";
 // paper_name = "itm";

 QString dsfolder = QString(DEFAULT_DATASET_FOLDER "/%1").arg(paper_name);

 // // put these in the dataset folder if they're not already ...
 QString _mergefile = QString(DEFAULT_SDI_FOLDER "/%1/sdi-merge.ntxh").arg(paper_name);
 QString _samplesfile = QString(DEFAULT_SDI_FOLDER "/%1/out/%1.ntxh").arg(paper_name);
 QString _pdffile = QString(DEFAULT_SDI_FOLDER "/%1/out/%1.pdf").arg(paper_name);
 QString _ppcfile = QString(DEFAULT_SDI_FOLDER "/%1/src/ppc.txt").arg(paper_name);


 QDir qd(dsfolder);

 if(!qd.exists("sdi-merge.ntxh"))
   copy_file_to_folder(_mergefile, dsfolder);

 if(!qd.exists("samples.ntxh"))
   copy_file_to_folder_with_rename(_samplesfile, dsfolder, "samples");

 if(!qd.exists("ppc.txt"))
   copy_file_to_folder(_ppcfile, dsfolder);

 if(!qd.exists("main.pdf"))
   copy_binary_file_to_folder_with_rename(_pdffile, dsfolder, "main");


 Dataset ds(dsfolder);

 ds.load_from_folder();

 qDebug() << "Dataset: " << ds.samples()->size() << " samples in "
   << ds.groups()->size() << " groups.";

 if(cmds.size() >= 4)
 {
  QString flag = cmds.at(3);
  if(flag == "-s")
  {
   // // save markdown
   ds.save_as_markdown(QString(ROOT_FOLDER "/documents/markdown/%1.md").arg(paper_name));
   return 0;
  }
 }

}

