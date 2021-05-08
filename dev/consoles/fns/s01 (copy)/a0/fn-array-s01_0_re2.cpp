void _f_2_(u2& retv, minimal_fn_s0_re2_type fn, minimal_fn_s1_re2_type sfn, void* _this)
{
 if(_this) retv=((u2(_min_::*)_this->*sfn)();
 else retv=((u2(*)()) fn)();}

