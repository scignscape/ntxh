
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
 QStringList cmdl = get_cmdl(argc, argv);

 //qDebug() << "cmdl " << cmdl;

 QString req = cmdl.size() > 1? cmdl[1]: "merge";
 if(req.startsWith('-'))
   req = req.mid(1);

 QString folder = cmdl.size() > 2? cmdl[2]: DEFAULT_SDI_FOLDER;
 QString file = cmdl.size() > 3? cmdl[3]: DEFAULT_SDI_FOLDER
   "/ngml-sdi/t1.ngml.sdi.ntxh";
 QString rfile = cmdl.size() > 4? cmdl[4]: DEFAULT_SDI_FOLDER
   "/ngml-sdi/t1.ngml.rev.txt";

 QString czfile = cmdl.size() > 5? cmdl[5]: QString();

 qDebug() << QString(R"(
Req: %1
Folder: %2
File: %3
RFile: %4
czFile: %5
   )").arg(req).arg(folder).arg(file).arg(rfile).arg(czfile);

#ifdef HIDE
 NGML_SDI_Document nsd(file, folder);
 nsd.load_review_file(rfile);

 nsd.set_copy_path(czfile);

 nsd.parse();

 nsd.output_pages();
#endif // HIDE
 return 0;
}

