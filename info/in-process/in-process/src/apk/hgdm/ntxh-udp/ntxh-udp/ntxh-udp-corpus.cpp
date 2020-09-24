
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "ntxh-udp-corpus.h"


#include <QDebug>

#include <QTextStream>

#include "textio.h"
USING_KANS(TextIO)

#include "ntxh-parser/ntxh-document.h"

#include "kans.h"
USING_KANS(HGDMCore)

NTXH_UDP_Corpus::NTXH_UDP_Corpus(QString root_folder)
  :  QRing_File_Structure(root_folder)
{


}

void NTXH_UDP_Corpus::check_comments()
{
 for(NTXH_UDP_Sentence& dgs : *this)
 {
  dgs.check_comments();
 }
}

void NTXH_UDP_Corpus::check_write_latex()
{
 for(NTXH_UDP_Sentence& dgs : *this)
 {
  if(dgs.latex_out_file().isEmpty())
    continue;
  QString latex;
  QTextStream qts(&latex);
  dgs.write_latex(qts);
  QString f = expand_external_file(dgs.latex_out_file());
  save_file(f, latex);
 }
}

void NTXH_UDP_Corpus::init_sentences()
{
 QString f = files_.first();
 QString xf = expand_file(f);

 NTXH_Document doc(xf);

 doc.parse();

 typedef NTXH_Graph::hypernode_type hypernode_type;

 NTXH_Graph& g = *doc.graph();
 const QVector<hypernode_type*>& v = g.hypernodes();

 QString udp_text;
 QTextStream qts(&udp_text);

 resize(v.size());

 int i = 0;

 for(hypernode_type* h : v)
 {
  NTXH_UDP_Sentence& sent = (*this)[i];
  ++i;
  g.get_sf(h, 1, [&sent](QPair<QString, void*>& pr)
  {
   sent.set_id(pr.first.toInt());
  });

  g.get_sf(h, 2, [&sent](QPair<QString, void*>& pr)
  {
   sent.set_corpus_name(pr.first);
  });

  g.get_sf(h, 3, [&sent](QPair<QString, void*>& pr)
  {
   sent.set_sxp_text(pr.first);
  });

  g.get_sf(h, 4, [&sent](QPair<QString, void*>& pr)
  {
   sent.set_latex_out_file(pr.first);
  });

  g.get_sf(h, 5, [&qts](QPair<QString, void*>& pr)
  {
   qts << pr.first << "\n\n";
  });
 }

 save_file(xf + ".conllu", udp_text);

 QVector<sentence*> sv;
 QStringList fs {xf + ".conllu"};

 int result = main_detokenize(fs,
   expand_file(xf + ".out"), &sv);

 i = 0;
 for(sentence* s : sv)
 {
  NTXH_UDP_Sentence& sent = (*this)[i];
  ++i;
  sent.set_udp_sentence(s);
  sent.check_parse_sxp();
 }
}

void NTXH_UDP_Corpus::report_sentence_texts(QTextStream& qts)
{
 for(NTXH_UDP_Sentence& dgs : *this)
 {
  dgs.report_text(qts);
  qts << '\n';
 }
}


void NTXH_UDP_Corpus::report_sentence_texts()
{
 for(NTXH_UDP_Sentence& dgs : *this)
 {
  dgs.report_text();
 }
}

int NTXH_UDP_Corpus::detokenize(QString outfile)
{
 QVector<sentence*> sv;

 QStringList infiles;
 expand_files(infiles);

 int result = main_detokenize(infiles,
   expand_file(outfile), &sv);

 for(sentence* s : sv)
 {
  push_back(NTXH_UDP_Sentence(s));
 }

 return result;
}
