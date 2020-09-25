
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "subtract.h"

USING_KANS(Phaon)

PHR_KOP_Subtract::PHR_KOP_Subtract()
{

}

void PHR_KOP_Subtract::run_eval(QPair<qint32, qint32>& args, qint32& result)
{
 result = args.first - args.second;
}

void PHR_KOP_Subtract::run_eval(QVector<qint32>& args, qint32& result)
{
 int sz = args.size();
 switch(sz)
 {
 case 0:
  return;
 case 1:
  result = args[0];
 default:
  {
   for(int i = 1; i < sz; ++i)
   {
    QPair<qint32, qint32> pr{args[i - 1], args[i]};
    run_eval(pr, result);
   }
  }
 }
}
