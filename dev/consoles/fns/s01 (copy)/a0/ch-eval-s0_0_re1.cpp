
Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
  return;

Chasm_Channel* sigma = ccp->channel("sigma");
if(!sigma)
return;

Chasm_Carrier cc = resultch->first_carrier();

u1 rr = cc.value<u1>();
run_s01_0_re1(fncode, (minimal_fn_s0_re1_type) fn,
  (minimal_fn_s1_re1_type) sfn, rr);

if(rcar)
  rcar->set_value(rr);
