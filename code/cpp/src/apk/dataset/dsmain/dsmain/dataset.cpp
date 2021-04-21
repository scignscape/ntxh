
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dataset.h"

#include "language-sample.h"

#include "language-sample-group.h"

#include "phaong/phaong.h"
#include "phaong/phaong-types.h"

#include "ntxh-parser/ntxh-document.h"

#include "textio.h"

#include <QDateTime>

#include "qh-model.h"


USING_KANS(DSM)
USING_KANS(TextIO)

Dataset::Dataset(QString root_folder)
  : QRing_File_Structure(root_folder), samples_(nullptr), groups_(nullptr)
{
 forms_ = QStringList{{"Text", "Dialog", "Intonation", "Fragment", "Paragraph"}};
 issues_ = QStringList{{"Ambiguity", "Roles", "Logic",
            "Scope", "Types", "Prosody", "Syntax", "Semantics", "Pragmatics",
            "Dialogue", "Cognition", "Lexical", "Discourse", "Reference", "Ontological",
 }};

 std::transform(issues_.begin(), issues_.end(),
   std::back_inserter(issue_codes_),[](QString issue)
   {
    return issue.mid(0, 3).toLower();
   });

 for(QString issue: issue_codes_)
 {
  issue_counts_.insert(issue, 0);
 }
}

void Dataset::load_from_folder()
{
 load_from_folder(root_folder_);
}


void Dataset::load_from_folder(QString path)
{
 QDir qd(path);
 merge_file_ = qd.absoluteFilePath("sdi-merge.ntxh");
 samples_file_ = qd.absoluteFilePath("samples.ntxh");
 pdf_file_ = qd.absoluteFilePath("main.pdf");

 ppc_file_ = qd.absoluteFilePath("ppc.txt");

 sdi_document_.load_from_ntxh(samples_file_);
 groups_ = &sdi_document_.language_sample_groups();
 samples_ = &sdi_document_.language_samples();

 // // get issue counts

 for(Language_Sample* samp : *samples_)
 {
  ++issue_counts_[samp->issue()];
 }
 qDebug() << "issue_counts: " << issue_counts_;

 u2 c = 1;
 for(QPair<u2, u2> pr: sdi_document_.subdocument_ranges())
 {
  // ignore author for now ...
  subdocuments_.push_back({{{},c}, pr});
  ++c;
 }

 load_ppc_file();

}

void Dataset::load_ppc_file()
{
 QString text;
 load_file(ppc_file_, text);

 QStringList qsl = text.split("===");
 for(QString dm : qsl)
 {
  Discourse_Markup_Sample dmsamp;
  dmsamp.parse(dm.trimmed());
  discourse_markup_samples_.push_back(dmsamp);
 }
}


bool check(QPair<QString, void*>& pr)
{
 if(pr.first.isEmpty())
   return pr.second;
 return true;
};

void Dataset::save_to_file(QString path)
{
//? Language_Sample_Group::serialize_samples_to_file(groups_, path);
}

void Dataset::save_to_file()
{
 save_to_file(samples_file_ + ".out.txt");
}

void Dataset::save_to_file_udp()
{
 //? save_to_file_udp(file_ + ".udp.ntxh", file_ + ".conllu", file_ + ".pre.txt");
}

void Dataset::save_to_file_udp(QString path, QString upath, QString ppath)
{
 QFile outfile(path);
 if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
   return;
 QTextStream outstream(&outfile);

 QFile uo(upath);
 if (!uo.open(QIODevice::WriteOnly | QIODevice::Text))
   return;
 QTextStream uos(&uo);

 QFile po(ppath);
 if (!po.open(QIODevice::WriteOnly | QIODevice::Text))
   return;
 QTextStream pos(&po);

 for(Language_Sample_Group* g : *groups_)
 {
  for(Language_Sample* ls : g->samples())
  {
   QString u;
   //?ls->serialize_udp(g->id(), outstream, u);
   uos << u;
   uos << "\n\n";
   //?QString aot = ls->archival_or_text().simplified();
   //?Language_Sample::clean(aot);
   //?pos << aot << "\n";
  }
 }

 outfile.close();
 uo.close();
 po.close();
}



#ifdef HIDE
void Dataset::load_from_file(QString path)
{
 file_ = path;

 NTXH_Document doc(path);

 doc.parse();

 typedef NTXH_Graph::hypernode_type hypernode_type;

//? NTXH_Graph& g = *doc.graph();

 QVector<NTXH_Graph::hypernode_type*>& hns = doc.top_level_hypernodes();

 auto it = hns.begin();

 NTXH_Graph::hypernode_type* hn = *it;

 int sdcount = 0;
 doc.graph()->get_sfsr(hn, {{1,4}}, [&sdcount, this](QVector<QPair<QString, void*>>& prs)
 {
  QString au = prs[0].first;
  sdcount = prs[1].first.toInt();
  this->subdocument_kind_ = prs[2].first;
  this->pdf_path_ = this->expand_external_file(prs[3].first);
 });

 subdocuments_.resize(sdcount);

 for(int i = 0; i < sdcount; ++i)
 {
  ++it;
  NTXH_Graph::hypernode_type* hn = *it;

  doc.graph()->get_sfsr(hn, {{1,3}}, [this, i](QVector<QPair<QString, void*>>& prs)
  {
   subdocuments_[i] = {{prs[0].first, i + 1},
     {prs[1].first.toInt(), prs[2].first.toInt()}};
  });
 }

 groups_.resize(hns.size() - sdcount - 1);

 int count = 0;

 ++it;

 std::transform(it, hns.end(), groups_.begin(), [&count,&doc](NTXH_Graph::hypernode_type* hn)
 {
  ++count;
  Language_Sample_Group* result = new Language_Sample_Group(count);

  doc.graph()->get_sfsr(hn, {{1,3}}, [result](QVector<QPair<QString, void*>>& prs)
  {
   QVector<quint16> nums = {0,0,0};
   std::transform(prs.begin(), prs.end(), nums.begin(), [](QPair<QString, void*>& pr)
   {
    return pr.first.toInt();
   });
   result->set_id(nums[0]);
   result->set_page(nums[1]);
   result->set_section(nums[2]);
  });

  doc.graph()->get_sfs(hn, {4,5}, [result](QVector<QPair<QString, void*>>& prs)
  {
//   result->set_text_id(prs[0].first);
//   result->set_classification(prs[1].first);
  });

  doc.graph()->all_afs(hn, [&doc, result](QPair<QString, void*>& pr)
  {
   NTXH_Graph::hypernode_type* ihn = (NTXH_Graph::hypernode_type*) pr.second;
   if(ihn)
   {
    Language_Sample* ls = nullptr;
    doc.graph()->get_sfsr(ihn, {{1,14}}, [result, &ls](QVector<QPair<QString, void*>>& prs)
    {
     {QPair<QString, void*>& ipr = prs[3];
//      if(check(ipr))
//        ls = new Language_Sample(result, ipr.first);
     }
     {QPair<QString, void*>& ipr = prs[0];
      if(check(ipr))
        ls->set_id(ipr.first.toInt());
      }
     {QPair<QString, void*>& ipr = prs[1];
      if(check(ipr))
        ls->set_page(ipr.first.toInt());
      }
     {QPair<QString, void*>& ipr = prs[2];
      if(check(ipr))
        ls->set_latex_label(ipr.first);
     }
     {QPair<QString, void*>& ipr = prs[4];
//      if(check(ipr))
//        ls->set_udp_source(ipr.first);
      }
     {QPair<QString, void*>& ipr = prs[5];
//      if(check(ipr))
//        ls->set_udp_label(ipr.first);
     }
     {QPair<QString, void*>& ipr = prs[6];
//      if(check(ipr))
//        ls->set_pre(ipr.first);
     }
     {QPair<QString, void*>& ipr = prs[7];
//      if(check(ipr))
//        ls->set_post(ipr.first);
         }
     {QPair<QString, void*>& ipr = prs[8];
//      if(check(ipr))
//        ls->set_archival(ipr.first);
          }
     {QPair<QString, void*>& ipr = prs[9];
      if(check(ipr))
        ls->set_classification(ipr.first);
           }
     {QPair<QString, void*>& ipr = prs[10];
//      if(check(ipr))
//        ls->set_subindex(ipr.first);
           }
     {QPair<QString, void*>& ipr = prs[11];
//      if(check(ipr))
//        ls->set_speaker(ipr.first);
            }
     {QPair<QString, void*>& ipr = prs[12];
//      if(check(ipr))
//        ls->set_annotation_mark(ipr.first);
             }
     {QPair<QString, void*>& ipr = prs[13];
//      if(check(ipr))
//        ls->set_alternate(ipr.first);
              }
    });

//?    result->push_back(ls);
   }
  });

  return result;
 });
}
#endif // HIDE

void Dataset::save_raw_file(QString text, int page, int num)
{
 QString dt = QDateTime::currentDateTime().toString("dd-MM-yy--hh-mm");
 QString path = QString("%1.%2.%3.%4.txt").arg(samples_file_)
   .arg(page).arg(num).arg(dt);
 save_file(path, text);
}

void Dataset::save_as_markdown(QString path)
{
 if(short_publication_title_.isEmpty())
 {
  // try to guess the title ...
  QFileInfo qfi(pdf_file_);
  QString dn = qfi.absoluteDir().dirName();
  if(dn == "ctg")
    short_publication_title_ = "Cognitive Transform Grammar";
  else if(dn == "itm")
    short_publication_title_ = "Interface Theory of Meaning";
  else if(dn == "icg")
    short_publication_title_ = "Conceptual Spaces/Cognitive Grammar";
 }

 QString text;
 QTextStream qts(&text);

 qts << "\n### " << short_publication_title_ << "\n---\n\n";

 for(Language_Sample_Group* g : *groups_)
 {
  qts << "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(page " << g->page() << ")  \n";
  for(Language_Sample* ls : g->samples())
  {
   QString text = ls->text();
   text.replace("---{}", "--");
   qts << text << "  \n";
  }
  qts << "\n#\n";
 }

// QString tmplate;
// load_file(path, tmplate);

 save_file(path, text);
}

void Dataset::get_serialization(QString& text, QString& gtext)
{
 // // TODO ... so far we're not using serialization directly from the dataset ...
 for(Language_Sample* samp : *samples_)
 {
 }

 int rgc = 0;
 for(Language_Sample_Group* g : *groups_)
 {
 }

}

void Dataset::parse_to_samples(QString text, int page,
  int num, phaong<pg_t>& phg)
{
#ifdef HIDE

 int current_page = page;
 int current_index = num;
 QString current_sub_index;

 QStringList qsl = text.split("\n");
 for(QString qs : qsl)
 {
  if(qs.isEmpty())
    continue;
  if(qs.startsWith('@'))
  {
   current_page = qs.mid(1).toInt();
   continue;
  }
  if(qs.startsWith('#'))
  {
   current_index = qs.mid(1).toInt();
   continue;
  }
  if(qs.size() < 3)
    continue;
  if( (qs[1] == '.') || (qs[1] == ')') )
  {
   current_sub_index = qs[0];
   qs = qs.mid(2);
  }
  else if( (qs[2] == '.') || (qs[2] == ')') )
  {
   current_sub_index = qs.left(2);
   qs = qs.mid(3);
  }
  else if( (qs[3] == '.') || (qs[3] == ')') )
  {
   current_sub_index = qs.left(3);
   qs = qs.mid(4);
  }
  Language_Sample* samp = new Language_Sample(qs.simplified(), phg);
  samp->set_page(current_page);
  samp->set_index(current_index);
  samp->set_sub_index(current_sub_index);
  samp->set_chapter(get_chapter_number_from_page(current_page));

  samples_.push_back(samp);
 }
#endif // HIDE
}
