
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gtagml-module.h"

#include "module-ir.h"

#include <QDebug>

#include "gtagml/kernel/document/gtagml-document.h"

#include "gtagml/output/gtagml-output-latex.h"
#include "gtagml/output/gtagml-output-blocks.h"
#include "gtagml/output/gtagml-output-sdi-infoset.h"
#include "gtagml/kernel/document/gtagml-folder.h"
#include "gtagml/gh/gh-block-writer.h"
#include "gtagml/sdi/gh-sdi-document.h"

#include "gtagml/kernel/document/gtagml-project-info.h"


#include "textio.h"

USING_KANS(TextIO)

USING_KANS(DGH)
USING_KANS(SDI)


GTagML_Module::GTagML_Module()
{

}

void GTagML_Module::process_gtagml_file(QString path,
  GTagML_Project_Info* gpi, GTagML_Folder* fld)
{
 GTagML_Module* _this = (GTagML_Module*) gpi->user_data();
 QSet<QString>& flagset = _this->current_flagset_;
 QMap<QString, QString>& flagpairs = _this->current_flagpairs_;

 GTagML_Document* gdoc = new GTagML_Document(gpi);

 if(!gpi)
   gdoc->init_project_info();

 if(fld)
   gdoc->set_man_folder_path(fld->man_path());

 if(flagpairs.contains(":top-level"))
   gdoc->set_top_level_path(flagpairs[":top-level"]);

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
  gpi->set_gtagml_setup(setup);
  if(cpy.isEmpty())
    cpy = setup;
 }

 QString ffolder;

 if(gpi->gtagml_setup().isEmpty())
 {
  if(flagset.contains(":archive"))
    ffolder = make_folder_from_file_name(path, DEFAULT_SDI_FOLDER);
  else
    ffolder = make_inner_folder_from_file_name("sdi", path);
  //
 }
 else
   ffolder = make_folder_from_file_name(path, gpi->gtagml_setup());


 GH_SDI_Document* gsd = gsi->sdi_document();


 QString sdi_path = get_path_with_different_folder(path, ffolder);

 gsd->finalize_sentence_boundaries(*blw->current_main_text_block(), sdi_path + ".sdi-prelatex.ntxh");

 QString mark_path = gob->export_marks(); //(path + ".");
// gob->load_marks(mark_path);


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

 if(flagset.contains(":setup"))
 {
  if(gdoc->top_level_path().isEmpty())
  {
   prepend_template_to_file(cp, DEFAULT_SDI_FOLDER "/prepend",
   {
    { "%CONSOLE", ROOT_FOLDER "/code/cpp/qmake-console/projects/gtagml/ngml-sdi-console"},
    { "%FILE", cp },
    { "%SDI-FILE", sdi_path + ".sdi.ntxh" },
    { "%SDI-PFILE", sdi_path + ".sdi-prelatex.ntxh" }
   });
  }

  gsd->setup_folder_from_template(gdoc->local_file_name() + ".tex",
    DEFAULT_SDI_FOLDER "/template", ffolder, gdoc->top_level_path());

  if(!gdoc->top_level_path().isEmpty())
  {
   QString full = gdoc->get_full_top_level_path();
   QString cptl = copy_file_to_folder(full, ffolder);
   qDebug() << "Copied " << full << " to " << cptl;
  }
 }
 else if(!setup.isEmpty())
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

void GTagML_Module::compile_gt_file(QString args)
{
// QMap<QString, u1> flagset;
// QMap<QString, QString> flagpairs;
 QString file_path = read_args(args);
//           current_flagset_pos_,
//           flagpairs, fs);
// if(flagset.contains(":setup"))
// {
//  qDebug() << "setup = " << args;
// }

 GTagML_Project_Info gpi({});

 gpi.set_user_data(this);

 process_gtagml_file(file_path, &gpi, nullptr);
}

void GTagML_Module::compile_gt_folder(QString args)
{
 qDebug() << "args = " << args;
}

//  QMap<QString, u1>& flagset,
//  QMap<QString, QString>& flagpairs, QSet<QString>& fs
QString GTagML_Module::read_args(QString args) //, QString& main_arg //,
{
 QStringList qsl = args.simplified().split(' ');
 QString result = Module_IR::first_non_flag_arg(qsl,
   &current_flagset_pos_, &current_flagpairs_);

 QStringList keys = current_flagset_pos_.keys();

 current_flagset_ = QSet<QString>(keys.begin(), keys.end());

 //qDebug() << "args = " << args;
 return result;
}


void GTagML_Module::compile_gt_manuscript(QString args)
{
// QMap<QString, u1> flagset;
// QMap<QString, QString> flagpairs;
 QString file_path = read_args(args);

 // QSet<QString> fs;
 //, flagset, flagpairs, fs);

 QFileInfo qfi(file_path);
 QString suffix = qfi.suffix();

 QString folder = qfi.absolutePath();

 GTagML_Project_Info* gpi = new GTagML_Project_Info(file_path);

 if(suffix == "gt")
 {
  gpi->flags.manuscript_top_level_is_gt = true;
 }

 QString mt = current_flagpairs_.value(":manuscript");

 GTagML_Folder fld(folder, file_path, mt);

 fld.set_project_info(gpi);

 gpi->set_user_data(this);

 fld.convert_all_files( &GTagML_Module::process_gtagml_file );

 //qDebug() << "args = " << args;
}

void GTagML_Module::compile_gt_manuscript_file(QString args)
{
 qDebug() << "args = " << args;
}

