void _f_6_(r8& retv, minimal_fn_s0_re6_type fn, minimal_fn_s1_re6_type sfn, void* _this)
{
 if(_this) retv=((r8(_min_::*)_this->*sfn)();
 else retv=((r8(*)()) fn)();}

