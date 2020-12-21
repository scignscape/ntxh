
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgh-sdi-document.h"

#include "ngml-sdi/ngml-sdi-paragraph.h"

#include "dgh-sdi-paragraph.h"


#include <QDebug>



USING_KANS(DGH)


DGH_SDI_Document::DGH_SDI_Document()
{

}

void DGH_SDI_Document::review_dgh()
{
 for(DGH_SDI_Paragraph* dsp : paragraphs_)
 {
  qDebug() << dsp->get_summary();
 }
}

void DGH_SDI_Document::parse_paragraph_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn)
{
 NGML_SDI_Paragraph* nsp = new NGML_SDI_Paragraph;
 DGH_SDI_Paragraph* dsp = new DGH_SDI_Paragraph(nsp);
 paragraphs_.push_back(dsp);

 g.get_sfsr(hn, {{2,13}}, [this, nsp, dsp](QVector<QPair<QString, void*>>& prs)
 {
  // :n:1 :i:2 :o:3 :p:5 :j:6 :x:7 :y:8 :b:4 ;
  nsp->set_id(prs[0].first.toInt());
  nsp->set_current_jobname(prs[1].first);
  dsp->set_page(prs[2].first.toInt());
  nsp->set_start_index(prs[3].first.toInt());
  nsp->set_end_index(prs[4].first.toInt());
  nsp->set_start_x(prs[5].first.toInt());
  nsp->set_start_y(prs[6].first.toInt());
  nsp->set_end_x(prs[7].first.toInt());
  nsp->set_end_y(prs[8].first.toInt());
  dsp->set_order_in_page(prs[9].first.toInt());
  dsp->set_in_file_id(prs[10].first.toInt());
  dsp->set_file_id(prs[11].first.toInt());
 });
 // // qDebug() << "parse_paragraph_start_hypernode()";


}

void DGH_SDI_Document::load_from_ntxh(QString path)
{
 QMap<QString, void(DGH_SDI_Document::*)(NTXH_Graph& g, NTXH_Graph::hypernode_type*)> methods {

  {"paragraph",
    &DGH_SDI_Document::parse_paragraph_hypernode},

//  {"Sentence",
//    &NGML_SDI_Document::parse_sentence_hypernode},
 };

 NTXH_Document doc(path);

 doc.parse();

 typedef NTXH_Graph::hypernode_type hypernode_type;

 NTXH_Graph& g = *doc.graph();
 const QVector<hypernode_type*>& v = g.hypernodes();

 qDebug() << "Parse: " << path << " -- " << v.size() << " nodes ...";

 u4 i = 0;

// n8 bls = 12; // default ...

 for(hypernode_type* h : v)
 {
  g.get_sf(h, 1, [this, &methods, &g, h](QPair<QString, void*>& pr)
  {
   auto it = methods.find(pr.first);
   if(it != methods.end())
   {
    (this->**it)(g, h);
   }
  });
 }
}


