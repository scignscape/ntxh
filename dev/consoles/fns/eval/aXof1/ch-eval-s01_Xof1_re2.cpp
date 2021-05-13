

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
  return;


QVector<n8> args;
lambda->pasn8vector(args, fncode.arg_count);

Chasm_Channel* sigma = ccp->channel("sigma");
void* _this;
if(sigma)
  _this = sigma->first_carrier().value<void*>();
else
  _this = nullptr;

Chasm_Carrier cc = retvalue->first_carrier();
u2 rr = cc.value<u2>();

run_s01_Xof1_re2(fncode.arg_count, fncode.distinct_type_pattern,
   (minimal_fn_s0_re2_type) fn,
   (minimal_fn_s1_re2_type) sfn, args, rr, _this);

if(rcar)
  rcar->set_value(rr);
