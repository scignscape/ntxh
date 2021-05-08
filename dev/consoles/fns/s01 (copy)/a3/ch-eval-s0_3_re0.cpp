

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* sigma = ccp->channel("sigma");
if(!sigma)
return;

run_s01_3_re0(fncode, (minimal_fn_s0_re0_type) fn, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3), (minimal_fn_s1_re0_type) fn, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3));
