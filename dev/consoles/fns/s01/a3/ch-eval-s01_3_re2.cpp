

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
run_s01_3_re2(fncode, (minimal_fn_s0_re2_type) fn,
  (minimal_fn_s1_re2_type) sfn, rr, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3), _this);

if(rcar)
  rcar->set_value(rr);
