void _f_X3_9_(u1 ac, void*& retv, QVector<n8>& args, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, void* _this)
{
 switch(ac)
 {
 case 4:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];
   QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (void*(_min_::*)(QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(QString,QString,QString,QString))fn)(a1,a2,a3,a4);
  } break;

 }
}


