

void _f_X36_1_(u1 ac_pattern, u1& retv,  QVector<n8>& args, minimal_fn_s0_re1_type fn,
  minimal_fn_s1_re1_type sfn, void** _this) // # 26
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];
  auto _sfn = (u1(_min_::*)(QString,r8))(sfn);
  if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
  else retv=((u1(*)(QString,r8))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];
  auto _sfn = (u1(_min_::*)(r8,QString))(sfn);
  if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
  else retv=((u1(*)(r8,QString))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (u1(_min_::*)(QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,QString,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (u1(_min_::*)(QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,r8,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (u1(_min_::*)(QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QString,r8,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (u1(_min_::*)(r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(r8,QString,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (u1(_min_::*)(r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(r8,QString,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (u1(_min_::*)(r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(r8,r8,QString))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QString,QString,QString,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QString,QString,r8,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QString,QString,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QString,r8,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QString,r8,QString,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QString,r8,r8,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QString,r8,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(r8,QString,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(r8,QString,QString,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(r8,QString,r8,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(r8,QString,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(r8,r8,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(r8,r8,QString,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(r8,r8,r8,QString))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,QString,QString,QString,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,QString,QString,r8,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,QString,QString,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,QString,r8,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,QString,r8,QString,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,QString,r8,r8,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,QString,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,r8,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,r8,QString,QString,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,r8,QString,r8,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,r8,QString,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,r8,r8,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,r8,r8,QString,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,r8,r8,r8,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QString,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,QString,QString,QString,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,QString,QString,r8,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,QString,QString,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,QString,r8,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,QString,r8,QString,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,QString,r8,r8,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,QString,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,r8,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,r8,QString,QString,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,r8,QString,r8,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,r8,QString,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,r8,r8,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,r8,r8,QString,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(r8,r8,r8,r8,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,QString,QString,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,QString,QString,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,QString,QString,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,QString,r8,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,QString,r8,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,QString,r8,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,QString,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,QString,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,r8,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,r8,QString,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,r8,QString,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,r8,QString,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,r8,r8,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,r8,r8,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,r8,r8,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,QString,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,QString,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,QString,QString,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,QString,QString,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,QString,QString,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,QString,r8,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,QString,r8,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,QString,r8,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,QString,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,QString,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,r8,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,r8,QString,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,r8,QString,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,r8,QString,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,r8,r8,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,r8,r8,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,r8,r8,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {QString a1=*(QString*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(QString,r8,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QString,r8,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,QString,QString,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,QString,QString,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,QString,QString,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,QString,r8,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,QString,r8,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,QString,r8,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,QString,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,QString,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,r8,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,r8,QString,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,r8,QString,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,r8,QString,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,r8,r8,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,r8,r8,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,r8,r8,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {r8 a1=*(r8*)args[0];QString a2=*(QString*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,QString,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,QString,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,QString,QString,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,QString,QString,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,QString,QString,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,QString,r8,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,QString,r8,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,QString,r8,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QString a3=*(QString*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,QString,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,QString,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,r8,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,QString,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,r8,QString,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,QString,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,r8,QString,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QString a4=*(QString*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,QString,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,r8,QString,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,r8,QString,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,r8,r8,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QString a5=*(QString*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,r8,QString,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,r8,r8,QString,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (u1(_min_::*)(r8,r8,r8,r8,r8,QString))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(r8,r8,r8,r8,r8,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}