

void _f_X56_0_(u1 ac_pattern,  QVector<n8>& args, minimal_fn_s0_re0_type fn,
  minimal_fn_s1_re0_type sfn, void** _this) // # 35
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];
  auto _sfn = (void(_min_::*)(QByteArray,r8))(sfn);
  if(_this) ((_min_*)*_this->*_sfn)(a1,a2);
  else ((void(*)(QByteArray,r8))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];
  auto _sfn = (void(_min_::*)(r8,QByteArray))(sfn);
  if(_this) ((_min_*)*_this->*_sfn)(a1,a2);
  else ((void(*)(r8,QByteArray))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3);
   else ((void(*)(QByteArray,QByteArray,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3);
   else ((void(*)(QByteArray,r8,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3);
   else ((void(*)(QByteArray,r8,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3);
   else ((void(*)(r8,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3);
   else ((void(*)(r8,QByteArray,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3);
   else ((void(*)(r8,r8,QByteArray))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,QByteArray,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,r8,QByteArray,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,r8,r8,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,r8,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(r8,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(r8,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(r8,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(r8,QByteArray,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(r8,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(r8,r8,QByteArray,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(r8,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(r8,r8,r8,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,r8,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,r8,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,r8,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,r8,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,r8,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,r8,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,r8,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,QByteArray,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,QByteArray,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,QByteArray,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,QByteArray,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,QByteArray,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,QByteArray,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,QByteArray,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,r8,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,r8,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,r8,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,r8,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(r8,r8,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,r8,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (void(_min_::*)(r8,r8,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,r8,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(r8,r8,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(r8,r8,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,r8,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,r8,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,r8,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,r8,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,r8,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,r8,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,r8,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,r8,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,QByteArray,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,QByteArray,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,QByteArray,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,QByteArray,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,QByteArray,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,QByteArray,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,QByteArray,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,QByteArray,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,r8,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,r8,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,r8,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,r8,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,r8,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,r8,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,r8,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {QByteArray a1=*(QByteArray*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,r8,r8,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,r8,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,QByteArray,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,QByteArray,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,QByteArray,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,QByteArray,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,QByteArray,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,QByteArray,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,QByteArray,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,QByteArray,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,r8,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,r8,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,r8,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,r8,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,r8,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,r8,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,r8,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {r8 a1=*(r8*)args[0];QByteArray a2=*(QByteArray*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,QByteArray,r8,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,QByteArray,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,QByteArray,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,QByteArray,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,QByteArray,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,QByteArray,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,QByteArray,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,QByteArray,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QByteArray a3=*(QByteArray*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,QByteArray,r8,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,QByteArray,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,r8,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,r8,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,r8,QByteArray,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,r8,QByteArray,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,r8,QByteArray,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,r8,QByteArray,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QByteArray a4=*(QByteArray*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,r8,QByteArray,r8,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,r8,QByteArray,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,r8,r8,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,r8,r8,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QByteArray a5=*(QByteArray*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,r8,r8,QByteArray,r8))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,r8,r8,QByteArray,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(r8,r8,r8,r8,r8,QByteArray))(sfn);
   if(_this) ((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(r8,r8,r8,r8,r8,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}