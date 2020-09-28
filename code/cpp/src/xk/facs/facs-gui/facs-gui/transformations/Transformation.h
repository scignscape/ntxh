
// // license___here_h

#ifndef Transformation__H
#define Transformation__H

// package facsanadu.transformations;

// // Transformation

class Transformation
{
 int channel_; //=-1;


public:

 int channel()
 {
  return channel_;
 }
 void set_channel(int i)
 {
  channel_ = i;
 }

 virtual void transform(QList<double> v) = 0;
 virtual void invert(QList<double> v) = 0;
 virtual double transform(double x, int index);
 virtual double invert(double x, int index);
};

class TransformationLog : Transformation
{

};

#endif //  Transformation__H


