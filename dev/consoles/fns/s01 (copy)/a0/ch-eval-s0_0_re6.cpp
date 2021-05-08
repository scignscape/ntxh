
Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
  return;

Chasm_Channel* sigma = ccp->channel("sigma");
if(!sigma)
return;

Chasm_Carrier cc = resultch->first_carrier();

r8 rr = cc.value<r8>();
run_s01_0_re6(fncode, (minimal_fn_s0_re6_type) fn,
  (minimal_fn_s1_re6_type) sfn, rr);

if(rcar)
  rcar->set_value(rr);
