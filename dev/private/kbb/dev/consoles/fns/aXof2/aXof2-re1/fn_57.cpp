

void _f_X57_1_(u1 ac_pattern, u1& retv,  QVector<n8>& args, minimal_fn_s0_re1_type fn,
  minimal_fn_s1_re1_type sfn, void** _this) // # 36
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];
  auto _sfn = (u1(_min_::*)(QByteArray,QVariant))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((u1(*)(QByteArray,QVariant))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];
  auto _sfn = (u1(_min_::*)(QVariant,QByteArray))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((u1(*)(QVariant,QByteArray))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QByteArray,QVariant,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,QByteArray,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((u1(*)(QVariant,QVariant,QByteArray))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QByteArray,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QByteArray,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QByteArray,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QByteArray,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QByteArray,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QByteArray,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {QByteArray a1=*(QByteArray*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QByteArray,QVariant,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QByteArray,QVariant,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QByteArray,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QByteArray,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {QVariant a1 = *(QVariant*)args[0];QByteArray a2=*(QByteArray*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QByteArray,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QByteArray,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QByteArray a3=*(QByteArray*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QByteArray,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QByteArray,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QByteArray,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QByteArray,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QByteArray,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QByteArray,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QByteArray a4=*(QByteArray*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QByteArray,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QByteArray,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QVariant,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QVariant,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QByteArray a5=*(QByteArray*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QVariant,QByteArray,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QVariant,QByteArray,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (u1(_min_::*)(QVariant,QVariant,QVariant,QVariant,QVariant,QByteArray))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((u1(*)(QVariant,QVariant,QVariant,QVariant,QVariant,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}