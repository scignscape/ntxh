

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
void* rr = cc.value<void*>();

run_s01_Xof1_re9(fncode.distinct_type_pattern, fncode.arg_count,
   (minimal_fn_s0_re6_type) fn,
   (minimal_fn_s1_re6_type) sfn, args, rr, _this);

if(rcar)
  rcar->set_value(rr);
