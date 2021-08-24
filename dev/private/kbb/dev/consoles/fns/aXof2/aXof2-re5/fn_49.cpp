

void _f_X49_5_(u1 ac_pattern, QByteArray& retv,  QVector<n8>& args, minimal_fn_s0_re5_type fn,
  minimal_fn_s1_re5_type sfn, void** _this) // # 34
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];
  auto _sfn = (QByteArray(_min_::*)(u4,n8))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((QByteArray(*)(u4,n8))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];
  auto _sfn = (QByteArray(_min_::*)(n8,u4))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((QByteArray(*)(n8,u4))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u4,u4,n8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u4,n8,u4))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(u4,n8,n8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(n8,u4,u4))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(n8,u4,n8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(n8,n8,u4))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,u4,u4,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,u4,n8,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,u4,n8,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,n8,u4,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,n8,u4,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,n8,n8,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(u4,n8,n8,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8,u4,u4,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8,u4,u4,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8,u4,n8,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8,u4,n8,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8,n8,u4,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8,n8,u4,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8,n8,n8,u4))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,u4,u4,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,u4,n8,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,u4,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,n8,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,n8,u4,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,n8,n8,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,u4,n8,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,n8,u4,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,n8,u4,u4,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,n8,u4,n8,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,n8,u4,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,n8,n8,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,n8,n8,u4,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,n8,n8,n8,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(u4,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,u4,u4,u4,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,u4,u4,n8,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,u4,u4,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,u4,n8,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,u4,n8,u4,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,u4,n8,n8,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,u4,n8,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,n8,u4,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,n8,u4,u4,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,n8,u4,n8,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,n8,u4,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,n8,n8,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,n8,n8,u4,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8,n8,n8,n8,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,u4,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,u4,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,u4,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,n8,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,n8,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,n8,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,u4,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,u4,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,n8,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,n8,u4,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,n8,u4,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,n8,u4,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,n8,n8,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,n8,n8,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,n8,n8,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,u4,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,u4,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,u4,u4,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,u4,u4,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,u4,u4,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,u4,n8,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,u4,n8,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,u4,n8,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,u4,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,u4,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,n8,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,n8,u4,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,n8,u4,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,n8,u4,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,n8,n8,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,n8,n8,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,n8,n8,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {u4 a1=*(u4*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(u4,n8,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(u4,n8,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,u4,u4,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,u4,u4,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,u4,u4,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,u4,n8,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,u4,n8,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,u4,n8,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,u4,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,u4,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,n8,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,n8,u4,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,n8,u4,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,n8,u4,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,n8,n8,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,n8,n8,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,n8,n8,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {n8 a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,u4,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,u4,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,u4,u4,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,u4,u4,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,u4,u4,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,u4,n8,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,u4,n8,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,u4,n8,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,u4,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,u4,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,n8,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,u4,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,n8,u4,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,u4,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,n8,u4,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,u4,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,n8,u4,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,n8,u4,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,n8,n8,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,n8,u4,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,n8,n8,u4,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8,n8,n8,n8,n8,u4))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8,n8,n8,n8,n8,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}