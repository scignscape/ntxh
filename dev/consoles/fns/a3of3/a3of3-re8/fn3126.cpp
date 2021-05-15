void _f_3126_8_(u4 pattern, n8& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re8_type fn,
  minimal_fn_s1_re8_type sfn, void** _this)
{
 switch(pattern)
 {
 case 112:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (n8(_min_::*)(u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u1,u1,u2))fn)(a1,a2,a3);
  } break;
 case 113:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(u1,u1,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u1,u1,r8))fn)(a1,a2,a3);
  } break;
 case 121:
  {u1 a1=*(u1*)arg1;u2 a2=*(u2*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (n8(_min_::*)(u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u1,u2,u1))fn)(a1,a2,a3);
  } break;
 case 122:
  {u1 a1=*(u1*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (n8(_min_::*)(u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u1,u2,u2))fn)(a1,a2,a3);
  } break;
 case 123:
  {u1 a1=*(u1*)arg1;u2 a2=*(u2*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(u1,u2,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u1,u2,r8))fn)(a1,a2,a3);
  } break;
 case 131:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (n8(_min_::*)(u1,r8,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u1,r8,u1))fn)(a1,a2,a3);
  } break;
 case 132:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (n8(_min_::*)(u1,r8,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u1,r8,u2))fn)(a1,a2,a3);
  } break;
 case 133:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(u1,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u1,r8,r8))fn)(a1,a2,a3);
  } break;
 case 211:
  {u2 a1=*(u2*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (n8(_min_::*)(u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u2,u1,u1))fn)(a1,a2,a3);
  } break;
 case 212:
  {u2 a1=*(u2*)arg1;u1 a2=*(u1*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (n8(_min_::*)(u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u2,u1,u2))fn)(a1,a2,a3);
  } break;
 case 213:
  {u2 a1=*(u2*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(u2,u1,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u2,u1,r8))fn)(a1,a2,a3);
  } break;
 case 221:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (n8(_min_::*)(u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u2,u2,u1))fn)(a1,a2,a3);
  } break;
 case 223:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(u2,u2,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u2,u2,r8))fn)(a1,a2,a3);
  } break;
 case 231:
  {u2 a1=*(u2*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (n8(_min_::*)(u2,r8,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u2,r8,u1))fn)(a1,a2,a3);
  } break;
 case 232:
  {u2 a1=*(u2*)arg1;r8 a2=*(r8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (n8(_min_::*)(u2,r8,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u2,r8,u2))fn)(a1,a2,a3);
  } break;
 case 233:
  {u2 a1=*(u2*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(u2,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u2,r8,r8))fn)(a1,a2,a3);
  } break;
 case 311:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (n8(_min_::*)(r8,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,u1,u1))fn)(a1,a2,a3);
  } break;
 case 312:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (n8(_min_::*)(r8,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,u1,u2))fn)(a1,a2,a3);
  } break;
 case 313:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(r8,u1,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,u1,r8))fn)(a1,a2,a3);
  } break;
 case 321:
  {r8 a1=*(r8*)arg1;u2 a2=*(u2*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (n8(_min_::*)(r8,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,u2,u1))fn)(a1,a2,a3);
  } break;
 case 322:
  {r8 a1=*(r8*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (n8(_min_::*)(r8,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,u2,u2))fn)(a1,a2,a3);
  } break;
 case 323:
  {r8 a1=*(r8*)arg1;u2 a2=*(u2*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(r8,u2,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,u2,r8))fn)(a1,a2,a3);
  } break;
 case 331:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (n8(_min_::*)(r8,r8,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,r8,u1))fn)(a1,a2,a3);
  } break;
 case 332:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (n8(_min_::*)(r8,r8,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,r8,u2))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

