
Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

u1 rr = cc.value<u1>();
run_s0_0_re1(fncode, (minimal_fn_s0_re1_type) fn,
  rr);

if(rcar)
  rcar->set_value(rr);
