

void _f_X13_0_(u1 ac_pattern,  QVector<n8>& args, minimal_fn_s0_re0_type fn,
  minimal_fn_s1_re0_type sfn, void** _this) // # 10
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];
  auto _sfn = (void(_min_::*)(u1,QString))(sfn);
  if(_this) ((_min_*)_this->*_sfn)(a1,a2);
  else ((void(*)(u1,QString))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];
  auto _sfn = (void(_min_::*)(QString,u1))(sfn);
  if(_this) ((_min_*)_this->*_sfn)(a1,a2);
  else ((void(*)(QString,u1))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (void(_min_::*)(u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(u1,u1,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];
   auto _sfn = (void(_min_::*)(u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(u1,QString,u1))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (void(_min_::*)(u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(u1,QString,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];
   auto _sfn = (void(_min_::*)(QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(QString,u1,u1))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (void(_min_::*)(QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(QString,u1,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];
   auto _sfn = (void(_min_::*)(QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3);
   else ((void(*)(QString,QString,u1))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (void(_min_::*)(u1,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(u1,u1,u1,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void(_min_::*)(u1,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(u1,u1,QString,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (void(_min_::*)(u1,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(u1,u1,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void(_min_::*)(u1,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(u1,QString,u1,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (void(_min_::*)(u1,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(u1,QString,u1,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void(_min_::*)(u1,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(u1,QString,QString,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (void(_min_::*)(u1,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(u1,QString,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void(_min_::*)(QString,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QString,u1,u1,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (void(_min_::*)(QString,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QString,u1,u1,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void(_min_::*)(QString,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QString,u1,QString,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (void(_min_::*)(QString,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QString,u1,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void(_min_::*)(QString,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QString,QString,u1,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (void(_min_::*)(QString,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QString,QString,u1,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void(_min_::*)(QString,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else ((void(*)(QString,QString,QString,u1))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(u1,u1,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,u1,u1,u1,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(u1,u1,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,u1,u1,QString,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(u1,u1,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,u1,u1,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(u1,u1,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,u1,QString,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(u1,u1,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,u1,QString,u1,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(u1,u1,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,u1,QString,QString,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(u1,u1,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,u1,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(u1,QString,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,QString,u1,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(u1,QString,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,QString,u1,u1,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(u1,QString,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,QString,u1,QString,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(u1,QString,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,QString,u1,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(u1,QString,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,QString,QString,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(u1,QString,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,QString,QString,u1,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(u1,QString,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,QString,QString,QString,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(u1,QString,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(u1,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(QString,u1,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(QString,u1,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,u1,u1,u1,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(QString,u1,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,u1,u1,QString,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(QString,u1,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,u1,u1,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(QString,u1,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,u1,QString,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(QString,u1,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,u1,QString,u1,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(QString,u1,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,u1,QString,QString,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(QString,u1,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,u1,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(QString,QString,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,QString,u1,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(QString,QString,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,QString,u1,u1,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(QString,QString,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,QString,u1,QString,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(QString,QString,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,QString,u1,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(QString,QString,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,QString,QString,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (void(_min_::*)(QString,QString,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,QString,QString,u1,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void(_min_::*)(QString,QString,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else ((void(*)(QString,QString,QString,QString,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,u1,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,u1,u1,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,u1,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,u1,u1,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,u1,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,u1,u1,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,u1,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,u1,QString,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,u1,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,u1,QString,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,u1,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,u1,QString,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,u1,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,u1,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,QString,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,QString,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,QString,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,QString,u1,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,QString,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,QString,u1,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,QString,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,QString,u1,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,QString,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,QString,QString,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,QString,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,QString,QString,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,QString,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,QString,QString,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,u1,QString,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,u1,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,u1,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,u1,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,u1,u1,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,u1,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,u1,u1,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,u1,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,u1,u1,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,u1,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,u1,QString,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,u1,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,u1,QString,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,u1,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,u1,QString,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,u1,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,u1,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,QString,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,QString,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,QString,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,QString,u1,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,QString,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,QString,u1,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,QString,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,QString,u1,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,QString,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,QString,QString,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,QString,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,QString,QString,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,QString,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,QString,QString,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {u1 a1=*(u1*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(u1,QString,QString,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(u1,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,u1,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,u1,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,u1,u1,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,u1,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,u1,u1,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,u1,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,u1,u1,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,u1,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,u1,QString,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,u1,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,u1,QString,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,u1,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,u1,QString,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,u1,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,u1,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,QString,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,QString,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,QString,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,QString,u1,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,QString,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,QString,u1,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,QString,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,QString,u1,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,QString,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,QString,QString,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,QString,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,QString,QString,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,QString,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,QString,QString,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {QString a1=*(QString*)args[0];u1 a2=*(u1*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,u1,QString,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,u1,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,u1,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,u1,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,u1,u1,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,u1,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,u1,u1,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,u1,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,u1,u1,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,u1,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,u1,QString,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,u1,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,u1,QString,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,u1,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,u1,QString,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];u1 a3=*(u1*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,u1,QString,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,u1,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,QString,u1,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,QString,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,QString,u1,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,QString,u1,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,QString,u1,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,QString,u1,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];u1 a4=*(u1*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,QString,u1,QString,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,QString,u1,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,QString,QString,u1,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,QString,QString,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];u1 a5=*(u1*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,QString,QString,u1,QString))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,QString,QString,u1,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void(_min_::*)(QString,QString,QString,QString,QString,u1))(sfn);
   if(_this) ((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else ((void(*)(QString,QString,QString,QString,QString,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}