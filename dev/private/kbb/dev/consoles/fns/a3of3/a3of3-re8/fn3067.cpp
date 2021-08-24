void _f_3067_8_(u4 pattern, n8& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re8_type fn,
  minimal_fn_s1_re8_type sfn, void** _this)
{
 switch(pattern)
 {
 case 112:
  {n8& a1=*(n8*)arg1;n8& a2=*(n8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,n8&,r8))fn)(a1,a2,a3);
  } break;
 case 113:
  {n8& a1=*(n8*)arg1;n8& a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,n8&,QVariant))fn)(a1,a2,a3);
  } break;
 case 121:
  {n8& a1=*(n8*)arg1;r8 a2=*(r8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,r8,n8&))fn)(a1,a2,a3);
  } break;
 case 122:
  {n8& a1=*(n8*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,r8,r8))fn)(a1,a2,a3);
  } break;
 case 123:
  {n8& a1=*(n8*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 131:
  {n8& a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,QVariant,n8&))fn)(a1,a2,a3);
  } break;
 case 132:
  {n8& a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,QVariant,r8))fn)(a1,a2,a3);
  } break;
 case 133:
  {n8& a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (n8(_min_::*)(n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(n8&,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 211:
  {r8 a1=*(r8*)arg1;n8& a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,n8&,n8&))fn)(a1,a2,a3);
  } break;
 case 212:
  {r8 a1=*(r8*)arg1;n8& a2=*(n8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,n8&,r8))fn)(a1,a2,a3);
  } break;
 case 213:
  {r8 a1=*(r8*)arg1;n8& a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (n8(_min_::*)(r8,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,n8&,QVariant))fn)(a1,a2,a3);
  } break;
 case 221:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,r8,n8&))fn)(a1,a2,a3);
  } break;
 case 223:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (n8(_min_::*)(r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 231:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(r8,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,QVariant,n8&))fn)(a1,a2,a3);
  } break;
 case 232:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,QVariant,r8))fn)(a1,a2,a3);
  } break;
 case 233:
  {r8 a1=*(r8*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (n8(_min_::*)(r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(r8,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 311:
  {QVariant a1 = *(QVariant*)arg1;n8& a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,n8&,n8&))fn)(a1,a2,a3);
  } break;
 case 312:
  {QVariant a1 = *(QVariant*)arg1;n8& a2=*(n8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(QVariant,n8&,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,n8&,r8))fn)(a1,a2,a3);
  } break;
 case 313:
  {QVariant a1 = *(QVariant*)arg1;n8& a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (n8(_min_::*)(QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,n8&,QVariant))fn)(a1,a2,a3);
  } break;
 case 321:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(QVariant,r8,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,r8,n8&))fn)(a1,a2,a3);
  } break;
 case 322:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,r8,r8))fn)(a1,a2,a3);
  } break;
 case 323:
  {QVariant a1 = *(QVariant*)arg1;r8 a2=*(r8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (n8(_min_::*)(QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,r8,QVariant))fn)(a1,a2,a3);
  } break;
 case 331:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,QVariant,n8&))fn)(a1,a2,a3);
  } break;
 case 332:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,QVariant,r8))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

