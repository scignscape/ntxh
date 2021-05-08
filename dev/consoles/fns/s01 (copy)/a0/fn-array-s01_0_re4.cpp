void _f_4_(u4& retv, minimal_fn_s0_re4_type fn, minimal_fn_s1_re4_type sfn, void* _this)
{
 if(_this) retv=((u4(_min_::*)_this->*sfn)();
 else retv=((u4(*)()) fn)();}

