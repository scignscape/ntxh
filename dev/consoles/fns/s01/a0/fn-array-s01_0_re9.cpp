void _f_9_(void*& retv, minimal_fn_s0_re9_type fn, minimal_fn_s1_re9_type sfn, void* _this)
{
 auto _sfn = (void*(_min_::*)())(sfn);
 if(_this) retv=((_min_*)_this->*_sfn)();

 else retv=((void*(*)()) fn)();
}
