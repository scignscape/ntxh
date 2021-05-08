
Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;

Chasm_Carrier cc = resultch->first_carrier();

void* rr = cc.value<void*>();


Chasm_Channel* sigma = ccp->channel("sigma");

if(sigma)
{
 Chasm_Carrier scc = sigma->first_carrier();

 void* _this = scc.value<void*>();
 run_s01_0_re9(fncode, nullptr, (minimal_fn_s1_re9_type) sfn, rr,
   _this);
}
else
  run_s01_0_re9(fncode, (minimal_fn_s0_re9_type) fn, nullptr,
  rr, nullptr);

if(rcar)
  rcar->set_value(rr);
