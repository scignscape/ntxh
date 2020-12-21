
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>
#include <QFile>


#include "ngml-sdi/ngml-sdi-document.h"

#include <QDir>
#include <QDebug>

#include <QCommandLineParser>

#include <QDirIterator>

#include "dgh-sdi/dgh-sdi-document.h"

USING_KANS(DGH)


#include "textio.h"
#include "get-cmdl.h"

USING_KANS(TextIO)
USING_KANS(Util)


int main(int argc, char* argv[])
{
 QString folder, file, pfile, czfile;

 QStringList cmdl = get_cmdl(argc, argv, 2, {
   {&folder, DEFAULT_SDI_FOLDER},
   {&file, DEFAULT_SDI_FOLDER "/t1/t1.gt.sdi.ntxh"},
   {&pfile, DEFAULT_SDI_FOLDER "/t1/t1.gt.sdi-prelatex.ntxh"},
   {&czfile, {}}
   });

// qDebug() << QString(R"(
//Folder: %1
//File: %2
//PFile: %3
//czFile: %4
//   )").arg(folder).arg(file).arg(pfile).arg(czfile);

 folder = "/home/nlevisrael/gits/ntxh/wip-sebi/gtagml/ctg/gen/ctg";
 file = "/home/nlevisrael/gits/ntxh/wip-sebi/gtagml/ctg/gen/ctg/out/ctg.gt.sdi.ntxh";

 QString outfile = "/home/nlevisrael/gits/ntxh/wip-sebi/gtagml/ctg/gen/sdi-merge.ntxh";

 QStringList prelatex_files;
 QStringList marks_files;

 QString cs;

// QDir qd(folder);
// qd.cd("sdi");
// QStringList qsl = qd.entryList(QDir::Files);
// for(QString file : qsl)
// {
//  if(file.endsWith("sdi-prelatex.ntxh"))
//    prelatex_files.push_back(qd.absoluteFilePath(file));
//  else if(file.endsWith("marks-summay.txt"))
//    marks_files.push_back(qd.absoluteFilePath(file));
// }

// NGML_SDI_Document nsd(file, folder);

// nsd.load_prelatex_files(prelatex_files);

// nsd.parse();

// nsd.merge_dgh();

// nsd.review_dgh();

// nsd.output_dgh(outfile);

 DGH_SDI_Document dsd;
 dsd.load_from_ntxh(outfile);

 dsd.review_dgh();

#ifdef HIDE

 nsd.set_copy_path(czfile);

 nsd.parse();

 nsd.output_pages();
#endif // HIDE
 return 0;
}

