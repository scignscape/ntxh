void _f_3048_8_(u4 pattern, n8& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re8_type fn,
  minimal_fn_s1_re8_type sfn, void** _this)
{
 switch(pattern)
 {
 case 112:
  {n8& a1=*(n8*)arg1;n8& a2=*(n8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,n8&,u4))fn)(a1,a2,a3);
  } break;
 case 113:
  {n8& a1=*(n8*)arg1;n8& a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,n8&,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,n8&,n8))fn)(a1,a2,a3);
  } break;
 case 121:
  {n8& a1=*(n8*)arg1;u4 a2=*(u4*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,u4,n8&))fn)(a1,a2,a3);
  } break;
 case 122:
  {n8& a1=*(n8*)arg1;u4 a2=*(u4*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,u4,u4))fn)(a1,a2,a3);
  } break;
 case 123:
  {n8& a1=*(n8*)arg1;u4 a2=*(u4*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,u4,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,u4,n8))fn)(a1,a2,a3);
  } break;
 case 131:
  {n8& a1=*(n8*)arg1;n8 a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,n8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,n8,n8&))fn)(a1,a2,a3);
  } break;
 case 132:
  {n8& a1=*(n8*)arg1;n8 a2=*(n8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,n8,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,n8,u4))fn)(a1,a2,a3);
  } break;
 case 133:
  {n8& a1=*(n8*)arg1;n8 a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,n8,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,n8,n8))fn)(a1,a2,a3);
  } break;
 case 211:
  {u4 a1=*(u4*)arg1;n8& a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u4,n8&,n8&))fn)(a1,a2,a3);
  } break;
 case 212:
  {u4 a1=*(u4*)arg1;n8& a2=*(n8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (n8(_min_::*)(u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u4,n8&,u4))fn)(a1,a2,a3);
  } break;
 case 213:
  {u4 a1=*(u4*)arg1;n8& a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(u4,n8&,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u4,n8&,n8))fn)(a1,a2,a3);
  } break;
 case 221:
  {u4 a1=*(u4*)arg1;u4 a2=*(u4*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u4,u4,n8&))fn)(a1,a2,a3);
  } break;
 case 223:
  {u4 a1=*(u4*)arg1;u4 a2=*(u4*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u4,u4,n8))fn)(a1,a2,a3);
  } break;
 case 231:
  {u4 a1=*(u4*)arg1;n8 a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(u4,n8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u4,n8,n8&))fn)(a1,a2,a3);
  } break;
 case 232:
  {u4 a1=*(u4*)arg1;n8 a2=*(n8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (n8(_min_::*)(u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u4,n8,u4))fn)(a1,a2,a3);
  } break;
 case 233:
  {u4 a1=*(u4*)arg1;n8 a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u4,n8,n8))fn)(a1,a2,a3);
  } break;
 case 311:
  {n8 a1=*(n8*)arg1;n8& a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8,n8&,n8&))fn)(a1,a2,a3);
  } break;
 case 312:
  {n8 a1=*(n8*)arg1;n8& a2=*(n8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (n8(_min_::*)(n8,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8,n8&,u4))fn)(a1,a2,a3);
  } break;
 case 313:
  {n8 a1=*(n8*)arg1;n8& a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8,n8&,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8,n8&,n8))fn)(a1,a2,a3);
  } break;
 case 321:
  {n8 a1=*(n8*)arg1;u4 a2=*(u4*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8,u4,n8&))fn)(a1,a2,a3);
  } break;
 case 322:
  {n8 a1=*(n8*)arg1;u4 a2=*(u4*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (n8(_min_::*)(n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8,u4,u4))fn)(a1,a2,a3);
  } break;
 case 323:
  {n8 a1=*(n8*)arg1;u4 a2=*(u4*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8,u4,n8))fn)(a1,a2,a3);
  } break;
 case 331:
  {n8 a1=*(n8*)arg1;n8 a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8,n8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8,n8,n8&))fn)(a1,a2,a3);
  } break;
 case 332:
  {n8 a1=*(n8*)arg1;n8 a2=*(n8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (n8(_min_::*)(n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8,n8,u4))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

