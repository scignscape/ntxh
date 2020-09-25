
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "ntxh-document.h"

#include "relae-graph/relae-parser.templates.h"

#include "kernel/graph/ntxh-graph.h"
#include "grammar/ntxh-grammar.h"
#include "grammar/ntxh-parser.h"
#include "grammar/ntxh-graph-build.h"

#include <QFileInfo>
#include <QDir>

USING_KANS(HGDMCore)


NTXH_Document::NTXH_Document(QString path)
 : graph_(nullptr), grammar_(nullptr)
{
 if(!path.isEmpty())
   load_file(path);
}

void NTXH_Document::surround(QString divider, QString text)
{
 int index = text.indexOf(divider);
 if(index == -1)
   raw_text_.append(text);
 else
 {
  raw_text_.prepend(text.midRef(0, index));
  raw_text_.append(text.midRef(index + divider.size()));
 }
}


QVector<NTXH_Graph::hypernode_type*>& NTXH_Document::top_level_hypernodes()
{
 static QVector<NTXH_Graph::hypernode_type*> static_default;
 if(graph_build_)
   return graph_build_->top_level_hypernodes();
 return static_default;
}

void NTXH_Document::load_file(QString path)
{
 QFile file(path);
 if(file.open(QFile::ReadOnly | QIODevice::Text))
 {
  raw_text_ = file.readAll();
  local_path_ = path;
  QFileInfo qfi(local_path_);
  local_directory_ = qfi.absoluteDir().absolutePath();
 }
}


void NTXH_Document::resolve_report_path(QString& path)
{
 if(path.startsWith('.'))
 {
  path = path.mid(1);
  if(path.startsWith('.'))
  {
   path = local_path_ + path;
  }
  else
  {
//?   QFileInfo qfi(local_path_);
  }
 }
}

void NTXH_Document::report_graph(QString path)
{
 resolve_report_path(path);
 QFile file(path);
 if(file.open(QFile::WriteOnly | QIODevice::Text))
 {
  QTextStream qts(&file);
 }
}

void NTXH_Document::set_grammar(NTXH_Grammar* grammar)
{
 if(grammar)
  grammar_ = grammar;
 else
  grammar_ = new NTXH_Grammar();
}

void NTXH_Document::parse(int start_position, int end_position)
{
 graph_ = new NTXH_Graph();
 parser_ = new NTXH_Parser(graph_);
 parser_->set_raw_text(raw_text_);

 graph_build_ = new NTXH_Graph_Build(this, *parser_, *graph_);
 graph_build_->init();

 grammar_ = new NTXH_Grammar;

 grammar_->init(*parser_, *graph_, *graph_build_);

 grammar_->compile(*parser_, *graph_, raw_text_, start_position);
}

NTXH_Document::~NTXH_Document()
{

}


