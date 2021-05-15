

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
 return;

Chasm_Channel* sigma = ccp->channel("sigma");
void* _this;
if(sigma)
 _this = sigma->first_carrier().value<void*>();
else
 _this = nullptr;

u2 index = type_patterns_3of3_map.value(fncode.distinct_type_pattern);
run_s01_3of3_re0(fncode.type_pattern, index, (minimal_fn_s0_re0_type) fn,
 (minimal_fn_s1_re0_type) sfn, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3), _this);
