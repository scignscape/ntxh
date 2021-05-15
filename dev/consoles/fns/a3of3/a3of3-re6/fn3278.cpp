void _f_3278_6_(u4 pattern, r8& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re6_type fn,
  minimal_fn_s1_re6_type sfn, void** _this)
{
 switch(pattern)
 {
 case 112:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(u2,u2,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,u2,QVariant))fn)(a1,a2,a3);
  } break;
 case 113:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(u2,u2,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,u2,n8))fn)(a1,a2,a3);
  } break;
 case 121:
  {u2 a1=*(u2*)arg1;QVariant a2 = *(QVariant*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(u2,QVariant,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,QVariant,u2))fn)(a1,a2,a3);
  } break;
 case 122:
  {u2 a1=*(u2*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(u2,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 123:
  {u2 a1=*(u2*)arg1;QVariant a2 = *(QVariant*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(u2,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,QVariant,n8))fn)(a1,a2,a3);
  } break;
 case 131:
  {u2 a1=*(u2*)arg1;n8 a2=*(n8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(u2,n8,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,n8,u2))fn)(a1,a2,a3);
  } break;
 case 132:
  {u2 a1=*(u2*)arg1;n8 a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(u2,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,n8,QVariant))fn)(a1,a2,a3);
  } break;
 case 133:
  {u2 a1=*(u2*)arg1;n8 a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(u2,n8,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,n8,n8))fn)(a1,a2,a3);
  } break;
 case 211:
  {QVariant a1 = *(QVariant*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,u2,u2))fn)(a1,a2,a3);
  } break;
 case 212:
  {QVariant a1 = *(QVariant*)arg1;u2 a2=*(u2*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,u2,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,u2,QVariant))fn)(a1,a2,a3);
  } break;
 case 213:
  {QVariant a1 = *(QVariant*)arg1;u2 a2=*(u2*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,u2,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,u2,n8))fn)(a1,a2,a3);
  } break;
 case 221:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,QVariant,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,QVariant,u2))fn)(a1,a2,a3);
  } break;
 case 223:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,QVariant,n8))fn)(a1,a2,a3);
  } break;
 case 231:
  {QVariant a1 = *(QVariant*)arg1;n8 a2=*(n8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,n8,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,n8,u2))fn)(a1,a2,a3);
  } break;
 case 232:
  {QVariant a1 = *(QVariant*)arg1;n8 a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,n8,QVariant))fn)(a1,a2,a3);
  } break;
 case 233:
  {QVariant a1 = *(QVariant*)arg1;n8 a2=*(n8*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,n8,n8))fn)(a1,a2,a3);
  } break;
 case 311:
  {n8 a1=*(n8*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(n8,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8,u2,u2))fn)(a1,a2,a3);
  } break;
 case 312:
  {n8 a1=*(n8*)arg1;u2 a2=*(u2*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(n8,u2,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8,u2,QVariant))fn)(a1,a2,a3);
  } break;
 case 313:
  {n8 a1=*(n8*)arg1;u2 a2=*(u2*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(n8,u2,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8,u2,n8))fn)(a1,a2,a3);
  } break;
 case 321:
  {n8 a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(n8,QVariant,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8,QVariant,u2))fn)(a1,a2,a3);
  } break;
 case 322:
  {n8 a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 323:
  {n8 a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;n8 a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8,QVariant,n8))fn)(a1,a2,a3);
  } break;
 case 331:
  {n8 a1=*(n8*)arg1;n8 a2=*(n8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(n8,n8,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8,n8,u2))fn)(a1,a2,a3);
  } break;
 case 332:
  {n8 a1=*(n8*)arg1;n8 a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8,n8,QVariant))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

