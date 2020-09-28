
// // license___here_h

#ifndef TransformationStack__H
#define TransformationStack__H

class Transformation;



#include <QList>

// package facsanadu.transformations;


// // A set of transformations
class TransformationStack
{
 QList<Transformation*> list_; //=new ArrayList<Transformation>();

public:

 TransformationStack();
   
  //@Override
 template<typename T>
 inline bool operator==(const T& t)
 {
  return false;
 }

 template<typename T>
 inline bool operator==(const TransformationStack& ts)
 {
  return ts.list_ == list_;
 }

 // // Transform a point. Returns a new point. Might be the same array (optimization)
 QList<double> perform(QList<double> v);

 QVector<double> perform(QVector<double> v); 

 /**
  * Invert a point. Returns a new point. Might be the same array (optimization)
  */
 QList<double> invert(QList<double> v);

 void set(int index, Transformation* trans);

 double perform(double x, int indexX);

 double invert(double x, int indexX);

 bool isEmpty()
 {
  return list_.isEmpty();
 }
 
};


#endif //  TransformationStack__H


