

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

u4 rr = cc.value();
run_s0_3_r4(fncode, (minimal_fn_s0_r4_type) fn,
      rr, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3));

if(rcar)
  rcar->set_value(rr);
