void _f_5_(QByteArray& retv, minimal_fn_s0_re5_type fn, minimal_fn_s1_re5_type sfn, void* _this)
{
 auto _sfn = (QByteArray(_min_::*)())(sfn);
 if(_this) retv=((_min_*)_this->*_sfn)();

 else retv=((QByteArray(*)()) fn)();
}
