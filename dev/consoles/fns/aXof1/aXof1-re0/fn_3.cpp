

void _f_X3_0_(u1 ac,  QVector<n8>& args, minimal_fn_s0_re0_type fn,
  minimal_fn_s1_re0_type sfn, void* _this)
{
 switch(ac)
 {

 case 1:
  {QString a1=*(QString*)args[0];
   auto _sfn = (void(_min_::*)(QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1);
   else ((void(*)(QString))fn)(a1);
  } break;

 case 2:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];
   auto _sfn = (void(_min_::*)(QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2);
   else ((void(*)(QString,QString))fn)(a1,a2);
  } break;

 case 3:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (void(_min_::*)(QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(QString,QString,QString))fn)(a1,a2,a3);
  } break;

 case 4:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (void(_min_::*)(QString,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QString,QString,QString,QString))fn)(a1,a2,a3,a4);
  } break;

 case 5:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(QString,QString,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

 case 6:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,QString,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 case 7:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];QString a7=*(QString*)args[6];
   auto _sfn = (void(_min_::*)(QString,QString,QString,QString,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7);
   else ((void(*)(QString,QString,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6,a7);
  } break;

 case 8:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];QString a7=*(QString*)args[6];QString a8=*(QString*)args[7];
   auto _sfn = (void(_min_::*)(QString,QString,QString,QString,QString,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7,a8);
   else ((void(*)(QString,QString,QString,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6,a7,a8);
  } break;

 }
}