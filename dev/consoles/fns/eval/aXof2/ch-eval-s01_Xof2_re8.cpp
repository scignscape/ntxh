

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
  return;


QVector<n8> args;
lambda->pasn8vector(args, fncode.arg_count);

Chasm_Channel* sigma = ccp->channel("sigma");
void** _this; void* _this_;
if(sigma)
{
 _this_ = sigma->first_carrier().value<void*>();
 _this = &_this_;
}
else { _this = nullptr; _this_ = nullptr; }

Chasm_Carrier cc = retvalue->first_carrier();
n8 rr = cc.value<n8>();


u1 ac_pattern = (fncode.arg_count == 2)?
  ( (fncode.type_pattern_binary == 2)? 255: 0):
  ( ((fncode.arg_count - 3) << 6)
    | (fncode.type_pattern_binary &
        ((1 << fncode.arg_count) - 1) ) );

u1 index = type_patterns_2_map.value((fncode.distinct_type_pattern % 100) + 200);

run_s01_Xof2_re8(ac_pattern, index,
  (minimal_fn_s0_re8_type) fn,
  (minimal_fn_s1_re8_type) sfn, args, rr, _this);

if(rcar)
  rcar->set_value(rr);
