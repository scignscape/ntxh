

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
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

run_s01_Xof1_re0(fncode.arg_count, fncode.distinct_pretype_pattern,
   (minimal_fn_s0_re0_type) fn,
   (minimal_fn_s1_re0_type) sfn, args, _this);
