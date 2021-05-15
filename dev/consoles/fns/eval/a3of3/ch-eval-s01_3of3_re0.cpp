

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
 return;

Chasm_Channel* sigma = ccp->channel("sigma");
void** _this; void* _this_;
if(sigma)
{
 _this_ = sigma->first_carrier().value<void*>();
 _this = &_this_;
}
else { _this = nullptr; _this_ = nullptr; }

u2 index = type_patterns_3of3_map.value(fncode.distinct_pretype_pattern);
run_s01_3of3_re0(fncode.type_pattern, index, (minimal_fn_s0_re0_type) fn,
 (minimal_fn_s1_re0_type) sfn, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3), _this);
