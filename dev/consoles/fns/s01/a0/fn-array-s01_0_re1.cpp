void _f_1_(u1& retv, minimal_fn_s0_re1_type fn, minimal_fn_s1_re1_type sfn, void* _this)
{
 auto _sfn = (u1(_min_::*)())(sfn);
 if(_this) retv=((_min_*)_this->*_sfn)();

 else retv=((u1(*)()) fn)();
}
