

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
QVariant& rr = cc.value_as<QVariant>();


u1 ac_pattern = (fncode.arg_count == 2)?
  ( (fncode.pretype_pattern_binary == 2)? 255: 0):
  ( ((fncode.arg_count - 3) << 6)
    | (fncode.pretype_pattern_binary &
        ((1 << fncode.arg_count) - 1) ) );

u1 index = pretype_patterns_2_map.value((fncode.distinct_pretype_pattern % 100) + 200);

run_s01_Xof2_re7(ac_pattern, index,
  (minimal_fn_s0_re7_type) fn,
  (minimal_fn_s1_re7_type) sfn, args, rr, _this);

if(rcar)
  rcar->set_value_as<QVariant>(rr);
