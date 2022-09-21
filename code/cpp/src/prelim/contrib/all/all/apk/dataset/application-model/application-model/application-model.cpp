
//          Copyright Nathaniel Christen 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "application-model.h"

#include "ScignStage-ling/ScignStage-ling-dialog.h"

#include <QDebug>

#include "dsmain/qh-model.h"

#include "dsmain/dataset.h"
#include "dsmain/language-sample.h"
#include "dsmain/language-sample-group.h"

#include "dsmain/dataset-info.h"


Application_Model::Application_Model(ScignStage_Ling_Dialog* ling_dialog, QString root_folder)
  :  ling_dialog_(ling_dialog), root_folder_(root_folder), qhm_(nullptr)
{

}

QString Application_Model::test_qh(QString type, int index)
{
 Dataset* ds = qhm_->dataset();
 Qh_Runtime& qhr = qhm_->qh_runtime();

 if(type == "sample")
 {
  Language_Sample* ls = ds->samples()->at(index);
  Qh_Pack_Builder* qpb = qhr.serialize(ls);

  Language_Sample ls1;
  ls1.absorb_pack(*qpb);

  return ls1.text();
 }

 else if(type == "group")
 {
  Language_Sample_Group* lsg = ds->groups()->at(index);
  Qh_Pack_Builder* qpb = qhr.serialize(lsg);

  Language_Sample_Group lsg1;
  lsg1.absorb_pack(*qpb);

  return lsg1.get_main_text();
 }

 else if(type == "info")
 {
  Dataset_Info dsi(ds);

  Qh_Pack_Builder* qpb = qhr.serialize(&dsi);

  Dataset_Info dsi1;

  dsi1.absorb_pack(*qpb);

  return dsi1.ds()->samples_file();
 }

 else if(type == "discourse")
 {

  Discourse_Markup_Sample dms = ds->discourse_markup_samples().first();
  Qh_Pack_Builder* qpb = qhr.serialize(&dms);

  Discourse_Markup_Sample dms1;
  dms1.absorb_pack(*qpb);

  return dms1.words().join(" | ");
 }

 return  {};
}

void Application_Model::check_init_qh(Dataset* ds)
{
 if(!qhm_)
 {
  qhm_ = new Qh_Model(ds);
  qhm_->init();
 }
}

void Application_Model::launch_xpdf(ScignStage_Ling_Dialog* dlg, QString f, int page)
{
 if(f.startsWith('@'))
   f = f.mid(1).prepend(root_folder_);
 dlg->open_pdf_file(f, page, 0);
}

void Application_Model::open_dataset(ScignStage_Ling_Dialog* dlg)
{
 dlg->get_replacement_dataset_path();
}

void Application_Model::copy_to_clipboard(ScignStage_Ling_Dialog* dlg)
{
 dlg->copy_to_clipboard();
}

void Application_Model::open_pdf(ScignStage_Ling_Dialog* dlg, QString f)
{
 if(f.startsWith('@'))
   f = f.mid(1).prepend(root_folder_);
 dlg->open_pdf_to_sample(f);
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
