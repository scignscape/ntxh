void _f_3147_1_(u4 pattern, u1& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re1_type fn,
  minimal_fn_s1_re1_type sfn, void** _this)
{
 switch(pattern)
 {
 case 112:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(u1,u1,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,u1,u4))fn)(a1,a2,a3);
  } break;
 case 113:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u1(_min_::*)(u1,u1,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,u1,QVariant))fn)(a1,a2,a3);
  } break;
 case 121:
  {u1 a1=*(u1*)arg1;u4 a2=*(u4*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(u1,u4,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,u4,u1))fn)(a1,a2,a3);
  } break;
 case 122:
  {u1 a1=*(u1*)arg1;u4 a2=*(u4*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(u1,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,u4,u4))fn)(a1,a2,a3);
  } break;
 case 123:
  {u1 a1=*(u1*)arg1;u4 a2=*(u4*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u1(_min_::*)(u1,u4,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,u4,QVariant))fn)(a1,a2,a3);
  } break;
 case 131:
  {u1 a1=*(u1*)arg1;QVariant a2 = *(QVariant*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(u1,QVariant,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,QVariant,u1))fn)(a1,a2,a3);
  } break;
 case 132:
  {u1 a1=*(u1*)arg1;QVariant a2 = *(QVariant*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(u1,QVariant,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,QVariant,u4))fn)(a1,a2,a3);
  } break;
 case 133:
  {u1 a1=*(u1*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u1(_min_::*)(u1,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u1,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 211:
  {u4 a1=*(u4*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(u4,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,u1,u1))fn)(a1,a2,a3);
  } break;
 case 212:
  {u4 a1=*(u4*)arg1;u1 a2=*(u1*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(u4,u1,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,u1,u4))fn)(a1,a2,a3);
  } break;
 case 213:
  {u4 a1=*(u4*)arg1;u1 a2=*(u1*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u1(_min_::*)(u4,u1,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,u1,QVariant))fn)(a1,a2,a3);
  } break;
 case 221:
  {u4 a1=*(u4*)arg1;u4 a2=*(u4*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(u4,u4,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,u4,u1))fn)(a1,a2,a3);
  } break;
 case 223:
  {u4 a1=*(u4*)arg1;u4 a2=*(u4*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u1(_min_::*)(u4,u4,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,u4,QVariant))fn)(a1,a2,a3);
  } break;
 case 231:
  {u4 a1=*(u4*)arg1;QVariant a2 = *(QVariant*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(u4,QVariant,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,QVariant,u1))fn)(a1,a2,a3);
  } break;
 case 232:
  {u4 a1=*(u4*)arg1;QVariant a2 = *(QVariant*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(u4,QVariant,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,QVariant,u4))fn)(a1,a2,a3);
  } break;
 case 233:
  {u4 a1=*(u4*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u1(_min_::*)(u4,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(u4,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 311:
  {QVariant a1 = *(QVariant*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(QVariant,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,u1,u1))fn)(a1,a2,a3);
  } break;
 case 312:
  {QVariant a1 = *(QVariant*)arg1;u1 a2=*(u1*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(QVariant,u1,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,u1,u4))fn)(a1,a2,a3);
  } break;
 case 313:
  {QVariant a1 = *(QVariant*)arg1;u1 a2=*(u1*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u1(_min_::*)(QVariant,u1,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,u1,QVariant))fn)(a1,a2,a3);
  } break;
 case 321:
  {QVariant a1 = *(QVariant*)arg1;u4 a2=*(u4*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(QVariant,u4,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,u4,u1))fn)(a1,a2,a3);
  } break;
 case 322:
  {QVariant a1 = *(QVariant*)arg1;u4 a2=*(u4*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(QVariant,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,u4,u4))fn)(a1,a2,a3);
  } break;
 case 323:
  {QVariant a1 = *(QVariant*)arg1;u4 a2=*(u4*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u1(_min_::*)(QVariant,u4,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,u4,QVariant))fn)(a1,a2,a3);
  } break;
 case 331:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,QVariant,u1))fn)(a1,a2,a3);
  } break;
 case 332:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,QVariant,u4))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

