void _f_3467_9_(u4 pattern, void*& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, void** _this)
{
 switch(pattern)
 {
 case 112:
  {u4 a1=*(u4*)arg1;u4 a2=*(u4*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u4,u4,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,u4,r8))fn)(a1,a2,a3);
  } break;
 case 113:
  {u4 a1=*(u4*)arg1;u4 a2=*(u4*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (void*(_min_::*)(u4,u4,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,u4,QVariant))fn)(a1,a2,a3);
  } break;
 case 121:
  {u4 a1=*(u4*)arg1;r8 a2=*(r8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(u4,r8,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,r8,u4))fn)(a1,a2,a3);
  } break;
 case 122:
  {u4 a1=*(u4*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u4,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,r8,r8))fn)(a1,a2,a3);
  } break;
 case 123:
  {u4 a1=*(u4*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (void*(_min_::*)(u4,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 131:
  {u4 a1=*(u4*)arg1;QVariant a2 = *(QVariant*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(u4,QVariant,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,QVariant,u4))fn)(a1,a2,a3);
  } break;
 case 132:
  {u4 a1=*(u4*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(u4,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,QVariant,r8))fn)(a1,a2,a3);
  } break;
 case 133:
  {u4 a1=*(u4*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (void*(_min_::*)(u4,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u4,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 211:
  {r8 a1=*(r8*)arg1;u4 a2=*(u4*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u4,u4))fn)(a1,a2,a3);
  } break;
 case 212:
  {r8 a1=*(r8*)arg1;u4 a2=*(u4*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u4,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u4,r8))fn)(a1,a2,a3);
  } break;
 case 213:
  {r8 a1=*(r8*)arg1;u4 a2=*(u4*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (void*(_min_::*)(r8,u4,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,u4,QVariant))fn)(a1,a2,a3);
  } break;
 case 221:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(r8,r8,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,r8,u4))fn)(a1,a2,a3);
  } break;
 case 223:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (void*(_min_::*)(r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 231:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(r8,QVariant,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,QVariant,u4))fn)(a1,a2,a3);
  } break;
 case 232:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,QVariant,r8))fn)(a1,a2,a3);
  } break;
 case 233:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (void*(_min_::*)(r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(r8,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 311:
  {QVariant a1 = *(QVariant*)arg1;u4 a2=*(u4*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(QVariant,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QVariant,u4,u4))fn)(a1,a2,a3);
  } break;
 case 312:
  {QVariant a1 = *(QVariant*)arg1;u4 a2=*(u4*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(QVariant,u4,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QVariant,u4,r8))fn)(a1,a2,a3);
  } break;
 case 313:
  {QVariant a1 = *(QVariant*)arg1;u4 a2=*(u4*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (void*(_min_::*)(QVariant,u4,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QVariant,u4,QVariant))fn)(a1,a2,a3);
  } break;
 case 321:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(QVariant,r8,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QVariant,r8,u4))fn)(a1,a2,a3);
  } break;
 case 322:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QVariant,r8,r8))fn)(a1,a2,a3);
  } break;
 case 323:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (void*(_min_::*)(QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QVariant,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 331:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;u4 a3=*(u4*)arg3;
   auto _sfn = (void*(_min_::*)(QVariant,QVariant,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QVariant,QVariant,u4))fn)(a1,a2,a3);
  } break;
 case 332:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (void*(_min_::*)(QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QVariant,QVariant,r8))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}
