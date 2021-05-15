

void _f_X06_7_(u1 ac_pattern, QVariant& retv,  QVector<n8>& args, minimal_fn_s0_re7_type fn,
  minimal_fn_s1_re7_type sfn, void** _this) // # 5
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];
  auto _sfn = (QVariant(_min_::*)(n8&,r8))(sfn);
  if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
  else retv=((QVariant(*)(n8&,r8))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];
  auto _sfn = (QVariant(_min_::*)(r8,n8&))(sfn);
  if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
  else retv=((QVariant(*)(r8,n8&))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QVariant(*)(n8&,n8&,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QVariant(*)(n8&,r8,n8&))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QVariant(*)(n8&,r8,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QVariant(*)(r8,n8&,n8&))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QVariant(*)(r8,n8&,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QVariant(*)(r8,r8,n8&))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(n8&,n8&,n8&,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(n8&,n8&,r8,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(n8&,n8&,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(n8&,r8,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(n8&,r8,n8&,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(n8&,r8,r8,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(n8&,r8,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(r8,n8&,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(r8,n8&,n8&,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(r8,n8&,r8,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(r8,n8&,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(r8,r8,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(r8,r8,n8&,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QVariant(*)(r8,r8,r8,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,n8&,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,n8&,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,n8&,n8&,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,n8&,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,n8&,r8,n8&,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,n8&,r8,r8,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,n8&,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,r8,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,r8,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,r8,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,r8,n8&,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,r8,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,r8,r8,n8&,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,r8,r8,r8,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(n8&,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,n8&,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,n8&,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,n8&,n8&,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,n8&,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,n8&,r8,n8&,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,n8&,r8,r8,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,n8&,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,r8,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,r8,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,r8,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,r8,n8&,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,r8,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,r8,r8,n8&,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QVariant(*)(r8,r8,r8,r8,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,n8&,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,n8&,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,n8&,n8&,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,n8&,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,n8&,r8,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,n8&,r8,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,n8&,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,n8&,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,r8,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,r8,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,r8,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,r8,n8&,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,r8,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,r8,r8,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,r8,r8,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,n8&,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,n8&,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,n8&,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,n8&,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,n8&,n8&,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,n8&,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,n8&,r8,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,n8&,r8,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,n8&,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,n8&,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,r8,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,r8,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,r8,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,r8,n8&,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,r8,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,r8,r8,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,r8,r8,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {n8& a1=*(n8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(n8&,r8,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(n8&,r8,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,n8&,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,n8&,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,n8&,n8&,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,n8&,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,n8&,r8,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,n8&,r8,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,n8&,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,n8&,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,r8,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,r8,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,r8,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,r8,n8&,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,r8,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,r8,r8,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,r8,r8,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {r8 a1=*(r8*)args[0];n8& a2=*(n8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,n8&,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,n8&,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,n8&,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,n8&,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,n8&,n8&,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,n8&,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,n8&,r8,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,n8&,r8,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];n8& a3=*(n8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,n8&,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,n8&,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,r8,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,n8&,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,r8,n8&,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,n8&,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,r8,n8&,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];n8& a4=*(n8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,n8&,r8,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,r8,n8&,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,r8,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,r8,r8,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];n8& a5=*(n8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,r8,n8&,r8))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,r8,r8,n8&,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QVariant(_min_::*)(r8,r8,r8,r8,r8,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QVariant(*)(r8,r8,r8,r8,r8,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}