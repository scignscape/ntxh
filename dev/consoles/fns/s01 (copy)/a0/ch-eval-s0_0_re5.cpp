
Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
  return;

Chasm_Channel* sigma = ccp->channel("sigma");
if(!sigma)
return;

Chasm_Carrier cc = resultch->first_carrier();

QByteArray& rr = cc.value_as<QByteArray>();
run_s01_0_re5(fncode, (minimal_fn_s0_re5_type) fn,
  (minimal_fn_s1_re5_type) sfn, rr);

if(rcar)
  rcar->set_value_as<QByteArray>(rr);
