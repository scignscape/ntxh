

void _f_X4_4_(u1 ac, u4& retv,  QVector<n8>& args, minimal_fn_s0_re4_type fn,
  minimal_fn_s1_re4_type sfn, void* _this)
{
 switch(ac)
 {

 case 1:
  {u4 a1=*(u4*)args[0];
   auto _sfn = (u4(_min_::*)(u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1);
   else retv=((u4(*)(u4))fn)(a1);
  } break;

 case 2:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];
   auto _sfn = (u4(_min_::*)(u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
   else retv=((u4(*)(u4,u4))fn)(a1,a2);
  } break;

 case 3:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];
   auto _sfn = (u4(_min_::*)(u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u4,u4,u4))fn)(a1,a2,a3);
  } break;

 case 4:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(u4,u4,u4,u4))fn)(a1,a2,a3,a4);
  } break;

 case 5:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

 case 6:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 case 7:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];u4 a7=*(u4*)args[6];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7);
   else retv=((u4(*)(u4,u4,u4,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6,a7);
  } break;

 case 8:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];u4 a7=*(u4*)args[6];u4 a8=*(u4*)args[7];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,u4,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7,a8);
   else retv=((u4(*)(u4,u4,u4,u4,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6,a7,a8);
  } break;

 }
}