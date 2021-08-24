

void _f_X78_1_(u1 ac_pattern, u1& retv,  QVector<n8>& args, minimal_fn_s0_re1_type fn,
  minimal_fn_s1_re1_type sfn, void** _this) // # 42
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];
  auto _sfn = (u1(_min_::*)(QVariant,n8))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((u1(*)(QVariant,n8))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];
  auto _sfn = (u1(_min_::*)(n8,QVariant))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((u1(*)(n8,QVariant))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,QVariant,n8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,n8,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,n8,n8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,QVariant,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,QVariant,n8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(n8,n8,QVariant))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,QVariant,QVariant,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,QVariant,n8,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,QVariant,n8,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,n8,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,n8,QVariant,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,n8,n8,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,n8,n8,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(n8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(n8,QVariant,QVariant,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(n8,QVariant,n8,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(n8,QVariant,n8,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(n8,n8,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(n8,n8,QVariant,n8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(n8,n8,n8,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,n8,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,n8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,n8,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,n8,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,n8,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,n8,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,n8,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,n8,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,QVariant,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,QVariant,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,QVariant,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,QVariant,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,QVariant,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,QVariant,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,QVariant,n8,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,n8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,n8,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,n8,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,n8,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,n8,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,n8,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(n8,n8,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,n8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,n8,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,n8,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,n8,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,n8,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,n8,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,n8,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,QVariant,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,QVariant,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,QVariant,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,QVariant,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,QVariant,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,QVariant,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,QVariant,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,QVariant,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,n8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,n8,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,n8,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,n8,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,n8,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,n8,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,n8,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {QVariant a1 = *(QVariant*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,n8,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,n8,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,QVariant,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,QVariant,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,QVariant,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,QVariant,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,QVariant,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,QVariant,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,QVariant,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,QVariant,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,n8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,n8,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,n8,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,n8,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,n8,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,n8,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,n8,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {n8 a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,QVariant,n8,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,QVariant,n8,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,QVariant,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,QVariant,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,QVariant,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,QVariant,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,QVariant,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,QVariant,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,QVariant,n8,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,QVariant,n8,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,n8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,QVariant,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,n8,QVariant,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,QVariant,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,n8,QVariant,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8 a5=*(n8*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,QVariant,n8,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,n8,QVariant,n8,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,n8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,n8,n8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8 a6=*(n8*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,n8,QVariant,n8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,n8,n8,QVariant,n8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {n8 a1=*(n8*)args[0];n8 a2=*(n8*)args[1];n8 a3=*(n8*)args[2];n8 a4=*(n8*)args[3];n8 a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(n8,n8,n8,n8,n8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(n8,n8,n8,n8,n8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}