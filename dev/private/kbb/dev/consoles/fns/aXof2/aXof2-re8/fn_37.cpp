

void _f_X37_8_(u1 ac_pattern, n8& retv,  QVector<n8>& args, minimal_fn_s0_re8_type fn,
  minimal_fn_s1_re8_type sfn, void** _this) // # 27
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];
  auto _sfn = (n8(_min_::*)(QString,QVariant))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((n8(*)(QString,QVariant))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];
  auto _sfn = (n8(_min_::*)(QVariant,QString))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((n8(*)(QVariant,QString))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QString,QString,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QString,QVariant,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QString,QVariant,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,QString,QString))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,QString,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((n8(*)(QVariant,QVariant,QString))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QString,QString,QString,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QString,QString,QVariant,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QString,QString,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QString,QVariant,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QString,QVariant,QString,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QString,QVariant,QVariant,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QString,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QVariant,QString,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QVariant,QString,QString,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QVariant,QString,QVariant,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QVariant,QString,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QVariant,QVariant,QString,QString))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QVariant,QVariant,QString,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QString))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QString,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QString,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QString,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QString,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QString,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QString,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QString,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QVariant,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QVariant,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QVariant,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QVariant,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QVariant,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QVariant,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QVariant,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QString,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QString,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QString,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QString,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QString,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QString,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QString,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QString,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QVariant,QString,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QVariant,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QVariant,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QVariant,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QString,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QString,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QString,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QString,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QString,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QString,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QString,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QString,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QVariant,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QVariant,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QVariant,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QVariant,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QVariant,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QVariant,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QVariant,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {QString a1=*(QString*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QString,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QString,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QString,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QString,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QString,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QString,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QString,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QString,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QString,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QString,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QVariant,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QVariant,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QVariant,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QVariant,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QVariant,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QVariant,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QVariant,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {QString a1=*(QString*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QString,QVariant,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QString,QVariant,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QString,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QString,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QString,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QString,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QString,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QString,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QString,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QString,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QVariant,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QVariant,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QVariant,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QVariant,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QVariant,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QVariant,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QVariant,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {QVariant a1 = *(QVariant*)args[0];QString a2=*(QString*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QString,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QString,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QString,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QString,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QString,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QString,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QString,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QString,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QString,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QString a3=*(QString*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QString,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QString,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QString,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QString,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QString,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QString,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QString,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QString,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QString a4=*(QString*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QString,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QString,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QVariant,QString,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QVariant,QString,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QString a5=*(QString*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QVariant,QString,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QVariant,QString,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QString a6=*(QString*)args[5];
   auto _sfn = (n8(_min_::*)(QVariant,QVariant,QVariant,QVariant,QVariant,QString))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((n8(*)(QVariant,QVariant,QVariant,QVariant,QVariant,QString))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}