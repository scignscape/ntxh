
//          Copyright Nathaniel Christen 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "xcsd-1d/vec1d.h"
#include "xcsd-1d/stk1d.h"
#include "xcsd-1d/que1d.h"
#include "xcsd-1d/deq1d.h"
#include "xcsd-1d/dsk1d.h"
#include "xcsd-1d/arr1d.h"

#include "xcsd-1d/hive-structure.h"


#include <QDebug>

#include <QVector>

USING_XCNS(XCSD)

int main1(int argc , char **argv)
{
 Vec1d<int> vec(6, 3);

 QVector<int> test {2, 3, 4, 5, 6, 7};

 vec.resize(11);

 vec.each <<= [](int& i, s2 ix)
 {
  i = ix - 1;
  return-1;
 };
 qDebug() << vec.to_qstring(QString_number(int));

 QVector<QPair<int*, s2>> breakdown;
 if(int* it = vec.contiguous(4, 9, breakdown))
 {
  std::copy(test.begin(), test.end(), it);
 }
 else
 {
  auto it1 = test.begin();
  for(QPair<int*, s2> pr : breakdown)
  {
   std::copy(it1, it1 + pr.second, pr.first);
   it1 += pr.second;
  }
 }

 qDebug() << vec.to_qstring(QString_number(int));

 return 0;
}

int main(int argc , char **argv)
{
 Vec1d<int> vec(10, 7);

 QVector<int> test {2, 3, 4, 5, 6, 7};

 vec.resize(30);

 vec.each <<= [](int& i, s2 ix)
 {
  i = ix - 1;
  return-1;
 };
 qDebug() << vec.to_qstring(QString_number(int));

 if(int* it = vec.contiguous(4, 9))
 {
  std::copy(test.begin(), test.end(), it);
 }
 qDebug() << vec.to_qstring(QString_number(int));

 QVector<QPair<int*, s2>> breakdown;
 if(int* it = vec.contiguous(18, 23, breakdown))
 {
  std::copy(test.begin(), test.end(), it);
 }
 else
 {
  auto it1 = test.begin();
  for(QPair<int*, s2> pr : breakdown)
  {
   std::copy(it1, it1 + pr.second, pr.first);
   it1 += pr.second;
  }
 }

 qDebug() << vec.to_qstring(QString_number(int));
}

void test1()
{
 //Hive_Structure<hive_galaxy<int>> hs(16, 16);

 Hive_Structure_s2 hs(16, 16);
 hs.set_value_size(4);

 int& x = *(int*) hs.get_indexed_location_unchecked(8);

 x = 55;

 int y = *(int*) hs.get_location(8);

 qDebug() << "y = " << y;
}


void test2()
{
 Que1d<int> q1d;

 q1d.set_default <= defzfn(int);

 qDebug() << q1d.head();
 qDebug() << q1d.tail();


}

void test3()
{
 Deq1d<int> d1d;

 d1d.push_back(7);
 d1d.push_back(9);

 d1d._each([](int& i)
 {
  qDebug() << i;
 });

 d1d.pop_front();

 d1d._each([](int& i)
 {
  qDebug() << i;
 });



 qDebug() << "ok";

}

void test4()
{
 Que1d<int> q1d;

 q1d.enqueue(7);
 q1d.enqueue(9);
 q1d.enqueue(17);

 q1d._each([](int& i)
 {
  qDebug() << i;
 });

 q1d.dequeue();

 q1d._each([](int& i)
 {
  qDebug() << i;
 });

 qDebug() << "ok";

}


void test5()
{
 Stk1d<int> s1d(5);

 s1d.push(7);
 s1d.push(9);
 s1d.push(27);
 s1d.push(37);
 s1d.push(39);
 s1d.push(47);
 s1d.push(9);
 s1d.push(27);
 s1d.push(37);
 s1d.push(39);
 s1d.push(47);

 s1d._each([](int& i)
 {
  qDebug() << i;
 });

 qDebug() << "...";

 for(int i  = 0; i < 6; ++i)
  s1d.pop();

 s1d._each([](int& i)
 {
  qDebug() << i;
 });

 qDebug() << "ok";

}

void test6()
{
 Dsk1d<int> d1d;

 d1d.push_back(7);
 d1d.push_back(9);

 d1d.push_front(17);
 d1d.push_front(23);
 d1d.push_front(45);

 d1d.reach <<= [](int& i, s2 ix)
 {
  qDebug() << ix << ": " << i;
  return-1;
 };

 qDebug() << "ok";


}


void test7()
{
 Deq1d<int> d1d;

 d1d.push_back(7);
 d1d.push_back(9);

 d1d.pop_front();
 d1d.push_front(17);

 d1d.reach <<= [](int& i, s2 ix)
 {
  qDebug() << ix << ": " << i;
  return-1;
 };

 qDebug() << "ok";


}

void test8()
{
 Que1d<int> q1d;

 q1d.enqueue(7);
 q1d.enqueue(9);
 q1d.enqueue(17);

 q1d.each <<= [](int& i, s2 ix)
 {
  qDebug() << i;
  return-1;
 };

 qDebug() << "ok";

 qDebug() << q1d.head();
 qDebug() << q1d.tail();


}

void test9()
{
 Stk1d<int> s1d;
 s1d.set_default <= defzfn(int);

 s1d.push(7);
 s1d.push(9);
 s1d.push(17);

 s1d.each <<= [](int& i, s2 ix)
 {
  qDebug() << i;
  return-1;
 };

 qDebug() << s1d.top();
 qDebug() << s1d.bottom();

 qDebug() << "ok";

}


void test10()
{
 Arr1d<int> a1d(4);

 a1d.set_default <= defzfn(int);

 qDebug() << a1d.first();


 a1d.push_back(7);
 a1d.push_back(9);
 a1d.push_back(17);
 a1d.push_back(27);
 a1d.push_back(29);
 a1d.push_back(37);

 a1d.each <= [](int& i, s2 index)
 {
  qDebug() << index;
  qDebug() << i;
 };

 a1d.reach <<= [](int& i, s2 index)
 {
  if(index == 3)
    return-0;
  qDebug() << i;
  return-1;
 };

 qDebug() << "ok";

 qDebug() << a1d.last();
 qDebug() << a1d.first();
}

void test11()
{
 Vec1d<u1> vec(5, 5);
  // vec.default_to(0);
 vec.set_default_fn(defzfn(u1));
 vec.at_index(67) = 111;
 u1 x11 = vec.get_element(67);
 qDebug() << "x11 = " << x11;

 Vec1d<u1>::pre_iterator pre = vec.parse_location(67);

 qDebug() << "pre= " << pre.to_qstring();

}


void test12()
{
 Vec1d<int> v1d;

 v1d.set_default <= defzfn(int);

 qDebug() << v1d.first();

 v1d.push_back(7);
 v1d.push_back(9);
 v1d.push_back(17);

 v1d.each <= [](int& i, s2 index)
 {
  qDebug() << index;
  qDebug() << i;
 };

 v1d.reach <<= [](int& i, s2 index)
 {
  if(index == 3)
    return-0;
  qDebug() << i;
  return-1;
 };

 qDebug() << "ok";

 qDebug() << v1d.last();
 qDebug() << v1d.first();
}

void test13()
{
 Vec1d<u1> vec;
  // vec.default_to(0);
 vec.set_default_fn(defzfn(u1));
 vec.push_back(15);
 u1 x = vec.get_element(0);
 qDebug() << "x = " << x;
}

int main2(int argc , char **argv)
{
 qDebug() << "\n\ntest 1";
 test1();

 qDebug() << "\n\ntest 2";
 test2();

 qDebug() << "\n\ntest 3";
 test3();

 qDebug() << "\n\ntest 4";
 test4();

 qDebug() << "\n\ntest 5";
 test5();

 qDebug() << "\n\ntest 6";
 test6();

 qDebug() << "\n\ntest 7";
 test7();

 qDebug() << "\n\ntest 8";
 test8();

 qDebug() << "\n\ntest 9";
 test9();

 qDebug() << "\n\ntest 10";
 test10();

 qDebug() << "\n\ntest 11";
 test11();

 qDebug() << "\n\ntest 12";
 test12();

 qDebug() << "\n\ntest 13";
 test13();
// test1();
// test1();
// test1();

 return 0;
}
