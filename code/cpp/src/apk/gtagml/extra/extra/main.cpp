
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include <QDirIterator>

#include "test-class.h"

#include "textio.h"
USING_KANS(TextIO)


int main1(int argc, char *argv[])
{
 Test_Class tc("OK");
 qDebug() << tc.text();
 tc.test_method(ROOT_FOLDER "/dev/extra", 79, 81);
 tc.test_cuo();
 return 0;
}

void get_files(QString paper_name, QMap<QString, QString>& result)
{
 QString folder = ROOT_FOLDER "/../dev/documents/" + paper_name + "/src";

 QDirIterator qdi(folder, {"*.gt"});
 while(qdi.hasNext())
 {
  qdi.next();
  QString fp = qdi.filePath();
  QFileInfo qfi(fp);
  if(qfi.fileName().startsWith("section"))
  {
   QString tail;
   if(qfi.fileName().length() == 12)
     tail = qfi.fileName().mid(8, 1);
   int sectno = qfi.fileName().midRef(7, 1).toInt();
   result[QString("%1-%2%3").arg(paper_name).arg(sectno).arg(tail)] = fp;
  }
 }

}

int main(int argc, char *argv[])
{
 // //  Pull all the `swl tag-commands

 QMap<QString, QString> files;

 get_files("ctg", files);
 get_files("icg", files);
 get_files("itm", files);

 qDebug() << files;

 QString all_swl = R"(
;;--

  This file is automatically generated by extracting
  all "swl" and "udref" tag-commands from each .gt
  file used to generate the essays from which the
  data set is compiled.  The main purpose of this
  file is to document notation for different facets
  of language-sample annotations and metadata.

  While the GTagML compiler can parse this file
  and produce TeX output, the resulting code
  by itself would not be able to generate
  a usable PDF file (for example).

--;;
)";

 QMapIterator<QString, QString> it(files);

 while(it.hasNext())
 {
  it.next();

  QString sect = it.key();
  sect.replace("-", " (section ");
  sect += ")";

  all_swl += "\n\n ;;- __________ \n ;;- From file: " + sect + "\n ;;- __________ \n\n";

  QString text = load_file(it.value());

  int index = 0;
  int last = 0;
  int udr = 0;
  while(last != -1)
  {
   index = text.indexOf("`swl", last);
   if(index == -1)
     break;
   last = text.indexOf(";;", index);

   QString swl = text.mid(index, last - index + 3);

   // // now look for a udref
   udr = text.indexOf("`udref", last);
   if(udr != -1)
   {
    // // 10 here is a rough number, just want to be
     //   sure only to match a udref immediately after
     //   the relevant swl ...
    if(udr < last + 10)
    {
     last = text.indexOf(";;", udr);
     if(!swl.endsWith("\n"))
       swl += "\n";
     swl += text.mid(udr, last - udr + 3);
    }
   }

   if(!swl.endsWith("\n"))
     all_swl += "\n";

   all_swl += "\n" + swl;
  }
 }

 save_file(ROOT_FOLDER "/documents/all-samples.gt", all_swl);

}
