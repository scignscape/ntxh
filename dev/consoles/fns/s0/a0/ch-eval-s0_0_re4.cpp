
Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

u4 rr = cc.value<u4>();
run_s0_0_re4(fncode, (minimal_fn_s0_re4_type) fn,
  rr);

if(rcar)
  rcar->set_value(rr);