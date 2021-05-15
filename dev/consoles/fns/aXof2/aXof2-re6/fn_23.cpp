

void _f_X23_6_(u1 ac_pattern, r8& retv,  QVector<n8>& args, minimal_fn_s0_re6_type fn,
  minimal_fn_s1_re6_type sfn, void** _this) // # 17
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];
  auto _sfn = (r8(_min_::*)(u2,QString))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((r8(*)(u2,QString))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];
  auto _sfn = (r8(_min_::*)(QString,u2))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((r8(*)(QString,u2))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (r8(_min_::*)(u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,u2,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];
   auto _sfn = (r8(_min_::*)(u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,QString,u2))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (r8(_min_::*)(u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(u2,QString,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];
   auto _sfn = (r8(_min_::*)(QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QString,u2,u2))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (r8(_min_::*)(QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QString,u2,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];
   auto _sfn = (r8(_min_::*)(QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((r8(*)(QString,QString,u2))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(u2,u2,u2,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(u2,u2,QString,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(u2,u2,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(u2,QString,u2,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(u2,QString,u2,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(u2,QString,QString,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(u2,QString,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(QString,u2,u2,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(QString,u2,u2,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(QString,u2,QString,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(QString,u2,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(QString,QString,u2,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(QString,QString,u2,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((r8(*)(QString,QString,QString,u2))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,u2,u2,u2,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,u2,u2,QString,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,u2,u2,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,u2,QString,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,u2,QString,u2,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,u2,QString,QString,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,u2,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,QString,u2,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,QString,u2,u2,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,QString,u2,QString,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,QString,u2,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,QString,QString,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,QString,QString,u2,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,QString,QString,QString,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(u2,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,u2,u2,u2,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,u2,u2,QString,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,u2,u2,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,u2,QString,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,u2,QString,u2,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,u2,QString,QString,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,u2,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,QString,u2,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,QString,u2,u2,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,QString,u2,QString,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,QString,u2,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,QString,QString,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,QString,QString,u2,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((r8(*)(QString,QString,QString,QString,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,u2,u2,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,u2,u2,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,u2,u2,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,u2,QString,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,u2,QString,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,u2,QString,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,u2,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,u2,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,QString,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,QString,u2,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,QString,u2,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,QString,u2,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,QString,QString,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,QString,QString,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,QString,QString,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,u2,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,u2,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,u2,u2,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,u2,u2,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,u2,u2,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,u2,QString,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,u2,QString,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,u2,QString,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,u2,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,u2,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,QString,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,QString,u2,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,QString,u2,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,QString,u2,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,QString,QString,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,QString,QString,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,QString,QString,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {u2 a1=*(u2*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(u2,QString,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(u2,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,u2,u2,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,u2,u2,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,u2,u2,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,u2,QString,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,u2,QString,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,u2,QString,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,u2,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,u2,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,QString,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,QString,u2,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,QString,u2,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,QString,u2,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,QString,QString,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,QString,QString,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,QString,QString,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {QString a1=*(QString*)args[0];u2 a2=*(u2*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,u2,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,u2,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,u2,u2,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,u2,u2,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,u2,u2,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,u2,QString,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,u2,QString,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,u2,QString,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u2 a3=*(u2*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,u2,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,u2,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,QString,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,u2,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,QString,u2,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,u2,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,QString,u2,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u2 a4=*(u2*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,u2,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,QString,u2,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,QString,u2,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,QString,QString,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u2 a5=*(u2*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,QString,u2,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,QString,QString,u2,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (r8(_min_::*)(QString,QString,QString,QString,QString,u2))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((r8(*)(QString,QString,QString,QString,QString,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}