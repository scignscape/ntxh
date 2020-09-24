
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "rz-ngml-output-axfd.h"


#include "rz-ngml-output-event-generator.h"
#include "kernel/document/rz-ngml-document.h"
#include "kernel/output/rz-ngml-output-bundle.h"
#include "tile/rz-ngml-token.h"
#include "kernel/graph/rz-ngml-node.h"
#include "tag-command/rz-ngml-tag-command.h"
#include "kernel/rz-ngml-root.h"
#include "tag-command/rz-ngml-command-callback.h"

#include "ngml-htxn/ngml-htxn-node.h"
#include "htxn/htxn-document-8b.h"
#include "htxn/glyph-layer-8b.h"

#include <QFile>
#include <QFileInfo>
#include <QDebug>

#include "rzns.h"


USING_RZNS(NGML)


NGML_Output_AXFD::NGML_Output_AXFD(NGML_Document& document, HTXN_Infoset_8b* infoset)
 :  NGML_Output_Base(document), NGML_Output_Event_Handler(), 
    infoset_(infoset), htxn_document_(nullptr),
    suppress_node_(nullptr)
{
 init_callbacks();
}

void NGML_Output_AXFD::init_callbacks()
{
 #include "rz-ngml-output-callbacks-common.h"

 #include "rz-ngml-output-axfd.callbacks.h"
}

void NGML_Output_AXFD::generate(QTextStream& qts)
{
 NGML_Output_Event_Generator events(*this, *this);
 events.generate(qts);
}

void NGML_Output_AXFD::write_axfd_output(QString& axfd_output)
{
 QTextStream qts(&axfd_output);
 generate(qts);
// xml_output.replace("$OP$", "(");
// xml_output.replace("$CP$", ")");
// xml_output.replace("$EQ$", "=");
}

void NGML_Output_AXFD::export_axfd(QString path)
{
  if(path.startsWith(".."))
 {
  path.remove(0, 1);
  path.prepend(document_.local_path());
 }
 else if(path.startsWith('.'))
 {
  QFileInfo qfi(document_.local_path());
  path.prepend(qfi.absolutePath() + '/' + qfi.completeBaseName());
 }

 QString axfd_output;
 write_axfd_output(axfd_output);

 QFile outfile(path);
 if(outfile.open(QFile::WriteOnly | QIODevice::Text))
 {
  outfile.write(axfd_output.toLatin1());
  outfile.close();
 }

}

void NGML_Output_AXFD::generate_root(const NGML_Output_Bundle& b, caon_ptr<NGML_Root> nr)
{
 nr->write_whitespace(b.qts);
}

caon_ptr<NGML_Command_Callback> NGML_Output_AXFD::check_command_callback(caon_ptr<NGML_Tag_Command> ntc)
{
 QString name = ntc->name();
 return callbacks_.value(name, caon_ptr<NGML_Command_Callback>( nullptr ));
}

void NGML_Output_AXFD::check_post_callback
 (QTextStream& qts, caon_ptr<NGML_Command_Callback> cb, caon_ptr<tNode> node, u4 index)
{
 if(cb->flags.has_post_callback)
 {
  cb->post_callback(qts, node, index, cb);
 }
}

void NGML_Output_AXFD::generate_tag_command_auto_leave(const NGML_Output_Bundle& b, caon_ptr<NGML_Tag_Command> ntc)
{ 
//? CHECK_SUPPRESS_NODE
//? b.qts << "/>";
}

void NGML_Output_AXFD::generate_tag_command_argument(const NGML_Output_Bundle& b,
  NGML_HTXN_Node& nhn)
{
//? CHECK_SUPPRESS_NODE
 HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);
//? b.qts << (nd->flags.optional? "<opt>" : "<man>");
 //?htxn_document_->write_minimal_xml_out(nd->get_layer(), nd->enter, nd->leave, b.qts);
//? b.qts << (nd->flags.optional? "<opt>" : "<man>");
}

void NGML_Output_AXFD::check_generate_tag_command_argument(const NGML_Output_Bundle& b,
  NGML_Tag_Command& ntc)
{
//? CHECK_SUPPRESS_NODE
 if(NGML_HTXN_Node* nhn = ntc.arg_ngml_htxn_node())
   generate_tag_command_argument(b, *nhn);

 ntc.each_arg_ngml_htxn_node([&b, this](NGML_HTXN_Node* nhn)
 {
  generate_tag_command_argument(b, *nhn);
 });
}

void NGML_Output_AXFD::generate_tag_command_entry(const NGML_Output_Bundle& b, NGML_HTXN_Node& nhn)
{ 
// CHECK_SUPPRESS_NODE
 HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);
 Glyph_Layer_8b* gl = nd->get_layer();
}


void NGML_Output_AXFD::generate_tag_command_entry(const NGML_Output_Bundle& b, caon_ptr<NGML_Tag_Command> ntc)
{ 
 CAON_PTR_B_DEBUG(NGML_Node ,node)
  //? chiefs_.push(b.node);
 switch(b.connection_descriptor)
 {
 case NGML_Connection_Descriptor::Tag_Command_Cross:
 case NGML_Connection_Descriptor::Tag_Command_Cross_From_Blank:
  //?
 case NGML_Connection_Descriptor::Tag_Command_Entry:

  caon_ptr<NGML_Command_Callback> cb = b.cb;

  if(cb)
  {
   CAON_PTR_DEBUG(NGML_Command_Callback ,cb)

   if(cb->flags.has_around_callback)
   {
    cb->around_callback(b.qts, b.node, b.index, b.cb);
    break;
   }

   if(cb->flags.has_pre_callback)
    cb->pre_callback(b.qts, b.node, b.index, b.cb);
   if(!cb->flags.pre_fallthrough)
    break;
  }
//?  CHECK_SUPPRESS_NODE

  if(htxn_document_)
  {
   if(NGML_HTXN_Node* nhn = ntc->ngml_htxn_node())
   {
//    if(ntc->flags.needs_sdi_mark)
//      generate_sdi_mark(ntc, b, *nhn);
//    generate_tag_command_entry(b, *nhn);
//    check_generate_tag_command_argument(b, *ntc);
    break;
   }
  }
 }
}


void NGML_Output_AXFD::generate_tag_command_leave(const NGML_Output_Bundle& b, NGML_HTXN_Node& nhn)
{ 
 HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);

 if(nd->flags.is_ghosted)
 {
  if(nd->flags.region_main_preempts_wrap)
    ; // nothing ...
  else if(nd->flags.optional)
  {
//   b.qts << "</opt>";
//?   reset_active_gap_code();
  }
  else
  {
//   b.qts << "</man>";
//?   reset_active_gap_code();
  }
 }
 else if(nd->flags.ref_preempts_wrap)
 {
  if(nd->flags.region)
  {
    // // should be some sort of whitespace flag ...
//?   check_reconcile_gap(b, 10);  //? b.qts << '\n';
   //?b.qts << "</" << end_names_.take(nd) << ">";
//?   reset_active_gap_code();
  }
 }
 else if(nd->flags.region)
 {
  if(nd->flags.main_only_block_environment)
    ; //?    check_reconcile_gap(b, 10);  //? b.qts << '\n';
  //?b.qts << "</" << end_names_.take(nd) << '>';
//?  reset_active_gap_code();
 }
 else if(nd->flags.wmi_none)
   ; // nothing
 else
 {
  //?b.qts << "</" << end_names_.take(nd) << '>';
//?  reset_active_gap_code();
 }
}



void NGML_Output_AXFD::generate_tag_command_leave(const NGML_Output_Bundle& b,
 caon_ptr<NGML_Tag_Command> ntc)
{
 if(b.cb)
 {
  if(b.cb->flags.has_post_callback)
  {
   b.cb->post_callback(b.qts, b.node, b.index, b.cb);
  }
  if(!b.cb->flags.post_fallthrough)
   return;
 }

//? CHECK_SUPPRESS_NODE
 if(htxn_document_)
 {
  if(NGML_HTXN_Node* nhn = ntc->ngml_htxn_node())
  {
   generate_tag_command_leave(b, *nhn);
   return;
  }
 }

 QString command_print_name;
 if(b.cb && b.cb->flags.has_rename)
  command_print_name = b.cb->rename_tag();
 else
  command_print_name = ntc->name();
//? b.qts << "</" << ntc->name() << '>';
}

void NGML_Output_AXFD::generate_tag_body_leave(const NGML_Output_Bundle& b, NGML_HTXN_Node& nhn)
{
//? CHECK_SUPPRESS_NODE
 HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);

 
 b.qts << '>';
}

void NGML_Output_AXFD::generate_tag_body_leave(const NGML_Output_Bundle& b, caon_ptr<NGML_Tag_Command> ntc)
{ 
//? CHECK_SUPPRESS_NODE
 CAON_PTR_DEBUG(NGML_Tag_Command ,ntc)

 if(htxn_document_)
 {
  if(NGML_HTXN_Node* nhn = ntc->ngml_htxn_node())
  {
   generate_tag_body_leave(b, *nhn);
   return;
  }
 }

//? b.qts << '>';
 ntc->write_whitespace(b.qts);
}

void NGML_Output_AXFD::generate_tile_via_htxn(const NGML_Output_Bundle& b, NGML_HTXN_Node& nhn)
{
//? CHECK_SUPPRESS_NODE
//? htxn_document_->write_minimal_xml_out(nhn.layer_code(), nhn.range(), b.qts);
 //? reset_active_gap_code();
}

