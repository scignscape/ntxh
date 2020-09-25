
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "rz-ngml/kernel/document/rz-ngml-document.h"

//?#include "rz-ngml/output/rz-ngml-output-html.h"

#include "rz-ngml/output/rz-ngml-output-latex.h"
#include "rz-ngml/output/rz-ngml-output-htxn.h"
#include "rz-ngml/output/rz-ngml-output-infoset.h"

#include "rz-ngml/output/rz-ngml-output-xml.h"

#include "rz-ngml/output/rz-ngml-output-axfd.h"

//?
#include "rz-ngml/kernel/document/rz-ngml-folder.h"

#include "rzns.h"

#include <QStringList>

#include "get-cmdl.h"

USING_KANS(TextIO)



// //
//#include <QDomDocument>
//#include <QDomElement>
//#include <QDomNode>


USING_RZNS(NGML)

//#include <QApplication>
//#include <QFileDialog>
#include <QDebug>

void process_ngml_file(QString path)
{
 qDebug() << "Processing file: " << path; 

 NGML_Document ndoc;
 ndoc.load_and_parse(path);

//? HTXN_Document_8b* hxd = new HTXN_Document_8b;
 HTXN_Document_8b hxd;

 NGML_Output_HTXN noh(ndoc, &hxd);
 noh.export_htxne();

 HTXN_Infoset_8b infoset(&hxd);
 NGML_Output_Infoset noi(ndoc, &infoset);
 noi.set_htxn_document(&hxd);
 noi.set_ngml_output_htxn(&noh);
 noi.export_infoset(path + ".info.txt");

 NGML_Output_Latex nol(ndoc);
 nol.set_htxn_document(&hxd);
 nol.set_infoset(&noi);
 nol.export_latex(path + ".tex");

 noi.export_infoset_review(path + ".rev.txt");

 NGML_Output_XML nox(ndoc);
 nox.set_ngml_output_htxn(&noh);
 nox.set_htxn_document(&hxd);
 nox.export_xml(path + ".xml");

 NGML_Output_AXFD noa(ndoc, &infoset);
 //noa.set_ngml_output_htxn(&noh);
 //nox.set_htxn_document(&hxd);
 noa.export_axfd(path + ".axfd");

}

int main1(int argc, char* argv[])
{
 QStringList ngml_files;

 NGML_Folder nf(DEFAULT_NGML_DIRECTORY "/ctg");
 nf.get_ngml_files(ngml_files);
 
 for(const QString& f: ngml_files) 
 {
  qDebug() << "Processing file: " << f; 
  process_ngml_file(f);
 }

 return 0;
}

int main(int argc, char* argv[])
{
 QString folder;// = cmdl.size() > 2? cmdl[2]: DEFAULT_SDI_FOLDER;
 QString file;// = cmdl.size() > 3? cmdl[3]: DEFAULT_SDI_FOLDER
 QString manfolder;

 QStringList cmdl = get_cmdl(argc, argv, 2, {
   {&folder, DEFAULT_NGML_DIRECTORY},
   {&file, DEFAULT_NGML_DIRECTORY "/t1/t1.ngml"}, 
   {&manfolder, {}}
   });

//? folder = "/home/nlevisrael/hypergr/ntxh-ngml/ar/htxn/sdi-test/t9";
//? file = "/home/nlevisrael/hypergr/ntxh-ngml/ar/htxn/sdi-test/t9/t9.ngml";

 qDebug() << "Folder: " << folder << ", File: " << file;
 qDebug() << "ManFolder: " << manfolder;

 if(manfolder.isEmpty())
 {
  if(file.isEmpty())
  {
   // process whole folder ...
   NGML_Folder fld(folder);
   fld.convert_to_latex();
  }
  else
    process_ngml_file(file);
 }
 else
 {
  NGML_Folder fld(folder, file, manfolder);
  fld.convert_to_latex(&process_ngml_file);
 }
 return 0;
}


int main2(int argc, char* argv[])
{
// QApplication qapp(argc, argv);

// QString folder = QFileDialog::getExistingDirectory(nullptr,
//   "Select Folder"
//   " (needs /ngml subfolder)",
//   DEFAULT_DIRECTORY);

 NGML_Document ndoc; //(DEFAULT_DIRECTORY "/t1.ngml");
 ndoc.load_and_parse(DEFAULT_NGML_DIRECTORY "/t1.ngml");

 HTXN_Document_8b* hxd = new HTXN_Document_8b;

 NGML_Output_HTXN noh(ndoc, hxd);
 noh.export_htxne();

// noh.write_latex_out(DEFAULT_DIRECTORY "/t1.ngml.htxne.tex");

 NGML_Output_Latex nol(ndoc);
 nol.set_htxn_document(hxd);
 nol.export_latex(DEFAULT_NGML_DIRECTORY "/t1.ngml.tex");
   // output_path + '/' + qfi.completeBaseName() + ".tex");


//? QFile file(DEFAULT_DIRECTORY "/t1.ngml.htxne");
//? if(file.open(QIODevice::WriteOnly | QIODevice::Text))
//? {
//?  doc.write_latex_out(file); 
//? }


// NGML_Folder ngf(folder + "/ngml");
// ngf.convert_all_files(folder, folder + "/khif");

 return 0;
}


