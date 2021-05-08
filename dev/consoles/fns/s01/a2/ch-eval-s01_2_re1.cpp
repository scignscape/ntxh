

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

u1 rr = cc.value<u1>();
run_s01_2_re1(fncode, (minimal_fn_s0_re1_type) fn,
  (minimal_fn_s1_re1_type) sfn, rr, lambda->pasn8(1), lambda->pasn8(2), _this);

if(rcar)
  rcar->set_value(rr);
