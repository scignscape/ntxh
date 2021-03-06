
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gtagml-output-sdi-infoset.h"

#include "gtagml-output-event-generator.h"
#include "kernel/document/gtagml-document.h"
#include "kernel/output/gtagml-output-bundle.h"
#include "tag-command/gtagml-tag-command.h"
#include "tile/gtagml-paralex-tile.h"

#include "tile/gtagml-tile.h"

#include "gh/gh-block-base.h"

#include "tag-command/gtagml-tag-command-callback.h"

#include "kernel/graph/gtagml-node.h"

#include "gh/gh-prenode.h"

//?#include "GTagML-htxn/GTagML-htxn-node.h"


//#include "htxn/htxn-document-8b.h"
//#include "htxn/glyph-layer-8b.h"
//#include "htxn/infoset/sdi-callback-8b.h"


//?#include "gtagml-output-infoset.h"
//?#include "gtagml-output-htxn.h"

#include "gh/gh-block-writer.h"

#include "sdi/gh-sdi-document.h"

#include <QFile>
#include <QFileInfo>
#include <QRegularExpression>

#include <QDebug>

#include "kans.h"
USING_KANS(GTagML)

#define CHECK_SUPPRESS_NODE if(suppress_node_) return;

GTagML_Output_SDI_Infoset::GTagML_Output_SDI_Infoset(GTagML_Document& document,
                                             GH_Block_Writer* block_writer) //, HTXN_Infoset_8b* infoset)
 :  GTagML_Output_Base(document), GTagML_Output_Event_Handler(),
    //infoset_(infoset),
    suppress_node_(nullptr),
    GTagML_output_htxn_(nullptr),
    held_sdi_sentence_end_index_(0),
    canceled_sdi_sentence_start_index_(0),
    held_sdi_sentence_end_node_(nullptr), block_writer_(block_writer),
    sdi_document_(new GH_SDI_Document)
{
 //?htxn_qts_.setString(&htxn_acc_);
 init_callbacks();
 review_qts_.setString(&review_, QIODevice::WriteOnly);
 sdi_document_->set_sdi_infoset_output(this);
}

void GTagML_Output_SDI_Infoset::init_callbacks()
{
 #include "gtagml-output-callbacks-common.h"

 #include "gtagml-output-sdi-infoset.callbacks.h"
}

// // common functionality for both insert methods ...

void _insert_start(QTextStream& qts, u8* u, QVector<caon_ptr<GTagML_Node>>* vec, u4 index, QString& pre_result, caon_ptr<GTagML_Node> n,
  u4& canceled_sdi_sentence_start_index)
{
 if(index == canceled_sdi_sentence_start_index)
 {
  // //  the \> supplants the \+ ...
  canceled_sdi_sentence_start_index = 0;
 }
 else
 {
  qts << "\\+ " << index << '\n';
  pre_result.append("\\+");
  if(u)
    ++*u;
  if(vec)
    vec->push_back(n);
 }
}

void _insert_end(QTextStream& qts, u8* u, QVector<caon_ptr<GTagML_Node>>* vec, u4 index,
  u4 new_index, QString& post_result,
  QMap<u4, QPair<caon_ptr<GTagML_Node>, u4>>& marked_sentence_starts,
  caon_ptr<GTagML_Node> n,
  u4& held_sdi_sentence_end_index,
  u4& canceled_sdi_sentence_start_index,
  caon_ptr<GTagML_Node>* held_sdi_sentence_end_node)
{
 if(new_index == index)
 {
  qts << "\\; " << index << '\n';
  post_result.append("\\;");
  if(u)
    ++*u;
  if(vec)
    vec->push_back(n);
 }
 else
 {
  // // this assumes the post-space will always be
   //   separated from a new sentence by one space or newline ...
  if(marked_sentence_starts.contains(new_index + 2))
  {
   held_sdi_sentence_end_index = new_index;
   if(held_sdi_sentence_end_node)
     *held_sdi_sentence_end_node = n;
   canceled_sdi_sentence_start_index = new_index + 2;
  }
  else
  {
   qts << "\\; " << index << '\n';
   post_result.append("\\;");
   if(u)
     ++*u;
   if(vec)
     vec->push_back(n);
  }
 }
}

void _insert_start(QTextStream& qts, u8* u, u4 index, QString& pre_result, u4& canceled_sdi_sentence_start_index)
{
 _insert_start(qts, u, nullptr, index, pre_result, nullptr, canceled_sdi_sentence_start_index);
}

void _insert_start(QTextStream& qts, QVector<caon_ptr<GTagML_Node>>* vec, u4 index,
  QString& pre_result, caon_ptr<GTagML_Node> n, u4& canceled_sdi_sentence_start_index)
{
 _insert_start(qts, nullptr, vec, index, pre_result, n, canceled_sdi_sentence_start_index);
}

void _insert_end(QTextStream& qts, u8* u, u4 index, u4 new_index,
  QString& post_result, QMap<u4, QPair<caon_ptr<GTagML_Node>, u4>>& marked_sentence_starts,
  u4& held_sdi_sentence_end_index,
  u4& canceled_sdi_sentence_start_index)
{
 _insert_end(qts, u, nullptr, index, new_index, post_result,
   marked_sentence_starts, nullptr,
   held_sdi_sentence_end_index, canceled_sdi_sentence_start_index,
   nullptr);
}

void _insert_end(QTextStream& qts,
  QVector<caon_ptr<GTagML_Node>>* vec,
  u4 index, u4 new_index,
  QString& post_result,
  QMap<u4, QPair<caon_ptr<GTagML_Node>, u4>>& marked_sentence_starts, caon_ptr<GTagML_Node> n,
  u4& held_sdi_sentence_end_index,
  u4& canceled_sdi_sentence_start_index,
  caon_ptr<GTagML_Node>* held_sdi_sentence_end_node)
{
 _insert_end(qts, nullptr, vec, index, new_index, post_result,
   marked_sentence_starts, n,
   held_sdi_sentence_end_index, canceled_sdi_sentence_start_index,
   held_sdi_sentence_end_node);
}

u4 GTagML_Output_SDI_Infoset::write_ntxh_sentences(QTextStream& qts, u4 paragraph_id,  u4 s, u4 e, u4 sentence_id)
{
 u4 result = sentence_id;
 QMapIterator<u4, QPair<caon_ptr<tNode>, u4>> it(marked_sentence_starts_);
 while(it.hasNext())
 {
  it.next();
  if(it.key() > e)
    return result;
  if(it.key() < s)
    continue;
  ++result;
  u4 se = it.value().second;
  u4 seg = 0;
  auto it1 = marked_sentence_ends_.find(se);
  if(it1 != marked_sentence_ends_.end())
  {
   seg = it1.value().second;
  }

  qts << QString(R"(
!/ GH_Sdi_Sentence
$i: %1
$p: %2
$s: %3
$e: %4
$g: %5
/!
<>>
)").arg(sentence_id).arg(paragraph_id).arg(it.key()).arg(se).arg(seg);
 }
}

void GTagML_Output_SDI_Infoset::write_ntxh(QTextStream& qts)
{
 QMapIterator<u4, QPair<caon_ptr<tNode>, u4>> it(marked_paragraph_starts_);
 u4 id = 0;
 u4 sid = 0;
 while(it.hasNext())
 {
  ++id;
  it.next();
  u4 s = it.key();
  u4 e = it.value().second;
  qts << QString(R"(
!/ GH_Sdi_Paragraph
$i: %1
$s: %2
$e: %3
/!
<<>

)").arg(id).arg(s).arg(e);

  sid = write_ntxh_sentences(qts, id, s, e, sid);
 }
}

void GTagML_Output_SDI_Infoset::finalize_paragraph_boundaries(GH_Block_Base& bl)
{
 static QString* ps = new QString("\\:");
 static QString* pe = new QString("\\<");
 {
  QMapIterator<u4, QPair<caon_ptr<tNode>, u4>> it(marked_paragraph_starts_);
  while(it.hasNext())
  {
   it.next();
   u4 i = it.key();
   bl.set_pre_insert(i, ps);
  }
 }
 {
  QMapIterator<u4, caon_ptr<tNode>> it(marked_paragraph_ends_);
  while(it.hasNext())
  {
   it.next();
   u4 i = it.key();
   bl.set_insert(i, pe);
  }
 }
}

void GTagML_Output_SDI_Infoset::finalize_sentence_boundaries(GH_Block_Base& bl)
{
 QMapIterator<u4, QPair<caon_ptr<tNode>, u4>> it(marked_sentence_starts_);
 while(it.hasNext())
 {
  it.next();
  u4 send = it.value().second;
  auto it1 = marked_sentence_ends_.find(send);
  if(it1 != marked_sentence_ends_.end())
  {
   bl.flag_as_sentence_end(send, it1.value().second);
  }

 }
}


u8 GTagML_Output_SDI_Infoset::check_sdi_latex_insert(GH_Block_Base* bl, u4 index, QString& pre_result, QString& post_result)
{
 u8 count = 0;
 if(index == held_sdi_sentence_end_index_)
 {
  ++count;
  held_sdi_sentence_end_index_ = 0;
  review_qts_ << "\\> " << index << '\n';
  post_result.append("\\>");
 }
 {
  auto it = marked_paragraph_starts_.find(index);
  if(it != marked_paragraph_starts_.end())
  {
   review_qts_ << "\\: " << index << '\n';
   pre_result.append("\\:");
   ++count;
  }
 }
 {
  auto it = marked_sentence_starts_.find(index);
  if(it != marked_sentence_starts_.end())
  {
   _insert_start(review_qts_, &count, index, pre_result, canceled_sdi_sentence_start_index_);
//   if(index == canceled_sdi_sentence_start_index_)
//   {
//    // //  the \> supplants the \+ ...
//    canceled_sdi_sentence_start_index_ = 0;
//   }
//   else
//   {
//    pre_result.append("\\+");
//    ++count;
//   }
  }
 }
 {
  auto it = sdi_marks_.find(index);
  if(it != sdi_marks_.end())
  {
   review_qts_ << "\\? " << index << '\n';
   if(it.value().first.isEmpty())
     pre_result.append("\\?");
   else
     pre_result.append(QString("\\?[%1]").arg(it.value().first));
   ++count;
  }
 }
 {
  auto it = sdi_secondary_marks_.find(index);
  if(it != sdi_secondary_marks_.end())
  {
   review_qts_ << "\\, " << index << '\n';
   if(it.value().first.isEmpty())
     post_result.append("\\,");
   else
     post_result.append(QString("\\,[%1]").arg(it.value().first));
   ++count;
  }
 }
 {
  auto it = marked_sentence_ends_.find(index);
  if(it != marked_sentence_ends_.end())
  {
   u4 new_index;// = htxn_document_->
     //check_advance_to_sentence_end_space(bl, index);

   _insert_end(review_qts_, &count, index, new_index, post_result,
     marked_sentence_starts_,
     held_sdi_sentence_end_index_,
     canceled_sdi_sentence_start_index_);

  }
 }
 {
  auto it = marked_paragraph_ends_.find(index);
  if(it != marked_paragraph_ends_.end())
  {
   review_qts_ << "\\< " << index << '\n';
   post_result.append("\\<");
   ++count;
  }
 }
}

QVector<caon_ptr<GTagML_Node>> GTagML_Output_SDI_Infoset::get_sdi_latex_insert_nodes(GH_Block_Base* bl, u4 index, QString& pre_result, QString& post_result)
{
 QVector<caon_ptr<tNode>> rvec;
 if(index == held_sdi_sentence_end_index_)
 {
  rvec.push_back(held_sdi_sentence_end_node_);
  held_sdi_sentence_end_index_ = 0;
  post_result.append("\\>");
  review_qts_ << "\\> " << index << '\n';
 }
 {
  auto it = marked_paragraph_starts_.find(index);
  if(it != marked_paragraph_starts_.end())
  {
   review_qts_ << "\\: " << index << '\n';
   pre_result.append("\\:");
   rvec.push_back(it.value().first);
  }
 }
 {
  auto it = marked_sentence_starts_.find(index);
  if(it != marked_sentence_starts_.end())
  {
   _insert_start(review_qts_, &rvec, index, pre_result, it.value().first, canceled_sdi_sentence_start_index_);
//   pre_result.append("\\+");
//   rvec.push_back(it.value());
  }
 }
 {
  auto it = sdi_marks_.find(index);
  if(it != sdi_marks_.end())
  {
   review_qts_ << "\\? " << index << '\n';
   if(it.value().first.isEmpty())
     pre_result.append("\\?");
   else
     pre_result.append(QString("\\?[%1]").arg(it.value().first));
   rvec.push_back(it.value().second);
  }
 }
 {
  auto it = sdi_secondary_marks_.find(index);
  if(it != sdi_secondary_marks_.end())
  {
   review_qts_ << "\\, " << index << '\n';
   if(it.value().first.isEmpty())
     post_result.append("\\,");
   else
     post_result.append(QString("\\,[%1]").arg(it.value().first));
   rvec.push_back(it.value().second);
  }
 }
 {
  auto it = marked_sentence_ends_.find(index);
  if(it != marked_sentence_ends_.end())
  {
   u4 new_index;// = //htxn_document_->
     //check_advance_to_sentence_end_space(bl, index);

   _insert_end(review_qts_, &rvec, index, new_index, post_result,
      marked_sentence_starts_,
      it.value().first,
      held_sdi_sentence_end_index_,
      canceled_sdi_sentence_start_index_,
      &held_sdi_sentence_end_node_);

//   u4 new_index = htxn_document_->
//     check_advance_to_sentence_end_space(bl, index);
//   if(new_index == index)
//     post_result.append("\\;");
//   else
//     post_result.append("\\>");

//   rvec.push_back(it.value());
  }
 }
 {
  auto it = marked_paragraph_ends_.find(index);
  if(it != marked_paragraph_ends_.end())
  {
   review_qts_ << "\\< " << index << '\n';
   pre_result.append("\\<");
   rvec.push_back(it.value());
  }
 }
 return rvec;
}


void GTagML_Output_SDI_Infoset::write_infoset_output(QString& output)
{
 QTextStream qts(&output);
 generate(qts);
}

void GTagML_Output_SDI_Infoset::generate(QTextStream& qts)
{
 GTagML_Output_Event_Generator events(*this, *this);
 events.generate(qts);
}

void GTagML_Output_SDI_Infoset::generate_root(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Root> nr)
{
}

void GTagML_Output_SDI_Infoset::export_infoset(QString path)
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
 QString output;
 write_infoset_output(output);

 QFile outfile(path);
 if(outfile.open(QFile::WriteOnly | QIODevice::Text))
 {
  outfile.write(output.toLatin1());
  outfile.close();
 }
}

void GTagML_Output_SDI_Infoset::export_infoset_review(QString path)
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
 QFile outfile(path);
 if(outfile.open(QFile::WriteOnly | QIODevice::Text))
 {
  outfile.write(review_.toLatin1());
  outfile.close();
 }
}

caon_ptr<GTagML_Tag_Command_Callback> GTagML_Output_SDI_Infoset::check_command_callback(caon_ptr<GTagML_Tag_Command> ntc)
{
 QString name = ntc->name();
 return callbacks_.value(name, caon_ptr<GTagML_Tag_Command_Callback>( nullptr ));
}


//caon_ptr<GTagML_Tag_Command_Callback> GTagML_Output_SDI_Infoset::check_callback
// (QTextStream& qts, caon_ptr<GTagML_Tag_Command> ntc, caon_ptr<tNode> node)
//{
// caon_ptr<GTagML_Tag_Command_Callback> result = nullptr;
// QString name = ntc->name();
// if(callbacks_.contains(name))
// {
//  result = callbacks_[name];
//  if(result->flags.has_pre_callback)
//  {
//   result->pre_callback(qts, node, result);
//  }
// }
// return result;
//}

void GTagML_Output_SDI_Infoset::check_post_callback
 (QTextStream& qts, caon_ptr<GTagML_Tag_Command_Callback> cb, caon_ptr<tNode> node, u4 index)
{
 if(cb->flags.has_post_callback)
 {
  cb->post_callback(qts, node, index, cb);
 }
}

void GTagML_Output_SDI_Infoset::generate_tag_command_auto_leave(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Tag_Command> ntc)
{
 CHECK_SUPPRESS_NODE
//? b.qts << "/>";
}

void GTagML_Output_SDI_Infoset::generate_tag_command_argument(const GTagML_Output_Bundle& b,
  GTagML_HTXN_Node& nhn)
{
 CHECK_SUPPRESS_NODE
// HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);
// b.qts << (nd->flags.optional? "<opt>" : "<man>");
// //?htxn_document_->write_minimal_xml_out(nd->get_layer(), nd->enter, nd->leave, b.qts);
// b.qts << (nd->flags.optional? "<opt>" : "<man>");
}

void GTagML_Output_SDI_Infoset::check_generate_tag_command_argument(const GTagML_Output_Bundle& b,
  GTagML_Tag_Command& ntc)
{
 CHECK_SUPPRESS_NODE
 if(GTagML_HTXN_Node* nhn = ntc.arg_GTagML_htxn_node())
   generate_tag_command_argument(b, *nhn);

 ntc.each_arg_GTagML_htxn_node([&b, this](GTagML_HTXN_Node* nhn)
 {
  generate_tag_command_argument(b, *nhn);
 });
}

void GTagML_Output_SDI_Infoset::generate_sdi_mark(caon_ptr<GTagML_Tag_Command> ntc,
  const GTagML_Output_Bundle& b,  GH_Prenode& ghp)
{
 // GH_Prenode* ghp =
// HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);
// Glyph_Layer_8b* bl = nd->get_layer();

 GH_Block_Base* bl = ghp.get_block();
 qDebug() << "Name: " << ntc->name();

 review_qts_ << ntc->name() << " " << ghp.range().first << " " << ghp.range().second << "\n";
}

void GTagML_Output_SDI_Infoset::generate_tag_command_entry(const GTagML_Output_Bundle& b, GTagML_HTXN_Node& nhn)
{
// CHECK_SUPPRESS_NODE
// HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);
// Glyph_Layer_8b* bl = nd->get_layer();


#ifdef HIDE
 if(nd->flags.pre_line_double_gap)
   check_reconcile_gap(b, 20);  //? b.qts << "\n\n";
 else if(nd->flags.pre_line_gap)
   check_reconcile_gap(b, 10);  //? b.qts << '\n';
 else if(nd->flags.pre_space_gap)
   check_reconcile_gap(b, 1);  //? b.qts << ' ';

 if(nd->flags.is_ghosted)
 {
  if(nd->flags.region_main_preempts_wrap)
  {
   if(nd->flags.block_environment_marked_main)
     ; //? check_reconcile_gap(b, 10);  //? b.qts << '\n';
  }
  else if(nd->flags.optional)
  {
   b.qts << "<opt>";
 //?  reset_active_gap_code();
  }
  else
  {
   b.qts << "<man>";
//?   reset_active_gap_code();
  }
 }
 else
 {
//?  htxn_document_->write_minimal_xml_out(bl, nd->enter,
//?    nd->leave, htxn_qts_);

  b.qts << '<' << htxn_acc_;// << '}';
  end_names_[nd] = htxn_acc_;
  htxn_acc_.clear();
  htxn_qts_.reset();
 }
#endif //def HIDE
}


void GTagML_Output_SDI_Infoset::generate_tag_command_entry(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Tag_Command> ntc)
{
 CAON_PTR_B_DEBUG(GTagML_Node ,node)
 chiefs_.push(b.node);
 switch(b.connection_descriptor)
 {
 case GTagML_Connection_Descriptor::Tag_Command_Cross:
 case GTagML_Connection_Descriptor::Tag_Command_Cross_From_Blank:
  //?
 case GTagML_Connection_Descriptor::Tag_Command_Entry:

  caon_ptr<GTagML_Tag_Command_Callback> cb = b.cb;

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
//?  CHECK_SUPPRESS_NODE

//  if(htxn_document_)
//  {
//   if(GTagML_HTXN_Node* nhn = ntc->GTagML_htxn_node())
//   {
//    if(ntc->flags.needs_sdi_mark)
//      generate_sdi_mark(ntc, b, *nhn);
////    generate_tag_command_entry(b, *nhn);
////    check_generate_tag_command_argument(b, *ntc);
//    break;
//   }
//  }

 }
}

void GTagML_Output_SDI_Infoset::check_sentence_boundaries(QTextStream& qts, caon_ptr<tNode> node)
{
 CAON_PTR_DEBUG(tNode ,node)
 if(caon_ptr<GTagML_Tag_Command> ntc = node->GTagML_tag_command())
 {
  CAON_PTR_DEBUG(GTagML_Tag_Command ,ntc)
  u4 enter = ntc->ref_enter();
  if(enter > 1) // = ntc->prenode())
  {
   u4 leave = ntc->ref_leave();// = ghp->get_ref_enter();
   if(leave >= enter)
   {
     // //  this assumes that ntc is a paragraph ...
    marked_paragraph_starts_[enter] = {node, leave};
    marked_paragraph_ends_[leave] = node;
    GH_Block_Base* bl = block_writer_->current_main_text_block();
    check_sentence_boundaries(qts, node, *bl, //*ghp,
                               enter, leave);
   }
  }
 }
}

void GTagML_Output_SDI_Infoset::mark_sentence(QTextStream& qts, caon_ptr<tNode> node,
  u4 enter, u4 leave, u4 sp)//, u4 pleave)
{
 marked_sentence_starts_[enter] = {node, leave};
 marked_sentence_ends_[leave] = {node, sp};
 //qts << "\n$ " << enter << " " << leave;
}

void GTagML_Output_SDI_Infoset::check_sentence_boundaries(QTextStream& qts,
  caon_ptr<tNode> node, GH_Block_Base& bl,  //GH_Prenode& ghp,
                                                      u4 enter, u4 leave)
{
 CAON_PTR_DEBUG(tNode ,node)

 QMap<u4, QString> notes;
// Glyph_Layer_8b* bl = GTagML_output_htxn_->main_bl();
// htxn_document_->check_sentence_boundaries(bl,
//   enter, leave, notes);
 u4 i = enter;
 while(i <= leave)
 {
  u4 ss = 0;
  if(!sdi_document_->scan_for_sentence_start(bl, i, leave, ss))
    break;
  u4 se = 0;
  u4 ses = 0;
  if(!sdi_document_->scan_for_sentence_end(bl, i, leave, se, ses))
    break;

//  if(!htxn_document_->scan_for_sentence_end(bl, ss, leave, se))
//    break;

  mark_sentence(qts, node, ss, se, ses);
  if(ses == 0)
    i = se + 1;
  else
    i = ses + 1;
 }
}
// QSet<u4> marked_sentence_starts_;
// QSet<u4> marked_non_pivot_sentence_ends_;

void GTagML_Output_SDI_Infoset::generate_tag_command_leave(const GTagML_Output_Bundle& b, GTagML_HTXN_Node& nhn)
{
// HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);

// if(nd->flags.is_ghosted)
// {
//  if(nd->flags.region_main_preempts_wrap)
//    ; // nothing ...
//  else if(nd->flags.optional)
//  {
//   b.qts << "</opt>";
////?   reset_active_gap_code();
//  }
//  else
//  {
//   b.qts << "</man>";
////?   reset_active_gap_code();
//  }
// }
// else if(nd->flags.ref_preempts_wrap)
// {
//  if(nd->flags.region)
//  {
//    // // should be some sort of whitespace flag ...
////?   check_reconcile_gap(b, 10);  //? b.qts << '\n';
//   //?b.qts << "</" << end_names_.take(nd) << ">";
////?   reset_active_gap_code();
//  }
// }
// else if(nd->flags.region)
// {
//  if(nd->flags.main_only_block_environment)
//    ; //?    check_reconcile_gap(b, 10);  //? b.qts << '\n';
//  //?b.qts << "</" << end_names_.take(nd) << '>';
////?  reset_active_gap_code();
// }
// else if(nd->flags.wmi_none)
//   ; // nothing
// else
// {
//  //?b.qts << "</" << end_names_.take(nd) << '>';
////?  reset_active_gap_code();
// }

#ifdef HIDE
 if(nd->flags.post_line_double_gap)
   check_reconcile_gap(b, 20);  //? b.qts << "\n\n";
 else if(nd->flags.post_line_gap)
   check_reconcile_gap(b, 10);  //? b.qts << '\n';
 else if(nd->flags.post_space_gap)
   check_reconcile_gap(b, 1);  //? b.qts << ' ';
#endif // HIDE
}



void GTagML_Output_SDI_Infoset::generate_tag_command_leave(const GTagML_Output_Bundle& b,
 caon_ptr<GTagML_Tag_Command> ntc)
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

 CHECK_SUPPRESS_NODE
 if(htxn_document_)
 {
  if(GTagML_HTXN_Node* nhn = ntc->GTagML_htxn_node())
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
 b.qts << "</" << ntc->name() << '>';
}

void GTagML_Output_SDI_Infoset::generate_tag_body_leave(const GTagML_Output_Bundle& b, GTagML_HTXN_Node& nhn)
{
 CHECK_SUPPRESS_NODE
// HTXN_Node_Detail* nd = nhn.get_node_detail(htxn_document_);

#ifdef HIDE
 if(nd->flags.is_ghosted)
   ; // nothing
 else if(nd->flags.wmi_left)
   ; // nothing
 else if(nd->flags.wmi_none)
 {
   ; // nothing
 }
 else if(nd->flags.ref_preempts_wrap)
 {
  if(nd->flags.region)
  {
   b.qts << '}';
   reset_active_gap_code();
  }
 }
 else if(nd->flags.region)
 {
  b.qts << '}';
  if(nd->flags.main_only_block_environment)
  {
    //?check_reconcile_gap(b, 10);  //?
   b.qts << '\n';
   active_gap_code_ = 10;
  }
  reset_active_gap_code();
 }
 else
 {
  b.qts << '{';
  reset_active_gap_code();
 }
#endif // HIDE

 b.qts << '>';
}

void GTagML_Output_SDI_Infoset::generate_tag_body_leave(const GTagML_Output_Bundle& b, caon_ptr<GTagML_Tag_Command> ntc)
{
 CHECK_SUPPRESS_NODE
 CAON_PTR_DEBUG(GTagML_Tag_Command ,ntc)

 if(htxn_document_)
 {
  if(GTagML_HTXN_Node* nhn = ntc->GTagML_htxn_node())
  {
   generate_tag_body_leave(b, *nhn);
   return;
  }
 }

 b.qts << '>';
 ntc->write_whitespace(b.qts);
}

//void GTagML_Output_SDI_Infoset::generate_tile_via_htxn(const GTagML_Output_Bundle& b, GTagML_HTXN_Node& nhn)
//{
////? CHECK_SUPPRESS_NODE
////? htxn_document_->write_minimal_xml_out(nhn.layer_code(), nhn.range(), b.qts);
// //? reset_active_gap_code();
//}

