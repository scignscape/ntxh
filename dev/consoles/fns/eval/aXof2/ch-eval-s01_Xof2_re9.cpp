
Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
  return;


QVector<n8> args;
lambda->pasn8vector(args, fncode.arg_count);

Chasm_Channel* sigma = ccp->channel("sigma");
void* _this;
if(sigma)
  _this = sigma->first_carrier().value<void*>();
else
  _this = nullptr;

Chasm_Carrier cc = retvalue->first_carrier();
void* rr = cc.value<void*>();

u1 ac_pattern = (fncode.arg_count == 2)?
  ( (fncode.type_pattern_binary == 1)? 255: 0):
  ( ((fncode.arg_count - 3) << 5)
    | (fncode.type_pattern_binary &
        ((1 << fncode.arg_count) - 1) ) );

u1 index = type_patterns_2_map.value((fncode.distinct_type_pattern % 100) + 200);

run_s01_Xof2_re9(ac_pattern,
   index,
   (minimal_fn_s0_re9_type) fn,
   (minimal_fn_s1_re9_type) sfn, args, rr, _this);

if(rcar)
  rcar->set_value(rr);
