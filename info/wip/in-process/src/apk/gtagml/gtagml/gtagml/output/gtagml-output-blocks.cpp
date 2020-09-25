
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gtagml-output-blocks.h"

#include "gtagml-output-event-generator.h"
#include "kernel/document/gtagml-document.h"
#include "kernel/output/gtagml-output-bundle.h"
#include "tag-command/gtagml-tag-command.h"
#include "tile/gtagml-paralex-tile.h"

#include "tile/gtagml-tile.h"

#include "tag-command/gtagml-tag-command-callback.h"

#include "kernel/graph/gtagml-node.h"

#include "gh/gh-block-writer.h"

//?#include "ngml-htxn/ngml-htxn-node.h"


//#include "htxn/htxn-document-8b.h"
//#include "htxn/glyph-layer-8b.h"
//#include "htxn/infoset/sdi-callback-8b.h"


//?#include "gtagml-output-infoset.h"
//?#include "gtagml-output-htxn.h"

#include <QFile>
#include <QFileInfo>
#include <QRegularExpression>

#include <QDebug>

#include "kans.h"
USING_KANS(GTagML)

//struct _SDI_Callback : public SDI_Callback_8b
//{
// GTagML_Output_Infoset& infoset;
// u4 target_layer_id;
// _SDI_Callback(GTagML_Output_Infoset& noi, u4 u);
// void pre_write(Glyph_Layer_8b& gl, u4 pos,
//   Glyph_Argument_Package& gap, u8& skip_flag,
//   QString& pre_insert, QString& post_insert) Q_DECL_OVERRIDE;
//};

//_SDI_Callback::_SDI_Callback(GTagML_Output_Infoset& noi, u4 u)
//  :  infoset(noi), target_layer_id(u)
//{

//}


GTagML_Output_Blocks::GTagML_Output_Blocks(GTagML_Document& document, GH_Block_Writer* block_writer)
  :  GTagML_Output_Base(document), active_gap_code_(0), 
     suppress_node_(nullptr), infoset_(nullptr),
     last_ref_enter_(0), last_ref_leave_(0),
     block_writer_(block_writer)
{
 htxn_qts_.setString(&htxn_acc_);
 ws_qts_.setString(&ws_acc_);
 init_callbacks();
}

void GTagML_Output_Blocks::init_standard_8bit()
{
  block_writer_->init_standard_8bit();
}

void GTagML_Output_Blocks::init_callbacks()
{
 #include "gtagml-output-callbacks-common.h"

 #include "gtagml-output-latex.callbacks.h"
}

void GTagML_Output_Blocks::generate_tile(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Attribute_Tile> tile)
{
}


void GTagML_Output_Blocks::write_block_output(QMap<QString, QString>& block_output)
{
 QTextStream qts(&summary_);
 generate(qts);
 //latex_output.replace(QRegularExpression("\\n{2,}"), "\n\n");
}

void GTagML_Output_Blocks::generate(QTextStream& qts)
{
 GTagML_Output_Event_Generator events(*this, *this);
 events.generate(qts);
}

void GTagML_Output_Blocks::export_blocks(QString path)
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

 QMap<QString, QString> _output;
 write_block_output(_output);

 // //temp
// latex_output.replace("@@", "%%");
// latex_output.replace("#{", "\\scaps{");
// latex_output.replace("}#", "}");

 QFile outfile(path);
 if(outfile.open(QFile::WriteOnly | QIODevice::Text))
 {
  outfile.write(summary_.toLatin1());
  outfile.close();
 }
}

void GTagML_Output_Blocks::handle_annotation(caon_ptr<GTagML_Tile> tile, caon_ptr<GTagML_Annotation_Tile> atile)
{
//? document_.tag_command_annotation(tile, atile);
}

void GTagML_Output_Blocks::check_reconcile_gap(const GTagML_Output_Bundle& b, u1 new_code)
{
 check_reconcile_gap(b, new_code, active_gap_code_);
}

void GTagML_Output_Blocks::check_reconcile_gap(const GTagML_Output_Bundle& b, u1 new_code, u1& result)
{
 u2 code = (active_gap_code_ * 100) + new_code;

 switch(code)
 {
 case 2020:
  result = 20; break;
 case 2121: 
  result = 21; break;
 case 2120:
  result = 21; break;
 case 2010:
  result = 20; break;
 case 2111:
  result = 21; break;
 case 2110:
  result = 21; break;
 case 1010:
  result = 10; break;
 case 1111:
  result = 11; break;
 case 1110:
  result = 11; break;
 case 2101:
  result = 21; break;
 case 1101:
  result = 11; break;
 case 1011:
  b.qts << ' '; result = 11; break;
 case 2021:
  b.qts << ' '; result = 21; break;
 case 1001:
  b.qts << ' '; result = 11; break;
 case 2001:
  b.qts << ' '; result = 21; break;
 case 1:
  b.qts << ' '; result = 1; break;
 case 1020:
  b.qts << '\n'; result = 20; break;
 case 1120:
  b.qts << '\n'; result = 20; break;
 case 10:
  b.qts << '\n'; result = 10; break;
 case 1021:
  b.qts << "\n "; result = 21; break;
 case 1121:
  b.qts << "\n "; result = 21; break;
 case 11:
  b.qts << "\n "; result = 11; break;
 case 21:
  b.qts << "\n\n "; result = 21; break;
 case 20:
  b.qts << "\n\n"; result = 20; break;
 default: break;
 }
}


void GTagML_Output_Blocks::generate_tile(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Paralex_Tile> tile)
{
// tile->write_latex(b.qts);
// check_generate_whitespace(b, tile);
// reset_active_gap_code();
}


//void GTagML_Output_Blocks::generate_tag_command_entry(const GTagML_Output_Bundle& b, GTagML_HTXN_Node& nhn)
//{
// HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);
// Glyph_Layer_8b* gl = nd->get_layer();

// if(nd->flags.pre_line_double_gap)
//   check_reconcile_gap(b, 20);  //? b.qts << "\n\n";
// else if(nd->flags.pre_line_gap)
//   check_reconcile_gap(b, 10);  //? b.qts << '\n';
// else if(nd->flags.pre_space_gap)
//   check_reconcile_gap(b, 1);  //? b.qts << ' ';

// if(nd->flags.is_ghosted)
// {
//  if(nd->flags.region_main_preempts_wrap)
//  {
//   if(nd->flags.block_environment_marked_main)
//     check_reconcile_gap(b, 10);  //? b.qts << '\n';
//  }
//  else if(nd->flags.optional)
//  {
//   b.qts << '[';
//   reset_active_gap_code();
//  }
//  else
//  {
//   b.qts << '{';
//   reset_active_gap_code();
//  }
// }
// else
// {
//  htxn_document_->write_minimal_latex_out(gl, nd->enter,
//    nd->leave, htxn_qts_);

////  if(nd->flags.ref_preempts_wrap)
////    b.qts << '\\' << htxn_acc_;
//  if(nd->flags.region)
//  {
//   b.qts << "\\begin{" << htxn_acc_;// << '}';
//   region_end_names_[nd] = htxn_acc_;
//  }
//  else if(nd->flags.wmi_left)
//  {
//   if(nd->flags.wmi_with_space)
//     b.qts << "{\\" << htxn_acc_ << ' ';
//   else
//     b.qts << "{\\" << htxn_acc_;
//  }
//  else
//    b.qts << '\\' << htxn_acc_;// << '{';
//  htxn_acc_.clear();
//  htxn_qts_.reset();
// }
//}

//void _SDI_Callback::pre_write(Glyph_Layer_8b& gl, u4 pos,
//  Glyph_Argument_Package& gap, u8& skip_flag,
//  QString& pre_insert, QString& post_insert)
//{
// if(gl.id() != target_layer_id)
//   return;
// QString pre_result;
// QString post_result;
// u8 inserts = infoset.check_sdi_latex_insert(&gl, pos,
//   pre_result, post_result);

// if(inserts)
// {
//  pre_insert = pre_result;
//  post_insert = post_result;
// }
//}

//void GTagML_Output_Blocks::generate_tile_via_htxn(const GTagML_Output_Bundle& b, GTagML_HTXN_Node& nhn)
//{
// if(infoset_)
// {
//  u4 id = infoset_->GTagML_output_htxn()->main_gl()->id();
//  _SDI_Callback cb(*infoset_, id);
//  htxn_document_->write_minimal_latex_out(nhn.layer_code(), nhn.range(), b.qts, &cb);
// }
// else
//   htxn_document_->write_minimal_latex_out(nhn.layer_code(), nhn.range(), b.qts);
// reset_active_gap_code();
//}

//void GTagML_Output_Blocks::generate_tag_command_argument(const GTagML_Output_Bundle& b,
//  GTagML_HTXN_Node& nhn)
//{
// HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);
// b.qts << (nd->flags.optional? '[' : '{');
// htxn_document_->write_minimal_latex_out(nd->get_layer(), nd->enter, nd->leave, b.qts);
// b.qts << (nd->flags.optional? ']' : '}');
//}

void GTagML_Output_Blocks::check_generate_tag_command_argument(const GTagML_Output_Bundle& b,
  GTagML_Tag_Command& ntc)
{
 if(!ntc.argument().isEmpty())
 {
  QPair<u4, u4> pr;
  GH_Block_Base* bl =  block_writer_->write_mandatory_argument(ntc.argument(), pr);//  write
  ntc.add_arg_prenode(bl, pr.first, pr.second);
 }
  // ntc.each_arg_GTagML_htxn_node(
// if(GTagML_HTXN_Node* nhn = ntc.arg_GTagML_htxn_node())
//   generate_tag_command_argument(b, *nhn);

// ntc.each_arg_GTagML_htxn_node([&b, this](GTagML_HTXN_Node* nhn)
// {
//  generate_tag_command_argument(b, *nhn);
// });
}

GTagML_Output_Blocks::~GTagML_Output_Blocks()
{
// qDebug() << "del GTagML_Output_Blocks";
}


void GTagML_Output_Blocks::generate_tile(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Tile> tile)
{
 CAON_PTR_DEBUG(GTagML_Tile ,tile)
 QString rt = tile->raw_text();
 QPair<u4, u4> pr;

 GH_Block_Base* bl =  block_writer_->write_tile(rt, pr);//  write
 GH_Prenode* ghp = tile->init_prenode(bl, pr.first, pr.second);

 QMutableMapIterator<caon_ptr<GTagML_Tag_Command>, QPair<u4, u4>> it (ref_ranges_);
 while (it.hasNext())
 {
  it.next();
  if(it.value().first == 0)
    it.value().first = pr.first;
  it.value().second = pr.second;
 }


 if(last_ref_enter_ == 0)
   last_ref_enter_ = pr.first;
 last_ref_leave_ = pr.second;
}


void GTagML_Output_Blocks::generate_tag_command_entry(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Tag_Command> ntc)
{
 CAON_PTR_B_DEBUG(GTagML_Node ,node)
 CAON_PTR_DEBUG(GTagML_Tag_Command ,ntc)

 caon_ptr<GTagML_Tag_Command_Callback> cb = b.cb;


 switch(b.connection_descriptor)
 {
 case GTagML_Connection_Descriptor::Tag_Command_Cross_From_Blank:
 case GTagML_Connection_Descriptor::Tag_Command_Cross:
 case GTagML_Connection_Descriptor::Tag_Command_Entry:
  if(cb)
  {
   CAON_PTR_DEBUG(GTagML_Tag_Command_Callback ,cb)

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

//  if(htxn_document_)
//  {
//   if(GTagML_HTXN_Node* nhn = ntc->GTagML_htxn_node())
//   {
//    generate_tag_command_entry(b, *nhn);
//    check_generate_tag_command_argument(b, *ntc);
//    reset_active_gap_code();
//    break;
//   }
//  }

  if(ntc->flags.is_multi_mandatory)
  {

  }
  else if(ntc->flags.is_multi_optional)
  {

  }
  else
  {
   QPair<u4, u4> pr;
   GH_Block_Base* bl =  block_writer_->write_tag_command_name(ntc->name(), pr);//  write
   ntc->init_name_prenode(bl, pr);
  }

  check_generate_tag_command_argument(b, *ntc);

  if(!ntc->flags.is_self_closed)
    ref_ranges_.insert(ntc, {0, 0});

//  if(ntc->flags.is_region)
//    b.qts << "\\begin{" << ntc->latex_name();
//  else
//    b.qts << '\\' << ntc->latex_name();

  reset_active_gap_code();
  break;
 }

 if(caon_ptr<tNode> n = qry_.Tag_Command_Annotation(b.node))
 {
  if(caon_ptr<tNode> mt = qry_.Tag_Command_Main_Tile(b.node))
  {
   if(caon_ptr<GTagML_Tile> nt = mt->GTagML_tile())
    tag_command_annotation(nt, n);
  }
 }
}

//void GTagML_Output_Blocks::generate_tag_command_leave(const GTagML_Output_Bundle& b, GTagML_HTXN_Node& nhn)
//{
// HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);

// if(nd->flags.is_ghosted)
// {
//  if(nd->flags.region_main_preempts_wrap)
//    ; // nothing ...
//  else if(nd->flags.optional)
//  {
//   b.qts << ']';
//   reset_active_gap_code();
//  }
//  else
//  {
//   b.qts << '}';
//   reset_active_gap_code();
//  }
// }
// else if(nd->flags.ref_preempts_wrap)
// {
//  if(nd->flags.region)
//  {
//    // // should be some sort of whitespace flag ...
//   check_reconcile_gap(b, 10);  //? b.qts << '\n';
//   b.qts << "\\end{" << region_end_names_.take(nd) << '}';
//   reset_active_gap_code();
//  }
// }
// else if(nd->flags.region)
// {
//  if(nd->flags.main_only_block_environment)
//    check_reconcile_gap(b, 10);  //? b.qts << '\n';
//  b.qts << "\\end{" << region_end_names_.take(nd) << '}';
//  reset_active_gap_code();
// }
// else if(nd->flags.wmi_none)
//   ; // nothing
// else
// {
//  b.qts << '}';
//  reset_active_gap_code();
// }

// if(nd->flags.post_line_double_gap)
//   check_reconcile_gap(b, 20);  //? b.qts << "\n\n";
// else if(nd->flags.post_line_gap)
//   check_reconcile_gap(b, 10);  //? b.qts << '\n';
// else if(nd->flags.post_space_gap)
//   check_reconcile_gap(b, 1);  //? b.qts << ' ';
//}


void GTagML_Output_Blocks::generate_tag_command_leave(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Tag_Command> ntc)
{
 CAON_PTR_DEBUG(GTagML_Tag_Command ,ntc)

 if(ref_ranges_.contains(ntc))
 {
  QPair<u4, u4> pr = ref_ranges_.take(ntc);
  ntc->set_ref_enter(pr.first);
  ntc->set_ref_leave(pr.second);
 }

 if(b.cb)
 {
  if(b.cb->flags.has_post_callback)
  {
   b.cb->post_callback(b.qts, b.node, b.index, b.cb);
  }
  if(!b.cb->flags.post_fallthrough)
   return;
 }

// if(htxn_document_)
// {
//  if(GTagML_HTXN_Node* nhn = ntc->GTagML_htxn_node())
//  {
//   generate_tag_command_leave(b, *nhn);
//   return;
//  }
// }

// if(ntc->flags.is_region)
//   b.qts << "\\end{" << ntc->latex_name() << '}';
// else
//   b.qts << '}';

 reset_active_gap_code();
}

void GTagML_Output_Blocks::check_generate_whitespace(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Tile> tile)
{
 GTagML_Output_Event_Handler::check_generate_whitespace(b, tile);
}

void GTagML_Output_Blocks::check_generate_whitespace(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Paralex_Tile> tile)
{
 GTagML_Output_Event_Handler::check_generate_whitespace(b, tile);
}

u1 GTagML_Output_Blocks::get_ws_gap_code()
{
 return get_ws_gap_code(ws_acc_);
}

u1 GTagML_Output_Blocks::get_ws_gap_code(const QString& str)
{
 if(str.endsWith("\n\n"))
   return 20;
 if(str.endsWith("\n"))
   return 10;
 if(str.endsWith("\n\n "))
   return 21;
 if(str.endsWith("\n "))
   return 11;
 if(str.endsWith(' '))
   return 1;
 return 0;
}


//void GTagML_Output_Blocks::check_generate_whitespace(const GTagML_Output_Bundle& b, GTagML_HTXN_Node& nhn)
//{
// HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);
// if(!nd)
//   return;
// if(nd->flags.wmi_none)
//   return;
//  // // or take ws from the node detail?

// nhn.write_whitespace(ws_qts_); //b.qts);

// if(ws_acc_.isEmpty())
// {
//  ws_qts_.reset();
//  return;
// }

// u1 wsgc = get_ws_gap_code();

// if(active_gap_code_ == 0)
// {
//  active_gap_code_ = wsgc;
//  b.qts << ws_acc_;
//  ws_acc_.clear();
//  ws_qts_.reset();
//  return;
// }
// if(wsgc == 0)
// {
//  b.qts << ws_acc_;
//  ws_acc_.clear();
//  ws_qts_.reset();
//  reset_active_gap_code();
//  return;
// }

// u2 code = (active_gap_code_ * 100) + wsgc;

// switch (code)
// {
// case 2121:
//   ws_acc_.chop(3); break;
// case 2020:
// case 1111:
//   ws_acc_.chop(2); break;
// case 1010:
// case 101:
//   ws_acc_.chop(1); break;
// case 2010:
//   ws_acc_.chop(1); break;
// case 1020:
//   ws_acc_.chop(1); active_gap_code_ = 20; break;
// case 2110:
//   active_gap_code_ = 10; break;
// case 2120:
//   active_gap_code_ = 20; break;
// case 2111:
//   ws_acc_.chop(2); break;
// case 2101:
//   ws_acc_.chop(1); break;
// case 110:
//  active_gap_code_ = 10; break;
// case 111:
//  active_gap_code_ = 11; break;
// case 120:
//  active_gap_code_ = 20; break;
// case 121:
//  active_gap_code_ = 21; break;
// default:
//  reset_active_gap_code();
// }

// b.qts << ws_acc_;
// ws_acc_.clear();
// ws_qts_.reset();
//}

void GTagML_Output_Blocks::check_generate_whitespace(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Tag_Command> ntc)
{
 CAON_PTR_DEBUG(GTagML_Tag_Command ,ntc)
// if(htxn_document_)
// {
//  if(GTagML_HTXN_Node* nhn = ntc->GTagML_htxn_node())
//  {
//   check_generate_whitespace(b, *nhn);
//   return;
//  }
// }
 GTagML_Output_Event_Handler::check_generate_whitespace(b, ntc);
 //ntc->write_whitespace(b.qts);
}

//void GTagML_Output_Blocks::generate_tag_body_leave(const GTagML_Output_Bundle& b, GTagML_HTXN_Node& nhn)
//{
// HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);

// if(nd->flags.is_ghosted)
//   ; // nothing
// else if(nd->flags.wmi_left)
//   ; // nothing
// else if(nd->flags.wmi_none)
// {
//   ; // nothing
// }
// else if(nd->flags.ref_preempts_wrap)
// {
//  if(nd->flags.region)
//  {
//   b.qts << '}';
//   reset_active_gap_code();
//  }
// }
// else if(nd->flags.region)
// {
//  b.qts << '}';
//  if(nd->flags.main_only_block_environment)
//  {
//    //?check_reconcile_gap(b, 10);  //?
//   b.qts << '\n';
//   active_gap_code_ = 10;
//  }
//  reset_active_gap_code();
// }
// else
// {
//  b.qts << '{';
//  reset_active_gap_code();
// }
//}

void GTagML_Output_Blocks::generate_tag_body_leave(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Tag_Command> ntc)
{
 CAON_PTR_DEBUG(GTagML_Tag_Command ,ntc)

// if(htxn_document_)
// {
//  if(GTagML_HTXN_Node* nhn = ntc->GTagML_htxn_node())
//  {
//   generate_tag_body_leave(b, *nhn);
//   return;
//  }
// }

// if(ntc->flags.is_region)
//   b.qts << '}';
// else
//  b.qts << '{';

 reset_active_gap_code();
}

caon_ptr<GTagML_Tag_Command_Callback> GTagML_Output_Blocks::check_command_callback(caon_ptr<GTagML_Tag_Command> ntc)
{
 QString name = ntc->name();
 return callbacks_.value(name, caon_ptr<GTagML_Tag_Command_Callback> ( nullptr ));
}

