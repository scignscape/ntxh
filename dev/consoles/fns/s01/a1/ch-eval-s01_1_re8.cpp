

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

n8 rr = cc.value<n8>();
run_s01_1_re8(fncode, (minimal_fn_s0_re8_type) fn,
  (minimal_fn_s1_re8_type) sfn, rr, lambda->pasn8(1), _this);

if(rcar)
  rcar->set_value(rr);