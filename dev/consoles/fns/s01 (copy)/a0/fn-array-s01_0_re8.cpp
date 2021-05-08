void _f_8_(n8& retv, minimal_fn_s0_re8_type fn, minimal_fn_s1_re8_type sfn, void* _this)
{
 if(_this) retv=((n8(_min_::*)_this->*sfn)();
 else retv=((n8(*)()) fn)();}

