

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

u2 rr = cc.value<u2>();
run_s0_1_re2(fncode, (minimal_fn_s0_re2_type) fn,
  rr, lambda->pasn8(1));

if(rcar)
  rcar->set_value(rr);