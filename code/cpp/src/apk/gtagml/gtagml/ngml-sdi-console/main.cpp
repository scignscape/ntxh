
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
 QString folder, file, outfile, pfile, czfile;

// QStringList cmdl = get_cmdl(argc, argv, 2, {
//   {&folder, DEFAULT_SDI_FOLDER},
//   {&file, DEFAULT_SDI_FOLDER "/t1/t1.gt.sdi.ntxh"},
//   {&pfile, DEFAULT_SDI_FOLDER "/t1/t1.gt.sdi-prelatex.ntxh"},
//   {&czfile, {}}
//   });

 QStringList cmdl = get_cmdl(argc, argv, 2, {
   {&folder, DEFAULT_SDI_FOLDER "/src/setup"},
   {&file, DEFAULT_SDI_FOLDER "/src/setup/out/ctg.prep.sdi.ntxh"},
   {&outfile, DEFAULT_SDI_FOLDER "/sdi-merge.ntxh"},
   {&pfile, {}},
   {&czfile, {}}
   });

// folder = "/home/nlevisrael/gits/ntxh/wip-sebi/dev/documents/ctg/src/setup";
// file = "/home/nlevisrael/gits/ntxh/wip-sebi/dev/documents/ctg/src/setup/out/ctg.prep.sdi.ntxh";

// QString outfile = "/home/nlevisrael/gits/ntxh/wip-sebi/dev/documents/ctg/sdi-merge.ntxh";

 QStringList prelatex_files;
 QStringList marks_files;

 QString cs;

 QDir qd(folder);
 if(!qd.cd("sdi"))
   qd.cd("sdi-prelatex");
 QStringList qsl = qd.entryList(QDir::Files);
 for(QString file : qsl)
 {
  if(file.endsWith("sdi-prelatex.ntxh"))
    prelatex_files.push_back(qd.absoluteFilePath(file));

  else if(file.endsWith("marks-summary.txt"))
    marks_files.push_back(qd.absoluteFilePath(file));
 }

 NGML_SDI_Document nsd(file, folder);

 nsd.load_prelatex_files(prelatex_files);

 nsd.parse();

 nsd.merge_dgh();

 nsd.review_dgh();

 nsd.output_dgh(outfile);

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

