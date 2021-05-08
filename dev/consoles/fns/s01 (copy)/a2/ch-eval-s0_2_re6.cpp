

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

r8 rr = cc.value<r8>();
run_s01_2_re6(fncode, (minimal_fn_s0_re6_type) fn,
  (minimal_fn_s1_re6_type) sfn, rr, lambda->pasn8(1), lambda->pasn8(2));

if(rcar)
  rcar->set_value(rr);
