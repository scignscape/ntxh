

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

QByteArray& rr = cc.value_as<QByteArray>();
run_s0_1_re5(fncode, (minimal_fn_s0_re5_type) fn,
  rr, lambda->pasn8(1));

if(rcar)
  rcar->set_value_as<QByteArray>(rr);
