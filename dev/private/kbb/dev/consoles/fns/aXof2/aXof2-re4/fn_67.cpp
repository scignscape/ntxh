

void _f_X67_4_(u1 ac_pattern, u4& retv,  QVector<n8>& args, minimal_fn_s0_re4_type fn,
  minimal_fn_s1_re4_type sfn, void** _this) // # 39
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];
  auto _sfn = (u4(_min_::*)(r8,QVariant))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((u4(*)(r8,QVariant))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];
  auto _sfn = (u4(_min_::*)(QVariant,r8))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((u4(*)(QVariant,r8))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(r8,r8,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(r8,QVariant,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(r8,QVariant,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,r8,r8))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,r8,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u4(*)(QVariant,QVariant,r8))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(r8,r8,r8,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(r8,r8,QVariant,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(r8,r8,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(r8,QVariant,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(r8,QVariant,r8,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(r8,QVariant,QVariant,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(r8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QVariant,r8,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QVariant,r8,r8,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QVariant,r8,QVariant,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QVariant,r8,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QVariant,QVariant,r8,r8))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QVariant,QVariant,r8,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u4(*)(QVariant,QVariant,QVariant,r8))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,r8,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,r8,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,r8,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,r8,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,r8,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,r8,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,r8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,QVariant,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,QVariant,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,QVariant,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,QVariant,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,QVariant,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,QVariant,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,QVariant,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(r8,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,r8,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,r8,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,r8,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,r8,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,r8,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,r8,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,r8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,QVariant,r8,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,QVariant,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,QVariant,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,QVariant,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,QVariant,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,QVariant,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u4(*)(QVariant,QVariant,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,r8,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,r8,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,r8,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,r8,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,r8,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,r8,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,r8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,r8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,QVariant,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,QVariant,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,QVariant,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,QVariant,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,QVariant,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,QVariant,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,QVariant,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {r8 a1=*(r8*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,r8,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,r8,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,r8,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,r8,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,r8,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,r8,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,r8,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,r8,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,r8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,r8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,QVariant,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,QVariant,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,QVariant,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,QVariant,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,QVariant,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,QVariant,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,QVariant,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {r8 a1=*(r8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(r8,QVariant,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(r8,QVariant,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,r8,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,r8,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,r8,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,r8,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,r8,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,r8,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,r8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,r8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,QVariant,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,QVariant,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,QVariant,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,QVariant,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,QVariant,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,QVariant,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,QVariant,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {QVariant a1 = *(QVariant*)args[0];r8 a2=*(r8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,r8,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,r8,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,r8,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,r8,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,r8,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,r8,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,r8,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,r8,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,r8,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];r8 a3=*(r8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,r8,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,r8,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,r8,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,QVariant,r8,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,r8,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,QVariant,r8,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,r8,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,QVariant,r8,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];r8 a4=*(r8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,r8,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,QVariant,r8,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,QVariant,r8,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,QVariant,QVariant,r8,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];r8 a5=*(r8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,QVariant,r8,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,QVariant,QVariant,r8,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];r8 a6=*(r8*)args[5];
   auto _sfn = (u4(_min_::*)(QVariant,QVariant,QVariant,QVariant,QVariant,r8))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u4(*)(QVariant,QVariant,QVariant,QVariant,QVariant,r8))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}