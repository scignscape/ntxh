
// // license___here

#include "TransformationLog.h"

#include <QtMath>

#include <QDebug>


TransformationLog::TransformationLog(r8 log0_default)
 :  log0_default_(log0_default)
{

}


void TransformationLog::transform(QList<double>& v)
{
 if(v[channel_] == 0)
   v[channel_] = log0_default_;
 else
   v[channel_] = qLn(v[channel_]);
}

void TransformationLog::invert(QList<double>& v)
{
 // // this did nothing in Java ... why?
  //   I'm assuming we should exponent ...
 v[channel_] = qExp(v[channel_]);
}


void TransformationLog::transform(QVector<double>& v)
{
// qDebug() << "v = " << v.size();
// qDebug() << "channel_ = " << channel_;

 if(v[channel_] == 0)
   v[channel_] = log0_default_;
 else
   v[channel_] = qLn(v[channel_]);
}

void TransformationLog::invert(QVector<double>& v)
{
 // // this did nothing in Java ... why?
  //   I'm assuming we should exponent ...

 v[channel_] = qExp(v[channel_]);
}


double TransformationLog::transform(double x, int index)
{
 if(index == channel_)
 {
  if(x == 0)
    return log0_default_;
  return qLn(x);
 } 
 else
   return x;
}

double TransformationLog::invert(double x, int index)
{
 if(index == channel_)
   return qExp(x);
 else
   return x;
}


