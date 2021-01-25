
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

#include <QApplication>
#include <QTimer>
#include <QScreen>


#include "dsmain/dsm-sdi-document.h"

#include "dgh-sdi/dgh-sdi-document.h"

#include "dsmain/dataset.h"

#include "ScignStage-ling/ScignStage-ling-dialog.h"

#include "ScignStage-ling/xpdf-bridge.h"

#ifdef USING_LEXPAIR
#include "lexpair/lexpair-dialog.h"
#endif // USING_LEXPAIR

#include "textio.h"
//?#include "get-cmdl.h"

USING_KANS(TextIO)
//?USING_KANS(Util)


USING_KANS(DSM)
USING_KANS(DGH)


int main1(int argc, char* argv[])
{
// QString mergefile = "/home/nlevisrael/gits/ntxh/wip-sebi/gtagml/ctg/gen/sdi-merge.ntxh";

// QString mergefile = "/home/nlevisrael/gits/ntxh/wip-sebi/dev/documents/ctg/sdi-merge.ntxh";

// DGH_SDI_Document dsd;
// dsd.load_from_ntxh(mergefile);

// dsd.review_dgh();

 QString mergefile = DEFAULT_SDI_FOLDER "/sdi-merge.ntxh";
 QString samplesfile = DEFAULT_SDI_FOLDER "/out/ctg.ntxh";

 DSM_SDI_Document dsd;
 dsd.load_from_ntxh(samplesfile);

// dsd.review_dgh();

 return 0;
}


int main(int argc, char **argv)
{
 QApplication qapp(argc, argv);
 qapp.setWindowIcon(QIcon(DEFAULT_ICON_FOLDER "/app-icon.png"));

// QString paper_name = "icg";
//
 QString paper_name = "ctg";
// QString paper_name = "itm";

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

 //?ds.load_from_file()DEFAULT_NTXH_FOLDER  "/ctg.ngml.ntxh");

 //?ds.set_pdf_path(DEFAULT_NTXH_FOLDER  "/main.pdf");


#ifdef USING_XPDF
 XPDF_Bridge xpdf_bridge(argc, argv);
 ScignStage_Ling_Dialog dlg (&xpdf_bridge, &ds);
#else
 ScignStage_Ling_Dialog dlg (nullptr, &ds);
#endif

 dlg.set_replace_dataset_function([](QString path) -> Dataset*
 {
  QFileInfo qfi(path);
  Dataset* result = new Dataset(qfi.absolutePath());
  result->load_from_folder();

//  result->load_from_file(path);
//  if(result->groups().isEmpty())
//    return nullptr;
  return result;
 });

#ifdef USING_KPH
 dlg.set_phr_init_function([&dlg](PHR_Runner& phr, PHR_Symbol_Scope*& pss)
 {
  PHR_Code_Model& pcm = phr.get_pcm();
  pcm.set_origin(phr.origin());
  pcm.set_direct_eval_fn(&phr_direct_eval);
  PHR_Runtime_Scope* prs = new PHR_Runtime_Scope(nullptr);
  pss = new PHR_Symbol_Scope(prs);
  init_test_functions(*phr.get_pcm().phaon_ir(), pcm, phr.get_table(), *pss);
  pcm.scopes()->phr_scope_queue().push_front(prs);
 });
#endif

// Application_Model apm(&dlg);
// dlg.set_application_model(&apm);

#ifdef USING_LEXPAIR
 dlg.set_launch_lexpair_dialog_function([](QString s)
 {
  Lexpair_Dialog* dlg = new Lexpair_Dialog(Lexpair_Dialog::split(s), nullptr);
  dlg->show();
 });
#endif // USING_LEXPAIR

 dlg.set_screenshot_function([&dlg, &qapp]()
 {
  QScreen* screen = QGuiApplication::primaryScreen();
  if (!screen)
    return;
  QApplication::beep();
  int target_window_id  = dlg.winId();

  QTimer::singleShot(10000, [=]
  {
   QPixmap pixmap = screen->grabWindow(target_window_id );
   QString path = SCREENSHOTS_FOLDER "/ScignStage_Ling_Dialog.png";
   qDebug() << "Saving to path: " << path;

   QFile file(path);
   if(file.open(QIODevice::WriteOnly))
   {
    pixmap.save(&file, "PNG");
   }
  });
 });

#ifdef USING_CONFIG_DIALOG
 Config_Dialog* cdlg = nullptr;
 dlg.set_launch_config_function([&cdlg, &dlg]()
 {
  launch_config_dialog(cdlg, &dlg);
 });
#endif

 dlg.show();

 qapp.exec();

}

