void _f_3356_2_(u4 pattern, u2& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re2_type fn,
  minimal_fn_s1_re2_type sfn, void* _this)
{
 switch(pattern)
 {
 case 112:
  {QString a1=*(QString*)arg1;QString a2=*(QString*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u2(_min_::*)(QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,QString,QByteArray))fn)(a1,a2,a3);
  } break;
 case 113:
  {QString a1=*(QString*)arg1;QString a2=*(QString*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,QString,r8))fn)(a1,a2,a3);
  } break;
 case 121:
  {QString a1=*(QString*)arg1;QByteArray a2=*(QByteArray*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,QByteArray,QString))fn)(a1,a2,a3);
  } break;
 case 122:
  {QString a1=*(QString*)arg1;QByteArray a2=*(QByteArray*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u2(_min_::*)(QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;
 case 123:
  {QString a1=*(QString*)arg1;QByteArray a2=*(QByteArray*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QString,QByteArray,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,QByteArray,r8))fn)(a1,a2,a3);
  } break;
 case 131:
  {QString a1=*(QString*)arg1;r8 a2=*(r8*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,r8,QString))fn)(a1,a2,a3);
  } break;
 case 132:
  {QString a1=*(QString*)arg1;r8 a2=*(r8*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u2(_min_::*)(QString,r8,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,r8,QByteArray))fn)(a1,a2,a3);
  } break;
 case 133:
  {QString a1=*(QString*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QString,r8,r8))fn)(a1,a2,a3);
  } break;
 case 211:
  {QByteArray a1=*(QByteArray*)arg1;QString a2=*(QString*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QByteArray,QString,QString))fn)(a1,a2,a3);
  } break;
 case 212:
  {QByteArray a1=*(QByteArray*)arg1;QString a2=*(QString*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u2(_min_::*)(QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QByteArray,QString,QByteArray))fn)(a1,a2,a3);
  } break;
 case 213:
  {QByteArray a1=*(QByteArray*)arg1;QString a2=*(QString*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QByteArray,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QByteArray,QString,r8))fn)(a1,a2,a3);
  } break;
 case 221:
  {QByteArray a1=*(QByteArray*)arg1;QByteArray a2=*(QByteArray*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QByteArray,QByteArray,QString))fn)(a1,a2,a3);
  } break;
 case 223:
  {QByteArray a1=*(QByteArray*)arg1;QByteArray a2=*(QByteArray*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QByteArray,QByteArray,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QByteArray,QByteArray,r8))fn)(a1,a2,a3);
  } break;
 case 231:
  {QByteArray a1=*(QByteArray*)arg1;r8 a2=*(r8*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(QByteArray,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QByteArray,r8,QString))fn)(a1,a2,a3);
  } break;
 case 232:
  {QByteArray a1=*(QByteArray*)arg1;r8 a2=*(r8*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u2(_min_::*)(QByteArray,r8,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QByteArray,r8,QByteArray))fn)(a1,a2,a3);
  } break;
 case 233:
  {QByteArray a1=*(QByteArray*)arg1;r8 a2=*(r8*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(QByteArray,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(QByteArray,r8,r8))fn)(a1,a2,a3);
  } break;
 case 311:
  {r8 a1=*(r8*)arg1;QString a2=*(QString*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QString,QString))fn)(a1,a2,a3);
  } break;
 case 312:
  {r8 a1=*(r8*)arg1;QString a2=*(QString*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QString,QByteArray))fn)(a1,a2,a3);
  } break;
 case 313:
  {r8 a1=*(r8*)arg1;QString a2=*(QString*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QString,r8))fn)(a1,a2,a3);
  } break;
 case 321:
  {r8 a1=*(r8*)arg1;QByteArray a2=*(QByteArray*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QByteArray,QString))fn)(a1,a2,a3);
  } break;
 case 322:
  {r8 a1=*(r8*)arg1;QByteArray a2=*(QByteArray*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;
 case 323:
  {r8 a1=*(r8*)arg1;QByteArray a2=*(QByteArray*)arg2;r8 a3=*(r8*)arg3;
   auto _sfn = (u2(_min_::*)(r8,QByteArray,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,QByteArray,r8))fn)(a1,a2,a3);
  } break;
 case 331:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;QString a3=*(QString*)arg3;
   auto _sfn = (u2(_min_::*)(r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,r8,QString))fn)(a1,a2,a3);
  } break;
 case 332:
  {r8 a1=*(r8*)arg1;r8 a2=*(r8*)arg2;QByteArray a3=*(QByteArray*)arg3;
   auto _sfn = (u2(_min_::*)(r8,r8,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(r8,r8,QByteArray))fn)(a1,a2,a3);
  } break;
  //end of switch
 }
}

