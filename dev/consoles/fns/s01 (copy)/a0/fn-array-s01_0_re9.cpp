void _f_9_(void*& retv, minimal_fn_s0_re9_type fn, minimal_fn_s1_re9_type sfn, void* _this)
{
 if(_this) retv=((void*(_min_::*)_this->*sfn)();
 else retv=((void*(*)()) fn)();}

