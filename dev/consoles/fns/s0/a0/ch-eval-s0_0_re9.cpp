
Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

void* rr = cc.value<void*>();
run_s0_0_re9(fncode, (minimal_fn_s0_re9_type) fn,
  rr);

if(rcar)
  rcar->set_value(rr);
