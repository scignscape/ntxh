
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dgh-sdi-repl-mainwindow.h"


#include "gtagml/kernel/document/gtagml-document.h"
#include "get-cmdl.h"

#include "gtagml/output/gtagml-output-latex.h"
#include "gtagml/output/gtagml-output-blocks.h"
#include "gtagml/output/gtagml-output-sdi-infoset.h"


#include "gtagml/kernel/document/gtagml-folder.h"



#include "gtagml/gh/gh-block-writer.h"

#include "gtagml/sdi/gh-sdi-document.h"

#include "dgh-module-ir/module-ir.h"

#include "textio.h"

USING_KANS(GTagML)
USING_KANS(Util)
USING_KANS(SDI)
USING_KANS(TextIO)

USING_KANS(DGH)


DGH_SDI_REPL_MainWindow::DGH_SDI_REPL_MainWindow()
{
 mir_ = new Module_IR;
// main_layout_ = new QVBoxLayout;

 main_text_edit_ = new QTextEdit(this);

 main_splitter_ = new QSplitter(Qt::Vertical, this);


 main_splitter_->addWidget(main_text_edit_);

 main_notebook_ = new QTabWidget(this);
 cmd_log_text_edit_ = new QTextEdit(this);
 http_log_text_edit_ = new QTextEdit(this);

 main_console_ = QImplConsole::getInstance(this);

 main_console_->set_cb([this](const QString& cmd, int* response, QString data)
 {
  QString line;
  if(cmd.endsWith(";."))
  {
   line = lines_acc_ + cmd + "\n";
   lines_acc_.clear();
  }
  else
  {
   lines_acc_ += cmd + "\n";
   return;
  }
  mir_->read_lines(line);
  mir_->run_lines();

//  qDebug() << "cmd = " << cmd;
//  QStringList qsl = cmd.simplified().split(' ');
//  QString cmd_str = qsl.takeFirst();
//  u2 cmd_code = command_list_.value(cmd_str);
//  if(cmd_code)
//  {
//   run_command(cmd_code, qsl);
//  }
 });

 main_notebook_->addTab(main_console_, "REPL");
 main_notebook_->addTab(cmd_log_text_edit_, "CMD Logs");
 main_notebook_->addTab(http_log_text_edit_, "HTTP Logs");

 main_splitter_->addWidget(main_notebook_);

// main_layout_->addWidget(main_splitter_);

// main_layout_->addWidget(button_box_);

// setLayout(main_layout_);

 setCentralWidget(main_splitter_);

 setMinimumWidth(600);

 init_command_list();

}

void DGH_SDI_REPL_MainWindow::init_command_list()
{
 command_list_ = {
  {"gt-compile-file", 1},
  {"gt-compile-folder", 2},
  {"gt-compile-manuscript", 3}
 };
}

void DGH_SDI_REPL_MainWindow::run_command(u2 cmd_code,
  const QStringList& qsl)
{
 switch(cmd_code)
 {
 case 1:
  {
   QString path = qsl.first();
   process_gtagml_file(path, nullptr);
  }

  break;

 case 2: qDebug() << "fld"; break;
 case 3: qDebug() << "man"; break;


 }
}


void DGH_SDI_REPL_MainWindow::process_gtagml_file(QString path, GTagML_Folder* fld)
{
 GTagML_Document* gdoc = new GTagML_Document;

 if(fld)
   gdoc->set_man_folder_path(fld->man_path());

 gdoc->load_and_parse(path);

 GH_Block_Writer* blw = new GH_Block_Writer;

// QString divert;
// QTextStream qts(&divert);
// gdoc->set_divert(&qts);

 GTagML_Output_Blocks* gob = new GTagML_Output_Blocks(*gdoc, blw);
 gob->init_standard_8bit();
 gob->export_blocks();

 GTagML_Output_SDI_Infoset* gsi = new GTagML_Output_SDI_Infoset(*gdoc, blw);

 QString fnc = gdoc->file_job_name();
 gsi->set_file_job_name(fnc);

 //goi->init_standard_8bit();
 gsi->export_infoset(path + ".info.txt"); // export_blocks(); //(path + ".");

 QString cpy = gsi->copy_path();
 QString setup = gsi->setup_path();

 if(!setup.isEmpty())
 {
  gtagml_setup_ = setup;
  if(cpy.isEmpty())
    cpy = setup;
 }

 QString ffolder;

 if(gtagml_setup_.isEmpty())
   ffolder = make_folder_from_file_name(path, DEFAULT_SDI_FOLDER);
 else
   ffolder = make_folder_from_file_name(path, gtagml_setup_);


 GH_SDI_Document* gsd = gsi->sdi_document();


 QString sdi_path = get_path_with_different_folder(path, ffolder);

 gsd->finalize_sentence_boundaries(*blw->current_main_text_block(), sdi_path + ".sdi-prelatex.ntxh");

 QString mark_path = gob->export_marks(); //(path + ".");
 gob->load_marks(mark_path);


 GTagML_Output_Latex* gol = new GTagML_Output_Latex(*gdoc, gsd);
 gol->export_latex(path + ".tex");

 QString cp = copy_file_to_folder(path + ".tex", ffolder);

 qDebug() << "Copied " << path + ".tex" << " to " << cp;

 if(!cpy.isEmpty())
 {
  QString cp;

  if(setup.isEmpty())
  {
   cp = copy_file_to_folder(path + ".tex", cpy);
   qDebug() << "Copied " << path + ".tex" << " to " << cp;
  }

  cpy += "/sdi";

  QDir sdi_dir(cpy);
  if(!sdi_dir.exists())
    if(sdi_dir.mkpath("."))
      qDebug() << "Made path: " << sdi_dir;

  cp = copy_file_to_folder(mark_path, cpy);
  qDebug() << "Copied " << mark_path << " to " << cp;

  cp = copy_file_to_folder(sdi_path + ".sdi-prelatex.ntxh", cpy);
  qDebug() << "Copied " << sdi_path + ".sdi-prelatex.ntxh" << " to " << cp;
 }


 if(!setup.isEmpty())
 {
  prepend_template_to_file(cp, DEFAULT_SDI_FOLDER "/prepend",
  {
   { "%CONSOLE", ROOT_FOLDER "/code/cpp/qmake-console/projects/gtagml/ngml-sdi-console"},
   { "%FILE", cp },
   { "%SDI-FILE", sdi_path + ".sdi.ntxh" },
   { "%SDI-PFILE", sdi_path + ".sdi-prelatex.ntxh" }
  });

  gsd->setup_folder_from_template(gdoc->local_file_name() + ".tex",
  DEFAULT_SDI_FOLDER "/template", ffolder);

 }
}


