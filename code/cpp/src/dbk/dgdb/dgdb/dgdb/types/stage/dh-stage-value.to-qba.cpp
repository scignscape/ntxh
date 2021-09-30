
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dh-stage-value.h"

template<DH_Stage_Code::Query_Typecode QTC>
void to_qba_(DH_Stage_Value& sv, QByteArray& result);

//x(N_A ,void*) \
//x(qstr ,QString) \
//x(qvar ,QVariant) \
//x(WG_INTTYPE ,int) \
//x(WG_DOUBLETYPE ,double) \
//x(WG_STRTYPE ,std::string) \
//x(WG_XMLLITERALTYPE ,QDomEntity) \
//x(WG_URITYPE ,QUrl) \
//x(WG_BLOBTYPE ,QByteArray) \
//x(WG_CHARTYPE ,char) \
//x(WG_FIXPOINTTYPE ,float) \
//x(WG_DATETYPE ,QDate) \
//x(WG_TIMETYPE ,QDateTime) \
//x(Generic ,n8) \

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_N_A>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_qstr>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_WG_INTTYPE>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_WG_DOUBLETYPE>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_WG_STRTYPE>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_WG_XMLLITERALTYPE>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_WG_URITYPE>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_WG_BLOBTYPE>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_WG_CHARTYPE>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_WG_FIXPOINTTYPE>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_WG_DATETYPE>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_WG_TIMETYPE>(DH_Stage_Value& sv, QByteArray& result)
{

}

template<>
void to_qba_<DH_Stage_Code::Query_Typecode::qtc_Generic>(DH_Stage_Value& sv, QByteArray& result)
{

}

void DH_Stage_Value::to_qba(QByteArray& result)
{
 DH_Stage_Code::Query_Typecode qtc = info_.get_qtc_code();

 switch (qtc)
 {

  #define TEMP_MACRO(x ,y) \
  case DH_Stage_Code::Query_Typecode::qtc_##x: \
    to_qba_<DH_Stage_Code::Query_Typecode::qtc_##x>(*this, result);
  _TYPECODE_QUERY_MACROS(TEMP_MACRO)
  #undef TEMP_MACRO

 }
}


