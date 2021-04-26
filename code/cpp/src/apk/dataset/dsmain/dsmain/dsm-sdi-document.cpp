
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dsm-sdi-document.h"

//#include "ngml-sdi/ngml-sdi-paragraph.h"
//#include "ngml-sdi/ngml-sdi-sentence.h"


#include "language-sample-group.h"
#include "language-sample.h"


#include <QDebug>



USING_KANS(DSM)


DSM_SDI_Document::DSM_SDI_Document()
{

}

//void DSM_SDI_Document::review_dgh()
//{
// for(DGH_SDI_Paragraph* dsp : paragraphs_)
// {
//  qDebug() << dsp->get_summary();
// }

// for(DGH_SDI_Sentence* dss : sentences_)
// {
//  qDebug() << dss->get_summary();
// }

//}

void DSM_SDI_Document::parse_subdocument_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn)
{
 g.get_sfs(hn, {2,3}, [this](QVector<QPair<QString, void*>>& prs)
 {
  subdocument_ranges_.push_back({prs[0].first.toUShort(), prs[1].first.toUShort()});
 });
}

void DSM_SDI_Document::parse_sample_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn)
{
 //NGML_SDI_Sentence* nss; // = new NGML_SDI_Sentence;
 Language_Sample* ls = new Language_Sample; //(0, 0);//nss);
 language_samples_.push_back(ls);

 Language_Sample_Group* lsg = language_sample_groups_.last();

 g.get_sfsr(hn, {{1,14}}, [lsg, ls](QVector<QPair<QString, void*>>& prs)
 {
  u2 id = prs[0].first.toUShort();
  ls->set_id(id);

  u2 page = prs[1].first.toUShort();
  ls->set_page(page);

  QString lbl = prs[2].first;
  ls->set_latex_label(lbl);

  QString text = prs[3].first;
  ls->set_text(text);

  QString xsrc = prs[4].first;
  ls->set_external_source(xsrc);

  QString xlbl = prs[5].first;
  ls->set_external_label(xlbl);

  QString pre = prs[6].first;
  // // not many pre's ...
  if(!pre.isEmpty())
  {
   if(pre.startsWith("{\\") || pre.startsWith('\\'))
   {
    qDebug() << "Likely LaTeX commands in ntxh; re-interpreting: " << pre;
    // // this is a hack to encode the ds version of the pre in the label
    if(lbl.startsWith("itm:_"))
    {
     pre = QString("(%1)").arg(lbl.mid(4));
     pre.replace('_', ' ');
     ls->set_pre(pre);
    }
   }
   else
   {
    qDebug() << "Have pre: " << pre;
    ls->set_pre(pre);
   }

  }

  QString post = prs[7].first;
  ls->set_post(prs[7].first);


  QString cl = prs[9].first;
  ls->parse_classification(cl);

  // // now there's enough info to do the add ...
  lsg->add_sample(ls);

  QString alt = prs[8].first;
  ls->check_alternate_text(alt);

  // :n:1 :i:2 :o:3 :p:5 :j:6 :x:7 :y:8 :b:4 ;
//  nss->set_id(prs[0].first.toInt());
//  dss->set_page(prs[1].first.toInt());
//  nss->set_start_index(prs[2].first.toInt());
//  nss->set_end_index(prs[3].first.toInt());
//  nss->set_start_x(prs[4].first.toInt());
//  nss->set_start_y(prs[5].first.toInt());
//  nss->set_end_x(prs[6].first.toInt());
//  nss->set_end_y(prs[7].first.toInt());
//  dss->set_in_file_id(prs[9].first.toInt());
//  dss->set_file_id(prs[10].first.toInt());
 });

}


void DSM_SDI_Document::parse_group_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn)
{
// NGML_SDI_Paragraph* nsp = new NGML_SDI_Paragraph;
 Language_Sample_Group* lsg = new Language_Sample_Group;

 language_sample_groups_.push_back(lsg);

 g.get_sfsr(hn, {{1,4}}, [this, lsg](QVector<QPair<QString, void*>>& prs)
 {
  u2 id = prs[0].first.toUShort();
  lsg->set_id(id);

  u2 rpage = prs[1].first.toUShort();
  // // currently rpage is not used ...

  u2 page = prs[2].first.toUShort();

  if( (rpage != 0) && (page != rpage) )
  {
   qDebug() << "\n" << QString("Different page and running-page values (%1, %2), "
     "maybe due to the surrounding paragraph crossing a page break.  Using "
     "the running-page value.").arg(page).arg(rpage) << "\n";
   page = rpage;
  }

  lsg->set_page(page);

  u2 section = prs[3].first.toUShort();
  lsg->set_section(section);

  // :i:1 :p:2 :s:3 ;

 });
 // // qDebug() << "parse_paragraph_start_hypernode()";


}

void DSM_SDI_Document::load_from_ntxh(QString path)
{
 QMap<QString, void(DSM_SDI_Document::*)(NTXH_Graph&, NTXH_Graph::hypernode_type*)> methods {

  {"SentenceList",
    &DSM_SDI_Document::parse_group_hypernode},

  {"SentenceItem",
    &DSM_SDI_Document::parse_sample_hypernode},

  {"Subdocument",
    &DSM_SDI_Document::parse_subdocument_hypernode},

 };

 NTXH_Document doc(path);

 doc.parse();

 typedef NTXH_Graph::hypernode_type hypernode_type;

 NTXH_Graph& g = *doc.graph();
 const QVector<hypernode_type*>& v = g.hypernodes();

 qDebug() << "Parse: " << path << " -- " << v.size() << " nodes ...";

// u4 i = 0;

//// n8 bls = 12; // default ...

 for(hypernode_type* h : v)
 {
  QString td = h->type_descriptor().first; // == "GH_SDI_Paragraph")
  auto it = methods.find(td);
  if(it != methods.end())
  {
   (this->**it)(g, h);
  }
 }
}


