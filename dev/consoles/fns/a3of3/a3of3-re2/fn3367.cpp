void _f_3367_2_(u4 pattern, u2& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re2_type fn,
  minimal_fn_s1_re2_type sfn, void** _this)
{
 switch(pattern)
 {
 case 112:
  {QString a1=*(QString*)arg1;QString a2=*(QString*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,QString,r8))fn)(a1,a2,a3);
  } break;
 case 113:
  {QString a1=*(QString*)arg1;QString a2=*(QString*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u2(_min_::*)(QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,QString,QVariant))fn)(a1,a2,a3);
  } break;
 case 121:
  {QString a1=*(QString*)arg1;r8 a2=*(r8*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,r8,QString))fn)(a1,a2,a3);
  } break;
 case 122:
  {QString a1=*(QString*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,r8,r8))fn)(a1,a2,a3);
  } break;
 case 123:
  {QString a1=*(QString*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u2(_min_::*)(QString,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 131:
  {QString a1=*(QString*)arg1;QVariant a2 = *(QVariant*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,QVariant,QString))fn)(a1,a2,a3);
  } break;
 case 132:
  {QString a1=*(QString*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QString,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,QVariant,r8))fn)(a1,a2,a3);
  } break;
 case 133:
  {QString a1=*(QString*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u2(_min_::*)(QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 211:
  {r8 a1=*(r8*)arg1;QString a2=*(QString*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QString,QString))fn)(a1,a2,a3);
  } break;
 case 212:
  {r8 a1=*(r8*)arg1;QString a2=*(QString*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QString,r8))fn)(a1,a2,a3);
  } break;
 case 213:
  {r8 a1=*(r8*)arg1;QString a2=*(QString*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QString,QVariant))fn)(a1,a2,a3);
  } break;
 case 221:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,r8,QString))fn)(a1,a2,a3);
  } break;
 case 223:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u2(_min_::*)(r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 231:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QVariant,QString))fn)(a1,a2,a3);
  } break;
 case 232:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QVariant,r8))fn)(a1,a2,a3);
  } break;
 case 233:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 311:
  {QVariant a1 = *(QVariant*)arg1;QString a2=*(QString*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QVariant,QString,QString))fn)(a1,a2,a3);
  } break;
 case 312:
  {QVariant a1 = *(QVariant*)arg1;QString a2=*(QString*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QVariant,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QVariant,QString,r8))fn)(a1,a2,a3);
  } break;
 case 313:
  {QVariant a1 = *(QVariant*)arg1;QString a2=*(QString*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u2(_min_::*)(QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QVariant,QString,QVariant))fn)(a1,a2,a3);
  } break;
 case 321:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(QVariant,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QVariant,r8,QString))fn)(a1,a2,a3);
  } break;
 case 322:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QVariant,r8,r8))fn)(a1,a2,a3);
  } break;
 case 323:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (u2(_min_::*)(QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QVariant,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 331:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QVariant,QVariant,QString))fn)(a1,a2,a3);
  } break;
 case 332:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QVariant,QVariant,r8))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}
