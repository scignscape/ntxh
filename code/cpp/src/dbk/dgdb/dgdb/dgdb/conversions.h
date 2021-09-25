
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CONVERSIONS__H
#define CONVERSIONS__H


#include <QBuffer>
#include <QVariant>

#include <QtEndian>


#include <functional>

#include "global-types.h"

#include "accessors.h"

inline QByteArray u1_to_qba(u1 u)
{
 return QByteArray(1, u);
}

inline QByteArray s1_to_qba(s1 s)
{
 return QByteArray(1, s);
}



inline u1 qba_to_u1(const QByteArray& qba)
{
 if(qba.isEmpty())
   return 0;
 return (u1) qba.at(0);
}

inline s1 qba_to_s1(const QByteArray& qba)
{
 if(qba.isEmpty())
   return 0;
 return (s1) qba.at(1);
}




template<typename VALUE_Type>
void _to_qba(VALUE_Type v, QByteArray& result)
{
 QBuffer buffer(&result);
 buffer.open(QIODevice::WriteOnly);
 v = qToBigEndian(v);
 buffer.write((char*) &v, sizeof(VALUE_Type));
}

inline QByteArray u2_to_qba(u2 unsigned_value)
{
 QByteArray result;
 _to_qba<u2>(unsigned_value, result);
 return result;
}

inline QByteArray s2_to_qba(s2 signed_value)
{
 QByteArray result;
 _to_qba<s2>(signed_value, result);
 return result;
}


inline QByteArray u4_to_qba(u4 unsigned_value)
{
 QByteArray result;
 _to_qba<u4>(unsigned_value, result);
 return result;
}

inline QByteArray s4_to_qba(s4 signed_value)
{
 QByteArray result;
 _to_qba<s4>(signed_value, result);
 return result;
}



inline QByteArray n8_to_qba(n8 value)
{
 QByteArray result;
 _to_qba<n8>(value, result);
 return result;
}




template<typename VALUE_Type>
void qba_to_(const QByteArray& data, VALUE_Type& result)
{
 QBuffer buffer;
 buffer.setData(data);//&result);
 buffer.open(QIODevice::ReadOnly);
 buffer.read((char*) &result, sizeof(VALUE_Type));
}

inline u2 qba_to_u2(const QByteArray& qba)
{
 u2 result;
 qba_to_<u2>(qba, result);
 return qFromBigEndian(result);
}

inline s2 qba_to_s2(const QByteArray& qba)
{
 s2 result;
 qba_to_<s2>(qba, result);
 return qFromBigEndian(result);
}

inline u4 qba_to_u4(const QByteArray& qba)
{
 u4 result;
 qba_to_<u4>(qba, result);
 return qFromBigEndian(result);
}

inline s4 qba_to_s4(const QByteArray& qba)
{
 s4 result;
 qba_to_<s4>(qba, result);
 return qFromBigEndian(result);
}


inline n8 qba_to_n8(const QByteArray& qba)
{
 n8 result;
 qba_to_<n8>(qba, result);
 return qFromBigEndian(result);
}




#endif // CONVERSIONS__H


