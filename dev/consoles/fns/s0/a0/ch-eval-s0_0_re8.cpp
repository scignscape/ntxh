
Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

n8 rr = cc.value<n8>();
run_s0_0_re8(fncode, (minimal_fn_s0_re8_type) fn,
  rr);

if(rcar)
  rcar->set_value(rr);