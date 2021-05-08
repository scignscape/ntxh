void _f_2_(u2& retv, minimal_fn_s0_re2_type fn, minimal_fn_s1_re2_type sfn, void* _this)
{
 auto _sfn = (u2(_min_::*)())(sfn);
 if(_this) retv=((_min_*)_this->*_sfn)();

 else retv=((u2(*)()) fn)();
}
