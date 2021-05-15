

void _f_X07_5_(u1 ac_pattern, QByteArray& retv,  QVector<n8>& args, minimal_fn_s0_re5_type fn,
  minimal_fn_s1_re5_type sfn, void** _this) // # 6
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];
  auto _sfn = (QByteArray(_min_::*)(n8&,QVariant))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((QByteArray(*)(n8&,QVariant))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];
  auto _sfn = (QByteArray(_min_::*)(QVariant,n8&))(sfn);
  if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2);
  else retv=((QByteArray(*)(QVariant,n8&))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(n8&,n8&,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(n8&,QVariant,n8&))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(QVariant,n8&,n8&))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8&,n8&,n8&,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,n8&,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,n8&,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,n8&,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,n8&,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,n8&,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,n8&,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,n8&,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,n8&,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,n8&,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,n8&,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,n8&,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {n8& a1=*(n8*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,n8&,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,n8&,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,n8&,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,n8&,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {n8& a1=*(n8*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(n8&,QVariant,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(n8&,QVariant,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,n8&,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,n8&,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {QVariant a1 = *(QVariant*)args[0];n8& a2=*(n8*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,n8&,QVariant,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,n8&,QVariant,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];n8& a3=*(n8*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,n8&,QVariant,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,n8&,QVariant,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,n8&,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,n8&,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,n8&,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,n8&,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,n8&,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,n8&,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];n8& a4=*(n8*)args[3];QVariant a5 = *(QVariant*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,n8&,QVariant,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,n8&,QVariant,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,QVariant,n8&,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,QVariant,n8&,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];n8& a5=*(n8*)args[4];QVariant a6 = *(QVariant*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,QVariant,n8&,QVariant))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,QVariant,n8&,QVariant))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {QVariant a1 = *(QVariant*)args[0];QVariant a2 = *(QVariant*)args[1];QVariant a3 = *(QVariant*)args[2];QVariant a4 = *(QVariant*)args[3];QVariant a5 = *(QVariant*)args[4];n8& a6=*(n8*)args[5];
   auto _sfn = (QByteArray(_min_::*)(QVariant,QVariant,QVariant,QVariant,QVariant,n8&))(sfn);
   if(_this) retv=((_min_*)*_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((QByteArray(*)(QVariant,QVariant,QVariant,QVariant,QVariant,n8&))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}