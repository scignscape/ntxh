

void _f_X1_8_(u1 ac, n8& retv,  QVector<n8>& args, minimal_fn_s0_re8_type fn,
  minimal_fn_s1_re8_type sfn, void* _this)
{
 switch(ac)
 {

 case 1:
  {u1 a1=*(u1*)args[0];
   auto _sfn = (n8(_min_::*)(u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1);
   else retv=((n8(*)(u1))fn)(a1);
  } break;

 case 2:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];
   auto _sfn = (n8(_min_::*)(u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
   else retv=((n8(*)(u1,u1))fn)(a1,a2);
  } break;

 case 3:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];
   auto _sfn = (n8(_min_::*)(u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(u1,u1,u1))fn)(a1,a2,a3);
  } break;

 case 4:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (n8(_min_::*)(u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(u1,u1,u1,u1))fn)(a1,a2,a3,a4);
  } break;

 case 5:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (n8(_min_::*)(u1,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(u1,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

 case 6:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (n8(_min_::*)(u1,u1,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(u1,u1,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 case 7:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];u1 a7=*(u1*)args[6];
   auto _sfn = (n8(_min_::*)(u1,u1,u1,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7);
   else retv=((n8(*)(u1,u1,u1,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6,a7);
  } break;

 case 8:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];u1 a7=*(u1*)args[6];u1 a8=*(u1*)args[7];
   auto _sfn = (n8(_min_::*)(u1,u1,u1,u1,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7,a8);
   else retv=((n8(*)(u1,u1,u1,u1,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6,a7,a8);
  } break;

 }
}