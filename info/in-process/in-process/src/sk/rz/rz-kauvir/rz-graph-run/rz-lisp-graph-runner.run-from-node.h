
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "rz-lisp-graph-runner.h"

#include "rz-graph-token/rz-lisp-graph-core-function.h"



#include "rz-graph-valuer/valuer/rz-lisp-graph-valuer.h"
#include "rz-graph-token/valuer/rz-lisp-core-function.h"

#include "rz-graph-build/rz-lisp-graph-result-holder.h"

#include "rz-lisp-graph-core-runner.h"

#include "rz-graph-token/token/rz-lisp-token.h"


#include "rz-graph-core/kernel/graph/rz-re-node.h"


USING_RZNS(GRun)


RZNS_(GRun)

template<>
void RZ_Lisp_Graph_Runner::proceed_run_from_node<0>(RZ_Lisp_Graph_Result_Holder& rh,
  RZ_Lisp_Graph_Valuer_Core_Pair& cp)
{
 RZ_Lisp_Graph_Core_Function& cf = *cp.cf;
 tNode& start_node = *cp.fnode;
 rh.hold(&start_node);
 RZ_Lisp_Graph_Function_Code code = cf.info().Core_Function_Code;
 switch(cf.info().Core_Function_Family)
 {
 case RZ_Graph_Call_S:
  RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_S>
    (rh, code,
     *start_node.lisp_token(), &start_node);
  break;
 }
 check_continue(rh);
 rh.unhold();
}


template<>
void RZ_Lisp_Graph_Runner::prepare_run_from_node<0>(int generation,
  RZ_Lisp_Graph_Result_Holder& rh,
  RZ_Lisp_Graph_Core_Function& cf,
  tNode& start_node, caon_ptr<tNode> next_node,
  caon_ptr<tNode> left_new_node,
  caon_ptr<tNode> second_node, caon_ptr<tNode> right_new_node)
{
 //?
}

template<>
void RZ_Lisp_Graph_Runner::check_run_from_node<0>(int generation,
  RZ_Lisp_Graph_Result_Holder& rh,
  RZ_Lisp_Graph_Core_Function& cf, tNode& start_node)
{
 valuer_->mark_core_function_call_entry(generation, cf, &start_node, nullptr, nullptr, nullptr, nullptr, nullptr);
 prepare_run_from_node<0>(generation, rh, cf, start_node, nullptr, nullptr, nullptr, nullptr);
}

template<>
void RZ_Lisp_Graph_Runner::proceed_run_from_node<1>(RZ_Lisp_Graph_Result_Holder& rh,
  RZ_Lisp_Graph_Valuer_Core_Pair& cp)
{

 RZ_Lisp_Graph_Core_Function& cf = *cp.cf;
 tNode& start_node = *cp.fnode;

 caon_ptr<tNode> next_node = cp.lhs_node;
 caon_ptr<tNode> left_new_node = cp.left_new_node;
 caon_ptr<tNode> second_node = cp.rhs_node;
 caon_ptr<tNode> right_new_node = cp.right_new_node;
 caon_ptr<tNode> arity_value_node = cp.arity_value_node;

 caon_ptr<RZ_Lisp_Token> lhs_token;

 if(left_new_node)
 {
  // //  indicate that the call entry is a core function ...
  //?valuer_->mark_core_function_call_entry(&cf, start_node, *left_new_node);
  lhs_token = valuer_->get_token_from(*left_new_node);
 }
 else
 {
  //?valuer_->mark_core_function_call_entry(start_node, *next_node);
  lhs_token = valuer_->get_token_from(*next_node);
 }

 rh.hold(&start_node);

 static RZ_Lisp_Graph_Value_Holder null_vh;

 switch(cf.info().Core_Function_Family)
 {
 case RZ_Graph_Call_C:
  if(rh.flags.has_held_value)
  {
   rh.flags.has_held_value = false;
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_C>
    (rh, cf.info().Core_Function_Code,
     rh.value_holder(), null_vh);
  }
  else if(arity_value_node)
  {
   RZ_Lisp_Graph_Value_Holder vh;
   caon_ptr<RZ_Type_Object> tobj =
    valuer_->get_node_type_object(*arity_value_node);
   // //   Should this be (as it once was) a function in RE_Node?
   vh.set_type_object(tobj);
   vh.set_value(arity_value_node->vertex());
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_C>
    (rh, cf.info().Core_Function_Code,
     vh, lhs_token->vh() );
  }
  else
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_C>
    (rh, cf.info().Core_Function_Code,
     lhs_token->vh(), null_vh );
  break;

 case RZ_Graph_Call_Tc:
  if(rh.flags.has_held_value)
  {
   rh.flags.has_held_value = false;
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_Tc>
    (rh, cf.info().Core_Function_Code,
     *lhs_token, rh.value_holder() );
  }
  else
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_Tc>
    (rh, cf.info().Core_Function_Code,
     *lhs_token, lhs_token->vh() );
  break;

 case RZ_Graph_Call_Tv:
  if(rh.flags.has_held_value)
  {
   rh.flags.has_held_value = false;
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_Tv>
    (rh, cf.info().Core_Function_Code,
     *lhs_token, rh.value_holder() );
  }
  else
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_Tv>
    (rh, cf.info().Core_Function_Code,
     *lhs_token, lhs_token->vh() );
  break;

 case RZ_Graph_Call_TC:
  if(rh.flags.has_held_value)
  {
   rh.flags.has_held_value = false;
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_TC>
    (rh, cf.info().Core_Function_Code,
     *lhs_token, second_node->lisp_token()->vh());
  }
  else
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_TC>
    (rh, cf.info().Core_Function_Code,
     *lhs_token, second_node->lisp_token()->vh());
  break;

 case RZ_Graph_Call_T:
  RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_T>
    (rh, cf.info().Core_Function_Code,
     *lhs_token );
  break;
 }
 check_continue(rh);
 rh.unhold();
}

template<>
void RZ_Lisp_Graph_Runner::prepare_run_from_node<1>(int generation,
  RZ_Lisp_Graph_Result_Holder& rh,
  RZ_Lisp_Graph_Core_Function& cf,
  tNode& start_node, caon_ptr<tNode> next_node,
  caon_ptr<tNode> left_new_node,
  caon_ptr<tNode> second_node, caon_ptr<tNode> right_new_node)
{
 CAON_PTR_DEBUG(tNode ,next_node)
 CAON_PTR_DEBUG(tNode ,second_node)

 CAON_PTR_DEBUG(tNode ,left_new_node)
 CAON_PTR_DEBUG(tNode ,right_new_node)

 valuer_->mark_core_function_call_entry(generation, cf, &start_node,
   next_node, left_new_node, second_node, right_new_node, rh.arity_value_node());

}


template<>
void RZ_Lisp_Graph_Runner::check_run_from_node<1>(int generation,
  RZ_Lisp_Graph_Result_Holder& rh,
  RZ_Lisp_Graph_Core_Function& cf, tNode& start_node)
{
 caon_ptr<tNode> next_node;
 caon_ptr<tNode> second_node;

 caon_ptr<tNode> left_new_node;
 caon_ptr<tNode> right_new_node;


 init_run_sequence_pair(rh, start_node, next_node, second_node, left_new_node, right_new_node);
 prepare_run_from_node<1>(generation, rh, cf, start_node, next_node, left_new_node, second_node, right_new_node);
}


//template<>
//void RZ_Lisp_Graph_Runner::proceed_run_from_node<2>(int generation,
//  RZ_Lisp_Graph_Result_Holder& rh,
//  RZ_Lisp_Graph_Core_Function& cf,
//  tNode& start_node, caon_ptr<tNode> lhs_node,
//  caon_ptr<tNode> left_new_node,
//  caon_ptr<tNode> rhs_node, caon_ptr<tNode> right_new_node)

template<>
void RZ_Lisp_Graph_Runner::proceed_run_from_node<2>(RZ_Lisp_Graph_Result_Holder& rh,
  RZ_Lisp_Graph_Valuer_Core_Pair& cp)
{

 RZ_Lisp_Graph_Core_Function& cf = *cp.cf;
 tNode& start_node = *cp.fnode;

 caon_ptr<tNode> lhs_node = cp.lhs_node;
 caon_ptr<tNode> left_new_node = cp.left_new_node;
 caon_ptr<tNode> rhs_node = cp.rhs_node;
 caon_ptr<tNode> right_new_node = cp.right_new_node;
 caon_ptr<tNode> arity_value_node = cp.arity_value_node;

 int generation = cp.generation;

 caon_ptr<RZ_Lisp_Token> lhs_token;

 if(left_new_node)
 {
//  if(right_new_node)
//    valuer_->mark_core_function_call_entry(start_node,
//      *left_new_node, *right_new_node);
//  else
//    valuer_->mark_core_function_call_entry(start_node,
//      *left_new_node, *rhs_node);
  lhs_token = valuer_->get_token_from(*left_new_node);
 }
 else
 {
//  if(right_new_node)
//    valuer_->mark_core_function_call_entry(start_node,
//      *lhs_node, *right_new_node);
//  else
//    valuer_->mark_core_function_call_entry(start_node,
//      *lhs_node, *rhs_node);
  lhs_token = valuer_->get_token_from(*lhs_node);
 }

 CAON_PTR_DEBUG(RZ_Lisp_Token ,lhs_token)

 CAON_EVALUATE_DEBUG(RZ_Type_Object, t, lhs_token->vh().type_object())


 RZ_Lisp_Graph_Value_Holder rhs_vh;

 CAON_PTR_DEBUG(tNode ,rhs_node)

 caon_ptr<RZ_Lisp_Token> rhs_token = rhs_node->lisp_token();
 CAON_PTR_DEBUG(RZ_Lisp_Token ,rhs_token)

 RZ_Lisp_Graph_Value_Holder lhs_vh;

 CAON_PTR_DEBUG(tNode ,lhs_node)

 caon_ptr<RZ_Type_Object> rto;
 if(rhs_token)
 {
  rto = rhs_token->vh().type_object();
 }
 if(rto)
 {
  CAON_PTR_DEBUG(RZ_Type_Object ,rto)

  caon_ptr<GBuild::RZ_Lisp_Core_Function> rhs_lcf =
       rhs_token->pRestore<GBuild::RZ_Lisp_Core_Function>(valuer_->type_variety());

  CAON_PTR_DEBUG(GBuild::RZ_Lisp_Core_Function ,rhs_lcf)
  CAON_DEBUG_NOOP
 }

 if(right_new_node)
 {
  caon_ptr<RZ_Type_Object> tobj =
   valuer_->get_node_type_object(*right_new_node);

  // //   Should this be (as it once was) a function in RE_Node?
  rhs_vh.set_type_object(tobj);

  rhs_vh.set_value(right_new_node->vertex());
 }
 else if(caon_ptr<RZ_Lisp_Graph_Core_Function> rhs_cf =
   rhs_token->pRestore<RZ_Lisp_Graph_Core_Function>(valuer_->type_variety()))
 {
  RZ_Lisp_Graph_Result_Holder rh1(*valuer_);
  //?
  check_run_info(generation + 1, rh1, *rhs_cf, *rhs_node);
  rhs_vh = rh1.value_holder();
 }
 else if(caon_ptr<GBuild::RZ_Lisp_Core_Function> rhs_lcf =
   rhs_token->pRestore<GBuild::RZ_Lisp_Core_Function>(valuer_->type_variety()))
 {
  rhs_vh = rhs_token->vh();
 }
 else
  rhs_vh = rhs_token->vh();

 rh.hold(&start_node);


 //lhs_vh = lhs_token->vh();
//}

//template<>
//void RZ_Lisp_Graph_Runner::proceed_run_from_node<2>(RZ_Lisp_Graph_Result_Holder& rh,
// RZ_Lisp_Graph_Core_Function& cf, tNode& start_node)
//{
 switch(cf.info().Core_Function_Family)
 {
 case RZ_Graph_Call_VV:
  {
   RZ_Lisp_Graph_Value_Holder lhs_vh;
   if(left_new_node)
   {
    caon_ptr<RZ_Type_Object> tobj =
     valuer_->get_node_type_object(*left_new_node);

    // //   Should this be (as it once was) a function in RE_Node?
    lhs_vh.set_type_object(tobj);

    lhs_vh.set_value(right_new_node->vertex());
   }
   else
    lhs_vh = lhs_token->vh();

   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_VV>
     (rh, cf.info().Core_Function_Code,
      lhs_vh,
      rhs_vh);
  }
  break;

 case RZ_Graph_Call_TV:
  RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_TV>
    (rh, cf.info().Core_Function_Code,
     *lhs_node->lisp_token(),
     rhs_vh);
  break;

 case RZ_Graph_Call_TC:
  RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_TC>
    (rh, cf.info().Core_Function_Code,
     *lhs_node->lisp_token(),
     rhs_vh);
  break;

 case RZ_Graph_Call_CT:
  if(rh.flags.has_held_value)
  {
   rh.flags.has_held_value = false;
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_CT>
    (rh, cf.info().Core_Function_Code,
     rh.value_holder(), *lhs_node->lisp_token());
  }
  else
  {
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_CT>
     (rh, cf.info().Core_Function_Code,
      lhs_vh,
      *rhs_node->lisp_token());
  }
  break;

 }
 rh.unhold();
}

template<>
void RZ_Lisp_Graph_Runner::prepare_run_from_node<2>(int generation,
  RZ_Lisp_Graph_Result_Holder& rh,
  RZ_Lisp_Graph_Core_Function& cf,
  tNode& start_node, caon_ptr<tNode> lhs_node,
  caon_ptr<tNode> left_new_node,
  caon_ptr<tNode> rhs_node, caon_ptr<tNode> right_new_node)
{
 if(lhs_node)
 {
  caon_ptr<RZ_Lisp_Token> lhst = lhs_node->lisp_token();
  CAON_PTR_DEBUG(RZ_Lisp_Token ,lhst)
  CAON_DEBUG_NOOP
 }

// CAON_PTR_DEBUG(tNode ,rhs_node)

// caon_ptr<RZ_Lisp_Token> rhs_token = rhs_node->lisp_token();
// CAON_PTR_DEBUG(RZ_Lisp_Token ,rhs_token)

// RZ_Lisp_Graph_Value_Holder rhs_vh;
// RZ_Lisp_Graph_Value_Holder lhs_vh;

// CAON_PTR_DEBUG(tNode ,lhs_node)

// caon_ptr<RZ_Type_Object> rto;
// if(rhs_token)
// {
//  rto = rhs_token->vh().type_object();
// }
// if(rto)
// {
//  CAON_PTR_DEBUG(RZ_Type_Object ,rto)

//  caon_ptr<GBuild::RZ_Lisp_Core_Function> rhs_lcf =
//       rhs_token->pRestore<GBuild::RZ_Lisp_Core_Function>(valuer_->type_variety());

//  CAON_PTR_DEBUG(GBuild::RZ_Lisp_Core_Function ,rhs_lcf)
//  CAON_DEBUG_NOOP
// }


// if(right_new_node)
// {
//  caon_ptr<RZ_Type_Object> tobj =
//   valuer_->get_node_type_object(*right_new_node);

//  // //   Should this be (as it once was) a function in RE_Node?
//  rhs_vh.set_type_object(tobj);

//  rhs_vh.set_value(right_new_node->vertex());
// }
// else if(caon_ptr<RZ_Lisp_Graph_Core_Function> rhs_cf =
//   rhs_token->pRestore<RZ_Lisp_Graph_Core_Function>(valuer_->type_variety()))
// {
//  RZ_Lisp_Graph_Result_Holder rh1(*valuer_);
//  check_run_info(rh1, *rhs_cf, *rhs_node);
//  rhs_vh = rh1.value_holder();
// }
// else if(caon_ptr<GBuild::RZ_Lisp_Core_Function> rhs_lcf =
//   rhs_token->pRestore<GBuild::RZ_Lisp_Core_Function>(valuer_->type_variety()))
// {
//  rhs_vh = rhs_token->vh();
// }
// else
//  rhs_vh = rhs_token->vh();

// rh.hold(&start_node);

 caon_ptr<RZ_Lisp_Token> lhs_token;

 valuer_->mark_core_function_call_entry(generation, cf, &start_node,
   lhs_node, left_new_node, rhs_node, right_new_node, rh.arity_value_node());

 //!
// proceed_run_from_node<2>(generation, rh, cf, start_node,
//   lhs_node, left_new_node, rhs_node, right_new_node);
// caon_ptr<RZ_Lisp_Token> lhs_token;

#ifdef HIDE

 if(left_new_node)
 {
//  if(right_new_node)
//    valuer_->mark_core_function_call_entry(start_node,
//      *left_new_node, *right_new_node);
//  else
//    valuer_->mark_core_function_call_entry(start_node,
//      *left_new_node, *rhs_node);
  lhs_token = valuer_->get_token_from(*left_new_node);
 }
 else
 {
//  if(right_new_node)
//    valuer_->mark_core_function_call_entry(start_node,
//      *lhs_node, *right_new_node);
//  else
//    valuer_->mark_core_function_call_entry(start_node,
//      *lhs_node, *rhs_node);
  lhs_token = valuer_->get_token_from(*lhs_node);
 }

 CAON_PTR_DEBUG(RZ_Lisp_Token ,lhs_token)

 CAON_EVALUATE_DEBUG(RZ_Type_Object, t, lhs_token->vh().type_object())


 RZ_Lisp_Graph_Value_Holder rhs_vh;

 CAON_PTR_DEBUG(tNode ,rhs_node)

 caon_ptr<RZ_Lisp_Token> rhs_token = rhs_node->lisp_token();
 CAON_PTR_DEBUG(RZ_Lisp_Token ,rhs_token)

 RZ_Lisp_Graph_Value_Holder lhs_vh;

 CAON_PTR_DEBUG(tNode ,lhs_node)

 caon_ptr<RZ_Type_Object> rto;
 if(rhs_token)
 {
  rto = rhs_token->vh().type_object();
 }
 if(rto)
 {
  CAON_PTR_DEBUG(RZ_Type_Object ,rto)

  caon_ptr<GBuild::RZ_Lisp_Core_Function> rhs_lcf =
       rhs_token->pRestore<GBuild::RZ_Lisp_Core_Function>(valuer_->type_variety());

  CAON_PTR_DEBUG(GBuild::RZ_Lisp_Core_Function ,rhs_lcf)
  CAON_DEBUG_NOOP
 }

 if(right_new_node)
 {
  caon_ptr<RZ_Type_Object> tobj =
   valuer_->get_node_type_object(*right_new_node);

  // //   Should this be (as it once was) a function in RE_Node?
  rhs_vh.set_type_object(tobj);

  rhs_vh.set_value(right_new_node->vertex());
 }
 else if(caon_ptr<RZ_Lisp_Graph_Core_Function> rhs_cf =
   rhs_token->pRestore<RZ_Lisp_Graph_Core_Function>(valuer_->type_variety()))
 {
  RZ_Lisp_Graph_Result_Holder rh1(*valuer_);
  check_run_info(rh1, *rhs_cf, *rhs_node);
  rhs_vh = rh1.value_holder();
 }
 else if(caon_ptr<GBuild::RZ_Lisp_Core_Function> rhs_lcf =
   rhs_token->pRestore<GBuild::RZ_Lisp_Core_Function>(valuer_->type_variety()))
 {
  rhs_vh = rhs_token->vh();
 }
 else
  rhs_vh = rhs_token->vh();

 rh.hold(&start_node);


 //lhs_vh = lhs_token->vh();
//}

//template<>
//void RZ_Lisp_Graph_Runner::proceed_run_from_node<2>(RZ_Lisp_Graph_Result_Holder& rh,
// RZ_Lisp_Graph_Core_Function& cf, tNode& start_node)
//{
 switch(cf.info().Core_Function_Family)
 {
 case RZ_Graph_Call_VV:
  {
   RZ_Lisp_Graph_Value_Holder lhs_vh;
   if(left_new_node)
   {
    caon_ptr<RZ_Type_Object> tobj =
     valuer_->get_node_type_object(*left_new_node);

    // //   Should this be (as it once was) a function in RE_Node?
    lhs_vh.set_type_object(tobj);

    lhs_vh.set_value(right_new_node->vertex());
   }
   else
    lhs_vh = lhs_token->vh();

   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_VV>
     (rh, cf.info().Core_Function_Code,
      lhs_vh,
      rhs_vh);
  }
  break;

 case RZ_Graph_Call_TV:
  RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_TV>
    (rh, cf.info().Core_Function_Code,
     *lhs_node->lisp_token(),
     rhs_vh);
  break;

 case RZ_Graph_Call_TC:
  RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_TC>
    (rh, cf.info().Core_Function_Code,
     *lhs_node->lisp_token(),
     rhs_vh);
  break;

 case RZ_Graph_Call_CT:
  if(rh.flags.has_held_value)
  {
   rh.flags.has_held_value = false;
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_CT>
    (rh, cf.info().Core_Function_Code,
     rh.value_holder(), *lhs_node->lisp_token());
  }
  else
  {
   RZ_Lisp_Graph_Core_Runner::run<RZ_Graph_Call_CT>
     (rh, cf.info().Core_Function_Code,
      lhs_vh,
      *rhs_node->lisp_token());
  }
  break;

 }
 rh.unhold();
#endif // HIDE
}

template<>
void RZ_Lisp_Graph_Runner::check_run_from_node<2>(int generation,
  RZ_Lisp_Graph_Result_Holder& rh,
  RZ_Lisp_Graph_Core_Function& cf, tNode& start_node)
{
 caon_ptr<tNode> rhs_node;
 caon_ptr<tNode> lhs_node;

 // //  New node might hold a representation of a data collection
 caon_ptr<tNode> left_new_node;
 caon_ptr<tNode> right_new_node;

 init_run_sequence_pair(rh, start_node, lhs_node, rhs_node, left_new_node, right_new_node);

 prepare_run_from_node<2>(generation, rh, cf, start_node, lhs_node, left_new_node, rhs_node, right_new_node);

}


_RZNS(GRun)

//#endif // HIDE
