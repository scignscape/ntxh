

void _f_X3_3_(u1 ac, QString& retv,  QVector<n8>& args, minimal_fn_s0_re3_type fn,
  minimal_fn_s1_re3_type sfn, void* _this)
{
 switch(ac)
 {

 case 1:
  {QString a1=*(QString*)args[0];
   auto _sfn = (QString(_min_::*)(QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1);
   else retv=((QString(*)(QString))fn)(a1);
  } break;

 case 2:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];
   auto _sfn = (QString(_min_::*)(QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
   else retv=((QString(*)(QString,QString))fn)(a1,a2);
  } break;

 case 3:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (QString(_min_::*)(QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QString(*)(QString,QString,QString))fn)(a1,a2,a3);
  } break;

 case 4:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (QString(_min_::*)(QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QString(*)(QString,QString,QString,QString))fn)(a1,a2,a3,a4);
  } break;

 case 5:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QString(_min_::*)(QString,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QString(*)(QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

 case 6:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QString(_min_::*)(QString,QString,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QString(*)(QString,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 case 7:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];QString a7=*(QString*)args[6];
   auto _sfn = (QString(_min_::*)(QString,QString,QString,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7);
   else retv=((QString(*)(QString,QString,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6,a7);
  } break;

 case 8:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];QString a7=*(QString*)args[6];QString a8=*(QString*)args[7];
   auto _sfn = (QString(_min_::*)(QString,QString,QString,QString,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6,a7,a8);
   else retv=((QString(*)(QString,QString,QString,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6,a7,a8);
  } break;

 }
}