

void _f_X2_3_(u1 ac, QString& retv,  QVector<n8>& args, minimal_fn_s0_re3_type fn,
  minimal_fn_s1_re3_type sfn, void* _this)
{
 switch(ac)
 {

 case 1:
  {u2 a1=*(u2*)args[0];
   auto _sfn = (QString(_min_::*)(u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1);
   else retv=((QString(*)(u2))fn)(a1);
  } break;

 case 2:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];
   auto _sfn = (QString(_min_::*)(u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
   else retv=((QString(*)(u2,u2))fn)(a1,a2);
  } break;

 case 3:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];
   auto _sfn = (QString(_min_::*)(u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(u2,u2,u2))fn)(a1,a2,a3);
  } break;

 case 4:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (QString(_min_::*)(u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QString(*)(u2,u2,u2,u2))fn)(a1,a2,a3,a4);
  } break;

 case 5:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QString(_min_::*)(u2,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QString(*)(u2,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

 case 6:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QString(_min_::*)(u2,u2,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QString(*)(u2,u2,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 case 7:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];u2 a7=*(u2*)args[6];
   auto _sfn = (QString(_min_::*)(u2,u2,u2,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7);
   else retv=((QString(*)(u2,u2,u2,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6,a7);
  } break;

 case 8:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];u2 a7=*(u2*)args[6];u2 a8=*(u2*)args[7];
   auto _sfn = (QString(_min_::*)(u2,u2,u2,u2,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7,a8);
   else retv=((QString(*)(u2,u2,u2,u2,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6,a7,a8);
  } break;

 }
}