

void _f_X34_5_(u1 ac_pattern, QByteArray& retv,  QVector<n8>& args, minimal_fn_s0_re5_type fn,
  minimal_fn_s1_re5_type sfn, void** _this) // # 24
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];
  auto _sfn = (QByteArray(_min_::*)(QString,u4))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((QByteArray(*)(QString,u4))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];
  auto _sfn = (QByteArray(_min_::*)(u4,QString))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((QByteArray(*)(u4,QString))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(QString,QString,u4))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(QString,u4,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(QString,u4,u4))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u4,QString,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u4,QString,u4))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u4,u4,QString))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QString,QString,QString,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QString,QString,u4,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QString,QString,u4,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QString,u4,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QString,u4,QString,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QString,u4,u4,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QString,u4,u4,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,QString,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,QString,QString,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,QString,u4,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,QString,u4,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,u4,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,u4,QString,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,u4,u4,QString))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,QString,QString,QString,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,QString,QString,u4,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,QString,QString,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,QString,u4,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,QString,u4,QString,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,QString,u4,u4,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,QString,u4,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,u4,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,u4,QString,QString,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,u4,QString,u4,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,u4,QString,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,u4,u4,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,u4,u4,QString,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,u4,u4,u4,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QString,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,QString,QString,QString,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,QString,QString,u4,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,QString,QString,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,QString,u4,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,QString,u4,QString,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,QString,u4,u4,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,QString,u4,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,QString,QString,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,QString,u4,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,QString,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,u4,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,u4,QString,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,u4,u4,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,QString,QString,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,QString,QString,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,QString,QString,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,QString,u4,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,QString,u4,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,QString,u4,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,QString,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,QString,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,u4,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,u4,QString,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,u4,QString,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,u4,QString,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,u4,u4,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,u4,u4,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,u4,u4,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,QString,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,QString,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,QString,QString,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,QString,QString,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,QString,QString,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,QString,u4,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,QString,u4,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,QString,u4,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,QString,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,QString,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,u4,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,u4,QString,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,u4,QString,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,u4,QString,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,u4,u4,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,u4,u4,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,u4,u4,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {QString a1=*(QString*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QString,u4,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QString,u4,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,QString,QString,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,QString,QString,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,QString,QString,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,QString,u4,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,QString,u4,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,QString,u4,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,QString,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,QString,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,u4,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,u4,QString,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,u4,QString,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,u4,QString,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,u4,u4,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,u4,u4,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,u4,u4,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {u4 a1=*(u4*)args[0];QString a2=*(QString*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,QString,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,QString,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,QString,QString,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,QString,QString,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,QString,QString,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,QString,u4,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,QString,u4,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,QString,u4,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];QString a3=*(QString*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,QString,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,QString,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,QString,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,QString,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,QString,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,QString,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];QString a4=*(QString*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,QString,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,QString,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,u4,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,u4,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];QString a5=*(QString*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,u4,QString,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,u4,QString,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,u4,u4,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,u4,u4,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}