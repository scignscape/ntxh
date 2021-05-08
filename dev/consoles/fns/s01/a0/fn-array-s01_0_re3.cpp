void _f_3_(QString& retv, minimal_fn_s0_re3_type fn, minimal_fn_s1_re3_type sfn, void* _this)
{
 auto _sfn = (QString(_min_::*)())(sfn);
 if(_this) retv=((_min_*)_this->*_sfn)();

 else retv=((QString(*)()) fn)();
}
