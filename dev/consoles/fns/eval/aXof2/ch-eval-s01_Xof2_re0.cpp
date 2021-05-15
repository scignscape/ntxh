

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
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


u1 ac_pattern = (fncode.arg_count == 2)?
  ( (fncode.type_pattern_binary == 2)? 255: 0):
  ( ((fncode.arg_count - 3) << 6)
    | (fncode.type_pattern_binary &
        ((1 << fncode.arg_count) - 1) ) );

u1 index = type_patterns_2_map.value((fncode.distinct_type_pattern % 100) + 200);

run_s01_Xof2_re0(ac_pattern, index,
  (minimal_fn_s0_re0_type) fn,
  (minimal_fn_s1_re0_type) sfn, args, _this);
