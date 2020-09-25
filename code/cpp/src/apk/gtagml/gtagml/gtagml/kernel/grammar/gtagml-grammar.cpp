
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gtagml-grammar.h"

#include "kernel/grammar/gtagml-parse-context.h"

#include "kernel/grammar/gtagml-graph-build.h"

#include "kernel/grammar/gtagml-parser.h"

#include "relae-graph/relae-parser.templates.h"

USING_KANS(GTagML)

GTagML_Grammar::GTagML_Grammar()
{
}

void GTagML_Grammar::init(GTagML_Parser& p, GTagML_Graph& g, GTagML_Graph_Build& graph_build)
{
 pre_rule( "script-word", "(?:[^{}()\\[\\]\\s`;,:]|(?:\\w::?\\w))+" );
 pre_rule( "valid-tag-command-name", "[\\w@](?:[^{}()\\[\\]<>/\\s`;,.:]|(?:\\w+::?\\w))*" );
 pre_rule( "space-to-end-of-line", "[__\\t]* \\n" );
 pre_rule( "end-of-line", "[__\\t\\S]* \\n" );
 pre_rule( "single-space", "[__\\t]" );

 pre_rule( "tag-command-wrap-mode-indicator", ": :? \\.?" );

 Context GTagML_context = add_context("gtaml-context");
 Context html_context = add_context("html-context");

 Context GTagML_or_html_context = add_context("gtaml-or-html",
  {GTagML_context, html_context});

 Context cxml_context = add_context("cxml-context");

 track_context({&GTagML_context, &html_context,
   &GTagML_or_html_context, &cxml_context });

 switch(graph_build.current_parsing_mode())
 {
 case GTagML_Parsing_Modes::HTML:
  activate(GTagML_or_html_context);
  break;

 case GTagML_Parsing_Modes::CXML:
  activate(cxml_context);
  break;

 case GTagML_Parsing_Modes::NGML:
  activate(GTagML_context);
  break;
 }


 GTagML_Parse_Context& parse_context = graph_build.parse_context();

// size_t test;


 add_rule( GTagML_context, "gtag-command-entry-inline",
   " \\[  "
   " (?<tag-command> .valid-tag-command-name. ) "
   " (?<tag-body-follow> [,>;.] ) "
   ,[&]
 {
  QString tag_command = p.matched("tag-command");
  QString tag_body_follow = p.matched("tag-body-follow");
 // QString argument = p.matched("argument");
  graph_build.gtag_command_entry_inline(tag_command, tag_body_follow);
  //graph_build.tag_body_leave();
 });

 add_rule( GTagML_context, "block-gtag-command-leave",
  " < (?<tag-command> .valid-tag-command-name. ) \\]  "
           ,[&]
 {
  graph_build.inline_tag_command_leave();
 });

 add_rule( flags_all_(parse_context ,inside_attribute_sequence),
   GTagML_context, "attribute-sequence-leave",
   " \\s+ => \\s+ "
   //" [/-]? "
   //" > "
   //" [,;.]? "
   ,[&]
 {
  //QString m = p.match_text();
  graph_build.attribute_sequence_leave();
 });

 add_rule( flags_all_(parse_context ,inside_attribute_sequence),
   GTagML_context, "mark-attribute-tile",
   " \\s+ @ \\s+ "
   ,[&]
 {
  graph_build.mark_attribute_tile();
 });



 // //  these should be for graph_build the equivalent
  //    of ->> (etc.) then `::some_cmd;
 add_rule( flags_all_(parse_context ,inside_multi_generic),
   GTagML_context,
   "cmd-multi-arg-transition",
   " (?<fiat-or-cmd> (?: (?: :: ) | = ) ) (?<main> -{1,2}>{1,2}) "
   " \\s+ (?<cmd> .valid-tag-command-name. ) "
    ,[&]
 {
  QString m = p.matched("main");
  QString cmd = p.matched("cmd");
  QString fiat = p.matched("fiat-or-cmd");
  graph_build.multi_arg_transition({}, {}, m);
  if(fiat == "=")
    graph_build.tag_command_entry_inline("::", fiat, cmd, ";", {});
  else
    graph_build.tag_command_entry_inline(fiat, {}, cmd, ";", {});
 });

 add_rule( flags_all_(parse_context ,inside_multi_generic),
   GTagML_context,
   "multi-arg-transition-to-main-tile",
   " \\s+ => \\s+ "
   ,[&]
 {
  graph_build.multi_arg_transition_to_main_tile();
 });

 add_rule( flags_all_(parse_context ,inside_multi_generic),
   GTagML_context, 
   "multi-arg-transition",
   " \\s+ (?<wmi> .tag-command-wrap-mode-indicator.? ) "
   " (?<fiat> =?)  "
   " (?<main> -{1,2}>{1,2} ) \\s+ "
   ,[&]
 {
  QString wmi = p.matched("wmi");  
  QString fiat = p.matched("fiat");  
  QString m = p.matched("main");
  graph_build.multi_arg_transition(wmi, fiat, m);
 });

 add_rule( flags_all_(parse_context ,inside_multi_parent_semis),
   GTagML_context, "tag-command-leave-multi",
   "  \\s+ ;; "
   ,[&]
 {
  graph_build.tag_command_leave_multi({});
 //?  parse_context.flags.inside_multi_parent_semis = false;
 //? parse_context.flags.inside_multi_parent = false;
 });

 add_rule( flags_all_(parse_context ,inside_multi_parent),
   GTagML_context, "tag-command-leave-multi",
   "  ` (?<tag-command> .valid-tag-command-name.? ) ` "
   ,[&]
 {
  QString tag_command = p.matched("tag-command");
  graph_build.tag_command_leave_multi(tag_command);
//?  parse_context.flags.inside_multi_parent = false;
 });


 add_rule( GTagML_context, "cmd-tag-command-entry-multi",
   " ` (?<wmi> .tag-command-wrap-mode-indicator.? ) "
   " (?<tag-command> .valid-tag-command-name. ) "
   " (?<tag-body-follow> [,.]?) "
   " \\s+ (?<fiat-or-cmd> (?: (?: :: ) | = ) ) "
   " (?<first-arg-marker> -{1,2} >{1,2} ) \\s+ (?<cmd> .valid-tag-command-name. )"
   ,[&]
 {
  QString wmi = p.matched("wmi");
  QString tag_command = p.matched("tag-command");
  QString tag_body_follow = p.matched("tag-body-follow");
  QString fiat = p.matched("fiat-or-cmd");
  QString first_arg_marker = p.matched("first-arg-marker");
  graph_build.tag_command_entry_multi(wmi, tag_command,
    tag_body_follow, {}, {}, first_arg_marker);
  QString cmd = p.matched("cmd");

  if(fiat == "=")
    graph_build.tag_command_entry_inline("::", fiat, cmd, ";", {});
  else
    graph_build.tag_command_entry_inline(fiat, {}, cmd, ";", {});

  //graph_build.tag_body_leave();
 });


 add_rule( GTagML_context, "tag-command-entry-multi",
  " ` (?<wmi> .tag-command-wrap-mode-indicator.? ) " 
  " (?<tag-command> .valid-tag-command-name. ) "
  " (?<tag-body-follow> [,.]?) \\s+  "
  " (?<fwmi> .tag-command-wrap-mode-indicator.? ) "
  " (?<first-arg-marker> @ | (?: -{1,2} >{1,2} ) ) \\s+ "
           ,[&]
 {
  QString wmi = p.matched("wmi");
  QString fwmi = p.matched("fwmi");
  QString tag_command = p.matched("tag-command");
  QString tag_body_follow = p.matched("tag-body-follow");
  QString first_arg_marker = p.matched("first-arg-marker");
  graph_build.tag_command_entry_multi(wmi, tag_command, 
    tag_body_follow, {}, fwmi, first_arg_marker);
    //graph_build.tag_body_leave();
 });

 add_rule( GTagML_context, "tag-command-entry-inline",
   " ` (?<wmi> .tag-command-wrap-mode-indicator.? ) "
   " (?<tag-command> .valid-tag-command-name. ) "
   " (?: < (?<argument> [^>]+ ) >)?  (?<tag-body-follow> [,;.] ) "
   ,[&]
 {
  QString wmi = p.matched("wmi");
  QString tag_command = p.matched("tag-command");
  QString tag_body_follow = p.matched("tag-body-follow");
  QString argument = p.matched("argument");
  graph_build.tag_command_entry_inline(wmi, {}, tag_command, tag_body_follow, argument);
  //graph_build.tag_body_leave();
 });

 add_rule( GTagML_context, "alt-tag-command-entry-inline",
   " ` (?<wmi> .tag-command-wrap-mode-indicator.? ) "
   " (?<tag-command> .valid-tag-command-name. ) "
   " <> (?<argument> [^;]* ) ;"
   ,[&]
 {
  QString wmi = p.matched("wmi");
  QString tag_command = p.matched("tag-command");
  QString argument = p.matched("argument");

  argument.replace('{', "! ");
  argument.replace('[', "? ");
  argument.replace('}', " ");
  argument.replace(']', " ");

  graph_build.tag_command_entry_inline(wmi, {}, tag_command, ";", argument);
  //graph_build.tag_body_leave();
 });


#ifdef HIDE
 add_rule( html_context, "html-tag-command-leave",
  " </ (?<tag-command> .valid-tag-command-name. ) "
  " > "
  ,[&]
 {
  QString tag_command = p.matched("tag-command");
  graph_build.check_html_tag_command_leave(tag_command, p.match_text());
 });

 add_rule( GTagML_context, "tag-command-leave",
  " < (?<load-connector> .valid-tag-command-name. )? "
  "  < (?<tag-command> .valid-tag-command-name. ) "
  " /? "  // this really needs to be set to check for matching env's
  " > "
           ,[&]
 {
  QString load_connector = p.matched("load-connector");
  QString tag_command = p.matched("tag-command");
  if(load_connector.isEmpty())
   graph_build.check_tag_command_leave(tag_command, p.match_text());
  else
   graph_build.tag_command_leave(load_connector, tag_command);
 });
#endif //def HIDE

 add_rule( GTagML_context, "tag-block-command-leave",
  "  ` (?<tag-command> .valid-tag-command-name. ) ` "
  ,[&]
 {
  QString tag_command = p.matched("tag-command");
  graph_build.check_tag_command_leave(tag_command, p.match_text());
 });

 add_rule( GTagML_context, "inline-tag-command-leave",
  " ` (?: / | (?= \\s))  "
           ,[&]
 {
  graph_build.inline_tag_command_leave();
 });


#ifdef HIDE
 add_rule( GTagML_context, "generic-tag-command-leave",
  " </>  "
           ,[&]
 {
  graph_build.tag_command_leave();
 });
#endif //def HIDE

//?
// add_rule( GTagML_context, "special-character-sequence",
//  " (?: %-- ) | (?: %[<>$'] ) | (&-\\S>\\w) | (&#\\w+;) | (&:\\w+;) "
//           ,[&]
// {
//  QString m = p.match_text();
//  graph_build.special_character_sequence(m);
// });


  add_rule( GTagML_context, "special-character-sequence",
   " (?: %-- ) | (?: ->- ) | (?: %\\.,{2,3} ) "
   "  | (?: ` \\( (?<bq-esc1> [^]]+ ) \\) ) "
   "  | (?: ` { (?<bq-esc2> [^}]+ ) } ) "
   "  | (?: ` \\[ (?<bq-esc3> [^]]+ ) \\] ) "
   "  | (?: ` < (?<bq-esc4> [^>]+ ) \\> ) "
   "  | (?: \\| (?<pipe-esc> [^|]+) \\| )"
 
          //? "| (?: %[<>$'] ) | (&-\\S>\\w) | (&#\\w+;) | (&:\\w+;) "
            ,[&]
  {
   int which = 1;
   QString esc = p.matched("bq-esc1");
   if(esc.isEmpty())
   {
    esc = p.matched("bq-esc2");
    ++which;
   }
   if(esc.isEmpty())
   {
    esc = p.matched("bq-esc3");
    ++which;
   }
   if(esc.isEmpty())
   {
    esc = p.matched("bq-esc4");
    ++which;
   }
   if(esc.isEmpty())
   {
    esc = p.matched("pipe-esc");
    ++which;
   }
   if(esc.isEmpty())
   {
    which = 0;
   }

   QString m = p.match_text();

   graph_build.special_character_sequence(m, esc, which);
  });


 add_rule( GTagML_context, "tile-acc",
  " . "
           ,[&]
 {
  graph_build.tile_acc(p.match_text());
 });


}
