
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "rz-ngml/kernel/document/rz-ngml-document.h"

#include "rz-ngml/output/rz-ngml-output-html.h"
#include "rz-ngml/output/rz-ngml-output-latex.h"
#include "rz-ngml/output/rz-ngml-output-khif.h"
#include "rz-ngml/kernel/document/rz-ngml-folder.h"

#include <QMapIterator>

#include <QRegularExpression>

USING_RZNS(NGML)



#define DEFAULT_DIRECTORY  "../.."


#include <QApplication>
#include <QFileDialog>
#include <QDebug>
#include <QMap>

int main(int argc, char* argv[])
{
 QString dir;
 {
  QApplication qapp(argc, argv);
  dir = QFileDialog::getExistingDirectory(nullptr, "Choose Folder", DEFAULT_DIRECTORY);
 }

 NGML_Folder folder(dir);
 folder.convert_to_latex();
}

