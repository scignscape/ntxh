void _f_7_(QVariant& retv, minimal_fn_s0_re7_type fn, minimal_fn_s1_re7_type sfn, void* _this)
{
 if(_this) retv=((QVariant(_min_::*)_this->*sfn)();
 else retv=((QVariant(*)()) fn)();}

