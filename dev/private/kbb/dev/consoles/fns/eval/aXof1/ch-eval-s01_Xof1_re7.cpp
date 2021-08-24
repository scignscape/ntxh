

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;

Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
  return;


QVector<n8> args;
lambda->pasn8vector(args, fncode.arg_count);

Chasm_Channel* sigma = ccp->channel("sigma");
void** _this; void* _this_;
if(sigma)
{
 _this_ = sigma->first_carrier().value<void*>();
 _this = &_this_;
}
else { _this = nullptr; _this_ = nullptr; }

Chasm_Carrier cc = retvalue->first_carrier();
QVariant& rr = cc.value_as<QVariant>();

run_s01_Xof1_re7(fncode.arg_count, fncode.distinct_pretype_pattern,
   (minimal_fn_s0_re7_type) fn,
   (minimal_fn_s1_re7_type) sfn, args, rr, _this);

if(rcar)
  rcar->set_value_as<QVariant>(rr);
