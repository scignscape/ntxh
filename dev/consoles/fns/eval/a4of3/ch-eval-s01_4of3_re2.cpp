

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
 return;

Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
 return;

Chasm_Channel* sigma = ccp->channel("sigma");
void* _this;
if(sigma)
 _this = sigma->first_carrier().value<void*>();
else
 _this = nullptr;

Chasm_Carrier cc = retvalue->first_carrier();

u2 rr = cc.value<u2>();

u2 index = type_patterns_4of3_map.value(fncode.distinct_type_pattern);
run_s01_4of3_re2(fncode.type_pattern, index, (minimal_fn_s0_re2_type) fn,
 (minimal_fn_s1_re2_type) sfn, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3), lambda->pasn8(4), rr, _this);

if(rcar)
 rcar->set_value(rr);
