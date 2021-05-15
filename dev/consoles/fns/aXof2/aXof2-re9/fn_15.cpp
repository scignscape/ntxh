

void _f_X15_9_(u1 ac_pattern, void*& retv,  QVector<n8>& args, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, void* _this) // # 12
{
 switch(ac_pattern)
 {

 case 0: // 2 args, lower-number pretype first
 {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];
  auto _sfn = (void*(_min_::*)(u1,QByteArray))(sfn);
  if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
  else retv=((void*(*)(u1,QByteArray))fn)(a1,a2);
 } break;

 case 255: // 2 args, higher-number pretype first
 {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];
  auto _sfn = (void*(_min_::*)(QByteArray,u1))(sfn);
  if(_this) retv=((_min_*)_this->*_sfn)(a1,a2);
  else retv=((void*(*)(QByteArray,u1))fn)(a1,a2);
 } break;

  case 0 + 0b001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,u1,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b010:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,QByteArray,u1))fn)(a1,a2,a3);
  } break;

  case 0 + 0b011:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(u1,QByteArray,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b100:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QByteArray,u1,u1))fn)(a1,a2,a3);
  } break;

  case 0 + 0b101:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QByteArray,u1,QByteArray))fn)(a1,a2,a3);
  } break;

  case 0 + 0b110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3);
   else retv=((void*(*)(QByteArray,QByteArray,u1))fn)(a1,a2,a3);
  } break;

  case 64 + 0b0001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(u1,u1,u1,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(u1,u1,QByteArray,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(u1,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0100:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(u1,QByteArray,u1,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0101:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(u1,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0110:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(u1,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b0111:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(u1,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1000:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(QByteArray,u1,u1,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1001:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(QByteArray,u1,u1,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1010:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(QByteArray,u1,QByteArray,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1011:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(QByteArray,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(QByteArray,QByteArray,u1,u1))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(QByteArray,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4);
  } break;

  case 64 + 0b1110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4);
  } break;

  case 128 + 0b00001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,u1,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,u1,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,u1,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00100:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,u1,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00101:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,u1,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00110:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,u1,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b00111:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,u1,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01000:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,QByteArray,u1,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01001:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,QByteArray,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01010:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,QByteArray,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01011:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,QByteArray,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01100:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,QByteArray,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01101:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,QByteArray,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01110:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,QByteArray,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b01111:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(u1,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10000:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10001:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,u1,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10010:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,u1,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10011:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,u1,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10100:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,u1,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10101:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,u1,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10110:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,u1,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b10111:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,u1,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,QByteArray,u1,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,QByteArray,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,QByteArray,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,QByteArray,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5);
  } break;

  case 128 + 0b11110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5);
  } break;

  case 192 + 0b000001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,u1,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,u1,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,u1,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000100:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,u1,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000101:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,u1,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000110:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,u1,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b000111:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,u1,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,u1,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001000:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,QByteArray,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001001:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,QByteArray,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001010:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,QByteArray,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001011:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,QByteArray,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001100:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,QByteArray,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001101:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,QByteArray,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001110:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,QByteArray,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b001111:
  {u1 a1=*(u1*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,u1,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,u1,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010000:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010001:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,u1,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010010:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,u1,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010011:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,u1,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010100:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,u1,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010101:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,u1,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010110:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,u1,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b010111:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,u1,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,u1,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011000:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,QByteArray,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011001:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,QByteArray,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011010:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,QByteArray,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011011:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,QByteArray,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011100:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,QByteArray,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011101:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,QByteArray,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011110:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,QByteArray,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b011111:
  {u1 a1=*(u1*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(u1,QByteArray,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(u1,QByteArray,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100000:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100001:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,u1,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100010:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,u1,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100011:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,u1,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100100:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,u1,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100101:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,u1,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100110:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,u1,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b100111:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,u1,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,u1,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101000:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,QByteArray,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101001:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,QByteArray,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101010:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,QByteArray,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101011:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,QByteArray,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101100:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,QByteArray,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101101:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,QByteArray,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101110:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,QByteArray,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b101111:
  {QByteArray a1=*(QByteArray*)args[0];u1 a2=*(u1*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,u1,QByteArray,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,u1,QByteArray,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,u1,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,u1,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,u1,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,u1,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,u1,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,u1,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,u1,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b110111:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];u1 a3=*(u1*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,u1,QByteArray,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,u1,QByteArray,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111000:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,u1,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,u1,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111001:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,u1,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,u1,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111010:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,u1,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,u1,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111011:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];u1 a4=*(u1*)args[3];QByteArray a5=*(QByteArray*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,u1,QByteArray,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,u1,QByteArray,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111100:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,u1,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,QByteArray,u1,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111101:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];u1 a5=*(u1*)args[4];QByteArray a6=*(QByteArray*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,u1,QByteArray))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,QByteArray,u1,QByteArray))fn)(a1,a2,a3,a4,a5,a6);
  } break;

  case 192 + 0b111110:
  {QByteArray a1=*(QByteArray*)args[0];QByteArray a2=*(QByteArray*)args[1];QByteArray a3=*(QByteArray*)args[2];QByteArray a4=*(QByteArray*)args[3];QByteArray a5=*(QByteArray*)args[4];u1 a6=*(u1*)args[5];
   auto _sfn = (void*(_min_::*)(QByteArray,QByteArray,QByteArray,QByteArray,QByteArray,u1))(sfn);
   if(_this) retv=((_min_*)_this->*_sfn)(a1,a2,a3,a4,a5,a6);
   else retv=((void*(*)(QByteArray,QByteArray,QByteArray,QByteArray,QByteArray,u1))fn)(a1,a2,a3,a4,a5,a6);
  } break;

 }
}