

void _f_X12_5_(u1 ac_pattern, QByteArray& retv,  QVector<n8>& args, minimal_fn_s0_re5_type fn,
  minimal_fn_s1_re5_type sfn, void** _this) // # 9
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];
  auto _sfn = (QByteArray(_min_::*)(u1,u2))(sfn);
  if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
  else retv=((QByteArray(*)(u1,u2))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];
  auto _sfn = (QByteArray(_min_::*)(u2,u1))(sfn);
  if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
  else retv=((QByteArray(*)(u2,u1))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u1,u1,u2))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u1,u2,u1))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u1,u2,u2))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u2,u1,u1))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u2,u1,u2))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u2,u2,u1))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u1,u1,u1,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u1,u1,u2,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u1,u1,u2,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u1,u2,u1,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u1,u2,u1,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u1,u2,u2,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u1,u2,u2,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u2,u1,u1,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u2,u1,u1,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u2,u1,u2,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u2,u1,u2,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u2,u2,u1,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u2,u2,u1,u2))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u2,u2,u2,u1))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u1,u1,u1,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u1,u1,u2,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u1,u1,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u1,u2,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u1,u2,u1,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u1,u2,u2,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u1,u2,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u2,u1,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u2,u1,u1,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u2,u1,u2,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u2,u1,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u2,u2,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u2,u2,u1,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u2,u2,u2,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u1,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u1,u1,u1,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u1,u1,u2,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u1,u1,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u1,u2,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u1,u2,u1,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u1,u2,u2,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u1,u2,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u2,u1,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u2,u1,u1,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u2,u1,u2,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u2,u1,u2,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u2,u2,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u2,u2,u1,u2))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u2,u2,u2,u2,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u1,u1,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u1,u1,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u1,u1,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u1,u2,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u1,u2,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u1,u2,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u1,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u1,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u2,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u2,u1,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u2,u1,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u2,u1,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u2,u2,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u2,u2,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u2,u2,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u1,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u1,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u1,u1,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u1,u1,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u1,u1,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u1,u2,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u1,u2,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u1,u2,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u1,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u1,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u2,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u2,u1,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u2,u1,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u2,u1,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u2,u2,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u2,u2,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u2,u2,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {u1 a1=*(u1*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u1,u2,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u1,u2,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u1,u1,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u1,u1,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u1,u1,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u1,u2,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u1,u2,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u1,u2,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u1,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u1,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u2,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u2,u1,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u2,u1,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u2,u1,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u2,u2,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u2,u2,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u2,u2,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {u2 a1=*(u2*)args[0];u1 a2=*(u1*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u1,u2,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u1,u2,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u1,u1,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u1,u1,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u1,u1,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u1,u2,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u1,u2,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u1,u2,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u1 a3=*(u1*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u1,u2,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u1,u2,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u2,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u1,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u2,u1,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u1,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u2,u1,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u1 a4=*(u1*)args[3];u2 a5=*(u2*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u1,u2,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u2,u1,u2,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u2,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u2,u2,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u1 a5=*(u1*)args[4];u2 a6=*(u2*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u2,u1,u2))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u2,u2,u1,u2))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {u2 a1=*(u2*)args[0];u2 a2=*(u2*)args[1];u2 a3=*(u2*)args[2];u2 a4=*(u2*)args[3];u2 a5=*(u2*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u2,u2,u2,u2,u2,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u2,u2,u2,u2,u2,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}