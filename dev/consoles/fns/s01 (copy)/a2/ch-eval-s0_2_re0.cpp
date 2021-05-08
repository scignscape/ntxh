

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* sigma = ccp->channel("sigma");
if(!sigma)
return;

run_s01_2_re0(fncode, (minimal_fn_s0_re0_type) fn, lambda->pasn8(1), lambda->pasn8(2), (minimal_fn_s1_re0_type) fn, lambda->pasn8(1), lambda->pasn8(2));
