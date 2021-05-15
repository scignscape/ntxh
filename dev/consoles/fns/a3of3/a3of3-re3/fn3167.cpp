void _f_3167_3_(u4 pattern, QString& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re3_type fn,
  minimal_fn_s1_re3_type sfn, void* _this)
{
 switch(pattern)
 {
 case 112:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (QString(_min_::*)(u1,u1,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(u1,u1,r8))fn)(a1,a2,a3);
  } break;
 case 113:
  {u1 a1=*(u1*)arg1;u1 a2=*(u1*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (QString(_min_::*)(u1,u1,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(u1,u1,QVariant))fn)(a1,a2,a3);
  } break;
 case 121:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (QString(_min_::*)(u1,r8,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(u1,r8,u1))fn)(a1,a2,a3);
  } break;
 case 122:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (QString(_min_::*)(u1,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(u1,r8,r8))fn)(a1,a2,a3);
  } break;
 case 123:
  {u1 a1=*(u1*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (QString(_min_::*)(u1,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(u1,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 131:
  {u1 a1=*(u1*)arg1;QVariant a2 = *(QVariant*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (QString(_min_::*)(u1,QVariant,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(u1,QVariant,u1))fn)(a1,a2,a3);
  } break;
 case 132:
  {u1 a1=*(u1*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (QString(_min_::*)(u1,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(u1,QVariant,r8))fn)(a1,a2,a3);
  } break;
 case 133:
  {u1 a1=*(u1*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (QString(_min_::*)(u1,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(u1,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 211:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (QString(_min_::*)(r8,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(r8,u1,u1))fn)(a1,a2,a3);
  } break;
 case 212:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (QString(_min_::*)(r8,u1,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(r8,u1,r8))fn)(a1,a2,a3);
  } break;
 case 213:
  {r8 a1=*(r8*)arg1;u1 a2=*(u1*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (QString(_min_::*)(r8,u1,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(r8,u1,QVariant))fn)(a1,a2,a3);
  } break;
 case 221:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (QString(_min_::*)(r8,r8,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(r8,r8,u1))fn)(a1,a2,a3);
  } break;
 case 223:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (QString(_min_::*)(r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(r8,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 231:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (QString(_min_::*)(r8,QVariant,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(r8,QVariant,u1))fn)(a1,a2,a3);
  } break;
 case 232:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (QString(_min_::*)(r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(r8,QVariant,r8))fn)(a1,a2,a3);
  } break;
 case 233:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (QString(_min_::*)(r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(r8,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 311:
  {QVariant a1 = *(QVariant*)arg1;u1 a2=*(u1*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (QString(_min_::*)(QVariant,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(QVariant,u1,u1))fn)(a1,a2,a3);
  } break;
 case 312:
  {QVariant a1 = *(QVariant*)arg1;u1 a2=*(u1*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (QString(_min_::*)(QVariant,u1,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(QVariant,u1,r8))fn)(a1,a2,a3);
  } break;
 case 313:
  {QVariant a1 = *(QVariant*)arg1;u1 a2=*(u1*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (QString(_min_::*)(QVariant,u1,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(QVariant,u1,QVariant))fn)(a1,a2,a3);
  } break;
 case 321:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (QString(_min_::*)(QVariant,r8,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(QVariant,r8,u1))fn)(a1,a2,a3);
  } break;
 case 322:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (QString(_min_::*)(QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(QVariant,r8,r8))fn)(a1,a2,a3);
  } break;
 case 323:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (QString(_min_::*)(QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(QVariant,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 331:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;u1 a3=*(u1*)arg3;
   auto _sfn = (QString(_min_::*)(QVariant,QVariant,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(QVariant,QVariant,u1))fn)(a1,a2,a3);
  } break;
 case 332:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (QString(_min_::*)(QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(QVariant,QVariant,r8))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

