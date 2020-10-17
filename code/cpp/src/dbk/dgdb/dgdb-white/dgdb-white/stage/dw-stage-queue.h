
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DW_STAGE_QUEUE__H
#define DW_STAGE_QUEUE__H

#include <QVector>
#include <QQueue>

#include <QDateTime>
#include <QDate>

#include <functional>

#include "accessors.h"

#include "global-types.h"

#include "kans.h"

KANS_(DGDB)


//class DgDb_Node;

struct DW_Stage_Queue  
{
 QQueue<void*> values;
 std::function<void(QQueue<void*>&)> callback;
 DW_Stage_Queue();// : callback(nullptr) {}
 void operator=(std::initializer_list<void*> vs) 
 { 
  values.append(QList<void*>(vs)); 
 }
 void operator<<(std::function<void(QQueue<void*>&)> cb)
   { callback = cb; }
};

template<typename T>
std::function<void(QQueue<void*>&)> stage_queue_memfnptr(void (T::*fn)(QQueue<void*>&))
{
 return [fn](QQueue<void*>& qq)
 {
  (((T*) qq.dequeue())->*fn)(qq);
 };
}




_KANS(DGDB)

#endif // DW_STAGE_QUEUE__H


