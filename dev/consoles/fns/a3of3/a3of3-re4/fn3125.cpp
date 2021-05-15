void _f_3125_4_(u4 pattern, u4& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re4_type fn,
  minimal_fn_s1_re4_type sfn, void* _this)
{
 switch(pattern)
 {
 case 112:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u4(_min_::*)(u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,u1,u2))fn)(a1,a2,a3);
  } break;
 case 113:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u4(_min_::*)(u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,u1,QByteArray))fn)(a1,a2,a3);
  } break;
 case 121:
  {u1 a1=*(u1*)arg1;u2 a2=*(u2*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,u2,u1))fn)(a1,a2,a3);
  } break;
 case 122:
  {u1 a1=*(u1*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u4(_min_::*)(u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,u2,u2))fn)(a1,a2,a3);
  } break;
 case 123:
  {u1 a1=*(u1*)arg1;u2 a2=*(u2*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u4(_min_::*)(u1,u2,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,u2,QByteArray))fn)(a1,a2,a3);
  } break;
 case 131:
  {u1 a1=*(u1*)arg1;QByteArray a2=*(QByteArray*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,QByteArray,u1))fn)(a1,a2,a3);
  } break;
 case 132:
  {u1 a1=*(u1*)arg1;QByteArray a2=*(QByteArray*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u4(_min_::*)(u1,QByteArray,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,QByteArray,u2))fn)(a1,a2,a3);
  } break;
 case 133:
  {u1 a1=*(u1*)arg1;QByteArray a2=*(QByteArray*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u4(_min_::*)(u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;
 case 211:
  {u2 a1=*(u2*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u2,u1,u1))fn)(a1,a2,a3);
  } break;
 case 212:
  {u2 a1=*(u2*)arg1;u1 a2=*(u1*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u4(_min_::*)(u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u2,u1,u2))fn)(a1,a2,a3);
  } break;
 case 213:
  {u2 a1=*(u2*)arg1;u1 a2=*(u1*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u4(_min_::*)(u2,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u2,u1,QByteArray))fn)(a1,a2,a3);
  } break;
 case 221:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u2,u2,u1))fn)(a1,a2,a3);
  } break;
 case 223:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u4(_min_::*)(u2,u2,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u2,u2,QByteArray))fn)(a1,a2,a3);
  } break;
 case 231:
  {u2 a1=*(u2*)arg1;QByteArray a2=*(QByteArray*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(u2,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u2,QByteArray,u1))fn)(a1,a2,a3);
  } break;
 case 232:
  {u2 a1=*(u2*)arg1;QByteArray a2=*(QByteArray*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u4(_min_::*)(u2,QByteArray,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u2,QByteArray,u2))fn)(a1,a2,a3);
  } break;
 case 233:
  {u2 a1=*(u2*)arg1;QByteArray a2=*(QByteArray*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u4(_min_::*)(u2,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u2,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;
 case 311:
  {QByteArray a1=*(QByteArray*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,u1,u1))fn)(a1,a2,a3);
  } break;
 case 312:
  {QByteArray a1=*(QByteArray*)arg1;u1 a2=*(u1*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u4(_min_::*)(QByteArray,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,u1,u2))fn)(a1,a2,a3);
  } break;
 case 313:
  {QByteArray a1=*(QByteArray*)arg1;u1 a2=*(u1*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u4(_min_::*)(QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,u1,QByteArray))fn)(a1,a2,a3);
  } break;
 case 321:
  {QByteArray a1=*(QByteArray*)arg1;u2 a2=*(u2*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(QByteArray,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,u2,u1))fn)(a1,a2,a3);
  } break;
 case 322:
  {QByteArray a1=*(QByteArray*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u4(_min_::*)(QByteArray,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,u2,u2))fn)(a1,a2,a3);
  } break;
 case 323:
  {QByteArray a1=*(QByteArray*)arg1;u2 a2=*(u2*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u4(_min_::*)(QByteArray,u2,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,u2,QByteArray))fn)(a1,a2,a3);
  } break;
 case 331:
  {QByteArray a1=*(QByteArray*)arg1;QByteArray a2=*(QByteArray*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,QByteArray,u1))fn)(a1,a2,a3);
  } break;
 case 332:
  {QByteArray a1=*(QByteArray*)arg1;QByteArray a2=*(QByteArray*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,QByteArray,u2))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

