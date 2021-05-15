void _f_3168_9_(u4 pattern, void*& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, void** _this)
{
 switch(pattern)
 {
 case 112:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u1,u1,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,u1,r8))fn)(a1,a2,a3);
  } break;
 case 113:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (void*(_min_::*)(u1,u1,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,u1,n8))fn)(a1,a2,a3);
  } break;
 case 121:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(u1,r8,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,r8,u1))fn)(a1,a2,a3);
  } break;
 case 122:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u1,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,r8,r8))fn)(a1,a2,a3);
  } break;
 case 123:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (void*(_min_::*)(u1,r8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,r8,n8))fn)(a1,a2,a3);
  } break;
 case 131:
  {u1 a1=*(u1*)arg1;n8 a2=*(n8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(u1,n8,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,n8,u1))fn)(a1,a2,a3);
  } break;
 case 132:
  {u1 a1=*(u1*)arg1;n8 a2=*(n8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u1,n8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,n8,r8))fn)(a1,a2,a3);
  } break;
 case 133:
  {u1 a1=*(u1*)arg1;n8 a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (void*(_min_::*)(u1,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,n8,n8))fn)(a1,a2,a3);
  } break;
 case 211:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u1,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u1,u1))fn)(a1,a2,a3);
  } break;
 case 212:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u1,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u1,r8))fn)(a1,a2,a3);
  } break;
 case 213:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u1,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u1,n8))fn)(a1,a2,a3);
  } break;
 case 221:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(r8,r8,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,r8,u1))fn)(a1,a2,a3);
  } break;
 case 223:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (void*(_min_::*)(r8,r8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,r8,n8))fn)(a1,a2,a3);
  } break;
 case 231:
  {r8 a1=*(r8*)arg1;n8 a2=*(n8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(r8,n8,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,n8,u1))fn)(a1,a2,a3);
  } break;
 case 232:
  {r8 a1=*(r8*)arg1;n8 a2=*(n8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(r8,n8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,n8,r8))fn)(a1,a2,a3);
  } break;
 case 233:
  {r8 a1=*(r8*)arg1;n8 a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (void*(_min_::*)(r8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,n8,n8))fn)(a1,a2,a3);
  } break;
 case 311:
  {n8 a1=*(n8*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(n8,u1,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(n8,u1,u1))fn)(a1,a2,a3);
  } break;
 case 312:
  {n8 a1=*(n8*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(n8,u1,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(n8,u1,r8))fn)(a1,a2,a3);
  } break;
 case 313:
  {n8 a1=*(n8*)arg1;u1 a2=*(u1*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (void*(_min_::*)(n8,u1,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(n8,u1,n8))fn)(a1,a2,a3);
  } break;
 case 321:
  {n8 a1=*(n8*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(n8,r8,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(n8,r8,u1))fn)(a1,a2,a3);
  } break;
 case 322:
  {n8 a1=*(n8*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(n8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(n8,r8,r8))fn)(a1,a2,a3);
  } break;
 case 323:
  {n8 a1=*(n8*)arg1;r8 a2=*(r8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (void*(_min_::*)(n8,r8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(n8,r8,n8))fn)(a1,a2,a3);
  } break;
 case 331:
  {n8 a1=*(n8*)arg1;n8 a2=*(n8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(n8,n8,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(n8,n8,u1))fn)(a1,a2,a3);
  } break;
 case 332:
  {n8 a1=*(n8*)arg1;n8 a2=*(n8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(n8,n8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(n8,n8,r8))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

