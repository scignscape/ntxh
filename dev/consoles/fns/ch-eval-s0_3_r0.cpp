

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Carrier cc = resultch->first_carrier();

void rr = cc.value();
run_s0_3_r0(fncode, (minimal_fn_s0_r0_type) fn,
      rr, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3));

if(rcar)
  rcar->set_value(rr);
