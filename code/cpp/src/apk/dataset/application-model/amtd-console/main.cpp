
//          Copyright Nathaniel Christen 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "application-model-test-dialog/application-model-test-dialog.h"

#include "application-model/application-test-model.h"

#include <QApplication>


#include "kans.h"

#include <QIcon>


USING_KANS(DSM)

USING_KANS(Phaon)


int main(int argc, char **argv)
{
 QApplication qapp(argc, argv);

 qapp.setWindowIcon(QIcon(DEFAULT_ICON_FOLDER "/app-icon.png"));

 Application_Test_Model apptm;

 Application_Model_Test_Dialog dlg(&apptm, {{

   {"Expand Sample", DEFAULT_KPH_FOLDER "/dataset/raw/expand-sample.kph"},

   {"Launch Lexpair Dialog", DEFAULT_KPH_FOLDER "/dataset/raw/launch-lexpair-dialog.kph"},

   {"Launch PDF", DEFAULT_KPH_FOLDER "/dataset/raw/launch-pdf.kph"},

   {"Open PDF to Sample", DEFAULT_KPH_FOLDER "/dataset/raw/open-pdf.kph"},

   {"Open Dataset", DEFAULT_KPH_FOLDER "/dataset/raw/open-dataset.kph"},

   {"Copy to Clipboard", DEFAULT_KPH_FOLDER "/dataset/raw/copy-to-clipboard.kph"},

   {"Test Qh", DEFAULT_KPH_FOLDER "/dataset/raw/test-qh.kph"},

   {"Test Message Box", DEFAULT_KPH_FOLDER "/dataset/raw/test-messagebox.kph"},

   }}, nullptr);

 dlg.show();

 return qapp.exec();
}
