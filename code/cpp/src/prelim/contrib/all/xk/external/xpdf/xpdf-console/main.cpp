

#include "xpdf/dhax/dhax-annotation-editor.h"

#include "xpdf/dhax/pdf-comment-dialog.h"


#include <QDirIterator>
#include <QDebug>

#include <QFile>

#include "textio.h"

#include <map>

USING_KANS(TextIO)

//qDebug() << ed->comment;
//if (!tikzfile.open(QIODevice::Append | QIODevice::Text))
// continue;
//QTextStream outstream(&tikzfile);
//outstream << QString("\n\\annoteNode{%1}{%2}").arg(ed->edit).arg(ed->first_edit);
//tikzfile.close();

int main6(int argc, char *argv[])
{
// std::map<QPair<int, int>, QPair<int, QPair<int, int>>> map;
// QString tikz_key = ROOT_FOLDER "/../dev/dhax-tikz/ch9/key.txt";
// setup_map(map, tikz_key);

 QString tikz_path = ROOT_FOLDER "/../dev/dhax-tikz/ch9/pages";
 QString pcd_path = ROOT_FOLDER "/../dev/dhax-tikz/ch9/pcd.txt";

 QVector<PDF_Comment_Data*> pcds;

 init_pcds(pcd_path, pcds);

 PDF_Comment_Data* pcd1 = pcds.first();

 qDebug() << pcd1->text;

}

int main5(int argc, char *argv[])
{
 //QMap<QPair<int, int>, QPair<int, int>> map;

 std::map<QPair<int, int>, QPair<int, QPair<int, int>>> map;

 QString tikz_key = ROOT_FOLDER "/../dev/dhax-tikz/ch9/key.txt";

 setup_map(map, tikz_key);

 QString dir_path = ROOT_FOLDER "/../dev/dhax-edits/ch9/pages";
 //return xpdf_main(argc, argv);

 QString tikz_path = ROOT_FOLDER "/../dev/dhax-tikz/ch9/pages";
 QString pcd_path = ROOT_FOLDER "/../dev/dhax-tikz/ch9/pcd.txt";

 QVector<DHAX_Annotation_Editor::Edit_Data*> edits;

 get_all_edits(dir_path, edits);

 int index = 0;

 DHAX_Annotation_Editor::Edit_Data* ed = edits.at(index);

 QApplication qapp(argc, argv);

 PDF_Comment_Dialog* pcd = new PDF_Comment_Dialog(&map, ed, index + 1);


 pcd->connect(pcd, &PDF_Comment_Dialog::ok_next_requested,
    [pcd_path, &index, &edits](PDF_Comment_Dialog* pcd)
 {
  register_new_pcd(pcd_path, *pcd->current_data());
  ++index;
  if(index == edits.size())
    pcd->close();
  DHAX_Annotation_Editor::Edit_Data* ed = edits.at(index);
  pcd->update_edit_data(ed, index + 1);
 });


 pcd->connect(pcd, &PDF_Comment_Dialog::cancel_requested,
    [&qapp](PDF_Comment_Dialog* pcd)
 {
  pcd->close();
//  qapp.closeAllWindows();
//  qapp.quit();
  //qapp.exit();
 });


 pcd->connect(pcd, &PDF_Comment_Dialog::apply_requested,
    [pcd_path](PDF_Comment_Dialog* pcd)
 {
  register_new_pcd(pcd_path, *pcd->current_data());
 });


// pcd->connect(pcd, &QDialog::finished,
//    [&qapp](PDF_Comment_Dialog* pcd)
// {
//  pcd->close();
//  qapp.exit();
// });

 pcd->exec();

 qapp.exec();

}

// QPair<int, int> testpr = {1, 19};
// QPair<int, int> testpr = {1, 38};

// QVector<QPair<int, int>> pairs {
//   {1, 19},
//   {1, 38},
//   {2, 20},
//   {2, 28},
//   {2, 32},
//   {2, 46},
// };

// for(QPair<int, int> testpr: pairs)
// {
//  test_map(map, testpr);
// }


 //QVector<>


// qDebug() << "target.lower_count = " << target.lower_count;
// qDebug() << "target.upper_count = " << target.upper_count;

// qDebug() << "target.lower_key = " << target.lower_key;
// qDebug() << "target.lower_value = " << target.lower_value;

// qDebug() << "target.upper_key = " << target.upper_key;
// qDebug() << "target.upper_value = " << target.upper_value;

// }

int main2(int argc, char *argv[])
{
 QString tikz_key = ROOT_FOLDER "/../dev/dhax-tikz/ch9/key.txt";

 QFile tikzfile(tikz_key);

 if(!tikzfile.open(QIODevice::WriteOnly | QIODevice::Text))
  return 0;

 QTextStream outstream(&tikzfile);

 for(int  p = 1; p <= 38; ++p)
 {
  outstream << QString("%1   1   ..\n").arg(p, 2);
  outstream << QString("%1  45   ..\n").arg(p, 2);
 }

// for(int  p = 1; p <= 22; ++p)
// {
//  for(int i = 1; i <= 60; ++i)
//  {
//   int padj = 0;
////   int padj = (i * 1.5) + 12;
//   int sp = padj / 90;
//   int sl = padj;
//   outstream << QString("%1 %2     %3 %4\n").arg(p, 2).arg(i, 2).arg(sp, 2).arg(sl, 2);
//  }
// }

}


int main1(int argc, char *argv[])
{
 QString dir_path = ROOT_FOLDER "/../dev/dhax-edits/ch9/pages";
 //return xpdf_main(argc, argv);

 QString tikz_path = ROOT_FOLDER "/../dev/dhax-tikz/ch9/pages";

 QFile tikzfile(tikz_path + "/tikz.tex");



 QDirIterator qdi(dir_path);
 while (qdi.hasNext())
 {
  QString path = qdi.next();
  QFileInfo qfi(path);
  QString bn = qfi.baseName();
  if(bn.isEmpty())
   continue;
  QChar first = bn.at(0);
  if(first.isDigit())
  {
   QString text = load_file(path);
   int i = text.indexOf("%%DATA");
   if(i == -1)
     continue;
   QByteArray qba = QByteArray::fromBase64(text.midRef(i + 7).toLatin1());
   DHAX_Annotation_Editor::Edit_Data* ed = DHAX_Annotation_Editor::read_edit_data(qba);
   qDebug() << ed->comment;

   if (!tikzfile.open(QIODevice::Append | QIODevice::Text))
    continue;
   QTextStream outstream(&tikzfile);
   outstream << QString("\n\\annoteNode{%1}{%2}").arg(ed->edit).arg(ed->first_edit);
   tikzfile.close();
  }

 }

}




extern int xpdf_main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
 return xpdf_main(argc, argv);
}

/*
 *
 *
 *
 *
 *
 * */

#ifdef HIDE
#ifdef _WIN32
int CALLBACK WinMain(HINSTANCE hIstance, HINSTANCE hPrevInstance,
       LPSTR lpCmdLine, int nCmdShow) {
  wchar_t **args;
  int argc, i, n, ret;

  if (!(args = CommandLineToArgvW(GetCommandLineW(), &argc)) ||
      argc < 0) {
    return -1;
  }
  char **argv = (char  **)gmallocn(argc + 1, sizeof(char *));
  for (i = 0; i < argc; ++i) {
    n = WideCharToMultiByte(CP_ACP, 0, args[i], -1, NULL, 0, NULL, NULL);
    argv[i] = (char *)gmalloc(n);
    WideCharToMultiByte(CP_ACP, 0, args[i], -1, argv[i], n, NULL, NULL);
  }
  argv[argc] = NULL;
  LocalFree(args);
  ret = xpdf_main(argc, argv);
  for (i = 0; i < argc; ++i) {
    gfree(argv[i]);
  }
  gfree(argv);
  return ret;
}
#endif
#endif // HIDE

