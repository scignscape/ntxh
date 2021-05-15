void _f_3248_1_(u4 pattern, u1& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re1_type fn,
  minimal_fn_s1_re1_type sfn, void** _this)
{
 switch(pattern)
 {
 case 112:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(u2,u2,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,u2,u4))fn)(a1,a2,a3);
  } break;
 case 113:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (u1(_min_::*)(u2,u2,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,u2,n8))fn)(a1,a2,a3);
  } break;
 case 121:
  {u2 a1=*(u2*)arg1;u4 a2=*(u4*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(u2,u4,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,u4,u2))fn)(a1,a2,a3);
  } break;
 case 122:
  {u2 a1=*(u2*)arg1;u4 a2=*(u4*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(u2,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,u4,u4))fn)(a1,a2,a3);
  } break;
 case 123:
  {u2 a1=*(u2*)arg1;u4 a2=*(u4*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (u1(_min_::*)(u2,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,u4,n8))fn)(a1,a2,a3);
  } break;
 case 131:
  {u2 a1=*(u2*)arg1;n8 a2=*(n8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(u2,n8,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,n8,u2))fn)(a1,a2,a3);
  } break;
 case 132:
  {u2 a1=*(u2*)arg1;n8 a2=*(n8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(u2,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,n8,u4))fn)(a1,a2,a3);
  } break;
 case 133:
  {u2 a1=*(u2*)arg1;n8 a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (u1(_min_::*)(u2,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,n8,n8))fn)(a1,a2,a3);
  } break;
 case 211:
  {u4 a1=*(u4*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(u4,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,u2,u2))fn)(a1,a2,a3);
  } break;
 case 212:
  {u4 a1=*(u4*)arg1;u2 a2=*(u2*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(u4,u2,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,u2,u4))fn)(a1,a2,a3);
  } break;
 case 213:
  {u4 a1=*(u4*)arg1;u2 a2=*(u2*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (u1(_min_::*)(u4,u2,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,u2,n8))fn)(a1,a2,a3);
  } break;
 case 221:
  {u4 a1=*(u4*)arg1;u4 a2=*(u4*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(u4,u4,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,u4,u2))fn)(a1,a2,a3);
  } break;
 case 223:
  {u4 a1=*(u4*)arg1;u4 a2=*(u4*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (u1(_min_::*)(u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,u4,n8))fn)(a1,a2,a3);
  } break;
 case 231:
  {u4 a1=*(u4*)arg1;n8 a2=*(n8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(u4,n8,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,n8,u2))fn)(a1,a2,a3);
  } break;
 case 232:
  {u4 a1=*(u4*)arg1;n8 a2=*(n8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,n8,u4))fn)(a1,a2,a3);
  } break;
 case 233:
  {u4 a1=*(u4*)arg1;n8 a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (u1(_min_::*)(u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,n8,n8))fn)(a1,a2,a3);
  } break;
 case 311:
  {n8 a1=*(n8*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(n8,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,u2,u2))fn)(a1,a2,a3);
  } break;
 case 312:
  {n8 a1=*(n8*)arg1;u2 a2=*(u2*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(n8,u2,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,u2,u4))fn)(a1,a2,a3);
  } break;
 case 313:
  {n8 a1=*(n8*)arg1;u2 a2=*(u2*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (u1(_min_::*)(n8,u2,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,u2,n8))fn)(a1,a2,a3);
  } break;
 case 321:
  {n8 a1=*(n8*)arg1;u4 a2=*(u4*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(n8,u4,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,u4,u2))fn)(a1,a2,a3);
  } break;
 case 322:
  {n8 a1=*(n8*)arg1;u4 a2=*(u4*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,u4,u4))fn)(a1,a2,a3);
  } break;
 case 323:
  {n8 a1=*(n8*)arg1;u4 a2=*(u4*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (u1(_min_::*)(n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,u4,n8))fn)(a1,a2,a3);
  } break;
 case 331:
  {n8 a1=*(n8*)arg1;n8 a2=*(n8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(n8,n8,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,n8,u2))fn)(a1,a2,a3);
  } break;
 case 332:
  {n8 a1=*(n8*)arg1;n8 a2=*(n8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,n8,u4))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

