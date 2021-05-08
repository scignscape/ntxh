void _f_5_(QByteArray& retv, minimal_fn_s0_re5_type fn, minimal_fn_s1_re5_type sfn, void* _this)
{
 if(_this) retv=((QByteArray(_min_::*)_this->*sfn)();
 else retv=((QByteArray(*)()) fn)();}

