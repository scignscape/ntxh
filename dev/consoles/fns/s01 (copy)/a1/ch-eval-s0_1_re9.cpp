

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
  return;

Chasm_Channel* sigma = ccp->channel("sigma");
if(!sigma)
return;

Chasm_Carrier cc = resultch->first_carrier();

void* rr = cc.value<void*>();
run_s01_1_re9(fncode, (minimal_fn_s0_re9_type) fn,
  (minimal_fn_s1_re9_type) sfn, rr, lambda->pasn8(1));

if(rcar)
  rcar->set_value(rr);
