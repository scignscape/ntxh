

void _f_X8_2_(u1 ac, u2& retv,  QVector<n8>& args, minimal_fn_s0_re2_type fn,
  minimal_fn_s1_re2_type sfn, void** _this)
{
 switch(ac)
 {

 case 1:
  {n8 a1=*(n8*)args[0];
   auto _sfn = (u2(_min_::*)(n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1);
   else retv=((u2(*)(n8))fn)(a1);
  } break;

 case 2:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];
   auto _sfn = (u2(_min_::*)(n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
   else retv=((u2(*)(n8,n8))fn)(a1,a2);
  } break;

 case 3:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];
   auto _sfn = (u2(_min_::*)(n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u2(*)(n8,n8,n8))fn)(a1,a2,a3);
  } break;

 case 4:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (u2(_min_::*)(n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u2(*)(n8,n8,n8,n8))fn)(a1,a2,a3,a4);
  } break;

 case 5:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u2(_min_::*)(n8,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u2(*)(n8,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

 case 6:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u2(_min_::*)(n8,n8,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u2(*)(n8,n8,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 case 7:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];n8 a7=*(n8*)args[6];
   auto _sfn = (u2(_min_::*)(n8,n8,n8,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7);
   else retv=((u2(*)(n8,n8,n8,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6,a7);
  } break;

 case 8:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];n8 a7=*(n8*)args[6];n8 a8=*(n8*)args[7];
   auto _sfn = (u2(_min_::*)(n8,n8,n8,n8,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7,a8);
   else retv=((u2(*)(n8,n8,n8,n8,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6,a7,a8);
  } break;

 }
}