void _f_4_(u4& retv, minimal_fn_s0_re4_type fn, minimal_fn_s1_re4_type sfn, void* _this)
{
 auto _sfn = (u4(_min_::*)())(sfn);
 if(_this) retv=((_min_*)_this->*_sfn)();

 else retv=((u4(*)()) fn)();
}
