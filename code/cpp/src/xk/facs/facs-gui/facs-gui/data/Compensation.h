
// // license___here_h

#ifndef Compensation__H
#define Compensation__H

// package facsanadu.data;

#include <QList>
#include <QMap>
#include <QStringList>

#include "facs-bridge/qvector-matrix-r8.h"


class FacsanaduProject;
class Dataset;

class Compensation
{
 //QList<QList<double>>
 QVector_Matrix_R8 matrix_; // =0;
 QStringList cnames_;

 static QList<double> multiply( //?QList<QList<double>>
   QVector_Matrix_R8 m, 
   QList<double> v);

public:

 Compensation();

 QStringList cnames()
 {
  return cnames_;
 }

 int getSize();
 void updateMatrix(FacsanaduProject* p);
 void apply(FacsanaduProject* p);
 void apply(Dataset* ds);
 double get(int to, int from);
 void set(int to, int from, double v);

 //?QList<QList<double>>
 QVector_Matrix_R8 getMatrix()
 {
  return matrix_;
 }

 void setMatrix(QVector_Matrix_R8 m) //QList<QList<double>> m)
 {
  matrix_ =  m;
 }
 
};

#endif // Compensation__H


