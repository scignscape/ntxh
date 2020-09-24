
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef GTAGML_DOCUMENT__H
#define GTAGML_DOCUMENT__H

#include "relae-graph/relae-node-ptr.h"

#include "kernel/gtagml-dominion.h"

#include "kernel/query/gtagml-query.h"

#include "kernel/grammar/gtagml-parsing-mode.h"

#include "gtagml-document-info.h"

#include "accessors.h"

#include "kans.h"

KANS_(GTagML)

class GTagML_Parser;
class GTagML_Grammar;
class GTagML_Graph_Build;
class GTagML_Word_Entry_List;

class GTagML_Annotation_Tile;

class GTagML_Document
{
 caon_ptr<GTagML_Graph> graph_;
 caon_ptr<GTagML_Parser> parser_;
 caon_ptr<GTagML_Graph_Build> graph_build_;
 caon_ptr<GTagML_Grammar> grammar_;

 QString local_path_;
 QString raw_text_;

 QString khi_info_;

 QMap<QString, caon_ptr<GTagML_Annotation_Tile> >* annotations_;

 typedef QMap<QString, caon_ptr<GTagML_Annotation_Tile> >* annotations_type;

 QMap<QString, caon_ptr<GTagML_Annotation_Tile> > local_annotations_;



 GTagML_Parsing_Modes parsing_mode_;

 GTagML_Document_Info document_info_;

 QString sdi_tag_command_info_path_;

public:


 ACCESSORS(QString ,local_path)
 ACCESSORS(QString ,raw_text)
 ACCESSORS(caon_ptr<GTagML_Graph> ,graph)
 ACCESSORS__GET(caon_ptr<GTagML_Grammar> ,grammar)

 ACCESSORS(annotations_type ,annotations)

 ACCESSORS(QString ,khi_info)
 ACCESSORS(GTagML_Parsing_Modes ,parsing_mode)

 GTagML_Document();

 ~GTagML_Document();

 void check_sdi_tag_command_info();

 void load_and_parse(QString path, caon_ptr<GTagML_Grammar> grammar =
   caon_ptr<GTagML_Grammar>(nullptr) );
 void load_file(QString path);
 void set_grammar(caon_ptr<GTagML_Grammar> grammar =
   caon_ptr<GTagML_Grammar>(nullptr) );
 void parse();

 void use_light_xml();

 QString file_name();

 QString save_word_count();
 QString save_word_stream();
 QString save_hrefs();
 QString save_light_xml();

 QString save_quotes();

 static void save_file(QString path, QString contents);

 static void clean_html(QString& str);
 static QString escape_unicode(QString contents);

// void tag_command_annotation(caon_ptr<GTagML_Tile> nt, caon_ptr<GTagML_Annotation_Tile> tile);
 void tag_command_annotation(caon_ptr<GTagML_Annotation_Tile> tile);

 void write_local_annotations(QString path);
 static void write_annotations(QString path, QMap<QString, caon_ptr<GTagML_Annotation_Tile>>& annotations);

};

_KANS(GTagML)


#endif
