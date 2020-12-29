
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

#include "textio.h"

USING_KANS(TextIO)

USING_KANS(DGH)
USING_KANS(SDI)


GTagML_Module::GTagML_Module()
{

}

void GTagML_Module::process_gtagml_file(QString path,
  QSet<QString> flagset, GTagML_Folder* fld)
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
 {
  if(flagset.contains(":archive"))
    ffolder = make_folder_from_file_name(path, DEFAULT_SDI_FOLDER);
  else
    ffolder = make_inner_folder_from_file_name("sdi", path);
  //
 }
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

void GTagML_Module::compile_gt_file(QString args)
{
 QStringList qsl = args.simplified().split(' ');
 QMap<QString, u1> flagset;
 QString file_path = Module_IR::first_non_flag_arg(qsl, &flagset);
 //qDebug() << "args = " << args;

 if(flagset.contains(":setup"))
 {
  qDebug() << "setup = " << args;
 }

 QStringList keys = flagset.keys();
 QSet<QString> fs(keys.begin(), keys.end());

 process_gtagml_file(file_path, fs, nullptr);
}

void GTagML_Module::compile_gt_folder(QString args)
{
 qDebug() << "args = " << args;
}

void GTagML_Module::compile_gt_manuscript(QString args)
{
 qDebug() << "args = " << args;
}

void GTagML_Module::compile_gt_manuscript_file(QString args)
{
 qDebug() << "args = " << args;
}

