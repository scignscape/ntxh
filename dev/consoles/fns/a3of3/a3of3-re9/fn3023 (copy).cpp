void _f_3023_9_(u4 pattern, void*& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, void* _this)
{
 switch(pattern)
 {
 case 312:
  {QString a1=*(QString*)arg1;n8& a2=*(n8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (void*(_min_::*)(QString,n8&,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QString,n8&,u2))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

