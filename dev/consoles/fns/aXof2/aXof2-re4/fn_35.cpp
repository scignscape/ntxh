

void _f_X35_4_(u1 ac_pattern, u4& retv,  QVector<n8>& args, minimal_fn_s0_re4_type fn,
  minimal_fn_s1_re4_type sfn, void** _this) // # 25
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];
  auto _sfn = (u4(_min_::*)(QString,QByteArray))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((u4(*)(QString,QByteArray))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];
  auto _sfn = (u4(_min_::*)(QByteArray,QString))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((u4(*)(QByteArray,QString))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QString,QString,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QString,QByteArray,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QString,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,QString,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,QString,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QByteArray,QByteArray,QString))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QString,QString,QString,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QString,QString,QByteArray,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QString,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QString,QByteArray,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QString,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QByteArray,QString,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QByteArray,QString,QString,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QString,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QString,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QString,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QString,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QString,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QString,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QString,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QByteArray,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QByteArray,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QByteArray,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QByteArray,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QString,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QString,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QString,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QString,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QString,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QString,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QString,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QString,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QString,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QString,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QString,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QByteArray,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QByteArray,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QByteArray,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QByteArray,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QByteArray,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QByteArray,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QByteArray,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QString,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QString,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QString,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QString,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QString,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QString,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QString,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QString,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QString,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QString,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {QString a1=*(QString*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QString,QByteArray,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QString,QByteArray,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QString,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QString,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QString,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QString,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QString,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QString,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QString,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QString,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {QByteArray a1=*(QByteArray*)args[0];QString a2=*(QString*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QString,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QString,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QString a3=*(QString*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QString,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QString,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QString,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QString,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QString,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QString,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QString a4=*(QString*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QString,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QString,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QByteArray,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QString a5=*(QString*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QString,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QByteArray,QString,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u4(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QByteArray,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QByteArray,QByteArray,QByteArray,QByteArray,QByteArray,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}