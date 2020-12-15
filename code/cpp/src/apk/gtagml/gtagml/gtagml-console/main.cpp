
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include <QFileInfo>

//#include <QFileDialog>


#include "gtagml/kernel/document/gtagml-document.h"
#include "get-cmdl.h"

#include "gtagml/output/gtagml-output-latex.h"
#include "gtagml/output/gtagml-output-blocks.h"
#include "gtagml/output/gtagml-output-sdi-infoset.h"


#include "gtagml/kernel/document/gtagml-folder.h"



#include "gh/gh-block-writer.h"

#include "sdi/gh-sdi-document.h"

#include "textio.h"

USING_KANS(GTagML)
USING_KANS(Util)
USING_KANS(SDI)
USING_KANS(TextIO)

void process_gtagml_file(QString path)
{
 qDebug() << "Processing file: " << path;

// GTagML_Document gdoc;
// gdoc.load_and_parse(path);

// GTagML_Output_Blocks gob(gdoc);
// gob.init_standard_8bit();
// gob.export_blocks(); //(path + ".");


// GTagML_Output_Latex gol(gdoc);
// gol.export_latex(path + ".tex");

 GTagML_Document* gdoc = new GTagML_Document;
 gdoc->load_and_parse(path);

 GH_Block_Writer* blw = new GH_Block_Writer;

 QString divert;
 QTextStream qts(&divert);
 gdoc->set_divert(&qts);

 GTagML_Output_Blocks* gob = new GTagML_Output_Blocks(*gdoc, blw);
 gob->init_standard_8bit();
 gob->export_blocks(); //(path + ".");

 GTagML_Output_SDI_Infoset* gsi = new GTagML_Output_SDI_Infoset(*gdoc, blw);


 //goi->init_standard_8bit();
 gsi->export_infoset(path + ".info.txt"); // export_blocks(); //(path + ".");

 QString cpy = gsi->copy_path();

 GH_SDI_Document* gsd = gsi->sdi_document();

 QString ffolder = make_folder_from_file_name(path, DEFAULT_SDI_FOLDER);

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
  QString cp = copy_file_to_folder(path + ".tex", cpy);
  qDebug() << "Copied " << path + ".tex" << " to " << cp;

  cp = copy_file_to_folder(mark_path, cpy);
  qDebug() << "Copied " << mark_path << " to " << cp;
 }

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



int main(int argc, char *argv[])
{
 QString folder;// = cmdl.size() > 2? cmdl[2]: DEFAULT_SDI_FOLDER;
 QString file;// = cmdl.size() > 3? cmdl[3]: DEFAULT_SDI_FOLDER
 QString manfolder;

 QStringList cmdl = get_cmdl(argc, argv, 2, {
   {&folder, DEFAULT_GTAGML_FOLDER "/dg/ctg/src"},
   {&file, DEFAULT_GTAGML_FOLDER "/dg/t1/t1.gt"},
   {&manfolder, {}}
   });

//? folder = "/home/.../ntxh-ngml/ar/htxn/sdi-test/t9";
//? file = "/home/.../ntxh-ngml/ar/htxn/sdi-test/t9/t9.ngml";

 qDebug() << "Folder: " << folder << ", File: " << file;
 qDebug() << "ManFolder: " << manfolder;

 // file.clear();

 if(manfolder.isEmpty())
 {
  if(file.isEmpty())
  {
   GTagML_Folder fld(folder);
   fld.convert_all_files( &process_gtagml_file );

   // process whole folder ...
//   NGML_Folder fld(folder);
//   fld.convert_to_latex();
  }
  else
    process_gtagml_file(file);
 }
 else
 {
//  NGML_Folder fld(folder, file, manfolder);
//  fld.convert_to_latex(&process_ngml_file);
 }
 return 0;
}

