void _f_3057_6_(u4 pattern, r8& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re6_type fn,
  minimal_fn_s1_re6_type sfn, void* _this)
{
 switch(pattern)
 {
 case 112:
  {n8& a1=*(n8*)arg1;n8& a2=*(n8*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (r8(_min_::*)(n8&,n8&,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8&,n8&,QByteArray))fn)(a1,a2,a3);
  } break;
 case 113:
  {n8& a1=*(n8*)arg1;n8& a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8&,n8&,QVariant))fn)(a1,a2,a3);
  } break;
 case 121:
  {n8& a1=*(n8*)arg1;QByteArray a2=*(QByteArray*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(n8&,QByteArray,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8&,QByteArray,n8&))fn)(a1,a2,a3);
  } break;
 case 122:
  {n8& a1=*(n8*)arg1;QByteArray a2=*(QByteArray*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (r8(_min_::*)(n8&,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8&,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;
 case 123:
  {n8& a1=*(n8*)arg1;QByteArray a2=*(QByteArray*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(n8&,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8&,QByteArray,QVariant))fn)(a1,a2,a3);
  } break;
 case 131:
  {n8& a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8&,QVariant,n8&))fn)(a1,a2,a3);
  } break;
 case 132:
  {n8& a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (r8(_min_::*)(n8&,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8&,QVariant,QByteArray))fn)(a1,a2,a3);
  } break;
 case 133:
  {n8& a1=*(n8*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(n8&,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 211:
  {QByteArray a1=*(QByteArray*)arg1;n8& a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(QByteArray,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QByteArray,n8&,n8&))fn)(a1,a2,a3);
  } break;
 case 212:
  {QByteArray a1=*(QByteArray*)arg1;n8& a2=*(n8*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (r8(_min_::*)(QByteArray,n8&,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QByteArray,n8&,QByteArray))fn)(a1,a2,a3);
  } break;
 case 213:
  {QByteArray a1=*(QByteArray*)arg1;n8& a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(QByteArray,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QByteArray,n8&,QVariant))fn)(a1,a2,a3);
  } break;
 case 221:
  {QByteArray a1=*(QByteArray*)arg1;QByteArray a2=*(QByteArray*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(QByteArray,QByteArray,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QByteArray,QByteArray,n8&))fn)(a1,a2,a3);
  } break;
 case 223:
  {QByteArray a1=*(QByteArray*)arg1;QByteArray a2=*(QByteArray*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QByteArray,QByteArray,QVariant))fn)(a1,a2,a3);
  } break;
 case 231:
  {QByteArray a1=*(QByteArray*)arg1;QVariant a2 = *(QVariant*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(QByteArray,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QByteArray,QVariant,n8&))fn)(a1,a2,a3);
  } break;
 case 232:
  {QByteArray a1=*(QByteArray*)arg1;QVariant a2 = *(QVariant*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (r8(_min_::*)(QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QByteArray,QVariant,QByteArray))fn)(a1,a2,a3);
  } break;
 case 233:
  {QByteArray a1=*(QByteArray*)arg1;QVariant a2 = *(QVariant*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QByteArray,QVariant,QVariant))fn)(a1,a2,a3);
  } break;
 case 311:
  {QVariant a1 = *(QVariant*)arg1;n8& a2=*(n8*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,n8&,n8&))fn)(a1,a2,a3);
  } break;
 case 312:
  {QVariant a1 = *(QVariant*)arg1;n8& a2=*(n8*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,n8&,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,n8&,QByteArray))fn)(a1,a2,a3);
  } break;
 case 313:
  {QVariant a1 = *(QVariant*)arg1;n8& a2=*(n8*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,n8&,QVariant))fn)(a1,a2,a3);
  } break;
 case 321:
  {QVariant a1 = *(QVariant*)arg1;QByteArray a2=*(QByteArray*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,QByteArray,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,QByteArray,n8&))fn)(a1,a2,a3);
  } break;
 case 322:
  {QVariant a1 = *(QVariant*)arg1;QByteArray a2=*(QByteArray*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;
 case 323:
  {QVariant a1 = *(QVariant*)arg1;QByteArray a2=*(QByteArray*)arg2;QVariant a3 = *(QVariant*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,QByteArray,QVariant))fn)(a1,a2,a3);
  } break;
 case 331:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;n8& a3=*(n8*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,QVariant,n8&))fn)(a1,a2,a3);
  } break;
 case 332:
  {QVariant a1 = *(QVariant*)arg1;QVariant a2 = *(QVariant*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (r8(_min_::*)(QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QVariant,QVariant,QByteArray))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

