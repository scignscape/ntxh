

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

r8 rr = cc.value<r8>();
run_s0_0_re6(fncode, (minimal_fn_s0_re6_type) fn,
  rr);

if(rcar)
  rcar->set_value(rr);
