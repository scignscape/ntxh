

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

QVariant& rr = cc.value_as<QVariant>();
run_s0_3_re7(fncode, (minimal_fn_s0_re7_type) fn,
  rr, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3));

if(rcar)
  rcar->set_value_as<QVariant>(rr);
