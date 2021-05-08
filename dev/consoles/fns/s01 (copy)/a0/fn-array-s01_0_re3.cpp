void _f_3_(QString& retv, minimal_fn_s0_re3_type fn, minimal_fn_s1_re3_type sfn, void* _this)
{
 if(_this) retv=((QString(_min_::*)_this->*sfn)();
 else retv=((QString(*)()) fn)();}

