void _f_0_(minimal_fn_s0_re0_type fn,
minimal_fn_s1_re0_type mfn, _min_* _this){

if(_this)
  (_this->*mfn)();
else
  ((void(*)()) fn)();

}

