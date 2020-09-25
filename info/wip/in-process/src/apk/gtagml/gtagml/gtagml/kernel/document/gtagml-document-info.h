
#ifndef GTAGML_DOCUMENT_INFO__H
#define GTAGML_DOCUMENT_INFO__H

#include "relae-graph/relae-node-ptr.h"

#include "accessors.h"

#include "kans.h"

#include <QStringList>

KANS_(GTagML)

class GTagML_Parser;
class GTagML_Grammar;
class GTagML_Graph_Build;
class GTagML_Word_Entry_List;

class GTagML_Document_Light_Xml;

class GTagML_Document_Info
{

 QMap<QString, int> word_count_;
 QString word_stream_;
 QMap<QString, QStringList> hrefs_;

 typedef QMap<QString, int> word_count_type;
 typedef QMap<QString, QStringList> hrefs_type;

 QStringList quotes_;

 GTagML_Document_Light_Xml* light_xml_;

public:

 ACCESSORS(word_count_type ,word_count)
 ACCESSORS(QString ,word_stream)
 ACCESSORS(hrefs_type ,hrefs)
 ACCESSORS(GTagML_Document_Light_Xml* ,light_xml)

 GTagML_Document_Info();

 void add_quote(QString quote);
 void add_word(QString word);

 void add_href(QString tagname, QString url);

 void save_word_count(QString file);
 void save_word_stream(QString file);
 void save_hrefs(QString file);
 void save_quotes(QString file);

// QString save_word_count(QString path);
// QString save_word_stream(QString path);
// QString save_hrefs(QString path);

 void save_file(QString path, QString contents);

 void init_light_xml();
 void check_light_xml_href();
 void save_light_xml(QString file);

};

_KANS(GTagML)


#endif
