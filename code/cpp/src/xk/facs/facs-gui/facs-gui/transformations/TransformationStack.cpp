
// // license___here


#include "TransformationStack.h"

#include "Transformation.h"

#include <QDebug>
#include <QtMath>


// package facsanadu.transformations;


// // A set of transformations
TransformationStack::TransformationStack()
{
 
}


 // // Transform a point. Returns a new point. Might be the same array (optimization)
QList<double> TransformationStack::perform(QList<double> v)
{
 qDebug() << "l TS size: " << list_.size();

 if(list_.isEmpty())
   return v;
 else
 {
  QList<double> n(v); // new double[v.length];
  // System.arraycopy(v, 0, n, 0, v.length);
  for(Transformation* one : list_)
    one->transform(n);
  return n;
 }
}

QVector<double> TransformationStack::perform(QVector<double> v)
{
 qDebug() << "v TS size: " << list_.size();

 if(list_.isEmpty())
   return v;
 else
 {
  QVector<double> n(v); // new double[v.length];
  // System.arraycopy(v, 0, n, 0, v.length);
  for(Transformation* one : list_)
    one->transform(n.toList());
  return n;
 }

}
 
 /**
  * Invert a point. Returns a new point. Might be the same array (optimization)
  */
QList<double> TransformationStack::invert(QList<double> v)
{
 if(list_.isEmpty())
   return v;
 else
 {
  QList<double> n(v);//   double[] n=new double[v.length];
  // System.arraycopy(v, 0, n, 0, v.length);
  for(int i = list_.size() - 1; i>= 0; --i)
    list_.at(i)->invert(n);
  return n;
 }
}

void TransformationStack::set(int index, Transformation* trans)
{
 for(Transformation* t : list_) // new LinkedList<Transformation>(list))
 { 
  if(t->channel() == index)
    list_.removeAll(t); //? all?
 }

 //Add new one
 if(trans)
 {
  trans->set_channel(index);
  list_.append(trans);
 }
}

double TransformationStack::perform(double x, int indexX)
{
 if(list_.size() == 0)
 {
  qDebug() << "ln: " << x << " = " << qLn(x);
  // default ... just log everything ...
  return qLn(x);
 }

 for(Transformation* t : list_)
   x = t->transform(x, indexX);
 return x;
}

double TransformationStack::invert(double x, int indexX)
{
 for(int i = list_.size() - 1; i >= 0; --i)
   x = list_.at(i)->invert(x, indexX);
 return x;
}

/*
bool TransformationStack::isEmpty()
{
 return list_.isEmpty();
}
*/


