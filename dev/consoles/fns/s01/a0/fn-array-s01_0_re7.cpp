void _f_7_(QVariant& retv, minimal_fn_s0_re7_type fn, minimal_fn_s1_re7_type sfn, void* _this)
{
 auto _sfn = (QVariant(_min_::*)())(sfn);
 if(_this) retv=((_min_*)_this->*_sfn)();

 else retv=((QVariant(*)()) fn)();
}
