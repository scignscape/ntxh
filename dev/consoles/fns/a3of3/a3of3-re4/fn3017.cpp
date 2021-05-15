void _f_3017_4_(u4 pattern, u4& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re4_type fn,
  minimal_fn_s1_re4_type sfn, void* _this)
{
 switch(pattern)
 {
 case 112:
  {n8& a1=*(n8*)arg1;n8& a2=*(n8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(n8&,n8&,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,n8&,u1))fn)(a1,a2,a3);
  } break;
 case 113:
  {n8& a1=*(n8*)arg1;n8& a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u4(_min_::*)(n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,n8&,QVariant))fn)(a1,a2,a3);
  } break;
 case 121:
  {n8& a1=*(n8*)arg1;u1 a2=*(u1*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (u4(_min_::*)(n8&,u1,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,u1,n8&))fn)(a1,a2,a3);
  } break;
 case 122:
  {n8& a1=*(n8*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(n8&,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,u1,u1))fn)(a1,a2,a3);
  } break;
 case 123:
  {n8& a1=*(n8*)arg1;u1 a2=*(u1*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u4(_min_::*)(n8&,u1,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,u1,QVariant))fn)(a1,a2,a3);
  } break;
 case 131:
  {n8& a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (u4(_min_::*)(n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,QVariant,n8&))fn)(a1,a2,a3);
  } break;
 case 132:
  {n8& a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(n8&,QVariant,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,QVariant,u1))fn)(a1,a2,a3);
  } break;
 case 133:
  {n8& a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u4(_min_::*)(n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 211:
  {u1 a1=*(u1*)arg1;n8& a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (u4(_min_::*)(u1,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,n8&,n8&))fn)(a1,a2,a3);
  } break;
 case 212:
  {u1 a1=*(u1*)arg1;n8& a2=*(n8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(u1,n8&,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,n8&,u1))fn)(a1,a2,a3);
  } break;
 case 213:
  {u1 a1=*(u1*)arg1;n8& a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u4(_min_::*)(u1,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,n8&,QVariant))fn)(a1,a2,a3);
  } break;
 case 221:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (u4(_min_::*)(u1,u1,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,u1,n8&))fn)(a1,a2,a3);
  } break;
 case 223:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u4(_min_::*)(u1,u1,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,u1,QVariant))fn)(a1,a2,a3);
  } break;
 case 231:
  {u1 a1=*(u1*)arg1;QVariant a2 = *(QVariant*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (u4(_min_::*)(u1,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,QVariant,n8&))fn)(a1,a2,a3);
  } break;
 case 232:
  {u1 a1=*(u1*)arg1;QVariant a2 = *(QVariant*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(u1,QVariant,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,QVariant,u1))fn)(a1,a2,a3);
  } break;
 case 233:
  {u1 a1=*(u1*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u4(_min_::*)(u1,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u1,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 311:
  {QVariant a1 = *(QVariant*)arg1;n8& a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (u4(_min_::*)(QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,n8&,n8&))fn)(a1,a2,a3);
  } break;
 case 312:
  {QVariant a1 = *(QVariant*)arg1;n8& a2=*(n8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(QVariant,n8&,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,n8&,u1))fn)(a1,a2,a3);
  } break;
 case 313:
  {QVariant a1 = *(QVariant*)arg1;n8& a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u4(_min_::*)(QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,n8&,QVariant))fn)(a1,a2,a3);
  } break;
 case 321:
  {QVariant a1 = *(QVariant*)arg1;u1 a2=*(u1*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (u4(_min_::*)(QVariant,u1,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,u1,n8&))fn)(a1,a2,a3);
  } break;
 case 322:
  {QVariant a1 = *(QVariant*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(QVariant,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,u1,u1))fn)(a1,a2,a3);
  } break;
 case 323:
  {QVariant a1 = *(QVariant*)arg1;u1 a2=*(u1*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u4(_min_::*)(QVariant,u1,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,u1,QVariant))fn)(a1,a2,a3);
  } break;
 case 331:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,QVariant,n8&))fn)(a1,a2,a3);
  } break;
 case 332:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,QVariant,u1))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

