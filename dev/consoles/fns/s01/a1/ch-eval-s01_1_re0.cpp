

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* sigma = ccp->channel("sigma");
void* _this;
if(sigma)
  _this = sigma->first_carrier().value<void*>();
else
  _this = nullptr;

run_s01_1_re0(fncode, (minimal_fn_s0_re0_type) fn,
  (minimal_fn_s1_re0_type) sfn, lambda->pasn8(1), _this);
