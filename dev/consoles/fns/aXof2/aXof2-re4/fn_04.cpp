

void _f_X04_4_(u1 ac_pattern, u4& retv,  QVector<n8>& args, minimal_fn_s0_re4_type fn,
  minimal_fn_s1_re4_type sfn, void* _this) // # 3
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];
  auto _sfn = (u4(_min_::*)(n8&,u4))(sfn);
  if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
  else retv=((u4(*)(n8&,u4))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];
  auto _sfn = (u4(_min_::*)(u4,n8&))(sfn);
  if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
  else retv=((u4(*)(u4,n8&))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,n8&,u4))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,u4,n8&))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(n8&,u4,u4))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u4,n8&,n8&))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u4,n8&,u4))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(u4,u4,n8&))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(n8&,n8&,n8&,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(n8&,n8&,u4,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(n8&,n8&,u4,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(n8&,u4,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(n8&,u4,n8&,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(n8&,u4,u4,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(n8&,u4,u4,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(u4,n8&,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(u4,n8&,n8&,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(u4,n8&,u4,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(u4,n8&,u4,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(u4,u4,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(u4,u4,n8&,u4))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(u4,u4,u4,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,n8&,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,n8&,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,n8&,n8&,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,n8&,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,n8&,u4,n8&,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,n8&,u4,u4,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,n8&,u4,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,u4,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,u4,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,u4,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,u4,n8&,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,u4,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,u4,u4,n8&,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,u4,u4,u4,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(n8&,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,n8&,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,n8&,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,n8&,n8&,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,n8&,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,n8&,u4,n8&,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,n8&,u4,u4,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,n8&,u4,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,u4,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,u4,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,u4,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,u4,n8&,u4,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,u4,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,u4,u4,n8&,u4))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(u4,u4,u4,u4,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,n8&,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,n8&,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,n8&,n8&,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,n8&,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,n8&,u4,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,n8&,u4,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,n8&,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,n8&,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,u4,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,u4,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,u4,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,u4,n8&,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,u4,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,u4,u4,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,u4,u4,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,n8&,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,n8&,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,n8&,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,n8&,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,n8&,n8&,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,n8&,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,n8&,u4,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,n8&,u4,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,n8&,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,n8&,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,u4,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,u4,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,u4,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,u4,n8&,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,u4,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,u4,u4,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,u4,u4,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {n8& a1=*(n8*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(n8&,u4,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(n8&,u4,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,n8&,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,n8&,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,n8&,n8&,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,n8&,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,n8&,u4,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,n8&,u4,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,n8&,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,n8&,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,u4,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,u4,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,u4,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,u4,n8&,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,u4,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,u4,u4,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,u4,u4,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {u4 a1=*(u4*)args[0];n8& a2=*(n8*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,n8&,u4,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,n8&,u4,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,n8&,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,n8&,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,n8&,n8&,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,n8&,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,n8&,u4,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,n8&,u4,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];n8& a3=*(n8*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,n8&,u4,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,n8&,u4,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,u4,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,n8&,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,u4,n8&,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,n8&,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,u4,n8&,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];n8& a4=*(n8*)args[3];u4 a5=*(u4*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,n8&,u4,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,u4,n8&,u4,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,u4,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,u4,u4,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];n8& a5=*(n8*)args[4];u4 a6=*(u4*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,u4,n8&,u4))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,u4,u4,n8&,u4))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {u4 a1=*(u4*)args[0];u4 a2=*(u4*)args[1];u4 a3=*(u4*)args[2];u4 a4=*(u4*)args[3];u4 a5=*(u4*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (u4(_min_::*)(u4,u4,u4,u4,u4,n8&))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(u4,u4,u4,u4,u4,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}