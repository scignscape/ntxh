

void _f_X05_0_(u1 ac_pattern,  QVector<n8>& args, minimal_fn_s0_re0_type fn,
  minimal_fn_s1_re0_type sfn, void** _this) // # 4
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];
  auto _sfn = (void(_min_::*)(n8&,QByteArray))(sfn);
  if(_this) ((_min_*)_this->*_sfn)(a1,a2);
  else ((void(*)(n8&,QByteArray))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];
  auto _sfn = (void(_min_::*)(QByteArray,n8&))(sfn);
  if(_this) ((_min_*)_this->*_sfn)(a1,a2);
  else ((void(*)(QByteArray,n8&))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(n8&,n8&,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(n8&,QByteArray,n8&))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(n8&,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(QByteArray,n8&,n8&))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(QByteArray,n8&,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(QByteArray,QByteArray,n8&))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(n8&,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(n8&,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(n8&,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(n8&,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(n8&,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(n8&,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(n8&,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,n8&,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QByteArray,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,n8&,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,n8&,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,n8&,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,n8&,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,n8&,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,n8&,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,n8&,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,QByteArray,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,QByteArray,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,QByteArray,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,QByteArray,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,QByteArray,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,QByteArray,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,QByteArray,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(n8&,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,n8&,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,n8&,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,n8&,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,n8&,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,n8&,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,n8&,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,n8&,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QByteArray,QByteArray,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,n8&,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,n8&,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,n8&,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,n8&,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,n8&,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,n8&,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,n8&,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,n8&,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,QByteArray,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,QByteArray,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,QByteArray,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,QByteArray,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,QByteArray,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,QByteArray,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,QByteArray,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,n8&,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,n8&,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,n8&,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,n8&,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,n8&,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,n8&,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,n8&,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,n8&,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,n8&,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,n8&,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,QByteArray,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,QByteArray,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,QByteArray,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,QByteArray,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,QByteArray,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,QByteArray,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,QByteArray,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {n8& a1=*(n8*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(n8&,QByteArray,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(n8&,QByteArray,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,n8&,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,n8&,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,n8&,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,n8&,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,n8&,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,n8&,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,n8&,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,n8&,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,QByteArray,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,QByteArray,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,QByteArray,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,QByteArray,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,QByteArray,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,QByteArray,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,QByteArray,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {QByteArray a1=*(QByteArray*)args[0];n8& a2=*(n8*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,n8&,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,n8&,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,n8&,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,n8&,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,n8&,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,n8&,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,n8&,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,n8&,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];n8& a3=*(n8*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,n8&,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,n8&,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,n8&,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,n8&,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,n8&,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,n8&,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,n8&,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];n8& a4=*(n8*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,n8&,QByteArray,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,n8&,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,n8&,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,QByteArray,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];n8& a5=*(n8*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,n8&,QByteArray))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,QByteArray,n8&,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (void(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QByteArray,n8&))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QByteArray,QByteArray,QByteArray,QByteArray,QByteArray,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}