
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

#include <QMessageBox>


#include "dsmain/dsm-sdi-document.h"

#include "dgh-sdi/dgh-sdi-document.h"

#include "dsmain/dataset.h"

#include "dsmain/dataset-environment.h"

#include "get-cmdl.h"
USING_KANS(Util)

#include "ScignStage-ling/ScignStage-ling-dialog.h"

#ifdef USING_XPDF
#include "ScignStage-ling/xpdf-bridge.h"
#endif // USING_XPDF


#ifdef USING_KPH
#include "phaon-ir/phr-code-model.h"
#include "phaon-lib/phr-runner.h"
#include "phr-direct-eval/phr-direct-eval.h"
#include "phaon-ir/table/phr-symbol-scope.h"
#include "phaon-ir/table/phr-channel-group-table.h"
#include "phaon-ir/scopes/phr-runtime-scope.h"
#include "phaon-ir/scopes/phr-scope-system.h"
extern void init_test_functions(PhaonIR& phr, PHR_Code_Model& pcm,
  PHR_Channel_Group_Table& table, PHR_Symbol_Scope& pss);
#endif // USING_KPH


#ifdef USING_LEXPAIR
#include "lexpair/lexpair-dialog.h"
#endif // USING_LEXPAIR


#ifdef USING_CONFIG_DIALOG
#include "config-dialog/config-dialog.h"
#include "application-model/application-config-model.h"
#endif

#ifdef USING_RO
#include "ro-info/ro-info.h"
#endif // USING_RO

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


#ifdef USING_CONFIG_DIALOG
void launch_config_dialog(Config_Dialog*& dlg, QWidget* parent)
{
 if(!dlg)
 {
  dlg = new Config_Dialog(parent);
 }

 dlg->set_reset_callback([]()
 {
  Application_Config_Model::reset(
  {
   DEFINES_SRC_FOLDER "/UNIBUILD-custom_defines.h",
   CHOICES_PRI_FOLDER "/UNIBUILD-custom_choices.pri",
   UNIBUILD_PRI_FOLDER "/build-custom.pro",
   CUSTOM_LIBS_PRI_FOLDER "/_xpdf.pri",
   CUSTOM_LIBS_PRI_FOLDER "/_kph.pri",
   CUSTOM_LIBS_PRI_FOLDER "/_ss3d.pri",
  }, ".reset");
 });

 dlg->set_proceed_callback([&dlg](QString qs)
 {
  qDebug() << qs;

  Application_Config_Model acm;
  acm.parse_config_code(qs);
  {
   QString result;
   QString f = acm.insert_to_defines(DEFINES_SRC_FOLDER "/UNIBUILD-custom_defines.h", result);
   save_file(f, result);
  }

  {
   QString result;
   QString f = acm.insert_to_choices(CHOICES_PRI_FOLDER "/UNIBUILD-custom_choices.pri", result);
   save_file(f, result);
  }

  {
   QString result;
   QString f = acm.insert_to_unibuild(UNIBUILD_PRI_FOLDER "/build-custom.pro", result);
   save_file(f, result);
  }

  {
   QMap<QString, QString> result;
   QMap<QString, QString> files {{
     { "xpdf", CUSTOM_LIBS_PRI_FOLDER "/_xpdf.pri" },
     { "kph", CUSTOM_LIBS_PRI_FOLDER "/_kph.pri" },
     { "ss3d", CUSTOM_LIBS_PRI_FOLDER "/_ss3d.pri" }
    }};
   acm.insert_to_custom_libs(files, result);

   QMapIterator<QString, QString> it(result);

   while(it.hasNext())
   {
    it.next();
    save_file(it.key(), it.value());
   }
  }

  dlg->register_proceed_completed(qs);
 });

 dlg->show();
}
#endif // USING_CONFIG_DIALOG

void ro_info()
{
 QString message;
 QString detailed;
#ifdef USING_RO
 static RO_Info* ro = new RO_Info([](RO_Info& ro)
 {
  #include "ro.h"
 });
 message = "Check the ro-info project for more detailed "
           "Research Object info.  Click \"Show Details\" for a brief summary.";
 detailed  = ro->get_summary();
#else
 message = R"(
RO Info is not compiled in this build setting.
Try "build_quick" or loading the ro-info project
directly as a Qt project to examine this info in more detail.
)";
#endif

 QMessageBox* qmb = new QMessageBox;
 qmb->setAttribute(Qt::WA_DeleteOnClose);
 qmb->setText(message);
 qmb->setIcon(QMessageBox::Information);
 qmb->setWindowTitle("Research Object Information");
 if(!detailed.isEmpty())
   qmb->setDetailedText(detailed);
 qmb->addButton("Ok", QMessageBox::YesRole);
 qmb->open();
}

int main(int argc, char **argv)
{

 QStringList cmds = get_cmdl(argc, argv);

 Dataset_Environment dsenv(cmds, "ctg");

 QString paper_name = dsenv.current_paper_name();
 dsenv.set_default_dataset_folder(DEFAULT_DATASET_FOLDER);
 dsenv.set_default_sdi_folder(DEFAULT_SDI_FOLDER);

 dsenv.init_dsfolder();

 QString dsfolder = dsenv.current_dataset_folder();

 Dataset ds(dsfolder);

 ds.load_from_folder();

 if(dsenv.check_setup_only())
 {
  ds.save_as_markdown(QString(ROOT_FOLDER "/documents/markdown/%1.ctg").arg(paper_name));
  return 0;
 }

 QApplication qapp(argc, argv);
 qapp.setWindowIcon(QIcon(DEFAULT_ICON_FOLDER "/app-icon.png"));



 //?ds.load_from_file()DEFAULT_NTXH_FOLDER  "/ctg.ngml.ntxh");

 //?ds.set_pdf_path(DEFAULT_NTXH_FOLDER  "/main.pdf");


#ifdef USING_XPDF
 XPDF_Bridge xpdf_bridge(argc, argv);
 ScignStage_Ling_Dialog dlg (&xpdf_bridge, &ds);
#else
 ScignStage_Ling_Dialog dlg (nullptr, &ds);
#endif

 dlg.setWindowFlags(dlg.windowFlags() & Qt::WindowStaysOnTopHint);

 dlg.set_publication_url("https://link.springer.com/article/10.1007/s10772-021-09817-z");

 dlg.set_ro_info_function(&ro_info);

 dlg.set_generate_markdown_function([](QString path, Dataset* ds)
 {
  ds->save_as_markdown(path);
 });

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

