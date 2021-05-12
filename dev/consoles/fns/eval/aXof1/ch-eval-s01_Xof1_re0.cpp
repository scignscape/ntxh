

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;


QVector<n8> args;
lambda->pasn8vector(args, fncode.arg_count);

Chasm_Channel* sigma = ccp->channel("sigma");
void* _this;
if(sigma)
  _this = sigma->first_carrier().value<void*>();
else
  _this = nullptr;

run_s01_Xof1_re9(fncode.distinct_type_pattern, fncode.arg_count,
   (minimal_fn_s0_re0_type) fn,
   (minimal_fn_s1_re0_type) sfn, args, _this);
