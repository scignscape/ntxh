
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "less-than.h"

USING_KANS(Phaon)


PHR_KOP_Less_Than::PHR_KOP_Less_Than()
{

}

void PHR_KOP_Less_Than::run_eval(QPair<qint32, qint32>& args, qint32& result)
{
 if(args.first < args.second)
   result = args.second - args.first;
 else
   result = 0;
}

void PHR_KOP_Less_Than::run_eval(QVector<qint32>& args, qint32& result)
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
