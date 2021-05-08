
Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
  return;

Chasm_Channel* sigma = ccp->channel("sigma");
void* _this;
if(sigma)
  _this = sigma->first_carrier().value<void*>();
else
  _this = nullptr;

Chasm_Carrier cc = retvalue->first_carrier();

QByteArray& rr = cc.value_as<QByteArray>();
run_s01_0_re5(fncode, (minimal_fn_s0_re5_type) fn,
  (minimal_fn_s1_re5_type) sfn, rr, _this);

if(rcar)
  rcar->set_value_as<QByteArray>(rr);
