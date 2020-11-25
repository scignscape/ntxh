
// // license___here

#include "TransformationLinear.h"

#include <QtMath>


TransformationLinear::TransformationLinear(s4 s1, r8 sk, s4 s2)
 :  shift1_(s1), skew_(sk), shift2_(s2)
{

}


void TransformationLinear::transform(QList<double>& v)
{
 v[channel_] = ((v[channel_] + shift1_) * skew_) + shift2_;
}

void TransformationLinear::invert(QList<double>& v)
{
 v[channel_] = ((v[channel_] - shift2_) / skew_) - shift1_;
}


void TransformationLinear::transform(QVector<double>& v)
{
 v[channel_] = ((v[channel_] + shift1_) * skew_) + shift2_;
}

void TransformationLinear::invert(QVector<double>& v)
{
 v[channel_] = ((v[channel_] - shift2_) / skew_) - shift1_;
}


double TransformationLinear::transform(double x, int index)
{
 if(index == channel_)
   return ((x + shift1_) * skew_) + shift2_;
 else
   return x;
}

double TransformationLinear::invert(double x, int index)
{
 if(index == channel_)
   return ((x - shift2_) / skew_) - shift1_;
 else
   return x;

}

