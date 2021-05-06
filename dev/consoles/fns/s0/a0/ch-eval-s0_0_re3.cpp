

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

QString& rr = cc.value_as<QString>();
run_s0_0_re3(fncode, (minimal_fn_s0_re3_type) fn,
  rr);

if(rcar)
  rcar->set_value_as<QString>(rr);
