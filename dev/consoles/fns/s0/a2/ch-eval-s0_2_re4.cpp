

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

u4 rr = cc.value<u4>();
run_s0_2_re4(fncode, (minimal_fn_s0_re4_type) fn,
  rr, lambda->pasn8(1), lambda->pasn8(2));

if(rcar)
  rcar->set_value(rr);