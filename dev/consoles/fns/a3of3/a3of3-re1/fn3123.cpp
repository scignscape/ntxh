void _f_3123_1_(u4 pattern, u1& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re1_type fn,
  minimal_fn_s1_re1_type sfn, void* _this)
{
 switch(pattern)
 {
 case 112:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,u1,u2))fn)(a1,a2,a3);
  } break;
 case 113:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u1(_min_::*)(u1,u1,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,u1,QString))fn)(a1,a2,a3);
  } break;
 case 121:
  {u1 a1=*(u1*)arg1;u2 a2=*(u2*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,u2,u1))fn)(a1,a2,a3);
  } break;
 case 122:
  {u1 a1=*(u1*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,u2,u2))fn)(a1,a2,a3);
  } break;
 case 123:
  {u1 a1=*(u1*)arg1;u2 a2=*(u2*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u1(_min_::*)(u1,u2,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,u2,QString))fn)(a1,a2,a3);
  } break;
 case 131:
  {u1 a1=*(u1*)arg1;QString a2=*(QString*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(u1,QString,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,QString,u1))fn)(a1,a2,a3);
  } break;
 case 132:
  {u1 a1=*(u1*)arg1;QString a2=*(QString*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(u1,QString,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,QString,u2))fn)(a1,a2,a3);
  } break;
 case 133:
  {u1 a1=*(u1*)arg1;QString a2=*(QString*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u1(_min_::*)(u1,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,QString,QString))fn)(a1,a2,a3);
  } break;
 case 211:
  {u2 a1=*(u2*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,u1,u1))fn)(a1,a2,a3);
  } break;
 case 212:
  {u2 a1=*(u2*)arg1;u1 a2=*(u1*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,u1,u2))fn)(a1,a2,a3);
  } break;
 case 213:
  {u2 a1=*(u2*)arg1;u1 a2=*(u1*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u1(_min_::*)(u2,u1,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,u1,QString))fn)(a1,a2,a3);
  } break;
 case 221:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,u2,u1))fn)(a1,a2,a3);
  } break;
 case 223:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u1(_min_::*)(u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,u2,QString))fn)(a1,a2,a3);
  } break;
 case 231:
  {u2 a1=*(u2*)arg1;QString a2=*(QString*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(u2,QString,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,QString,u1))fn)(a1,a2,a3);
  } break;
 case 232:
  {u2 a1=*(u2*)arg1;QString a2=*(QString*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,QString,u2))fn)(a1,a2,a3);
  } break;
 case 233:
  {u2 a1=*(u2*)arg1;QString a2=*(QString*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u1(_min_::*)(u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u2,QString,QString))fn)(a1,a2,a3);
  } break;
 case 311:
  {QString a1=*(QString*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(QString,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,u1,u1))fn)(a1,a2,a3);
  } break;
 case 312:
  {QString a1=*(QString*)arg1;u1 a2=*(u1*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(QString,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,u1,u2))fn)(a1,a2,a3);
  } break;
 case 313:
  {QString a1=*(QString*)arg1;u1 a2=*(u1*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u1(_min_::*)(QString,u1,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,u1,QString))fn)(a1,a2,a3);
  } break;
 case 321:
  {QString a1=*(QString*)arg1;u2 a2=*(u2*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(QString,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,u2,u1))fn)(a1,a2,a3);
  } break;
 case 322:
  {QString a1=*(QString*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,u2,u2))fn)(a1,a2,a3);
  } break;
 case 323:
  {QString a1=*(QString*)arg1;u2 a2=*(u2*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u1(_min_::*)(QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,u2,QString))fn)(a1,a2,a3);
  } break;
 case 331:
  {QString a1=*(QString*)arg1;QString a2=*(QString*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(QString,QString,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,QString,u1))fn)(a1,a2,a3);
  } break;
 case 332:
  {QString a1=*(QString*)arg1;QString a2=*(QString*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (u1(_min_::*)(QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,QString,u2))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

