void _f_3267_6_(u4 pattern, r8& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re6_type fn,
  minimal_fn_s1_re6_type sfn, void* _this)
{
 switch(pattern)
 {
 case 112:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (r8(_min_::*)(u2,u2,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,u2,r8))fn)(a1,a2,a3);
  } break;
 case 113:
  {u2 a1=*(u2*)arg1;u2 a2=*(u2*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(u2,u2,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,u2,QVariant))fn)(a1,a2,a3);
  } break;
 case 121:
  {u2 a1=*(u2*)arg1;r8 a2=*(r8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(u2,r8,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,r8,u2))fn)(a1,a2,a3);
  } break;
 case 122:
  {u2 a1=*(u2*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (r8(_min_::*)(u2,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,r8,r8))fn)(a1,a2,a3);
  } break;
 case 123:
  {u2 a1=*(u2*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(u2,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 131:
  {u2 a1=*(u2*)arg1;QVariant a2 = *(QVariant*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(u2,QVariant,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,QVariant,u2))fn)(a1,a2,a3);
  } break;
 case 132:
  {u2 a1=*(u2*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (r8(_min_::*)(u2,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,QVariant,r8))fn)(a1,a2,a3);
  } break;
 case 133:
  {u2 a1=*(u2*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(u2,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 211:
  {r8 a1=*(r8*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(r8,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(r8,u2,u2))fn)(a1,a2,a3);
  } break;
 case 212:
  {r8 a1=*(r8*)arg1;u2 a2=*(u2*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (r8(_min_::*)(r8,u2,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(r8,u2,r8))fn)(a1,a2,a3);
  } break;
 case 213:
  {r8 a1=*(r8*)arg1;u2 a2=*(u2*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(r8,u2,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(r8,u2,QVariant))fn)(a1,a2,a3);
  } break;
 case 221:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(r8,r8,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(r8,r8,u2))fn)(a1,a2,a3);
  } break;
 case 223:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(r8,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 231:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(r8,QVariant,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(r8,QVariant,u2))fn)(a1,a2,a3);
  } break;
 case 232:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (r8(_min_::*)(r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(r8,QVariant,r8))fn)(a1,a2,a3);
  } break;
 case 233:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(r8,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 311:
  {QVariant a1 = *(QVariant*)arg1;u2 a2=*(u2*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,u2,u2))fn)(a1,a2,a3);
  } break;
 case 312:
  {QVariant a1 = *(QVariant*)arg1;u2 a2=*(u2*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,u2,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,u2,r8))fn)(a1,a2,a3);
  } break;
 case 313:
  {QVariant a1 = *(QVariant*)arg1;u2 a2=*(u2*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,u2,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,u2,QVariant))fn)(a1,a2,a3);
  } break;
 case 321:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,r8,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,r8,u2))fn)(a1,a2,a3);
  } break;
 case 322:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,r8,r8))fn)(a1,a2,a3);
  } break;
 case 323:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 331:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;u2 a3=*(u2*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,QVariant,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,QVariant,u2))fn)(a1,a2,a3);
  } break;
 case 332:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,QVariant,r8))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

