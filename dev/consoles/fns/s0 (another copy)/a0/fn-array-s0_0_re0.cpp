void _f_0_(minimal_fn_s0_re0_type fn,
minimal_fn_s1_re0_type sfn, void* _this){

if(_this)
  ((_min_*)_this->*sfn)();
else
  ((void(*)()) fn)();

}

