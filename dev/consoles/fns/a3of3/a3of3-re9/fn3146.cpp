void _f_3146_9_(u4 pattern, void*& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, void** _this)
{
 switch(pattern)
 {
 case 112:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(u1,u1,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,u1,u4))fn)(a1,a2,a3);
  } break;
 case 113:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u1,u1,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,u1,r8))fn)(a1,a2,a3);
  } break;
 case 121:
  {u1 a1=*(u1*)arg1;u4 a2=*(u4*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(u1,u4,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,u4,u1))fn)(a1,a2,a3);
  } break;
 case 122:
  {u1 a1=*(u1*)arg1;u4 a2=*(u4*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(u1,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,u4,u4))fn)(a1,a2,a3);
  } break;
 case 123:
  {u1 a1=*(u1*)arg1;u4 a2=*(u4*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u1,u4,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,u4,r8))fn)(a1,a2,a3);
  } break;
 case 131:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(u1,r8,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,r8,u1))fn)(a1,a2,a3);
  } break;
 case 132:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(u1,r8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,r8,u4))fn)(a1,a2,a3);
  } break;
 case 133:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u1,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,r8,r8))fn)(a1,a2,a3);
  } break;
 case 211:
  {u4 a1=*(u4*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(u4,u1,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,u1,u1))fn)(a1,a2,a3);
  } break;
 case 212:
  {u4 a1=*(u4*)arg1;u1 a2=*(u1*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(u4,u1,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,u1,u4))fn)(a1,a2,a3);
  } break;
 case 213:
  {u4 a1=*(u4*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u4,u1,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,u1,r8))fn)(a1,a2,a3);
  } break;
 case 221:
  {u4 a1=*(u4*)arg1;u4 a2=*(u4*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(u4,u4,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,u4,u1))fn)(a1,a2,a3);
  } break;
 case 223:
  {u4 a1=*(u4*)arg1;u4 a2=*(u4*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u4,u4,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,u4,r8))fn)(a1,a2,a3);
  } break;
 case 231:
  {u4 a1=*(u4*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(u4,r8,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,r8,u1))fn)(a1,a2,a3);
  } break;
 case 232:
  {u4 a1=*(u4*)arg1;r8 a2=*(r8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(u4,r8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,r8,u4))fn)(a1,a2,a3);
  } break;
 case 233:
  {u4 a1=*(u4*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u4,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,r8,r8))fn)(a1,a2,a3);
  } break;
 case 311:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u1,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u1,u1))fn)(a1,a2,a3);
  } break;
 case 312:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u1,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u1,u4))fn)(a1,a2,a3);
  } break;
 case 313:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u1,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u1,r8))fn)(a1,a2,a3);
  } break;
 case 321:
  {r8 a1=*(r8*)arg1;u4 a2=*(u4*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u4,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u4,u1))fn)(a1,a2,a3);
  } break;
 case 322:
  {r8 a1=*(r8*)arg1;u4 a2=*(u4*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u4,u4))fn)(a1,a2,a3);
  } break;
 case 323:
  {r8 a1=*(r8*)arg1;u4 a2=*(u4*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u4,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u4,r8))fn)(a1,a2,a3);
  } break;
 case 331:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (void*(_min_::*)(r8,r8,u1))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,r8,u1))fn)(a1,a2,a3);
  } break;
 case 332:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(r8,r8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,r8,u4))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

