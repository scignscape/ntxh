
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef PHAON_IR__H
#define PHAON_IR__H

#include <QString>
#include <QMap>
#include <QMultiMap>
#include <QStack>

#include <functional>

#include "accessors.h"

#include "scopes/phr-runtime-scope.h"
#include "scopes/phr-scope-system.h"

#include "runtime/phr-callable-value.h"

#define PASTE_EXPRESSION(...) __VA_ARGS__

KANS_(Phaon)

class PHR_Channel_Semantic_Protocol;
class PHR_Type_System;
class PHR_Program_Stack;
class PHR_Carrier_Stack;
class PHR_Type;
class PHR_Channel_Group;
class PHR_Channel_Group_Evaluator;
class PHR_Channel;
class PHR_Command_Package;
class PHR_Expression_Object;
class PHR_Type_Object;
class PHR_Cocyclic_Type;

class PHR_Symbol_Scope;

class PHR_Runtime_Scope;
class PHR_Scope_Value;
class PHR_Channel_System;

class PHR_Code_Model;
class PHR_Channel_Group_Table;

class PhaonIR
{
 struct Unwind_Scope_Index
 {
  quint8 chief_channel_pos;
  quint8 unwind_level;
  quint8 depth;
  quint8 unwind_maximum_;
  quint8 level_channel_pos;

  QString channel_name;

  Unwind_Scope_Index project()
  {
   return {chief_channel_pos, unwind_level, depth, 0, 0, channel_name};
  }
 };

 struct Source_Function_Scope
 {
  QString source_fn_name;

  Unwind_Scope_Index _current_chief_unwind_scope_index;

  QMap<Unwind_Scope_Index, Unwind_Scope_Index> _unwind_scope_index_parents;
  QMap<Unwind_Scope_Index, QPair<PHR_Program_Stack*, PHR_Carrier_Stack*>> _held_program_stacks;
  QMap<Unwind_Scope_Index, PHR_Program_Stack*> _stashed_program_stacks;
  QMap<Unwind_Scope_Index, PHR_Channel_Group*> _indexed_channel_groups;
 };

 void init_current_source_function_scope(QString source_fn);

 Source_Function_Scope* current_source_function_scope_;

 Unwind_Scope_Index& current_chief_unwind_scope_index()
 {
  if(temp_held_program_stack_)
    return *alt_usi_;
  return current_source_function_scope_->_current_chief_unwind_scope_index;
 }

 QMap<Unwind_Scope_Index, Unwind_Scope_Index>& unwind_scope_index_parents()
 {
  return current_source_function_scope_->_unwind_scope_index_parents;
 }

 QMap<Unwind_Scope_Index, QPair<PHR_Program_Stack*, PHR_Carrier_Stack*>>&
   held_program_stacks()
 {
  return current_source_function_scope_->_held_program_stacks;
 }

 QMap<Unwind_Scope_Index, PHR_Program_Stack*>& stashed_program_stacks()
 {
  return current_source_function_scope_->_stashed_program_stacks;
 }

 QMap<Unwind_Scope_Index, PHR_Channel_Group*>& indexed_channel_groups()
 {
  return current_source_function_scope_->_indexed_channel_groups;
 }

 QStack<Source_Function_Scope*> source_function_scopes_;

 typedef union {void(PhaonIR::*fn0)(); void(PhaonIR::*fn1)(QString);} fn_u ;

 QMap<QString, QList<QPair<QString*, fn_u>>> line_ops_;

 QString starting_source_fn_name_;
 QString current_source_fn_name_;
 QStack<QString> source_fn_names_;


 QString last_source_fn_name_;
 ACCESSORS__GET(QString ,last_source_fn_name)


 PHR_Channel_System* channel_system_;
 QMap<QPair<Unwind_Scope_Index, PHR_Channel_Semantic_Protocol*>, PHR_Carrier_Stack*>* sp_map_;

 PHR_Type_System* type_system_;
 PHR_Program_Stack* program_stack_;
 PHR_Type* held_type_;
 PHR_Carrier_Stack* current_carrier_stack_;
 PHR_Channel_Group* held_channel_group_;
 PHR_Channel_Group_Table* table_;

 PHR_Program_Stack* alt_program_stack_;
 PHR_Program_Stack* temp_held_program_stack_;
 Unwind_Scope_Index* alt_usi_;

 QString held_usi_symbol_;

 std::function<PHR_Channel_Group_Evaluator*(PhaonIR&,
   PHR_Channel_Group&)> load_evaluator_fn_;


 QMap<QString, PHR_Channel_Group*> temp_anchored_channel_groups_;

 QMultiMap<PHR_Channel_Group*, void*> temps_by_channel_group_;

 QList<void*> retired_temps_;

 PHR_Code_Model* code_model_;

 PHR_Symbol_Scope* held_symbol_scope_;

 int source_fn_anon_count_;

 struct anchor_channel_link
 {
  PHR_Channel_Semantic_Protocol* protocol;
  PHR_Runtime_Scope* scope;
  QString sym;
  quint64 (PhaonIR::*cofinalizer)(anchor_channel_link& acl, void* pv);
 };

 quint64 default_cofinalizer(anchor_channel_link& acl, void* pv);

 QMultiMap<PHR_Channel_Group*, anchor_channel_link> anchored_channel_groups_;

 PHR_Scope_System scopes_;
 PHR_Runtime_Scope* current_lexical_scope()
 {
  return scopes_.current_scope();
 }


 struct Run_State
 {
  Source_Function_Scope* _source_function_scope;
  PHR_Program_Stack* _program_stack;
  PHR_Carrier_Stack* _carrier_stack;
  PHR_Channel_Group* _held_channel_group;
  QMap<QPair<Unwind_Scope_Index,
    PHR_Channel_Semantic_Protocol*>, PHR_Carrier_Stack*>* _sp_map;
 };
 QStack<Run_State> run_state_stack_;

 std::function<void(PHR_Code_Model* pcm,
   PHR_Command_Package* pcp, PHR_Symbol_Scope* pss)> direct_eval_fn_;

 PHR_Cocyclic_Type* current_cocyclic_type_;

 QMap<QString, QString> named_source_fns_;

 QMap<QString, PHR_Channel_Group*> block_signature_channel_groups_;

 QMap<QString, QPair<PHR_Scope_Value*, PHR_Runtime_Scope::Storage_Options>>* current_channel_lexical_scope_;
 QStack<QMap<QString, QPair<PHR_Scope_Value*, PHR_Runtime_Scope::Storage_Options>>*> parent_channel_lexical_scopes_;


 friend bool operator<(const Unwind_Scope_Index& lhs, const Unwind_Scope_Index& rhs)
 {
  if(lhs.chief_channel_pos != rhs.chief_channel_pos)
    return lhs.chief_channel_pos < rhs.chief_channel_pos;
  if(lhs.unwind_level != rhs.unwind_level)
    return lhs.unwind_level < rhs.unwind_level;
  if(lhs.level_channel_pos != rhs.level_channel_pos)
    return lhs.level_channel_pos < rhs.level_channel_pos;
  if(lhs.depth != rhs.depth)
    return lhs.depth < rhs.depth;
  return false;
 }

 PHR_Carrier_Stack* get_carrier_stack_by_sp_name(Unwind_Scope_Index usi,
   QString sp_name);
 void check_semantic_protocol(QString sp_name);
 void inc_channel_pos();

 void check_init_program_stack();

 void reread_substitute(QString& key);

public:

 PhaonIR(PHR_Channel_System* channel_system);

 ACCESSORS(PASTE_EXPRESSION(std::function<PHR_Channel_Group_Evaluator*(PhaonIR&,
   PHR_Channel_Group&)>) ,load_evaluator_fn)

 ACCESSORS(PASTE_EXPRESSION(std::function<void(PHR_Code_Model* pcm,
    PHR_Command_Package* pcp, PHR_Symbol_Scope* pss)>) ,direct_eval_fn)

 ACCESSORS__GET(PHR_Code_Model* ,code_model)
 ACCESSORS__GET(PHR_Channel_System* ,channel_system)
 ACCESSORS__GET(PHR_Type_System* ,type_system)
 ACCESSORS__GET(PHR_Channel_Group_Table* ,table)

 void create_channel_semantic_protocol(QString name);

 QString find_source_fn(QString name);

 PHR_Channel_Group* get_select_channel_group()
 {
  return held_channel_group_;
 }

 PHR_Channel_Group_Evaluator* run_expression_object(PHR_Channel_Group* pcg);

 void init_table();
 void init_program_stack();
 void reinit_program_stack();
 void reset_program_stack();
 void index_channel_group();
 void temp_anchor_channel_group();
 void temp_anchor_channel_group_by_need();
 void anchor_channel_group(QString sym, QString ch);
 void copy_anchor_channel_group(QString sym, QString ch);

 void check_init_block_signature_lexical(QString source_fn, PHR_Callable_Value::fn_type fn);
 void anticipate_nested_block(QString chn);

 void load_alt_program_stack();
 void finalize_block_signature(QString sfn);
 void reload_program_stack();

 void register_callable_value(QString source_fn, QString name);


 void anchor_without_channel_group(QString sym, QString ch);
 void anchor_without_channel_group(QString str);

 void copy_anchor_channel_group(QString str);

 PHR_Type* init_value_from_symbol(QString sym,
   PHR_Runtime_Scope::Storage_Options& so, quint64& val);

 void finalize_signature(QString fn);

 void push_delete(void* pv);

 void delete_temps();
 void delete_retired();
 void clear_temps();

 void init_type_system();
 void init_type(QString type_name, quint8 byte_code);
 void init_code_model();

 qint32 get_s4_symbol_value(QString sym);

 void push_carrier_stack(QString sp_name);
 void push_carrier_raw_value(QString rv);
 void push_carrier_symbol(QString sn);
 void push_carrier_type_holder(QString ty_name);
 void push_carrier_anon_fn(QString fn);

 PHR_Channel_Group_Evaluator* evaluate_channel_group_by_usi_symbol(QString usi_sym,
   PHR_Expression_Object*& pxo, void*& pv);

 void hold_type_by_name(QString ty_name);
 void coalesce_channel_group();
 void evaluate_channel_group();

 void evaluate_channel_group_via_direct_eval(PHR_Channel_Group* pcg,
   quint64& rv, QString& string_result,
   const PHR_Type_Object*& pto, QString anchor);

 void mark_void_call();

 void hold_symbol_scope(PHR_Symbol_Scope* pss);

 void read_local_program(QString path);
 void read_line(QString inst);
 void read_line(QString inst, QString arg);
 void parse_fn_line(QString line);

 void run_lines(QString source_fn);

 void run_callable_value(QString source_fn, PHR_Callable_Value::fn_type fn = nullptr);

 void enter_lexical_scope();

 void push_unwind_scope(int level_delta, QString chn);

 void push_unwind_scope(QString level_delta);

 void type_field_decl(QString modifier, QString sym, QString type_name);
 void type_field_decl(QString m_sym_ty);

 void enter_cocyclic_type(QString name);
 void leave_cocyclic_type(QString name);


 void type_decl(QString sym, QString type_name);
 void type_decl(QString sym_ty);

 void pop_unwind_scope();

 void push_carrier_expression();

 QString get_first_raw_value_string(QString sp_name, PHR_Channel_Group& pcg);
 PHR_Channel* get_channel_by_sp_name(QString sp_name, PHR_Channel_Group& pcg);
 void* get_first_raw_value(QString sp_name, PHR_Channel_Group& pcg);

 void reset(PHR_Symbol_Scope* pss = nullptr);

};

_KANS(Phaon)

#endif // PHAON_IR__H
