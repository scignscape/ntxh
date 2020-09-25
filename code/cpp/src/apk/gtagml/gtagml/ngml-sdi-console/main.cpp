
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>
#include <QFile>


#include "ngml-sdi/ngml-sdi-document.h"

#include <QDir>
#include <QDebug>

#include <QCommandLineParser>


#include "textio.h"
#include "get-cmdl.h"

USING_KANS(TextIO)
USING_KANS(Util)

int main(int argc, char* argv[])
{
 QString folder, file, pfile, czfile;

 QStringList cmdl = get_cmdl(argc, argv, 2, {
   {&folder, DEFAULT_SDI_FOLDER},
   {&file, DEFAULT_SDI_FOLDER "/t1.gt.sdi.ntxh"},
   {&pfile, DEFAULT_SDI_FOLDER "/t1.gt.sdi-prelatex.ntxh"},
   {&czfile, {}}
   });

 qDebug() << QString(R"(
Folder: %1
File: %2
PFile: %3
czFile: %4
   )").arg(folder).arg(file).arg(pfile).arg(czfile);

 NGML_SDI_Document nsd(file, folder);
 nsd.load_prelatex_file(pfile);

 nsd.parse();

#ifdef HIDE

 nsd.set_copy_path(czfile);

 nsd.parse();

 nsd.output_pages();
#endif // HIDE
 return 0;
}

