

void _f_X6_3_(u1 ac, QString& retv,  QVector<n8>& args, minimal_fn_s0_re3_type fn,
  minimal_fn_s1_re3_type sfn, void** _this)
{
 switch(ac)
 {

 case 1:
  {r8 a1=*(r8*)args[0];
   auto _sfn = (QString(_min_::*)(r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1);
   else retv=((QString(*)(r8))fn)(a1);
  } break;

 case 2:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];
   auto _sfn = (QString(_min_::*)(r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
   else retv=((QString(*)(r8,r8))fn)(a1,a2);
  } break;

 case 3:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (QString(_min_::*)(r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(r8,r8,r8))fn)(a1,a2,a3);
  } break;

 case 4:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (QString(_min_::*)(r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QString(*)(r8,r8,r8,r8))fn)(a1,a2,a3,a4);
  } break;

 case 5:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QString(_min_::*)(r8,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QString(*)(r8,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

 case 6:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QString(_min_::*)(r8,r8,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QString(*)(r8,r8,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 case 7:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];r8 a7=*(r8*)args[6];
   auto _sfn = (QString(_min_::*)(r8,r8,r8,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7);
   else retv=((QString(*)(r8,r8,r8,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6,a7);
  } break;

 case 8:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];r8 a7=*(r8*)args[6];r8 a8=*(r8*)args[7];
   auto _sfn = (QString(_min_::*)(r8,r8,r8,r8,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7,a8);
   else retv=((QString(*)(r8,r8,r8,r8,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6,a7,a8);
  } break;

 }
}