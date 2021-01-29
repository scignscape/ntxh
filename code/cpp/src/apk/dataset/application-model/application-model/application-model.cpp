
//          Copyright Nathaniel Christen 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "application-model.h"

#include "ScignStage-ling/ScignStage-ling-dialog.h"

#include <QDebug>


Application_Model::Application_Model(ScignStage_Ling_Dialog* ling_dialog, QString root_folder)
  :  ling_dialog_(ling_dialog), root_folder_(root_folder)
{

}

void Application_Model::launch_xpdf(ScignStage_Ling_Dialog* dlg, QString f, int page)
{
 if(f.startsWith('@'))
   f = f.mid(1).prepend(root_folder_);
 dlg->open_pdf_file(f, page, 0);
}

void Application_Model::expand_sample(ScignStage_Ling_Dialog* dlg, int index)
{
 dlg->expand_sample(index - 1);
}

void Application_Model::launch_lexpair_dialog(ScignStage_Ling_Dialog* dlg, QString s)
{
#ifdef USING_LEXPAIR
 dlg->launch_lexpair_dialog(s);
#endif
}

Application_Model::~Application_Model() {}
