void _f_8_(n8& retv, minimal_fn_s0_re8_type fn, minimal_fn_s1_re8_type sfn, void* _this)
{
 auto _sfn = (n8(_min_::*)())(sfn);
 if(_this) retv=((_min_*)_this->*_sfn)();

 else retv=((n8(*)()) fn)();
}
