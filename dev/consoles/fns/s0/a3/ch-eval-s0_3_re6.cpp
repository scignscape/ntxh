

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

r8 rr = cc.value<r8>();
run_s0_3_re6(fncode, (minimal_fn_s0_re6_type) fn,
  rr, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3));

if(rcar)
  rcar->set_value(rr);
