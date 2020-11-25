
// // license___here_h

#ifndef Transformation__H
#define Transformation__H

#include <QList>

#include <QVector>


// package facsanadu.transformations;

// // Transformation

class Transformation
{
protected:
 int channel_; //=-1;


public:

 Transformation()
  : channel_(-1)
 {
 }

 int channel()
 {
  return channel_;
 }
 void set_channel(int i)
 {
  channel_ = i;
 }

 virtual void transform(QList<double>& v) = 0;
 virtual void invert(QList<double>& v) = 0;

 virtual void transform(QVector<double>& v) = 0;
 virtual void invert(QVector<double>& v) = 0;

 virtual double transform(double x, int index) = 0;
 virtual double invert(double x, int index) = 0;
};

//class TransformationLog : Transformation
//{

//};

#endif //  Transformation__H


