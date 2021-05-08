
//run_s0_0_re0(fncode, (minimal_fn_s0_re0_type) fn);


Chasm_Channel* sigma = ccp->channel("sigma");

if(sigma)
{
 Chasm_Carrier scc = sigma->first_carrier();

 void* _this = scc.value<void*>();
 run_s01_0_re0(fncode, nullptr, (minimal_fn_s1_re0_type) sfn,
   _this);
}
else
  run_s01_0_re0(fncode, (minimal_fn_s0_re0_type) fn,
  nullptr, nullptr);
